/* Decompiled from: cg_drawtools_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_drawtools_mp.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>

extern float fabsf(float x);
extern float sinf(float x);
extern float cosf(float x);
extern double atof(const char *s);

static vec4_t color; /* 0xf31700 */
static vec2_t sign[4] = { /* 0x303100 */
    {-1.0f, -1.0f},
    { 1.0f, -1.0f},
    { 1.0f,  1.0f},
    {-1.0f,  1.0f}
};

extern char **cg_glob;              /* 0x195f584 — pointer to cg_t base */
extern char **cgs_glob;             /* 0x195f5c4 — pointer to cgs_t base */
extern char **compPointerConfig;    /* 0x195f6d8 */
extern const vec_t *colorWhite;    /* 0x195ed2c */

extern FontHandle UI_GetFontHandle(int type, float scale);
extern void UI_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float fontScale, const vec_t *color, int style);
extern int CL_TextWidth(const char *text, int maxChars, FontHandle font);
extern int CL_TextHeight(FontHandle font);
extern void CL_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style);
extern const char *CL_GetConfigString(int index);
extern float AngleNormalize360(float angle);
extern float AngleNormalize180(float angle);
extern float AngleSubtract(float a1, float a2);
extern void CL_SetFullScreenViewport(void);
extern void CL_SetViewport(int x, int y, int width, int height);
extern void CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign);
extern void CL_DrawQuadPic(vec2_t *verts, const vec_t *color, MaterialHandle material);

void CG_DrawStringExt(float x, float y, const char *string, const vec_t *setColor, qboolean forceColor, qboolean shadow, float charHeight, qboolean adjust);
int CG_DrawDevString(float x, float y, const char *s, const vec_t *color, int align, FontHandle font, int style);
int CG_DrawBigDevStringColor(float x, float y, const char *s, const vec_t *color, int align);
int CG_DrawSmallDevStringColor(float x, float y, const char *s, const vec_t *color, int align);
float * CG_FadeColor(int startMsec, int totalMsec, int fadeMsec);
void CG_NorthDirectionChanged(void);
void CG_UpdateCompassOrientation(void);
void CG_UpdateCompPointerOrientation(void);
void CG_TileClear(void);
int CG_DrawBigDevString(float x, float y, const char *s, float alpha, int align);
void CG_DrawRotatedPicPhysical(float x, float y, float width, float height, float angle, const vec_t *color, MaterialHandle material);
void CG_DrawRotatedPic(float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const vec_t *color, MaterialHandle material);
void CG_DrawRotatedQuadPic(float x, float y, vec2_t *verts, float angle, const vec_t *color, MaterialHandle material);

void CG_DrawStringExt(float x, float y, const char *string, const vec_t *setColor, qboolean forceColor, qboolean shadow, float charHeight, qboolean adjust) {
    float baselineY = y + charHeight * 0.8f;
    float fontScale = charHeight / 48.0f;

    if (!setColor) {
        setColor = colorWhite;
    }

    FontHandle font = UI_GetFontHandle(5, fontScale);
    int style = (shadow >= 1) ? 3 : 0;

    UI_DrawText(string, 0x7fffffff, font, x, baselineY, 1, 1, fontScale, setColor, style);
}

int CG_DrawDevString(float x, float y, const char *s, const vec_t *color, int align, FontHandle font, int style) {
    if ((align & 3) != 1) {
        CL_TextWidth(s, 0, font);
    }

    int step = CL_TextHeight(font);
    float fStep = (float)step;

    int vertAlign = align & 0xC;
    if (vertAlign == 0xC) {
        fStep *= 0.5f;
    }
    if (vertAlign != 8) {
        y += fStep;
    }

    int textWidth = CL_TextWidth(s, 0, font);
    CL_DrawText(s, 0x7fffffff, font, -(float)textWidth, y, 3, 1, 1.0f, 1.0f, color, style);

    return step;
}

