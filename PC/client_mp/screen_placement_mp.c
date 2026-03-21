/* Decompiled from: screen_placement_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/screen_placement_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern unsigned char spGlob[]; /* spGlob - global BSS, not static */
#define SP ((struct ScreenPlacementGlob *)spGlob)

extern byte *cls_ptr_195ecac; /* imp_cls - pointer to clientStatic_t */

/* vidConfig field offsets within clientStatic_t */
#define CLS_VIDCONFIG_WIDTH(base) (((clientStatic_t *)(base))->vidConfig.width)
#define CLS_VIDCONFIG_HEIGHT(base) (((clientStatic_t *)(base))->vidConfig.height)
#define CLS_VIDCONFIG_ASPECT_RATIO_PIXEL(base) (((clientStatic_t *)(base))->vidConfig.aspectRatioPixel)

float GetRealWidthFromVirtualWidth(float width);
float GetRealHeightFromVirtualHeight(float height);
float GetVirtualWidthFromRealWidth(float width);
float GetVirtualHeightFromRealHeight(float height);
void CalcScreenX(float *x, int horzAlign);
void CalcScreenY(float *y, int vertAlign);
void CalcSplitScreenTextOffset(FontHandle font, float *y);
void SetScreenScaling(float safeAreaRatioHorizontal, float safeAreaRatioVertical, int viewportX, int viewportY, int viewportWidth, int viewportHeight);
void CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign);

/* line 141 */
float GetRealWidthFromVirtualWidth(float width)
{
    return width * SP->scaleVirtualToReal[0];
}

/* line 147 */
float GetRealHeightFromVirtualHeight(float height)
{
    return height * SP->scaleVirtualToReal[1];
}

/* line 153 */
float GetVirtualWidthFromRealWidth(float width)
{
    return width * SP->scaleRealToVirtual[0];
}

/* line 159 */
float GetVirtualHeightFromRealHeight(float height)
{
    return height * SP->scaleRealToVirtual[1];
}

/* line 165 */
/* Alignment values from menudefinition.h:
 * 0 = SUBLEFT       (4:3 left edge, no safe area)
 * 1 = LEFT          (safe area left edge)
 * 2 = CENTER        (viewport center)
 * 3 = RIGHT         (safe area right edge)
 * 4 = FULLSCREEN    (full viewport, ignore safe area)
 * 5 = NOSCALE       (exact pixels, no scaling)
 * 6 = TO640         (scale real coords into 0-640 range)
 * 7 = CENTER_SAFEAREA (center of safe area)
 */
void CalcScreenX(float *x, int horzAlign)
{
    switch (horzAlign) {
    default:
        *x = *x * SP->scaleVirtualToReal[0] + SP->subScreenLeft;
        break;
    case 1:
        *x = *x * SP->scaleVirtualToReal[0] + SP->realViewableMin[0];
        break;
    case 2:
        *x = *x * SP->scaleVirtualToReal[0] + SP->realViewportSize[0] * 0.5f;
        break;
    case 3:
        *x = *x * SP->scaleVirtualToReal[0] + SP->realViewableMax[0];
        break;
    case 4:
        *x *= SP->scaleVirtualToFull[0];
        break;
    case 5:
        break;
    case 6:
        *x = *x * SP->scaleRealToVirtual[0] + SP->virtualScreenOffsetX;
        break;
    case 7:
        *x = *x * SP->scaleVirtualToReal[0] + (SP->realViewableMin[0] + SP->realViewableMax[0]) * 0.5f;
        break;
    }
}

/* line 200 */
void CalcScreenY(float *y, int vertAlign)
{
    switch (vertAlign) {
    default:
        *y *= SP->scaleVirtualToReal[1];
        break;
    case 1:
        *y = *y * SP->scaleVirtualToReal[1] + SP->realViewableMin[1];
        break;
    case 2:
        *y = *y * SP->scaleVirtualToReal[1] + SP->realViewportSize[1] * 0.5f;
        break;
    case 3:
        *y = *y * SP->scaleVirtualToReal[1] + SP->realViewableMax[1];
        break;
    case 4:
        *y *= SP->scaleVirtualToFull[1];
        break;
    case 5:
        break;
    case 6:
        *y *= SP->scaleRealToVirtual[1];
        break;
    case 7:
        *y = *y * SP->scaleVirtualToReal[1] + (SP->realViewableMin[1] + SP->realViewableMax[1]) * 0.5f;
        break;
    }
}

/* line 235 */
void CalcSplitScreenTextOffset(FontHandle font, float *y)
{
    /* Empty function - split screen text offset not used on PC */
}

