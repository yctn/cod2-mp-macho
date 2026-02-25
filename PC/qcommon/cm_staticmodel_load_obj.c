/* Converted to C from ASM: cm_staticmodel_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_staticmodel_load_obj.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

extern const char *Com_Parse(const char **buf);
extern int stricmp(const char *s1, const char *s2);
extern void *CM_XModelPrecache(const char *name);
extern Bool Com_ValidXModelName(const char *name);
extern void AnglesToAxis(vec3_t angles, float *axis);
extern void MatrixInverse(float *src, float *dst);
extern int XModelGetStaticBounds(void *model, float *axis, vec3_t outMins, vec3_t outMaxs);
extern void Com_Error(int level, const char *fmt, ...);
extern void *CM_Hunk_Alloc(int size, const char *name, int align);
extern int sscanf(const char *str, const char *fmt, ...);

extern byte *cm_global; /* 0x195eda4 */

void CM_LoadStaticModels(void)
{
    byte *cm = *(byte **)&cm_global;
    const char *ptr = *(const char **)(cm + 0x98);

    /* Reset counts */
    *(int *)(cm + 4) = 0;
    *(int *)(cm + 8) = 0;

    char modelName[64];
    char key[64];
    char value[64];
    int bMiscModel;

    /* First pass: count static models */
    for (;;) {
        const char *token = Com_Parse(&ptr);
        if (ptr == NULL)
            break;
        if (*token != '{')
            break;

        modelName[0] = '\0';
        bMiscModel = 0;

        for (;;) {
            token = Com_Parse(&ptr);
            if (ptr == NULL || *token == '}')
                break;

            strcpy(key, token);

            token = Com_Parse(&ptr);
            if (ptr == NULL)
                break;

            strcpy(value, token);

            if (stricmp(key, "classname") == 0) {
                if (stricmp(value, "misc_model") == 0) {
                    bMiscModel = 1;
                }
            } else if (stricmp(key, "model") == 0) {
                strcpy(modelName, value);
            }
        }

        if (!bMiscModel)
            continue;

        if (!Com_ValidXModelName(modelName))
            continue;

        *(int *)(cm + 4) += 1;
    }

    /* Check if any models found */
    int numStaticModels = *(int *)(cm + 4);
    if (numStaticModels == 0)
        return;

    /* Allocate static model array (each entry is 0x50 = 80 bytes) */
    byte *staticModels = (byte *)CM_Hunk_Alloc(numStaticModels * 80, "CM_CreateStaticModel", 0x19);
    *(byte **)(cm + 8) = staticModels;

    /* Second pass: populate static models */
    ptr = *(const char **)(cm + 0x98);
    int offset = 0;

    for (;;) {
        const char *token = Com_Parse(&ptr);
        if (ptr == NULL)
            return;
        if (*token != '{')
            return;

        modelName[0] = '\0';
        vec3_t origin = {0, 0, 0};
        vec3_t angles = {0, 0, 0};
        vec3_t scale = {1.0f, 1.0f, 1.0f};
        int found = 0;

        for (;;) {
            token = Com_Parse(&ptr);
            if (ptr == NULL || *token == '}')
                break;

            strcpy(key, token);

            token = Com_Parse(&ptr);
            if (ptr == NULL)
                break;

            strcpy(value, token);

            if (stricmp(key, "classname") == 0) {
                if (stricmp(value, "misc_model") == 0) {
                    found = 1;
                }
            } else if (stricmp(key, "model") == 0) {
                strcpy(modelName, value);
            } else if (stricmp(key, "origin") == 0) {
                sscanf(value, "%f %f %f", &origin[0], &origin[1], &origin[2]);
            } else if (stricmp(key, "angles") == 0) {
                sscanf(value, "%f %f %f", &angles[0], &angles[1], &angles[2]);
            } else if (stricmp(key, "modelscale_vec") == 0) {
                sscanf(value, "%f %f %f", &scale[0], &scale[1], &scale[2]);
            } else if (stricmp(key, "modelscale") == 0) {
                float s = (float)atof(value);
                scale[0] = s;
                scale[1] = s;
                scale[2] = s;
            }
        }

        if (!found)
            continue;

        if (!Com_ValidXModelName(modelName))
            continue;

        byte *staticModel = staticModels + offset;

        /* Validate model name not empty */
        if (modelName[7] == '\0') {
            Com_Error(1, "CM_LoadStaticModels: empty model name");
        }

        /* Validate scales */
        if (scale[0] == 0.0f) {
            Com_Error(1, "Static model [%s] has x scale of 0.0\n", modelName + 7);
        }
        if (scale[1] == 0.0f) {
            Com_Error(1, "Static model [%s] has y scale of 0.0\n", modelName + 7);
        }
        if (scale[2] == 0.0f) {
            Com_Error(1, "Static model [%s] has z scale of 0.0\n", modelName + 7);
        }

        /* Load model */
        void *model = CM_XModelPrecache(modelName + 7);
        if (model == NULL) {
            *(int *)(cm + 4) -= 1;
            continue;
        }

        /* Store model pointer */
        *(void **)(staticModel + 4) = model;

        /* Copy origin */
        *(float *)(staticModel + 8) = origin[0];
        *(float *)(staticModel + 12) = origin[1];
        *(float *)(staticModel + 16) = origin[2];

        /* Build scaled axis */
        float axis[9];
        AnglesToAxis(angles, axis);

        /* Scale axis[0] by scale[0] */
        axis[0] *= scale[0];
        axis[1] *= scale[0];
        axis[2] *= scale[0];

        /* Scale axis[1] by scale[1] */
        axis[3] *= scale[1];
        axis[4] *= scale[1];
        axis[5] *= scale[1];

        /* Scale axis[2] by scale[2] */
        axis[6] *= scale[2];
        axis[7] *= scale[2];
        axis[8] *= scale[2];

        /* Store inverse axis */
        MatrixInverse(axis, (float *)(staticModel + 0x14));

        /* Get static bounds */
        float *absMin = (float *)(staticModel + 0x38);
        float *absMax = (float *)(staticModel + 0x44);
        if (XModelGetStaticBounds(model, axis, absMin, absMax)) {
            /* Offset bounds by origin */
            absMin[0] += origin[0];
            absMin[1] += origin[1];
            absMin[2] += origin[2];
            absMax[0] += origin[0];
            absMax[1] += origin[1];
            absMax[2] += origin[2];
        }

        offset += 0x50;
    }
}