int CG_DrawBigDevStringColor(float x, float y, const char *s, const vec_t *color, int align) {
    char *cgs = *cgs_glob;
    return CG_DrawDevString(x, y, s, color, align, *(FontHandle *)(cgs + 0xbc80), 0);
}

int CG_DrawSmallDevStringColor(float x, float y, const char *s, const vec_t *color, int align) {
    char *cgs = *cgs_glob;
    return CG_DrawDevString(x, y, s, color, align, *(FontHandle *)(cgs + 0xbc7c), 0);
}

float * CG_FadeColor(int startMsec, int totalMsec, int fadeMsec) {
    if (!startMsec) {
        return NULL;
    }

    char *cg = *cg_glob;
    int t = *(int *)(cg + 0x25bb0) - startMsec;

    if (t >= totalMsec) {
        return NULL;
    }

    int remaining = totalMsec - t;

    if (remaining >= fadeMsec) {
        color[3] = 1.0f;
    } else {
        color[3] = (float)remaining / (float)fadeMsec;
    }

    color[0] = 1.0f;
    color[1] = 1.0f;
    color[2] = 1.0f;
    return color;
}

void CG_NorthDirectionChanged(void) {
    const char *configStr = CL_GetConfigString(11);
    char *cg = *cg_glob;
    *(float *)(cg + 0x2c5ac) = (float)atof(configStr);
}

void CG_UpdateCompassOrientation(void) {
    char *cg = *cg_glob;
    float fTargetYaw = AngleNormalize360(*(float *)(cg + 0x285cc) - *(float *)(cg + 0x2c5ac));

    int lastTime = *(int *)(cg + 0x2c5a8);
    int currentTime = *(int *)(cg + 0x25bb0);

    if (lastTime > currentTime || (float)(currentTime - lastTime) > 500.0f) {
        *(int *)(cg + 0x2c5a8) = currentTime;
        *(float *)(cg + 0x2c5b0) = fTargetYaw;
        *(float *)(cg + 0x2c5b4) = 0.0f;
        return;
    }

    int iTotalTime = currentTime - lastTime;
    *(int *)(cg + 0x2c5a8) = currentTime;
    float fDiff = AngleSubtract(*(float *)(cg + 0x2c5b0), fTargetYaw);

    if (iTotalTime <= 0) {
        cg = *cg_glob;
        *(float *)(cg + 0x2c5b0) = AngleNormalize360(fDiff + fTargetYaw);
        return;
    }

    while (iTotalTime > 0) {
        float dt;
        if (iTotalTime > 5) {
            iTotalTime -= 5;
            dt = 5.0f;
        } else {
            dt = (float)iTotalTime;
            iTotalTime = 0;
        }
        float fTimeStep = dt * 0.001f;

        if (fabsf(fDiff) < 0.25f) {
            cg = *cg_glob;
            if (fabsf(*(float *)(cg + 0x2c5b4)) < 1.0f) {
                *(float *)(cg + 0x2c5b0) = fTargetYaw;
                *(float *)(cg + 0x2c5b4) = 0.0f;
                return;
            }
        }

        cg = *cg_glob;
        fDiff = AngleNormalize180(fDiff + fTimeStep * *(float *)(cg + 0x2c5b4));

        if (fDiff > 0.0f) {
            *(float *)(cg + 0x2c5b4) -= fTimeStep * 1000.0f;
        } else if (fDiff < 0.0f) {
            cg = *cg_glob;
            *(float *)(cg + 0x2c5b4) += fTimeStep * 1000.0f;
        }

        cg = *cg_glob;
        float vel = *(float *)(cg + 0x2c5b4);
        vel -= vel * 2.0f * fTimeStep;
        *(float *)(cg + 0x2c5b4) = vel;

        if (vel > 0.0f) {
            if (fDiff > 0.0f) {
                vel -= vel * 3.5f * fTimeStep;
                *(float *)(cg + 0x2c5b4) = vel;
            }
            vel -= fTimeStep;
            *(float *)(cg + 0x2c5b4) = vel;
            if (vel < 0.0f) {
                *(float *)(cg + 0x2c5b4) = 0.0f;
            }
        } else {
            if (fDiff < 0.0f) {
                vel -= vel * 3.5f * fTimeStep;
                *(float *)(cg + 0x2c5b4) = vel;
            }
            vel += fTimeStep;
            if (vel > 0.0f) vel = 0.0f;
            *(float *)(cg + 0x2c5b4) = vel;
        }

        cg = *cg_glob;
        vel = *(float *)(cg + 0x2c5b4);
        if (vel > 30000.0f) {
            *(float *)(cg + 0x2c5b4) = 30000.0f;
        } else if (vel < -30000.0f) {
            *(float *)(cg + 0x2c5b4) = -30000.0f;
        }
    }

    cg = *cg_glob;
    *(float *)(cg + 0x2c5b0) = AngleNormalize360(fDiff + fTargetYaw);
}

