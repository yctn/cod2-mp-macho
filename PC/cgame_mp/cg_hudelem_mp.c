/* ASM dump from: cg_hudelem_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_hudelem_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

extern float floorf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

/* extern data */
extern char **cg_glob;            /* imp_cg -- pointer to cg_t base */

/* extern functions */
extern int CL_GetKeyCatchers(void);
extern Bool CL_GetDisplayHUDWithKeycatchUI(void);
extern float CL_NormalizedTextScale(FontHandle font, float fontScale);
extern void CalcScreenPlacement(float *x, float *y, float *scaleX, float *scaleY, int vertAlign, int horzAlign);
extern void CL_DrawTextPhysical(const char *text, int maxChars, FontHandle font, float x, float y, float scaleX, float scaleY, vec4_t *color, int style);
extern void CL_DrawStretchPicPhysical(float x, float y, float w, float h, float s0, float t0, float s1, float t1, vec4_t *color, void *material);
extern void CG_DrawRotatedPicPhysical(float x, float y, float w, float h, float angle, vec4_t *color, void *material);
extern void CL_DrawSprite(void *material, byte *rgbaColor, float halfSize, vec3_t pos, float rotation, int renderFxFlags);
extern FontHandle UI_GetFontHandle(int scriptIndex, float fontScale);
extern int UI_TextWidth(const char *text, int maxChars, FontHandle font, float fontScale);
extern int UI_TextHeight(FontHandle font, float fontScale);
extern void CG_SafeTranslateHudElemString(int label, char *dst);
extern int CG_ServerMaterialName(int materialIndex, char *buf, int bufSize);
extern void *CL_RegisterMaterial(const char *name, int imageTrack);
extern void *CL_RegisterMaterialNoMip(const char *name, int imageTrack);
extern const char *CL_GetConfigString(int index);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void I_strncat(char *dest, int maxlen, const char *src);
extern const char *va(const char *format, ...);
extern float AngleNormalize360(float angle);

Bool CG_AreHudElemsHidden(void);
float CG_AlignHudElemX(int alignOrg, float x, float width);
float CG_AlignHudElemY(int alignOrg, float y, float height);
int compare_hudelems(const inflate_huft *pe0, const inflate_huft *pe1);
static void CG_DrawHudElemString(const char *text, const hudelem_t *elem, cg_hudelem_t *cghe);
static void CG_GetHudElemInfo(const hudelem_t *elem, cg_hudelem_t *cghe, char *hudElemString);
void CG_Draw2dHudElems(qboolean foreground);
void CG_Draw3dHudElems(void);

/* Helper: get cg base pointer */
static char *cg_base(void) {
    return *cg_glob;
}

/* Helper: get current server time from cg */
static int cg_time(void) {
    return ((cg_t *)cg_base())->time;
}

/* Helper: get cgs->clientinfo / hudelem pointer base from snap */
static char *cg_snap(void) {
    return (char *)((cg_t *)cg_base())->snap;
}

/* Helper: clamp 0..1 */
static float clamp01(float val) {
    if (val < 0.0f) return 0.0f;
    if (val > 1.0f) return 1.0f;
    return val;
}

/* Helper: compute width/height value with fallback to text height */
static float CG_GetDimValue(int dimVal, float fontHeight) {
    if (dimVal == 0)
        return fontHeight;
    return (float)dimVal;
}

/* Inline helper: compute move lerp factor */
static float CG_GetMoveLerpFactor(const hudelem_t *elem) {
    int moveTime = elem->moveTime;
    if (moveTime <= 0)
        return 1.0f;
    int serverTime = cg_time();
    int elapsed = serverTime - elem->moveStartTime;
    if (elapsed <= 0)
        return 0.0f;
    if (moveTime > elapsed) {
        float frac = (float)elapsed / (float)moveTime;
        return frac;
    }
    return 1.0f;
}

/* Align X position based on alignment type */
static float CG_AlignX(int alignOrg, float x, float width) {
    int xAlign = (alignOrg >> 2) & 3;
    switch (xAlign) {
        case 1: return x + width * -0.5f;
        case 2: return x - width;
        default: return x;
    }
}

/* Align Y position based on alignment type */
static float CG_AlignY(int alignOrg, float y, float height) {
    int yAlign = alignOrg & 3;
    switch (yAlign) {
        case 1: return y + height * -0.5f;
        case 2: return y - height;
        default: return y;
    }
}

