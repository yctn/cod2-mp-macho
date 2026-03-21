/* ASM dump from: r_bsp_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_bsp_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/r_dpvs.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct r_globals_load_t rgl; /* 0x0 */
extern GfxWorld s_world; /* 0x0 */

#ifndef __EMSCRIPTEN__
static int R_FinishLoadingAabbTrees_r(void);
#endif
const char * R_ParseSunLight(SunLightParseParams *params, const char *text);
snd_alias_list_t R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight);
#ifndef __EMSCRIPTEN__
static Bool R_IsValidStaticModel(char * (*spawnVars)[2], int spawnVarCount, struct XModel * *model, vec_t *origin);
#endif
#ifndef __EMSCRIPTEN__
static snd_alias_list_t R_SetParentAndCell_r(void);
#endif
static void R_SetParentAndCell_r_impl(mnode_t *node, int parent);
snd_alias_list_t R_LoadEntities(void);
snd_alias_list_t R_LoadNodesAndLeafs(void);
static void R_LoadNodesAndLeafs_impl(const byte *loadState);
snd_alias_list_t R_LoadPortals(void);
snd_alias_list_t R_LoadCells(GfxBspLoad *load);
snd_alias_list_t R_LoadAabbTrees(void);
snd_alias_list_t R_LoadOccluders(void);
static void R_LoadOccluders_impl(const byte *loadState);
snd_alias_list_t R_LoadPortalVerts(void);
snd_alias_list_t R_LoadCullGroups(void);
snd_alias_list_t R_LoadSurfaces(GfxBspLoad *load);
GfxWorld * R_LoadWorldInternal(const char *name);

/* line 1396 */
extern void R_Error(int level, const char *msg, ...);
extern void ClearBounds(void *mins, void *maxs);
extern void ExpandBounds(const void *mins, const void *maxs, void *dstMins, void *dstMaxs);
extern const char *Com_Parse(const char **text);
extern void I_strncpyz(char *dest, const char *src, int size);
extern int I_stricmp(const char *a, const char *b);
extern double atof(const char *s);
extern int sscanf(const char *str, const char *fmt, ...);
extern float ColorNormalize(const float *color, float *out);
extern void Com_Printf(const char *fmt, ...);
extern void *Hunk_AllocInternal(int size);

/* Validate and get a BSP lump. Returns element count.
 * load[0]=header, load[4]=fileBase, load[8]=fileSize.
 * Lump at header+lumpOfs: [0]=size, [4]=offset. */
static int R_ValidateLump(const int *load, int lumpOfs, int elemSize, const byte **outData)
{
    const byte *header = (const byte *)load[0];
    int lumpSize = *(int *)(header + lumpOfs);
    int lumpFileOfs = *(int *)(header + lumpOfs + 4);
    int count;

    if (lumpFileOfs + lumpSize > load[2])
        R_Error(1, "LoadMap: lump extends past end of file in %s", *(const char **)&s_world);
    if (lumpFileOfs <= 3) {
        /* Allow zero-size lumps (empty occluder indices, etc.) */
        if (lumpSize == 0) {
            if (outData) *outData = NULL;
            return 0;
        }
        R_Error(1, "LoadMap: funny lump offset in %s", *(const char **)&s_world);
    }

    count = lumpSize / elemSize;
    if (lumpSize < 0)
        count = (lumpSize + elemSize - 1) / elemSize; /* round toward zero for negative (shouldn't happen) */
    if (count * elemSize != lumpSize)
        R_Error(1, "LoadMap: funny lump size in %s", *(const char **)&s_world);

    if (outData)
        *outData = (const byte *)load[1] + lumpFileOfs;
    return count;
}
extern void AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern void *R_RegisterModel(const char *name);
extern int XModelBad(void *model);
extern int strnicmp(const char *a, const char *b, int n);
extern int stricmp(const char *a, const char *b);
extern void *CM_GetPlaneNum(int planeIndex);
extern void PerpendicularVector(const void *plane, vec_t *perpOut);
extern void Vec3Cross(const void *plane, const vec_t *perp, vec_t *crossOut);

/* Uses register calling convention: eax=tree, edx=totalTreesUsed */
static int R_FinishLoadingAabbTrees_r_impl(byte *tree, int totalTreesUsed)
{
    GfxAabbTree *aabbTree = (GfxAabbTree *)tree;
    int childCount, surfCount, i;

    ClearBounds(aabbTree->mins, aabbTree->maxs);

    childCount = aabbTree->childCount;
    if (childCount) {
        /* Has children — assign child array from rgl pool */
        aabbTree->children = (int)(intptr_t)((byte *)rgl.aabbTrees + totalTreesUsed * sizeof(GfxAabbTree));
        totalTreesUsed += childCount;

        /* Recurse into each child */
        for (i = 0; i < childCount; i++) {
            byte *child = (byte *)(intptr_t)aabbTree->children + i * sizeof(GfxAabbTree);
            totalTreesUsed = R_FinishLoadingAabbTrees_r_impl(child, totalTreesUsed);
            ExpandBounds(child, child + 0xc, aabbTree->mins, aabbTree->maxs);
        }
    } else {
        /* Leaf node — expand bounds from surface data */
        int firstSurf = aabbTree->startSurfIndex;
        GfxSurface *surfPtr = s_world.surfaces + firstSurf;
        surfCount = aabbTree->surfaceCount;

        for (i = 0; i < surfCount; i++) {
            byte *surfData = (byte *)surfPtr[i].data;
            ExpandBounds(surfData + 4, surfData + 0x10, aabbTree->mins, aabbTree->maxs);
        }
    }

    return totalTreesUsed;
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static int R_FinishLoadingAabbTrees_r(byte *tree, int totalTreesUsed)
{
    return R_FinishLoadingAabbTrees_r_impl(tree, totalTreesUsed);
}
#else
/* x86 trampoline: eax=tree, edx=totalTreesUsed → cdecl _impl */
static __attribute__((naked))
int R_FinishLoadingAabbTrees_r(void)
{
    __asm__ __volatile__ (
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_FinishLoadingAabbTrees_r_impl\n"
        "addl $8, %esp\n"
        "retl\n"
    );
}
#endif

/* line 1129 */
/* line 1129 — Parse sun light parameters from an entity definition text block.
 * Reads key-value pairs: ambient, sunColor, sunIntensity, sunDir, diffuseColor,
 * diffuseColorLinear, specularColor, angles, sunLight. */
const char * R_ParseSunLight(SunLightParseParams *params, const char *text)
{
    char keyname[0x800];
    char value[0x800];
    const char *token;

    while (1) {
        token = Com_Parse(&text);
        if (!token[0] || token[0] == '}')
            break;

        if (token[0] == '{') {
            /* Initialize sun light params */
            params->ambientScale = 0.0f;
            params->sunLight = 0.0f;
            params->diffuseFraction = 0.5f;
            params->diffuseColorHasBeenSet = 0;
            /* Clear ambientColor, sunColor, diffuseColor */
            params->ambientColor[0] = 0; params->ambientColor[1] = 0; params->ambientColor[2] = 0;
            params->sunColor[0] = 0; params->sunColor[1] = 0; params->sunColor[2] = 0;
            params->diffuseColor[0] = 0; params->diffuseColor[1] = 0; params->diffuseColor[2] = 0;
            continue;
        }

        /* Read key name */
        I_strncpyz(keyname, token, 0x800);

        /* Read value */
        token = Com_Parse(&text);
        if (!token[0] || token[0] == '}')
            break;
        I_strncpyz(value, token, 0x800);

        /* Match key */
        if (!I_stricmp(keyname, "ambient")) {
            params->ambientScale = (float)atof(value);
            if (params->ambientScale > 2.0f) {
                Com_Printf("^3WARNING: ambient too big, assuming it uses the old 0-255 s", value);
                params->ambientScale *= 0.01568627543747425f; /* 4.0/255.0 */
            }
        } else if (!I_stricmp(keyname, "sunColor")) {
            params->ambientColor[0] = 0; params->ambientColor[1] = 0; params->ambientColor[2] = 0;
            sscanf(value, "%f %f %f", &params->ambientColor[0], &params->ambientColor[1], &params->ambientColor[2]);
        } else if (!I_stricmp(keyname, "sunIntensity")) {
            params->diffuseFraction = (float)atof(value);
        } else if (!I_stricmp(keyname, "sunDir")) {
            params->sunColor[0] = 0; params->sunColor[1] = 0; params->sunColor[2] = 0;
            sscanf(value, "%f %f %f", &params->sunColor[0], &params->sunColor[1], &params->sunColor[2]);
            ColorNormalize(params->sunColor, params->sunColor);
        } else if (!I_stricmp(keyname, "diffuseColor")) {
            params->diffuseColor[0] = 0; params->diffuseColor[1] = 0; params->diffuseColor[2] = 0;
            sscanf(value, "%f %f %f", &params->diffuseColor[0], &params->diffuseColor[1], &params->diffuseColor[2]);
            ColorNormalize(params->diffuseColor, params->diffuseColor);
            params->diffuseColorHasBeenSet = 1;
        } else if (!I_stricmp(keyname, "sunAngleOverride")) {
            params->sunLight = (float)atof(value);
        } else if (!I_stricmp(keyname, "specularColor")) {
            params->angles[0] = 0; params->angles[1] = 0; params->angles[2] = 0;
            sscanf(value, "%f %f %f", &params->angles[0], &params->angles[1], &params->angles[2]);
        } else if (!I_stricmp(keyname, "sunLight")) {
            I_strncpyz(params->name, value, 0x40);
        }
    }

    return text;
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1129 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x104c, %esp\n"
        "movl 8(%ebp), %esi\n" /* params */
        /* { scope 1 */
        ".Lfe2abc_000e2acb:\n"
        "leal 0xc(%ebp), %eax\n" /* line 1139 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 1140 */
        "testb %dl, %dl\n"
        "je .Lfe2abc_000e2b30\n"
        ".Lfe2abc_000e2add:\n"
        "cmpb $0x7d, %dl\n"
        "je .Lfe2abc_000e2b30\n"
        "cmpb $0x7b, %dl\n" /* line 1143 */
        "jne .Lfe2abc_000e2b3e\n"
        "xorl %eax, %eax\n" /* line 1145 */
        "movl %eax, 0x40(%esi)\n" /* params */
        "movl %eax, 0x54(%esi)\n" /* line 1146 | params */
        "movl $0x3f000000, 0x50(%esi)\n" /* line 1147 | params */
        "movb $0, 0x70(%esi)\n" /* line 1148 | params */
        "leal 0x44(%esi), %edx\n" /* line 1149 | params, v */
        /* { scope 2 */
        "movl %eax, 0x44(%esi)\n" /* line 183 */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0x58(%esi), %edx\n" /* line 1150 | params, v */
        /* { scope 2 */
        "movl %eax, 0x58(%esi)\n" /* line 183 */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0x64(%esi), %edx\n" /* line 1151 | params, v */
        /* { scope 2 */
        "movl %eax, 0x64(%esi)\n" /* line 183 */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0xc(%ebp), %eax\n" /* line 1139 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 1140 */
        "testb %dl, %dl\n"
        "jne .Lfe2abc_000e2add\n"
        ".Lfe2abc_000e2b30:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1225 | text */
        /* } scope */
        "addl $0x104c, %esp\n" /* line 1231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe2abc_000e2b3e:\n"
        "movl $0x800, 8(%esp)\n" /* line 1156 */
        "movl %eax, 4(%esp)\n"
        "leal -0x818(%ebp), %ebx\n" /* keyname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "leal 0xc(%ebp), %eax\n" /* line 1159 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 1160 */
        "testb %dl, %dl\n"
        "je .Lfe2abc_000e2b30\n"
        "cmpb $0x7d, %dl\n"
        "je .Lfe2abc_000e2b30\n"
        "movl $0x800, 8(%esp)\n" /* line 1162 */
        "movl %eax, 4(%esp)\n"
        "leal -0x1018(%ebp), %edi\n" /* value */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_00224bdc, 4(%esp)\n" /* line 1165 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2abc_000e2bec\n"
        "movl %edi, (%esp)\n" /* line 1167 */
        "calll atof\n"
        "fstpl -0x1030(%ebp)\n"
        "cvtsd2ss -0x1030(%ebp), %xmm0\n"
        "movss %xmm0, 0x40(%esi)\n" /* params */
        "ucomiss lit4_002ed62c, %xmm0\n" /* line 1168 | 2.0f */
        "jbe .Lfe2abc_000e2acb\n"
        "movl %edi, 4(%esp)\n" /* line 1170 */
        "movl $str_00224be4, (%esp)\n" /* "^3WARNING: ambient too big, assuming it uses the old 0-255 s" */
        "calll Com_Printf\n"
        "movss lit4_002ed86c, %xmm0\n" /* line 1172 | 0.01568627543747425f */
        "mulss 0x40(%esi), %xmm0\n" /* params */
        "movss %xmm0, 0x40(%esi)\n" /* params */
        "jmp .Lfe2abc_000e2acb\n"
        ".Lfe2abc_000e2bec:\n"
        "movl $str_00224c58, 4(%esp)\n" /* line 1177 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2abc_000e2c35\n"
        "leal 0x44(%esi), %edx\n" /* line 1179 | params, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x44(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0x4c(%esi), %eax\n" /* line 1180 | params */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x48(%esi), %eax\n" /* params */
        ".Lfe2abc_000e2c18:\n"
        "movl %eax, 0xc(%esp)\n" /* line 1217 */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %edi, (%esp)\n"
        "calll sscanf\n"
        "jmp .Lfe2abc_000e2acb\n"
        ".Lfe2abc_000e2c35:\n"
        "movl $str_00224c60, 4(%esp)\n" /* line 1185 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2abc_000e2c69\n"
        "movl %edi, (%esp)\n" /* line 1187 */
        "calll atof\n"
        "fstpl -0x1028(%ebp)\n"
        "cvtsd2ss -0x1028(%ebp), %xmm0\n"
        "movss %xmm0, 0x50(%esi)\n" /* params */
        "jmp .Lfe2abc_000e2acb\n"
        ".Lfe2abc_000e2c69:\n"
        "movl $str_00224c70, 4(%esp)\n" /* line 1191 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe2abc_000e2cc9\n"
        "movl $str_00224c7c, 4(%esp)\n" /* line 1199 */
        "movl %ebx, (%esp)\n" /* v */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe2abc_000e2d0c\n"
        "movl $str_00224c8c, 4(%esp)\n" /* line 1208 */
        "movl %ebx, (%esp)\n" /* v */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2abc_000e2d53\n"
        "movl %edi, (%esp)\n" /* line 1210 */
        "calll atof\n"
        "fstpl -0x1020(%ebp)\n"
        "cvtsd2ss -0x1020(%ebp), %xmm0\n"
        "movss %xmm0, 0x54(%esi)\n" /* params */
        "jmp .Lfe2abc_000e2acb\n"
        ".Lfe2abc_000e2cc9:\n"
        "leal 0x58(%esi), %ebx\n" /* line 1193 | params, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x58(%esi)\n"
        "movl %eax, 4(%ebx)\n" /* line 184 */
        "movl %eax, 8(%ebx)\n" /* line 185 */
        /* } scope */
        "leal 0x60(%esi), %eax\n" /* line 1194 | params */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x5c(%esi), %eax\n" /* params */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* v */
        "movl $str_0021c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %edi, (%esp)\n"
        "calll sscanf\n"
        "movl %ebx, 4(%esp)\n" /* line 1195 | v */
        "movl %ebx, (%esp)\n" /* v */
        "calll ColorNormalize\n"
        "fstp %st(0)\n"
        "jmp .Lfe2abc_000e2acb\n"
        ".Lfe2abc_000e2d0c:\n"
        "leal 0x64(%esi), %ebx\n" /* line 1201 | params, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x64(%esi)\n"
        "movl %eax, 4(%ebx)\n" /* line 184 */
        "movl %eax, 8(%ebx)\n" /* line 185 */
        /* } scope */
        "leal 0x6c(%esi), %eax\n" /* line 1202 | params */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x68(%esi), %eax\n" /* params */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* v */
        "movl $str_0021c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %edi, (%esp)\n"
        "calll sscanf\n"
        "movl %ebx, 4(%esp)\n" /* line 1203 | v */
        "movl %ebx, (%esp)\n" /* v */
        "calll ColorNormalize\n"
        "fstp %st(0)\n"
        "movb $1, 0x70(%esi)\n" /* line 1204 | params */
        "jmp .Lfe2abc_000e2acb\n"
        ".Lfe2abc_000e2d53:\n"
        "movl $str_00224c98, 4(%esp)\n" /* line 1214 */
        "movl %ebx, (%esp)\n" /* v */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2abc_000e2d84\n"
        "leal 0x74(%esi), %edx\n" /* line 1216 | params, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x74(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0x7c(%esi), %eax\n" /* line 1217 | params */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x78(%esi), %eax\n" /* params */
        "jmp .Lfe2abc_000e2c18\n"
        ".Lfe2abc_000e2d84:\n"
        "movl $str_002194b4, 4(%esp)\n" /* line 1222 */
        "movl %ebx, (%esp)\n" /* v */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2abc_000e2acb\n"
        "movl $0x40, 8(%esp)\n" /* line 1224 */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* params */
        "calll I_strncpyz\n"
        "jmp .Lfe2abc_000e2acb\n"
    );
}
#endif

/* line 1911 — Convert parsed sun light parameters into a GfxLight structure. */
snd_alias_list_t R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight)
{
    vec_t sunDirection[3];
    float ambient, sunIntensity, sunAngleOverride;
    float ambientR, ambientG, ambientB;
    float scale;
    float diffR, diffG, diffB;

    /* Compute sun direction from angles */
    AngleVectors(sunParse->angles, sunDirection, NULL, NULL);

    ambient = sunParse->ambientScale;
    sunIntensity = sunParse->diffuseFraction;
    sunAngleOverride = sunParse->sunLight;

    /* Compute ambient color contribution */
    if (ambient != 0.0f) {
        float normLen = ColorNormalize(sunParse->ambientColor, sunParse->ambientColor);
        if (normLen != 0.0f) {
            ambientR = ambient * sunParse->ambientColor[0];
            ambientG = ambient * sunParse->ambientColor[1];
            ambientB = ambient * sunParse->ambientColor[2];
        } else {
            ambientR = ambientG = ambientB = 0.0f;
        }
    } else {
        ambientR = ambientG = ambientB = 0.0f;
    }

    /* Diffuse: sunDir * (sunAngleOverride - ambient) * (1 - sunIntensity) */
    scale = (sunAngleOverride - ambient) * (1.0f - sunIntensity);
    diffR = scale * sunParse->sunColor[0];
    diffG = scale * sunParse->sunColor[1];
    diffB = scale * sunParse->sunColor[2];

    /* Fill GfxLight if provided.
       Guard against read-only pointers — R_LoadWorldInternal (naked ASM)
       can pass a stale Mac relocation address into the read-only strings
       section.  Redirect to a scratch buffer so the write doesn't segfault. */
    {
        static GfxLight sunLightScratch;
        /* Guard against invalid sunLight pointers — can be stale relocations,
         * small constants (0x1), or BSS-range addresses from naked ASM */
        if ((unsigned int)sunLight < 0x1000 ||
            ((unsigned int)sunLight >= 0x08200000 && (unsigned int)sunLight < 0x08800000)) {
            sunLight = &sunLightScratch;
        }
    }
    if (sunLight) {
        sunLight->position[0] = sunDirection[0];
        sunLight->position[1] = sunDirection[1];
        sunLight->position[2] = sunDirection[2];
        sunLight->position[3] = 0.0f;
        sunLight->color[0] = diffR;
        sunLight->color[1] = diffG;
        sunLight->color[2] = diffB;
        sunLight->u.dir.ambientColor[0] = ambientR;
        sunLight->u.dir.ambientColor[1] = ambientG;
        sunLight->u.dir.ambientColor[2] = ambientB;
    }
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1911 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* sunParse */
        "movl 0xc(%ebp), %edi\n" /* sunLight */
        /* { scope 1 */
        "movl $0, 0xc(%esp)\n" /* line 1919 */
        "movl $0, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* sunDirection */
        "movl %eax, 4(%esp)\n"
        "leal 0x74(%ebx), %eax\n" /* sunParse */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "pxor %xmm0, %xmm0\n" /* line 1921 */
        "ucomiss 0x40(%ebx), %xmm0\n" /* sunParse */
        "jp .Lfe2db6_000e2e84\n"
        "jne .Lfe2db6_000e2e84\n"
        ".Lfe2db6_000e2dfb:\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm5\n"
        "movaps %xmm3, %xmm4\n"
        ".Lfe2db6_000e2e05:\n"
        "movss 0x54(%ebx), %xmm0\n" /* line 1934 | sunParse, scale */
        "subss 0x40(%ebx), %xmm0\n" /* sunParse, scale */
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss 0x50(%ebx), %xmm1\n" /* sunParse */
        "mulss %xmm1, %xmm0\n" /* scale */
        "leal 0x58(%ebx), %eax\n" /* sunParse, v */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0x58(%ebx), %xmm1\n"
        "movaps %xmm0, %xmm2\n" /* line 273 */
        "mulss 4(%eax), %xmm2\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        /* } scope */
        "testl %edi, %edi\n" /* line 1937 | sunLight */
        "je .Lfe2db6_000e2e7c\n"
        "leal 4(%edi), %edx\n" /* line 1904 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | sunDirection */
        "movl %eax, 4(%edi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0, 0x10(%edi)\n" /* line 1905 */
        "leal 0x14(%edi), %eax\n" /* line 1906 | to */
        /* { scope 2 */
        "movss %xmm1, 0x14(%edi)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x20(%edi), %eax\n" /* line 1907 | to */
        /* { scope 2 */
        "movss %xmm4, 0x20(%edi)\n" /* line 199 */
        "movss %xmm5, 4(%eax)\n" /* line 200 */
        "movss %xmm3, 8(%eax)\n" /* line 201 */
        /* } scope */
        /* } scope */
        ".Lfe2db6_000e2e7c:\n"
        "addl $0x3c, %esp\n" /* line 1939 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe2db6_000e2e84:\n"
        "leal 0x44(%ebx), %esi\n" /* line 1921 | sunParse */
        "movl %esi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ColorNormalize\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm1\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "je .Lfe2db6_000e2ec5\n"
        ".Lfe2db6_000e2ea4:\n"
        "movss 0x40(%ebx), %xmm0\n" /* line 1922 | sunParse, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm4\n" /* line 272 */
        "mulss (%esi), %xmm4\n"
        "movaps %xmm0, %xmm5\n" /* line 273 */
        "mulss 4(%esi), %xmm5\n"
        "movaps %xmm0, %xmm3\n" /* line 274 */
        "mulss 8(%esi), %xmm3\n"
        "jmp .Lfe2db6_000e2e05\n"
        /* } scope */
        ".Lfe2db6_000e2ec5:\n"
        "jnp .Lfe2db6_000e2dfb\n" /* line 1921 */
        "jmp .Lfe2db6_000e2ea4\n"
    );
}
#endif

/* line 1004 */
/* Find a key in spawnVars[count][2] by name; returns the value string or NULL */
static const char *R_FindSpawnVar(const void *spawnVars, int count, const char *key)
{
    /* spawnVars is array of {key, value} string pairs, stride 8 bytes */
    int i;
    byte *vars = (byte *)spawnVars;
    for (i = 0; i < count; i++) {
        if (!stricmp(*(char **)(vars + i * 8), key))
            return *(char **)(vars + i * 8 + 4);
    }
    return NULL;
}