void CG_UpdateCompPointerOrientation(void) {
    char *config = *compPointerConfig;
    if (*(char *)(config + 8) == 0) {
        char *cg = *cg_glob;
        *(float *)(cg + 0x2c5b8) = *(float *)(cg + 0x285cc);
        return;
    }

    char *cg = *cg_glob;
    int lastTime = *(int *)(cg + 0x2c5a8);
    int currentTime = *(int *)(cg + 0x25bb0);

    if (lastTime == currentTime) {
        return;
    }

    float fTargetYaw = *(float *)(cg + 0x285cc);

    if (lastTime > currentTime || (float)(currentTime - lastTime) > 500.0f) {
        *(int *)(cg + 0x2c5a8) = currentTime;
        *(float *)(cg + 0x2c5b8) = fTargetYaw;
        *(float *)(cg + 0x2c5bc) = 0.0f;
        return;
    }

    int iTotalTime = currentTime - lastTime;
    *(int *)(cg + 0x2c5a8) = currentTime;
    float fDiff = AngleSubtract(*(float *)(cg + 0x2c5b8), fTargetYaw);

    if (fabsf(fDiff) > 10.0f) {
        fDiff = (fDiff >= 0.0f) ? 10.0f : -10.0f;
    }

    if (iTotalTime <= 0) {
        cg = *cg_glob;
        *(float *)(cg + 0x2c5b8) = AngleNormalize360(fDiff + fTargetYaw);
        return;
    }

    while (iTotalTime > 0) {
        float dt;
        if (iTotalTime > 5) {
            iTotalTime -= 5;
            dt = 5.0f;
        } else {
            dt = (float)iTotalTime;
            iTotalTime = 0;
        }
        float fTimeStep = dt * 0.001f;

        if (fabsf(fDiff) < 0.5f) {
            cg = *cg_glob;
            if (fabsf(*(float *)(cg + 0x2c5bc)) < 2.0f) {
                *(float *)(cg + 0x2c5b8) = fTargetYaw;
                *(float *)(cg + 0x2c5bc) = 0.0f;
                return;
            }
        }

        cg = *cg_glob;
        fDiff = AngleNormalize180(fDiff + fTimeStep * *(float *)(cg + 0x2c5bc));

        if (fDiff > 0.0f) {
            *(float *)(cg + 0x2c5bc) -= fTimeStep * 1500.0f;
        } else if (fDiff < 0.0f) {
            cg = *cg_glob;
            *(float *)(cg + 0x2c5bc) += fTimeStep * 1500.0f;
        }

        cg = *cg_glob;
        float vel = *(float *)(cg + 0x2c5bc);
        vel -= vel * 3.0f * fTimeStep;
        *(float *)(cg + 0x2c5bc) = vel;

        if (vel > 0.0f) {
            if (fDiff > 0.0f) {
                vel -= vel * 5.0f * fTimeStep;
                *(float *)(cg + 0x2c5bc) = vel;
            }
            vel -= 2.0f * fTimeStep;
            *(float *)(cg + 0x2c5bc) = vel;
            if (vel < 0.0f) {
                *(float *)(cg + 0x2c5bc) = 0.0f;
            }
        } else {
            if (fDiff < 0.0f) {
                vel -= vel * 5.0f * fTimeStep;
                *(float *)(cg + 0x2c5bc) = vel;
            }
            vel += 2.0f * fTimeStep;
            if (vel > 0.0f) vel = 0.0f;
            *(float *)(cg + 0x2c5bc) = vel;
        }

        cg = *cg_glob;
        vel = *(float *)(cg + 0x2c5bc);
        if (vel > 2000.0f) {
            *(float *)(cg + 0x2c5bc) = 2000.0f;
        } else if (vel < -2000.0f) {
            *(float *)(cg + 0x2c5bc) = -2000.0f;
        }
    }

    cg = *cg_glob;
    *(float *)(cg + 0x2c5b8) = AngleNormalize360(fDiff + fTargetYaw);
}

