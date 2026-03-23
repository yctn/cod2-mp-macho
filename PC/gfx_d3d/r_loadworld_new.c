/*
 * R_LoadWorldInternal - Complete C reimplementation
 *
 * Replaces the naked ASM version in r_bsp_load_obj.c (lines 3879-5567).
 * Loads a BSP world file and populates the global s_world structure.
 */

#include "common_types.h"
#include "imports.h"

#include <math.h>   /* floorf */
#include <string.h> /* strlen, strcpy, memset */

/* ---- External globals ---- */
extern GfxWorld s_world;
extern struct r_globals_load_t rgl;
extern void *imp_ri;
extern void *imp_r_optimizeLightmaps;
extern void *imp_r_rendererInUse;
extern void *imp_vidConfig;

/* ---- External functions ---- */
extern void R_Error(int level, const char *msg, ...);
extern void *Hunk_AllocInternal(int size);
extern void *Hunk_AllocateTempMemoryInternal(int size);
extern void Hunk_FreeTempMemory(void *buf);
extern dheader_t *Com_GetBsp(int *fileSize, unsigned int *checksum);
extern const char *Com_SkipPath(const char *path);
extern void Com_StripExtension(const char *in, char *out);
extern void I_strncpyz(char *dest, const char *src, int size);
extern void Com_Memset(void *dest, int val, int count);
extern void Com_Memcpy(void *dest, const void *src, int count);
extern void Com_Printf(const char *fmt, ...);
extern const char *va(const char *fmt, ...);
extern void *Image_Alloc(const char *name, int type1, int type2, int type3);
extern void Image_Generate2D(void *image, byte *data, int width, int height, int format);
extern const char *R_ParseSunLight(SunLightParseParams *params, const char *text);
extern void R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight);
extern void R_LoadSun(const char *name, sunflare_t *sun);
extern void R_RegisterOutdoorImage(GfxWorld *world);

/* Helper loaders (naked ASM functions that expect load pointer in eax register).
 * They use a non-standard calling convention: the GfxBspLoad* argument is passed
 * in eax, NOT on the stack as cdecl would require. We use inline asm wrappers. */
extern void R_LoadSurfaces(GfxBspLoad *load);
extern void R_LoadCullGroups(void);
extern void R_LoadPortalVerts(void);
extern void R_LoadOccluders(void);
extern void R_LoadAabbTrees(void);
extern void R_LoadCells(GfxBspLoad *load);
extern void R_LoadPortals(void);
extern void R_LoadNodesAndLeafs(void);
extern void R_LoadEntities(void);

/* Call a naked ASM loader that expects its argument in eax (regparm(1)).
 * The naked functions read their single pointer argument from eax,
 * which matches GCC's __attribute__((regparm(1))) calling convention. */
typedef void (*loader_regparm_fn)(void *) __attribute__((regparm(1)));
#define CALL_LOADER_EAX(func, arg) \
    ((loader_regparm_fn)(func))((void *)(arg))

/* ---- Constants ---- */
#define LIGHTMAP_NONE       31
#define MAX_LIGHTMAPS       31
#define LIGHTMAP_PIXELS     (1024 * 1024)
#define LIGHTMAP_BYTES      (LIGHTMAP_PIXELS * 4)  /* 0x400000 = 4 MB per lightmap */
#define MAX_MERGED_GROUPS   32

/* ---- Helper macros for accessing renderer import table ---- */
#define RI_PRINTF(fmt, ...)   ((void (*)(int, const char *, ...))*(void **)(((byte *)&imp_ri)[0]))(0, fmt, ##__VA_ARGS__)
#define UPDATE_SCREEN()       ((refimport_t *)imp_ri)->Cbuf_ExecuteText(0, "updatescreen\n")

/*
 * R_PrintLoadProgress - Print a "Loading ..." message and update the screen.
 */
static void R_PrintLoadProgress(const char *what)
{
    refimport_t *ri = (refimport_t *)imp_ri;
    ri->Printf(0, "Loading %s...\n", what);
    ri->Cbuf_ExecuteText(0, "updatescreen\n");
}

/*
 * R_ValidateLumpRaw - Validate and retrieve a BSP lump using raw header byte offsets.
 *
 * This reads the lump size and file offset directly from the header bytes,
 * bypassing the lump_t struct (whose field order may not match the binary layout).
 *
 * lumpByteOfs: byte offset into the header for this lump (e.g. 8 for lump 0, 0x40 for lump 7)
 * elemSize: size of each element in the lump
 * countOut: receives the element count
 * dataOut: if non-NULL, receives a pointer to the lump data (fileBase + fileOffset)
 *
 * Returns the raw lump byte-size.
 */