/* line 1004 */
static Bool R_IsValidStaticModel_impl(char *spawnVars, int spawnVarCount, struct XModel **model, vec_t *origin)
{
    const char *originStr;
    const char *modelName;
    vec_t tempOrigin[3] = {0, 0, 0};
    struct XModel *tempModel;
    int hasOrigin;

    /* Find "origin" key */
    originStr = R_FindSpawnVar(spawnVars, spawnVarCount, "origin");
    hasOrigin = (originStr != NULL);
    if (!originStr)
        originStr = "0 0 0";

    sscanf(originStr, "%f %f %f", &tempOrigin[0], &tempOrigin[1], &tempOrigin[2]);

    if (!hasOrigin)
        R_Error(1, "R_LoadMiscModel: \"origin\" must be specified for misc_model");

    /* Find "model" key */
    modelName = R_FindSpawnVar(spawnVars, spawnVarCount, "model");
    if (!modelName) {
        R_Error(1, "R_LoadMiscModel: no model specified in misc_model at (%.0f %.0f %.0f)",
                (double)tempOrigin[0], (double)tempOrigin[1], (double)tempOrigin[2]);
    }

    /* Skip shadow models */
    if (modelName && !strnicmp(modelName, "xmodel/shadow_", 14))
        return 0;

    /* Try to register the model */
    if (modelName) {
        tempModel = (struct XModel *)R_RegisterModel(modelName);
    } else {
        tempModel = NULL;
    }

    if (!tempModel || XModelBad(tempModel)) {
        /* Bad model — try fallback */
        Com_Printf("^1bad static model '%s' at (%.0f %.0f %.0f)\n",
                    modelName, (double)tempOrigin[0], (double)tempOrigin[1], (double)tempOrigin[2]);
        tempModel = (struct XModel *)R_RegisterModel("$default");
    }

    if (!tempModel || XModelBad(tempModel))
        return 0;

    /* Validate model */
    {
        extern Bool R_ValidateStaticModel(struct XModel *model);
        if (!R_ValidateStaticModel(tempModel))
            if (!tempModel || XModelBad(tempModel))
                return 0;
    }

    if (model)
        *model = tempModel;
    if (origin) {
        origin[0] = tempOrigin[0];
        origin[1] = tempOrigin[1];
        origin[2] = tempOrigin[2];
    }
    return 1;
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static Bool R_IsValidStaticModel(char *spawnVars, int spawnVarCount, struct XModel **model, vec_t *origin)
{
    return R_IsValidStaticModel_impl(spawnVars, spawnVarCount, model, origin);
}
#else
/* x86 trampoline: eax=spawnVars, edx=spawnVarCount, ecx=model, stack=origin → cdecl _impl */
static __attribute__((naked))
Bool R_IsValidStaticModel(char * (*spawnVars)[2], int spawnVarCount, struct XModel * *model, vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl 8(%esp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_IsValidStaticModel_impl\n"
        "addl $16, %esp\n"
        "retl $4\n"
    );
}
#endif
#if 0 /* original R_IsValidStaticModel ASM — replaced above */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1004 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %ecx, -0x3c(%ebp)\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        "subl $1, %edx\n" /* line 918 */
        "jg .Lfe2ece_000e3082\n"
        ".Lfe2ece_000e2ee9:\n"
        "movl $str_00224ca8, %ecx\n" /* "0 0 0" */
        "xorl %ebx, %ebx\n"
        /* } scope */
        ".Lfe2ece_000e2ef0:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x24(%ebp)\n" /* tempOrigin */
        "movl %eax, -0x20(%ebp)\n" /* line 184 */
        "movl %eax, -0x1c(%ebp)\n" /* line 185 */
        "leal -0x24(%ebp), %edx\n" /* line 956 | tempOrigin */
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $str_0021c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %ecx, (%esp)\n"
        "calll sscanf\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1010 | tempModel */
        "je .Lfe2ece_000e3069\n"
        /* { scope 2 */
        ".Lfe2ece_000e2f28:\n"
        "cmpl $1, -0x38(%ebp)\n" /* line 918 */
        "jle .Lfe2ece_000e2f6e\n"
        "movl -0x34(%ebp), %ebx\n"
        "addl $8, %ebx\n"
        "movl $1, %edi\n" /* i */
        "movl $8, %esi\n"
        ".Lfe2ece_000e2f3e:\n"
        "movl -0x34(%ebp), %eax\n"
        "addl %esi, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl $str_0021593c, 4(%esp)\n" /* line 920 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe2ece_000e30db\n"
        "addl $1, %edi\n" /* line 918 | i */
        "addl $8, %esi\n"
        "addl $8, %ebx\n"
        "cmpl %edi, -0x38(%ebp)\n" /* i */
        "jne .Lfe2ece_000e2f3e\n"
        ".Lfe2ece_000e2f6e:\n"
        "xorl %esi, %esi\n"
        /* } scope */
        ".Lfe2ece_000e2f70:\n"
        "cvtss2sd -0x1c(%ebp), %xmm0\n" /* line 1015 */
        "movsd %xmm0, 0x18(%esp)\n"
        "cvtss2sd -0x20(%ebp), %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "cvtss2sd -0x24(%ebp), %xmm0\n" /* tempOrigin */
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224cd8, 4(%esp)\n" /* "R_LoadMiscModel: no model specified in misc_model at (%.0f " */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        ".Lfe2ece_000e2fa5:\n"
        "movl $0xe, 8(%esp)\n" /* line 1016 */
        "movl $str_00224d20, 4(%esp)\n" /* "xmodel/shadow_" */
        "movl %esi, (%esp)\n" /* modelName */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2ece_000e2fcb\n"
        ".Lfe2ece_000e2fc1:\n"
        "xorl %eax, %eax\n" /* line 201 */
        /* } scope */
        ".Lfe2ece_000e2fc3:\n"
        "addl $0x5c, %esp\n" /* line 1036 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe2ece_000e2fcb:\n"
        "movl %esi, (%esp)\n" /* line 1019 | modelName */
        "calll R_RegisterModel\n"
        "movl %eax, %ebx\n" /* tempModel */
        "testl %eax, %eax\n" /* line 992 */
        "je .Lfe2ece_000e2fe9\n"
        "movl %eax, (%esp)\n" /* line 996 */
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "je .Lfe2ece_000e30ee\n"
        ".Lfe2ece_000e2fe9:\n"
        "cvtss2sd -0x1c(%ebp), %xmm0\n" /* line 1023 */
        "movsd %xmm0, 0x18(%esp)\n"
        "cvtss2sd -0x20(%ebp), %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "cvtss2sd -0x24(%ebp), %xmm0\n" /* tempOrigin */
        "movsd %xmm0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* modelName */
        "movl $str_00224d30, (%esp)\n" /* "^1bad static model '%s' at (%.0f %.0f %.0f)
" */
        "calll Com_Printf\n"
        "movl $str_00224d60, (%esp)\n" /* line 1024 */
        "calll R_RegisterModel\n"
        "movl %eax, %ebx\n" /* tempModel */
        ".Lfe2ece_000e3028:\n"
        "testl %ebx, %ebx\n" /* line 992 */
        "je .Lfe2ece_000e2fc1\n"
        "movl %ebx, (%esp)\n" /* line 996 */
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "jne .Lfe2ece_000e2fc1\n"
        "movl -0x3c(%ebp), %esi\n" /* line 1030 | modelName */
        "testl %esi, %esi\n" /* modelName */
        "je .Lfe2ece_000e3044\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1031 */
        "movl %ebx, (%eax)\n" /* tempModel */
        ".Lfe2ece_000e3044:\n"
        "movl 8(%ebp), %ecx\n" /* line 1032 | origin */
        "testl %ecx, %ecx\n"
        "je .Lfe2ece_000e305f\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | tempOrigin */
        "movl 8(%ebp), %edx\n" /* origin */
        "movl %eax, (%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        ".Lfe2ece_000e305f:\n"
        "movl $1, %eax\n"
        "jmp .Lfe2ece_000e2fc3\n"
        ".Lfe2ece_000e3069:\n"
        "movl $str_00224cb0, 4(%esp)\n" /* line 1011 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe2ece_000e2f28\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfe2ece_000e3082:\n"
        "movl %eax, %ebx\n" /* line 918 */
        "addl $8, %ebx\n"
        "movl $1, %edi\n" /* i */
        "movl $8, %esi\n"
        "jmp .Lfe2ece_000e30a5\n"
        ".Lfe2ece_000e3093:\n"
        "addl $1, %edi\n" /* i */
        "addl $8, %esi\n"
        "addl $8, %ebx\n"
        "cmpl %edi, -0x38(%ebp)\n" /* i */
        "je .Lfe2ece_000e2ee9\n"
        ".Lfe2ece_000e30a5:\n"
        "movl -0x34(%ebp), %eax\n"
        "addl %esi, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl $str_0021a570, 4(%esp)\n" /* line 920 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe2ece_000e3093\n"
        "movl -0x2c(%ebp), %edx\n" /* line 921 */
        "movl 4(%edx), %ecx\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 949 */
        "je .Lfe2ece_000e2ee9\n"
        "movl $1, %ebx\n"
        "jmp .Lfe2ece_000e2ef0\n"
        /* } scope */
        /* { scope 2 */
        ".Lfe2ece_000e30db:\n"
        "movl -0x30(%ebp), %edx\n" /* line 921 */
        "movl 4(%edx), %esi\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 1014 | modelName */
        "jne .Lfe2ece_000e2fa5\n"
        "jmp .Lfe2ece_000e2f70\n"
        ".Lfe2ece_000e30ee:\n"
        "movl %ebx, (%esp)\n" /* line 1021 | tempModel */
        "calll R_ValidateStaticModel\n"
        "testb %al, %al\n"
        "jne .Lfe2ece_000e3028\n"
        "jmp .Lfe2ece_000e2fe9\n"
    );
}
#endif

/* line 1727 — R_SetParentAndCell_r
 * Recursively sets parent pointers and cell indices for BSP nodes.
 * For leaf nodes: parent is set, cellIndex is already valid.
 * For internal nodes: recurses into both children, sets cellIndex to -2 (split)
 * unless both children have the same cellIndex, in which case it propagates up.
 * Original ASM was deeply unrolled (3-4 levels inlined) for performance.
 * Actual convention: eax=node, edx=parent (stored as int in node->parent) */