/* line 32 */
Bool CG_AreHudElemsHidden(void)
{
    char *base = cg_base();
    int val = ((cg_t *)base)->drawHud;
    if (!val) {
        return 1;
    }
    if (!(CL_GetKeyCatchers() & 8)) {
        return 0;
    }
    if (CL_GetDisplayHUDWithKeycatchUI()) {
        return 0;
    }
    return 1;
}

/* line 227 */
float CG_AlignHudElemX(int alignOrg, float x, float width)
{
    int xAlign = (alignOrg >> 2) & 3;
    switch (xAlign) {
        case 1: return x + width * -0.5f;
        case 2: return x - width;
        default: return x;
    }
}

/* line 244 */
float CG_AlignHudElemY(int alignOrg, float y, float height)
{
    int yAlign = alignOrg & 3;
    switch (yAlign) {
        case 1: return y + height * -0.5f;
        case 2: return y - height;
        default: return y;
    }
}

/* line 738 */
int compare_hudelems(const inflate_huft *pe0, const inflate_huft *pe1)
{
    const hudelem_t *e0 = *(const hudelem_t **)pe0;
    const hudelem_t *e1 = *(const hudelem_t **)pe1;
    float delta = e0->sort - e1->sort;
    if (delta < 0.0f) {
        return -1;
    }
    if (delta > 0.0f) {
        return 1;
    }
    return 0;
}

/* Helper: get the format string for the timer type and compute the time value
 * Returns the formatted string via va(), or NULL if type is not a timer.
 * The "resolution" parameter selects between tenths and seconds timers.
 */
static const char *CG_FormatTimerString(const hudelem_t *elem, int isTenths) {
    int serverTime = cg_time();
    int msec;
    int hours, minutes, seconds, tenths;

    switch (elem->type) {
        case HE_TYPE_TIMER_DOWN:
        case HE_TYPE_TENTHS_TIMER_DOWN:
            msec = elem->time - serverTime + 999;
            break;
        case HE_TYPE_CLOCK_DOWN:
            msec = elem->time - serverTime + 99;
            break;
        case HE_TYPE_TIMER_UP:
        case HE_TYPE_TENTHS_TIMER_UP:
            msec = serverTime - elem->time;
            break;
        case HE_TYPE_CLOCK_UP:
            msec = serverTime - elem->time;
            break;
        default:
            return NULL;
    }

    if (isTenths) {
        /* Tenths resolution */
        if (msec < 0) {
            hours = 0; minutes = 0; seconds = 0; tenths = 0;
        } else {
            int total = msec / 100;
            hours = total / 36000;
            int rem = total - hours * 36000;
            minutes = rem / 600;
            rem = rem - minutes * 600;
            seconds = rem / 10;
            tenths = rem - seconds * 10;
        }
        if (hours) {
            return va("%i:%02i:%02i.%i", hours, minutes, seconds, tenths);
        } else {
            return va("%i:%02i.%i", minutes, seconds, tenths);
        }
    } else {
        /* Seconds resolution */
        if (msec < 0) {
            hours = 0; minutes = 0; seconds = 0;
        } else {
            int total = msec / 1000;
            hours = total / 3600;
            int rem = total - hours * 3600;
            minutes = rem / 60;
            seconds = rem - minutes * 60;
        }
        if (hours) {
            return va("%i:%02i:%02i", hours, minutes, seconds);
        } else {
            return va("%i:%02i", minutes, seconds);
        }
    }
}

/* Helper: get width dimension with scale interpolation */
static float CG_GetWidth(const hudelem_t *elem, float fontHeight) {
    float width = CG_GetDimValue(elem->width, fontHeight);
    int scaleTime = elem->scaleTime;
    if (scaleTime > 0) {
        int serverTime = cg_time();
        int elapsed = serverTime - elem->scaleStartTime;
        if (scaleTime > elapsed) {
            float toWidth = CG_GetDimValue(elem->fromWidth, fontHeight);
            float lerp = (float)elapsed / (float)scaleTime;
            lerp = clamp01(lerp);
            width = (width - toWidth) * lerp + toWidth;
        }
    }
    return width;
}