static int R_ValidateLumpRaw(const byte *header, const byte *fileBase, int fileSize,
                             int lumpByteOfs, int elemSize, int *countOut, const byte **dataOut)
{
    int lumpSize    = *(int *)(header + lumpByteOfs);
    int lumpFileOfs = *(int *)(header + lumpByteOfs + 4);
    int count;

    if (lumpFileOfs + lumpSize > fileSize)
        R_Error(1, "LoadMap: lump extends past end of file in %s", s_world.name);
    if (lumpFileOfs <= 3) {
        Com_Printf("DBG funny lump offset: byteOfs=0x%x size=%d fileOfs=%d\n", lumpByteOfs, lumpSize, lumpFileOfs);
        /* Allow zero-size lumps (empty occluder indices, etc.) */
        if (lumpSize == 0) {
            if (countOut) *countOut = 0;
            if (dataOut) *dataOut = NULL;
            return 0;
        }
        R_Error(1, "LoadMap: funny lump offset in %s", s_world.name);
    }

    if (lumpSize < 0)
        count = (lumpSize + elemSize - 1) / elemSize;
    else
        count = lumpSize / elemSize;

    if (count * elemSize != lumpSize)
        R_Error(1, "LoadMap: funny lump size in %s", s_world.name);

    if (countOut)
        *countOut = count;
    if (dataOut)
        *dataOut = fileBase + lumpFileOfs;
    return lumpSize;
}

/*
 * Lump byte offsets within the BSP header.
 * Each lump_t entry is 8 bytes. The lumps array starts at header offset 8.
 * Lump N is at header offset 8 + N*8.
 */
#define LUMP_OFS_MATERIALS       0x08   /* lump 0: materials (72 bytes each) */
#define LUMP_OFS_LIGHTMAPS       0x10   /* lump 1: lightmap pixel data */
#define LUMP_OFS_GRIDPOINTS      0x18   /* lump 2: lightgrid hash points (8 bytes each) */
#define LUMP_OFS_GRIDCOLORS      0x20   /* lump 3: lightgrid colors (24 bytes each) */
#define LUMP_OFS_TRIANGLES       0x40   /* lump 7: triangle soups (16 bytes each) */
#define LUMP_OFS_CULLGROUPIDX    0x60   /* lump 11: cull group indices (4 bytes each) */
#define LUMP_OFS_OCCLUDERS       0xA8   /* lump 20: occluder planes */
#define LUMP_OFS_OCCLUDERIDX     0xB0   /* lump 21: occluder indices (2 bytes each) */
#define LUMP_OFS_SUBMODELS       0x120  /* lump 35: submodels (48 bytes each) */
#define LUMP_OFS_ENTITIES        0x130  /* lump 37: entity string data */

/* ================================================================
 *                    R_LoadWorldInternal
 * ================================================================ */