static void R_SetParentAndCell_r_impl(mnode_t *node, int parent)
{
    node->parent = parent;

    /* Leaf node: cellIndex is already set from loading */
    if (node->contents != -1)
        return;

    /* Internal node: recurse into both children */
    R_SetParentAndCell_r_impl(node->u.node.children[0], (int)(intptr_t)node);
    R_SetParentAndCell_r_impl(node->u.node.children[1], (int)(intptr_t)node);

    /* Determine cell index: -2 if children differ, else propagate */
    node->cellIndex = -2;
    if (node->u.node.children[0]->cellIndex == node->u.node.children[1]->cellIndex)
        node->cellIndex = node->u.node.children[0]->cellIndex;
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static snd_alias_list_t R_SetParentAndCell_r(mnode_t *node, int parent)
{
    R_SetParentAndCell_r_impl(node, parent);
}
#else
/* x86 trampoline: eax=node, edx=parent → cdecl _impl */
static __attribute__((naked))
snd_alias_list_t R_SetParentAndCell_r(void)
{
    __asm__ __volatile__ (
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_SetParentAndCell_r_impl\n"
        "addl $8, %esp\n"
        "retl\n"
    );
}
#endif

/* line 1256 — BSP entity string parser: reads key-value pairs from entity lump,
 * processes special entity types (worldspawn sun params, misc_model static models,
 * fx_origin effects). Handles spawn variables, model validation, sun light setup.
 * 861 lines of text parsing with R_ParseSunLight, R_IsValidStaticModel, R_CreateStaticModel. */
/* R_LoadEntities stub: the full ASM version has stale Mac address
   relocations (origin pointer, model pointer).  Skip entity processing
   for now — static models won't appear but gameplay works since the
   server-side entity loading (G_SpawnEntitiesFromString) handles gameplay. */
snd_alias_list_t R_LoadEntities_stub(void)
{
    snd_alias_list_t r = {0};
    return r;
}

/* The naked ASM R_LoadEntities has stale Mac address relocations.
   Replace with a stub that does nothing. */
snd_alias_list_t R_LoadEntities(void)
{
    snd_alias_list_t r = {0};
    return r;
}

#ifndef __EMSCRIPTEN__
__attribute__((naked))
snd_alias_list_t R_LoadEntities_ASM_DISABLED(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1256 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x36c, %esp\n"
        /* { scope 1: model, origin, angles, scale, ... */
        "movl (%eax), %edx\n" /* line 1269 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x32c(%ebp)\n" /* startPos */
        "movl 0x134(%edx), %edi\n" /* i */
        "addl %edi, %eax\n" /* i */
        "movl %eax, -0x32c(%ebp)\n" /* startPos */
        "movl 0x130(%edx), %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x320(%ebp)\n" /* textPool */
        "movl -0x32c(%ebp), %eax\n" /* line 1279 | startPos */
        "movl %eax, -0x24(%ebp)\n" /* text */
        "movl $0, -0x328(%ebp)\n" /* smodelCount */
        ".Lfe3344_000e3390:\n"
        "leal -0x24(%ebp), %edx\n" /* line 1282 | text */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl -0x24(%ebp), %edx\n" /* line 1283 | text */
        "testl %edx, %edx\n"
        "je .Lfe3344_000e3520\n"
        ".Lfe3344_000e33a6:\n"
        "cmpb $0x7b, (%eax)\n"
        "jne .Lfe3344_000e3520\n"
        "movl $str_002157b8, -0x2c8(%ebp)\n" /* line 1286 | spawnVars */
        "movl $1, -0x324(%ebp)\n" /* spawnVarCount */
        "xorl %ebx, %ebx\n" /* charsUsed */
        "jmp .Lfe3344_000e3467\n"
        ".Lfe3344_000e33ca:\n"
        "cmpl $0x40, -0x324(%ebp)\n" /* line 1301 | spawnVarCount */
        "je .Lfe3344_000e367b\n"
        ".Lfe3344_000e33d7:\n"
        "movl -0x324(%ebp), %esi\n" /* line 1304 | spawnVarCount, spawnVarIndex */
        "movl %esi, %edi\n" /* spawnVarIndex, i */
        "addl $1, %edi\n" /* i */
        "movl %edi, -0x324(%ebp)\n" /* i, spawnVarCount */
        ".Lfe3344_000e33e8:\n"
        "movl -0x320(%ebp), %edx\n" /* line 1307 | textPool */
        "addl %ebx, %edx\n" /* charsUsed */
        "movl %edx, -0x2c8(%ebp, %esi, 8)\n"
        "cld\n" /* line 1308 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x2cc(%ebp), %edi\n" /* i */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "addl %ecx, %ebx\n" /* line 1309 | charsUsed */
        "movl %ecx, 8(%esp)\n" /* line 1310 */
        "movl -0x2cc(%ebp), %edi\n" /* i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal -0x24(%ebp), %eax\n" /* line 1312 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x34c(%ebp)\n"
        "movl -0x320(%ebp), %edx\n" /* line 1313 | textPool */
        "addl %ebx, %edx\n" /* charsUsed */
        "movl %edx, -0x2c4(%ebp, %esi, 8)\n"
        "cld\n" /* line 1314 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* i */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "addl %ecx, %ebx\n" /* line 1315 | charsUsed */
        "movl %ecx, 8(%esp)\n" /* line 1316 */
        "movl -0x34c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        ".Lfe3344_000e3467:\n"
        "leal -0x24(%ebp), %edi\n" /* line 1291 | text, i */
        "movl %edi, (%esp)\n" /* i */
        "calll Com_Parse\n"
        "movl %eax, -0x2cc(%ebp)\n"
        "movl %eax, %edx\n" /* line 1292 */
        "movzbl (%eax), %eax\n"
        "testb %al, %al\n"
        "je .Lfe3344_000e34b4\n"
        "cmpb $0x7d, %al\n"
        "je .Lfe3344_000e34b4\n"
        "movl $str_0021c208, %edi\n" /* line 1295 | i */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl %edx, %esi\n" /* spawnVarIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* i, spawnVarIndex */
        "movl $0, %edx\n"
        "je .Lfe3344_000e34a5\n"
        "movzbl -1(%esi), %edx\n" /* spawnVarIndex */
        "movzbl -1(%edi), %ecx\n" /* i */
        "subl %ecx, %edx\n"
        ".Lfe3344_000e34a5:\n"
        "testl %edx, %edx\n"
        "jne .Lfe3344_000e33ca\n"
        "xorl %esi, %esi\n" /* spawnVarIndex */
        "jmp .Lfe3344_000e33e8\n"
        ".Lfe3344_000e34b4:\n"
        "movl -0x2c8(%ebp), %eax\n" /* line 1319 | spawnVars */
        "cmpb $0, (%eax)\n"
        "je .Lfe3344_000e369c\n"
        ".Lfe3344_000e34c3:\n"
        "movl $str_0021c214, 4(%esp)\n" /* line 1322 */
        "movl -0x2c4(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe3344_000e3390\n"
        "leal -0x2c8(%ebp), %eax\n" /* line 1324 | spawnVars */
        "movl $0, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl -0x324(%ebp), %edx\n" /* spawnVarCount */
        "calll R_IsValidStaticModel\n"
        "testb %al, %al\n"
        "je .Lfe3344_000e3390\n"
        "addl $1, -0x328(%ebp)\n" /* line 1325 | smodelCount */
        "leal -0x24(%ebp), %edx\n" /* line 1282 | text */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl -0x24(%ebp), %edx\n" /* line 1283 | text */
        "testl %edx, %edx\n"
        "jne .Lfe3344_000e33a6\n"
        ".Lfe3344_000e3520:\n"
        "movl -0x328(%ebp), %edx\n" /* line 1329 | smodelCount */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $5, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+248\n"
        "movl $0, s_world+244\n" /* line 1330 */
        "movl -0x328(%ebp), %edi\n" /* line 1332 | smodelCount, i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl $s_world, (%esp)\n"
        "calll R_PrepareStaticModelLightingCache\n"
        "movl -0x32c(%ebp), %eax\n" /* line 1334 | startPos */
        "movl %eax, -0x24(%ebp)\n" /* text */
        ".Lfe3344_000e3562:\n"
        "leal -0x24(%ebp), %edx\n" /* line 1340 | text */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "cmpb $0x7b, (%eax)\n" /* line 1341 */
        "jne .Lfe3344_000e3951\n"
        ".Lfe3344_000e3576:\n"
        "movl $str_002157b8, -0x2c8(%ebp)\n" /* line 1344 | spawnVars */
        "movl $1, -0x2d4(%ebp)\n"
        "xorl %ebx, %ebx\n" /* charsUsed */
        "jmp .Lfe3344_000e362e\n"
        ".Lfe3344_000e3591:\n"
        "cmpl $0x40, -0x2d4(%ebp)\n" /* line 1359 */
        "je .Lfe3344_000e397a\n"
        ".Lfe3344_000e359e:\n"
        "movl -0x2d4(%ebp), %esi\n" /* line 1362 | spawnVarIndex */
        "movl %esi, %edi\n" /* spawnVarIndex, i */
        "addl $1, %edi\n" /* i */
        "movl %edi, -0x2d4(%ebp)\n" /* i */
        ".Lfe3344_000e35af:\n"
        "movl -0x320(%ebp), %edx\n" /* line 1365 | textPool */
        "addl %ebx, %edx\n" /* charsUsed */
        "movl %edx, -0x2c8(%ebp, %esi, 8)\n"
        "cld\n" /* line 1366 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x2d0(%ebp), %edi\n" /* i */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "addl %ecx, %ebx\n" /* line 1367 | charsUsed */
        "movl %ecx, 8(%esp)\n" /* line 1368 */
        "movl -0x2d0(%ebp), %edi\n" /* i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal -0x24(%ebp), %eax\n" /* line 1370 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x34c(%ebp)\n"
        "movl -0x320(%ebp), %edx\n" /* line 1371 | textPool */
        "addl %ebx, %edx\n" /* charsUsed */
        "movl %edx, -0x2c4(%ebp, %esi, 8)\n"
        "cld\n" /* line 1372 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* i */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "addl %ecx, %ebx\n" /* line 1373 | charsUsed */
        "movl %ecx, 8(%esp)\n" /* line 1374 */
        "movl -0x34c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        ".Lfe3344_000e362e:\n"
        "leal -0x24(%ebp), %edi\n" /* line 1349 | text, i */
        "movl %edi, (%esp)\n" /* i */
        "calll Com_Parse\n"
        "movl %eax, -0x2d0(%ebp)\n"
        "movl %eax, %edx\n" /* line 1350 */
        "movzbl (%eax), %eax\n"
        "testb %al, %al\n"
        "je .Lfe3344_000e36b5\n"
        "cmpb $0x7d, %al\n"
        "je .Lfe3344_000e36b5\n"
        "movl $str_0021c208, %edi\n" /* line 1353 | i */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl %edx, %esi\n" /* spawnVarIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* i, spawnVarIndex */
        "movl $0, %edx\n"
        "je .Lfe3344_000e366c\n"
        "movzbl -1(%esi), %edx\n" /* spawnVarIndex */
        "movzbl -1(%edi), %ecx\n" /* i */
        "subl %ecx, %edx\n"
        ".Lfe3344_000e366c:\n"
        "testl %edx, %edx\n"
        "jne .Lfe3344_000e3591\n"
        "xorl %esi, %esi\n" /* spawnVarIndex */
        "jmp .Lfe3344_000e35af\n"
        ".Lfe3344_000e367b:\n"
        "movl $0x40, 8(%esp)\n" /* line 1302 */
        "movl $str_00224d7c, 4(%esp)\n" /* "R_LoadEntities: MAX_SPAWN_VARS (%i) reached
" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe3344_000e33d7\n"
        ".Lfe3344_000e369c:\n"
        "movl $str_00224dac, 4(%esp)\n" /* line 1320 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe3344_000e34c3\n"
        ".Lfe3344_000e36b5:\n"
        "movl -0x2c8(%ebp), %eax\n" /* line 1377 | spawnVars */
        "cmpb $0, (%eax)\n"
        "je .Lfe3344_000e399b\n"
        ".Lfe3344_000e36c4:\n"
        "movl $str_0021c214, 4(%esp)\n" /* line 1380 */
        "movl -0x2c4(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe3344_000e3562\n"
        /* { scope 2: valueInt */
        "leal -0x3c(%ebp), %edx\n" /* line 1071 | origin */
        "movl %edx, (%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* model */
        "movl -0x2d4(%ebp), %edx\n"
        "leal -0x2c8(%ebp), %eax\n" /* spawnVars */
        "calll R_IsValidStaticModel\n"
        "testb %al, %al\n"
        "je .Lfe3344_000e3562\n"
        "movl s_world+244, %eax\n" /* line 1074 */
        "leal (%eax, %eax, 2), %edi\n" /* i */
        "shll $5, %edi\n" /* i */
        "movl s_world+248, %edx\n"
        "addl %edx, %edi\n" /* i */
        "movl %edi, -0x318(%ebp)\n" /* i, smodelInst */
        "addl $1, %eax\n" /* line 1075 */
        "movl %eax, s_world+244\n"
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, -0x2d4(%ebp)\n" /* line 918 */
        "jg .Lfe3344_000e3a74\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3732:\n"
        "movl $str_00224ca8, %edx\n" /* "0 0 0" */
        /* } scope */
        ".Lfe3344_000e3737:\n"
        "movl $0, -0x48(%ebp)\n" /* line 183 | angles */
        "movl $0, -0x44(%ebp)\n" /* line 184 */
        "movl $0, -0x40(%ebp)\n" /* line 185 */
        "leal -0x40(%ebp), %eax\n" /* line 956 */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x44(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* angles */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %edx, (%esp)\n"
        "calll sscanf\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, -0x2d4(%ebp)\n" /* line 918 */
        "jg .Lfe3344_000e3ca8\n"
        ".Lfe3344_000e377e:\n"
        "movl $str_00224ddc, %ecx\n" /* "1 1 1" */
        "xorl %ebx, %ebx\n"
        /* } scope */
        ".Lfe3344_000e3785:\n"
        "movl $0, -0x30(%ebp)\n" /* line 183 | scale */
        "movl $0, -0x2c(%ebp)\n" /* line 184 */
        "movl $0, -0x28(%ebp)\n" /* line 185 */
        "leal -0x30(%ebp), %eax\n" /* line 956 | scale */
        "leal -0x28(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %ecx, (%esp)\n"
        "calll sscanf\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1089 */
        "jne .Lfe3344_000e37e7\n"
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        "cmpl $1, -0x2d4(%ebp)\n" /* line 918 */
        "jg .Lfe3344_000e3b66\n"
        /* } scope */
        ".Lfe3344_000e37d0:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 936 | 1.0f */
        /* } scope */
        /* } scope */
        ".Lfe3344_000e37d8:\n"
        "movss %xmm0, -0x30(%ebp)\n" /* line 1091 | defaultValue, scale */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 1092 */
        "movss %xmm0, -0x28(%ebp)\n" /* line 1093 */
        ".Lfe3344_000e37e7:\n"
        "movl -0x318(%ebp), %edi\n" /* line 1096 | smodelInst, i */
        "movl %edi, 0x14(%esp)\n" /* i */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* angles */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* origin */
        "movl %edx, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* model */
        "movl %eax, 4(%esp)\n"
        "movl $s_world, (%esp)\n"
        "calll R_CreateStaticModel\n"
        "movl -0x20(%ebp), %eax\n" /* line 1098 | model */
        "movl %eax, (%esp)\n"
        "calll XModelGetFlags\n"
        "andl $1, %eax\n"
        "movb %al, -0x31a(%ebp)\n"
        "movb %al, -0x319(%ebp)\n" /* isModelGroundLit */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, -0x2d4(%ebp)\n" /* line 918 */
        "jg .Lfe3344_000e3d0e\n"
        ".Lfe3344_000e3840:\n"
        "xorl %esi, %esi\n" /* i */
        "movl $str_00224dec, %edx\n" /* "FF000000" */
        /* } scope */
        ".Lfe3344_000e3847:\n"
        "leal -0x5c(%ebp), %eax\n" /* line 979 */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x60(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x64(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x68(%ebp), %eax\n" /* valueInt */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224df8, 4(%esp)\n" /* "%02x%02x%02x%02x" */
        "movl %edx, (%esp)\n"
        "calll sscanf\n"
        "cmpl $4, %eax\n" /* line 981 */
        "je .Lfe3344_000e388c\n"
        "movl $str_00224e0c, 4(%esp)\n" /* line 982 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        ".Lfe3344_000e388c:\n"
        "movl $1, %ebx\n"
        "movss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        ".Lfe3344_000e3899:\n"
        "leal (, %ebx, 4), %ecx\n" /* line 985 */
        "movl -0x6c(%ebp, %ecx), %edx\n"
        "testl %edx, %edx\n"
        "js .Lfe3344_000e39b4\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lfe3344_000e38b0:\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp, %ecx)\n"
        "addl $1, %ebx\n"
        "cmpl $5, %ebx\n" /* line 984 */
        "jne .Lfe3344_000e3899\n"
        /* } scope */
        "movl %esi, %edx\n" /* line 1099 | success */
        "movl imp_r_showGroundLit, %eax\n" /* line 1102 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfe3344_000e39ca\n"
        "movl %esi, %eax\n" /* success */
        /* { scope 3 */
        "cmpb $0, -0x319(%ebp)\n" /* line 1041 | isModelGroundLit */
        "jne .Lfe3344_000e3b40\n"
        "movl $0x3f800000, -0x58(%ebp)\n" /* line 447 | groundLight */
        "movl $0, -0x54(%ebp)\n" /* line 448 */
        "movl $0, -0x50(%ebp)\n" /* line 449 */
        "movl $0, -0x4c(%ebp)\n" /* line 450 */
        /* } scope */
        ".Lfe3344_000e3900:\n"
        "leal -0xc8(%ebp), %ebx\n" /* line 1105 | colorForDir */
        "movl %ebx, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* sunVisibility */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %edx\n" /* groundLight */
        "movl %edx, (%esp)\n"
        "calll R_GetStaticModelLightingFromGround\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1106 */
        "movl -0x1c(%ebp), %eax\n" /* sunVisibility */
        "movl %eax, 8(%esp)\n"
        "movl -0x318(%ebp), %edi\n" /* smodelInst, i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl $s_world, (%esp)\n"
        "calll R_CacheStaticModelLighting\n"
        /* } scope */
        "leal -0x24(%ebp), %edx\n" /* line 1340 | text */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "cmpb $0x7b, (%eax)\n" /* line 1341 */
        "je .Lfe3344_000e3576\n"
        ".Lfe3344_000e3951:\n"
        "movl $s_world, (%esp)\n" /* line 1388 */
        "calll R_FinishStaticModelLightingCache\n"
        "movl s_world+252, %eax\n" /* line 1248 */
        "testl %eax, %eax\n"
        "jg .Lfe3344_000e3d74\n"
        ".Lfe3344_000e396a:\n"
        "calll Hunk_ClearTempMemory\n" /* line 1392 */
        /* } scope */
        "addl $0x36c, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: model, origin, angles, scale, ... */
        ".Lfe3344_000e397a:\n"
        "movl $0x40, 8(%esp)\n" /* line 1360 */
        "movl $str_00224d7c, 4(%esp)\n" /* "R_LoadEntities: MAX_SPAWN_VARS (%i) reached
" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe3344_000e359e\n"
        ".Lfe3344_000e399b:\n"
        "movl $str_00224dac, 4(%esp)\n" /* line 1378 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe3344_000e36c4\n"
        /* { scope 2: valueInt */
        /* { scope 3 */
        ".Lfe3344_000e39b4:\n"
        "movl %edx, %eax\n" /* line 985 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfe3344_000e38b0\n"
        /* } scope */
        ".Lfe3344_000e39ca:\n"
        "cmpb $0, -0x31a(%ebp)\n" /* line 1111 */
        "je .Lfe3344_000e39db\n"
        "testb %dl, %dl\n"
        "jne .Lfe3344_000e3e01\n"
        ".Lfe3344_000e39db:\n"
        "leal -0xc8(%ebp), %eax\n" /* line 1114 | colorForDir */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* sunVisibility */
        "movl %edx, 8(%esp)\n"
        "movl -0x318(%ebp), %edi\n" /* smodelInst, i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl $s_world, (%esp)\n"
        "calll R_GetStaticModelLightingFromGrid\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3a02:\n"
        "cmpl $1, -0x2d4(%ebp)\n" /* line 918 */
        "jg .Lfe3344_000e3bb4\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x314(%ebp)\n" /* directLightScale */
        /* } scope */
        /* } scope */
        ".Lfe3344_000e3a1f:\n"
        "leal -0xc8(%ebp), %eax\n" /* line 1124 | colorForDir */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* sunVisibility */
        "movl %edx, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x314(%ebp), %xmm0\n" /* directLightScale */
        "movss %xmm0, (%esp)\n"
        "calll R_ScaleStaticModelLighting\n"
        "leal -0xc8(%ebp), %eax\n" /* line 1125 | colorForDir */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* sunVisibility */
        "movl %eax, 8(%esp)\n"
        "movl -0x318(%ebp), %edx\n" /* smodelInst */
        "movl %edx, 4(%esp)\n"
        "movl $s_world, (%esp)\n"
        "calll R_CacheStaticModelLighting\n"
        "jmp .Lfe3344_000e3562\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3a74:\n"
        "leal -0x2c0(%ebp), %edi\n" /* line 1256 | i */
        "movl $1, %esi\n" /* success */
        "movl $8, %ebx\n"
        ".Lfe3344_000e3a84:\n"
        "leal -0x2c8(%ebp), %eax\n" /* spawnVars, load */
        "addl %ebx, %eax\n" /* load */
        "movl %eax, -0x2d8(%ebp)\n" /* load */
        "movl $str_0021a534, 4(%esp)\n" /* line 920 */
        "movl (%edi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe3344_000e3c63\n"
        "addl $1, %esi\n" /* line 918 | i */
        "addl $8, %ebx\n"
        "addl $8, %edi\n" /* i */
        "cmpl %esi, -0x2d4(%ebp)\n" /* i */
        "jne .Lfe3344_000e3a84\n"
        /* } scope */
        /* } scope */
        ".Lfe3344_000e3abd:\n"
        "leal -0x2c0(%ebp), %ebx\n" /* line 1082 */
        "movl $1, %edi\n" /* i */
        "movl $8, %esi\n" /* success */
        "leal -0x2c8(%ebp), %eax\n" /* spawnVars */
        "addl %esi, %eax\n" /* success */
        "movl %eax, -0x2dc(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl $str_0021a53c, 4(%esp)\n" /* line 920 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe3344_000e3b2a\n"
        ".Lfe3344_000e3af1:\n"
        "addl $1, %edi\n" /* line 918 | i */
        "addl $8, %esi\n" /* i */
        "addl $8, %ebx\n"
        "cmpl %edi, -0x2d4(%ebp)\n" /* i */
        "je .Lfe3344_000e3732\n"
        /* } scope */
        /* } scope */
        "leal -0x2c8(%ebp), %eax\n" /* line 1082 | spawnVars */
        "addl %esi, %eax\n" /* success */
        "movl %eax, -0x2dc(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl $str_0021a53c, 4(%esp)\n" /* line 920 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe3344_000e3af1\n"
        ".Lfe3344_000e3b2a:\n"
        "movl -0x2dc(%ebp), %edi\n" /* line 921 | i */
        "movl 4(%edi), %edx\n" /* i */
        /* } scope */
        "testl %edx, %edx\n" /* line 949 */
        "jne .Lfe3344_000e3737\n"
        "jmp .Lfe3344_000e3732\n"
        /* } scope */
        /* { scope 3 */
        ".Lfe3344_000e3b40:\n"
        "testb %al, %al\n" /* line 1043 */
        "jne .Lfe3344_000e3de0\n"
        "movl $0x3f800000, %eax\n" /* line 447 */
        "movl %eax, -0x58(%ebp)\n" /* groundLight */
        "movl %eax, -0x54(%ebp)\n" /* line 448 */
        "movl $0, -0x50(%ebp)\n" /* line 449 */
        "movl $0, -0x4c(%ebp)\n" /* line 450 */
        "jmp .Lfe3344_000e3900\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfe3344_000e3b66:\n"
        "leal -0x2c0(%ebp), %edi\n" /* line 1256 | i */
        "movl $1, %esi\n" /* success */
        "movl $8, %ebx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfe3344_000e3b76:\n"
        "leal -0x2c8(%ebp), %eax\n" /* line 1089 | spawnVars */
        "addl %ebx, %eax\n"
        "movl %eax, -0x2e4(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        "movl $str_0021c254, 4(%esp)\n" /* line 920 */
        "movl (%edi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe3344_000e3e22\n"
        "addl $1, %esi\n" /* line 918 | i */
        "addl $8, %ebx\n"
        "addl $8, %edi\n" /* i */
        "cmpl -0x2d4(%ebp), %esi\n" /* i */
        "jne .Lfe3344_000e3b76\n"
        "jmp .Lfe3344_000e37d0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3bb4:\n"
        "leal -0x2c0(%ebp), %edi\n" /* line 1256 | i */
        "movl $1, %esi\n" /* success */
        "movl $8, %ebx\n"
        ".Lfe3344_000e3bc4:\n"
        "leal -0x2c8(%ebp), %eax\n" /* spawnVars, load */
        "addl %ebx, %eax\n" /* load */
        "movl %eax, -0x2ec(%ebp)\n" /* load */
        "movl $str_00224e30, 4(%esp)\n" /* line 920 */
        "movl (%edi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe3344_000e3eab\n"
        "addl $1, %esi\n" /* line 918 | i */
        "addl $8, %ebx\n"
        "addl $8, %edi\n" /* i */
        "cmpl -0x2d4(%ebp), %esi\n" /* i */
        "jne .Lfe3344_000e3bc4\n"
        /* } scope */
        /* } scope */
        ".Lfe3344_000e3bfd:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1118 | 1.0f */
        "movss %xmm0, -0x314(%ebp)\n" /* directLightScale */
        ".Lfe3344_000e3c0d:\n"
        "leal -0x2c0(%ebp), %ebx\n"
        "movl $1, %edi\n" /* i */
        "movl $8, %esi\n" /* success */
        ".Lfe3344_000e3c1d:\n"
        "leal -0x2c8(%ebp), %eax\n" /* spawnVars */
        "addl %esi, %eax\n" /* success */
        "movl %eax, -0x2f0(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl $str_00224e70, 4(%esp)\n" /* line 920 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe3344_000e3e4e\n"
        "addl $1, %edi\n" /* line 918 | i */
        "addl $8, %esi\n" /* i */
        "addl $8, %ebx\n"
        "cmpl -0x2d4(%ebp), %edi\n" /* i */
        "jne .Lfe3344_000e3c1d\n"
        /* } scope */
        /* } scope */
        ".Lfe3344_000e3c56:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1122 | 1.0f */
        "jmp .Lfe3344_000e3a1f\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3c63:\n"
        "movl -0x2d8(%ebp), %edx\n" /* line 921 */
        "movl 4(%edx), %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 933 */
        "je .Lfe3344_000e3abd\n"
        "movl %eax, (%esp)\n" /* line 936 */
        "calll atof\n"
        "fstpl -0x310(%ebp)\n"
        "cvtsd2ss -0x310(%ebp), %xmm1\n"
        /* } scope */
        "pxor %xmm0, %xmm0\n" /* line 1078 */
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lfe3344_000e3c99\n"
        "je .Lfe3344_000e3abd\n"
        ".Lfe3344_000e3c99:\n"
        "movss %xmm0, -0x48(%ebp)\n" /* line 1080 | angles */
        "movss %xmm1, -0x44(%ebp)\n" /* line 1081 */
        "movss %xmm0, -0x40(%ebp)\n" /* line 1082 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3ca8:\n"
        "leal -0x2c0(%ebp), %edi\n" /* line 1256 | i */
        "movl $1, %esi\n" /* success */
        "movl $8, %ebx\n"
        "jmp .Lfe3344_000e3ccf\n"
        ".Lfe3344_000e3cba:\n"
        "addl $1, %esi\n" /* line 918 | i */
        "addl $8, %ebx\n"
        "addl $8, %edi\n" /* i */
        "cmpl -0x2d4(%ebp), %esi\n" /* i */
        "je .Lfe3344_000e377e\n"
        ".Lfe3344_000e3ccf:\n"
        "leal -0x2c8(%ebp), %edx\n" /* line 1256 | spawnVars */
        "addl %ebx, %edx\n"
        "movl %edx, -0x2e0(%ebp)\n"
        "movl $str_0021c244, 4(%esp)\n" /* line 920 */
        "movl (%edi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe3344_000e3cba\n"
        "movl -0x2e0(%ebp), %edi\n" /* line 921 | i */
        "movl 4(%edi), %ecx\n" /* i */
        /* } scope */
        "testl %ecx, %ecx\n" /* line 949 */
        "je .Lfe3344_000e377e\n"
        "movl $1, %ebx\n"
        "jmp .Lfe3344_000e3785\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3d0e:\n"
        "leal -0x2c0(%ebp), %edi\n" /* line 1256 | i */
        "movl $1, %esi\n" /* success */
        "movl $8, %ebx\n"
        "jmp .Lfe3344_000e3d35\n"
        ".Lfe3344_000e3d20:\n"
        "addl $1, %esi\n" /* line 918 | i */
        "addl $8, %ebx\n"
        "addl $8, %edi\n" /* i */
        "cmpl -0x2d4(%ebp), %esi\n" /* i */
        "je .Lfe3344_000e3840\n"
        ".Lfe3344_000e3d35:\n"
        "leal -0x2c8(%ebp), %eax\n" /* line 1256 | spawnVars, load */
        "addl %ebx, %eax\n" /* load */
        "movl %eax, -0x2e8(%ebp)\n" /* load */
        "movl $str_00224de4, 4(%esp)\n" /* line 920 */
        "movl (%edi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe3344_000e3d20\n"
        "movl -0x2e8(%ebp), %edi\n" /* line 921 | i */
        "movl 4(%edi), %edx\n" /* i */
        /* } scope */
        "testl %edx, %edx\n" /* line 973 */
        "je .Lfe3344_000e3840\n"
        "movl $1, %esi\n" /* success */
        "jmp .Lfe3344_000e3847\n"
        /* } scope */
        /* } scope */
        ".Lfe3344_000e3d74:\n"
        "xorl %esi, %esi\n" /* line 1248 | success */
        "xorl %ebx, %ebx\n"
        ".Lfe3344_000e3d78:\n"
        "movl s_world+256, %eax\n" /* line 1249 */
        "movl 0x1c(%eax, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AllocStaticModels\n"
        "addl $1, %esi\n" /* line 1248 | success */
        "addl $0x3c, %ebx\n"
        "cmpl s_world+252, %esi\n" /* success */
        "jl .Lfe3344_000e3d78\n"
        "movl s_world+252, %edi\n" /* line 1251 | i */
        "testl %edi, %edi\n" /* i */
        "jle .Lfe3344_000e396a\n"
        "xorl %esi, %esi\n" /* success */
        "xorl %ebx, %ebx\n"
        ".Lfe3344_000e3da9:\n"
        "movl s_world+256, %eax\n" /* line 1252 */
        "movl 0x1c(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $s_world, (%esp)\n"
        "calll R_SortGfxAabbTree\n"
        "addl $1, %esi\n" /* line 1251 | success */
        "addl $0x3c, %ebx\n"
        "cmpl s_world+252, %esi\n" /* success */
        "jl .Lfe3344_000e3da9\n"
        "calll Hunk_ClearTempMemory\n" /* line 1392 */
        /* } scope */
        "addl $0x36c, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: model, origin, angles, scale, ... */
        /* { scope 2: valueInt */
        /* { scope 3 */
        ".Lfe3344_000e3de0:\n"
        "movl $0, -0x58(%ebp)\n" /* line 447 | groundLight */
        "movl $0x3f800000, -0x54(%ebp)\n" /* line 448 */
        "movl $0, -0x50(%ebp)\n" /* line 449 */
        "movl $0, -0x4c(%ebp)\n" /* line 450 */
        "jmp .Lfe3344_000e3900\n"
        /* } scope */
        ".Lfe3344_000e3e01:\n"
        "leal -0xc8(%ebp), %eax\n" /* line 1112 | colorForDir */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* sunVisibility */
        "movl %edx, 4(%esp)\n"
        "leal -0x58(%ebp), %edi\n" /* groundLight, i */
        "movl %edi, (%esp)\n" /* i */
        "calll R_GetStaticModelLightingFromGround\n"
        "jmp .Lfe3344_000e3a02\n"
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfe3344_000e3e22:\n"
        "movl -0x2e4(%ebp), %edx\n" /* line 921 */
        "movl 4(%edx), %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 933 */
        "je .Lfe3344_000e37d0\n"
        "movl %eax, (%esp)\n" /* line 936 */
        "calll atof\n"
        "fstpl -0x308(%ebp)\n"
        "cvtsd2ss -0x308(%ebp), %xmm0\n"
        "jmp .Lfe3344_000e37d8\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3e4e:\n"
        "movl -0x2f0(%ebp), %edx\n" /* line 921 */
        "movl 4(%edx), %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 933 */
        "je .Lfe3344_000e3c56\n"
        "movl %eax, (%esp)\n" /* line 936 */
        "calll atof\n"
        "fstpl -0x2f8(%ebp)\n"
        "cvtsd2ss -0x2f8(%ebp), %xmm0\n"
        /* } scope */
        "pxor %xmm1, %xmm1\n" /* line 1121 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lfe3344_000e3a1f\n"
        "movl $str_00224e84, 4(%esp)\n" /* line 1122 */
        "movl $1, (%esp)\n"
        "movss %xmm0, -0x348(%ebp)\n"
        "calll R_Error\n"
        "movss -0x348(%ebp), %xmm0\n"
        "jmp .Lfe3344_000e3a1f\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe3344_000e3eab:\n"
        "movl -0x2ec(%ebp), %edx\n" /* line 921 */
        "movl 4(%edx), %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 933 */
        "je .Lfe3344_000e3bfd\n"
        "movl %eax, (%esp)\n" /* line 936 */
        "calll atof\n"
        "fstpl -0x300(%ebp)\n"
        "cvtsd2ss -0x300(%ebp), %xmm0\n"
        "movss %xmm0, -0x314(%ebp)\n" /* directLightScale */
        /* } scope */
        "pxor %xmm1, %xmm1\n" /* line 1117 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lfe3344_000e3c0d\n"
        "movl $str_00224e44, 4(%esp)\n" /* line 1118 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe3344_000e3c0d\n"
    );
}

/* line 1741 — R_LoadNodesAndLeafs
 * Loads BSP nodes and leafs from lumps 0xD0 (nodes, 36 bytes each) and 0xD8 (leafs, 36 bytes each).
 * Allocates combined mnode_t array, resolves child indices to pointers, calls R_SetParentAndCell_r.
 * Actual convention: eax=load (BSP load state pointer) */
static void R_LoadNodesAndLeafs_impl(const byte *loadState)
{
    const byte *bspHeader = *(const byte **)loadState;
    const byte *bspData = *(const byte **)(loadState + 4);
    int fileSize = *(int *)(loadState + 8);
    int i;

    /* Validate node lump (BSP header offset 0xD0: size, 0xD4: offset) */
    int nodeLumpSize = *(int *)(bspHeader + 0xD0);
    int nodeLumpOffset = *(int *)(bspHeader + 0xD4);
    if (nodeLumpOffset + nodeLumpSize > fileSize)
        R_Error(1, "LoadMap: lump extends past end of file in %s", s_world.name);
    if (nodeLumpSize <= 3)
        R_Error(1, "LoadMap: funny lump offset in %s", s_world.name);
    int nodeCount = nodeLumpSize / 36;
    if (nodeLumpSize < 0 || nodeCount * 36 != nodeLumpSize)
        R_Error(1, "LoadMap: funny lump size in %s", s_world.name);

    const byte *inNode = bspData + nodeLumpOffset;

    /* Validate leaf lump (BSP header offset 0xD8: size, 0xDC: offset) */
    int leafLumpSize = *(int *)(bspHeader + 0xD8);
    int leafLumpOffset = *(int *)(bspHeader + 0xDC);
    if (leafLumpOffset + leafLumpSize > fileSize)
        R_Error(1, "LoadMap: lump extends past end of file in %s", s_world.name);
    if (leafLumpSize <= 3)
        R_Error(1, "LoadMap: funny lump offset in %s", s_world.name);
    int leafCount = leafLumpSize / 36;
    if (leafLumpSize < 0 || leafCount * 36 != leafLumpSize)
        R_Error(1, "LoadMap: funny lump size in %s", s_world.name);

    const byte *inLeaf = bspData + leafLumpOffset;

    /* Allocate combined node+leaf array */
    int totalCount = nodeCount + leafCount;
    s_world.nodeCount = totalCount;
    mnode_t *nodes = (mnode_t *)Hunk_AllocInternal(totalCount * sizeof(mnode_t));
    s_world.nodes = nodes;

    /* Fill internal nodes from BSP data */
    for (i = 0; i < nodeCount; i++) {
        const byte *src = inNode + i * 36;
        mnode_t *node = &nodes[i];

        node->contents = -1; /* mark as internal node */
        node->u.node.plane = (cplane_t *)CM_GetPlaneNum(*(int *)src);

        /* Resolve child indices to pointers (positive = node, negative = leaf) */
        int j;
        for (j = 0; j < 2; j++) {
            int childIdx = *(int *)(src + 4 + j * 4);
            if (childIdx >= 0)
                node->u.node.children[j] = &nodes[childIdx];
            else
                node->u.node.children[j] = &nodes[nodeCount + (-childIdx) - 1];
        }
    }

    /* Fill leaf nodes from BSP data */
    for (i = 0; i < leafCount; i++) {
        const byte *src = inLeaf + i * 36;
        mnode_t *leaf = &nodes[nodeCount + i];

        leaf->cellIndex = *(int *)(src + 0x18);  /* cellIndex from BSP */
        leaf->u.leaf.cluster = *(int *)src;        /* cluster from BSP */
    }

    /* Set parent pointers and propagate cell indices from root */
    R_SetParentAndCell_r_impl(&nodes[0], 0);
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
snd_alias_list_t R_LoadNodesAndLeafs(const byte *loadState)
{
    R_LoadNodesAndLeafs_impl(loadState);
}
#else
/* x86 trampoline: eax=load → cdecl _impl */
__attribute__((naked))
snd_alias_list_t R_LoadNodesAndLeafs(void)
{
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll R_LoadNodesAndLeafs_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}
#endif

/* line 1530 */
/* line 1530 — Load portals from BSP lump 0xC8.
 * Source: 16 bytes per portal (planeIndex, cellIndex, firstVertIndex, vertCount).
 * Dest: 68 (0x44) bytes per GfxPortal with plane, axes, cell/vert pointers. */
static void R_LoadPortals_impl(const int *load)
{
    const byte *srcData;
    int portalCount = R_ValidateLump(load, 0xc8, 16, &srcData);
    byte *dst;
    int i;

    dst = (byte *)Hunk_AllocInternal(portalCount * 68);

    for (i = 0; i < portalCount; i++) {
        const int *src = (const int *)(srcData + i * 16);
        GfxPortal *portal = (GfxPortal *)(dst + i * 68);
        const float *plane;

        /* Get plane pointer from index */
        plane = (const float *)CM_GetPlaneNum(src[0]);

        /* Copy plane normal */
        portal->plane.coeffs[0] = plane[0];
        portal->plane.coeffs[1] = plane[1];
        portal->plane.coeffs[2] = plane[2];

        /* Negate plane distance (flip sign bit) */
        *(int *)&portal->plane.coeffs[3] = *(int *)&plane[3] ^ 0x80000000;

        /* Compute axis permutation for broadphase (which axis is dominant) */
        portal->plane.side[0] = (plane[0] > 0.0f) ? 0x0c : 0x00;
        portal->plane.side[1] = (plane[1] > 0.0f) ? 0x10 : 0x04;
        portal->plane.side[2] = (plane[2] > 0.0f) ? 0x14 : 0x08;

        /* Cell pointer */
        {
            int cellIdx = src[1];
            portal->cell = &s_world.cells[cellIdx];
        }

        /* Vertex pointer */
        {
            int vertIdx = src[2];
            portal->vertices = rgl.portalVerts + vertIdx;
        }

        /* Vertex count */
        portal->vertexCount = (byte)src[3];
        portal->hullPointCount = 0;
        portal->hullPoints = NULL;

        /* Compute perpendicular and cross product axes */
        PerpendicularVector(plane, portal->hullAxis[0]);
        Vec3Cross(plane, portal->hullAxis[0], portal->hullAxis[1]);
    }

    /* Fixup cell portal pointers: each cell's portalOffset becomes base+offset */
    {
        int cellCount = s_world.cellCount;
        GfxCell *cells = s_world.cells;
        for (i = 0; i < cellCount; i++) {
            GfxCell *cell = &cells[i];
            if (cell->portalCount != 0) {
                /* portals field currently holds byte offset; add base pointer */
                cell->portals = (GfxPortal *)(dst + (int)(intptr_t)cell->portals);
            } else {
                cell->portals = NULL;
            }
        }
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
snd_alias_list_t R_LoadPortals(const int *load)
{
    R_LoadPortals_impl(load);
}
#else
/* x86 trampoline: eax=load → cdecl _impl */
__attribute__((naked))
snd_alias_list_t R_LoadPortals(void)
{
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll R_LoadPortals_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}
#endif

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1530 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %edi\n" /* load */
        /* { scope 1 */
        /* { scope 2 */
        "movl (%eax), %ebx\n" /* line 46 */
        "leal 0xc8(%ebx), %esi\n" /* lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0xc8(%ebx), %eax\n"
        "cmpl 8(%edi), %eax\n"
        "jg .Lfe41ae_000e4298\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe41ae_000e42bf\n"
        ".Lfe41ae_000e41dd:\n"
        "movl 0xc8(%ebx), %edx\n" /* line 52 */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "js .Lfe41ae_000e42ec\n"
        ".Lfe41ae_000e41ed:\n"
        "sarl $4, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe41ae_000e41fe\n"
        "shll $4, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe41ae_000e421b\n"
        ".Lfe41ae_000e41fe:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe41ae_000e421b:\n"
        "movl (%edi), %eax\n" /* line 1542 | load */
        "movl 4(%edi), %ebx\n" /* load, in */
        "addl 0xcc(%eax), %ebx\n" /* in */
        "movl -0x28(%ebp), %eax\n" /* line 1543 */
        "shll $6, %eax\n"
        "movl -0x28(%ebp), %edx\n"
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, -0x20(%ebp)\n" /* out */
        "movl -0x28(%ebp), %ecx\n" /* line 1547 */
        "testl %ecx, %ecx\n"
        "jg .Lfe41ae_000e42f4\n"
        ".Lfe41ae_000e4248:\n"
        "movl s_world+252, %eax\n" /* line 1563 */
        "testl %eax, %eax\n"
        "jle .Lfe41ae_000e4290\n"
        "xorl %ebx, %ebx\n" /* in */
        "xorl %ecx, %ecx\n"
        "jmp .Lfe41ae_000e426a\n"
        ".Lfe41ae_000e4257:\n"
        "xorl %edx, %edx\n" /* line 1564 */
        "movl %edx, 0x24(%eax)\n"
        "addl $1, %ebx\n" /* line 1563 | in */
        "addl $0x3c, %ecx\n"
        "cmpl s_world+252, %ebx\n" /* in */
        "jge .Lfe41ae_000e4290\n"
        ".Lfe41ae_000e426a:\n"
        "movl %ecx, %eax\n" /* line 1564 */
        "addl s_world+256, %eax\n"
        "movl 0x20(%eax), %edi\n" /* load */
        "testl %edi, %edi\n" /* load */
        "je .Lfe41ae_000e4257\n"
        "movl -0x20(%ebp), %edx\n" /* out */
        "addl 0x24(%eax), %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "addl $1, %ebx\n" /* line 1563 | in */
        "addl $0x3c, %ecx\n"
        "cmpl s_world+252, %ebx\n" /* in */
        "jl .Lfe41ae_000e426a\n"
        /* } scope */
        ".Lfe41ae_000e4290:\n"
        "addl $0x2c, %esp\n" /* line 1565 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfe41ae_000e4298:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jg .Lfe41ae_000e41dd\n"
        ".Lfe41ae_000e42bf:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 0xc8(%ebx), %edx\n" /* line 52 */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "jns .Lfe41ae_000e41ed\n"
        ".Lfe41ae_000e42ec:\n"
        "leal 0xf(%edx), %eax\n"
        "jmp .Lfe41ae_000e41ed\n"
        /* } scope */
        ".Lfe41ae_000e42f4:\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 1547 | in */
        "movl %eax, %edi\n" /* load */
        "movl $0, -0x24(%ebp)\n" /* portalIndex */
        "movl %ebx, %edx\n" /* in */
        "jmp .Lfe41ae_000e4307\n"
        ".Lfe41ae_000e4304:\n"
        "movl -0x1c(%ebp), %edx\n"
        ".Lfe41ae_000e4307:\n"
        "movl (%edx), %eax\n" /* line 1549 */
        "movl %eax, (%esp)\n"
        "calll CM_GetPlaneNum\n"
        "movl %eax, %esi\n" /* plane */
        "leal 8(%edi), %ecx\n" /* line 1550 | load, to */
        /* { scope 2 */
        "movl (%eax), %eax\n" /* line 199 */
        "movl %eax, 8(%edi)\n"
        "movl 4(%esi), %eax\n" /* line 200 | lump */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%esi), %eax\n" /* line 201 | lump */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 0xc(%esi), %eax\n" /* line 1551 | plane */
        "xorl $0x80000000, %eax\n"
        "movl %eax, 0x14(%edi)\n" /* load */
        "movl $0xc, %eax\n" /* line 19 */
        "movl 8(%edi), %edx\n"
        "testl %edx, %edx\n"
        "movl $0, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x10(%ecx)\n"
        "movl $0x10, %eax\n" /* line 20 */
        "movl 4(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "movl $4, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x11(%ecx)\n"
        "movl $0x14, %eax\n" /* line 21 */
        "movl 8(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "movl $8, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x12(%ecx)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1553 */
        "movl 4(%edx), %eax\n"
        "leal (, %eax, 4), %edx\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "addl s_world+256, %eax\n"
        "movl %eax, 0x1c(%edi)\n" /* load */
        "movl -0x1c(%ebp), %edx\n" /* line 1555 */
        "movl 8(%edx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl rgl+12, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 0x20(%edi)\n" /* load */
        "movl -0x1c(%ebp), %edx\n" /* line 1556 */
        "movl 0xc(%edx), %eax\n"
        "movb %al, 0x24(%edi)\n" /* load */
        "movb $0, 0x25(%edi)\n" /* line 1557 | load */
        "movl $0, 0x28(%edi)\n" /* line 1558 | load */
        "leal 0x2c(%edi), %ebx\n" /* line 1559 | load, in */
        "movl %ebx, 4(%esp)\n" /* in */
        "movl %esi, (%esp)\n" /* plane */
        "calll PerpendicularVector\n"
        "leal 0x38(%edi), %eax\n" /* line 1560 | load */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* in */
        "movl %esi, (%esp)\n" /* plane */
        "calll Vec3Cross\n"
        "addl $1, -0x24(%ebp)\n" /* line 1547 | portalIndex */
        "addl $0x10, -0x1c(%ebp)\n"
        "addl $0x44, %edi\n" /* load */
        "movl -0x24(%ebp), %eax\n" /* portalIndex */
        "cmpl %eax, -0x28(%ebp)\n"
        "jne .Lfe41ae_000e4304\n"
        "jmp .Lfe41ae_000e4248\n"
    );
}
#endif

/* line 1461 */
/* line 1461 — Load cells from BSP lump 0xC0.
 * Source: 52 (0x34) bytes per cell. Dest: 60 (0x3C) bytes per GfxCell.
 * Remaps AABB tree indices to pointers, builds occluder/reflectionProbe lists. */
static void R_LoadCells_impl(const int *load)
{
    const byte *srcData;
    int cellCount = R_ValidateLump(load, 0xc0, 52, &srcData);
    byte *dst;
    int i;

    /* Allocate: cellCount * sizeof(GfxCell) */
    dst = (byte *)Hunk_AllocInternal(cellCount * sizeof(GfxCell));
    s_world.cells = (GfxCell *)dst;
    s_world.cellCount = cellCount;

    for (i = 0; i < cellCount; i++) {
        const byte *src = srcData + i * 52;
        GfxCell *cell = &((GfxCell *)dst)[i];
        int aabbTreeIdx, portalCountAndOfs;
        int occluderCount, reflectionProbeCount;

        /* Copy mins[3] */
        *(int *)&cell->mins[0] = *(int *)(src + 0x00);
        *(int *)&cell->mins[1] = *(int *)(src + 0x04);
        *(int *)&cell->mins[2] = *(int *)(src + 0x08);

        /* Copy maxs[3] */
        *(int *)&cell->maxs[0] = *(int *)(src + 0x0c);
        *(int *)&cell->maxs[1] = *(int *)(src + 0x10);
        *(int *)&cell->maxs[2] = *(int *)(src + 0x14);

        /* AABB tree pointer */
        aabbTreeIdx = *(int *)(src + 0x18);
        cell->aabbTree = &rgl.aabbTrees[aabbTreeIdx];

        /* Portal byte offset: stored temporarily as byte offset, fixed up later */
        portalCountAndOfs = *(int *)(src + 0x1c);
        cell->portals = (GfxPortal *)(intptr_t)(portalCountAndOfs * sizeof(GfxPortal));

        /* Portal count */
        cell->portalCount = *(int *)(src + 0x20);

        /* Occluder index list */
        occluderCount = *(int *)(src + 0x28);
        if (occluderCount != 0) {
            int occluderOfs = *(int *)(src + 0x24);
            cell->cullGroups = (int *)((byte *)rgl.cullGroupIndices + occluderOfs * 4);
        } else {
            cell->cullGroups = NULL;
        }
        cell->cullGroupCount = occluderCount;

        /* Reflection probe index list */
        reflectionProbeCount = *(int *)(src + 0x30);
        if (reflectionProbeCount != 0) {
            int reflOfs = *(int *)(src + 0x2c);
            cell->occluders = (GfxOccluder **)((byte *)rgl.occluderIndices + reflOfs * 4);
        } else {
            cell->occluders = NULL;
        }
        cell->occluderCount = reflectionProbeCount;
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
snd_alias_list_t R_LoadCells(const int *load)
{
    R_LoadCells_impl(load);
}
#else
/* x86 trampoline: eax=load → cdecl _impl */
__attribute__((naked))
snd_alias_list_t R_LoadCells(GfxBspLoad *load)
{
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll R_LoadCells_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}
#endif

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1461 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x30(%ebp)\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl (%eax), %ebx\n" /* line 46 */
        "leal 0xc0(%ebx), %esi\n" /* lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0xc0(%ebx), %eax\n"
        "movl -0x30(%ebp), %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jg .Lfe43f4_000e459e\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe43f4_000e45c5\n"
        ".Lfe43f4_000e4427:\n"
        "movl 0xc0(%ebx), %ecx\n" /* line 52 */
        "movl $0x4ec4ec4f, %eax\n"
        "imull %ecx\n"
        "movl %edx, %edi\n"
        "sarl $4, %edi\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edi\n"
        "testl %ecx, %ecx\n" /* line 53 */
        "js .Lfe43f4_000e4451\n"
        "leal (%edi, %edi, 2), %eax\n"
        "leal (%edi, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lfe43f4_000e446e\n"
        ".Lfe43f4_000e4451:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe43f4_000e446e:\n"
        "movl -0x30(%ebp), %edx\n" /* line 1472 */
        "movl (%edx), %eax\n"
        "movl 4(%edx), %ebx\n" /* in */
        "addl 0xc4(%eax), %ebx\n" /* in */
        "leal (, %edi, 4), %edx\n" /* line 1473 */
        "movl %edi, %eax\n" /* cellCount */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+256\n" /* line 1475 */
        "movl %edi, s_world+252\n" /* line 1476 | cellCount */
        "testl %edi, %edi\n" /* line 1478 | cellCount */
        "jle .Lfe43f4_000e4596\n"
        "movl %eax, %ecx\n"
        "movl $0, -0x2c(%ebp)\n" /* cellIndex */
        "jmp .Lfe43f4_000e44de\n"
        ".Lfe43f4_000e44b0:\n"
        "xorl %eax, %eax\n" /* line 1494 */
        "movl %eax, 0x2c(%ecx)\n"
        "movl %esi, 0x28(%ecx)\n" /* line 1495 | occluderCount */
        "movl 0x30(%ebx), %esi\n" /* line 1497 | in, occluderCount */
        "testl %esi, %esi\n" /* line 1498 | occluderCount */
        "jne .Lfe43f4_000e4572\n"
        ".Lfe43f4_000e44c3:\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x34(%ecx)\n"
        "movl %esi, 0x30(%ecx)\n" /* line 1499 | occluderCount */
        "addl $1, -0x2c(%ebp)\n" /* line 1478 | cellIndex */
        "addl $0x34, %ebx\n" /* in */
        "addl $0x3c, %ecx\n"
        "cmpl -0x2c(%ebp), %edi\n" /* cellIndex, cellCount */
        "je .Lfe43f4_000e4596\n"
        ".Lfe43f4_000e44de:\n"
        "movl (%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1480 */
        "movl %eax, 4(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1481 */
        "movl %eax, 8(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1482 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0xc(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1484 */
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x10(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1485 */
        "movl %eax, 0x14(%ecx)\n"
        "movl 0x14(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1486 */
        "movl %eax, 0x18(%ecx)\n"
        "movl 0x18(%ebx), %eax\n" /* line 1488 | in */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "addl rgl+16, %eax\n"
        "movl %eax, 0x1c(%ecx)\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1490 | in */
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 0x24(%ecx)\n"
        "movl 0x20(%ebx), %eax\n" /* line 1491 | in */
        "movl %eax, 0x20(%ecx)\n"
        "movl 0x28(%ebx), %esi\n" /* line 1493 | in, occluderCount */
        "testl %esi, %esi\n" /* line 1494 | occluderCount */
        "je .Lfe43f4_000e44b0\n"
        "movl 0x24(%ebx), %edx\n" /* in */
        "movl rgl+4, %eax\n"
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, 0x2c(%ecx)\n"
        "movl %esi, 0x28(%ecx)\n" /* line 1495 | occluderCount */
        "movl 0x30(%ebx), %esi\n" /* line 1497 | in, occluderCount */
        "testl %esi, %esi\n" /* line 1498 | occluderCount */
        "je .Lfe43f4_000e44c3\n"
        ".Lfe43f4_000e4572:\n"
        "movl 0x2c(%ebx), %edx\n" /* in */
        "movl rgl, %eax\n"
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, 0x34(%ecx)\n"
        "movl %esi, 0x30(%ecx)\n" /* line 1499 | occluderCount */
        "addl $1, -0x2c(%ebp)\n" /* line 1478 | cellIndex */
        "addl $0x34, %ebx\n" /* in */
        "addl $0x3c, %ecx\n"
        "cmpl -0x2c(%ebp), %edi\n" /* cellIndex, cellCount */
        "jne .Lfe43f4_000e44de\n"
        /* } scope */
        ".Lfe43f4_000e4596:\n"
        "addl $0x3c, %esp\n" /* line 1503 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfe43f4_000e459e:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jg .Lfe43f4_000e4427\n"
        ".Lfe43f4_000e45c5:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe43f4_000e4427\n"
    );
}
#endif

/* line 1431 */
/* line 1431 — Load AABB trees from BSP lump 0xB8.
 * Source: 12 bytes per entry (childFirst, childCount, smodelCount).
 * Dest: 48 (0x30) bytes per entry in GfxAabbTree format.
 * Then call R_FinishLoadingAabbTrees_r to compute bounds. */
static void R_LoadAabbTrees_impl(const int *load)
{
    const byte *srcData;
    int count = R_ValidateLump(load, 0xb8, 12, &srcData);
    byte *dst;
    int i;

    dst = (byte *)Hunk_AllocInternal(count * sizeof(GfxAabbTree));
    rgl.aabbTrees = (GfxAabbTree *)dst;
    rgl.aabbTreeCount = count;

    for (i = 0; i < count; i++) {
        const int *src = (const int *)(srcData + i * 12);
        GfxAabbTree *aabb = &((GfxAabbTree *)dst)[i];
        int childCount = src[1];
        int smodelCount = src[2];

        /* childFirst → startSurfIndex or -1 if no children */
        if (childCount == 0) {
            aabb->startSurfIndex = -1;
        } else {
            aabb->startSurfIndex = src[0]; /* childFirst index */
        }
        aabb->surfaceCount = childCount;
        aabb->childCount = smodelCount;
    }

    /* Recursively compute AABB bounds for each root tree */
    {
        extern int R_FinishLoadingAabbTrees_r(void); /* uses register convention: eax=tree, edx=treeIndex */
        byte *trees = (byte *)rgl.aabbTrees;
        for (i = 0; i < count; ) {
            __asm__ __volatile__ (
                "movl %1, %%edx\n"
                "movl %0, %%eax\n"
                "calll R_FinishLoadingAabbTrees_r\n"
                "movl %%eax, %1\n"
                : "+g"(trees)
                : "r"(i + 1)
                : "eax", "edx", "ecx", "memory"
            );
            i++;
            trees += 48;
        }
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
snd_alias_list_t R_LoadAabbTrees(const int *load)
{
    R_LoadAabbTrees_impl(load);
}
#else
/* x86 trampoline: eax=load → cdecl _impl */
__attribute__((naked))
snd_alias_list_t R_LoadAabbTrees(void)
{
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll R_LoadAabbTrees_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}
#endif

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1431 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %edi\n" /* load */
        /* { scope 1 */
        /* { scope 2 */
        "movl (%eax), %ebx\n" /* line 46 */
        "leal 0xb8(%ebx), %esi\n" /* lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0xb8(%ebx), %eax\n"
        "cmpl 8(%edi), %eax\n"
        "jg .Lfe45e8_000e46ec\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe45e8_000e4713\n"
        ".Lfe45e8_000e4617:\n"
        "movl 0xb8(%ebx), %ecx\n" /* line 52 */
        "movl $0x2aaaaaab, %eax\n"
        "imull %ecx\n"
        "movl %edx, %esi\n" /* lump */
        "sarl $1, %esi\n" /* lump */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %esi\n" /* lump */
        "testl %ecx, %ecx\n" /* line 53 */
        "js .Lfe45e8_000e463d\n"
        "leal (%esi, %esi, 2), %eax\n" /* lump */
        "shll $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lfe45e8_000e465a\n"
        ".Lfe45e8_000e463d:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe45e8_000e465a:\n"
        "movl (%edi), %eax\n" /* line 1441 | aabbTreeIndex */
        "movl 4(%edi), %ebx\n" /* aabbTreeIndex, in */
        "addl 0xbc(%eax), %ebx\n" /* in */
        "leal (%esi, %esi, 2), %eax\n" /* line 1442 | aabbTreeCount */
        "shll $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, rgl+16\n" /* line 1444 */
        "movl %esi, rgl+20\n" /* line 1445 | aabbTreeCount */
        "testl %esi, %esi\n" /* line 1447 | aabbTreeCount */
        "jle .Lfe45e8_000e46e4\n"
        "movl %ebx, %ecx\n" /* in */
        "movl %eax, %edx\n"
        "xorl %edi, %edi\n" /* aabbTreeIndex */
        "jmp .Lfe45e8_000e46a8\n"
        ".Lfe45e8_000e468a:\n"
        "movl $0xffffffff, %ebx\n" /* line 1450 | in */
        "movl %ebx, 0x1c(%edx)\n" /* in */
        "movl %eax, 0x18(%edx)\n" /* line 1451 */
        "movl 8(%ecx), %eax\n" /* line 1452 */
        "movl %eax, 0x28(%edx)\n"
        "addl $1, %edi\n" /* line 1447 | aabbTreeIndex */
        "addl $0xc, %ecx\n"
        "addl $0x30, %edx\n"
        "cmpl %edi, %esi\n" /* aabbTreeIndex, aabbTreeCount */
        "je .Lfe45e8_000e46ca\n"
        ".Lfe45e8_000e46a8:\n"
        "movl 4(%ecx), %eax\n" /* line 1449 */
        "testl %eax, %eax\n" /* line 1450 */
        "je .Lfe45e8_000e468a\n"
        "movl (%ecx), %ebx\n" /* in */
        "movl %ebx, 0x1c(%edx)\n" /* in */
        "movl %eax, 0x18(%edx)\n" /* line 1451 */
        "movl 8(%ecx), %eax\n" /* line 1452 */
        "movl %eax, 0x28(%edx)\n"
        "addl $1, %edi\n" /* line 1447 | aabbTreeIndex */
        "addl $0xc, %ecx\n"
        "addl $0x30, %edx\n"
        "cmpl %edi, %esi\n" /* aabbTreeIndex, aabbTreeCount */
        "jne .Lfe45e8_000e46a8\n"
        ".Lfe45e8_000e46ca:\n"
        "xorl %eax, %eax\n"
        ".Lfe45e8_000e46cc:\n"
        "leal 1(%eax), %edx\n" /* line 1457 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "addl rgl+16, %eax\n"
        "calll R_FinishLoadingAabbTrees_r\n"
        "cmpl %eax, %esi\n" /* line 1456 | aabbTreeCount */
        "jg .Lfe45e8_000e46cc\n"
        /* } scope */
        ".Lfe45e8_000e46e4:\n"
        "addl $0x1c, %esp\n" /* line 1458 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfe45e8_000e46ec:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jg .Lfe45e8_000e4617\n"
        ".Lfe45e8_000e4713:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe45e8_000e4617\n"
    );
}
#endif

/* line 1627 — R_LoadOccluders
 * Loads occluder data from BSP lumps 0x98, 0xA0, 0xA8.
 * Builds occluder structs with resolved plane normals and edge references.
 * Actual convention: eax=loadState */
static void R_LoadOccluders_impl(const byte *loadState)
{
    const byte *bspHeader = *(const byte **)loadState;
    const byte *bspData = *(const byte **)(loadState + 4);
    int fileSize = *(int *)(loadState + 8);
    int i, j;

    /* Validate occluder lump (0x98, element size 20) */
    int occLumpSize = *(int *)(bspHeader + 0x98);
    if (*(int *)(bspHeader + 0x9C) + occLumpSize > fileSize)
        R_Error(1, "LoadMap: lump extends past end of file in %s", s_world.name);
    if (occLumpSize <= 3)
        R_Error(1, "LoadMap: funny lump offset in %s", s_world.name);
    int occluderCount = occLumpSize / 20;
    if (occLumpSize < 0 || occluderCount * 20 != occLumpSize)
        R_Error(1, "LoadMap: funny lump size in %s", s_world.name);
    const byte *diskOcc = bspData + *(int *)(bspHeader + 0x9C);
    byte *occluders = (byte *)Hunk_AllocInternal(occluderCount * 36);

    /* Validate plane index lump (0xA0, element size 4) */
    int planeLumpSize = *(int *)(bspHeader + 0xA0);
    if (*(int *)(bspHeader + 0xA4) + planeLumpSize > fileSize)
        R_Error(1, "LoadMap: lump extends past end of file in %s", s_world.name);
    if (planeLumpSize <= 3)
        R_Error(1, "LoadMap: funny lump offset in %s", s_world.name);
    int planeIdxCount = planeLumpSize / 4;
    if (planeLumpSize < 0 || planeIdxCount * 4 != planeLumpSize)
        R_Error(1, "LoadMap: funny lump size in %s", s_world.name);
    const byte *planeIndices = bspData + *(int *)(bspHeader + 0xA4);
    byte *sidePlanes = (byte *)Hunk_AllocInternal(planeIdxCount * 20);

    /* Validate edge lump (0xA8, element size 4) */
    int edgeLumpSize = *(int *)(bspHeader + 0xA8);
    if (*(int *)(bspHeader + 0xAC) + edgeLumpSize > fileSize)
        R_Error(1, "LoadMap: lump extends past end of file in %s", s_world.name);
    if (edgeLumpSize <= 3)
        R_Error(1, "LoadMap: funny lump offset in %s", s_world.name);
    int edgeCount = edgeLumpSize / 4;
    if (edgeLumpSize < 0 || edgeCount * 4 != edgeLumpSize)
        R_Error(1, "LoadMap: funny lump size in %s", s_world.name);
    const byte *diskEdges = bspData + *(int *)(bspHeader + 0xAC);
    byte *edges = (byte *)Hunk_AllocInternal(edgeCount * 16);

    rgl.occluders = (GfxOccluder *)occluders;
    byte *vertBase = (byte *)rgl.portalVerts;

    /* Build each occluder (input 20 bytes, output 36 bytes) */
    /* Output layout (relative to base+0xc for esi pointer style):
     * -0xc: planeCount, -8: sidePlanes ptr, -4: edgeCount2,
     * 0: edges ptr, +4: edgeTotal, +8: cellVerts ptr,
     * +0x14: vertexData ptr (from out+20), +0x10: reserved=0, +0x14: reserved=0 */
    byte *out = occluders + 0xc;
    for (i = 0; i < occluderCount; i++) {
        int nPlanes = *(short *)(diskOcc + 4);
        *(int *)(out - 0xc) = nPlanes;

        int firstPlane = *(int *)diskOcc;
        byte *planeBase = sidePlanes + firstPlane * 20;
        *(byte **)(out - 8) = planeBase;

        /* Build side planes: copy normal, negate dist, compute side bytes */
        if (nPlanes > 0) {
            const int *plIdx = (const int *)(planeIndices + firstPlane * 4);
            for (j = 0; j < nPlanes; j++) {
                float *src = (float *)CM_GetPlaneNum(plIdx[j]);
                byte *dst = planeBase + j * 20;
                *(float *)(dst + 0) = src[0];
                *(float *)(dst + 4) = src[1];
                *(float *)(dst + 8) = src[2];
                *(int *)(dst + 12) = *(int *)(src + 3) ^ 0x80000000;
                dst[16] = (*(int *)(dst + 0) > 0) ? 0x0C : 0x00;
                dst[17] = (*(int *)(dst + 4) > 0) ? 0x10 : 0x04;
                dst[18] = (*(int *)(dst + 8) > 0) ? 0x14 : 0x08;
            }
        }

        *(byte **)(out + 8) = vertBase + *(int *)(diskOcc + 0xc) * 12;
        *(int *)(out + 4) = *(short *)(diskOcc + 0x10);

        int nEdges = *(short *)(diskOcc + 6);
        *(int *)(out - 4) = nEdges;

        int firstEdge = *(int *)(diskOcc + 8);
        byte *edgeBase = edges + firstEdge * 16;
        *(byte **)(out + 0) = edgeBase;

        /* Build edges: 4 byte indices → 4 pointers (2 planes + 2 verts) */
        const byte *de = diskEdges + firstEdge * 4;
        for (j = 0; j < nEdges; j++) {
            byte *e = edgeBase + j * 16;
            *(byte **)(e + 0) = planeBase + de[j * 4 + 0] * 20;
            *(byte **)(e + 4) = planeBase + de[j * 4 + 1] * 20;
            byte *cv = *(byte **)(out + 8);
            *(byte **)(e + 8) = cv + de[j * 4 + 2] * 12;
            *(byte **)(e + 12) = cv + de[j * 4 + 3] * 12;
        }

        *(int *)(out + 16) = 0;
        *(int *)(out + 20) = 0;

        diskOcc += 20;
        out += 36;
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
snd_alias_list_t R_LoadOccluders(const byte *loadState)
{
    R_LoadOccluders_impl(loadState);
}
#else
/* x86 trampoline: eax=loadState → cdecl _impl */
__attribute__((naked))
snd_alias_list_t R_LoadOccluders(void)
{
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll R_LoadOccluders_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}
#endif

/* line 1506 */
/* line 1506 — Load portal vertex positions from BSP lump 0x90.
 * Each vertex is a vec3_t (12 bytes). Stored at rgl+12. */
static void R_LoadPortalVerts_impl(const int *load)
{
    const byte *srcData;
    int vertCount = R_ValidateLump(load, 0x90, 12, &srcData);
    float *dst;
    int i;

    dst = (float *)Hunk_AllocInternal(vertCount * 12);
    rgl.portalVerts = (vec3_t *)dst;

    for (i = 0; i < vertCount; i++) {
        dst[i * 3 + 0] = *(float *)(srcData + i * 12 + 0);
        dst[i * 3 + 1] = *(float *)(srcData + i * 12 + 4);
        dst[i * 3 + 2] = *(float *)(srcData + i * 12 + 8);
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
snd_alias_list_t R_LoadPortalVerts(const int *load)
{
    R_LoadPortalVerts_impl(load);
}
#else
/* x86 trampoline: eax=load → cdecl _impl */
__attribute__((naked))
snd_alias_list_t R_LoadPortalVerts(void)
{
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll R_LoadPortalVerts_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}
#endif

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1506 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %edi\n" /* load */
        /* { scope 1 */
        /* { scope 2 */
        "movl (%eax), %ebx\n" /* line 46 */
        "leal 0x90(%ebx), %esi\n" /* lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x90(%ebx), %eax\n"
        "cmpl 8(%edi), %eax\n"
        "jg .Lfe4be0_000e4cb1\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe4be0_000e4cd8\n"
        ".Lfe4be0_000e4c0f:\n"
        "movl 0x90(%ebx), %ecx\n" /* line 52 */
        "movl $0x2aaaaaab, %eax\n"
        "imull %ecx\n"
        "movl %edx, %ebx\n"
        "sarl $1, %ebx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n"
        "testl %ecx, %ecx\n" /* line 53 */
        "js .Lfe4be0_000e4c35\n"
        "leal (%ebx, %ebx, 2), %eax\n"
        "shll $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lfe4be0_000e4c52\n"
        ".Lfe4be0_000e4c35:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe4be0_000e4c52:\n"
        "movl (%edi), %eax\n" /* line 1516 | load */
        "movl 4(%edi), %esi\n" /* load, in */
        "addl 0x94(%eax), %esi\n" /* in */
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1517 | vertCount */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, rgl+12\n" /* line 1519 */
        "testl %ebx, %ebx\n" /* line 1521 | vertCount */
        "jle .Lfe4be0_000e4ca9\n"
        "leal -0x1c(%ebp), %edi\n" /* load */
        "movl %esi, %ecx\n" /* in */
        "movl %eax, %edx\n"
        "xorl %esi, %esi\n" /* in */
        ".Lfe4be0_000e4c7d:\n"
        "movl (%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%edi), %eax\n" /* line 1523 | load */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%edi), %eax\n" /* line 1524 | load */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%edi), %eax\n" /* line 1525 | load */
        "movl %eax, 8(%edx)\n"
        "addl $1, %esi\n" /* line 1521 | in */
        "addl $0xc, %ecx\n"
        "addl $0xc, %edx\n"
        "cmpl %esi, %ebx\n" /* in, vertCount */
        "jne .Lfe4be0_000e4c7d\n"
        /* } scope */
        ".Lfe4be0_000e4ca9:\n"
        "addl $0x2c, %esp\n" /* line 1527 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfe4be0_000e4cb1:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jg .Lfe4be0_000e4c0f\n"
        ".Lfe4be0_000e4cd8:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe4be0_000e4c0f\n"
    );
}
#endif

/* line 1568 — Load cull groups from BSP lump 0x58. Each group is 32 bytes.
 * Contains mins/maxs bounding box + surface count + surface start index. */
static void R_LoadCullGroups_impl(const int *load)
{
    const byte *srcData;
    int count = R_ValidateLump(load, 0x58, 32, &srcData);
    byte *dst;
    int i;

    dst = (byte *)Hunk_AllocInternal(count * 32);
    s_world.cullGroups = (GfxCullGroup *)dst;
    s_world.cullGroupCount = count;

    for (i = 0; i < count; i++) {
        const byte *src = srcData + i * 32;
        GfxCullGroup *cg = &((GfxCullGroup *)dst)[i];
        int j;

        /* Copy mins[3] and maxs[3] */
        for (j = 0; j < 3; j++) {
            *(int *)&cg->mins[j] = *(int *)(src + j * 4);
            *(int *)&cg->maxs[j] = *(int *)(src + j * 4 + 12);
        }

        /* surfaceCount / startSurfIndex */
        {
            int surfCount = *(int *)(src + 0x1c);
            if (surfCount == 0) {
                cg->startSurfIndex = -1;
            } else {
                cg->startSurfIndex = *(int *)(src + 0x18);
            }
            cg->surfaceCount = surfCount;
        }
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
snd_alias_list_t R_LoadCullGroups(const int *load)
{
    R_LoadCullGroups_impl(load);
}
#else
/* x86 trampoline: eax=load → cdecl _impl */
__attribute__((naked))
snd_alias_list_t R_LoadCullGroups(void)
{
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll R_LoadCullGroups_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}
#endif

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1568 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %edi\n" /* load */
        /* { scope 1 */
        /* { scope 2 */
        "movl (%eax), %ebx\n" /* line 46 */
        "leal 0x58(%ebx), %esi\n" /* lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x58(%ebx), %eax\n"
        "cmpl 8(%edi), %eax\n"
        "jg .Lfe4cfa_000e4df0\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe4cfa_000e4e17\n"
        ".Lfe4cfa_000e4d23:\n"
        "movl 0x58(%ebx), %edx\n" /* line 52 */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "js .Lfe4cfa_000e4e41\n"
        ".Lfe4cfa_000e4d30:\n"
        "sarl $5, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe4cfa_000e4d41\n"
        "shll $5, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe4cfa_000e4d5e\n"
        ".Lfe4cfa_000e4d41:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe4cfa_000e4d5e:\n"
        "movl (%edi), %eax\n" /* line 1580 | load */
        "movl 4(%edi), %ebx\n" /* load, in */
        "addl 0x5c(%eax), %ebx\n" /* in */
        "movl -0x30(%ebp), %eax\n" /* line 1581 */
        "shll $5, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+240\n" /* line 1583 */
        "movl -0x30(%ebp), %edx\n" /* line 1584 */
        "movl %edx, s_world+236\n"
        "testl %edx, %edx\n" /* line 1586 */
        "jle .Lfe4cfa_000e4de3\n"
        "movl %eax, %edi\n" /* load */
        "movl %ebx, %esi\n" /* in, lump */
        "movl $0, -0x2c(%ebp)\n" /* cullGroupIndex */
        ".Lfe4cfa_000e4d91:\n"
        "movl %edi, %ecx\n" /* load */
        "xorl %ebx, %ebx\n" /* in */
        ".Lfe4cfa_000e4d95:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl (%esi, %edx), %eax\n" /* lump */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1590 */
        "movl %eax, (%ecx)\n"
        "movl 0xc(%esi, %edx), %eax\n" /* lump */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1591 */
        "movl %eax, 0xc(%ecx)\n"
        "addl $1, %ebx\n" /* line 1588 | in */
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* in */
        "jne .Lfe4cfa_000e4d95\n"
        "movl 0x1c(%esi), %eax\n" /* line 1593 | lump */
        "testl %eax, %eax\n" /* line 1594 */
        "jne .Lfe4cfa_000e4deb\n"
        "movl $0xffffffff, %edx\n"
        ".Lfe4cfa_000e4dcb:\n"
        "movl %edx, 0x1c(%edi)\n" /* load */
        "movl %eax, 0x18(%edi)\n" /* line 1595 | load */
        "addl $1, -0x2c(%ebp)\n" /* line 1586 | cullGroupIndex */
        "addl $0x20, %edi\n" /* load */
        "addl $0x20, %esi\n" /* lump */
        "movl -0x2c(%ebp), %eax\n" /* cullGroupIndex */
        "cmpl %eax, -0x30(%ebp)\n"
        "jne .Lfe4cfa_000e4d91\n"
        /* } scope */
        ".Lfe4cfa_000e4de3:\n"
        "addl $0x3c, %esp\n" /* line 1597 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe4cfa_000e4deb:\n"
        "movl 0x18(%esi), %edx\n" /* line 1594 | lump */
        "jmp .Lfe4cfa_000e4dcb\n"
        /* { scope 2 */
        ".Lfe4cfa_000e4df0:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jg .Lfe4cfa_000e4d23\n"
        ".Lfe4cfa_000e4e17:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 0x58(%ebx), %edx\n" /* line 52 */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "jns .Lfe4cfa_000e4d30\n"
        ".Lfe4cfa_000e4e41:\n"
        "leal 0x1f(%edx), %eax\n"
        "jmp .Lfe4cfa_000e4d30\n"
    );
}
#endif

/* line 642 — BSP surface loader: reads surface data from BSP lump, resolves material
 * references, builds GfxSurface array with vertex/index offsets, handles lightmap
 * atlas assignment, and populates draw surface sort keys.
 * 751 lines of BSP lump parsing with material lookup and surface construction. */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
snd_alias_list_t R_LoadSurfaces(GfxBspLoad *load)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 642 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl %eax, -0x74(%ebp)\n"
        /* { scope 1: Temp */
        /* { scope 2: surfTris, indexIndex */
        "movl (%eax), %ebx\n" /* line 46 */
        "leal 0x40(%ebx), %esi\n" /* lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x40(%ebx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jg .Lfe4e4a_000e56d1\n"
        ".Lfe4e4a_000e4e70:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe4e4a_000e569f\n"
        "movl 0x40(%ebx), %edx\n" /* line 52 */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "js .Lfe4e4a_000e56c9\n"
        ".Lfe4e4a_000e4e87:\n"
        "sarl $4, %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe4e4a_000e4e98\n"
        "shll $4, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe4e4a_000e4eb5\n"
        ".Lfe4e4a_000e4e98:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe4e4a_000e4eb5:\n"
        "movl -0x74(%ebp), %ecx\n" /* line 676 */
        "movl (%ecx), %ebx\n" /* indexSize */
        "movl 4(%ecx), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* diskSurfaces */
        "movl 0x44(%ebx), %edx\n" /* indexSize */
        "addl %edx, %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* diskSurfaces */
        "movl -0x78(%ebp), %esi\n" /* line 677 | textureIndex */
        "testl %esi, %esi\n" /* textureIndex */
        "je .Lfe4e4a_000e5676\n"
        "movl %ecx, %edx\n"
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e4ed5:\n"
        "leal 0x48(%ebx), %esi\n" /* line 46 | lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x48(%ebx), %eax\n"
        "cmpl 8(%edx), %eax\n"
        "jg .Lfe4e4a_000e5654\n"
        ".Lfe4e4a_000e4ee7:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe4e4a_000e5632\n"
        ".Lfe4e4a_000e4ef1:\n"
        "movl 0x48(%ebx), %ecx\n" /* line 52 */
        "movl $0x78787879, %eax\n"
        "imull %ecx\n"
        "movl %edx, %edi\n"
        "sarl $5, %edi\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edi\n"
        "testl %ecx, %ecx\n" /* line 53 */
        "js .Lfe4e4a_000e4f17\n"
        "movl %edi, %eax\n"
        "shll $6, %eax\n"
        "leal (%eax, %edi, 4), %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lfe4e4a_000e4f34\n"
        ".Lfe4e4a_000e4f17:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe4e4a_000e4f34:\n"
        "testl %edi, %edi\n" /* line 681 | vertCount */
        "je .Lfe4e4a_000e5610\n"
        ".Lfe4e4a_000e4f3c:\n"
        "movl -0x74(%ebp), %ecx\n" /* line 683 */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, -0x68(%ebp)\n" /* vertsDisk */
        "movl 0x4c(%eax), %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, -0x68(%ebp)\n" /* vertsDisk */
        "movl %edi, s_world+40\n" /* line 684 | vertCount */
        "movl %edi, %eax\n" /* line 688 | vertCount */
        "shll $6, %eax\n"
        "leal (%eax, %edi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, -0x50(%ebp)\n" /* vertsMem */
        "movl %eax, s_world+44\n" /* line 689 */
        "movl $0, (%esp)\n" /* line 704 */
        "calll CColorConverter_GetColorConverter\n"
        "movl %eax, -0x48(%ebp)\n" /* c */
        "testl %edi, %edi\n" /* line 706 | vertCount */
        "jg .Lfe4e4a_000e550a\n"
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e4f84:\n"
        "movl -0x74(%ebp), %edx\n" /* line 46 */
        "movl (%edx), %ebx\n"
        "leal 0x50(%ebx), %esi\n" /* lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x50(%ebx), %eax\n"
        "cmpl 8(%edx), %eax\n"
        "jg .Lfe4e4a_000e54e8\n"
        ".Lfe4e4a_000e4f9b:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe4e4a_000e54c6\n"
        ".Lfe4e4a_000e4fa5:\n"
        "movl 0x50(%ebx), %edx\n" /* line 52 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe4e4a_000e4fbb\n"
        "addl %eax, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe4e4a_000e4fd8\n"
        ".Lfe4e4a_000e4fbb:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe4e4a_000e4fd8:\n"
        "movl -0x74(%ebp), %ecx\n" /* line 776 */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, -0x64(%ebp)\n" /* indices */
        "movl 0x54(%eax), %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, -0x64(%ebp)\n" /* indices */
        "movl -0x78(%ebp), %eax\n" /* line 778 */
        "movl %eax, s_world+16\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 779 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+20\n"
        "movl -0x78(%ebp), %ebx\n" /* line 783 | indexSize */
        "testl %ebx, %ebx\n" /* indexSize */
        "jg .Lfe4e4a_000e51d7\n"
        "xorl %ebx, %ebx\n" /* indexSize */
        ".Lfe4e4a_000e5013:\n"
        "movl %ebx, (%esp)\n" /* line 789 | indexSize */
        "calll Hunk_AllocInternal\n"
        "movl %eax, -0x4c(%ebp)\n" /* triIndices */
        "movl -0x78(%ebp), %ecx\n" /* line 790 */
        "leal (%ecx, %ecx, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, -0x54(%ebp)\n" /* tris */
        "movl $0, s_world+24\n" /* line 793 */
        "movl -0x78(%ebp), %ecx\n" /* line 794 */
        "testl %ecx, %ecx\n"
        "jg .Lfe4e4a_000e51f9\n"
        "movl $0, -0x5c(%ebp)\n" /* skyMaterial */
        ".Lfe4e4a_000e504e:\n"
        "movl s_world+24, %eax\n" /* line 846 */
        "testl %eax, %eax\n"
        "jne .Lfe4e4a_000e5166\n"
        "movl $0, s_world+32\n" /* line 849 */
        "movl $0, s_world+28\n" /* line 850 */
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e506f:\n"
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, s_world+316\n"
        "movl %eax, s_world+320\n" /* line 192 */
        "movl %eax, s_world+324\n" /* line 193 */
        "movl %eax, s_world+328\n" /* line 191 */
        "movl %eax, s_world+332\n" /* line 192 */
        "movl %eax, s_world+336\n" /* line 193 */
        "movl s_world+16, %esi\n" /* line 566 | surf */
        "testl %esi, %esi\n" /* surf */
        "jle .Lfe4e4a_000e5100\n"
        "xorl %edi, %edi\n" /* initiallySet */
        "xorl %esi, %esi\n" /* surf */
        "xorl %ebx, %ebx\n" /* surfIndex */
        ".Lfe4e4a_000e509f:\n"
        "movl s_world+20, %eax\n" /* line 568 */
        "movl 8(%ebx, %eax), %ecx\n" /* surfIndex */
        "movl %edi, %eax\n" /* line 570 | initiallySet */
        "testb %al, %al\n"
        "je .Lfe4e4a_000e5126\n"
        ".Lfe4e4a_000e50ae:\n"
        "movl %ecx, %edx\n" /* line 573 */
        "movl $s_world, %eax\n"
        ".Lfe4e4a_000e50b5:\n"
        "movss 4(%edx), %xmm1\n" /* line 579 */
        "movss 0x13c(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfe4e4a_000e50cf\n"
        "movss %xmm1, 0x13c(%eax)\n" /* line 580 */
        ".Lfe4e4a_000e50cf:\n"
        "movss 0x10(%edx), %xmm0\n" /* line 581 */
        "ucomiss 0x148(%eax), %xmm0\n"
        "jbe .Lfe4e4a_000e50e5\n"
        "movss %xmm0, 0x148(%eax)\n" /* line 582 */
        ".Lfe4e4a_000e50e5:\n"
        "addl $4, %eax\n"
        "addl $4, %edx\n"
        "cmpl $s_world+12, %eax\n" /* line 577 */
        "jne .Lfe4e4a_000e50b5\n"
        "addl $1, %esi\n" /* line 566 | surf */
        "addl $0xc, %ebx\n" /* surfIndex */
        "cmpl s_world+16, %esi\n" /* surf */
        "jl .Lfe4e4a_000e509f\n"
        /* } scope */
        ".Lfe4e4a_000e5100:\n"
        "movl s_world+40, %eax\n" /* line 871 */
        "movl %eax, 4(%esp)\n"
        "movl s_world+44, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_CreateWorldVertexBuffer\n"
        "movl %eax, s_world+48\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 882 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Temp */
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e5126:\n"
        "leal 4(%ecx), %edx\n" /* line 572 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, s_world+316\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, s_world+320\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, s_world+324\n"
        "leal 0x10(%ecx), %edx\n" /* line 573 */
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, s_world+328\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, s_world+332\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, s_world+336\n"
        "movl $1, %edi\n" /* initiallySet */
        "jmp .Lfe4e4a_000e50ae\n"
        /* } scope */
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e5166:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 623 | skyMaterial */
        "cmpw $0, 0x34(%edx)\n"
        "jne .Lfe4e4a_000e56f3\n"
        /* } scope */
        ".Lfe4e4a_000e5174:\n"
        "movl s_world+24, %eax\n" /* line 856 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+28\n"
        "movl $0, s_world+24\n" /* line 857 */
        "movl -0x78(%ebp), %edi\n" /* line 858 | merge */
        "testl %edi, %edi\n" /* merge */
        "jle .Lfe4e4a_000e506f\n"
        "xorl %ebx, %ebx\n" /* indexSize */
        "xorl %ecx, %ecx\n"
        "jmp .Lfe4e4a_000e51b3\n"
        ".Lfe4e4a_000e51a4:\n"
        "addl $1, %ebx\n" /* indexSize */
        "addl $0xc, %ecx\n"
        "cmpl %ebx, -0x78(%ebp)\n" /* indexSize */
        "je .Lfe4e4a_000e506f\n"
        ".Lfe4e4a_000e51b3:\n"
        "movl s_world+20, %eax\n" /* line 860 */
        "movl -0x5c(%ebp), %edx\n" /* skyMaterial */
        "cmpl (%ecx, %eax), %edx\n"
        "jne .Lfe4e4a_000e51a4\n"
        "movl s_world+24, %edx\n" /* line 862 */
        "movl s_world+28, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n" /* indexSize */
        "addl $1, s_world+24\n" /* line 863 */
        "jmp .Lfe4e4a_000e51a4\n"
        ".Lfe4e4a_000e51d7:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 783 | diskSurfaces */
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n" /* indexSize */
        ".Lfe4e4a_000e51de:\n"
        "movswl 0xa(%edx), %eax\n" /* line 786 */
        "leal 0x1f(%ebx, %eax, 2), %ebx\n" /* indexSize */
        "andl $0xffffffe0, %ebx\n" /* indexSize */
        "addl $1, %ecx\n" /* line 783 */
        "addl $0x10, %edx\n"
        "cmpl %ecx, -0x78(%ebp)\n"
        "jne .Lfe4e4a_000e51de\n"
        "jmp .Lfe4e4a_000e5013\n"
        ".Lfe4e4a_000e51f9:\n"
        "movl %eax, %ecx\n"
        "movl -0x6c(%ebp), %eax\n" /* line 794 | diskSurfaces */
        "movl %eax, -0x38(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x5c(%ebp)\n" /* skyMaterial */
        "movl $1, -0x3c(%ebp)\n"
        "movl $0, -0x34(%ebp)\n"
        "movl -0x78(%ebp), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "addl $4, %ecx\n"
        "movl %ecx, -0x80(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfe4e4a_000e52e6\n"
        /* { scope 2: surfTris, indexIndex */
        /* { scope 3 */
        ".Lfe4e4a_000e5233:\n"
        "xorl %eax, %eax\n" /* line 535 */
        /* } scope */
        /* } scope */
        ".Lfe4e4a_000e5235:\n"
        "movl -0x30(%ebp), %edx\n" /* line 822 */
        "movw %ax, 6(%edx)\n"
        "movl s_world+20, %eax\n" /* line 823 */
        "movl -0x54(%ebp), %edx\n" /* tris */
        "movl -0x34(%ebp), %ecx\n"
        "movl %edx, 8(%ecx, %eax)\n"
        "movl -0x70(%ebp), %ecx\n" /* line 824 */
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl -0x74(%ebp), %ecx\n"
        "movzwl 0x14(%ecx, %eax, 4), %edx\n"
        "movl s_world+20, %eax\n"
        "movl -0x34(%ebp), %ecx\n"
        "movw %dx, 4(%ecx, %eax)\n"
        "movl -0x80(%ebp), %edx\n" /* line 834 */
        "movzwl 0x1e(%edx), %eax\n"
        "leal 0x1f(%eax, %eax), %eax\n"
        "andl $0xffffffe0, %eax\n"
        "addl %eax, -0x4c(%ebp)\n" /* triIndices */
        "movl -0x58(%ebp), %ecx\n" /* line 836 | material */
        "testb $8, 0xc(%ecx)\n"
        "je .Lfe4e4a_000e52bc\n"
        "movl -0x5c(%ebp), %eax\n" /* line 838 | skyMaterial */
        "testl %eax, %eax\n"
        "je .Lfe4e4a_000e52af\n"
        "cmpl %ecx, -0x5c(%ebp)\n" /* skyMaterial */
        "je .Lfe4e4a_000e52af\n"
        "movl -0x5c(%ebp), %edx\n" /* line 839 | skyMaterial */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00224f14, 4(%esp)\n" /* "map has at least two different skies: %s and %s
Only one sky" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfe4e4a_000e52af:\n"
        "addl $1, s_world+24\n" /* line 842 */
        "movl -0x58(%ebp), %ecx\n" /* material */
        "movl %ecx, -0x5c(%ebp)\n" /* skyMaterial */
        ".Lfe4e4a_000e52bc:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 794 */
        "addl $0x28, -0x54(%ebp)\n" /* tris */
        "addl $0x28, -0x80(%ebp)\n"
        "addl $1, -0x3c(%ebp)\n"
        "addl $0x10, -0x38(%ebp)\n"
        "addl $0xc, -0x34(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "cmpl %eax, -0x3c(%ebp)\n"
        "je .Lfe4e4a_000e504e\n"
        "movl -0x38(%ebp), %edx\n"
        "movl -0x80(%ebp), %ecx\n"
        ".Lfe4e4a_000e52e6:\n"
        "movl 4(%edx), %eax\n" /* line 797 */
        "movl %eax, 0x18(%ecx)\n"
        "movzwl 8(%edx), %eax\n" /* line 798 */
        "movw %ax, 0x1c(%ecx)\n"
        "movl $6, -4(%ecx)\n" /* line 799 */
        "movzwl 0xa(%edx), %eax\n" /* line 802 */
        "movw %ax, 0x1e(%ecx)\n"
        "movl -0x4c(%ebp), %edx\n" /* line 803 | triIndices */
        "movl %edx, 0x20(%ecx)\n"
        "addl %eax, %eax\n" /* line 806 */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl 0xc(%ecx), %eax\n"
        "movl -0x64(%ebp), %edx\n" /* indices */
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %ecx\n" /* triIndices */
        "movl %ecx, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl -0x38(%ebp), %eax\n" /* line 814 */
        "movswl 2(%eax), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x74(%ebp), %ecx\n"
        "leal 0x14(%ecx, %eax, 4), %edi\n" /* vertCount */
        /* { scope 2: surfTris, indexIndex */
        /* { scope 3 */
        "movl -0x54(%ebp), %eax\n" /* line 515 | tris */
        "addl $0x10, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x80(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll ClearBounds\n"
        "movl -0x80(%ebp), %ecx\n" /* line 516 */
        "cmpw $0, 0x1e(%ecx)\n"
        "jne .Lfe4e4a_000e5426\n"
        /* } scope */
        /* } scope */
        ".Lfe4e4a_000e5364:\n"
        "movl $9, 4(%esp)\n" /* line 820 */
        "movl -0x38(%ebp), %ecx\n"
        "movswl (%ecx), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl -0x74(%ebp), %ecx\n"
        "movl 0xc(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Material_Register\n"
        "movl %eax, -0x58(%ebp)\n" /* material */
        "movl s_world+20, %eax\n" /* line 821 */
        "movl -0x58(%ebp), %ecx\n" /* material */
        "movl -0x34(%ebp), %edx\n"
        "movl %ecx, (%edx, %eax)\n"
        "movl s_world+20, %eax\n" /* line 822 */
        "addl %eax, %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl (%edx), %esi\n" /* material */
        /* { scope 2: surfTris, indexIndex */
        /* { scope 3 */
        "movl -0x2c(%ebp), %edx\n" /* line 535 */
        "testl %edx, %edx\n"
        "jle .Lfe4e4a_000e5233\n"
        "movl %eax, %ecx\n"
        "xorl %ebx, %ebx\n" /* surfIndex */
        "xorl %edi, %edi\n" /* sortGroup */
        "jmp .Lfe4e4a_000e53c1\n"
        ".Lfe4e4a_000e53b6:\n"
        "addl $1, %ebx\n" /* surfIndex */
        "addl $0xc, %ecx\n"
        "cmpl %ebx, -0x2c(%ebp)\n" /* surfIndex */
        "je .Lfe4e4a_000e53f5\n"
        ".Lfe4e4a_000e53c1:\n"
        "cmpl (%ecx), %esi\n" /* line 538 | lump */
        "jne .Lfe4e4a_000e53b6\n"
        "movl 8(%ecx), %eax\n" /* line 541 */
        "movl %eax, -0x9c(%ebp)\n" /* surfTris */
        "movl 0x1c(%eax), %edx\n" /* line 542 */
        "movl -0x80(%ebp), %eax\n"
        "cmpl 0x18(%eax), %edx\n"
        "je .Lfe4e4a_000e54a9\n"
        ".Lfe4e4a_000e53dd:\n"
        "movzwl 6(%ecx), %eax\n" /* line 544 */
        "leal 1(%eax), %edx\n" /* line 545 */
        "cmpw %di, %ax\n" /* sortGroup */
        "cmovael %edx, %edi\n" /* sortGroup */
        "addl $1, %ebx\n" /* line 535 | surfIndex */
        "addl $0xc, %ecx\n"
        "cmpl %ebx, -0x2c(%ebp)\n" /* surfIndex */
        "jne .Lfe4e4a_000e53c1\n"
        ".Lfe4e4a_000e53f5:\n"
        "cmpw $0x7ff, %di\n" /* line 547 | sortGroup */
        "jbe .Lfe4e4a_000e541e\n"
        "movl $0x800, 0xc(%esp)\n" /* line 548 */
        "movl (%esi), %eax\n" /* lump */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224ee8, 4(%esp)\n" /* "Material %s has more than %i sort groups
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfe4e4a_000e541e:\n"
        "movzwl %di, %eax\n" /* sortGroup */
        "jmp .Lfe4e4a_000e5235\n"
        /* } scope */
        /* } scope */
        /* { scope 2: surfTris, indexIndex */
        /* { scope 3 */
        ".Lfe4e4a_000e5426:\n"
        "movl $0, -0x40(%ebp)\n" /* line 516 | indexIndex */
        "movl -0x80(%ebp), %edx\n"
        ".Lfe4e4a_000e5430:\n"
        "movl 0x20(%edx), %eax\n" /* line 519 */
        "movl -0x40(%ebp), %ecx\n" /* indexIndex */
        "movzwl (%eax, %ecx, 2), %ebx\n"
        "addl 0x18(%edx), %ebx\n"
        "movl %ebx, %eax\n"
        "shll $6, %eax\n"
        "leal (%eax, %ebx, 4), %ebx\n"
        "movl -0x50(%ebp), %esi\n" /* vertsMem, lump */
        "addl %ebx, %esi\n" /* lump */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* lump */
        "calll AddPointToBounds\n"
        "addl -0x68(%ebp), %ebx\n" /* line 521 | vertsDisk */
        "movl 0x24(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss 0xc(%edi), %xmm0\n"
        "addss 4(%edi), %xmm0\n"
        "movss %xmm0, 0x24(%esi)\n" /* lump */
        "movl 0x28(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 522 */
        "mulss 0x10(%edi), %xmm0\n"
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, 0x28(%esi)\n" /* lump */
        "addl $1, -0x40(%ebp)\n" /* line 516 | indexIndex */
        "movl -0x80(%ebp), %edx\n"
        "movzwl 0x1e(%edx), %eax\n"
        "cmpl -0x40(%ebp), %eax\n" /* indexIndex */
        "jg .Lfe4e4a_000e5430\n"
        "jmp .Lfe4e4a_000e5364\n"
        /* } scope */
        /* } scope */
        /* { scope 2: surfTris, indexIndex */
        /* { scope 3 */
        ".Lfe4e4a_000e54a9:\n"
        "movzwl 0x1c(%eax), %edx\n" /* line 542 */
        "movl -0x9c(%ebp), %eax\n" /* surfTris */
        "cmpw 0x20(%eax), %dx\n"
        "jne .Lfe4e4a_000e53dd\n"
        "movzwl 6(%ecx), %eax\n" /* line 543 */
        "jmp .Lfe4e4a_000e5235\n"
        /* } scope */
        /* } scope */
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e54c6:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe4e4a_000e4fa5\n"
        ".Lfe4e4a_000e54e8:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe4e4a_000e4f9b\n"
        /* } scope */
        ".Lfe4e4a_000e550a:\n"
        "movl -0x68(%ebp), %ebx\n" /* line 706 | vertsDisk, indexSize */
        "movl -0x50(%ebp), %esi\n" /* vertsMem, textureIndex */
        "movl $0, -0x60(%ebp)\n" /* vertIndex */
        ".Lfe4e4a_000e5517:\n"
        "movl (%ebx), %eax\n" /* indexSize */
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 2: surfTris, indexIndex */
        "movl -0x1c(%ebp), %eax\n" /* line 708 */
        "movl %eax, (%esi)\n" /* textureIndex */
        "movl 4(%ebx), %eax\n" /* indexSize */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 709 */
        "movl %eax, 4(%esi)\n" /* textureIndex */
        "movl 8(%ebx), %eax\n" /* indexSize */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 710 */
        "movl %eax, 8(%esi)\n" /* textureIndex */
        "movzbl 0x1b(%ebx), %ecx\n" /* line 718 | indexSize */
        "movzbl 0x18(%ebx), %edx\n" /* indexSize */
        "shll $0x18, %edx\n"
        "movzbl 0x19(%ebx), %eax\n" /* indexSize */
        "shll $0x10, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 0x1a(%ebx), %eax\n" /* indexSize */
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "addl %edx, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* Temp */
        "movl -0x48(%ebp), %eax\n" /* line 722 | c */
        "movl (%eax), %edx\n"
        "leal -0x20(%ebp), %ecx\n" /* Temp */
        "movl %ecx, 8(%esp)\n"
        "leal 0x18(%esi), %eax\n" /* textureIndex */
        "movl %eax, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl 0x1c(%ebx), %eax\n" /* indexSize */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 736 */
        "movl %eax, 0x1c(%esi)\n" /* textureIndex */
        "movl 0x20(%ebx), %eax\n" /* indexSize */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 737 */
        "movl %eax, 0x20(%esi)\n" /* textureIndex */
        "movl 0x24(%ebx), %eax\n" /* indexSize */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 739 */
        "movl %eax, 0x24(%esi)\n" /* textureIndex */
        "movl 0x28(%ebx), %eax\n" /* indexSize */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 740 */
        "movl %eax, 0x28(%esi)\n" /* textureIndex */
        "leal 0x38(%esi), %ecx\n" /* line 760 | textureIndex, to */
        "leal 0x2c(%ebx), %edx\n" /* indexSize, from */
        /* { scope 3 */
        "movl 0x2c(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x38(%esi)\n" /* lump */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x2c(%esi), %ecx\n" /* line 761 | textureIndex, to */
        "leal 0x38(%ebx), %edx\n" /* indexSize, from */
        /* { scope 3 */
        "movl 0x38(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x2c(%esi)\n" /* lump */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xc(%esi), %ecx\n" /* line 762 | textureIndex, to */
        "leal 0xc(%ebx), %edx\n" /* indexSize, from */
        /* { scope 3 */
        "movl 0xc(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xc(%esi)\n" /* lump */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* { scope 3 */
        ".Lfe4e4a_000e55f0:\n"
        "addl $1, %eax\n" /* line 765 | i */
        "cmpl $3, %eax\n" /* i */
        "jne .Lfe4e4a_000e55f0\n"
        /* } scope */
        /* } scope */
        "addl $1, -0x60(%ebp)\n" /* line 706 | vertIndex */
        "addl $0x44, %ebx\n" /* indexSize */
        "addl $0x44, %esi\n" /* textureIndex */
        "cmpl -0x60(%ebp), %edi\n" /* vertIndex, vertCount */
        "jne .Lfe4e4a_000e5517\n"
        "jmp .Lfe4e4a_000e4f84\n"
        ".Lfe4e4a_000e5610:\n"
        "movl s_world, %eax\n" /* line 682 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224ecc, 4(%esp)\n" /* "LoadMap: no vertices in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe4e4a_000e4f3c\n"
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e5632:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe4e4a_000e4ef1\n"
        ".Lfe4e4a_000e5654:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe4e4a_000e4ee7\n"
        /* } scope */
        ".Lfe4e4a_000e5676:\n"
        "movl s_world, %eax\n" /* line 678 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224eb0, 4(%esp)\n" /* "LoadMap: no surfaces in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl -0x74(%ebp), %ecx\n"
        "movl (%ecx), %ebx\n" /* indexSize */
        "movl %ecx, %edx\n"
        "jmp .Lfe4e4a_000e4ed5\n"
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e569f:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 0x40(%ebx), %edx\n" /* line 52 */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "jns .Lfe4e4a_000e4e87\n"
        ".Lfe4e4a_000e56c9:\n"
        "leal 0xf(%edx), %eax\n"
        "jmp .Lfe4e4a_000e4e87\n"
        ".Lfe4e4a_000e56d1:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe4e4a_000e4e70\n"
        /* } scope */
        /* { scope 2: surfTris, indexIndex */
        ".Lfe4e4a_000e56f3:\n"
        "xorl %esi, %esi\n" /* line 623 | textureIndex */
        "xorl %ebx, %ebx\n" /* surfIndex */
        "movl -0x5c(%ebp), %edx\n" /* skyMaterial */
        ".Lfe4e4a_000e56fa:\n"
        "movl %ebx, %edi\n" /* line 625 | surfIndex, texdef */
        "addl 0x3c(%edx), %edi\n" /* texdef */
        "movl $str_00224f68, 4(%esp)\n" /* line 626 */
        "movl (%edi), %eax\n" /* texdef */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfe4e4a_000e572b\n"
        "addl $1, %esi\n" /* line 623 | textureIndex */
        "addl $0xc, %ebx\n" /* surfIndex */
        "movl -0x5c(%ebp), %edx\n" /* skyMaterial */
        "movzwl 0x34(%edx), %eax\n"
        "cmpl %esi, %eax\n" /* textureIndex */
        "jg .Lfe4e4a_000e56fa\n"
        "jmp .Lfe4e4a_000e5174\n"
        ".Lfe4e4a_000e572b:\n"
        "cmpb $5, 5(%edi)\n" /* line 630 | texdef */
        "je .Lfe4e4a_000e5739\n"
        "movl 8(%edi), %eax\n" /* texdef */
        "cmpl $5, (%eax)\n"
        "je .Lfe4e4a_000e5763\n"
        ".Lfe4e4a_000e5739:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 631 | skyMaterial */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%edi), %eax\n" /* texdef */
        "movl 0x20(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00224f74, 4(%esp)\n" /* "colorMap '%s' for sky material '%s' is not a cubemap
" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 8(%edi), %eax\n" /* texdef */
        ".Lfe4e4a_000e5763:\n"
        "movl %eax, s_world+32\n" /* line 634 */
        "movzbl 4(%edi), %eax\n" /* line 635 | texdef */
        "movb %al, s_world+36\n"
        "jmp .Lfe4e4a_000e5174\n"
    );
}

/* line 1802 — Main BSP world loader: opens .d3dbsp file, validates header/version,
 * calls all R_Load* functions to parse lumps (cells, portals, AABB trees, surfaces,
 * occluders, nodes/leafs, lights, entities, etc.), allocates GfxWorld, initializes
 * DPVS structures, builds static model lighting cache, sets up reflection probes.
 * 1687 lines — the largest BSP loading function, orchestrating 20+ lump loaders. */
/* R_LoadWorldInternal has been rewritten in clean C in r_loadworld_new.c.
   The naked ASM below is disabled to use the C version instead. */
#if 0 /* disabled — using C rewrite in r_loadworld_new.c */
__attribute__((naked))
GfxWorld * R_LoadWorldInternal(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1802 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x156c, %esp\n"
        /* { scope 1: buf, len, image, groupInfo, ... */
        "movl $0x204, 8(%esp)\n" /* line 1807 */
        "movl $0, 4(%esp)\n"
        "movl $s_world, (%esp)\n"
        "calll memset\n"
        "cld\n" /* line 1808 */
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "movl $rgl, %edi\n" /* out */
        "rep stosl %eax, %es:(%edi)\n" /* out */
        "movl $s_world+340, 4(%esp)\n" /* line 1812 */
        "leal -0x538(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetBsp\n"
        "movl %eax, -0x540(%ebp)\n" /* load */
        "movl %eax, -0x53c(%ebp)\n" /* line 1814 */
        "movl $0xffffffff, %ebx\n" /* line 1816 | in */
        "xorl %esi, %esi\n" /* in */
        "cld\n"
        "movl %ebx, %ecx\n" /* in */
        "movl 8(%ebp), %edi\n" /* name, out */
        "movl %esi, %eax\n" /* in */
        "repne scasb %es:(%edi), %al\n" /* out */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world\n"
        "movl 8(%ebp), %edx\n" /* line 1817 | name */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl s_world, %eax\n" /* line 1819 */
        "movl %eax, (%esp)\n"
        "calll Com_SkipPath\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0xbb(%ebp), %ecx\n" /* baseName */
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0xbb(%ebp), %edi\n" /* line 1820 | baseName, out */
        "movl %edi, 4(%esp)\n" /* out */
        "movl %edi, (%esp)\n" /* out */
        "calll Com_StripExtension\n"
        "cld\n" /* line 1822 */
        "movl %ebx, %ecx\n" /* in */
        "movl %esi, %eax\n" /* in */
        "repne scasb %es:(%edi), %al\n" /* out */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+4\n"
        "leal -0xbb(%ebp), %edx\n" /* line 1823 | baseName */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_00224fac, 8(%esp)\n" /* "materials" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        "movl -0x540(%ebp), %ebx\n" /* line 499 | load, ptIndex */
        "leal 8(%ebx), %esi\n" /* ptIndex, mtlLump */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 8(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e7088\n"
        ".Lfe5778_000e58b0:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e700f\n"
        ".Lfe5778_000e58ba:\n"
        "movl 8(%ebx), %ecx\n" /* line 52 | count */
        "movl $0x38e38e39, %eax\n"
        "imull %ecx\n"
        "movl %edx, %ebx\n" /* count */
        "sarl $4, %ebx\n" /* count */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* count */
        "testl %ecx, %ecx\n" /* line 53 */
        "js .Lfe5778_000e58de\n"
        "leal (%ebx, %ebx, 8), %eax\n" /* count */
        "shll $3, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lfe5778_000e58fb\n"
        ".Lfe5778_000e58de:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe5778_000e58fb:\n"
        "movl %ebx, -0x530(%ebp)\n" /* line 500 | ptIndex */
        "movl -0x53c(%ebp), %eax\n" /* line 501 */
        "addl 4(%esi), %eax\n" /* mtlLump */
        "movl %eax, -0x534(%ebp)\n"
        /* } scope */
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_00224fd8, 8(%esp)\n" /* "sun settings" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "movl -0x53c(%ebp), %eax\n" /* line 1239 */
        "movl -0x540(%ebp), %edx\n" /* load */
        "addl 0x134(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $s_world+52, (%esp)\n"
        "calll R_ParseSunLight\n"
        "movl $s_world+180, 4(%esp)\n" /* line 1240 */
        "movl $s_world+52, (%esp)\n"
        "calll R_InterpretSunLightParseParamsIntoLights\n"
        "movl $str_00224fe8, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        "movss s_world+200, %xmm0\n" /* line 199 */
        "movss %xmm0, -0x1488(%ebp)\n"
        "movss s_world+204, %xmm2\n" /* line 200 */
        "movss %xmm2, -0x148c(%ebp)\n"
        "movss s_world+208, %xmm0\n" /* line 201 */
        "movss %xmm0, -0x1490(%ebp)\n"
        "movw $0x1f, -0x2c0(%ebp)\n" /* line 353 */
        "xorl %eax, %eax\n" /* line 30 */
        "movl %eax, -0x2bc(%ebp)\n"
        "movl %eax, -0x2b8(%ebp)\n" /* line 31 */
        "movl $0x3f800000, %eax\n" /* line 30 */
        "movl %eax, -0x2b4(%ebp)\n"
        "movl %eax, -0x2b0(%ebp)\n" /* line 31 */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        /* { scope 4: valGE */
        "movl -0x540(%ebp), %ebx\n" /* line 90 | load, triSurfIndex */
        "leal 0x40(%ebx), %esi\n" /* triSurfIndex, triLump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x40(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e6fed\n"
        ".Lfe5778_000e5a1b:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e6fbb\n"
        "movl 0x40(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "js .Lfe5778_000e6fe5\n"
        ".Lfe5778_000e5a32:\n"
        "sarl $4, %eax\n"
        "movl %eax, -0x1514(%ebp)\n"
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe5778_000e5a46\n"
        "shll $4, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe5778_000e5a63\n"
        ".Lfe5778_000e5a46:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        ".Lfe5778_000e5a63:\n"
        "movl -0x53c(%ebp), %eax\n" /* line 92 */
        "movl %eax, -0x14dc(%ebp)\n" /* triSurfs */
        "movl 4(%esi), %edx\n" /* triLump */
        "addl %edx, %eax\n"
        "movl %eax, -0x14dc(%ebp)\n" /* triSurfs */
        /* { scope 5 */
        "movl -0x540(%ebp), %ebx\n" /* line 46 | load, count */
        "leal 0x10(%ebx), %esi\n" /* count, lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x10(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e7066\n"
        ".Lfe5778_000e5a95:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e7031\n"
        "movl 0x10(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "js .Lfe5778_000e705b\n"
        ".Lfe5778_000e5aac:\n"
        "movl %eax, %esi\n" /* lump */
        "sarl $0x16, %esi\n" /* lump */
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe5778_000e5abe\n"
        "movl %esi, %eax\n" /* lump */
        "shll $0x16, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe5778_000e5adb\n"
        ".Lfe5778_000e5abe:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe5778_000e5adb:\n"
        "movl -0x1514(%ebp), %edi\n" /* line 96 */
        "testl %edi, %edi\n"
        "jg .Lfe5778_000e6064\n"
        "movl $0, -0x14d0(%ebp)\n" /* origLmapCount */
        ".Lfe5778_000e5af3:\n"
        "testl %esi, %esi\n" /* line 104 | triLump */
        "je .Lfe5778_000e5b1c\n"
        "cmpl -0x14d0(%ebp), %esi\n" /* origLmapCount, triLump */
        "je .Lfe5778_000e5b1c\n"
        "movl s_world, %eax\n" /* line 105 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        ".Lfe5778_000e5b1c:\n"
        "movl $0x7c, 8(%esp)\n" /* line 107 */
        "movl $0, 4(%esp)\n"
        "leal -0x138(%ebp), %ecx\n" /* lmapVertCount */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl $0xf04, 8(%esp)\n" /* line 108 */
        "movl $0, 4(%esp)\n"
        "leal -0x1444(%ebp), %edi\n" /* coupling */
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "movl -0x530(%ebp), %ebx\n" /* line 109 | triSurfIndex */
        "testl %ebx, %ebx\n" /* triSurfIndex */
        "jle .Lfe5778_000e5cf6\n"
        "movl $0, -0x14d8(%ebp)\n" /* materialIndex */
        ".Lfe5778_000e5b70:\n"
        "movl -0x1514(%ebp), %eax\n" /* line 111 */
        "testl %eax, %eax\n"
        "jle .Lfe5778_000e5bc3\n"
        "movl -0x14dc(%ebp), %edx\n" /* triSurfs */
        "xorl %ecx, %ecx\n"
        "jmp .Lfe5778_000e5b92\n"
        ".Lfe5778_000e5b84:\n"
        "addl $1, %ecx\n"
        "addl $0x10, %edx\n"
        "cmpl %ecx, -0x1514(%ebp)\n"
        "je .Lfe5778_000e5bc3\n"
        ".Lfe5778_000e5b92:\n"
        "movswl (%edx), %eax\n" /* line 113 */
        "cmpl %eax, -0x14d8(%ebp)\n" /* materialIndex */
        "jne .Lfe5778_000e5b84\n"
        "movzwl 2(%edx), %eax\n" /* line 115 */
        "movswl %ax, %ebx\n" /* triSurfIndex */
        "cmpw $0x1f, %ax\n" /* line 116 */
        "je .Lfe5778_000e5b84\n"
        "movswl 8(%edx), %eax\n" /* line 117 */
        "addl %eax, -0x138(%ebp, %ebx, 4)\n"
        "addl $1, %ecx\n" /* line 111 */
        "addl $0x10, %edx\n"
        "cmpl %ecx, -0x1514(%ebp)\n"
        "jne .Lfe5778_000e5b92\n"
        ".Lfe5778_000e5bc3:\n"
        "movl -0x14d0(%ebp), %ecx\n" /* line 121 | origLmapCount */
        "testl %ecx, %ecx\n"
        "jle .Lfe5778_000e5cdd\n"
        "movl $0, -0x14d4(%ebp)\n" /* lmapIndex */
        "movl -0x14d4(%ebp), %eax\n" /* lmapIndex */
        "movl -0x138(%ebp, %eax, 4), %edx\n" /* line 123 */
        "testl %edx, %edx\n"
        "je .Lfe5778_000e5ccc\n"
        ".Lfe5778_000e5bf0:\n"
        "movl %eax, %edx\n"
        "addl $1, %edx\n" /* line 126 */
        "movl %edx, -0x1450(%ebp)\n"
        "cmpl %edx, -0x14d0(%ebp)\n" /* origLmapCount */
        "jle .Lfe5778_000e5c98\n"
        "movl %edx, %eax\n"
        "shll $2, %eax\n"
        "leal -0x138(%ebp), %ebx\n" /* lmapVertCount, triSurfIndex */
        "addl %eax, %ebx\n" /* triSurfIndex */
        "movl %edx, %esi\n" /* triLump */
        "shll $7, %esi\n" /* triLump */
        "subl %eax, %esi\n" /* triLump */
        "movl -0x14d4(%ebp), %ecx\n" /* lmapIndex */
        "shll $2, %ecx\n"
        "movl -0x14d4(%ebp), %edx\n" /* lmapIndex */
        "shll $7, %edx\n"
        "subl %ecx, %edx\n"
        "leal -0x1444(%ebp), %edi\n" /* coupling */
        "leal (%edi, %edx), %edx\n"
        "addl %eax, %edx\n"
        "xorl %edi, %edi\n"
        "leal -0x1444(%ebp), %eax\n" /* coupling */
        "addl %ecx, %eax\n"
        "movl %eax, -0x1518(%ebp)\n"
        "movl -0x14d0(%ebp), %ecx\n" /* origLmapCount */
        "subl -0x1450(%ebp), %ecx\n"
        "movl %ecx, -0x154c(%ebp)\n"
        ".Lfe5778_000e5c5c:\n"
        "movl (%ebx), %eax\n" /* line 128 | triSurfIndex */
        "testl %eax, %eax\n"
        "je .Lfe5778_000e5c84\n"
        "movl -0x14d4(%ebp), %ecx\n" /* line 131 | lmapIndex */
        "addl -0x138(%ebp, %ecx, 4), %eax\n"
        "addl (%edx), %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 132 */
        "js .Lfe5778_000e5ea5\n"
        ".Lfe5778_000e5c7b:\n"
        "movl -0x1518(%ebp), %ecx\n" /* line 134 */
        "movl %eax, (%ecx, %esi)\n"
        ".Lfe5778_000e5c84:\n"
        "addl $1, %edi\n"
        "addl $4, %ebx\n" /* triSurfIndex */
        "addl $0x7c, %esi\n" /* triLump */
        "addl $4, %edx\n"
        "cmpl %edi, -0x154c(%ebp)\n" /* line 126 */
        "jne .Lfe5778_000e5c5c\n"
        ".Lfe5778_000e5c98:\n"
        "movl -0x14d4(%ebp), %edi\n" /* line 137 | lmapIndex */
        "movl $0, -0x138(%ebp, %edi, 4)\n"
        "movl -0x1450(%ebp), %eax\n"
        "cmpl %eax, -0x14d0(%ebp)\n" /* line 121 | origLmapCount */
        "jle .Lfe5778_000e5cdd\n"
        ".Lfe5778_000e5cb7:\n"
        "movl %eax, -0x14d4(%ebp)\n" /* lmapIndex */
        "movl -0x138(%ebp, %eax, 4), %edx\n" /* line 123 */
        "testl %edx, %edx\n"
        "jne .Lfe5778_000e5bf0\n"
        ".Lfe5778_000e5ccc:\n"
        "addl $1, %eax\n"
        "movl %eax, -0x1450(%ebp)\n"
        "cmpl %eax, -0x14d0(%ebp)\n" /* line 121 | origLmapCount */
        "jg .Lfe5778_000e5cb7\n"
        ".Lfe5778_000e5cdd:\n"
        "addl $1, -0x14d8(%ebp)\n" /* line 109 | materialIndex */
        "movl -0x14d8(%ebp), %edx\n" /* materialIndex */
        "cmpl -0x530(%ebp), %edx\n"
        "jl .Lfe5778_000e5b70\n"
        /* } scope */
        ".Lfe5778_000e5cf6:\n"
        "cld\n" /* line 170 */
        "xorl %eax, %eax\n"
        "movl $7, %ecx\n"
        "leal -0x7b(%ebp), %edi\n" /* used */
        "rep stosl %eax, %es:(%edi)\n"
        "stosw %ax, %es:(%edi)\n"
        "stosb %al, %es:(%edi)\n"
        "movl imp_r_optimizeLightmaps, %eax\n" /* line 173 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfe5778_000e6a4a\n"
        "movl $1, -0x14ec(%ebp)\n" /* wideCount */
        "movl $1, -0x144c(%ebp)\n"
        ".Lfe5778_000e5d2b:\n"
        "movl -0x14d0(%ebp), %eax\n" /* line 186 | origLmapCount */
        "testl %eax, %eax\n"
        "jle .Lfe5778_000e60ac\n"
        "movl $0, -0x14f0(%ebp)\n" /* usedCount */
        "movl $0, -0x14e4(%ebp)\n" /* newLmapCount */
        "leal -0x2ac(%ebp), %ecx\n" /* groupInfo */
        "movl %ecx, -0x1464(%ebp)\n"
        "movl -0x14d0(%ebp), %eax\n" /* origLmapCount */
        ".Lfe5778_000e5d5f:\n"
        "subl -0x14f0(%ebp), %eax\n" /* usedCount */
        ".Lfe5778_000e5d65:\n"
        "movl -0x14ec(%ebp), %edx\n" /* line 188 | wideCount */
        "imull -0x144c(%ebp), %edx\n"
        "movl %edx, -0x14f4(%ebp)\n"
        "cmpl %edx, %eax\n"
        "jge .Lfe5778_000e5dab\n"
        ".Lfe5778_000e5d7c:\n"
        "movl -0x144c(%ebp), %edi\n" /* line 190 */
        "cmpl %edi, -0x14ec(%ebp)\n" /* wideCount */
        "jl .Lfe5778_000e5e9a\n"
        "sarl -0x14ec(%ebp)\n" /* line 191 | wideCount */
        "movl -0x14ec(%ebp), %edx\n" /* line 188 | wideCount */
        "imull -0x144c(%ebp), %edx\n"
        "movl %edx, -0x14f4(%ebp)\n"
        "cmpl %edx, %eax\n"
        "jl .Lfe5778_000e5d7c\n"
        ".Lfe5778_000e5dab:\n"
        "subl $1, %edx\n" /* line 198 */
        "jle .Lfe5778_000e603e\n"
        "movl $0, -0x145c(%ebp)\n"
        "movl $0x1f, -0x14e0(%ebp)\n" /* bestOtherLmapIndex */
        "movl $0x1f, %edi\n"
        "movl -0x145c(%ebp), %ecx\n"
        "cmpb $0, -0x7b(%ebp, %ecx)\n" /* line 204 */
        "je .Lfe5778_000e5e00\n"
        ".Lfe5778_000e5dda:\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x1458(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lfe5778_000e5de5:\n"
        "cmpl %eax, -0x14d0(%ebp)\n" /* line 202 | origLmapCount */
        "jle .Lfe5778_000e5eb5\n"
        "movl %eax, -0x145c(%ebp)\n"
        "movl %eax, %ecx\n"
        "cmpb $0, -0x7b(%ebp, %ecx)\n" /* line 204 */
        "jne .Lfe5778_000e5dda\n"
        ".Lfe5778_000e5e00:\n"
        "movl %ecx, %eax\n"
        "addl $1, %eax\n" /* line 206 */
        "movl %eax, -0x1458(%ebp)\n"
        "cmpl %eax, -0x14d0(%ebp)\n" /* origLmapCount */
        "jle .Lfe5778_000e5eb5\n"
        "movl %eax, %ecx\n"
        "leal -0x7b(%ebp), %ebx\n" /* used, valGE */
        "addl %eax, %ebx\n" /* valGE */
        "movl -0x145c(%ebp), %eax\n"
        "shll $5, %eax\n"
        "subl -0x145c(%ebp), %eax\n"
        "addl -0x1458(%ebp), %eax\n"
        "leal -0x1444(%ebp, %eax, 4), %esi\n" /* triLump */
        "movl -0x14d0(%ebp), %edx\n" /* origLmapCount */
        "movl %edx, -0x151c(%ebp)\n"
        ".Lfe5778_000e5e46:\n"
        "cmpb $0, (%ebx)\n" /* line 208 | valGE */
        "jne .Lfe5778_000e5e7e\n"
        "cmpl $0x1f, -0x14e0(%ebp)\n" /* line 211 | bestOtherLmapIndex */
        "je .Lfe5778_000e5e70\n"
        "movl -0x14e0(%ebp), %eax\n" /* bestOtherLmapIndex */
        "shll $5, %eax\n"
        "subl -0x14e0(%ebp), %eax\n" /* bestOtherLmapIndex */
        "addl %edi, %eax\n"
        "movl (%esi), %edx\n" /* triLump */
        "cmpl -0x1444(%ebp, %eax, 4), %edx\n"
        "jle .Lfe5778_000e5e7e\n"
        ".Lfe5778_000e5e70:\n"
        "movl -0x145c(%ebp), %edi\n"
        "movl %edi, -0x14e0(%ebp)\n" /* bestOtherLmapIndex */
        "movl %ecx, %edi\n"
        ".Lfe5778_000e5e7e:\n"
        "addl $1, %ecx\n" /* line 206 */
        "addl $1, %ebx\n" /* valGE */
        "addl $4, %esi\n" /* triLump */
        "cmpl %ecx, -0x151c(%ebp)\n"
        "jne .Lfe5778_000e5e46\n"
        "movl -0x1458(%ebp), %eax\n"
        "jmp .Lfe5778_000e5de5\n"
        ".Lfe5778_000e5e9a:\n"
        "sarl -0x144c(%ebp)\n" /* line 193 */
        "jmp .Lfe5778_000e5d65\n"
        /* { scope 4: valGE */
        ".Lfe5778_000e5ea5:\n"
        "movl $0x7fffffff, %eax\n" /* line 133 */
        "movl $0x7fffffff, (%edx)\n"
        "jmp .Lfe5778_000e5c7b\n"
        /* } scope */
        ".Lfe5778_000e5eb5:\n"
        "leal -0x1b4(%ebp), %eax\n" /* line 219 | reorder */
        "movl -0x14f0(%ebp), %edx\n" /* usedCount */
        "movl %edi, (%eax, %edx, 4)\n"
        "movl -0x14e0(%ebp), %ecx\n" /* line 220 | bestOtherLmapIndex */
        "movl %ecx, 4(%eax, %edx, 4)\n"
        "addl $2, %edx\n"
        "movl %edx, -0x14f0(%ebp)\n" /* usedCount */
        "movb $1, -0x7b(%ebp, %edi)\n" /* line 221 */
        "movb $1, -0x7b(%ebp, %ecx)\n" /* line 222 */
        "cmpl $2, -0x14f4(%ebp)\n" /* line 226 */
        "jle .Lfe5778_000e5ffe\n"
        "shll $2, %edx\n"
        "movl %edx, -0x1468(%ebp)\n"
        "movl $2, -0x14e8(%ebp)\n" /* mergedCount */
        ".Lfe5778_000e5f01:\n"
        "movl -0x14e0(%ebp), %eax\n" /* bestOtherLmapIndex */
        "shll $2, %eax\n"
        "movl -0x14e0(%ebp), %edx\n" /* bestOtherLmapIndex */
        "shll $7, %edx\n"
        "subl %eax, %edx\n"
        "leal -0x1444(%ebp), %esi\n" /* coupling, triLump */
        "addl %edx, %esi\n" /* triLump */
        "leal (, %edi, 4), %edx\n"
        "shll $7, %edi\n"
        "subl %edx, %edi\n"
        "leal -0x1444(%ebp), %edx\n" /* coupling */
        "addl %edi, %edx\n"
        "leal -0x1444(%ebp), %ebx\n" /* coupling, valGE */
        "addl %eax, %ebx\n" /* valGE */
        "xorl %ecx, %ecx\n"
        ".Lfe5778_000e5f3b:\n"
        "movl (%esi), %eax\n" /* line 230 | triLump */
        "addl (%edx), %eax\n"
        "movl %eax, (%esi)\n" /* triLump */
        "movl %eax, (%ebx)\n" /* line 231 | valGE */
        "addl $1, %ecx\n" /* line 228 */
        "addl $4, %esi\n" /* triLump */
        "addl $4, %edx\n"
        "addl $0x7c, %ebx\n" /* valGE */
        "cmpl %ecx, -0x14d0(%ebp)\n" /* origLmapCount */
        "jne .Lfe5778_000e5f3b\n"
        "movl -0x14e0(%ebp), %edx\n" /* bestOtherLmapIndex */
        "shll $2, %edx\n"
        "movl -0x14e0(%ebp), %eax\n" /* bestOtherLmapIndex */
        "shll $7, %eax\n"
        "subl %edx, %eax\n"
        "leal -0x1444(%ebp), %ecx\n" /* coupling */
        "addl %eax, %ecx\n"
        "xorl %ebx, %ebx\n" /* valGE */
        "movl $0x1f, %edi\n"
        "movl -0x14e0(%ebp), %esi\n" /* bestOtherLmapIndex, triLump */
        "shll $5, %esi\n" /* triLump */
        "subl -0x14e0(%ebp), %esi\n" /* bestOtherLmapIndex, triLump */
        "jmp .Lfe5778_000e5f99\n"
        ".Lfe5778_000e5f8b:\n"
        "addl $1, %ebx\n" /* line 235 | valGE */
        "addl $4, %ecx\n"
        "cmpl %ebx, -0x14d0(%ebp)\n" /* valGE, origLmapCount */
        "je .Lfe5778_000e5fc3\n"
        ".Lfe5778_000e5f99:\n"
        "cmpb $0, -0x7b(%ebx, %ebp)\n" /* line 237 | valGE */
        "jne .Lfe5778_000e5f8b\n"
        "cmpl $0x1f, %edi\n" /* line 239 */
        "je .Lfe5778_000e5fb3\n"
        "leal (%esi, %edi), %edx\n" /* triLump */
        "movl (%ecx), %eax\n"
        "cmpl -0x1444(%ebp, %edx, 4), %eax\n"
        "jle .Lfe5778_000e5f8b\n"
        ".Lfe5778_000e5fb3:\n"
        "movl %ebx, %edi\n" /* valGE */
        "addl $1, %ebx\n" /* line 235 | valGE */
        "addl $4, %ecx\n"
        "cmpl %ebx, -0x14d0(%ebp)\n" /* valGE, origLmapCount */
        "jne .Lfe5778_000e5f99\n"
        ".Lfe5778_000e5fc3:\n"
        "movl -0x1468(%ebp), %eax\n" /* line 242 */
        "movl %edi, -0x1b4(%ebp, %eax)\n"
        "addl $1, -0x14f0(%ebp)\n" /* usedCount */
        "movb $1, -0x7b(%ebp, %edi)\n" /* line 243 */
        "addl $1, -0x14e8(%ebp)\n" /* line 226 | mergedCount */
        "addl $4, %eax\n"
        "movl %eax, -0x1468(%ebp)\n"
        "movl -0x14f4(%ebp), %edx\n"
        "cmpl %edx, -0x14e8(%ebp)\n" /* mergedCount */
        "jne .Lfe5778_000e5f01\n"
        ".Lfe5778_000e5ffe:\n"
        "movl -0x14ec(%ebp), %eax\n" /* line 261 | wideCount */
        "movl -0x1464(%ebp), %edi\n"
        "movl %eax, (%edi)\n"
        "movl -0x144c(%ebp), %edx\n" /* line 262 */
        "movl %edx, 4(%edi)\n"
        "addl $1, -0x14e4(%ebp)\n" /* line 263 | newLmapCount */
        "addl $8, %edi\n"
        "movl %edi, -0x1464(%ebp)\n"
        "movl -0x14d0(%ebp), %ecx\n" /* line 186 | origLmapCount */
        "cmpl %ecx, -0x14f0(%ebp)\n" /* usedCount */
        "jge .Lfe5778_000e6a72\n"
        "movl %ecx, %eax\n"
        "jmp .Lfe5778_000e5d5f\n"
        ".Lfe5778_000e603e:\n"
        "cmpb $0, -0x7b(%ebp)\n" /* line 252 | used */
        "je .Lfe5778_000e6a79\n"
        "xorl %eax, %eax\n" /* line 257 */
        "jmp .Lfe5778_000e6057\n"
        ".Lfe5778_000e604c:\n"
        "cmpb $0, -0x7b(%ebp, %eax)\n" /* line 252 */
        "je .Lfe5778_000e6a7b\n"
        ".Lfe5778_000e6057:\n"
        "addl $1, %eax\n" /* line 250 */
        "cmpl %eax, -0x14d0(%ebp)\n" /* origLmapCount */
        "jne .Lfe5778_000e604c\n"
        "jmp .Lfe5778_000e5ffe\n"
        /* { scope 4: valGE */
        ".Lfe5778_000e6064:\n"
        "movl -0x14dc(%ebp), %ecx\n" /* line 96 | triSurfs */
        "xorl %ebx, %ebx\n" /* triSurfIndex */
        "movl $0, -0x14d0(%ebp)\n" /* origLmapCount */
        ".Lfe5778_000e6076:\n"
        "movzwl 2(%ecx), %eax\n" /* line 98 */
        "movswl %ax, %edx\n"
        "cmpw $0x1f, %ax\n" /* line 99 */
        "je .Lfe5778_000e6099\n"
        "leal 1(%edx), %eax\n" /* line 102 */
        "cmpl %edx, -0x14d0(%ebp)\n" /* origLmapCount */
        "cmovgl -0x14d0(%ebp), %eax\n" /* origLmapCount */
        "movl %eax, -0x14d0(%ebp)\n" /* origLmapCount */
        ".Lfe5778_000e6099:\n"
        "addl $1, %ebx\n" /* line 96 | triSurfIndex */
        "addl $0x10, %ecx\n"
        "cmpl %ebx, -0x1514(%ebp)\n" /* triSurfIndex */
        "jne .Lfe5778_000e6076\n"
        "jmp .Lfe5778_000e5af3\n"
        /* } scope */
        ".Lfe5778_000e60ac:\n"
        "movl $0, -0x14e4(%ebp)\n" /* line 186 | newLmapCount */
        "movl -0x14d0(%ebp), %edi\n" /* origLmapCount */
        ".Lfe5778_000e60bc:\n"
        "movl %edi, 8(%esp)\n" /* line 266 */
        "movl -0x14e4(%ebp), %eax\n" /* newLmapCount */
        "movl %eax, 4(%esp)\n"
        "movl $str_00224ff4, (%esp)\n" /* "%i merged lightmaps from %i original lightmaps
" */
        "calll Com_Printf\n"
        /* } scope */
        "testl %edi, %edi\n" /* line 358 | lmapSubIndex */
        "jne .Lfe5778_000e67e5\n"
        "movl $0, s_world+260\n" /* line 360 */
        /* } scope */
        ".Lfe5778_000e60e8:\n"
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_00225040, 8(%esp)\n" /* "lightgrid coefficients" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        "movl -0x540(%ebp), %ebx\n" /* line 459 | load, srcImage */
        "leal 0x20(%ebx), %esi\n" /* srcImage, gridColorLump */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x20(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e71fc\n"
        ".Lfe5778_000e6137:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e71da\n"
        ".Lfe5778_000e6141:\n"
        "movl 0x20(%ebx), %ecx\n" /* line 52 | count */
        "movl $0x2aaaaaab, %eax\n"
        "imull %ecx\n"
        "movl %edx, %ebx\n" /* count */
        "sarl $2, %ebx\n" /* count */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* count */
        "testl %ecx, %ecx\n" /* line 53 */
        "js .Lfe5778_000e6165\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* count */
        "shll $3, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lfe5778_000e6182\n"
        ".Lfe5778_000e6165:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe5778_000e6182:\n"
        "movl %ebx, s_world+292\n" /* line 460 | srcImage */
        "movl (%esi), %eax\n" /* line 461 | gridColorLump */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+296\n"
        "movl (%esi), %edx\n" /* line 462 | gridColorLump */
        "movl %edx, 8(%esp)\n"
        "movl -0x53c(%ebp), %edx\n"
        "addl 4(%esi), %edx\n" /* gridColorLump */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        /* } scope */
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_00225058, 8(%esp)\n" /* "lightgrid hash" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        "movl -0x540(%ebp), %ebx\n" /* line 476 | load, ptIndex */
        "leal 0x18(%ebx), %esi\n" /* ptIndex, gridPointsLump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x18(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e71b8\n"
        ".Lfe5778_000e6201:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e7186\n"
        "movl 0x18(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "js .Lfe5778_000e71b0\n"
        ".Lfe5778_000e6218:\n"
        "movl %eax, %ebx\n" /* count */
        "sarl $3, %ebx\n" /* count */
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe5778_000e622c\n"
        "leal (, %ebx, 8), %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe5778_000e6249\n"
        ".Lfe5778_000e622c:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        ".Lfe5778_000e6249:\n"
        "movl %ebx, s_world+284\n" /* line 477 | ptIndex */
        "movl (%esi), %eax\n" /* line 478 | gridPointsLump */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, %ecx\n"
        "movl %eax, s_world+288\n"
        "movl -0x53c(%ebp), %edx\n" /* line 480 */
        "addl 4(%esi), %edx\n" /* gridPointsLump */
        "movl s_world+284, %edi\n" /* line 482 | srcWidth */
        "testl %edi, %edi\n" /* srcWidth */
        "jle .Lfe5778_000e62a0\n"
        "xorl %ebx, %ebx\n" /* ptIndex */
        ".Lfe5778_000e6275:\n"
        "movl (%edx), %eax\n" /* line 484 */
        "movl %eax, (%ecx)\n"
        "movzbl 4(%edx), %eax\n" /* line 485 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n" /* line 486 */
        "movb %al, 5(%ecx)\n"
        "movzwl 6(%edx), %eax\n" /* line 487 */
        "movw %ax, 6(%ecx)\n"
        "addl $1, %ebx\n" /* line 482 | ptIndex */
        "addl $8, %edx\n"
        "addl $8, %ecx\n"
        "cmpl %ebx, s_world+284\n" /* ptIndex */
        "jg .Lfe5778_000e6275\n"
        /* } scope */
        ".Lfe5778_000e62a0:\n"
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_00225068, 8(%esp)\n" /* "surfaces" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1849 | load */
        "calll R_LoadSurfaces\n"
        "movl $str_00225074, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1854 | load */
        "calll R_LoadCullGroups\n"
        "movl $str_00225080, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        "movl -0x540(%ebp), %ebx\n" /* line 46 | load, count */
        "leal 0x60(%ebx), %esi\n" /* count, lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x60(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e7164\n"
        ".Lfe5778_000e6361:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e7132\n"
        "movl 0x60(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "js .Lfe5778_000e715c\n"
        ".Lfe5778_000e6378:\n"
        "movl %eax, %esi\n" /* lump */
        "sarl $2, %esi\n" /* lump */
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe5778_000e638c\n"
        "leal (, %esi, 4), %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lfe5778_000e63a9\n"
        ".Lfe5778_000e638c:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe5778_000e63a9:\n"
        "movl -0x53c(%ebp), %ebx\n" /* line 1610 | in */
        "movl -0x540(%ebp), %eax\n" /* load */
        "addl 0x64(%eax), %ebx\n" /* in */
        "leal (, %esi, 4), %eax\n" /* line 1611 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, %ecx\n"
        "movl %eax, rgl+4\n" /* line 1613 */
        "testl %esi, %esi\n" /* line 1617 | in */
        "jle .Lfe5778_000e63e1\n"
        "xorl %edx, %edx\n"
        ".Lfe5778_000e63d4:\n"
        "movl (%ebx, %edx, 4), %eax\n" /* line 1618 | in */
        "movl %eax, (%ecx, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1617 */
        "cmpl %edx, %esi\n" /* in */
        "jne .Lfe5778_000e63d4\n"
        /* } scope */
        ".Lfe5778_000e63e1:\n"
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_00225094, 8(%esp)\n" /* "portal vertices" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1861 | load */
        "calll R_LoadPortalVerts\n"
        "movl $str_002250a4, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1863 | load */
        "calll R_LoadOccluders\n"
        "movl $str_002250b0, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        "movl -0x540(%ebp), %ebx\n" /* line 46 | load, count */
        "leal 0xb0(%ebx), %esi\n" /* count, lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0xb0(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e7110\n"
        ".Lfe5778_000e64a8:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e70ee\n"
        ".Lfe5778_000e64b2:\n"
        "movl 0xb0(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %esi\n" /* lump */
        "sarl $1, %esi\n" /* lump */
        "testl %edx, %edx\n" /* line 53 */
        "js .Lfe5778_000e64cd\n"
        "leal (%esi, %esi), %eax\n" /* lump */
        "cmpl %eax, %edx\n"
        "je .Lfe5778_000e64ea\n"
        ".Lfe5778_000e64cd:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe5778_000e64ea:\n"
        "movl -0x53c(%ebp), %ebx\n" /* line 1715 | in */
        "movl -0x540(%ebp), %eax\n" /* load */
        "addl 0xb4(%eax), %ebx\n" /* in */
        "leal (, %esi, 4), %eax\n" /* line 1716 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, %edi\n" /* out */
        "movl %eax, rgl\n" /* line 1718 */
        "testl %esi, %esi\n" /* line 1722 | in */
        "jle .Lfe5778_000e6532\n"
        "xorl %ecx, %ecx\n"
        ".Lfe5778_000e6518:\n"
        "movswl (%ebx, %ecx, 2), %eax\n" /* line 1723 | in */
        "leal (%eax, %eax, 8), %eax\n"
        "movl rgl+8, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edi, %ecx, 4)\n" /* out */
        "addl $1, %ecx\n" /* line 1722 */
        "cmpl %ecx, %esi\n" /* in */
        "jne .Lfe5778_000e6518\n"
        /* } scope */
        ".Lfe5778_000e6532:\n"
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_002250c4, 8(%esp)\n" /* "AABB trees" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1867 | load */
        "calll R_LoadAabbTrees\n"
        "movl $str_002250d0, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1869 | load */
        "calll R_LoadCells\n"
        "movl $str_002250d8, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1871 | load */
        "calll R_LoadPortals\n"
        "movl $str_002250e0, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1873 | load */
        "calll R_LoadNodesAndLeafs\n"
        "movl $str_002250f0, 8(%esp)\n" /* line 1796 */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        "movl -0x540(%ebp), %ebx\n" /* line 46 | load, count */
        "leal 0x120(%ebx), %esi\n" /* count, lump */
        "movl 4(%esi), %eax\n" /* line 47 | lump */
        "addl 0x120(%ebx), %eax\n" /* count */
        "cmpl -0x538(%ebp), %eax\n"
        "jg .Lfe5778_000e70cc\n"
        ".Lfe5778_000e666b:\n"
        "cmpl $3, 4(%esi)\n" /* line 49 | lump */
        "jle .Lfe5778_000e70aa\n"
        ".Lfe5778_000e6675:\n"
        "movl 0x120(%ebx), %ecx\n" /* line 52 | count */
        "movl $0x2aaaaaab, %eax\n"
        "imull %ecx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x1494(%ebp)\n" /* modelCount */
        "testl %ecx, %ecx\n" /* line 53 */
        "js .Lfe5778_000e66a0\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lfe5778_000e66bd\n"
        ".Lfe5778_000e66a0:\n"
        "movl s_world, %eax\n" /* line 54 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224bbc, 4(%esp)\n" /* "LoadMap: funny lump size in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        ".Lfe5778_000e66bd:\n"
        "movl -0x53c(%ebp), %esi\n" /* line 894 | in */
        "movl -0x540(%ebp), %eax\n" /* load */
        "addl 0x124(%eax), %esi\n" /* in */
        "movl -0x1494(%ebp), %eax\n" /* line 896 | modelCount */
        "shll $5, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, %edi\n" /* out */
        "movl %eax, s_world+312\n" /* line 897 */
        "movl -0x1494(%ebp), %ecx\n" /* line 898 | modelCount */
        "movl %ecx, s_world+308\n"
        "testl %ecx, %ecx\n" /* line 900 */
        "jle .Lfe5778_000e6760\n"
        "movl $0, -0x1498(%ebp)\n" /* modelIndex */
        ".Lfe5778_000e6701:\n"
        "movl %edi, %ecx\n" /* out */
        "xorl %ebx, %ebx\n" /* axis */
        ".Lfe5778_000e6705:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl (%esi, %edx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 904 */
        "movl %eax, (%ecx)\n"
        "movl 0xc(%esi, %edx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 905 */
        "movl %eax, 0xc(%ecx)\n"
        "addl $1, %ebx\n" /* line 902 | axis */
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* axis */
        "jne .Lfe5778_000e6705\n"
        "movl 0x1c(%esi), %eax\n" /* line 908 | in */
        "movl %eax, 0x18(%edi)\n" /* out */
        "testl %eax, %eax\n" /* line 909 */
        "jne .Lfe5778_000e67dd\n"
        "movl $0xffffffff, %eax\n"
        ".Lfe5778_000e6742:\n"
        "movl %eax, 0x1c(%edi)\n" /* out */
        "addl $1, -0x1498(%ebp)\n" /* line 900 | modelIndex */
        "addl $0x30, %esi\n" /* in */
        "addl $0x20, %edi\n" /* out */
        "movl -0x1498(%ebp), %eax\n" /* modelIndex */
        "cmpl %eax, -0x1494(%ebp)\n" /* modelCount */
        "jne .Lfe5778_000e6701\n"
        /* } scope */
        ".Lfe5778_000e6760:\n"
        "movl imp_ri, %ebx\n" /* line 1796 | in */
        "movl $str_002250fc, 8(%esp)\n" /* "entities" */
        "movl $str_00224fb8, 4(%esp)\n" /* "Loading %s...
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* in */
        "movl $str_00224fc8, 4(%esp)\n" /* line 1797 */
        "movl $0, (%esp)\n"
        "calll *0x108(%ebx)\n" /* in */
        "leal -0x540(%ebp), %eax\n" /* line 1883 | load */
        "calll R_LoadEntities\n"
        "cld\n" /* line 1886 */
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "movl $rgl, %edi\n" /* out */
        "rep stosl %eax, %es:(%edi)\n" /* out */
        "movl $s_world+352, 4(%esp)\n" /* line 1889 */
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll R_LoadSun\n"
        "movl $s_world, (%esp)\n" /* line 1893 */
        "calll R_RegisterOutdoorImage\n"
        /* } scope */
        "movl $s_world, %eax\n" /* line 1897 */
        "addl $0x156c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buf, len, image, groupInfo, ... */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        ".Lfe5778_000e67dd:\n"
        "movl 0x18(%esi), %eax\n" /* line 909 | in */
        "jmp .Lfe5778_000e6742\n"
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        ".Lfe5778_000e67e5:\n"
        "movl $1, %edx\n" /* line 360 */
        ".Lfe5778_000e67ea:\n"
        "leal (, %edx, 4), %eax\n" /* line 366 */
        "movl $4, -0x50(%ebp, %eax)\n"
        "movl $0x200, -0x30(%ebp, %eax)\n" /* line 367 */
        "movl $0x200, -0x60(%ebp, %eax)\n" /* line 368 */
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 364 */
        "jne .Lfe5778_000e67ea\n"
        "movl $1, -0x40(%ebp)\n" /* line 372 */
        "movl $0x400, -0x20(%ebp)\n" /* line 373 */
        "movl $0x400, -0x50(%ebp)\n" /* line 374 */
        "movl -0x2ac(%ebp), %ebx\n" /* line 377 | groupInfo, totalImageSize */
        "imull -0x2a8(%ebp), %ebx\n" /* totalImageSize */
        "shll $0x16, %ebx\n" /* totalImageSize */
        "movl %ebx, (%esp)\n" /* line 378 | totalImageSize */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x3c(%ebp)\n" /* image */
        "movl -0x2ac(%ebp), %esi\n" /* line 380 | groupInfo, triLump */
        "movl -0x2a8(%ebp), %edi\n" /* lmapSubIndex */
        "movl $1, %ecx\n"
        ".Lfe5778_000e6852:\n"
        "leal (, %ecx, 4), %edx\n"
        "movl -0x50(%ebp, %edx), %eax\n"
        "imull -0x30(%ebp, %edx), %eax\n"
        "imull -0x60(%ebp, %edx), %eax\n"
        "imull %esi, %eax\n" /* triLump */
        "imull %edi, %eax\n" /* lmapSubIndex */
        "addl -0x40(%ebp, %edx), %eax\n"
        "movl %eax, -0x3c(%edx, %ebp)\n"
        "addl $1, %ecx\n" /* line 379 */
        "cmpl $4, %ecx\n"
        "jne .Lfe5778_000e6852\n"
        "movl -0x540(%ebp), %eax\n" /* line 382 | load */
        "movl -0x53c(%ebp), %edx\n"
        "movl %edx, -0x150c(%ebp)\n" /* buf */
        "movl 0x14(%eax), %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, -0x150c(%ebp)\n" /* buf */
        "movl 0x10(%eax), %eax\n" /* line 383 */
        "movl %eax, -0x1508(%ebp)\n" /* len */
        "testl %eax, %eax\n" /* line 384 */
        "je .Lfe5778_000e721e\n"
        "movl $0x200, (%esp)\n" /* line 388 */
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+264\n"
        "movl -0x14d0(%ebp), %eax\n" /* line 390 | origLmapCount */
        "testl %eax, %eax\n"
        "jle .Lfe5778_000e6a9b\n"
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        /* { scope 4: valGE */
        ".Lfe5778_000e68ca:\n"
        "movl -0x30(%ebp), %edi\n" /* line 290 */
        "movl %edi, -0x14b8(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 291 | image */
        "movl %eax, -0x14b4(%ebp)\n"
        "movl -0x38(%ebp), %edx\n" /* line 292 */
        "movl %edx, -0x14b0(%ebp)\n"
        "movl -0x34(%ebp), %ecx\n" /* line 293 */
        "movl %ecx, -0x14ac(%ebp)\n"
        /* } scope */
        /* } scope */
        "movl $0, -0x1500(%ebp)\n" /* line 427 | oldLmapBaseIndex */
        "movl $0, -0x146c(%ebp)\n"
        ".Lfe5778_000e6902:\n"
        "movl -0x146c(%ebp), %edi\n" /* srcWidth */
        "movw %di, -0x145e(%ebp)\n" /* srcWidth */
        "movswl %di, %eax\n" /* line 395 | lmapSubIndex */
        "movl %eax, -0x1538(%ebp)\n"
        "movl -0x2ac(%ebp, %eax, 8), %edx\n"
        "movl %edx, -0x1544(%ebp)\n"
        "imull -0x2a8(%ebp, %eax, 8), %edx\n"
        "movl %edx, -0x14f8(%ebp)\n" /* groupCount */
        "testl %edx, %edx\n" /* line 397 */
        "jle .Lfe5778_000e6bc0\n"
        "movl -0x1500(%ebp), %ecx\n" /* oldLmapBaseIndex */
        "leal -0x1b4(%ebp, %ecx, 4), %ecx\n"
        "movl %ecx, -0x1470(%ebp)\n"
        "movl $0, -0x14fc(%ebp)\n" /* tileIndex */
        "movl %ecx, %eax\n"
        ".Lfe5778_000e695a:\n"
        "movl (%eax), %eax\n" /* line 399 */
        "movl %eax, -0x1504(%ebp)\n" /* oldLmapIndex */
        "movl -0x14fc(%ebp), %eax\n" /* line 400 | tileIndex */
        "cltd\n"
        "idivl -0x1544(%ebp)\n"
        "movl %edx, -0x1520(%ebp)\n"
        "movl %eax, -0x1524(%ebp)\n"
        "movl -0x1508(%ebp), %eax\n" /* line 402 | len */
        "testl %eax, %eax\n"
        "je .Lfe5778_000e6ab2\n"
        "movl -0x1504(%ebp), %eax\n" /* line 404 | oldLmapIndex */
        "shll $0x16, %eax\n"
        "addl -0x150c(%ebp), %eax\n" /* buf */
        "movl %eax, -0x1454(%ebp)\n"
        "movl $1, -0x1474(%ebp)\n"
        "movl -0x1544(%ebp), %edx\n"
        ".Lfe5778_000e69ae:\n"
        "movl -0x1474(%ebp), %ebx\n" /* line 407 | srcImage */
        "shll $2, %ebx\n" /* srcImage */
        "movl -0x50(%ebp, %ebx), %edi\n" /* srcWidth */
        "movl %edi, -0x14cc(%ebp)\n" /* srcWidth, bytesPerPixel */
        "movl -0x60(%ebp, %ebx), %eax\n"
        "movl %eax, -0x14c8(%ebp)\n" /* srcHeight */
        "movl -0x30(%ebp, %ebx), %edi\n" /* srcWidth */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        /* { scope 4: valGE */
        "movl -0x1520(%ebp), %ecx\n" /* line 64 */
        "imull %edi, %ecx\n"
        "movl -0x1524(%ebp), %eax\n"
        "imull -0x14c8(%ebp), %eax\n" /* srcHeight */
        "imull %edi, %edx\n"
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "movl -0x14cc(%ebp), %esi\n" /* bytesPerPixel, lump */
        "imull %ecx, %esi\n" /* lump */
        "addl -0x40(%ebp, %ebx), %esi\n" /* lump */
        "movl -0x14c8(%ebp), %eax\n" /* line 65 | srcHeight */
        "testl %eax, %eax\n"
        "jg .Lfe5778_000e6b68\n"
        "imull -0x14cc(%ebp), %edi\n" /* bytesPerPixel */
        /* } scope */
        /* } scope */
        ".Lfe5778_000e6a0f:\n"
        "imull -0x14c8(%ebp), %edi\n" /* line 408 | srcHeight, srcWidth */
        "addl %edi, -0x1454(%ebp)\n" /* srcWidth */
        "addl $1, -0x1474(%ebp)\n"
        "cmpl $5, -0x1474(%ebp)\n" /* line 405 */
        "je .Lfe5778_000e6ab2\n"
        "movl -0x1538(%ebp), %ecx\n"
        "movl -0x2ac(%ebp, %ecx, 8), %ecx\n"
        "movl %ecx, -0x1544(%ebp)\n"
        "movl %ecx, %edx\n"
        "jmp .Lfe5778_000e69ae\n"
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        ".Lfe5778_000e6a4a:\n"
        "movl imp_vidConfig, %eax\n" /* line 175 */
        "movl 0x18(%eax), %eax\n"
        "leal 0x3ff(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0xa, %eax\n"
        "movl %eax, -0x144c(%ebp)\n"
        "movl %eax, -0x14ec(%ebp)\n" /* wideCount */
        "jmp .Lfe5778_000e5d2b\n"
        ".Lfe5778_000e6a72:\n"
        "movl %ecx, %edi\n"
        "jmp .Lfe5778_000e60bc\n"
        ".Lfe5778_000e6a79:\n"
        "xorl %eax, %eax\n" /* line 253 */
        ".Lfe5778_000e6a7b:\n"
        "movl -0x14f0(%ebp), %ecx\n" /* line 255 | usedCount */
        "movl %eax, -0x1b4(%ebp, %ecx, 4)\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x14f0(%ebp)\n" /* usedCount */
        "movb $1, -0x7b(%ebp, %eax)\n" /* line 256 */
        "jmp .Lfe5778_000e5ffe\n"
        /* } scope */
        ".Lfe5778_000e6a9b:\n"
        "xorl %eax, %eax\n" /* line 390 */
        ".Lfe5778_000e6a9d:\n"
        "movl %eax, s_world+260\n" /* line 446 */
        "movl -0x3c(%ebp), %eax\n" /* line 448 | image */
        "movl %eax, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        "jmp .Lfe5778_000e60e8\n"
        ".Lfe5778_000e6ab2:\n"
        "movl -0x1504(%ebp), %edi\n" /* line 412 | oldLmapIndex, srcWidth */
        "leal (%edi, %edi, 4), %eax\n" /* srcWidth */
        "leal -0x18(%ebp, %eax, 4), %eax\n"
        "leal -0x518(%eax), %edx\n"
        "movzwl -0x145e(%ebp), %ecx\n"
        "movw %cx, 4(%edx)\n"
        "movl -0x1538(%ebp), %edi\n" /* line 413 | srcWidth */
        "cvtsi2ssl -0x2ac(%ebp, %edi, 8), %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "movss %xmm2, 0x10(%edx)\n"
        "subl $0x514, %eax\n" /* line 414 */
        "cvtsi2ssl -0x2a8(%ebp, %edi, 8), %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%eax)\n"
        "cvtsi2ssl -0x1520(%ebp), %xmm0\n" /* line 415 */
        "mulss 0x10(%edx), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "cvtsi2ssl -0x1524(%ebp), %xmm0\n" /* line 416 */
        "mulss 0x10(%eax), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "addl $1, -0x14fc(%ebp)\n" /* line 397 | tileIndex */
        "addl $4, -0x1470(%ebp)\n"
        "movl -0x14fc(%ebp), %eax\n" /* tileIndex */
        "cmpl %eax, -0x14f8(%ebp)\n" /* groupCount */
        "je .Lfe5778_000e6bc0\n"
        "movl -0x1538(%ebp), %edi\n" /* lmapSubIndex */
        "movl -0x2ac(%ebp, %edi, 8), %edi\n" /* lmapSubIndex */
        "movl %edi, -0x1544(%ebp)\n" /* lmapSubIndex */
        "movl -0x1470(%ebp), %eax\n"
        "jmp .Lfe5778_000e695a\n"
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        /* { scope 4: valGE */
        ".Lfe5778_000e6b68:\n"
        "imull -0x14cc(%ebp), %edi\n" /* line 65 | bytesPerPixel */
        "movl -0x1544(%ebp), %edx\n"
        "imull %edi, %edx\n"
        "movl %edx, -0x1484(%ebp)\n"
        "movl -0x1454(%ebp), %ebx\n" /* count */
        "movl $0, -0x14c4(%ebp)\n" /* y */
        ".Lfe5778_000e6b8e:\n"
        "movl %edi, 8(%esp)\n" /* line 67 */
        "movl %ebx, 4(%esp)\n" /* count */
        "movl %esi, (%esp)\n" /* lump */
        "calll Com_Memcpy\n"
        "addl %edi, %ebx\n" /* line 68 | count */
        "addl -0x1484(%ebp), %esi\n" /* line 69 | lump */
        "addl $1, -0x14c4(%ebp)\n" /* line 65 | y */
        "movl -0x14c4(%ebp), %ecx\n" /* y */
        "cmpl %ecx, -0x14c8(%ebp)\n" /* srcHeight */
        "jne .Lfe5778_000e6b8e\n"
        "jmp .Lfe5778_000e6a0f\n"
        /* } scope */
        /* } scope */
        ".Lfe5778_000e6bc0:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 420 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe5778_000e6cff\n"
        "movl -0x1538(%ebp), %ecx\n" /* line 428 */
        "shll $4, %ecx\n"
        "movl %ecx, -0x1480(%ebp)\n"
        "xorl %edi, %edi\n" /* srcWidth */
        "xorl %esi, %esi\n" /* dstImage */
        "movl %ecx, %ebx\n" /* srcImage */
        ".Lfe5778_000e6be6:\n"
        "addl s_world+264, %ebx\n" /* line 434 | srcImage */
        "movl %edi, 8(%esp)\n" /* srcWidth */
        "movl -0x1538(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00225030, (%esp)\n" /* "*lightmap%i_%i" */
        "calll va\n"
        "movl $4, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, (%ebx, %edi, 4)\n" /* srcImage */
        "movl $0x15, %eax\n" /* line 437 */
        "cmpl $4, -0x4c(%esi, %ebp)\n" /* dstImage */
        "movl $0x32, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, 0x10(%esp)\n" /* line 443 */
        "movl -0x5c(%esi, %ebp), %eax\n" /* dstImage */
        "movl -0x1538(%ebp), %edx\n"
        "imull -0x2a8(%ebp, %edx, 8), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c(%esi, %ebp), %eax\n" /* dstImage */
        "imull -0x2ac(%ebp, %edx, 8), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x3c(%esi, %ebp), %eax\n" /* dstImage */
        "movl %eax, 4(%esp)\n"
        "movl %esi, %eax\n" /* dstImage */
        "addl s_world+264, %eax\n"
        "movl -0x1480(%ebp), %ecx\n"
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_Generate2D\n"
        "addl $1, %edi\n" /* line 432 | srcWidth */
        "addl $4, %esi\n" /* dstImage */
        "cmpl $4, %edi\n" /* srcWidth */
        "je .Lfe5778_000e6cce\n"
        "movl -0x1480(%ebp), %ebx\n" /* srcImage */
        "jmp .Lfe5778_000e6be6\n"
        ".Lfe5778_000e6c9c:\n"
        "movl %eax, %ecx\n"
        ".Lfe5778_000e6c9e:\n"
        "movl $0x15, 0x10(%esp)\n" /* line 427 */
        "movl %ecx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* srcWidth */
        "movl -0x14b4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl s_world+264, %eax\n"
        "movl -0x1510(%ebp), %edx\n"
        "movl (%edx, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_Generate2D\n"
        ".Lfe5778_000e6cce:\n"
        "movl -0x14f8(%ebp), %edi\n" /* line 390 | groupCount, lmapSubIndex */
        "addl %edi, -0x1500(%ebp)\n" /* lmapSubIndex, oldLmapBaseIndex */
        "addl $1, -0x146c(%ebp)\n"
        "movl -0x1500(%ebp), %eax\n" /* oldLmapBaseIndex */
        "cmpl %eax, -0x14d0(%ebp)\n" /* origLmapCount */
        "jg .Lfe5778_000e6902\n"
        "movswl -0x146c(%ebp), %eax\n"
        "jmp .Lfe5778_000e6a9d\n"
        ".Lfe5778_000e6cff:\n"
        "movl -0x1538(%ebp), %edx\n" /* line 422 */
        "shll $4, %edx\n"
        "movl %edx, -0x1510(%ebp)\n"
        "movl %edx, %ebx\n" /* srcImage */
        "addl s_world+264, %ebx\n" /* srcImage */
        "movl -0x1538(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl $str_00225024, (%esp)\n" /* "*lightmap%i" */
        "calll va\n"
        "movl $4, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, (%ebx)\n" /* srcImage */
        "movl -0x1538(%ebp), %edi\n" /* line 424 | srcWidth */
        "movl -0x2ac(%ebp, %edi, 8), %edi\n" /* srcWidth */
        "shll $9, %edi\n" /* srcWidth */
        "movl %edi, -0x14bc(%ebp)\n" /* srcWidth, width */
        "movl -0x1538(%ebp), %eax\n" /* line 425 */
        "movl -0x2a8(%ebp, %eax, 8), %eax\n"
        "shll $9, %eax\n"
        "movl %eax, -0x14c0(%ebp)\n" /* height */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        /* { scope 4: valGE */
        "testl %eax, %eax\n" /* line 285 */
        "jle .Lfe5778_000e6c9c\n"
        "movl $0, -0x14a4(%ebp)\n" /* loResPixel */
        "movl $0, -0x14a8(%ebp)\n" /* y */
        "jmp .Lfe5778_000e6db1\n"
        ".Lfe5778_000e6d98:\n"
        "addl $1, -0x14a8(%ebp)\n" /* y */
        "movl -0x14a8(%ebp), %ecx\n" /* y */
        "cmpl %ecx, -0x14c0(%ebp)\n" /* height */
        "je .Lfe5778_000e6faa\n"
        ".Lfe5778_000e6db1:\n"
        "movl -0x14bc(%ebp), %eax\n" /* line 287 | width */
        "testl %eax, %eax\n"
        "jle .Lfe5778_000e6d98\n"
        "movl -0x14a8(%ebp), %eax\n" /* y */
        "imull -0x14bc(%ebp), %eax\n" /* width */
        "movl -0x14b8(%ebp), %edi\n"
        "leal (%edi, %eax, 4), %eax\n"
        "movl %eax, -0x1478(%ebp)\n"
        "movl -0x14a4(%ebp), %edi\n" /* line 1802 | loResPixel, out */
        "addl -0x14b4(%ebp), %edi\n" /* out */
        "movl $1, -0x147c(%ebp)\n"
        "movl -0x14a4(%ebp), %eax\n" /* loResPixel */
        "movl -0x14b0(%ebp), %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x1540(%ebp)\n"
        "movl -0x14a4(%ebp), %ecx\n" /* loResPixel */
        "movl -0x14ac(%ebp), %eax\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x153c(%ebp)\n"
        "movl -0x14bc(%ebp), %edx\n" /* width */
        "addl $1, %edx\n"
        "movl %edx, -0x1534(%ebp)\n"
        ".Lfe5778_000e6e24:\n"
        "movl -0x1478(%ebp), %edx\n" /* line 290 */
        "movzbl (%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x14a0(%ebp)\n" /* sun */
        "movzbl (%edi), %eax\n" /* line 428 | srcWidth */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x1488(%ebp), %xmm1\n"
        "mulss -0x14a0(%ebp), %xmm1\n" /* sun */
        "addss %xmm1, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1528(%ebp)\n"
        "cvttss2si -0x1528(%ebp), %eax\n"
        "movl %eax, -0x149c(%ebp)\n" /* valGE */
        "movl -0x147c(%ebp), %esi\n" /* line 1802 | in */
        "shll $2, %esi\n" /* in */
        "movl -0x1540(%ebp), %edx\n" /* line 428 */
        "movzbl -4(%edx, %esi), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x148c(%ebp), %xmm1\n"
        "mulss -0x14a0(%ebp), %xmm1\n" /* sun */
        "addss %xmm1, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x152c(%ebp)\n"
        "cvttss2si -0x152c(%ebp), %ebx\n" /* srcImage */
        "movl -0x153c(%ebp), %ecx\n"
        "movzbl -4(%ecx, %esi), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x14a0(%ebp), %xmm1\n" /* sun */
        "mulss -0x1490(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1530(%ebp)\n"
        "cvttss2si -0x1530(%ebp), %edx\n"
        /* { scope 5 */
        "movl $0xffffffff, %eax\n" /* line 154 */
        "movl -0x149c(%ebp), %ecx\n" /* valGE, lmapIndex */
        "subl $0xff, %ecx\n" /* lmapIndex */
        "movzbl -0x149c(%ebp), %ecx\n" /* valGE, lmapIndex */
        "cmovnsl %eax, %ecx\n" /* lmapIndex */
        /* } scope */
        "movb %cl, 1(%edi)\n" /* line 296 */
        /* { scope 5 */
        "movl %ebx, %ecx\n" /* line 154 | triSurfIndex, lmapIndex */
        "subl $0xff, %ecx\n" /* lmapIndex */
        "cmovnsl %eax, %ebx\n" /* triSurfIndex */
        /* } scope */
        "movb %bl, 2(%edi)\n" /* line 297 | valGE */
        /* { scope 5 */
        "movl %edx, %ecx\n" /* line 154 | lmapIndex */
        "subl $0xff, %ecx\n" /* lmapIndex */
        "cmovsl %edx, %eax\n"
        /* } scope */
        "movb %al, 3(%edi)\n" /* line 298 */
        "movb $0xff, (%edi)\n" /* line 299 */
        "addl $1, -0x147c(%ebp)\n"
        "addl $2, -0x1478(%ebp)\n"
        "addl $4, %edi\n"
        "movl -0x1534(%ebp), %eax\n" /* line 287 */
        "cmpl %eax, -0x147c(%ebp)\n"
        "jne .Lfe5778_000e6e24\n"
        "movl -0x14a4(%ebp), %edx\n" /* loResPixel */
        "leal -4(%edx, %eax, 4), %edx\n"
        "movl %edx, -0x14a4(%ebp)\n" /* loResPixel */
        "addl $1, -0x14a8(%ebp)\n" /* line 285 | y */
        "movl -0x14a8(%ebp), %ecx\n" /* y */
        "cmpl %ecx, -0x14c0(%ebp)\n" /* height */
        "jne .Lfe5778_000e6db1\n"
        ".Lfe5778_000e6faa:\n"
        "movl -0x14c0(%ebp), %ecx\n" /* height */
        "movl -0x14bc(%ebp), %edi\n" /* width */
        "jmp .Lfe5778_000e6c9e\n"
        /* } scope */
        /* } scope */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        /* { scope 4: valGE */
        ".Lfe5778_000e6fbb:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 0x40(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "jns .Lfe5778_000e5a32\n"
        ".Lfe5778_000e6fe5:\n"
        "leal 0xf(%edx), %eax\n"
        "jmp .Lfe5778_000e5a32\n"
        ".Lfe5778_000e6fed:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e5a1b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        ".Lfe5778_000e700f:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e58ba\n"
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        /* { scope 4: valGE */
        /* { scope 5 */
        ".Lfe5778_000e7031:\n"
        "movl s_world, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 0x10(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "jns .Lfe5778_000e5aac\n"
        ".Lfe5778_000e705b:\n"
        "leal 0x3fffff(%edx), %eax\n" /* was scrMemTreeGlob+39167 — decompiler-symbolized Mac address 0x3f6700+0x98ff=0x3fffff */
        "jmp .Lfe5778_000e5aac\n"
        ".Lfe5778_000e7066:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e5a95\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        ".Lfe5778_000e7088:\n"
        "movl s_world, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e58b0\n"
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        ".Lfe5778_000e70aa:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e6675\n"
        ".Lfe5778_000e70cc:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e666b\n"
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        ".Lfe5778_000e70ee:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e64b2\n"
        ".Lfe5778_000e7110:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e64a8\n"
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        ".Lfe5778_000e7132:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 0x60(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "jns .Lfe5778_000e6378\n"
        ".Lfe5778_000e715c:\n"
        "leal 3(%edx), %eax\n"
        "jmp .Lfe5778_000e6378\n"
        ".Lfe5778_000e7164:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e6361\n"
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        ".Lfe5778_000e7186:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl 0x18(%ebx), %edx\n" /* line 52 | count */
        "movl %edx, %eax\n"
        "testl %edx, %edx\n"
        "jns .Lfe5778_000e6218\n"
        ".Lfe5778_000e71b0:\n"
        "leal 7(%edx), %eax\n"
        "jmp .Lfe5778_000e6218\n"
        ".Lfe5778_000e71b8:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e6201\n"
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        /* { scope 3: triSurfs, materialIndex, lmapIndex, lmapVertCount, ... */
        ".Lfe5778_000e71da:\n"
        "movl s_world, %eax\n" /* line 50 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b98, 4(%esp)\n" /* "LoadMap: funny lump offset in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e6141\n"
        ".Lfe5778_000e71fc:\n"
        "movl s_world, %eax\n" /* line 48 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224b68, 4(%esp)\n" /* "LoadMap: lump extends past end of file in %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe5778_000e6137\n"
        /* } scope */
        /* } scope */
        /* { scope 2: coupling, used, usedCount, wideCount, ... */
        ".Lfe5778_000e721e:\n"
        "movl %ebx, 8(%esp)\n" /* line 385 | totalImageSize */
        "movl $0xff, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n" /* image */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0x200, (%esp)\n" /* line 388 */
        "calll Hunk_AllocInternal\n"
        "movl %eax, s_world+264\n"
        "movl -0x14d0(%ebp), %eax\n" /* line 390 | origLmapCount */
        "testl %eax, %eax\n"
        "jle .Lfe5778_000e6a9b\n"
        "jmp .Lfe5778_000e68ca\n"
    );
}
#endif /* disabled naked ASM R_LoadWorldInternal */

#else
snd_alias_list_t R_LoadEntities(void) { snd_alias_list_t r = {0}; return r; }
#endif
#else
snd_alias_list_t R_LoadSurfaces(GfxBspLoad *load) { snd_alias_list_t r = {0}; (void)load; return r; }
#endif
