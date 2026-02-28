/* Decompiled from: cm_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_load_obj.cpp */

#include "common_types.h"
#include "imports.h"
/* sqrtf declaration for radius computation */
extern float sqrtf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

/* cml is a static block; the BSS has 124 bytes at cml.
 * Only the first 12 bytes are used in this file:
 *   offset 0: numPlanes (int)
 *   offset 4: planes (cplane_t *)
 *   offset 8: bsp base pointer (void *)
 */
typedef struct cml_s {
    int numPlanes;
    cplane_t *planes;
    void *base;
    char _pad[124 - 12];
} cml_t;

static cml_t cml; /* cml */

/* Global clipMap_t pointer stored at imp_cm */
extern clipMap_t cm;
#define cm_ptr (*(clipMap_t **)&cm)

/* Forward declarations */
void CM_Cleanup(void);
cplane_t *CM_GetPlaneNum(int planeNum);
void CMod_LoadPlanes(const byte *base, const lump_t *l);
static cLeafBrushNode_t *CMod_PartionLeafBrushes_r(unsigned short *leafBrushes, int numLeafBrushes, const vec_t *mins, const vec_t *maxs);
static void CMod_PartionLeafBrushes(unsigned short *leafBrushes, int numLeafBrushes, cLeaf_t *leaf);
void CM_LoadMapFromBsp(const char *name, int usePvs);

/* Extern function declarations */
extern void *CM_Hunk_Alloc(int size, const char *name, int type);
extern void CM_Hunk_CheckTempMemoryClear(void);
extern void CM_Hunk_CheckTempMemoryHighClear(void);
extern void *CM_Hunk_AllocateTempMemoryHigh(int size, const char *name);
extern void CM_Hunk_ClearTempMemory(void);
extern void CM_Hunk_ClearTempMemoryHigh(void);
extern char *TempMalloc(int len);
extern void TempMemoryReset(void);
extern const dheader_t *Com_GetBsp(int *fileSize, unsigned int *checksum);
extern void Com_Error(errorParm_t code, const char *fmt, ...);
extern void Com_Memset(void *dest, int val, int count);
extern void Com_Memcpy(void *dest, const void *src, int count);

/* line 1318 */
void CM_Cleanup(void)
{
    cml.base = (void *)0;
}

/* line 1329 */
cplane_t *CM_GetPlaneNum(int planeNum)
{
    return cml.planes + planeNum;
}

/* line 772 */
void CMod_LoadPlanes(const byte *base, const lump_t *l)
{
    int i, j;
    int count;
    const byte *in;
    cplane_t *out;
    byte bits;

    in = base + l->fileofs;

    if (l->filelen & 0xf) {
        Com_Error(ERR_DROP, "CMod_LoadPlanes: funny lump size");
    }

    count = l->filelen >> 4;

    if (count <= 0) {
        Com_Error(ERR_DROP, "CMod_LoadPlanes: map has no planes");
    }

    out = (cplane_t *)CM_Hunk_Alloc(count * sizeof(cplane_t), "CMod_LoadPlanes", 0x17);
    cml.planes = out;
    cml.numPlanes = count;

    for (i = 0; i < count; i++) {
        bits = 0;
        for (j = 0; j < 3; j++) {
            out->normal[j] = *(const float *)(in + j * 4);
            if (0.0f > out->normal[j]) {
                bits |= (1 << j);
            }
        }
        out->dist = *(const float *)(in + 12);

        if (out->normal[0] == 1.0f) {
            out->type = 0;
        } else if (out->normal[1] == 1.0f) {
            out->type = 1;
        } else {
            byte t = (out->normal[2] != 1.0f) | ((*(unsigned int *)&out->normal[2] ^ 0x3f800000) ? 1 : 0);
            /* Simplified: if normal[2] == 1.0f, type = 2; else type = 3 */
            if (out->normal[2] == 1.0f) {
                out->type = 2;
            } else {
                out->type = 3;
            }
        }

        out->signbits = bits;
        in += 16;
        out++;
    }
}

/* Branchless min-like helper matching assembly's cmpltss / andps / andnps / orps pattern.
 * Computes: if (a - b < 0) return a; else return b; */
static float _branchless_select(float a, float b)
{
    return (a - b) < 0.0f ? a : b;
}