GfxWorld *R_LoadWorldInternal(const char *name)
{
    /* Local variables */
    GfxBspLoad load;
    char baseName[64];
    const byte *header;
    const byte *fileBase;

    /* Lightmap merging locals */
    r_lightmapGroup_t groupInfo[MAX_LIGHTMAPS];
    int reorder[MAX_LIGHTMAPS];
    int coupling[MAX_LIGHTMAPS][MAX_LIGHTMAPS];
    int lmapVertCount[MAX_LIGHTMAPS];
    byte used[MAX_LIGHTMAPS];
    int origLmapCount;
    int wideCount, highCount;
    int triSoupCount;
    const DiskTriangleSoup *triSurfs;
    const byte *lmapData;
    int lmapDataSize;

    /* Image generation locals */
    byte *imageBuffer[4];
    int subImgBytesPerPixel[4];
    int subImgWidth[4];
    int subImgHeight[4];

    /* Submodel locals */
    int modelCount;

    int i, j, k;
    int nameLen;

    /* ================================================================
     * Phase 0: Init - clear s_world, get BSP header, setup names
     * ================================================================ */
    memset(&s_world, 0, sizeof(GfxWorld));
    memset(&rgl, 0, 6 * 4);  /* clear first 6 dwords of rgl */

    /* Get the BSP data from the engine.
     * Com_GetBsp writes the file size into the first arg and checksum into the second.
     * We pass &load.fileSize directly so it populates the load struct. */
    header = (const byte *)Com_GetBsp(&load.fileSize, &s_world.checksum);
    fileBase = (const byte *)header;

    /* Store header and fileBase into load struct */
    load.header = (const dheader_t *)header;
    load.fileBase = fileBase;

    /* Allocate and copy the world name */
    nameLen = strlen(name) + 1;
    s_world.name = (const char *)Hunk_AllocInternal(nameLen);
    strcpy((char *)s_world.name, name);

    /* Derive and store the base name (filename without path and extension) */
    I_strncpyz(baseName, Com_SkipPath(s_world.name), 64);
    Com_StripExtension(baseName, baseName);
    nameLen = strlen(baseName) + 1;
    s_world.baseName = (const char *)Hunk_AllocInternal(nameLen);
    strcpy((char *)s_world.baseName, baseName);

    /* ================================================================
     * Phase 1: Load materials (lump 0, 72 bytes each)
     * ================================================================ */
    R_PrintLoadProgress("materials");
    {
        const byte *mtlData;
        int mtlCount;
        R_ValidateLumpRaw(header, fileBase, load.fileSize,
                          LUMP_OFS_MATERIALS, 72, &mtlCount, &mtlData);
        load.materialCount = mtlCount;
        load.materials = (const dmaterial_t *)mtlData;
    }

    /* ================================================================
     * Phase 2: Load sun settings (entity string in lump 37)
     * ================================================================ */
    R_PrintLoadProgress("sun settings");
    {
        /* Entity string file offset is at header + LUMP_OFS_ENTITIES + 4 */
        int entityOfs = *(int *)(header + LUMP_OFS_ENTITIES + 4);
        const char *entityString = (const char *)(fileBase + entityOfs);
        R_ParseSunLight(&s_world.sunParse, entityString);
        R_InterpretSunLightParseParamsIntoLights(&s_world.sunParse, &s_world.sunLight);
    }

    /* ================================================================
     * Phase 3: Load lightmaps (lump 1 for data, lump 7 for triangle soups)
     * ================================================================ */
    R_PrintLoadProgress("lightmaps");

    /* Cache sun color for the low-res lightmap combination pass (DX9 path) */
    float sunR = s_world.sunLight.color[0];
    float sunG = s_world.sunLight.color[1];
    float sunB = s_world.sunLight.color[2];

    /* Initialize the LIGHTMAP_NONE merge entry as identity */
    load.lmapMergeInfo[LIGHTMAP_NONE].index = LIGHTMAP_NONE;
    load.lmapMergeInfo[LIGHTMAP_NONE].shift[0] = 0.0f;
    load.lmapMergeInfo[LIGHTMAP_NONE].shift[1] = 0.0f;
    load.lmapMergeInfo[LIGHTMAP_NONE].scale[0] = 1.0f;
    load.lmapMergeInfo[LIGHTMAP_NONE].scale[1] = 1.0f;

    /* --- Phase 3a: Validate triangle soup lump (lump 7, 16 bytes each) --- */
    R_ValidateLumpRaw(header, fileBase, load.fileSize,
                      LUMP_OFS_TRIANGLES, 16, &triSoupCount, (const byte **)&triSurfs);

    /* --- Phase 3b: Validate lightmap data lump (lump 1, 4 MB each) --- */
    lmapDataSize = R_ValidateLumpRaw(header, fileBase, load.fileSize,
                                     LUMP_OFS_LIGHTMAPS, LIGHTMAP_BYTES,
                                     NULL, &lmapData);
    int lmapPageCount = lmapDataSize / LIGHTMAP_BYTES;

    /* --- Phase 3c: Count original lightmaps from triangle soups --- */
    if (triSoupCount > 0) {
        origLmapCount = 0;
        for (i = 0; i < triSoupCount; i++) {
            int lmIdx = (int)(unsigned short)triSurfs[i].lightmapIndex;
            if ((short)lmIdx != LIGHTMAP_NONE) {
                int candidate = (int)(signed short)lmIdx + 1;
                if (candidate > origLmapCount)
                    origLmapCount = candidate;
            }
        }
    } else {
        origLmapCount = 0;
    }

    /* Verify lightmap page count matches */
    if (lmapPageCount != 0 && lmapPageCount != origLmapCount)
        R_Error(1, "LoadMap: funny lump size in %s", s_world.name);

    /* --- Phase 3d: Build coupling matrix --- */
    memset(lmapVertCount, 0, sizeof(int) * MAX_LIGHTMAPS);
    memset(coupling, 0, sizeof(int) * MAX_LIGHTMAPS * MAX_LIGHTMAPS);

    /* For each material, accumulate vertex counts per lightmap and build coupling info */
    for (int materialIndex = 0; materialIndex < load.materialCount; materialIndex++) {
        /* Accumulate vertex counts per lightmap for this material */
        for (i = 0; i < triSoupCount; i++) {
            if ((signed short)triSurfs[i].materialIndex != materialIndex)
                continue;
            int lmIdx = (int)(unsigned short)triSurfs[i].lightmapIndex;
            if ((short)lmIdx == LIGHTMAP_NONE)
                continue;
            lmapVertCount[lmIdx] += (signed short)triSurfs[i].vertexCount;
        }

        /* Build coupling: for each lightmap pair that share this material, record coupling strength */
        for (int lmapIndex = 0; lmapIndex < origLmapCount; /* advanced in body */) {
            if (lmapVertCount[lmapIndex] == 0) {
                lmapIndex++;
                continue;
            }

            int nextLmap = lmapIndex + 1;
            if (nextLmap < origLmapCount) {
                for (j = nextLmap; j < origLmapCount; j++) {
                    if (lmapVertCount[j] == 0)
                        continue;
                    int strength = lmapVertCount[j] + lmapVertCount[lmapIndex] + coupling[lmapIndex][j];
                    if (strength < 0)
                        strength = 0x7FFFFFFF;  /* clamp overflow */
                    coupling[lmapIndex][j] = strength;
                    coupling[j][lmapIndex] = strength;
                }
            }

            /* Clear this lightmap's vertex count for the next material iteration */
            lmapVertCount[lmapIndex] = 0;

            /* Skip to next lightmap with nonzero vertex count */
            lmapIndex = nextLmap;
            while (lmapIndex < origLmapCount && lmapVertCount[lmapIndex] == 0)
                lmapIndex++;
        }
    }

    /* --- Phase 3e: Determine merge tile dimensions --- */
    memset(used, 0, sizeof(used));

    /* Lightmap optimization tile dimension.
     * Force 1x1 grouping — the stub renderer doesn't benefit from atlas merging
     * and the dvar read through imp_r_optimizeLightmaps returns garbage in some
     * configurations (double-indirection chain may be broken after hunk clear). */
    wideCount = 1;
    highCount = 1;

    /* --- Phase 3f: Greedy lightmap bin-packing --- */
    int newLmapCount;
    int usedCount;
    r_lightmapGroup_t *groupPtr;

    if (origLmapCount <= 0) {
        newLmapCount = 0;
    } else {
        usedCount = 0;
        newLmapCount = 0;
        groupPtr = groupInfo;
        int remaining = origLmapCount;

        while (usedCount < origLmapCount) {
            remaining = origLmapCount - usedCount;

            /* Find a tile size that fits the remaining lightmaps */
            int targetSize = wideCount * highCount;
            while (remaining < targetSize) {
                if (wideCount < highCount) {
                    highCount >>= 1;
                } else {
                    wideCount >>= 1;
                }
                targetSize = wideCount * highCount;
            }

            if (targetSize <= 1) {
                /* Single lightmap per group: find first unused */
                int found = -1;
                if (!used[0]) {
                    found = 0;
                } else {
                    for (i = 1; i < origLmapCount; i++) {
                        if (!used[i]) {
                            found = i;
                            break;
                        }
                    }
                }
                if (found < 0) {
                    /* All used, shouldn't happen */
                    break;
                }
                reorder[usedCount] = found;
                usedCount++;
                used[found] = 1;
            } else {
                /* Find the first unused lightmap to seed the group */
                int firstLmap = -1;
                int bestOther = LIGHTMAP_NONE;

                /* Find first unused lightmap */
                for (i = 0; i < origLmapCount; i++) {
                    if (!used[i]) {
                        firstLmap = i;
                        break;
                    }
                }

                /* Find the lightmap most strongly coupled to firstLmap */
                bestOther = LIGHTMAP_NONE;
                for (j = firstLmap + 1; j < origLmapCount; j++) {
                    if (used[j])
                        continue;
                    if (bestOther == LIGHTMAP_NONE ||
                        coupling[firstLmap][j] > coupling[firstLmap][bestOther]) {
                        bestOther = j;
                    }
                }

                /* Place the initial pair */
                reorder[usedCount] = firstLmap;
                reorder[usedCount + 1] = bestOther;
                usedCount += 2;
                used[firstLmap] = 1;
                used[bestOther] = 1;

                /* Fill remaining slots in this group */
                if (targetSize > 2) {
                    int slotIdx = usedCount;
                    for (int filled = 2; filled < targetSize; filled++) {
                        /* Merge coupling rows: add firstLmap's row into bestOther's row */
                        for (k = 0; k < origLmapCount; k++) {
                            coupling[bestOther][k] += coupling[firstLmap][k];
                            coupling[k][bestOther] = coupling[bestOther][k];
                        }

                        /* Find the unused lightmap most coupled to bestOther */
                        int nextBest = LIGHTMAP_NONE;
                        for (k = 0; k < origLmapCount; k++) {
                            if (used[k])
                                continue;
                            if (nextBest == LIGHTMAP_NONE ||
                                coupling[bestOther][k] > coupling[bestOther][nextBest]) {
                                nextBest = k;
                            }
                        }

                        reorder[slotIdx] = nextBest;
                        slotIdx++;
                        usedCount++;
                        used[nextBest] = 1;

                        /* Update firstLmap for next iteration's coupling merge */
                        firstLmap = nextBest;
                    }
                }
            }

            /* Record group dimensions */
            groupPtr->wideCount = wideCount;
            groupPtr->highCount = highCount;
            newLmapCount++;
            groupPtr++;

            /* Reset tile dimensions for next group if we exhausted this size */
            /* (wideCount and highCount persist for the next iteration) */
        }
    }

    Com_Printf("%i merged lightmaps from %i original lightmaps\n", newLmapCount, origLmapCount);

    /* --- Phase 3g: Generate lightmap images --- */
    if (origLmapCount == 0) {
        s_world.lightmapCount = 0;
    } else {
        /* Set up sub-image parameters (0-indexed, mapping to BSP sub-images 1-4):
         *   [0]-[2]: directional color channels, 4 bytes/pixel, 512x512 per tile.
         *   [3]:     primary lightmap / sun visibility, 1 byte/pixel, 1024x1024 per tile.
         */
        for (i = 0; i < 3; i++) {
            subImgBytesPerPixel[i] = 4;
            subImgWidth[i]  = 512;
            subImgHeight[i] = 512;
        }
        subImgBytesPerPixel[3] = 1;
        subImgWidth[3]  = 1024;
        subImgHeight[3] = 1024;

        /* Allocate temp buffer for the merged lightmap tile images.
         * Total size = wideCount * highCount of first group * 4 MB per tile
         * (using first group dimensions since it's the largest) */
        int firstGroupWide = groupInfo[0].wideCount;
        int firstGroupHigh = groupInfo[0].highCount;
        int totalImageSize = firstGroupWide * firstGroupHigh * LIGHTMAP_BYTES;

        imageBuffer[0] = (byte *)Hunk_AllocateTempMemoryInternal(totalImageSize);

        /* Compute sub-image base pointers within the merged buffer.
         * Each sub-image plane is laid out contiguously:
         *   image[k+1] = image[k] + (bpp[k] * width[k] * height[k] * tilesWide * tilesHigh) */
        for (i = 1; i < 4; i++) {
            int planeSize = subImgBytesPerPixel[i] * subImgWidth[i] * subImgHeight[i]
                            * firstGroupWide * firstGroupHigh;
            imageBuffer[i] = imageBuffer[i - 1] + planeSize;
        }

        /* Get the raw lightmap pixel data from the BSP */
        {
            int lmDataOfs = *(int *)(header + LUMP_OFS_LIGHTMAPS + 4);
            lmapData = fileBase + lmDataOfs;
            lmapDataSize = *(int *)(header + LUMP_OFS_LIGHTMAPS);
        }

        /* If no actual lightmap data, fill image buffer with 0xFF (white) */
        if (lmapDataSize == 0)
            memset(imageBuffer[0], 0xFF, totalImageSize);

        /* Allocate the GfxLightmapArray table (up to 32 groups, each is 4 GfxImage pointers = 16 bytes) */
        s_world.lightmaps = (GfxLightmapArray *)Hunk_AllocInternal(MAX_MERGED_GROUPS * sizeof(GfxLightmapArray));

        int groupIdx = 0;
        if (origLmapCount > 0) {
            /* --- Phase 3h: Copy tiles and generate images per group --- */
            /* Cache sub-image base pointers for the DX9 low-res path.
             * imageBuffer[3] = primary lightmap (1bpp, 1024x1024 per tile).
             * imageBuffer[0..2] = directional color channels (4bpp, 512x512). */
            byte *hiResBase  = imageBuffer[3];   /* 1bpp primary lightmap / sun visibility */
            byte *loResBase1 = imageBuffer[0];   /* 4bpp directional color channel 1 */
            byte *loResBase2 = imageBuffer[1];   /* 4bpp directional color channel 2 */
            byte *loResBase3 = imageBuffer[2];   /* 4bpp directional color channel 3 */

            int oldLmapBaseIndex = 0;

            while (oldLmapBaseIndex < origLmapCount) {
                short mergedIndex = (short)groupIdx;
                int grpWide = groupInfo[groupIdx].wideCount;
                int grpHigh = groupInfo[groupIdx].highCount;
                int groupTileCount = grpWide * grpHigh;

                /* Copy each tile in this group from the BSP lightmap data into the merged buffer */
                for (int tileIndex = 0; tileIndex < groupTileCount; tileIndex++) {
                    int oldLmapIndex = reorder[oldLmapBaseIndex + tileIndex];
                    int tileCol = tileIndex % grpWide;
                    int tileRow = tileIndex / grpWide;

                    if (lmapDataSize != 0) {
                        /* Source: 4 sub-images packed sequentially in the BSP per lightmap page.
                         * Order: [0]=4bpp 512x512, [1]=4bpp 512x512, [2]=4bpp 512x512, [3]=1bpp 1024x1024.
                         * Total = 3*1MB + 1MB = 4MB per page. */
                        const byte *srcPtr = lmapData + (unsigned int)oldLmapIndex * LIGHTMAP_BYTES;

                        for (int subImg = 0; subImg < 4; subImg++) {
                            int curWide = grpWide;
                            int bpp     = subImgBytesPerPixel[subImg];
                            int srcH    = subImgHeight[subImg];
                            int srcW    = subImgWidth[subImg];

                            /* Destination: row-interleaved within the merged sub-image plane */
                            int dstRowStride = curWide * srcW * bpp;
                            byte *dstBase = imageBuffer[subImg]
                                + ((tileRow * srcH * curWide * srcW) + (tileCol * srcW)) * bpp;

                            if (srcH > 0) {
                                int srcRowBytes = srcW * bpp;
                                for (int row = 0; row < srcH; row++) {
                                    Com_Memcpy(dstBase, srcPtr, srcRowBytes);
                                    srcPtr += srcRowBytes;
                                    dstBase += dstRowStride;
                                }
                            }

                            /* Re-read grpWide from groupInfo (matches original behavior) */
                            grpWide = groupInfo[groupIdx].wideCount;
                        }
                    }

                    /* Write the merge info for this original lightmap */
                    load.lmapMergeInfo[oldLmapIndex].index = mergedIndex;
                    load.lmapMergeInfo[oldLmapIndex].scale[0] = 1.0f / (float)grpWide;
                    load.lmapMergeInfo[oldLmapIndex].scale[1] = 1.0f / (float)grpHigh;
                    load.lmapMergeInfo[oldLmapIndex].shift[0] = (float)tileCol * load.lmapMergeInfo[oldLmapIndex].scale[0];
                    load.lmapMergeInfo[oldLmapIndex].shift[1] = (float)tileRow * load.lmapMergeInfo[oldLmapIndex].scale[1];
                }

                /* Generate GPU images for this lightmap group */
                int rendererInUse = (*(const dvar_t **)imp_r_rendererInUse)->current.integer;

                if (rendererInUse == 2) {
                    /* DX9 path: generate a single combined low-res image */
                    int grpOffset = groupIdx * (int)sizeof(GfxLightmapArray);

                    /* Allocate the primary lightmap image (sub-image 0) */
                    ((GfxImage **)((byte *)s_world.lightmaps + grpOffset))[0] =
                        (GfxImage *)Image_Alloc(va("*lightmap%i", groupIdx), 2, 1, 4);

                    int pixWidth  = grpWide * 512;   /* half-res width */
                    int pixHeight = grpHigh * 512;   /* half-res height */

                    if (pixHeight > 0) {
                        /* Combine the 4 sub-images into a single RGBA texture.
                         *
                         * hiRes (sub-image [3]) is 1bpp 1024x1024 per tile.
                         * loRes (sub-images [0],[1],[2]) are 4bpp 512x512 per tile.
                         *
                         * The hi-res is 2x the lo-res resolution, so we read every
                         * other hi-res pixel (step 2 horizontally) and every other
                         * row (y * pixWidth * 4 bytes = y * 2 hi-res rows).
                         *
                         * For each half-res pixel:
                         *   R = floor((loR[byte0] + sunR * sunVis) * 0.5 + 0.5)
                         *   G = floor((loG[byte0] + sunG * sunVis) * 0.5 + 0.5)
                         *   B = floor((loB[byte0] + sunB * sunVis) * 0.5 + 0.5)
                         *   Output ARGB = {0xFF, R, G, B} written in-place into loRes buffer 1.
                         */
                        int loResPixelOfs = 0;

                        for (int y = 0; y < pixHeight; y++) {
                            if (pixWidth <= 0)
                                continue;

                            /* hiResPtr = hiResBase + y * (2 * hiResRowStride)
                             *          = hiResBase + y * pixWidth * 4
                             * since pixWidth*4 = grpWide*512*4 = grpWide*2048 = 2*(grpWide*1024) = 2 hi-res rows */
                            byte *hiResPtr = hiResBase + y * pixWidth * 4;
                            byte *loR = loResBase1 + loResPixelOfs;
                            byte *loG = loResBase2 + loResPixelOfs;
                            byte *loB = loResBase3 + loResPixelOfs;

                            for (int x = 1; x <= pixWidth; x++) {
                                /* Sun visibility from hi-res primary (1 byte, stepping by 2) */
                                float sunVis = (float)(unsigned char)(*hiResPtr);

                                /* Red channel: read byte 0 of current lo-res pixel */
                                float valR = (float)(unsigned char)(*loR) + sunR * sunVis;
                                valR = floorf(valR * 0.5f + 0.5f);
                                int iR = (int)valR;
                                if (iR < 0) iR = 0;
                                if (iR > 255) iR = 255;

                                /* Green channel: read byte 0 of current pixel in sub-image 2 */
                                float valG = (float)(unsigned char)loG[x * 4 - 4] + sunG * sunVis;
                                valG = floorf(valG * 0.5f + 0.5f);
                                int iG = (int)valG;
                                if (iG < 0) iG = 0;
                                if (iG > 255) iG = 255;

                                /* Blue channel: read byte 0 of current pixel in sub-image 3 */
                                float valB = (float)(unsigned char)loB[x * 4 - 4] + sunB * sunVis;
                                valB = floorf(valB * 0.5f + 0.5f);
                                int iB = (int)valB;
                                if (iB < 0) iB = 0;
                                if (iB > 255) iB = 255;

                                /* Write ARGB pixel in-place into loResBase1 buffer */
                                loR[0] = 0xFF;         /* alpha */
                                loR[1] = (byte)iR;     /* red */
                                loR[2] = (byte)iG;     /* green */
                                loR[3] = (byte)iB;     /* blue */

                                hiResPtr += 2;
                                loR += 4;
                            }

                            /* Advance to next row (pixWidth pixels * 4 bytes each) */
                            loResPixelOfs += pixWidth * 4;
                        }
                    }

                    /* Generate the single combined image for DX9 */
                    Image_Generate2D(
                        ((GfxImage **)((byte *)s_world.lightmaps + grpOffset))[0],
                        loResBase1,
                        pixWidth, pixHeight, 0x15);  /* format 0x15 = ARGB8888 */

                } else {
                    /* DX7/other path: generate 4 separate sub-images.
                     * Slots 0-2: directional color data (4bpp, format ARGB8888).
                     * Slot 3: primary lightmap (1bpp, format LUMINANCE). */
                    int grpOffset = groupIdx * (int)sizeof(GfxLightmapArray);

                    for (int si = 0; si < 4; si++) {
                        ((GfxImage **)((byte *)s_world.lightmaps + grpOffset))[si] =
                            (GfxImage *)Image_Alloc(
                                va("*lightmap%i_%i", groupIdx, si), 2, 1, 4);

                        /* 4bpp sub-images → ARGB8888 (0x15), 1bpp → LUMINANCE (0x32) */
                        int format = (subImgBytesPerPixel[si] == 4) ? 0x15 : 0x32;

                        int imgW = subImgWidth[si] * grpWide;
                        int imgH = subImgHeight[si] * grpHigh;

                        Image_Generate2D(
                            ((GfxImage **)((byte *)s_world.lightmaps + grpOffset))[si],
                            imageBuffer[si],
                            imgW, imgH, format);
                    }
                }

                oldLmapBaseIndex += groupTileCount;
                groupIdx++;
            }
        }

        /* Store final lightmap count and free temp memory */
        s_world.lightmapCount = (origLmapCount > 0) ? (short)groupIdx : 0;
        Hunk_FreeTempMemory(imageBuffer[0]);
    }

    /* ================================================================
     * Phase 4: Load lightgrid colors (lump 3, 24 bytes each)
     * ================================================================ */
    R_PrintLoadProgress("lightgrid coefficients");
    {
        const byte *gridColorData;
        int gridColorCount;
        int lumpSize = R_ValidateLumpRaw(header, fileBase, load.fileSize,
                                         LUMP_OFS_GRIDCOLORS, 24,
                                         &gridColorCount, &gridColorData);

        s_world.lightGrid.colorCount = gridColorCount;
        s_world.lightGrid.colors = (GfxLightGridColors *)Hunk_AllocInternal(lumpSize);
        Com_Memcpy(s_world.lightGrid.colors, gridColorData, lumpSize);
    }

    /* ================================================================
     * Phase 5: Load lightgrid points (lump 2, 8 bytes each)
     * ================================================================ */
    R_PrintLoadProgress("lightgrid hash");
    {
        const byte *gridPointData;
        int gridPointCount;
        R_ValidateLumpRaw(header, fileBase, load.fileSize,
                          LUMP_OFS_GRIDPOINTS, 8,
                          &gridPointCount, &gridPointData);

        s_world.lightGrid.pointCount = gridPointCount;
        GfxLightGridPoint *pts = (GfxLightGridPoint *)Hunk_AllocInternal(gridPointCount * 8);
        s_world.lightGrid.points = pts;

        const GfxLightGridPoint *srcPts = (const GfxLightGridPoint *)gridPointData;
        for (i = 0; i < s_world.lightGrid.pointCount; i++) {
            pts[i].xyzHighBits = srcPts[i].xyzHighBits;
            pts[i].xyzLowBitsAndSunVisible = srcPts[i].xyzLowBitsAndSunVisible;
            pts[i].needsTrace = srcPts[i].needsTrace;
            pts[i].colorsIndex = srcPts[i].colorsIndex;
        }
    }

    /* ================================================================
     * Phase 6: Load surfaces
     * ================================================================ */
    R_PrintLoadProgress("surfaces");
    CALL_LOADER_EAX(R_LoadSurfaces, &load);

    /* ================================================================
     * Phase 7: Load cull groups
     * ================================================================ */
    R_PrintLoadProgress("cull groups");
    CALL_LOADER_EAX(R_LoadCullGroups, &load);

    /* ================================================================
     * Phase 8: Load cull group indices (lump 11, 4 bytes each)
     * ================================================================ */
    R_PrintLoadProgress("cull group indices");
    {
        const byte *cgIdxData;
        int cgIdxCount;
        R_ValidateLumpRaw(header, fileBase, load.fileSize,
                          LUMP_OFS_CULLGROUPIDX, 4,
                          &cgIdxCount, &cgIdxData);

        const int *srcIdx = (const int *)cgIdxData;
        int *dstIdx = (int *)Hunk_AllocInternal(cgIdxCount * 4);
        rgl.cullGroupIndices = dstIdx;

        for (i = 0; i < cgIdxCount; i++)
            dstIdx[i] = srcIdx[i];
    }

    /* ================================================================
     * Phase 9: Load portal vertices
     * ================================================================ */
    R_PrintLoadProgress("portal vertices");
    CALL_LOADER_EAX(R_LoadPortalVerts, &load);

    /* ================================================================
     * Phase 10: Load occluders
     * ================================================================ */
    R_PrintLoadProgress("occluders");
    {
        /* Check if occluder lump exists before calling the ASM loader,
           which has an inline validation that fatally errors on empty lumps. */
        int occLumpSize = *(int *)(header + LUMP_OFS_OCCLUDERS);
        if (occLumpSize > 0)
            CALL_LOADER_EAX(R_LoadOccluders, &load);
    }

    /* ================================================================
     * Phase 11: Load occluder indices (lump 21, 2 bytes each)
     * ================================================================ */
    R_PrintLoadProgress("occluder indices");
    {
        const byte *occIdxData;
        int occIdxCount;
        R_ValidateLumpRaw(header, fileBase, load.fileSize,
                          LUMP_OFS_OCCLUDERIDX, 2,
                          &occIdxCount, &occIdxData);

        const short *srcOcc = (const short *)occIdxData;
        GfxOccluder **dstOcc = (GfxOccluder **)Hunk_AllocInternal(occIdxCount * 4);
        rgl.occluderIndices = dstOcc;

        for (i = 0; i < occIdxCount; i++) {
            int idx = (int)(signed short)srcOcc[i];
            /* Each GfxOccluder is 36 bytes: base + idx * 36 */
            dstOcc[i] = (GfxOccluder *)((byte *)rgl.occluders + idx * 36);
        }
    }

    /* ================================================================
     * Phase 12: Load AABB trees
     * ================================================================ */
    R_PrintLoadProgress("AABB trees");
    CALL_LOADER_EAX(R_LoadAabbTrees, &load);

    /* ================================================================
     * Phase 13: Load cells
     * ================================================================ */
    R_PrintLoadProgress("cells");
    CALL_LOADER_EAX(R_LoadCells, &load);

    /* ================================================================
     * Phase 14: Load portals
     * ================================================================ */
    R_PrintLoadProgress("portals");
    CALL_LOADER_EAX(R_LoadPortals, &load);

    /* ================================================================
     * Phase 15: Load nodes and leafs
     * ================================================================ */
    R_PrintLoadProgress("nodes and leafs");
    CALL_LOADER_EAX(R_LoadNodesAndLeafs, &load);

    /* ================================================================
     * Phase 16: Load submodels (lump 35, 48 bytes each)
     * ================================================================ */
    R_PrintLoadProgress("submodels");
    {
        const byte *modelData;
        R_ValidateLumpRaw(header, fileBase, load.fileSize,
                          LUMP_OFS_SUBMODELS, 48,
                          &modelCount, &modelData);

        const dmodel_t *inModels = (const dmodel_t *)modelData;
        GfxBrushModel *outModels = (GfxBrushModel *)Hunk_AllocInternal(modelCount * sizeof(GfxBrushModel));
        s_world.models = outModels;
        s_world.modelCount = modelCount;

        for (i = 0; i < modelCount; i++) {
            /* Copy bounds: mins and maxs */
            for (j = 0; j < 3; j++) {
                outModels[i].bounds[0][j] = inModels[i].mins[j];
                outModels[i].bounds[1][j] = inModels[i].maxs[j];
            }

            /* surfaceCount comes from numTriangles field (offset 28 in dmodel_t) */
            outModels[i].surfaceCount = inModels[i].numTriangles;

            /* startSurfIndex: if there are surfaces, use firstTriangle; otherwise -1 */
            if (inModels[i].numTriangles != 0)
                outModels[i].startSurfIndex = inModels[i].firstTriangle;
            else
                outModels[i].startSurfIndex = -1;
        }
    }

    /* ================================================================
     * Phase 17: Load entities
     * ================================================================ */
    R_PrintLoadProgress("entities");
    {
        extern snd_alias_list_t R_LoadEntities_stub(void);
        R_LoadEntities_stub();
    }

    /* ================================================================
     * Phase 18: Final cleanup and sun/outdoor setup
     * ================================================================ */

    /* Clear rgl again */
    memset(&rgl, 0, 6 * 4);

    /* Sun and outdoor setup — these are binary ASM functions */
    R_LoadSun(name, &s_world.sun);
    R_RegisterOutdoorImage(&s_world);

    return &s_world;
}
