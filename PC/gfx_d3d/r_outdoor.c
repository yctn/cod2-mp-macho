/* Converted to C from ASM: r_outdoor.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_outdoor.cpp */

#include "common_types.h"
#include "imports.h"

extern void **g_dxCaps;         /* 0x195eec0 */
extern void *Image_Register(const char *name, int trackType, int filter);
extern void ClearBounds(vec3_t mins, vec3_t maxs);
extern void ExpandBounds(vec3_t mins, vec3_t maxs, vec3_t boundsMin, vec3_t boundsMax);
extern void MatrixIdentity44(float *matrix);
extern void CM_BoxTrace(float *results, vec3_t start, vec3_t end,
                         vec3_t mins, vec3_t maxs, int brushmask, int capsule);
extern float floorf(float);
extern void Image_Generate2D(void *image, byte *data, int width, int height, int format);
extern void *Hunk_AllocateTempMemoryInternal(int size);
extern void Hunk_FreeTempMemory(void *buf);

static const int outdoorMapSize[3]; /* 0x2f30a0 */

static OutdoorGlob outdoorGlob; /* 0xce7180 */

void R_RegisterOutdoorImage(GfxWorld *world)
{
    byte *dxCaps = *(byte **)g_dxCaps;
    if (*(int *)(dxCaps + 8) == 2) {
        *(void **)((byte *)world + 0x200) = NULL;
        return;
    }

    ClearBounds(outdoorGlob.bbox[0], outdoorGlob.bbox[1]);

    int surfCount = *(int *)((byte *)world + 0x10);
    byte *surfData = *(byte **)((byte *)world + 0x14);

    int i;
    for (i = 0; i < surfCount; i++) {
        byte *surf = surfData + i * 12;
        byte *material = *(byte **)surf;

        if (*(byte *)(material + 0xc) & 8)
            continue;

        byte *bounds = *(byte **)(surf + 8);
        ExpandBounds((float *)(bounds + 4), (float *)(bounds + 0x10),
                     outdoorGlob.bbox[0], outdoorGlob.bbox[1]);
    }

    /* Ensure bounds have at least 1.0 extent */
    int axis;
    for (axis = 0; axis < 3; axis++) {
        if (outdoorGlob.bbox[0][axis] == 131072.0f) {
            outdoorGlob.bbox[0][axis] = 0.0f;
            outdoorGlob.bbox[1][axis] = 0.0f;
        }

        float extent = outdoorGlob.bbox[1][axis] - outdoorGlob.bbox[0][axis];
        if (extent < 1.0f) {
            outdoorGlob.bbox[0][axis] -= 0.5f;
            outdoorGlob.bbox[1][axis] += 0.5f;
        }
    }

    /* Compute scale, invScale, add for each axis */
    for (axis = 0; axis < 3; axis++) {
        float range = outdoorGlob.bbox[1][axis] - outdoorGlob.bbox[0][axis];
        float s = (float)(outdoorMapSize[axis] - 1) / range;
        outdoorGlob.scale[axis] = s;
        outdoorGlob.invScale[axis] = 1.0f / s;
        outdoorGlob.add[axis] = -outdoorGlob.bbox[0][axis] * s;
    }

    /* Build outdoor transform matrix for world */
    float outdoorScale[3];
    float outdoorTranslate[3];
    for (axis = 0; axis < 3; axis++) {
        float range = outdoorGlob.bbox[1][axis] - outdoorGlob.bbox[0][axis];
        outdoorScale[axis] = 1.0f / range;
        outdoorTranslate[axis] = -outdoorGlob.bbox[0][axis] * outdoorScale[axis];
    }

    float *matrix = (float *)((byte *)world + 0x1c0);
    MatrixIdentity44(matrix);
    matrix[0] = outdoorScale[0];
    matrix[5] = outdoorScale[1];
    matrix[10] = outdoorScale[2];
    matrix[12] = outdoorTranslate[0];
    matrix[13] = outdoorTranslate[1];
    matrix[14] = outdoorTranslate[2];

    *(void **)((byte *)world + 0x200) = Image_Register("$outdoor", 1, 0);
}

void R_GenerateOutdoorImage(GfxImage *outdoorImage)
{
    byte *pic = (byte *)Hunk_AllocateTempMemoryInternal(0x40000);
    outdoorGlob.pic = pic;

    int row;
    for (row = 0; row < 512; row++) {
        float rowF = (float)row + 0.5f - outdoorGlob.add[1];
        rowF *= outdoorGlob.invScale[1];

        int col;
        for (col = 0; col < 512; col++) {
            float colF = (float)col + 0.5f - outdoorGlob.add[0];
            colF *= outdoorGlob.invScale[0];

            float ceilZ = outdoorGlob.scale[1] + 1.0f;
            float floorZ = outdoorGlob.scale[0] - 1.0f;

            vec3_t start, end;
            start[0] = colF;
            start[1] = rowF;
            start[2] = ceilZ;

            end[0] = colF;
            end[1] = rowF;
            end[2] = floorZ;

            float trace[9];
            memset(trace, 0, 9 * sizeof(float));
            trace[0] = 1.0f;

            vec3_t nullVec = {0, 0, 0};
            CM_BoxTrace(trace, start, end, nullVec, nullVec, 0x2001, 0);

            float hitZ = floorZ + (ceilZ - floorZ) * trace[0];
            hitZ = hitZ * outdoorGlob.scale[2] + outdoorGlob.add[2];

            float fval = floorf(hitZ);
            int ival = (int)fval;
            byte bval;
            if (ival < 0) {
                bval = 0;
            } else {
                bval = (ival > 255) ? 255 : (byte)ival;
            }

            pic[col] = bval;
        }

        pic += 512;
    }

    Image_Generate2D(outdoorImage, outdoorGlob.pic, 512, 512, 0x32);
    Hunk_FreeTempMemory(outdoorGlob.pic);
}