void CG_TileClear(void) {
    char *cgs = *cgs_glob;
    char *cg = *cg_glob;

    if (*(int *)(cgs + 0x5e84) == *(int *)(cg + 0x28570) &&
        *(int *)(cgs + 0x5e88) == *(int *)(cg + 0x28574) &&
        *(int *)(cgs + 0x5e8c) == *(int *)(cg + 0x28578) &&
        *(int *)(cgs + 0x5e90) == *(int *)(cg + 0x2857c)) {
        return;
    }

    CL_SetFullScreenViewport();
    cg = *cg_glob;
    CL_SetViewport(
        *(int *)(cg + 0x28570),
        *(int *)(cg + 0x28574),
        *(int *)(cg + 0x28578),
        *(int *)(cg + 0x2857c)
    );
}

int CG_DrawBigDevString(float x, float y, const char *s, float alpha, int align) {
    vec4_t c;
    c[0] = 1.0f;
    c[1] = 1.0f;
    c[2] = 1.0f;
    c[3] = alpha;

    char *cgs = *cgs_glob;
    return CG_DrawDevString(x, y, s, c, align, *(FontHandle *)(cgs + 0xbc80), 0);
}

void CG_DrawRotatedPicPhysical(float x, float y, float width, float height, float angle, const vec_t *color, MaterialHandle material) {
    float radians = (float)((double)angle * 0.017453292519943295);
    float s = sinf(radians);
    float c = cosf(radians);
    float halfW = width * 0.5f;
    float halfH = height * 0.5f;
    float cx = halfW + x;
    float cy = halfH + y;
    float cw = c * halfW;
    float sw = s * halfW;
    float sh = s * halfH;
    float ch = c * halfH;

    vec2_t verts[4];
    int i;
    for (i = 0; i < 4; i++) {
        verts[i][0] = cx + cw * sign[i][0] - sw * sign[i][1];
        verts[i][1] = cy + sh * sign[i][0] + ch * sign[i][1];
    }

    CL_DrawQuadPic(verts, color, material);
}

void CG_DrawRotatedPic(float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const vec_t *color, MaterialHandle material) {
    CalcScreenPlacement(&x, &y, &width, &height, horzAlign, vertAlign);
    CG_DrawRotatedPicPhysical(x, y, width, height, angle, color, material);
}

void CG_DrawRotatedQuadPic(float x, float y, vec2_t *verts, float angle, const vec_t *color, MaterialHandle material) {
    float radians = (float)((double)angle * 0.017453292519943295);
    float s = sinf(radians);
    float c = cosf(radians);

    vec2_t xy[4];
    int i;
    for (i = 0; i < 4; i++) {
        xy[i][0] = x + c * verts[i][0] - s * verts[i][1];
        xy[i][1] = y + s * verts[i][0] + c * verts[i][1];
    }

    CL_DrawQuadPic(xy, color, material);
}
