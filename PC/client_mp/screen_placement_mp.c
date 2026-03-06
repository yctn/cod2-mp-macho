/* Decompiled from: screen_placement_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/screen_placement_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdio.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static struct ScreenPlacementGlob spGlob; /* spGlob */

extern byte *cls_ptr_195ecac; /* imp_cls - pointer to clientStatic_t */

/* vidConfig field offsets within clientStatic_t */
#define CLS_VIDCONFIG_WIDTH(base) (*(int *)((base) + 0x2a0a64))
#define CLS_VIDCONFIG_HEIGHT(base) (*(int *)((base) + 0x2a0a68))
#define CLS_VIDCONFIG_ASPECT_RATIO_PIXEL(base) (*(float *)((base) + 0x2a0a78))

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
    return width * spGlob.scaleVirtualToReal[0];
}

/* line 147 */
float GetRealHeightFromVirtualHeight(float height)
{
    return height * spGlob.scaleVirtualToReal[1];
}

/* line 153 */
float GetVirtualWidthFromRealWidth(float width)
{
    return width * spGlob.scaleRealToVirtual[0];
}

/* line 159 */
float GetVirtualHeightFromRealHeight(float height)
{
    return height * spGlob.scaleRealToVirtual[1];
}

/* line 165 */
void CalcScreenX(float *x, int horzAlign)
{
    switch (horzAlign) {
    default:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.subScreenLeft + spGlob.virtualScreenOffsetX;
        break;
    case 1:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.realViewableMin[0];
        break;
    case 2:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.realViewportSize[0] * 0.5f;
        break;
    case 3:
        *x = *x * spGlob.scaleVirtualToReal[0] + (spGlob.realViewableMin[0] + spGlob.realViewableMax[0]) * 0.5f;
        break;
    case 4:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.realViewableMax[0];
        break;
    case 5:
        *x *= spGlob.scaleVirtualToFull[0];
        break;
    case 6:
    case 7:
        *x = *x * spGlob.scaleRealToVirtual[0] + spGlob.virtualScreenOffsetX;
        break;
    }
}