/* line 218 */
static cLeafBrushNode_t *CMod_PartionLeafBrushes_r(unsigned short *leafBrushes, int numLeafBrushes, const vec_t *mins, const vec_t *maxs)
{
    cLeafBrushNode_t *node;
    cbrush_t *brushesBase;
    int bestAxis;
    float bestDist;
    float bestScore;
    int axisLoop;
    int k;
    const vec_t *curMaxs;

    /* Allocate a new node via temp memory */
    node = (cLeafBrushNode_t *)TempMalloc(sizeof(cLeafBrushNode_t));
    node->axis = 0;
    node->contents = 0;
    node->data.children.range = 0;
    node->data.children.childOffset[0] = 0;
    node->data.children.childOffset[1] = 0;
    *(float *)&node->data = -3.4028234663852886e+38f;

    brushesBase = cm_ptr->brushes;
    curMaxs = maxs;

    bestAxis = -1;
    bestDist = 0.0f;
    bestScore = 0.0f;

    /* Try each axis (0,1,2) to find the best split plane */
    for (axisLoop = 0; axisLoop < 3; axisLoop++) {
        int k;

        for (k = 0; k < numLeafBrushes; k++) {
            cbrush_t *brush_k = brushesBase + leafBrushes[k];
            float pivot;
            float splitMax, splitMin;
            int countAbove, countBelow;
            float mid, score;
            int jj;

            /* First try using this brush's min on the current axis as pivot */
            pivot = ((float *)&brush_k->mins)[axisLoop];
            countAbove = -1;
            countBelow = -1;
            splitMax = -3.4028234663852886e+38f;
            splitMin = 3.4028234663852886e+38f;

            for (jj = 0; jj < numLeafBrushes; jj++) {
                cbrush_t *brush_j = brushesBase + leafBrushes[jj];
                float bmin = ((float *)&brush_j->mins)[axisLoop];

                if (bmin >= pivot) {
                    countAbove++;
                    if (bmin < splitMin)
                        splitMin = bmin;
                } else {
                    float bmax = ((float *)&brush_j->maxs)[axisLoop];
                    if (bmax >= pivot) {
                        countBelow++;
                        if (bmax > splitMax)
                            splitMax = bmax;
                    }
                }
            }

            if (countAbove >= countBelow)
                countAbove = countBelow;

            mid = (splitMax + splitMin) * 0.5f;

            if (countAbove > 0) {
                float rangeHigh = curMaxs[0] - splitMax;
                float rangeLow = splitMin - mins[axisLoop];
                score = _branchless_select(rangeHigh, rangeLow);
                score *= (float)countAbove;
            } else {
                score = 0.0f;
            }

            if (score > bestScore) {
                bestScore = score;
                bestAxis = axisLoop;
                bestDist = mid;
            }

            /* Now try using this brush's max on the current axis as pivot */
            pivot = ((float *)&brush_k->maxs)[axisLoop];
            countAbove = -1;
            countBelow = -1;
            splitMax = -3.4028234663852886e+38f;
            splitMin = 3.4028234663852886e+38f;

            for (jj = 0; jj < numLeafBrushes; jj++) {
                cbrush_t *brush_j = brushesBase + leafBrushes[jj];
                float bmin = ((float *)&brush_j->mins)[axisLoop];

                if (bmin >= pivot) {
                    countAbove++;
                    if (bmin < splitMin)
                        splitMin = bmin;
                } else {
                    float bmax = ((float *)&brush_j->maxs)[axisLoop];
                    if (bmax >= pivot) {
                        countBelow++;
                        if (bmax > splitMax)
                            splitMax = bmax;
                    }
                }
            }

            if (countAbove >= countBelow)
                countAbove = countBelow;

            mid = (splitMax + splitMin) * 0.5f;

            if (countAbove > 0) {
                float rangeHigh = curMaxs[0] - splitMax;
                float rangeLow = splitMin - mins[axisLoop];
                score = _branchless_select(rangeHigh, rangeLow);
                score *= (float)countAbove;
            } else {
                score = 0.0f;
            }

            if (score > bestScore) {
                bestScore = score;
                bestAxis = axisLoop;
                bestDist = mid;
            }
        }

        curMaxs++;
    }

    if (bestAxis < 0) {
        /* Leaf node -- no good split found */
        node->leafBrushCount = (short)numLeafBrushes;
        if ((int)(short)numLeafBrushes != numLeafBrushes) {
            Com_Error(ERR_DROP, "CMod_PartionLeafBrushes_r: numLeafBrushes overflows a short");
        }

        if (numLeafBrushes > 0) {
            int contents = 0;
            for (k = 0; k < numLeafBrushes; k++) {
                cbrush_t *b = brushesBase + leafBrushes[k];
                contents |= b->contents;
            }
            node->contents = contents;
        }

        node->data.leaf.brushes = leafBrushes;
        return node;
    }

    /* Internal node -- partition the brushes */
    {
        unsigned short *leafBrushesCopy;
        int numChild;
        int sideIdx;
        int m;

        leafBrushesCopy = (unsigned short *)CM_Hunk_AllocateTempMemoryHigh(numLeafBrushes * 2, "CMod_PartionLeafBrushes_r");
        memcpy(leafBrushesCopy, leafBrushes, numLeafBrushes * 2);

        /* First pass: collect brushes that straddle the split plane */
        numChild = 0;
        for (m = 0; m < numLeafBrushes; m++) {
            unsigned short brushIdx = leafBrushesCopy[m];
            cbrush_t *b = brushesBase + brushIdx;
            float bmin = ((float *)&b->mins)[bestAxis];
            float bmax = ((float *)&b->maxs)[bestAxis];

            if (bmin < bestDist && bestDist < bmax) {
                leafBrushes[numChild] = brushIdx;
                numChild++;
            }
        }

        if (numChild > 0) {
            /* Recursively partition the straddling brushes */
            cLeafBrushNode_t *stradChild = CMod_PartionLeafBrushes_r(leafBrushes, numChild, mins, maxs);
            node->leafBrushCount = (short)0xFFFF;
            node->contents = stradChild->contents;
            leafBrushes += numChild;
        }

        /* Set up node axis and dist */
        node->axis = (byte)bestAxis;
        node->data.children.dist = bestDist;

        {
            float tolerance = 3.4028234663852886e+38f;

            for (sideIdx = 0; sideIdx < 2; sideIdx++) {
                vec3_t childMins, childMaxs;
                cLeafBrushNode_t *childNode;
                int childOffset, encoded;
                int numChildBrushes = 0;
                int numChildSaved;

                if (sideIdx == 0) {
                    /* Left child: brushes with min[axis] <= dist (below the split) */
                    for (m = 0; m < numLeafBrushes; m++) {
                        unsigned short brushIdx = leafBrushesCopy[m];
                        cbrush_t *b = brushesBase + brushIdx;
                        float bmin = ((float *)&b->mins)[bestAxis];

                        if (bmin >= bestDist) {
                            continue;
                        }
                        {
                            float diff = bestDist - bmin;
                            float ddiff = diff - tolerance;
                            if (!(ddiff < 0.0f)) {
                                /* tolerance stays or grows */
                            } else {
                                tolerance = diff;
                            }
                        }
                        leafBrushes[numChildBrushes] = brushIdx;
                        numChildBrushes++;
                    }
                } else {
                    /* Right child: brushes with max[axis] >= dist (above the split) */
                    tolerance = 3.4028234663852886e+38f;
                    for (m = 0; m < numLeafBrushes; m++) {
                        unsigned short brushIdx = leafBrushesCopy[m];
                        cbrush_t *b = brushesBase + brushIdx;
                        float bval = ((float *)&b->mins)[bestAxis];
                        float bmax_val;

                        /* For right side, check if brush max >= dist */
                        /* The assembly uses a different pattern for side 1 vs side 0 */
                        bmax_val = ((float *)&b->maxs)[bestAxis];
                        if (bmax_val <= bestDist) {
                            continue;
                        }
                        {
                            float diff = bval - bestDist;
                            float test = diff - tolerance;
                            if (test >= 0.0f) {
                                /* diff is ok, no update needed */
                            } else {
                                tolerance = diff;
                            }
                        }
                        leafBrushes[numChildBrushes] = brushIdx;
                        numChildBrushes++;
                    }
                }

                numChildSaved = numChildBrushes;

                /* Set up child bounds */
                childMins[0] = mins[0];
                childMins[1] = mins[1];
                childMins[2] = mins[2];
                childMaxs[0] = maxs[0];
                childMaxs[1] = maxs[1];
                childMaxs[2] = maxs[2];

                if (sideIdx == 0) {
                    childMins[bestAxis] = bestDist + tolerance;
                } else {
                    childMaxs[bestAxis] = bestDist - tolerance;
                }

                /* Recurse */
                childNode = CMod_PartionLeafBrushes_r(leafBrushes, numChildBrushes, childMins, childMaxs);

                /* Encode child offset as a 16-bit value */
                childOffset = (int)(childNode - node);
                /* The assembly does: x = offset; t = x*3; t += t<<4; t += t<<8; t += t<<16; encoded = x + t*4
                 * This is equivalent to: encoded = offset * 0x33333334 / 4 ... actually it's just:
                 * t = x * 3 * (1 + 16) * (1 + 256) * (1 + 65536) * 4 + x = x * (1 + 12 * 17 * 257 * 65537)
                 * Actually: x*3 = 3x; 3x + 3x*16 = 3x*17 = 51x; 51x + 51x*256 = 51x*257 = 13107x;
                 * 13107x + 13107x*65536 = 13107x*65537 = 858993459x; 858993459*4 = 3435973836; +x = 3435973837x
                 * Hmm, that's 0xCCCCCCCD * x which is the multiplication constant for dividing by 5.
                 * Actually it computes (childOffset - node) as a pointer difference / 4 (since cLeafBrushNode_t is
                 * not necessarily 4 bytes), then does encoding.
                 *
                 * Wait, the assembly does: (childNode - node) where node is cLeafBrushNode_t *.
                 * The subtraction gives byte offset, then sarl $2 divides by 4.
                 * Then the multiplication chain reconstructs a 16-bit packed value.
                 * Actually, the sarl $2 divides by 4 (sizeof(int)), and then the multiplication
                 * by 0xCCCCCCCD is dividing by 5, yielding offset / 20 (sizeof(cLeafBrushNode_t)).
                 *
                 * So: encoded = ((byte*)childNode - (byte*)node) / sizeof(cLeafBrushNode_t)
                 * which is just: childNode - node (C pointer arithmetic).
                 */
                encoded = (int)((byte *)childNode - (byte *)node);
                encoded >>= 2;
                {
                    int t = encoded * 3;
                    t = t + (t << 4);
                    t = t + (t << 8);
                    t = t + (t << 16);
                    encoded = encoded + t * 4;
                }
                node->data.children.childOffset[sideIdx] = (unsigned short)encoded;
                if ((int)(unsigned short)encoded != encoded) {
                    Com_Error(ERR_DROP, "CMod_PartionLeafBrushes_r: childOffset overflows a short");
                }

                /* Merge contents */
                node->contents |= childNode->contents;

                /* Advance leafBrushes pointer past the children we just processed */
                leafBrushes += numChildSaved;
            }

            node->data.children.range = tolerance;
        }
    }

    return node;
}

