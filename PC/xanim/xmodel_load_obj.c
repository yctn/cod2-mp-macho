/* ASM dump from: xmodel_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xmodel_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/consumedata.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/xanim/xanim_local.h"
 *   #include "PC/xanim/xanim_public.h"
 */

int XModelGetStaticBounds(const XModel *model, vec3_t *axis, vec_t *mins, vec_t *maxs);
XModel * XModelLoad(const char *name, Alloc_t Alloc, Alloc_t AllocColl);

extern void MatrixTransformVector(const float *in1, const float (*in2)[3], float *out);
extern void QuatMultiply(const float *in1, const float *in2, float *out);
extern XModelParts * XModelPartsFindData(const char *name);
extern void XModelPartsSetData(const char *name, XModelParts *modelParts, Alloc_t Alloc);
extern XModelSurfs * XModelSurfsFindData(const char *name);
extern void XModelSurfsSetData(const char *name, XModelSurfs *modelSurfs, Alloc_t Alloc);
extern XSurface * XModelReadSurface(XModel *model, int *partBits, const byte **pos, Alloc_t Alloc);
extern void XModelFree(XModel *model);
extern trXSkin_t * R_LoadXSkins(XModel *model);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern int FS_ReadFile(const char *qpath, void **buffer);
extern void FS_FreeFile(void *buffer);
extern void Com_Printf(const char *fmt, ...);
extern unsigned int SL_GetString_(const char *str, unsigned int user, int type);
extern unsigned int SL_GetStringOfLen(const char *str, unsigned int user, unsigned int len, int type);

extern float floorf(float x);
extern float sqrtf(float x);
extern char *g_renderer_ptr; /* 0x195eca8 */

/* line 711 */
int XModelGetStaticBounds(const XModel *model, vec3_t *axis, vec_t *mins, vec_t *maxs)
{
    int i, k, j;
    XModelCollSurf *csurf;
    vec3_t corner;
    vec3_t rotated;

    if (!model->numCollSurfs) {
        return 0;
    }

    /* ClearBounds */
    mins[0] = 3.4028234663852886e+38f;
    mins[1] = 3.4028234663852886e+38f;
    mins[2] = 3.4028234663852886e+38f;
    maxs[0] = -3.4028234663852886e+38f;
    maxs[1] = -3.4028234663852886e+38f;
    maxs[2] = -3.4028234663852886e+38f;

    if (model->numCollSurfs <= 0) {
        return 1;
    }

    for (i = 0; i < model->numCollSurfs; i++) {
        csurf = &model->collSurfs[i];

        for (k = 0; k < 8; k++) {
            /* Build corner from mins/maxs based on bits of k */
            if (k & 1) {
                corner[0] = csurf->mins[0];
            } else {
                corner[0] = csurf->maxs[0];
            }

            if (k & 2) {
                corner[1] = csurf->mins[1];
            } else {
                corner[1] = csurf->maxs[1];
            }

            if (k & 4) {
                corner[2] = csurf->mins[2];
            } else {
                corner[2] = csurf->maxs[2];
            }

            MatrixTransformVector(corner, axis, rotated);

            for (j = 1; j < 4; j++) {
                if (mins[j - 1] > rotated[j - 1]) {
                    mins[j - 1] = rotated[j - 1];
                }
                if (rotated[j - 1] > maxs[j - 1]) {
                    maxs[j - 1] = rotated[j - 1];
                }
            }
        }
    }

    return 1;
}

