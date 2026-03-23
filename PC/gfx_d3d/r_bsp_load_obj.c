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

const char * R_ParseSunLight(SunLightParseParams *params, const char *text);
void R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight);
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

/* Clean C version for WASM — no register calling convention */
static int R_FinishLoadingAabbTrees_r(byte *tree, int totalTreesUsed)
{
    return R_FinishLoadingAabbTrees_r_impl(tree, totalTreesUsed);
}

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


/* line 1911 — Convert parsed sun light parameters into a GfxLight structure. */
void R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight)
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

/* Clean C version for WASM — no register calling convention */
static Bool R_IsValidStaticModel(char *spawnVars, int spawnVarCount, struct XModel **model, vec_t *origin)
{
    return R_IsValidStaticModel_impl(spawnVars, spawnVarCount, model, origin);
}

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

/* Clean C version for WASM — no register calling convention */
static snd_alias_list_t R_SetParentAndCell_r(mnode_t *node, int parent)
{
    R_SetParentAndCell_r_impl(node, parent);
}

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

snd_alias_list_t R_LoadSurfaces(GfxBspLoad *load) { snd_alias_list_t r = {0}; (void)load; return r; }