/* Helper: get height dimension with scale interpolation */
static float CG_GetHeight(const hudelem_t *elem, float fontHeight) {
    float height = CG_GetDimValue(elem->height, fontHeight);
    int scaleTime = elem->scaleTime;
    if (scaleTime > 0) {
        int serverTime = cg_time();
        int elapsed = serverTime - elem->scaleStartTime;
        if (scaleTime > elapsed) {
            float toHeight = CG_GetDimValue(elem->fromHeight, fontHeight);
            float lerp = (float)elapsed / (float)scaleTime;
            lerp = clamp01(lerp);
            height = (height - toHeight) * lerp + toHeight;
        }
    }
    return height;
}

/* line 522 */
static void CG_DrawHudElemString(const char *text, const hudelem_t *elem, cg_hudelem_t *cghe)
{
    if (!text || !text[0] || !cghe->font) {
        return;
    }

    float negHeight = -(cghe->height - cghe->fontHeight);

    /* Compute move lerp factor for Y position */
    float moveLerp = CG_GetMoveLerpFactor(elem);
    float yPos;
    if (moveLerp == 1.0f) {
        yPos = cghe->y;
        yPos = CG_AlignY(elem->alignOrg, yPos, negHeight);
    } else {
        /* Interpolate between from and current aligned positions */
        float fromY = cghe->y;
        float toY = cghe->y;

        /* Align from position */
        int fromYAlign = elem->fromAlignOrg & 3;
        if (fromYAlign == 1)
            fromY = fromY + negHeight * -0.5f;
        else if (fromYAlign == 2)
            fromY = fromY - negHeight;

        /* Align current position */
        int yAlign = elem->alignOrg & 3;
        if (yAlign == 1)
            toY = toY + negHeight * -0.5f;
        else if (yAlign == 2)
            toY = toY - negHeight;

        yPos = (toY - fromY) * moveLerp + fromY;
    }

    float scaleX, scaleY;
    float scale = CL_NormalizedTextScale(cghe->font, cghe->fontScale);
    scaleX = scale;
    scaleY = scale;

    /* CalcScreenPlacement for scale */
    float dummyX = 0.0f;
    float dummyY = 0.0f;
    int alignScreen = elem->alignScreen;
    CalcScreenPlacement(&dummyX, &dummyY, &scaleX, &scaleY, alignScreen & 7, (alignScreen >> 3) & 7);

    /* CalcScreenPlacement for position offset */
    float dx = 0.0f;
    float dy = cghe->fontHeight;
    CalcScreenPlacement(&dummyX, &dummyY, &dx, &dy, alignScreen & 7, (alignScreen >> 3) & 7);

    /* Draw the text */
    CL_DrawTextPhysical(text, 0x7fffffff, cghe->font, cghe->x, yPos + dy, scaleX, scaleY, &cghe->color, 3);
}