/* line 200 */
void CalcScreenY(float *y, int vertAlign)
{
    switch (vertAlign) {
    default:
        *y *= spGlob.scaleVirtualToReal[1];
        break;
    case 1:
        *y = *y * spGlob.scaleVirtualToReal[1] + spGlob.realViewableMin[1];
        break;
    case 2:
        *y = *y * spGlob.scaleVirtualToReal[1] + spGlob.realViewportSize[1] * 0.5f;
        break;
    case 3:
        *y = *y * spGlob.scaleVirtualToReal[1] + (spGlob.realViewableMin[1] + spGlob.realViewableMax[1]) * 0.5f;
        break;
    case 4:
        *y = *y * spGlob.scaleVirtualToReal[1] + spGlob.realViewableMax[1];
        break;
    case 5:
        *y *= spGlob.scaleVirtualToFull[1];
        break;
    case 6:
    case 7:
        *y *= spGlob.scaleRealToVirtual[1];
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
    {
        static int ssc_count = 0;
        fprintf(stderr, "SetScreenScaling[%d]: safe=(%f,%f) vp=(%d,%d,%d,%d) ra=%p\n",
                ssc_count++, safeAreaRatioHorizontal, safeAreaRatioVertical,
                viewportX, viewportY, viewportWidth, viewportHeight,
                __builtin_return_address(0));
    }
    float fViewportHeight = (float)viewportHeight;
    float fViewportWidth = (float)viewportWidth;
    float fViewportY = (float)viewportY;
    float fViewportX = (float)viewportX;

    spGlob.realViewportSize[0] = fViewportWidth;
    spGlob.realViewportSize[1] = fViewportHeight;

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

    spGlob.realViewableMin[0] = safeLeft - fViewportX;
    spGlob.realViewableMin[1] = safeTop - fViewportY;
    spGlob.realViewableMax[0] = clampedRight - fViewportX;
    spGlob.realViewableMax[1] = clampedBottom - fViewportY;

    spGlob.virtualViewableMin[0] = horzAspectScale * spGlob.realViewableMin[0] * (640.0f / fViewportWidth);
    spGlob.virtualViewableMin[1] = spGlob.realViewableMin[1] * (480.0f / fViewportHeight);
    spGlob.virtualViewableMax[0] = horzAspectScale * spGlob.realViewableMax[0] * (640.0f / fViewportWidth);
    spGlob.virtualViewableMax[1] = spGlob.realViewableMax[1] * (480.0f / fViewportHeight);

    float scaleY = fViewportHeight / 480.0f;

    spGlob.scaleVirtualToReal[0] = adjustedRealWidth / 640.0f;
    spGlob.scaleVirtualToReal[1] = scaleY;

    spGlob.scaleVirtualToFull[0] = fViewportWidth / 640.0f;
    spGlob.scaleVirtualToFull[1] = scaleY;

    spGlob.scaleRealToVirtual[0] = 640.0f / adjustedRealWidth;
    spGlob.scaleRealToVirtual[1] = 480.0f / fViewportHeight;

    spGlob.subScreenLeft = 0.5f * horzAspectPixelDiff;
    spGlob.virtualScreenOffsetX = 640.0f - adjustedRealWidth * spGlob.scaleRealToVirtual[0];
    fprintf(stderr, "  result: scaleVToR={%f,%f} scaleVToF={%f,%f} scaleRToV={%f,%f} subLeft=%f vscreenOfsX=%f spGlob@%p\n",
           spGlob.scaleVirtualToReal[0], spGlob.scaleVirtualToReal[1],
           spGlob.scaleVirtualToFull[0], spGlob.scaleVirtualToFull[1],
           spGlob.scaleRealToVirtual[0], spGlob.scaleRealToVirtual[1],
           spGlob.subScreenLeft, spGlob.virtualScreenOffsetX, &spGlob);
}

/* line 285 */
void CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign)
{
    switch (horzAlign) {
    default:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.subScreenLeft + spGlob.virtualScreenOffsetX;
        *w *= spGlob.scaleVirtualToReal[0];
        break;
    case 1:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.realViewableMin[0];
        *w *= spGlob.scaleVirtualToReal[0];
        break;
    case 2:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.realViewportSize[0] * 0.5f;
        *w *= spGlob.scaleVirtualToReal[0];
        break;
    case 3:
        *x = *x * spGlob.scaleVirtualToReal[0] + (spGlob.realViewableMin[0] + spGlob.realViewableMax[0]) * 0.5f;
        *w *= spGlob.scaleVirtualToReal[0];
        break;
    case 4:
        *x = *x * spGlob.scaleVirtualToReal[0] + spGlob.realViewableMax[0];
        *w *= spGlob.scaleVirtualToReal[0];
        break;
    case 5:
        *x *= spGlob.scaleVirtualToFull[0];
        *w *= spGlob.scaleVirtualToFull[0];
        break;
    case 6:
    case 7:
        *x = *x * spGlob.scaleRealToVirtual[0] + spGlob.virtualScreenOffsetX;
        *w *= spGlob.scaleRealToVirtual[0];
        break;
    }

    switch (vertAlign) {
    default:
        *y *= spGlob.scaleVirtualToReal[1];
        *h *= spGlob.scaleVirtualToReal[1];
        break;
    case 1:
        *y = *y * spGlob.scaleVirtualToReal[1] + spGlob.realViewableMin[1];
        *h *= spGlob.scaleVirtualToReal[1];
        break;
    case 2:
        *y = *y * spGlob.scaleVirtualToReal[1] + spGlob.realViewportSize[1] * 0.5f;
        *h *= spGlob.scaleVirtualToReal[1];
        break;
    case 3:
        *y = *y * spGlob.scaleVirtualToReal[1] + (spGlob.realViewableMin[1] + spGlob.realViewableMax[1]) * 0.5f;
        *h *= spGlob.scaleVirtualToReal[1];
        break;
    case 4:
        *y = *y * spGlob.scaleVirtualToReal[1] + spGlob.realViewableMax[1];
        *h *= spGlob.scaleVirtualToReal[1];
        break;
    case 5:
        *y *= spGlob.scaleVirtualToFull[1];
        *h *= spGlob.scaleVirtualToFull[1];
        break;
    case 6:
    case 7:
        *y *= spGlob.scaleRealToVirtual[1];
        *h *= spGlob.scaleRealToVirtual[1];
        break;
    }
}