/* line 679 */
XModel * XModelLoad(const char *name, Alloc_t Alloc, Alloc_t AllocColl)
{
    XModelConfig config;
    int nameLens[4];
    char filename[64];
    char partsFilename[64];
    void *buf;
    void *partsBuf;
    int i, j;
    XModel *model;
    const byte *pos;
    int size;
    XModelParts *modelParts;
    char *lodFilename;
    int lodIndex;
    const char *modelName;
    short modelNumSurfs;

    union {
        short s;
        int i;
        float f;
    } u;

    /* Format filename "xmodel/%s" */
    if (Com_sprintf(filename, 64, "xmodel/%s", name) < 0) {
        Com_Printf("^1ERROR: filename '%s' too long\n", filename);
        model = NULL;
        goto done;
    }

    /* Read the xmodel file */
    i = FS_ReadFile(filename, &buf);
    if (i < 0) {
        Com_Printf("^1ERROR: xmodel '%s' not found\n", name);
        model = NULL;
        goto done;
    }

    if (i == 0) {
        Com_Printf("^1ERROR: xmodel '%s' has 0 length\n", name);
        goto version_error;
    }

    /* Check version */
    pos = (const byte *)buf;
    u.s = *(short *)pos;
    if (u.s != 0x14) {
        Com_Printf("^1ERROR: xmodel '%s' out of date (version %d, expecting %d).", name, (int)(signed short)u.s, 0x14);
version_error:
        FS_FreeFile(buf);
        model = NULL;
        goto done;
    }

    /* Read flags byte at offset 2 */
    config.flags = *(unsigned char *)(pos + 2);

    /* Read 6 floats: mins[3] and maxs[3] starting at offset 3 */
    memcpy(&config.mins[0], pos + 3, 4);
    memcpy(&config.mins[1], pos + 7, 4);
    memcpy(&config.mins[2], pos + 11, 4);
    memcpy(&config.maxs[0], pos + 15, 4);
    memcpy(&config.maxs[1], pos + 19, 4);
    memcpy(&config.maxs[2], pos + 23, 4);

    /* Read collLod at offset 27 (4 bytes, but used as int) */
    {
        const byte *cur = pos + 27;

        /* Read 4 config entries (lod filenames and distances) */
        for (i = 0; i < 4; i++) {
            memcpy(&config.entries[i].dist, cur, 4);
            cur += 4;
            strcpy(config.entries[i].filename, (const char *)cur);
            cur += strlen((const char *)cur) + 1;
        }

        /* Read collLod (4 bytes) */
        memcpy(&config.collLod, cur, 4);
        cur += 4;

        /* Compute string lengths and total size */
        size = 0;
        for (j = 0; j < 4; j++) {
            nameLens[j] = strlen(config.entries[j].filename) + 1;
            size += nameLens[j];
        }

        /* Allocate model struct (size 0x90 + string space) */
        size += sizeof(XModel);
        model = (XModel *)Alloc(size);
        model->memUsage = size;

        /* Read numCollSurfs from file data */
        {
            int numCS;
            memcpy(&numCS, cur, 4);
            cur += 4;

            model->numCollSurfs = numCS;

            if (numCS != 0) {
                /* Allocate collision surfaces: numCS * (numCS*10+1) * 4 ... */
                /* Actually: size = numCS * 11 * 4 = numCS * 44 = numCS * sizeof(XModelCollSurf) */
                model->collSurfs = (XModelCollSurf *)AllocColl(numCS * sizeof(XModelCollSurf));

                if (model->numCollSurfs > 0) {
                    float epsilon = 0.0010000000474974513f;
                    for (i = 0; i < model->numCollSurfs; i++) {
                        XModelCollSurf *surf = &model->collSurfs[i];
                        int numTris;

                        /* Read numCollTris */
                        memcpy(&numTris, cur, 4);
                        cur += 4;
                        surf->numCollTris = numTris;

                        /* Allocate collision triangles: numTris * 3 * 16 = numTris * 48 */
                        surf->collTris = (XModelCollTri *)AllocColl(numTris * sizeof(XModelCollTri));

                        /* Read collision triangles */
                        if (surf->numCollTris > 0) {
                            for (j = 0; j < surf->numCollTris; j++) {
                                XModelCollTri *tri = &surf->collTris[j];
                                /* Read 12 floats (plane, svec, tvec = 3 vec4_t) */
                                memcpy(&tri->plane[0], cur, 4); cur += 4;
                                memcpy(&tri->plane[1], cur, 4); cur += 4;
                                memcpy(&tri->plane[2], cur, 4); cur += 4;
                                memcpy(&tri->plane[3], cur, 4); cur += 4;
                                memcpy(&tri->svec[0], cur, 4); cur += 4;
                                memcpy(&tri->svec[1], cur, 4); cur += 4;
                                memcpy(&tri->svec[2], cur, 4); cur += 4;
                                memcpy(&tri->svec[3], cur, 4); cur += 4;
                                memcpy(&tri->tvec[0], cur, 4); cur += 4;
                                memcpy(&tri->tvec[1], cur, 4); cur += 4;
                                memcpy(&tri->tvec[2], cur, 4); cur += 4;
                                memcpy(&tri->tvec[3], cur, 4); cur += 4;
                            }
                        }

                        /* Read bounds with epsilon adjustment */
                        {
                            float tmp;
                            memcpy(&tmp, cur, 4); surf->mins[0] = tmp - epsilon; cur += 4;
                            memcpy(&tmp, cur, 4); surf->mins[1] = tmp - epsilon; cur += 4;
                            memcpy(&tmp, cur, 4); surf->mins[2] = tmp - epsilon; cur += 4;
                            memcpy(&tmp, cur, 4); surf->maxs[0] = tmp + epsilon; cur += 4;
                            memcpy(&tmp, cur, 4); surf->maxs[1] = tmp + epsilon; cur += 4;
                            memcpy(&tmp, cur, 4); surf->maxs[2] = tmp + epsilon; cur += 4;
                        }

                        /* Read boneIdx */
                        memcpy(&surf->boneIdx, cur, 4); cur += 4;

                        /* Read contents with mask */
                        {
                            int contents;
                            memcpy(&contents, cur, 4); cur += 4;
                            surf->contents = contents & 0xdffffffb;
                        }

                        /* Read surfFlags */
                        memcpy(&surf->surfFlags, cur, 4); cur += 4;

                        /* Accumulate contents */
                        model->contents |= surf->contents;
                    }
                }
            }
        }

        /* Set up LOD info */
        lodFilename = (char *)model + sizeof(XModel);
        model->numLods = 0;

        for (i = 0; i < 4; i++) {
            strcpy(lodFilename, config.entries[i].filename);
            model->lodInfo[i].filename = lodFilename;

            if (*lodFilename == '\0') {
                model->lodInfo[i].surfNames = NULL;
                goto next_lod;
            }

            model->numLods += 1;

            /* Read numsurfs from file data */
            {
                short ns;
                memcpy(&ns, cur, 2);
                cur += 2;

                model->lodInfo[i].numsurfs = ns;

                /* Allocate surfNames */
                model->lodInfo[i].surfNames = (short unsigned int *)Alloc(ns * 2);
                model->memUsage += ns * 2;

                if (model->lodInfo[i].numsurfs > 0) {
                    for (j = 0; j < model->lodInfo[i].numsurfs; j++) {
                        int len;
                        const char *str = (const char *)cur;
                        len = strlen(str) + 1;
                        cur += len;
                        model->lodInfo[i].surfNames[j] = (unsigned short)SL_GetString_(str, 0, 8);
                    }
                }
            }

next_lod:
            model->lodInfo[i].dist = config.entries[i].dist;
            lodFilename += nameLens[i];
        }

        /* Find model parts data */
        {
            const char *partsName = model->lodInfo[0].filename;

            modelParts = XModelPartsFindData(partsName);
            if (!modelParts) {
                /* Need to load parts from file */
                if (Com_sprintf(partsFilename, 64, "xmodelparts/%s", partsName) < 0) {
                    Com_Printf("^1ERROR: filename '%s' too long\n", partsFilename);
                    goto cannot_find_parts;
                }

                i = FS_ReadFile(partsFilename, &partsBuf);
                if (i < 0) {
                    Com_Printf("^1ERROR: xmodelparts '%s' not found\n", partsName);
                    goto cannot_find_parts;
                }

                if (i == 0) {
                    Com_Printf("^1ERROR: xmodelparts '%s' has 0 length\n", partsName);
                    FS_FreeFile(partsBuf);
cannot_find_parts:
                    Com_Printf("^1ERROR: Cannot find xmodelparts '%s'.\n", partsName);
                    modelParts = NULL;
                    goto have_parts;
                }

                /* Check version */
                {
                    const byte *partsPos = (const byte *)partsBuf;
                    short ver;
                    memcpy(&ver, partsPos, 2);
                    if (ver != 0x14) {
                        FS_FreeFile(partsBuf);
                        Com_Printf("^1ERROR: xmodelparts '%s' out of date (version %d, expecting %d).", partsName, (int)ver, 0x14);
                        goto cannot_find_parts;
                    }

                    {
                        short numRootBones;
                        short numNonRootBones;
                        short totalBones;
                        int numNonRoot;
                        short unsigned int *boneNames;
                        XBoneHierarchy *hierarchy;
                        const byte *filePos;

                        memcpy(&numRootBones, partsPos + 2, 2);
                        memcpy(&numNonRootBones, partsPos + 4, 2);
                        numNonRoot = (int)(signed short)numNonRootBones;
                        filePos = partsPos + 6;

                        totalBones = numRootBones + numNonRootBones;

                        if ((int)(signed short)totalBones > 127) {
                            FS_FreeFile(partsBuf);
                            Com_Printf("^1ERROR: xmodel '%s' has more than %d bones\n", partsName, 127);
                            goto cannot_find_parts;
                        }

                        /* Allocate boneNames */
                        boneNames = (short unsigned int *)Alloc((int)(signed short)totalBones * 2);
                        model->memUsage += (int)(signed short)totalBones * 2;

                        /* Allocate hierarchy */
                        {
                            int hierSize = (int)(signed short)numRootBones + 7;
                            hierarchy = (XBoneHierarchy *)Alloc(hierSize);
                            model->memUsage += hierSize;
                        }

                        hierarchy->names = boneNames;

                        /* Allocate modelParts */
                        {
                            int partsSize = (int)(signed short)totalBones * 32 + 0x44;
                            modelParts = (XModelParts *)Alloc(partsSize);
                            model->memUsage += partsSize;
                        }

                        modelParts->hierarchy = hierarchy;

                        /* Allocate quats and trans if there are root bones */
                        if (numRootBones != 0) {
                            modelParts->quats = (short int *)Alloc((int)(signed short)numRootBones * 8);
                            model->memUsage += (int)(signed short)numRootBones * 8;
                            modelParts->trans = (float *)Alloc((int)(signed short)numRootBones * 16);
                            model->memUsage += (int)(signed short)numRootBones * 16;
                        } else {
                            modelParts->quats = NULL;
                            modelParts->trans = NULL;
                        }

                        /* Allocate partClassification */
                        modelParts->partClassification = (unsigned char *)Alloc((int)(signed short)totalBones);
                        model->memUsage += (int)(signed short)totalBones;

                        /* Set header fields */
                        modelParts->numBones = totalBones;
                        modelParts->numRootBones = numNonRootBones;

                        /* Read bone names */
                        {
                            int totalB = (int)(signed short)totalBones;
                            if (totalB > 0) {
                                for (i = 0; i < totalB; i++) {
                                    int slen = strlen((const char *)filePos) + 1;
                                    boneNames[i] = (unsigned short)SL_GetStringOfLen((const char *)filePos, 0, slen, 10);
                                    filePos += slen;
                                }
                            }
                        }

                        /* Copy part classification data */
                        memcpy(modelParts->partClassification, filePos, (int)(signed short)totalBones);

                        /* Read non-root bone hierarchy data */
                        if (numNonRoot > (int)(signed short)totalBones - numNonRoot) {
                            /* There are non-root bones with parent data */
                            int numWithParents = (int)(signed short)totalBones - numNonRoot;
                            const byte *hierPos = filePos;
                            short *quats = modelParts->quats;
                            float *trans = modelParts->trans;

                            /* Read non-root bones data */
                            {
                                DObjAnimMat *skelMat = (DObjAnimMat *)((byte *)modelParts + 0x44);
                                int numNR = (int)(signed short)totalBones - numNonRoot;
                                int bi;

                                /* First, handle root bones: identity quats, zero trans */
                                {
                                    int nr = (int)(signed short)numNonRootBones;
                                    if (nr > 0) {
                                        DObjAnimMat *mat = (DObjAnimMat *)((byte *)modelParts + 0x44);
                                        for (bi = 0; bi < nr; bi++) {
                                            mat[bi].quat[0] = 0.0f;
                                            mat[bi].quat[1] = 0.0f;
                                            mat[bi].quat[2] = 0.0f;
                                            mat[bi].quat[3] = 1.0f;
                                            mat[bi].trans[0] = 0.0f;
                                            mat[bi].trans[1] = 0.0f;
                                            mat[bi].trans[2] = 0.0f;
                                            mat[bi].transWeight = 2.0f;
                                        }
                                    }
                                }

                                /* Process non-root bones that have parents */
                                {
                                    int numToProcess = (int)(signed short)totalBones - numNonRoot - numNonRoot;
                                    float *parentTrans;
                                    DObjAnimMat *mat;

                                    if (numToProcess <= 0) {
                                        goto set_part_bits;
                                    }

                                    parentTrans = modelParts->trans + 3; /* skip first trans entry */
                                    mat = (DObjAnimMat *)((byte *)modelParts + 0x44 + (int)(signed short)numNonRootBones * 32);

                                    for (bi = 0; bi < (int)(signed short)totalBones - numNonRoot - numNonRoot; bi++) {
                                        /* Read parent index */
                                        hierarchy->parentList[bi] = (unsigned char)((bi + (int)(signed short)numNonRootBones) - filePos[0]);
                                        filePos++;

                                        /* Read trans (3 floats) */
                                        memcpy(&parentTrans[0], filePos + 1, 4);
                                        memcpy(&parentTrans[1], filePos + 5, 4);
                                        memcpy(&parentTrans[2], filePos + 9, 4);

                                        /* Read compressed quat (3 shorts) */
                                        {
                                            short qx, qy, qz, qw;
                                            int xx, yy, zz;
                                            int rem;

                                            memcpy(&qx, filePos + 13, 2);
                                            memcpy(&qy, filePos + 15, 2);
                                            memcpy(&qz, filePos + 17, 2);
                                            filePos += 19;

                                            mat[bi].quat[0] = *(float *)&qx; /* store raw short */
                                            /* Actually the asm stores the short values directly */
                                            /* Let me re-read: movw %ax, (%ebx) etc */
                                            /* These are stored as shorts into the quat memory */
                                            /* The DObjAnimMat uses floats, but here we're writing
                                               into it as if it were a short array */
                                            /* This is the compressed quaternion representation */
                                            ((short *)&mat[bi].quat[0])[0] = qx;
                                            ((short *)&mat[bi].quat[0])[1] = qy;
                                            ((short *)&mat[bi].quat[0])[2] = qz;

                                            /* Compute qw = sqrt(0x3fff0001 - xx - yy - zz) */
                                            xx = (int)qx * (int)qx;
                                            yy = (int)qy * (int)qy;
                                            zz = (int)qz * (int)qz;
                                            rem = 0x3fff0001 - xx - yy - zz;

                                            if (rem > 0) {
                                                ((short *)&mat[bi].quat[0])[3] = (short)(int)floorf(sqrtf((float)rem) + 0.5f);
                                            } else {
                                                ((short *)&mat[bi].quat[0])[3] = 0;
                                            }
                                        }

                                        parentTrans += 3;
                                        /* mat stride is 8 shorts = 0x20 bytes per entry */
                                    }
                                }

                                goto finish_parts;
                            }
                        }

finish_parts:
                        /* Read remaining bones with full quats */
                        {
                            DObjAnimMat *mat;
                            float *trans;
                            int numRemaining;
                            short *quatData;
                            int bi;
                            float one = 1.0f;

                            mat = (DObjAnimMat *)((byte *)modelParts + 0x44 + (int)(signed short)numNonRootBones * 32);
                            numRemaining = (int)(signed short)totalBones - (int)(signed short)numNonRootBones;
                            quatData = modelParts->quats;
                            trans = modelParts->trans + 3; /* past first root bone trans */

                            if (numRemaining > 0) {
                                float scale = 3.0518509447574615e-05f;
                                float two = 2.0f;
                                float fone = 1.0f;

                                for (bi = 0; bi < numRemaining; bi++) {
                                    /* Read 4 shorts, convert to float quat */
                                    float q[4];
                                    DObjAnimMat *parentMat;
                                    unsigned char parentIdx;

                                    q[0] = (float)(short)quatData[bi * 4 + 0] * scale;
                                    q[1] = (float)(short)quatData[bi * 4 + 1] * scale;
                                    q[2] = (float)(short)quatData[bi * 4 + 2] * scale;
                                    q[3] = (float)(short)quatData[bi * 4 + 3] * scale;

                                    /* Multiply with parent quaternion */
                                    parentIdx = hierarchy->parentList[0]; /* accessed via edi */
                                    parentMat = &mat[bi] - (parentIdx); /* parent is parentIdx entries back */
                                    /* Actually: ecx = ebx - parentIdx*32 */
                                    parentMat = (DObjAnimMat *)((byte *)&mat[bi] - ((int)parentIdx << 5));

                                    QuatMultiply(q, (float *)parentMat, (float *)&mat[bi]);

                                    /* Normalize quaternion and compute transWeight */
                                    {
                                        float len2 = mat[bi].quat[0] * mat[bi].quat[0]
                                                   + mat[bi].quat[1] * mat[bi].quat[1]
                                                   + mat[bi].quat[2] * mat[bi].quat[2]
                                                   + mat[bi].quat[3] * mat[bi].quat[3];

                                        if (len2 == 0.0f) {
                                            mat[bi].quat[3] = fone;
                                            mat[bi].transWeight = two;
                                        } else {
                                            mat[bi].transWeight = two / len2;
                                        }
                                    }

                                    /* Compute transformed translation */
                                    {
                                        /* This is a quaternion rotation of the parent's translation
                                           applied to this bone's local translation */
                                        float scale2 = parentMat->transWeight;
                                        float sx = scale2 * parentMat->quat[0];
                                        float sy = scale2 * parentMat->quat[1];
                                        float sz = scale2 * parentMat->quat[2];

                                        float xx = sx * parentMat->quat[0];
                                        float xy = sx * parentMat->quat[1];
                                        float xz = sx * parentMat->quat[2];
                                        float xw = sx * parentMat->quat[3];

                                        float yy = sy * parentMat->quat[1];
                                        float yz = sy * parentMat->quat[2];
                                        float yw = sy * parentMat->quat[3];

                                        float zz = sz * parentMat->quat[2];
                                        float zw = sz * parentMat->quat[3];

                                        mat[bi].trans[0] = (fone - (yy + zz)) * trans[bi * 3 + 0]
                                                         + (xy - zw) * trans[bi * 3 + 1]
                                                         + (xz + yw) * trans[bi * 3 + 2]
                                                         + parentMat->trans[0];

                                        mat[bi].trans[1] = (xy + zw) * trans[bi * 3 + 0]
                                                         + (fone - (xx + zz)) * trans[bi * 3 + 1]
                                                         + (yz - xw) * trans[bi * 3 + 2]
                                                         + parentMat->trans[1];

                                        mat[bi].trans[2] = (xz - yw) * trans[bi * 3 + 0]
                                                         + (yz + xw) * trans[bi * 3 + 1]
                                                         + (fone - (xx + yy)) * trans[bi * 3 + 2]
                                                         + parentMat->trans[2];
                                    }
                                }
                            }
                        }

set_part_bits:
                        /* Set partBits to 0xFFFFFFFF */
                        {
                            int *bits1 = (int *)((byte *)modelParts + 0x14);
                            int *bits2 = (int *)((byte *)modelParts + 0x34);
                            bits1[0] = -1;
                            bits1[1] = -1;
                            bits1[2] = -1;
                            bits1[3] = -1;
                            bits2[0] = -1;
                            bits2[1] = -1;
                            bits2[2] = -1;
                            bits2[3] = -1;
                        }

                        XModelPartsSetData(partsName, modelParts, Alloc);
                    }
                }
            }
        }

have_parts:
        model->parts = (void (*)())modelParts;

        if (!modelParts) {
            /* Failed to load parts */
            FS_FreeFile(buf);
            XModelFree(model);
            model = NULL;
            goto done;
        }

        {
            int numBones = (int)(signed short)modelParts->numBones;
            int boneInfoSize = numBones * 40;
            XBoneInfo *boneInfo;

            boneInfo = (XBoneInfo *)Alloc(boneInfoSize);
            model->memUsage += boneInfoSize;

            if (numBones > 0) {
                float half = 0.5f;
                for (i = 0; i < numBones; i++) {
                    /* Read 6 floats: bounds[0] and bounds[1] (mins/maxs) */
                    memcpy(&boneInfo[i].bounds[0][0], cur, 4); cur += 4;
                    memcpy(&boneInfo[i].bounds[0][1], cur, 4); cur += 4;
                    memcpy(&boneInfo[i].bounds[0][2], cur, 4); cur += 4;
                    memcpy(&boneInfo[i].bounds[1][0], cur, 4); cur += 4;
                    memcpy(&boneInfo[i].bounds[1][1], cur, 4); cur += 4;
                    memcpy(&boneInfo[i].bounds[1][2], cur, 4); cur += 4;

                    /* Compute offset = (bounds[0] + bounds[1]) * 0.5 */
                    boneInfo[i].offset[0] = (boneInfo[i].bounds[0][0] + boneInfo[i].bounds[1][0]) * half;
                    boneInfo[i].offset[1] = (boneInfo[i].bounds[0][1] + boneInfo[i].bounds[1][1]) * half;
                    boneInfo[i].offset[2] = (boneInfo[i].bounds[0][2] + boneInfo[i].bounds[1][2]) * half;

                    /* Compute radiusSquared */
                    {
                        float dx = boneInfo[i].bounds[1][0] - boneInfo[i].offset[0];
                        float dy = boneInfo[i].bounds[1][1] - boneInfo[i].offset[1];
                        float dz = boneInfo[i].bounds[1][2] - boneInfo[i].offset[2];
                        boneInfo[i].radiusSquared = dx * dx + dy * dy + dz * dz;
                    }
                }
            }

            model->boneInfo = boneInfo;
        }

        FS_FreeFile(buf);

        /* Copy mins and maxs vectors */
        model->mins[0] = config.mins[0];
        model->mins[1] = config.mins[1];
        model->mins[2] = config.mins[2];
        model->maxs[0] = config.maxs[0];
        model->maxs[1] = config.maxs[1];
        model->maxs[2] = config.maxs[2];

        /* Set collLod and flags */
        model->collLod = (short)config.collLod;
        model->flags = config.flags;

        /* Check renderer for loading surfs */
        if (!*(char *)(g_renderer_ptr + 0x144)) {
            goto done;
        }

        /* Load model surfaces for each LOD */
        lodIndex = 0;
        for (lodIndex = 0; lodIndex < 4; lodIndex++) {
            const char *lodName = model->lodInfo[lodIndex].filename;
            if (*lodName == '\0') {
                break;
            }

            modelName = model->name;
            modelNumSurfs = model->lodInfo[lodIndex].numsurfs;

            {
                XModelSurfs *modelSurfs = XModelSurfsFindData(lodName);

                if (!modelSurfs) {
                    /* Need to load surfs from file */
                    if (Com_sprintf(filename, 64, "xmodelsurfs/%s", lodName) < 0) {
                        Com_Printf("^1ERROR: filename '%s' too long\n", filename);
                        goto cannot_find_surfs;
                    }

                    i = FS_ReadFile(filename, &buf);
                    if (i < 0) {
                        Com_Printf("^1ERROR: xmodelsurf '%s' not found\n", lodName);
                        goto cannot_find_surfs;
                    }

                    if (i == 0) {
                        Com_Printf("^1ERROR: xmodelsurf '%s' has 0 length\n", lodName);
                        FS_FreeFile(buf);
cannot_find_surfs:
                        Com_Printf("^1ERROR: Cannot find 'xmodelsurfs '%s'.\n", lodName);
                        modelSurfs = NULL;
                        goto have_surfs;
                    }

                    /* Check surfs version */
                    {
                        const byte *surfsPos = (const byte *)buf;
                        short surfsVer;
                        memcpy(&surfsVer, surfsPos, 2);
                        surfsPos += 2;

                        if (surfsVer != 0x14) {
                            FS_FreeFile(buf);
                            Com_Printf("^1ERROR: xmodelsurfs '%s' out of date (version %d, expecting %d).", lodName, (int)(signed short)surfsVer, 0x14);
                            goto cannot_find_surfs;
                        }

                        /* Check numsurfs matches */
                        {
                            short fileNumSurfs;
                            memcpy(&fileNumSurfs, surfsPos, 2);
                            surfsPos += 2;

                            if (modelNumSurfs != fileNumSurfs) {
                                FS_FreeFile(buf);
                                Com_Printf("^1ERROR: File conflict (between non-iwd and iwd file) on xmo", lodName, modelName);
                                goto cannot_find_surfs;
                            }

                            /* Allocate XModelSurfs structure */
                            {
                                int surfsAllocSize = 0x14 + (int)(signed short)modelNumSurfs * 4;
                                XSurface **surfPtrs;

                                modelSurfs = (XModelSurfs *)Alloc(surfsAllocSize);
                                model->memUsage += surfsAllocSize;

                                surfPtrs = (XSurface **)((byte *)modelSurfs + 0x14);
                                modelSurfs->surfs = surfPtrs;

                                /* Read surfaces */
                                if ((int)(signed short)modelNumSurfs > 0) {
                                    int *partBits = (int *)((byte *)modelSurfs + 4);
                                    for (j = 0; j < (int)(signed short)modelNumSurfs; j++) {
                                        surfPtrs[j] = XModelReadSurface(model, partBits, &surfsPos, Alloc);
                                    }
                                }

                                FS_FreeFile(buf);
                                XModelSurfsSetData(lodName, modelSurfs, Alloc);
                            }
                        }
                    }
                }

have_surfs:
                model->lodInfo[lodIndex].surfs = modelSurfs;
                if (!modelSurfs) {
                    /* Failed to load surfs - free model */
                    XModelFree(model);
                    model = NULL;
                    goto done;
                }
            }
        }

        /* Load skins */
        model->xskins = R_LoadXSkins(model);
    }

done:
    return model;
}