/* line 399 */
static void CG_GetHudElemInfo(const hudelem_t *elem, cg_hudelem_t *cghe, char *hudElemString)
{
    const char *strResult;
    int fontIndex;

    /* Font setup based on elem->font (offset 0x14) */
    cghe->font = 0;
    cghe->fontHeight = 0.0f;

    switch (elem->font) {
        case 0:
            cghe->fontScale = 0.25f * elem->fontScale;
            fontIndex = 0;
            break;
        case 1:
            cghe->fontScale = 0.5f * elem->fontScale;
            fontIndex = 4;
            break;
        case 2:
            cghe->fontScale = 0.3333333f * elem->fontScale;
            fontIndex = 5;
            break;
        default:
            cghe->fontScale = 0.25f * elem->fontScale;
            fontIndex = 0;
            break;
    }
    cghe->font = UI_GetFontHandle(fontIndex, cghe->fontScale);
    if (!cghe->font && fontIndex != 0) {
        cghe->font = UI_GetFontHandle(0, cghe->fontScale);
    }
    if (cghe->font) {
        cghe->fontHeight = (float)UI_TextHeight(cghe->font, cghe->fontScale);
    }

    cghe->hudElemLabel[0] = 0;

    /* Handle label */
    if (elem->label) {
        CG_SafeTranslateHudElemString(elem->label, cghe->hudElemLabel);
    }

    /* Handle text field for hudElemText */
    cghe->hudElemText[0] = 0;
    strResult = NULL;

    switch (elem->type) {
        case HE_TYPE_TEXT:
            /* elem->text at 0x74 is a localized string ref */
            if (elem->text) {
                CG_SafeTranslateHudElemString(elem->text, cghe->hudElemText);
            }
            break;
        case HE_TYPE_VALUE: {
            /* Format the float value */
            double val = (double)elem->value;
            strResult = va("%g", val);
            break;
        }
        case HE_TYPE_PLAYERNAME: {
            /* Look up player name from clientinfo array */
            int idx = (int)(floorf(elem->value + 0.5f));
            if (idx > 63)
                break;
            /* clientinfo array: snap + 0xe0920, stride 1208 per entry */
            char *snap = cg_snap();
            I_strncpyz(cghe->hudElemText, (char *)snap + 0xe0920 + idx * 1208, 256);
            break;
        }
        case HE_TYPE_MAPNAME:
            strResult = CL_GetConfigString(0x14);
            break;
        case HE_TYPE_GAMETYPE:
            strResult = CL_GetConfigString(0x13);
            break;
        case HE_TYPE_MATERIAL:
            break;
        case HE_TYPE_TIMER_DOWN:
        case HE_TYPE_TIMER_UP:
            strResult = CG_FormatTimerString(elem, 0);
            break;
        case HE_TYPE_TENTHS_TIMER_DOWN:
        case HE_TYPE_TENTHS_TIMER_UP:
            strResult = CG_FormatTimerString(elem, 1);
            break;
        case HE_TYPE_CLOCK_DOWN:
        case HE_TYPE_CLOCK_UP:
            strResult = CG_FormatTimerString(elem, 0);
            break;
        default:
            break;
    }

    if (strResult) {
        I_strncpyz(cghe->hudElemText, strResult, 256);
    }

    /* Process label+text combination */
    if (cghe->hudElemLabel[0] && cghe->hudElemText[0]) {
        /* Combine label and text with &&1 replacement */
        int outIdx = 0;
        int labelIdx = 0;

        while (outIdx < 255) {
            char ch = cghe->hudElemLabel[labelIdx];
            if (ch == 0)
                break;
            if (ch == '&') {
                if (cghe->hudElemLabel[labelIdx + 1] == '&' && cghe->hudElemLabel[labelIdx + 2] == '1') {
                    labelIdx += 3;
                    break;
                }
            }
            hudElemString[outIdx++] = ch;
            labelIdx++;
        }

        /* Append hudElemText */
        if (outIdx <= 254) {
            int textIdx = 0;
            while (outIdx < 255 && cghe->hudElemText[textIdx]) {
                hudElemString[outIdx++] = cghe->hudElemText[textIdx++];
            }
        }

        /* Append rest of label after &&1 */
        if (outIdx <= 254) {
            while (outIdx < 255 && cghe->hudElemLabel[labelIdx]) {
                hudElemString[outIdx++] = cghe->hudElemLabel[labelIdx++];
            }
        }

        if (outIdx > 255) outIdx = 255;
        hudElemString[outIdx] = 0;

        /* Copy back to hudElemText */
        memcpy(cghe->hudElemText, hudElemString, 256);

        /* Compute text width */
        cghe->textWidth = (float)UI_TextWidth(cghe->hudElemText, 0, cghe->font, cghe->fontScale);
        cghe->hudElemLabel[0] = 0;
        cghe->labelWidth = 0.0f;
    } else if (cghe->hudElemLabel[0] && !cghe->hudElemText[0]) {
        /* Only label, no text - compute label width for labelWidth field */
        cghe->labelWidth = (float)UI_TextWidth(cghe->hudElemLabel, 0, cghe->font, cghe->fontScale);
    }

    cghe->labelWidth = 0.0f;

    /* Compute text width if text exists */
    if (cghe->hudElemText[0]) {
        cghe->textWidth = (float)UI_TextWidth(cghe->hudElemText, 0, cghe->font, cghe->fontScale);
    } else {
        cghe->textWidth = 0.0f;
    }

    /* Compute elem width (cghe->width at offset 0x0C) */
    {
        int typeMask;
        float elemWidth = 0.0f;

        if (elem->type <= 13) {
            typeMask = 1 << elem->type;
        } else {
            typeMask = 0;
        }

        /* Types that use text width + label width */
        if (typeMask & 0x7be) {
            /* HE_TYPE_TEXT through HE_TYPE_CLOCK_UP (text-based types) */
            elemWidth = cghe->labelWidth + cghe->textWidth;
        } else if (typeMask & 0x1840) {
            /* Material / timer types with separate width logic */
            float w = CG_GetDimValue(elem->width, cghe->fontHeight);
            w = CG_GetWidth(elem, cghe->fontHeight);
            elemWidth = w + cghe->labelWidth;
        } else if (typeMask & 0x2000) {
            /* WAYPOINT */
            elemWidth = 0.0f;
        } else if (typeMask & 0x2040) {
            /* Types using direct height value */
            elemWidth = (float)elem->height;
        } else if (typeMask & 0x1800) {
            /* CLOCK types with height interpolation */
            float h = CG_GetDimValue(elem->height, cghe->fontHeight);
            float hResult = h;
            int scaleTime = elem->scaleTime;
            if (scaleTime > 0) {
                int serverTime = cg_time();
                int elapsed = serverTime - elem->scaleStartTime;
                if (scaleTime > elapsed) {
                    float toH = CG_GetDimValue(elem->fromHeight, cghe->fontHeight);
                    float lerp = (float)elapsed / (float)scaleTime;
                    lerp = clamp01(lerp);
                    hResult = (h - toH) * lerp + toH;
                }
            }
            elemWidth = hResult;  /* intentional: height used as width for these types */
        } else {
            elemWidth = 0.0f;
        }

        cghe->width = elemWidth;
    }

    /* Compute elem height */
    {
        int typeMask;
        float elemHeight = 0.0f;

        if (elem->type <= 13) {
            typeMask = 1 << elem->type;
        } else {
            typeMask = 0;
        }

        if (typeMask & 0x7be) {
            /* Text-based types: height = max(fontHeight, fontHeight) */
            elemHeight = cghe->fontHeight;
            if (cghe->fontHeight > elemHeight)
                elemHeight = cghe->fontHeight;
        } else if (typeMask & 0x2040) {
            /* Types using height value from elem */
            elemHeight = (float)elem->height;
        } else if (typeMask & 0x1800) {
            /* CLOCK types: interpolated height */
            float h = CG_GetDimValue(elem->height, cghe->fontHeight);
            float hResult = h;
            int scaleTime = elem->scaleTime;
            if (scaleTime > 0) {
                int serverTime = cg_time();
                int elapsed = serverTime - elem->scaleStartTime;
                if (scaleTime > elapsed) {
                    float toH = CG_GetDimValue(elem->fromHeight, cghe->fontHeight);
                    float lerp = (float)elapsed / (float)scaleTime;
                    lerp = clamp01(lerp);
                    hResult = (h - toH) * lerp + toH;
                }
            }
            elemHeight = hResult;
        } else {
            elemHeight = 0.0f;
        }

        cghe->height = elemHeight;
    }

    /* Set Z from elem */
    cghe->z = elem->z;

    /* Compute screen position with alignment and placement */
    {
        float moveLerp = CG_GetMoveLerpFactor(elem);

        if (moveLerp == 1.0f) {
            /* No move interpolation needed */
            float x = elem->x;
            float y = elem->y;
            float width = cghe->width;
            float height = cghe->height;

            x = CG_AlignX(elem->alignOrg, x, width);
            y = CG_AlignY(elem->alignOrg, y, height);

            cghe->x = x;
            cghe->y = y;

            float dummyWidth = 0.0f;
            float dummyHeight = 0.0f;
            int alignScreen = elem->alignScreen;
            CalcScreenPlacement(&cghe->x, &cghe->y, &dummyWidth, &dummyHeight, alignScreen & 7, (alignScreen >> 3) & 7);
        } else {
            /* Move interpolation: compute from and to positions */
            float width = cghe->width;
            float height = cghe->height;

            /* "from" position */
            float fromX = elem->fromX;
            float fromY = elem->fromY;
            fromX = CG_AlignX(elem->fromAlignOrg, fromX, width);
            fromY = CG_AlignY(elem->fromAlignOrg, fromY, height);

            float dummyWidth = 0.0f;
            float dummyHeight = 0.0f;
            int fromAlignScreen = elem->fromAlignScreen;
            CalcScreenPlacement(&fromX, &fromY, &dummyWidth, &dummyHeight, fromAlignScreen & 7, (fromAlignScreen >> 3) & 7);

            /* "to" position */
            float toX = elem->x;
            float toY = elem->y;
            toX = CG_AlignX(elem->alignOrg, toX, width);
            toY = CG_AlignY(elem->alignOrg, toY, height);

            dummyWidth = 0.0f;
            dummyHeight = 0.0f;
            int alignScreen = elem->alignScreen;
            CalcScreenPlacement(&toX, &toY, &dummyWidth, &dummyHeight, alignScreen & 7, (alignScreen >> 3) & 7);

            /* Interpolate */
            cghe->x = fromX + (toX - fromX) * moveLerp;
            cghe->y = fromY + (toY - fromY) * moveLerp;
        }

        /* Snap positions to integer pixels */
        cghe->x = (float)(int)(floorf(cghe->x + 0.5f));
        cghe->y = (float)(int)(floorf(cghe->y + 0.5f));
    }

    /* Compute color with fade interpolation */
    {
        int serverTime = cg_time();
        int fadeElapsed = serverTime - elem->fadeStartTime;
        int fadeTime = elem->fadeTime;

        if (fadeTime > 0 && fadeTime > fadeElapsed) {
            /* Interpolating color */
            float lerp;
            if (fadeElapsed <= 0) {
                lerp = 0.0f;
            } else {
                lerp = (float)fadeElapsed / (float)fadeTime;
            }

            byte *fromColor = (byte *)&elem->fromColor;
            byte *toColor = (byte *)&elem->color;

            cghe->color[0] = ((float)(int)toColor[0] + ((float)(int)fromColor[0] - (float)(int)toColor[0]) * lerp) * (1.0f / 255.0f);
            cghe->color[1] = ((float)(int)toColor[1] + ((float)(int)fromColor[1] - (float)(int)toColor[1]) * lerp) * (1.0f / 255.0f);
            cghe->color[2] = ((float)(int)toColor[2] + ((float)(int)fromColor[2] - (float)(int)toColor[2]) * lerp) * (1.0f / 255.0f);
            cghe->color[3] = ((float)(int)toColor[3] + ((float)(int)fromColor[3] - (float)(int)toColor[3]) * lerp) * (1.0f / 255.0f);
        } else {
            /* No fade - use current color directly */
            byte *color = (byte *)&elem->color;
            cghe->color[0] = (float)(int)color[0] * (1.0f / 255.0f);
            cghe->color[1] = (float)(int)color[1] * (1.0f / 255.0f);
            cghe->color[2] = (float)(int)color[2] * (1.0f / 255.0f);
            cghe->color[3] = (float)(int)color[3] * (1.0f / 255.0f);
        }
    }
}