/* line 387 */
static void CMod_PartionLeafBrushes(unsigned short *leafBrushes, int numLeafBrushes, cLeaf_t *leaf)
{
    int k, j;
    vec3_t mins, maxs;
    cbrush_t *brushesBase;
    cLeafBrushNode_t *resultNode;

    if (numLeafBrushes == 0) {
        return;
    }

    /* Initialize bounds to extreme values */
    mins[0] = 3.4028234663852886e+38f;
    mins[1] = 3.4028234663852886e+38f;
    mins[2] = 3.4028234663852886e+38f;
    maxs[0] = -3.4028234663852886e+38f;
    maxs[1] = -3.4028234663852886e+38f;
    maxs[2] = -3.4028234663852886e+38f;

    if (numLeafBrushes > 0) {
        brushesBase = cm_ptr->brushes;
        for (k = 0; k < numLeafBrushes; k++) {
            cbrush_t *b = brushesBase + leafBrushes[k];
            /* The assembly iterates j from 1 to 3 and accesses -4(%eax + j*4) = (j-1)*4
             * where %edx points to brush data. This accesses brush mins[0..2] and maxs[0..2].
             * The brush layout is: mins[3], contents, maxs[3], ...
             * Access pattern: (%edx) for first float, then +4, +8 for mins
             * 0x10(%edx) for maxs[0], etc. */
            for (j = 0; j < 3; j++) {
                float bmin = ((float *)&b->mins)[j];
                float bmax = ((float *)&b->maxs)[j];
                if (bmin < mins[j]) {
                    mins[j] = bmin;
                }
                if (bmax > maxs[j]) {
                    maxs[j] = bmax;
                }
            }
        }
    }

    /* Copy bounds to leaf */
    leaf->mins[0] = mins[0];
    leaf->mins[1] = mins[1];
    leaf->mins[2] = mins[2];
    leaf->maxs[0] = maxs[0];
    leaf->maxs[1] = maxs[1];
    leaf->maxs[2] = maxs[2];

    /* Expand bounds by 0.125 */
    for (j = 0; j < 3; j++) {
        leaf->mins[j] -= 0.125f;
        leaf->maxs[j] += 0.125f;
    }

    CM_Hunk_CheckTempMemoryHighClear();

    resultNode = CMod_PartionLeafBrushes_r(leafBrushes, numLeafBrushes, mins, maxs);

    /* Convert node pointer to index relative to leafbrushNodes base */
    {
        int byteOffset = (int)((byte *)resultNode - (byte *)cm_ptr->leafbrushNodes);
        int dwordOffset = byteOffset >> 2;
        int t = dwordOffset * 3;
        t = t + (t << 4);
        t = t + (t << 8);
        t = t + (t << 16);
        leaf->leafBrushNode = dwordOffset + t * 4;
    }

    CM_Hunk_ClearTempMemoryHigh();
}

/* Helper: get terrain contents from collision aabb trees */
static int CM_GetLeafTerrainContents(cLeaf_t *leaf)
{
    int contents = 0;
    int count = leaf->collAabbCount;
    int k;
    clipMap_t *cmLocal = cm_ptr;

    if (count <= 0)
        return 0;

    {
        dmaterial_t *materials = cmLocal->materials;
        CollisionAabbTree *trees = cmLocal->aabbTrees + leaf->firstCollAabbIndex;

        for (k = 0; k < count; k++) {
            contents |= materials[trees[k].materialIndex].contentFlags;
        }
    }
    return contents;
}

