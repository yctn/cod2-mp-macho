/* Decompiled from: r_water_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_water_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern void *Material_Alloc(int size);
extern void GaussianRandom(float *real, float *imag);
extern GfxImage *R_CreateWaterMap(const char *name, int M, int N);
extern const char *va(const char *fmt, ...);
#ifndef __EMSCRIPTEN__
extern void *memcpy(void *dest, const void *src, unsigned int n);
#endif
extern double exp(double x);
extern float fabsf(float x);
extern float sqrtf(float x);

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

qboolean R_WatersEquivalent(const water_t *w0, const water_t *w1)
{
    float dot, mag0_sq, mag1_sq, denom, cosAngle;

    /* Compare integer fields M and N */
    if (w0->M != w1->M)
        return 0;
    if (w0->N != w1->N)
        return 0;

    /* Compare float fields Lx and Lz exactly */
    if (w0->Lx != w1->Lx)
        return 0;
    if (w0->Lz != w1->Lz)
        return 0;

    /* Compare amplitude with absolute tolerance 0.001 */
    if (fabsf(w0->amplitude - w1->amplitude) > 0.001f)
        return 0;

    /* Compare gravity with absolute tolerance 0.1 (double precision) */
    if ((double)fabsf(w0->gravity - w1->gravity) > 0.1)
        return 0;

    /* Compare windvel with absolute tolerance 0.1 (double precision) */
    if ((double)fabsf(w0->windvel - w1->windvel) > 0.1)
        return 0;

    /* Direction vector cosine angle check:
     * Compute dot(d0, d1) / sqrt(|d0|^2 * |d1|^2 + 1e-10)
     * and check that result is within 0.001 of 1.0 */
    dot = w0->winddir[0] * w1->winddir[0] + w0->winddir[1] * w1->winddir[1];

    mag0_sq = w0->winddir[0] * w0->winddir[0] + w0->winddir[1] * w0->winddir[1];
    mag1_sq = w1->winddir[0] * w1->winddir[0] + w1->winddir[1] * w1->winddir[1];

    denom = (float)((double)sqrtf(mag0_sq * mag1_sq) + 1e-10);
    cosAngle = dot / denom;

    if (fabsf(cosAngle - 1.0f) > 0.001f)
        return 0;

    return 1;
}

void R_CreateWaterSetup(const water_t *source, int waterMapSetupIndex, water_t *destination)
{
    int elementCount;
    int n, m, i;
    int N, M;
    float n_scale, m_scale;
    float kx, ky;
    float k_sq, k, omega_sq;
    float dot;
    float E_real, E_imag;
    float L; /* Phillips spectrum peak: windvel^4 / gravity */
    float coeff;
    double Ph;
    const char *name;

    elementCount = source->M * source->N;

    /* Copy entire water_t struct */
    memcpy(destination, source, 0x44);

    /* Allocate complex amplitude array (elementCount * sizeof(complex_t)) */
    destination->H0 = (complex_t *)Material_Alloc(elementCount * 8);

    /* Allocate omega frequency array (elementCount * sizeof(float)) */
    destination->wTerm = (float *)Material_Alloc(elementCount * 4);

    N = destination->N;
    M = destination->M;

    /* L = windvel^4 / gravity (Phillips spectrum parameter) */
    L = destination->windvel * destination->windvel;
    L = L * L;
    L = L / destination->gravity;

    /* Wave number scale factors: 2*PI / (dimension * spacing) */
    n_scale = (float)(2.0 * M_PI / ((double)((float)N * destination->Lx)));
    m_scale = (float)(2.0 * M_PI / ((double)((float)M * destination->Lz)));

    i = 0;
    for (n = -(N / 2); n < N / 2; n++)
    {
        kx = (float)n * n_scale;

        for (m = -(M / 2); m < M / 2; m++)
        {
            ky = (float)m * m_scale;

            /* Get Gaussian random numbers for this frequency */
            GaussianRandom(&E_real, &E_imag);

            /* Compute wave number magnitude */
            k_sq = kx * kx + ky * ky;
            k = sqrtf(k_sq);

            /* Dispersion relation: omega^2 = k * gravity */
            omega_sq = k * destination->gravity;

            /* Wind direction dot product */
            dot = kx * destination->winddir[0] + ky * destination->winddir[1];

            if (dot > 0.0f)
            {
                /* Phillips spectrum computation */
                Ph = (double)destination->amplitude * exp((double)(-1.0f / (k_sq * L)));
                Ph = Ph / (double)(k_sq * k_sq * k_sq);
                Ph = Ph * (double)(dot * dot);

                coeff = destination->amplitude * sqrtf((float)Ph * 0.5f);

                /* Store complex amplitude H0[i] = coeff * GaussianRandom */
                destination->H0[i].real = coeff * E_real;
                destination->H0[i].imag = coeff * E_imag;

                /* Store angular frequency */
                destination->wTerm[i] = sqrtf(omega_sq);
            }
            else
            {
                /* No contribution when wind is against wave direction */
                destination->H0[i].real = 0.0f;
                destination->H0[i].imag = 0.0f;
                destination->wTerm[i] = 0.0f;
            }

            i++;
        }
    }

    /* Create the water map texture */
    name = va("watersetup%i", waterMapSetupIndex);
    destination->image = R_CreateWaterMap(name, (unsigned short)source->M, (unsigned short)source->N);
}