/* line 780 */
void CG_Draw2dHudElems(qboolean foreground)
{
    hudelem_t *elems[64];
    cg_hudelem_t cghe;
    char hudElemString[256];
    int elemCount;
    int i;

    /* Collect elements */
    char *snap = cg_snap();
    elemCount = 0;

    /* First loop: team-specific elems (at snap+0xC, check type at snap+0xC+0x1728) */
    byte *elemBase = (byte *)snap + 0x0C;
    byte *elemPtr = elemBase;
    byte *endPtr = (byte *)snap + 0x0C + 0x1734;

    for (i = 0; i < 31; i++) {
        if (*(int *)(elemPtr + 0x1728) != 0) { /* TODO: unknown offset */
            elems[elemCount++] = (hudelem_t *)endPtr;
            endPtr += 0x80;
            elemPtr += 0x80;
        } else {
            break;
        }
    }

    /* Second loop: global elems (at snap+0xC+0x7a8) */
    byte *globalBase = elemBase + 0x7a8;
    byte *globalPtr = elemBase;
    for (i = 0; i < 31; i++) {
        if (*(int *)globalBase != 0) {
            elems[elemCount++] = (hudelem_t *)globalBase;
            globalBase += 0x80;
            globalPtr += 0x80;
        } else {
            break;
        }
    }

    qsort(elems, elemCount, 4, (int (*)(const void *, const void *))compare_hudelems);

    if (elemCount <= 0)
        return;

    for (i = 0; i < elemCount; i++) {
        hudelem_t *elem = elems[i];

        /* Check foreground flag matches */
        if (elem->foreground != foreground)
            continue;

        /* Skip waypoint type for 2D */
        if (elem->type == HE_TYPE_WAYPOINT)
            continue;

        /* Get HUD elem info */
        CG_GetHudElemInfo(elem, &cghe, hudElemString);

        /* Check alpha is non-zero */
        if (cghe.color[3] == 0.0f)
            continue;

        /* Draw label if present */
        if (cghe.hudElemLabel[0]) {
            CG_DrawHudElemString(cghe.hudElemLabel, elem, &cghe);
            cghe.x += cghe.labelWidth;
        }

        /* Handle drawing based on type */
        if (elem->type <= 12) {
            int typeMask = 1 << elem->type;

            if (typeMask & 0x7be) {
                /* Text-based types */
                if (cghe.hudElemText[0]) {
                    CG_DrawHudElemString(cghe.hudElemText, elem, &cghe);
                }
            } else if (typeMask & 0x40) {
                /* HE_TYPE_MATERIAL */
                char materialName[64];
                if (!CG_ServerMaterialName(elem->materialIndex, materialName, 64))
                    continue;
                void *material = CL_RegisterMaterial(materialName, 7);

                float width = CG_GetWidth(elem, cghe.fontHeight);
                float height = CG_GetHeight(elem, cghe.fontHeight);
                float negHeight = -(cghe.height - height);

                /* Compute move lerp for Y */
                float moveLerp = CG_GetMoveLerpFactor(elem);
                float yPos;
                if (moveLerp == 1.0f) {
                    yPos = cghe.y;
                    yPos = CG_AlignY(elem->alignOrg, yPos, negHeight);
                } else {
                    float fromY = cghe.y;
                    float toY = cghe.y;
                    int fromYAlign = elem->fromAlignOrg & 3;
                    if (fromYAlign == 1) fromY += negHeight * -0.5f;
                    else if (fromYAlign == 2) fromY -= negHeight;
                    int yAlign = elem->alignOrg & 3;
                    if (yAlign == 1) toY += negHeight * -0.5f;
                    else if (yAlign == 2) toY -= negHeight;
                    yPos = (toY - fromY) * moveLerp + fromY;
                }

                /* CalcScreenPlacement */
                float dummyX = 0.0f;
                float dummyY = 0.0f;
                int alignScreen = elem->alignScreen;
                CalcScreenPlacement(&dummyX, &dummyY, &width, &height, alignScreen & 7, (alignScreen >> 3) & 7);

                CL_DrawStretchPicPhysical(cghe.x, yPos, width, height, 0.0f, 0.0f, 1.0f, 1.0f, &cghe.color, material);
            } else if (typeMask & 0x1800) {
                /* HE_TYPE_CLOCK_DOWN, HE_TYPE_CLOCK_UP - compass/clock material */
                char materialName[64];
                if (!CG_ServerMaterialName(elem->materialIndex, materialName, 58))
                    continue;

                void *faceMaterial = CL_RegisterMaterialNoMip(materialName, 7);
                I_strncat(materialName, 64, "_hand");
                void *handMaterial = CL_RegisterMaterialNoMip(materialName, 7);

                /* Compute time and angle */
                float timeVal = 0.0f;
                int serverTime = cg_time();
                int msec;

                switch (elem->type) {
                    case HE_TYPE_TIMER_DOWN:
                    case HE_TYPE_TENTHS_TIMER_DOWN:
                        msec = elem->time - serverTime + 999;
                        if (msec >= 0) timeVal = (float)msec;
                        break;
                    case HE_TYPE_CLOCK_DOWN:
                        msec = elem->time - serverTime + 99;
                        if (msec >= 0) timeVal = (float)msec;
                        break;
                    case HE_TYPE_TIMER_UP:
                    case HE_TYPE_TENTHS_TIMER_UP:
                        msec = serverTime - elem->time;
                        if (msec >= 0) timeVal = (float)msec;
                        break;
                    case HE_TYPE_CLOCK_UP:
                        msec = serverTime - elem->time;
                        if (msec >= 0) timeVal = (float)msec;
                        break;
                    default:
                        break;
                }

                float angle;
                if (elem->duration != 0) {
                    angle = AngleNormalize360(timeVal * 360.0f / (float)elem->duration);
                } else {
                    angle = AngleNormalize360(timeVal * 0.006f);
                }

                float width = CG_GetWidth(elem, cghe.fontHeight);
                float height = CG_GetHeight(elem, cghe.fontHeight);
                float negHeight = -(cghe.height - height);

                /* Compute move lerp for Y */
                float moveLerp2 = CG_GetMoveLerpFactor(elem);
                float yPos2;
                if (moveLerp2 == 1.0f) {
                    yPos2 = cghe.y;
                    yPos2 = CG_AlignY(elem->alignOrg, yPos2, negHeight);
                } else {
                    float fromY = cghe.y;
                    float toY = cghe.y;
                    int fromYAlign = elem->fromAlignOrg & 3;
                    if (fromYAlign == 1) fromY += negHeight * -0.5f;
                    else if (fromYAlign == 2) fromY -= negHeight;
                    int yAlign = elem->alignOrg & 3;
                    if (yAlign == 1) toY += negHeight * -0.5f;
                    else if (yAlign == 2) toY -= negHeight;
                    yPos2 = (toY - fromY) * moveLerp2 + fromY;
                }

                /* CalcScreenPlacement */
                float dummyY2 = 0.0f;
                float dummyW = 0.0f;
                int alignScreen2 = elem->alignScreen;
                CalcScreenPlacement(&dummyY2, &dummyW, &width, &height, alignScreen2 & 7, (alignScreen2 >> 3) & 7);

                /* Draw face */
                CL_DrawStretchPicPhysical(cghe.x, yPos2, width, height, 0.0f, 0.0f, 1.0f, 1.0f, &cghe.color, faceMaterial);

                /* Draw hand with rotation */
                CG_DrawRotatedPicPhysical(cghe.x, yPos2, width, height, angle, &cghe.color, handMaterial);
            }
        }
    }

    return;
}

