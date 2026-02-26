/* ASM dump from: com_convexhull.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_convexhull.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern vec_t Vec2Normalize(vec_t *v);

static void SwapVec2(vec2_t a, vec2_t b)
{
    float tmp0 = a[0];
    float tmp1 = a[1];
    a[0] = b[0];
    a[1] = b[1];
    b[0] = tmp0;
    b[1] = tmp1;
}

/*
 * Quickhull subdivision: given an edge of the hull (hull[hullIdx1] to hull[hullIdx2]),
 * find the farthest point on the positive side, insert it into the hull, and recurse.
 *
 * points: array of candidate points (modified in-place via swaps)
 * numPoints: number of candidate points to search (indices 0..numPoints-1)
 * hullIdx1: hull index of first edge endpoint
 * hullIdx2: hull index of second edge endpoint
 * hull: the hull point array
 * hullPointCount: current number of points in the hull
 *
 * Returns: updated hullPointCount
 */
static int Com_RecursivelyGrowHull(vec2_t *points, int numPoints, int hullIdx1, int hullIdx2, vec2_t *hull, int hullPointCount)
{
    vec2_t edgeEq;
    float dist;
    int topIndex;
    int botIndex;
    int frontIndex;
    float maxDist;
    int newIndex;

    /* Compute outward-pointing edge normal */
    edgeEq[0] = hull[hullIdx1][1] - hull[hullIdx2][1];
    edgeEq[1] = hull[hullIdx2][0] - hull[hullIdx1][0];
    Vec2Normalize(edgeEq);

    /* Distance of the edge from origin along the normal */
    dist = edgeEq[0] * hull[hullIdx1][0] + edgeEq[1] * hull[hullIdx1][1];

    topIndex = numPoints - 1;
    if (topIndex < 0) {
        return hullPointCount;
    }

    botIndex = 0;
    maxDist = 0.001f;
    frontIndex = -1;

    /* Partition points: search from bottom up for positive-side points,
     * from top down for negative-side points, and find the farthest positive point */
    while (botIndex <= topIndex) {
        float d;

        /* Scan from bottom looking for positive-side (front) points */
        while (botIndex <= topIndex) {
            d = edgeEq[0] * points[botIndex][0] + edgeEq[1] * points[botIndex][1] - dist;

            if (d <= 0.0f) {
                /* Point is behind the edge; scan from top instead */
                goto scan_top;
            }

            if (d > maxDist) {
                maxDist = d;
                frontIndex = botIndex;
            }
            botIndex++;
        }
        break;

    scan_top:
        /* Scan from top looking for negative-side (back) points to swap with bottom */
        while (topIndex >= botIndex) {
            d = edgeEq[0] * points[topIndex][0] + edgeEq[1] * points[topIndex][1] - dist;

            if (d > 0.0f) {
                /* Point is in front; check if it's the new farthest */
                if (d > maxDist) {
                    maxDist = d;
                    frontIndex = botIndex;
                }
                /* Swap points[botIndex] and points[topIndex] */
                if (botIndex != topIndex) {
                    SwapVec2(points[botIndex], points[topIndex]);
                }
                botIndex++;
                topIndex--;
                break;
            }

            /* Point is behind; just decrement top */
            topIndex--;
        }
    }

    /* After partitioning, topIndex is the last front-side point index */
    if (frontIndex < 0) {
        return hullPointCount;
    }

    /* Swap the farthest point to the end of the front partition */
    if (frontIndex != topIndex) {
        SwapVec2(points[frontIndex], points[topIndex]);
    }

    /* Insert points[topIndex] into the hull after hullIdx1 */
    newIndex = hullIdx1 + 1;

    /* Shift hull points to make room */
    memmove(&hull[newIndex + 1], &hull[newIndex], (hullPointCount - newIndex) * sizeof(vec2_t));

    /* Copy the new point into the hull */
    hull[newIndex][0] = points[topIndex][0];
    hull[newIndex][1] = points[topIndex][1];
    hullPointCount++;

    if (topIndex == 0) {
        return hullPointCount;
    }

    /* Determine the second hull index for the first recursive call.
     * If hullIdx2 was 0, it stays 0 (wrapping); otherwise it shifts by insertion. */
    if (hullIdx2 != 0) {
        hullIdx2 = hullIdx1 + 2;
    }

    /* Recurse on the edge from newIndex to hullIdx2 */
    hullPointCount = Com_RecursivelyGrowHull(points, topIndex, newIndex, hullIdx2, hull, hullPointCount);

    /* Recurse on the edge from hullIdx1 to newIndex */
    hullPointCount = Com_RecursivelyGrowHull(points, topIndex, hullIdx1, newIndex, hull, hullPointCount);

    return hullPointCount;
}

