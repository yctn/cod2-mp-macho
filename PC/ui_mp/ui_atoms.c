/* Converted to C from ASM: ui_atoms.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui_mp/ui_atoms.cpp */

#include "common_types.h"
#include "imports.h"

extern void CL_DrawStretchPic(float x, float y, float w, float h, int horzAlign, int vertAlign, float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material);
extern void CL_DrawStretchPicPhysical(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material);
extern int Dvar_GetInt(const char *dvarName);
extern int Hunk_Used(void);

extern byte *uiInfo_ptr; /* imp_sharedUiInfo */

float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle hMaterial);
float UI_DrawLoadBar(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle material);
float UI_FillRectPhysical(float x, float y, float width, float height, const vec_t *color);
float UI_FillRect(float x, float y, float width, float height, int horzAlign, int vertAlign, const vec_t *color);

/* line 56 */
float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle hMaterial)
{
    float s0, t0, s1, t1;

    /* line 63 */
    if (w < 0.0f)
    {
        /* line 65 — negative width: flip horizontal */
        w = -w;
        s0 = 1.0f;
        s1 = 0.0f;
    }
    else
    {
        s0 = 0.0f;
        s1 = 1.0f;
    }

    /* line 75 */
    if (h < 0.0f)
    {
        /* line 77 — negative height: flip vertical */
        h = -h;
        t0 = 1.0f;
        t1 = 0.0f;
    }
    else
    {
        t0 = 0.0f;
        t1 = 1.0f;
    }

    /* line 87 */
    CL_DrawStretchPic(x, y, w, h, horzAlign, vertAlign, s0, t0, s1, t1, color, hMaterial);
}

/* line 91 */
float UI_DrawLoadBar(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle material)
{
    int expectedHunk;
    float frac;

    /* line 104 */
    expectedHunk = Dvar_GetInt("com_expectedHunkUsage");

    /* line 105 */
    frac = 0.0f;

    if (expectedHunk > 0)
    {
        /* line 107 */
        frac = (float)Hunk_Used() / (float)expectedHunk;

        /* line 108 — clamp to 1.0 */
        if (frac > 1.0f)
            frac = 1.0f;
    }

    /* line 127 */
    CL_DrawStretchPic(x, y, frac * w, h, horzAlign, vertAlign, 0.0f, 0.0f, frac, 1.0f, color, material);
}

/* line 138 */
float UI_FillRectPhysical(float x, float y, float width, float height, const vec_t *color)
{
    MaterialHandle whiteMaterial;

    /* line 140 */
    whiteMaterial = *(MaterialHandle *)(uiInfo_ptr + 0x20);

    if (whiteMaterial)
    {
        /* line 141 */
        CL_DrawStretchPicPhysical(x, y, width, height, 0.0f, 0.0f, 0.0f, 0.0f, color, whiteMaterial);
    }
}

/* line 152 */
float UI_FillRect(float x, float y, float width, float height, int horzAlign, int vertAlign, const vec_t *color)
{
    MaterialHandle whiteMaterial;

    /* line 154 */
    whiteMaterial = *(MaterialHandle *)(uiInfo_ptr + 0x20);

    if (whiteMaterial)
    {
        /* line 155 */
        CL_DrawStretchPic(x, y, width, height, horzAlign, vertAlign, 0.0f, 0.0f, 0.0f, 0.0f, color, whiteMaterial);
    }
}