/* line 806 */
void CG_Draw3dHudElems(void)
{
    hudelem_t *elems[64];
    cg_hudelem_t cghe;
    char hudElemString[256];
    int elemCount;
    int i;

    /* Check if HUD elems are hidden */
    if (CG_AreHudElemsHidden())
        return;

    /* Collect elements */
    char *snap = cg_snap();
    elemCount = 0;

    byte *elemBase = (byte *)snap + 0x0C;
    byte *elemPtr = elemBase;
    byte *endPtr = (byte *)snap + 0x0C + 0x1734;

    for (i = 0; i < 31; i++) {
        if (*(int *)(elemPtr + 0x1728) != 0) { /* TODO: unknown offset */
            elems[elemCount++] = (hudelem_t *)endPtr;
            endPtr += 0x80;
            elemPtr += 0x80;
        } else {
            break;
        }
    }

    byte *globalBase = elemBase + 0x7a8;
    byte *globalPtr = elemBase;
    for (i = 0; i < 31; i++) {
        if (*(int *)globalBase != 0) {
            elems[elemCount++] = (hudelem_t *)globalBase;
            globalBase += 0x80;
            globalPtr += 0x80;
        } else {
            break;
        }
    }

    qsort(elems, elemCount, 4, (int (*)(const void *, const void *))compare_hudelems);

    if (elemCount <= 0)
        return;

    for (i = 0; i < elemCount; i++) {
        hudelem_t *elem = elems[i];

        /* Only process waypoint type for 3D */
        if (elem->type != HE_TYPE_WAYPOINT)
            continue;

        CG_GetHudElemInfo(elem, &cghe, hudElemString);

        /* Draw label if present */
        if (cghe.hudElemLabel[0]) {
            CG_DrawHudElemString(cghe.hudElemLabel, elem, &cghe);
            cghe.x += cghe.labelWidth;
        }

        /* Only process waypoint type */
        if (elem->type != HE_TYPE_WAYPOINT)
            continue;

        /* Check alpha byte (renderFxFlags at elem color byte 3) */
        byte *colorBytes = (byte *)&elem->color;
        if (colorBytes[3] == 0)
            continue;

        /* Get material */
        char materialName[64];
        if (!CG_ServerMaterialName(elem->materialIndex, materialName, 64))
            continue;

        void *material = CL_RegisterMaterial(materialName, 7);

        /* Get height with interpolation */
        float height = CG_GetHeight(elem, cghe.fontHeight);

        /* Check height is non-zero */
        if (height == 0.0f)
            continue;

        /* Get position from elem */
        vec3_t pos;
        pos[0] = elem->x;
        pos[1] = elem->y;
        pos[2] = elem->z;

        /* Compute alpha */
        float alpha = (float)(int)colorBytes[3] / 255.0f;

        /* Check if value > 0 for distance-scaled size */
        int renderFxFlags = 0;
        if (elem->value > 0.0f) {
            height *= 0.0043f;
            renderFxFlags = 0x3000;
        }

        /* Set RGBA color */
        byte rgbaColor[4];
        rgbaColor[0] = 0xFF;
        rgbaColor[1] = 0xFF;
        rgbaColor[2] = 0xFF;
        rgbaColor[3] = (byte)(int)(floorf(alpha * 255.0f + 0.5f));

        CL_DrawSprite(material, rgbaColor, height, pos, 0.0f, renderFxFlags);
    }

    return;
}