/* line 285 */
int Com_ConvexHull(vec2_t *points, int pointCount, vec2_t *hull)
{
    int topIdx, botIdx;
    int pointIndex1;
    int hullPointCount;
    vec2_t edgeEq;
    float dist;
    int frontIndex, backIndex;
    float maxFrontDist, maxBackDist;
    int i;
    int remainingCount;
    int insertIdx;

    topIdx = 0;
    botIdx = 0;

    if (pointCount > 1) {
        /* Find the topmost (min Y) and bottommost (max Y) points */
        int j;
        for (j = 1; j < pointCount; j++) {
            if (points[j][1] >= points[botIdx][1]) {
                botIdx = j;
            }
            if (points[j][1] < points[topIdx][1]) {
                topIdx = j;
            }
        }
    }

    /* hull[0] = top point (highest Y), hull[1] = bottom point (lowest Y) */
    hull[0][0] = points[topIdx][0];
    hull[0][1] = points[topIdx][1];
    hull[1][0] = points[botIdx][0];
    hull[1][1] = points[botIdx][1];

    if (topIdx > botIdx) {
        /* Swap top point to points[pointCount-1] */
        pointIndex1 = pointCount - 1;
        if (topIdx != pointIndex1) {
            SwapVec2(points[topIdx], points[pointIndex1]);
        }

        /* Swap bottom point to points[pointCount-2] */
        pointIndex1 = pointCount - 2;
        if (botIdx != pointIndex1) {
            SwapVec2(points[botIdx], points[pointIndex1]);
        }
    } else {
        /* botIdx >= topIdx: swap bottom first, then top */
        pointIndex1 = pointCount - 1;
        if (botIdx != pointIndex1) {
            SwapVec2(points[botIdx], points[pointIndex1]);
        }

        pointIndex1 = pointCount - 2;
        if (topIdx != pointIndex1) {
            SwapVec2(points[topIdx], points[pointIndex1]);
        }
    }

    remainingCount = pointCount - 2;

    /* Compute edge normal from hull[1] to hull[0] */
    edgeEq[0] = hull[1][1] - hull[0][1];
    edgeEq[1] = hull[0][0] - hull[1][0];
    Vec2Normalize(edgeEq);

    dist = edgeEq[0] * hull[0][0] + edgeEq[1] * hull[0][1];

    i = pointCount - 3;
    if (i < 0) {
        hullPointCount = 0;
        goto done;
    }

    {
        int botScan = 0;
        maxFrontDist = 0.001f;
        frontIndex = -1;
        maxBackDist = -0.001f;
        backIndex = -1;

        /* Search for farthest front and back points */
        while (botScan <= i) {
            float d;

            /* Scan from bottom */
            while (botScan <= i) {
                d = edgeEq[0] * points[botScan][0] + edgeEq[1] * points[botScan][1] - dist;

                if (d < 0.0f) {
                    /* Negative side: check if this is the farthest back point */
                    if (d < maxBackDist) {
                        backIndex = botScan;
                        maxBackDist = d;
                    }
                    /* Scan from top */
                    goto convex_scan_top;
                }

                if (d > maxFrontDist) {
                    maxFrontDist = d;
                    frontIndex = botScan;
                }
                botScan++;
            }
            break;

        convex_scan_top:

            /* Scan from top */
            while (i >= botScan) {
                d = edgeEq[0] * points[i][0] + edgeEq[1] * points[i][1] - dist;

                if (d > 0.0f) {
                    /* Front side point found at top */
                    if (d > maxFrontDist) {
                        maxFrontDist = d;
                        frontIndex = botScan;
                    }
                    /* Swap with bottom point */
                    if (botScan != i) {
                        SwapVec2(points[botScan], points[i]);
                    }
                    /* Update backIndex if it was at botScan */
                    if (backIndex == botScan) {
                        backIndex = i;
                    }
                    botScan++;
                    i--;
                    break;
                }

                /* Back side: check if farthest */
                if (d < maxBackDist) {
                    maxBackDist = d;
                    backIndex = i;
                }
                i--;
            }
        }

        /* frontIndex >= 0: there's a front-side point */
        if (frontIndex < 0) {
            /* No front point found; check for back point only */
            if (backIndex < 0) {
                hullPointCount = 0;
                goto done;
            }
            /* No front point, but there is a back point.
             * Hull currently has [top, bottom, top_copy], 3 points.
             * Insert back point at hull[1], shifting 1 element. */
            hullPointCount = 3;
            insertIdx = 1;
            goto handle_back_only;
        }

        /* Swap frontIndex to points[i] (end of front partition) */
        if (frontIndex != i) {
            SwapVec2(points[frontIndex], points[i]);
        }

        /* hull[2] = the farthest front point */
        hull[2][0] = points[i][0];
        hull[2][1] = points[i][1];

        if (i <= 0) {
            hullPointCount = 3;
        } else {
            /* Recursively grow hull on the upper side:
             * Edge from hull[0] to hull[2] (indices 0 and 2) */
            hullPointCount = Com_RecursivelyGrowHull(points, i, 2, 0, hull, 3);

            /* Edge from hull[2] to hull[1] (index 2 shifted, and 1) */
            hullPointCount = Com_RecursivelyGrowHull(points, i, 1, 2, hull, hullPointCount);
        }

        /* Handle back-side point */
        if (backIndex < 0) {
            goto done;
        }

        /* Insert back point into hull at position 1, shifting existing hull[1..] right */
        insertIdx = hullPointCount - 1;
        hullPointCount++;

    handle_back_only:
        /* Swap backIndex to points[botScan] if needed */
        if (backIndex != botScan) {
            SwapVec2(points[backIndex], points[botScan]);
        }

        /* Insert into hull: shift hull[1..] right by 1, put backPoint at hull[1] */
        memmove(&hull[2], &hull[1], insertIdx * sizeof(vec2_t));
        hull[1][0] = points[botScan][0];
        hull[1][1] = points[botScan][1];

        /* Adjust remaining point count */
        remainingCount -= botScan;
        remainingCount--;

        if (remainingCount <= 0) {
            goto done;
        }

        {
            vec2_t *backPoints = &points[botScan + 1];

            /* Recurse on the lower hull edges */
            hullPointCount = Com_RecursivelyGrowHull(backPoints, remainingCount, 1, 2, hull, hullPointCount);
            hullPointCount = Com_RecursivelyGrowHull(backPoints, remainingCount, 0, 1, hull, hullPointCount);
        }
    }

done:
    return hullPointCount;
}