/* line 135 */
void SetScreenScaling(float safeAreaRatioHorizontal, float safeAreaRatioVertical,
                       int viewportX, int viewportY, int viewportWidth, int viewportHeight)
{
    float fViewportHeight = (float)viewportHeight;
    float fViewportWidth = (float)viewportWidth;
    float fViewportY = (float)viewportY;
    float fViewportX = (float)viewportX;

    SP->realViewportSize[0] = fViewportWidth;
    SP->realViewportSize[1] = fViewportHeight;

    byte *cls = cls_ptr_195ecac;
    float adjustedRealWidth = fViewportHeight * 1.3333333f / CLS_VIDCONFIG_ASPECT_RATIO_PIXEL(cls);
    float horzAspectPixelDiff = fViewportWidth - adjustedRealWidth;
    float horzAspectScale = fViewportWidth / adjustedRealWidth;

    float displayWidth = (float)CLS_VIDCONFIG_WIDTH(cls);
    float displayHeight = (float)CLS_VIDCONFIG_HEIGHT(cls);

    float unsafeHorz = (1.0f - safeAreaRatioHorizontal) * 0.5f * displayWidth;
    float unsafeVert = (1.0f - safeAreaRatioVertical) * 0.5f * displayHeight;

    float safeRight = displayWidth - unsafeHorz;
    float safeBottom = displayHeight - unsafeVert;

    float safeLeft = (fViewportX - unsafeHorz >= 0) ? fViewportX : unsafeHorz;
    float safeTop = (fViewportY - unsafeVert >= 0) ? fViewportY : unsafeVert;
    float clampedRight = (safeRight - (fViewportX + fViewportWidth) >= 0) ? (fViewportX + fViewportWidth) : safeRight;
    float clampedBottom = (safeBottom - (fViewportY + fViewportHeight) >= 0) ? (fViewportY + fViewportHeight) : safeBottom;

    SP->realViewableMin[0] = safeLeft - fViewportX;
    SP->realViewableMin[1] = safeTop - fViewportY;
    SP->realViewableMax[0] = clampedRight - fViewportX;
    SP->realViewableMax[1] = clampedBottom - fViewportY;

    SP->virtualViewableMin[0] = horzAspectScale * SP->realViewableMin[0] * (640.0f / fViewportWidth);
    SP->virtualViewableMin[1] = SP->realViewableMin[1] * (480.0f / fViewportHeight);
    SP->virtualViewableMax[0] = horzAspectScale * SP->realViewableMax[0] * (640.0f / fViewportWidth);
    SP->virtualViewableMax[1] = SP->realViewableMax[1] * (480.0f / fViewportHeight);

    float scaleY = fViewportHeight / 480.0f;

    SP->scaleVirtualToReal[0] = adjustedRealWidth / 640.0f;
    SP->scaleVirtualToReal[1] = scaleY;

    SP->scaleVirtualToFull[0] = fViewportWidth / 640.0f;
    SP->scaleVirtualToFull[1] = scaleY;

    SP->scaleRealToVirtual[0] = 640.0f / adjustedRealWidth;
    SP->scaleRealToVirtual[1] = 480.0f / fViewportHeight;

    SP->subScreenLeft = 0.5f * horzAspectPixelDiff;
    SP->virtualScreenOffsetX = 640.0f - adjustedRealWidth * SP->scaleRealToVirtual[0];

}


/* line 285 */
void CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign)
{
    switch (horzAlign) {
    default:
        *x = *x * SP->scaleVirtualToReal[0] + SP->subScreenLeft;
        *w *= SP->scaleVirtualToReal[0];
        break;
    case 1:
        *x = *x * SP->scaleVirtualToReal[0] + SP->realViewableMin[0];
        *w *= SP->scaleVirtualToReal[0];
        break;
    case 2:
        *x = *x * SP->scaleVirtualToReal[0] + SP->realViewportSize[0] * 0.5f;
        *w *= SP->scaleVirtualToReal[0];
        break;
    case 3:
        *x = *x * SP->scaleVirtualToReal[0] + SP->realViewableMax[0];
        *w *= SP->scaleVirtualToReal[0];
        break;
    case 4:
        *x *= SP->scaleVirtualToFull[0];
        *w *= SP->scaleVirtualToFull[0];
        break;
    case 5:
        break;
    case 6:
        *x = *x * SP->scaleRealToVirtual[0] + SP->virtualScreenOffsetX;
        *w *= SP->scaleRealToVirtual[0];
        break;
    case 7:
        *x = *x * SP->scaleVirtualToReal[0] + (SP->realViewableMin[0] + SP->realViewableMax[0]) * 0.5f;
        *w *= SP->scaleVirtualToReal[0];
        break;
    }

    switch (vertAlign) {
    default:
        *y *= SP->scaleVirtualToReal[1];
        *h *= SP->scaleVirtualToReal[1];
        break;
    case 1:
        *y = *y * SP->scaleVirtualToReal[1] + SP->realViewableMin[1];
        *h *= SP->scaleVirtualToReal[1];
        break;
    case 2:
        *y = *y * SP->scaleVirtualToReal[1] + SP->realViewportSize[1] * 0.5f;
        *h *= SP->scaleVirtualToReal[1];
        break;
    case 3:
        *y = *y * SP->scaleVirtualToReal[1] + SP->realViewableMax[1];
        *h *= SP->scaleVirtualToReal[1];
        break;
    case 4:
        *y *= SP->scaleVirtualToFull[1];
        *h *= SP->scaleVirtualToFull[1];
        break;
    case 5:
        break;
    case 6:
        *y *= SP->scaleRealToVirtual[1];
        *h *= SP->scaleRealToVirtual[1];
        break;
    case 7:
        *y = *y * SP->scaleVirtualToReal[1] + (SP->realViewableMin[1] + SP->realViewableMax[1]) * 0.5f;
        *h *= SP->scaleVirtualToReal[1];
        break;
    }
}