/* line 1228 */
void CM_LoadMapFromBsp(const char *name, int usePvs)
{
    clipMap_t *cmLocal;
    const dheader_t *header;
    const byte *bspBase;
    int count;
    int i, j;
    byte usePvsFlag;

    cmLocal = cm_ptr;
    usePvsFlag = (byte)usePvs;

    /* Clear clipmap and cml */
    Com_Memset(cmLocal, 0, sizeof(clipMap_t));
    Com_Memset(&cml, 0, 12);

    /* Allocate and copy name */
    {
        int nameLen = strlen(name) + 1;
        cmLocal->name = (const char *)CM_Hunk_Alloc(nameLen, "CM_LoadMapFromBsp", 0x17);
        strcpy((char *)cmLocal->name, name);
    }

    /* Get BSP data */
    header = Com_GetBsp(NULL, &cmLocal->checksum);
    bspBase = (const byte *)header;
    cml.base = (void *)header;

    /* ===========================
     * CMod_LoadMaterials (lump 0)
     * =========================== */
    {
        const byte *in;
        int matLumpLen, matLumpOfs;

        /* lumps[0] at header offset 8: {filelen, fileofs} */
        matLumpOfs = header->lumps[0].fileofs;
        matLumpLen = header->lumps[0].filelen;
        in = bspBase + matLumpOfs;

        /* sizeof(dmaterial_t) = 72. Division uses magic mul by 0x38e38e39, shift right 4 */
        if (matLumpLen % 72 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadMaterials: funny lump size");
        }
        count = matLumpLen / 72;
        if (count <= 0) {
            Com_Error(ERR_DROP, "CMod_LoadMaterials: map has no materials");
        }

        /* Allocate materials with one extra slot at the beginning (indexed -1) */
        cmLocal->materials = (dmaterial_t *)CM_Hunk_Alloc(count * 72 + 72, "CMod_LoadMaterials", 0x17);
        cmLocal->materials = (dmaterial_t *)((byte *)cmLocal->materials + 72);
        cmLocal->numMaterials = count;

        Com_Memcpy(cmLocal->materials, (const void *)in, count * 72);
    }

    /* ===========================
     * CMod_LoadPlanes (lump 4)
     * =========================== */
    /* header offset 0x28 = lumps[4] */
    CMod_LoadPlanes(bspBase, &header->lumps[4]);

    usePvsFlag = (byte)usePvs; /* re-read since function call may clobber */

    /* ===========================
     * CMod_LoadBrushes + BrushSides (lumps 5,6)
     * =========================== */
    {
        /* Lump 6 (offset 0x38): brush definitions */
        /* Lump 5 (offset 0x30): brush sides */
        const byte *inBrush;
        const byte *inSides;
        int brushCount;
        int sideCount;
        int sideLumpLen;
        cbrush_t *outBrush;
        cbrushside_t *outSides;

        /* Brush lump: header->lumps[6] at offset 0x38 */
        inBrush = bspBase + header->lumps[6].fileofs;
        if (header->lumps[6].filelen & 3) {
            Com_Error(ERR_DROP, "CMod_LoadBrushes: funny lump size");
        }
        brushCount = header->lumps[6].filelen >> 2;

        /* Sides lump: header->lumps[5] at offset 0x30 */
        inSides = bspBase + header->lumps[5].fileofs;
        sideLumpLen = header->lumps[5].filelen;
        if (sideLumpLen & 7) {
            Com_Error(ERR_DROP, "CMod_LoadBrushes: funny lump size");
        }
        sideCount = sideLumpLen >> 3;
        if (sideCount - brushCount * 6 < 0) {
            Com_Error(ERR_DROP, "CMod_LoadBrushSides: too few sides");
        }

        /* Allocate brush sides */
        if (sideCount == 0) {
            outSides = (cbrushside_t *)0;
        } else {
            outSides = (cbrushside_t *)CM_Hunk_Alloc(sideCount * 8, "CMod_LoadBrushSides", 0x18);
        }
        cmLocal->brushsides = outSides;
        cmLocal->numBrushSides = sideCount;

        /* Allocate brushes: (brushCount * 3 + 3) * sizeof(cplane_t)
         * The asm: leal 3(%edx, %edx, 2), %eax = 3*brushCount + 3; shll $4 = *16
         * But cbrush_t is 48 bytes... Actually sizeof(cplane_t) is 20 bytes.
         * (brushCount*3 + 3) * 16 = total allocation.
         * Actually: brushCount * 3 + 3 = total items; each item is 16 bytes... but that's not cbrush_t(48).
         * Let me re-examine: leal 3(%edx, %edx, 2) = edx*3 + 3; shll $4 = *16.
         * So allocation = (brushCount*3 + 3) * 16 bytes.
         * But a cbrush_t is 48 bytes = 3*16. So this is (brushCount + 1) cbrush_t structs.
         * The +1 is for box_brush. */
        outBrush = (cbrush_t *)CM_Hunk_Alloc((brushCount * 3 + 3) * 16, "CMod_LoadBrushes", 0x18);
        cmLocal->brushes = outBrush;
        cmLocal->numBrushes = (unsigned short)brushCount;
        if ((int)(unsigned short)brushCount != brushCount) {
            Com_Error(ERR_DROP, "CMod_LoadBrushes: numBrushes overflows a short");
        }

        for (i = 0; i < brushCount; i++) {
            int numSides;
            int materialNum;
            int axialIdx, sideIdx;

            /* Each inBrush entry is 4 bytes: short numTotalSides, short materialNum */
            numSides = (int)*(const short *)inBrush - 6;
            outBrush->numsides = numSides;
            if (numSides < 0) {
                Com_Error(ERR_DROP, "CMod_LoadBrushes: bad numsides");
            }

            if (outBrush->numsides == 0) {
                outBrush->sides = (cbrushside_t *)0;
            } else {
                outBrush->sides = outSides;
            }

            /* Load 3 axial side pairs (6 axial sides, stored as 3 pairs of plane+material) */
            for (axialIdx = 0; axialIdx < 3; axialIdx++) {
                /* First side of this axial pair (sideIdx 0) */
                {
                    int planeNum = *(const int *)inSides;
                    /* Store planeNum as the axial plane reference in the brush
                     * outBrush byte layout: offset 0x00 = mins[0..2], 0x0C = contents, 0x10 = maxs[0..2] */
                    *(int *)((byte *)outBrush + axialIdx * 4) = planeNum;
                }
                for (sideIdx = 0; sideIdx < 2; sideIdx++) {
                    if (sideIdx > 0) {
                        int planeNum = *(const int *)inSides;
                        /* Store second axial plane in outBrush + 0x10 + axialIdx*4 */
                        *(int *)((byte *)outBrush + 0x10 + axialIdx * 4) = planeNum;
                    }

                    materialNum = *(const int *)(inSides + 4);
                    if (materialNum < 0 || materialNum >= cmLocal->numMaterials) {
                        Com_Error(ERR_DROP, "CMod_LoadBrushes: bad materialNum: %i", materialNum);
                    }

                    /* Store material in axialMaterialNum[sideIdx][axialIdx]
                     * axialMaterialNum is at offset 0x24 in cbrush_t (short[2][3])
                     * axialMaterialNum[sideIdx][axialIdx] offset = 0x24 + (sideIdx*3 + axialIdx)*2 */
                    outBrush->axialMaterialNum[sideIdx][axialIdx] = (short)materialNum;
                    if ((int)(short)materialNum != materialNum) {
                        Com_Error(ERR_DROP, "CMod_LoadBrushSides: materialNum overflows a short");
                    }

                    inSides += 8;
                }
            }

            /* Load extra (non-axial) brush sides */
            {
                int *outSideNumSides = (int *)((byte *)outBrush + 0x1C);  /* numsides field */
                for (j = 0; j < *outSideNumSides; j++) {
                    int planeNum = *(const int *)inSides;
                    outSides->plane = cml.planes + planeNum;
                    outSides->materialNum = *(const int *)(inSides + 4);
                    if (outSides->materialNum < 0 || outSides->materialNum >= cmLocal->numMaterials) {
                        Com_Error(ERR_DROP, "CMod_LoadBrushes: bad materialNum: %i", outSides->materialNum);
                    }
                    inSides += 8;
                    outSides++;
                }
            }

            /* Get brush content flags from material */
            materialNum = (int)((const short *)inBrush)[1];
            if (materialNum < 0 || materialNum >= cmLocal->numMaterials) {
                Com_Error(ERR_DROP, "CMod_LoadBrushes: bad materialNum: %i", materialNum);
            }
            outBrush->contents = cmLocal->materials[materialNum].contentFlags & 0xDFFFFFFB;

            outBrush++;
            inBrush += 4;
        }
    }

    /* ===========================
     * CMod_LoadLeafBrushes (lump 28)
     * header offsets: 0xE0 = lumps[27].filelen, 0xE4 = lumps[27].fileofs
     * =========================== */
    {
        const byte *in;
        unsigned short *out;

        in = bspBase + header->lumps[27].fileofs;
        if (header->lumps[27].filelen & 3) {
            Com_Error(ERR_DROP, "CMod_LoadLeafBrushes: funny lump size");
        }
        count = header->lumps[27].filelen >> 2;

        out = (unsigned short *)CM_Hunk_Alloc(count * 2 + 2, "CMod_LoadLeafBrushes", 0x18);
        cmLocal->leafbrushes = out;
        cmLocal->numLeafBrushes = count;

        for (i = 0; i < count; i++) {
            int val = *(const int *)in;
            *out = (unsigned short)val;
            if ((int)(unsigned short)val != val) {
                Com_Error(ERR_DROP, "CMod_LoadLeafBrushes: leaf brush overflows a short");
            }
            in += 4;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadCollisionAabbTrees (lump 34)
     * header offset: 0x118 = lumps[33].filelen, 0x11C = lumps[33].fileofs
     * =========================== */
    {
        const byte *in;
        CollisionAabbTree *out;

        in = bspBase + header->lumps[33].fileofs;
        if (header->lumps[33].filelen & 0x1f) {
            Com_Error(ERR_DROP, "CMod_LoadCollisionAabbTrees: funny lump size");
        }
        count = header->lumps[33].filelen >> 5;

        out = (CollisionAabbTree *)CM_Hunk_Alloc(count * 32, "CMod_LoadCollisionAabbTrees", 0x1a);
        cmLocal->aabbTrees = out;
        cmLocal->aabbTreeCount = count;

        for (i = 0; i < count; i++) {
            out[i].origin[0] = *(const float *)(in + 0);
            out[i].origin[1] = *(const float *)(in + 4);
            out[i].origin[2] = *(const float *)(in + 8);
            out[i].halfSize[0] = *(const float *)(in + 0xc);
            out[i].halfSize[1] = *(const float *)(in + 0x10);
            out[i].halfSize[2] = *(const float *)(in + 0x14);
            out[i].materialIndex = *(const unsigned short *)(in + 0x18);
            out[i].childCount = *(const unsigned short *)(in + 0x1a);
            out[i].u.firstChildIndex = *(const int *)(in + 0x1c);
            in += 0x20;
        }
    }

    /* ===========================
     * CMod_LoadLeafs (lump 26)
     * header offset: 0xD8 = lumps[26].filelen, 0xDC = lumps[26].fileofs
     * =========================== */
    {
        const lump_t *leafLump;
        const byte *in;
        cLeaf_t *out;
        int leafLumpLen;

        /* header offset 0xD8 = lumps[26] */
        leafLump = &header->lumps[26];

        in = bspBase + leafLump->fileofs;
        leafLumpLen = leafLump->filelen;

        /* sizeof leaf on disk = 36. Magic mul 0x38e38e39, shift right 3 => divide by 36 */
        if (leafLumpLen % 36 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadLeafs: funny lump size");
        }
        count = leafLumpLen / 36;
        if (count <= 0) {
            Com_Error(ERR_DROP, "CMod_LoadLeafs: map has no leafs");
        }

        /* sizeof(cLeaf_t) = 0x2C = 44. Alloc: count * (1 + 2*5) * 4 = count * 44
         * The asm: leal (%ecx, %ecx, 4), %eax; leal (%ecx, %eax, 2), %eax; shll $2
         * = count*5, count + count*10 = count*11, *4 = count*44 */
        out = (cLeaf_t *)CM_Hunk_Alloc(count * sizeof(cLeaf_t), "CMod_LoadLeafs", 0x17);
        cmLocal->leafs = out;
        cmLocal->numLeafs = count;

        for (i = 0; i < count; i++) {
            if (usePvsFlag) {
                int cluster = *(const int *)in;
                out->cluster = (short)cluster;
                if ((int)(short)cluster != cluster) {
                    Com_Error(ERR_DROP, "CMod_LoadLeafs: cluster overflows a short");
                }

                {
                    int fcaa = *(const int *)(in + 8);
                    out->firstCollAabbIndex = (unsigned short)fcaa;
                    if ((int)(unsigned short)fcaa != fcaa) {
                        Com_Error(ERR_DROP, "CMod_LoadLeafs: firstCollAabbIndex overflows an unsigned short");
                    }
                }

                {
                    int cac = *(const int *)(in + 0xc);
                    out->collAabbCount = (unsigned short)cac;
                    if ((int)(unsigned short)cac != cac) {
                        Com_Error(ERR_DROP, "CMod_LoadLeafs: collAabbCount overflows an unsigned short");
                    }
                }

                if (cluster >= cmLocal->numClusters) {
                    cmLocal->numClusters = cluster + 1;
                }
            } else {
                int fcaa = *(const int *)(in + 8);
                out->firstCollAabbIndex = (unsigned short)fcaa;
                if ((int)(unsigned short)fcaa != fcaa) {
                    Com_Error(ERR_DROP, "CMod_LoadLeafs: firstCollAabbIndex overflows an unsigned short");
                }

                int cac = *(const int *)(in + 0xc);
                out->collAabbCount = (unsigned short)cac;
                if ((int)(unsigned short)cac != cac) {
                    Com_Error(ERR_DROP, "CMod_LoadLeafs: collAabbCount overflows an unsigned short");
                }
            }

            in += 0x24;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadSubmodels (lump 36)
     * header offset: 0x120 = lumps[35].filelen, 0x124 = lumps[35].fileofs
     * Disk submodel size = 48 (0x30). Magic mul 0xaaaaaaab, shift 5 => /48
     * =========================== */
    {
        const byte *in;
        cmodel_t *out;
        int subLumpLen;

        in = bspBase + header->lumps[35].fileofs;
        subLumpLen = header->lumps[35].filelen;

        if (subLumpLen % 48 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadSubmodels: funny lump size");
        }
        count = subLumpLen / 48;
        if (count <= 0) {
            Com_Error(ERR_DROP, "CMod_LoadSubmodels: map has no submodels");
        }
        if (count > 1023) {
            Com_Error(ERR_DROP, "CMod_LoadSubmodels: too many submodels");
        }

        /* sizeof(cmodel_t) = 72 = 0x48. count * 72 */
        out = (cmodel_t *)CM_Hunk_Alloc(count * 72, "CMod_LoadSubmodels", 0x18);
        cmLocal->cmodels = out;
        cmLocal->numSubModels = count;

        for (i = 0; i < count; i++) {
            float extent[3];
            float absMin, absMax;

            for (j = 0; j < 3; j++) {
                float minVal = *(const float *)(in + j * 4) - 1.0f;
                float maxVal = *(const float *)(in + 12 + j * 4) + 1.0f;
                out[i].mins[j] = minVal;
                out[i].maxs[j] = maxVal;

                /* Compute extent for radius */
                absMin = minVal < 0.0f ? -minVal : minVal;
                absMax = maxVal < 0.0f ? -maxVal : maxVal;
                extent[j] = (absMin - absMax) < 0.0f ? absMin : absMax;
            }

            /* radius = length(extent) */
            out[i].radius = sqrtf(extent[0] * extent[0] + extent[1] * extent[1] + extent[2] * extent[2]);

            if (i > 0) {
                int numBrushes = *(const int *)(in + 0x24);
                out[i].leaf.collAabbCount = (unsigned short)numBrushes;
                if ((int)(unsigned short)numBrushes != numBrushes) {
                    Com_Error(ERR_DROP, "CMod_LoadSubmodels: collAabbCount overflows a short");
                }

                int firstBrush = *(const int *)(in + 0x20);
                out[i].leaf.firstCollAabbIndex = (unsigned short)firstBrush;
                if ((int)(unsigned short)firstBrush != firstBrush) {
                    Com_Error(ERR_DROP, "CMod_LoadSubmodels: firstCollAabbIndex overflows a short");
                }
            }

            in += 0x30;
        }
    }

    /* ===========================
     * Post-submodel initialization
     * =========================== */
    CM_Hunk_CheckTempMemoryClear();
    TempMemoryReset();
    TempMalloc(0);

    /* Set up leafbrushNodes base pointer:
     * The asm subtracts 0x14 (sizeof cLeafBrushNode_t) from the TempMalloc(0) result
     * and stores it as the leafbrushNodes pointer. */
    {
        cLeafBrushNode_t *tempBase = (cLeafBrushNode_t *)((byte *)TempMalloc(0) - sizeof(cLeafBrushNode_t));
        /* Wait, TempMalloc(0) was already called above. Let me re-read the asm. */
        /* "calll TempMalloc\n"  -- returns current temp pointer
         * "subl $0x14, %eax\n"  -- subtract sizeof(cLeafBrushNode_t)
         * "movl %eax, 0x30(%edx)\n"  -- store as cmLocal->leafbrushNodes */
        /* Actually TempMalloc(0) was already called and returned. Then we subtract 0x14. */
        cmLocal->leafbrushNodes = (cLeafBrushNode_t *)((byte *)tempBase);
    }

    /* ===========================
     * Build leaf brush nodes for each leaf
     * header->lumps[26] was stored in a local
     * =========================== */
    {
        const lump_t *leafDataLump = &header->lumps[26];
        const byte *leafIn;
        cLeaf_t *leaf;
        int numLeafs;

        leafIn = bspBase + leafDataLump->fileofs;
        leaf = cmLocal->leafs;
        numLeafs = cmLocal->numLeafs;

        for (i = 0; i < numLeafs; i++) {
            int numLeafBrushes;
            int indexFirstLeafBrush;
            int brushContents = 0;
            int terrainContents = 0;

            numLeafBrushes = *(const int *)(leafIn + 0x14);
            indexFirstLeafBrush = *(const int *)(leafIn + 0x10);

            /* Compute brush contents */
            if (numLeafBrushes > 0) {
                unsigned short *lb = cmLocal->leafbrushes + indexFirstLeafBrush;
                cbrush_t *brushes = cmLocal->brushes;

                for (j = 0; j < numLeafBrushes; j++) {
                    cbrush_t *b = brushes + lb[j];
                    brushContents |= b->contents;
                }
            }
            leaf->brushContents = brushContents;

            /* Compute terrain contents from collision aabb trees */
            {
                int collCount = leaf->collAabbCount;
                if (collCount > 0) {
                    dmaterial_t *materials = cmLocal->materials;
                    CollisionAabbTree *trees = cmLocal->aabbTrees + leaf->firstCollAabbIndex;

                    for (j = 0; j < collCount; j++) {
                        terrainContents |= materials[trees[j].materialIndex].contentFlags;
                    }
                }
            }
            leaf->terrainContents = terrainContents;

            /* Partition leaf brushes */
            CMod_PartionLeafBrushes(cmLocal->leafbrushes + indexFirstLeafBrush, numLeafBrushes, leaf);

            leafIn += 0x24;
            leaf++;

            /* Refresh cmLocal pointer */
            cmLocal = cm_ptr;
        }
    }

    /* ===========================
     * Build submodel brush nodes
     * =========================== */
    {
        const lump_t *submodelLump = &header->lumps[35];
        const byte *submodelIn;
        int numSubModels;

        submodelIn = bspBase + submodelLump->fileofs;
        numSubModels = cmLocal->numSubModels;

        for (i = 1; i < numSubModels; i++) {
            cmodel_t *cmod;
            int numBrushes;
            int firstBrush;
            unsigned short *indexes;
            int contents;
            cLeaf_t *subLeaf;
            int terrainContents;

            cmod = cmLocal->cmodels + i;
            numBrushes = *(const int *)(submodelIn + i * 0x30 + 0x5C - 0x30);

            /* Actually, let me be more careful. The asm says:
             * movl 0x5c + submodelIn_offset ... for the first submodel data.
             * After lump offset, the submodelIn points to the start of the data.
             * The iteration starts at i=1. The field "numBrushes" is at offset 0x1C into each
             * disk submodel entry (0x30 bytes each).
             * So for submodel i: base + i*0x30 + firstBrush_offset
             *
             * From the asm at the call site:
             * movl -0x3c(%ebp), %ecx -> points to submodelIn + i*0x30 + 0x5C-0x30
             * Actually the asm is:
             * "addl $0x5c, %eax\n" -- starts at submodelIn + 0x5C (first submodel, offset 0x2C into the disk data? )
             * This is offset relative to the base of the lump data.
             * "movl (%ecx), %ecx\n" -- reads numBrushes
             * Index 0x5C - 0x30 = 0x2C, then each step adds 0x30.
             * Actually first iteration: base + fileofs + 0x5C. That's the second submodel (i=1) at offset 0x5C = 0x30 + 0x2C.
             * So 0x2C into the 0x30-byte structure is the "numBrushes" field of the disk submodel.
             * Which matches: dmodel_t at offset 0x2C = numBrushes (firstBrush=0x20, numBrushes=0x24... let me check).
             * dmodel_t: mins[3]=12, maxs[3]=12, firstTriangle=4, numTriangles=4, firstSurface=4, numSurfaces=4, firstBrush=4, numBrushes=4 = 48 total.
             * Offsets: mins=0, maxs=12, firstTri=24, numTri=28, firstSurf=32, numSurf=36, firstBrush=40(0x28), numBrushes=44(0x2C). YES!
             */
            numBrushes = *(const int *)(submodelIn + i * 0x30 + 0x2C); /* numBrushes */
            firstBrush = *(const int *)(submodelIn + i * 0x30 + 0x28); /* firstBrush */

            if (numBrushes <= 0) continue;

            /* Allocate indexes array for this submodel's brushes */
            indexes = (unsigned short *)CM_Hunk_Alloc(numBrushes * 2, "CMod_LoadSubmodelBrushNodes", 0x18);

            /* Fill indexes and compute contents */
            {
                int brushContents = 0;
                for (j = 0; j < numBrushes; j++) {
                    int brushIdx = firstBrush + j;
                    indexes[j] = (unsigned short)brushIdx;
                    if ((int)(unsigned short)brushIdx != brushIdx) {
                        Com_Error(ERR_DROP, "CMod_LoadSubmodelBrushNodes: brush index overflows a short");
                    }
                    brushContents |= cmLocal->brushes[brushIdx].contents;
                }
                cmod->leaf.brushContents = brushContents;
            }

            /* Compute terrain contents for submodel leaf */
            subLeaf = &cmod->leaf;
            {
                int collCount = subLeaf->collAabbCount;
                terrainContents = 0;
                if (collCount > 0) {
                    dmaterial_t *materials = cmLocal->materials;
                    CollisionAabbTree *trees = cmLocal->aabbTrees + subLeaf->firstCollAabbIndex;

                    for (j = 0; j < collCount; j++) {
                        terrainContents |= materials[trees[j].materialIndex].contentFlags;
                    }
                }
            }
            cmod->leaf.terrainContents = terrainContents;

            /* Partition submodel leaf brushes */
            CMod_PartionLeafBrushes(indexes, numBrushes, subLeaf);

            cmLocal = cm_ptr;
        }
    }

    /* ===========================
     * Set up box_brush and box_model
     * =========================== */
    {
        cbrush_t *box_brush;

        /* box_brush is located right after the last regular brush */
        box_brush = cmLocal->brushes + cmLocal->numBrushes;
        cmLocal->box_brush = box_brush;
        box_brush->numsides = 0;
        box_brush->sides = (cbrushside_t *)0;
        box_brush->contents = -1;

        /* Initialize box_model with cleared values */
        cmLocal->box_model.leaf.leafBrushNode = -1;
        cmLocal->box_model.leaf.brushContents = 0;
        cmLocal->box_model.leaf.mins[0] = 3.4028234663852886e+38f;
        cmLocal->box_model.leaf.mins[1] = 3.4028234663852886e+38f;
        cmLocal->box_model.leaf.mins[2] = 3.4028234663852886e+38f;
        cmLocal->box_model.leaf.maxs[0] = -3.4028234663852886e+38f;
        cmLocal->box_model.leaf.maxs[1] = -3.4028234663852886e+38f;
        cmLocal->box_model.leaf.maxs[2] = -3.4028234663852886e+38f;

        /* Set collision AABB indices on box_brush to 0xFFFF */
        box_brush->axialMaterialNum[0][0] = (short)0xFFFF;
        box_brush->axialMaterialNum[0][1] = (short)0xFFFF;
        box_brush->axialMaterialNum[0][2] = (short)0xFFFF;
        box_brush->axialMaterialNum[1][0] = (short)0xFFFF;
        box_brush->axialMaterialNum[1][1] = (short)0xFFFF;
        box_brush->axialMaterialNum[1][2] = (short)0xFFFF;
    }

    /* Allocate a cLeafBrushNode_t for the box */
    {
        cLeafBrushNode_t *boxNode;
        int boxNodeIndex;

        boxNode = (cLeafBrushNode_t *)TempMalloc(sizeof(cLeafBrushNode_t));
        boxNode->axis = 0;
        boxNode->contents = 0;
        boxNode->data.children.range = 0;
        boxNode->data.children.childOffset[0] = 0;
        boxNode->data.children.childOffset[1] = 0;
        /* Store -FLT_MAX into data.children.dist (the float at offset 8 in the node) */
        *(float *)&boxNode->data = -3.4028234663852886e+38f;

        /* Compute box node index */
        {
            int byteOffset = (int)((byte *)boxNode - (byte *)cmLocal->leafbrushNodes);
            int dwordOffset = byteOffset >> 2;
            int t = dwordOffset * 3;
            t = t + (t << 4);
            t = t + (t << 8);
            t = t + (t << 16);
            cmLocal->box_model.leaf.leafBrushNode = dwordOffset + t * 4;
        }

        /* Set leafBrushCount to 1 */
        boxNode->leafBrushCount = 1;

        /* Set leaf brushes pointer to the end of the leafbrushes array */
        boxNode->data.leaf.brushes = cmLocal->leafbrushes + cmLocal->numLeafBrushes;

        /* Write box brush index into the leafbrushes at the end */
        cmLocal->leafbrushes[cmLocal->numLeafBrushes] = cmLocal->numBrushes;
    }

    /* Finalize leafbrushNodes: copy temp memory into hunk */
    {
        cLeafBrushNode_t *tempNodes;
        int tempNodesByteSize;
        int nodeCount;

        /* Advance the temp node pointer */
        cmLocal->leafbrushNodes = (cLeafBrushNode_t *)((byte *)cmLocal->leafbrushNodes + sizeof(cLeafBrushNode_t));

        /* Get temp memory top to compute total nodes size */
        {
            byte *tempTop = (byte *)TempMalloc(0);
            int totalBytes = (int)(tempTop - (byte *)cmLocal->leafbrushNodes);
            int byteOffset = totalBytes >> 2;
            int t = byteOffset * 3;
            t = t + (t << 4);
            t = t + (t << 8);
            t = t + (t << 16);
            nodeCount = byteOffset + t * 4;
        }

        cmLocal->leafbrushNodesCount = nodeCount + 1;

        /* Allocate permanent hunk memory for leafbrushNodes */
        {
            cLeafBrushNode_t *permNodes;
            permNodes = (cLeafBrushNode_t *)CM_Hunk_Alloc((nodeCount + 1) * sizeof(cLeafBrushNode_t), "CMod_LoadBrushRelated", 0x18);

            /* Copy from offset sizeof(cLeafBrushNode_t) of permNodes (skip first entry) */
            {
                int copySize;
                int t2 = nodeCount;
                t2 = t2 * 5;
                copySize = t2 * 4; /* nodeCount * sizeof(cLeafBrushNode_t) */

                memcpy((byte *)permNodes + sizeof(cLeafBrushNode_t), cmLocal->leafbrushNodes, copySize);
            }
            cmLocal->leafbrushNodes = permNodes;
        }

        CM_Hunk_ClearTempMemory();
    }

    /* ===========================
     * CMod_LoadNodes (lump 25)
     * header offset: 0xD0 = lumps[25].filelen, 0xD4 = lumps[25].fileofs
     * Disk node size = 36. Magic 0x38e38e39 / shift 3 => /36
     * =========================== */
    {
        const byte *in;
        cNode_t *out;
        int nodeLumpLen;

        in = bspBase + header->lumps[25].fileofs;
        nodeLumpLen = header->lumps[25].filelen;

        if (nodeLumpLen % 36 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadNodes: funny lump size");
        }
        count = nodeLumpLen / 36;
        if (count <= 0) {
            Com_Error(ERR_DROP, "CMod_LoadNodes: map has no nodes");
        }

        out = (cNode_t *)CM_Hunk_Alloc(count * sizeof(cNode_t), "CMod_LoadNodes", 0x17);
        cmLocal->nodes = out;
        cmLocal->numNodes = count;

        for (i = 0; i < count; i++) {
            int planeNum = *(const int *)in;
            out->plane = cml.planes + planeNum;

            for (j = 0; j < 2; j++) {
                int child = *(const int *)(in + 4 + j * 4);
                out->children[j] = (short)child;
                if ((int)(short)child != child) {
                    Com_Error(ERR_DROP, "CMod_LoadNodes: child overflows a short");
                }
            }

            in += 0x24;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadLeafSurfaces (lump 29)
     * header offset: 0xE8 = lumps[28].filelen, 0xEC = lumps[28].fileofs
     * =========================== */
    {
        const byte *in;
        int *out;

        in = bspBase + header->lumps[28].fileofs;
        if (header->lumps[28].filelen & 3) {
            Com_Error(ERR_DROP, "CMod_LoadLeafSurfaces: funny lump size");
        }
        count = header->lumps[28].filelen >> 2;

        out = (int *)CM_Hunk_Alloc(count * 4, "CMod_LoadLeafSurfaces", 0x1a);
        cmLocal->leafsurfaces = out;
        cmLocal->numLeafSurfaces = count;

        for (i = 0; i < count; i++) {
            *out = *(const int *)in;
            in += 4;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadCollisionVerts (lump 30)
     * header offset: 0xF0 = lumps[29].filelen, 0xF4 = lumps[29].fileofs
     * Disk vertex size = 16. filelen >> 4
     * =========================== */
    {
        const byte *in;
        CollisionVertex *out;

        in = bspBase + header->lumps[29].fileofs;
        if (header->lumps[29].filelen & 0xf) {
            Com_Error(ERR_DROP, "CMod_LoadCollisionVerts: funny lump size");
        }
        count = header->lumps[29].filelen >> 4;

        /* CollisionVertex = {vec3_t xyz} = 12 bytes. Alloc count*12 */
        out = (CollisionVertex *)CM_Hunk_Alloc(count * 12, "CMod_LoadCollisionVerts", 0x1a);
        cmLocal->verts = out;
        cmLocal->vertCount = count;

        for (i = 0; i < count; i++) {
            out->xyz[0] = *(const float *)(in + 4);
            out->xyz[1] = *(const float *)(in + 8);
            out->xyz[2] = *(const float *)(in + 12);
            in += 16;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadCollisionEdges (lump 31)
     * header offset: 0xF8 = lumps[30].filelen, 0xFC = lumps[30].fileofs
     * Disk edge size = 56 (0x38). Division: shift right 3 then divide by 7 (magic 0x24924925).
     * Output edge size = 48 (0x30)
     * =========================== */
    {
        const byte *in;
        CollisionEdge *out;
        int edgeLumpLen;

        in = bspBase + header->lumps[30].fileofs;
        edgeLumpLen = header->lumps[30].filelen;

        /* Check: (len >> 3) * 56 == len, i.e. len % 56 == 0
         * The asm does: edx = len>>3; magic_mul 0x24924925; result * 56 == len? */
        if (edgeLumpLen % 56 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadCollisionEdges: funny lump size");
        }
        count = edgeLumpLen / 56;

        /* CollisionEdge = {vec3_t origin; vec3_t axis[3]} = 48 bytes */
        out = (CollisionEdge *)CM_Hunk_Alloc(count * 48, "CMod_LoadCollisionEdges", 0x1a);
        cmLocal->edges = out;
        cmLocal->edgeCount = count;

        for (i = 0; i < count; i++) {
            /* Copy 12 floats from disk (first 12 fields) */
            ((float *)out)[0] = *(const float *)(in + 4);
            ((float *)out)[1] = *(const float *)(in + 8);
            ((float *)out)[2] = *(const float *)(in + 0xc);
            ((float *)out)[3] = *(const float *)(in + 0x10);
            ((float *)out)[4] = *(const float *)(in + 0x14);
            ((float *)out)[5] = *(const float *)(in + 0x18);
            ((float *)out)[6] = *(const float *)(in + 0x1c);
            ((float *)out)[7] = *(const float *)(in + 0x20);
            ((float *)out)[8] = *(const float *)(in + 0x24);
            ((float *)out)[9] = *(const float *)(in + 0x28);
            ((float *)out)[10] = *(const float *)(in + 0x2c);
            ((float *)out)[11] = *(const float *)(in + 0x30);

            /* Normalize the last axis vector: divide axis[2] by length stored in in+0x34
             * The asm: 1.0f / *(float *)(in + 0x34), then multiply axis[2][0..2] */
            {
                float invLen = 1.0f / *(const float *)(in + 0x34);
                out->axis[2][0] *= invLen;
                out->axis[2][1] *= invLen;
                out->axis[2][2] *= invLen;
            }

            in += 0x38;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadCollisionTriangles (lump 32)
     * header offset: 0x100 = lumps[31].filelen, 0x104 = lumps[31].fileofs
     * Disk and output size = 72 (0x48). Magic 0x38e38e39, shift 4 => /72
     * =========================== */
    {
        const byte *in;
        CollisionTriangle *out;
        int triLumpLen;

        in = bspBase + header->lumps[31].fileofs;
        triLumpLen = header->lumps[31].filelen;

        if (triLumpLen % 72 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadCollisionTriangles: funny lump size");
        }
        count = triLumpLen / 72;

        out = (CollisionTriangle *)CM_Hunk_Alloc(count * 72, "CMod_LoadCollisionTriangles", 0x1a);
        cmLocal->tris = out;
        cmLocal->triCount = count;

        for (i = 0; i < count; i++) {
            /* Copy plane (vec4), svec (vec4), tvec (vec4) = 12 floats */
            ((float *)out)[0] = *(const float *)(in + 0);
            ((float *)out)[1] = *(const float *)(in + 4);
            ((float *)out)[2] = *(const float *)(in + 8);
            ((float *)out)[3] = *(const float *)(in + 0xc);
            ((float *)out)[4] = *(const float *)(in + 0x10);
            ((float *)out)[5] = *(const float *)(in + 0x14);
            ((float *)out)[6] = *(const float *)(in + 0x18);
            ((float *)out)[7] = *(const float *)(in + 0x1c);
            ((float *)out)[8] = *(const float *)(in + 0x20);
            ((float *)out)[9] = *(const float *)(in + 0x24);
            ((float *)out)[10] = *(const float *)(in + 0x28);
            ((float *)out)[11] = *(const float *)(in + 0x2c);

            /* Copy verts[3] and edges[3] with stride */
            for (j = 0; j < 3; j++) {
                out->edges[j] = *(const int *)(in + 0x3c + j * 4);
                out->verts[j] = *(const int *)(in + 0x30 + j * 4);
            }

            in += 0x48;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadCollisionBorders (lump 33)
     * header offset: 0x108 = lumps[32].filelen, 0x10C = lumps[32].fileofs
     * Disk and output size = 28 (0x1C). Magic 0x24924925 for /7 on dwords.
     * =========================== */
    {
        const byte *in;
        CollisionBorder *out;
        int borderLumpLen;

        in = bspBase + header->lumps[32].fileofs;
        borderLumpLen = header->lumps[32].filelen;

        /* Division: (len >> 2) / 7 using magic mul 0x24924925 */
        if (borderLumpLen % 28 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadCollisionBorders: funny lump size");
        }
        count = borderLumpLen / 28;

        /* CollisionBorder = 28 bytes */
        out = (CollisionBorder *)CM_Hunk_Alloc(count * 28, "CMod_LoadCollisionBorders", 0x1a);
        cmLocal->borders = out;
        cmLocal->borderCount = count;

        for (i = 0; i < count; i++) {
            ((float *)out)[0] = *(const float *)(in + 0);
            ((float *)out)[1] = *(const float *)(in + 4);
            ((float *)out)[2] = *(const float *)(in + 8);
            ((float *)out)[3] = *(const float *)(in + 0xc);
            ((float *)out)[4] = *(const float *)(in + 0x10);
            ((float *)out)[5] = *(const float *)(in + 0x14);
            ((float *)out)[6] = *(const float *)(in + 0x18);
            in += 0x1c;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadCollisionPartitions (lump 34)
     * header offset: 0x110 = lumps[33].filelen, 0x114 = lumps[33].fileofs
     * Wait, lump 33 was already used for aabb trees at 0x118/0x11C.
     * Let me recalculate: lumps[33] at offset 8 + 33*8 = 272 = 0x110.
     * But 0x118 = 8 + 34*8 = 280 which is lumps[34].
     *
     * Re-checking: lumps[N] is at header offset 8 + N*8.
     * lumps[0] = 0x08, lumps[1] = 0x10, ..., lumps[N] = 8 + 8N.
     * lumps[25] = 0xD0, lumps[26] = 0xD8, lumps[27] = 0xE0,
     * lumps[28] = 0xE8, lumps[29] = 0xF0, lumps[30] = 0xF8,
     * lumps[31] = 0x100, lumps[32] = 0x108, lumps[33] = 0x110,
     * lumps[34] = 0x118, lumps[35] = 0x120, lumps[36] = 0x128,
     * lumps[37] = 0x130.
     *
     * So collision partitions use 0x110/0x114 = lumps[33].
     * But aabb trees used 0x118/0x11C = lumps[34].
     * Let me re-examine: the original aabb trees code used header offsets 0x118 and 0x11C.
     * 0x118 = lumps[34].filelen, 0x11C = lumps[34].fileofs. Yes, lumps[34] for aabb trees.
     *
     * And partitions: 0x110 = lumps[33].filelen, 0x114 = lumps[33].fileofs.
     * Disk partition size = 12 (0xC). Magic 0xaaaaaaab / shift 3 => /12.
     */
    {
        const byte *in;
        CollisionPartition *out;
        int partLumpLen;

        in = bspBase + header->lumps[33].fileofs;
        partLumpLen = header->lumps[33].filelen;

        if (partLumpLen % 12 != 0) {
            Com_Error(ERR_DROP, "CMod_LoadCollisionPartitions: funny lump size");
        }
        count = partLumpLen / 12;

        /* CollisionPartition = 12 bytes */
        out = (CollisionPartition *)CM_Hunk_Alloc(count * 12, "CMod_LoadCollisionPartitions", 0x1a);
        cmLocal->partitions = out;
        cmLocal->partitionCount = count;

        for (i = 0; i < count; i++) {
            out->triCount = *(const byte *)(in + 2);
            out->borderCount = *(const byte *)(in + 3);
            {
                int triIndex = *(const int *)(in + 4);
                out->tris = cmLocal->tris + triIndex;
            }
            {
                int borderIndex = *(const int *)(in + 8);
                out->borders = cmLocal->borders + borderIndex;
            }
            in += 12;
            out++;
        }
    }

    /* ===========================
     * CMod_LoadVisibility (lump 36 = 0x128)
     * =========================== */
    if (usePvsFlag) {
        const lump_t *visLump = &header->lumps[36];

        if (visLump->filelen == 0) {
            /* No vis data -- generate default */
            int visSize = (cmLocal->numClusters + 31) & ~31;
            cmLocal->clusterBytes = visSize;

            cmLocal->visibility = (byte *)CM_Hunk_Alloc(visSize, "CMod_LoadVisibility", 9);
            Com_Memset(cmLocal->visibility, 0xFF, visSize);
        } else {
            const byte *buf = bspBase + visLump->fileofs;
            int visDataLen;

            cmLocal->vised = 1;
            cmLocal->numClusters = *(const int *)buf;
            cmLocal->clusterBytes = *(const int *)(buf + 4);

            visDataLen = visLump->filelen - 8;
            cmLocal->visibility = (byte *)CM_Hunk_Alloc(visDataLen, "CMod_LoadVisibility", 9);
            Com_Memcpy(cmLocal->visibility, buf + 8, visDataLen);
        }
    } else {
        if (header->lumps[36].filelen != 0) {
            Com_Error(ERR_DROP, "CMod_LoadVisibility: vis data present but usePvs is false");
        }
    }

    /* ===========================
     * CMod_LoadEntityString (lump 37 = 0x130)
     * =========================== */
    {
        int entLen = header->lumps[37].filelen;
        cmLocal->numEntityChars = entLen;

        cmLocal->entityString = (char *)CM_Hunk_Alloc(entLen, "CMod_LoadEntityString", 9);
        Com_Memcpy(cmLocal->entityString, bspBase + header->lumps[37].fileofs, entLen);
    }

    /* Clear BSP base */
    cml.base = (void *)0;
}
