/* ASM dump from: com_math.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_math.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/com_math.h"
 */

extern vec3_t bytedirs[162]; /* 0x0 */
extern vec2_t vec2_origin; /* 0x0 */
extern vec3_t vec3_origin; /* 0x0 */
extern const float identityMatrix44[4][4]; /* 0x0 */
static long unsigned int holdrand; /* 0x308b58 */

const qboolean VecNCompareCustomEpsilon(const vec_t *v0, const vec_t *v1, vec_t epsilon, int coordCount);
float randomf(void);
float GraphGetValueFromFraction(const int knotCount, vec2_t *knots, const float fraction);
const float Q_acos(const float c);
const signed char ClampChar(const int i);
const vec_t Vec2DistanceSq(const vec_t *p1, const vec_t *p2);
jpeg_alloc Vec3Cross(const vec_t *v0, const vec_t *v1, vec_t *cross);
jpeg_alloc Vec3RotateTranspose(const vec_t *in, vec3_t *matrix, vec_t *out);
jpeg_alloc MatrixMultiply(const float (*in1)[3], const float (*in2)[3], float (*out)[3]);
const float vectoyaw(const vec_t *vec);
const float vectosignedyaw(const vec_t *vec);
float PointToBoxDistSq(const vec_t *pt, const vec_t *mins, const vec_t *maxs);
jpeg_alloc MatrixIdentity44(float (*out)[4]);
jpeg_alloc MatrixSet44(float (*out)[4], const vec_t *origin, vec3_t *axis, vec_t scale);
jpeg_alloc MatrixMultiply43(const float (*in1)[3], const float (*in2)[3], float (*out)[3]);
jpeg_alloc MatrixMultiply44(const float (*in1)[4], const float (*in2)[4], float (*out)[4]);
jpeg_alloc MatrixTranspose(const float (*in)[3], float (*out)[3]);
jpeg_alloc MatrixTranspose44(const float *in, float *out);
jpeg_alloc MatrixInverse(const float (*in)[3], float (*out)[3]);
jpeg_alloc MatrixTransformVector(const float *in1, const float (*in2)[3], float *out);
jpeg_alloc MatrixInverse44(const float *mat, float *dst);
jpeg_alloc MatrixTransformVector44(const float *vec, const float (*mat)[4], float *out);
jpeg_alloc MatrixTransposeTransformVector(const float *in1, const float (*in2)[3], float *out);
jpeg_alloc MatrixTransformVector43(const float *in1, const float (*in2)[3], float *out);
jpeg_alloc QuatMultiply(const float *in1, const float *in2, float *out);
jpeg_alloc QuatToAxis(const vec_t *quat, double (*axis)[16]);
float RotationToYaw(const vec_t *rot);
jpeg_alloc InfinitePerspectiveMatrix(float (*mtx)[4], float fov_x, float fov_y, float zNear);
jpeg_alloc MatrixForViewer(float (*mtx)[4], const vec_t *origin, vec3_t *axis);
const float AngleMod(const float a);
const float LerpAngle(const float from, const float to, const float frac);
const float AngleSubtract(const float a1, const float a2);
const float AngleNormalize360(const float angle);
const float AngleNormalize360Accurate(float angle);
const float AngleNormalize180Accurate(float angle);
jpeg_alloc AddPointToBounds(const vec_t *v, vec_t *mins, vec_t *maxs);
jpeg_alloc ExpandBounds(const vec_t *addedmins, const vec_t *addedmaxs, vec_t *mins, vec_t *maxs);
jpeg_alloc AxisTransformVector(vec3_t *axes, const vec_t x, const vec_t y, const vec_t z, vec_t *out);
jpeg_alloc ProjectPointOnPlane(const vec_t *p, const vec_t *normal, vec_t *dst);
const int BoxOnPlaneSide(const vec_t *emins, const vec_t *emaxs, const cplane_s *p);
jpeg_alloc Rand_Init(int seed);
float flrand(float min, float max);
int irand(int min, int max);
jpeg_alloc MatrixTransformVectorQuatTrans(const vec_t *in, const DObjAnimMat *mat, vec_t *out);
float DiffTrack(float tgt, float cur, float rate, float deltaTime);
const vec_t RadiusFromBounds2D(const vec_t *mins, const vec_t *maxs);
jpeg_alloc ByteToDir(const int b, vec_t *dir);
jpeg_alloc AxisCopy(vec3_t *in, double (*out)[16]);
const vec_t Vec3DistanceSq(const vec_t *p1, const vec_t *p2);
jpeg_alloc MatrixTransposeTransformVector43(const float *in1, const float (*in2)[3], float *out);
jpeg_alloc ExpandBoundsToWidth(vec_t *mins, vec_t *maxs);
jpeg_alloc ShrinkBoundsToHeight(vec_t *mins, vec_t *maxs);
qboolean BoxDistSqrdExceeds(const vec_t *absmin, const vec_t *absmax, const vec_t *org, const float fogOpaqueDistSqrd);
const byte DirToByte(const vec_t *dir);
jpeg_alloc GetRotatedBounds(vec3_t *baseBounds, const vec_t *origin, vec3_t *axis, double (*rotatedBounds)[16]);
const vec_t ColorNormalize(const vec_t *in, vec_t *out);
jpeg_alloc ClearBounds(vec_t *mins, vec_t *maxs);
const vec_t Vec3Normalize(vec_t *v);
const vec_t Vec2Normalize(vec_t *v);
const float vectopitch(const vec_t *vec);
jpeg_alloc vectoangles(const vec_t *vec, vec_t *angles);
const vec_t RadiusFromBounds(const vec_t *mins, const vec_t *maxs);
jpeg_alloc AnglesSubtract(const vec_t *v1, const vec_t *v2, vec_t *v3);
const vec_t Vec3NormalizeTo(const vec_t *v, vec_t *out);
int Vec3MajorAxis(const vec_t *dir);
const float AngleNormalize180(const float angle);
const float AngleDelta(const float angle1, const float angle2);
const vec_t Vec3Distance(const vec_t *v1, const vec_t *v2);
float DiffTrackAngle(float tgt, float cur, float rate, float deltaTime, float f, float granularity, float epsilon);
float crandom(void);
jpeg_alloc GaussianRandom(float *f0, float *f1);
jpeg_alloc MatrixInverseOrthogonal43(const float (*in)[3], float (*out)[3]);
qboolean WindingContainsCoplanarPoint(vec3_t *verts, int vertCount, const vec_t *normal, const vec_t *point);
jpeg_alloc MakeNormalVectors(const vec_t *forward, vec_t *right, vec_t *up);
jpeg_alloc PerpendicularVector(const vec_t *src, vec_t *dst);
float PitchForYawOnNormal(const float fYaw, const vec_t *normal);
jpeg_alloc YawToAxis(float yaw, double (*axis)[16]);
jpeg_alloc RotatePointAroundVector(vec_t *dst, const vec_t *dir, const vec_t *point, const float degrees);
jpeg_alloc AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
jpeg_alloc AnglesToAxis(const vec_t *angles, double (*axis)[16]);
jpeg_alloc YawVectors(const vec_t yaw, vec_t *forward, vec_t *right);
jpeg_alloc VectorAngleMultiply(vec_t *vec, float angle);
jpeg_alloc AngleAxisToQuat(float angle, const vec_t *axis, vec_t *quat);
jpeg_alloc AxisToAngles(double (*axis)[16], vec_t *angles);

/* line 611 */
__attribute__((naked))
const qboolean VecNCompareCustomEpsilon(const vec_t *v0, const vec_t *v1, vec_t epsilon, int coordCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 611 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* v0 */
        "movl 0xc(%ebp), %ecx\n" /* v1 */
        "movss 0x10(%ebp), %xmm1\n" /* epsilon */
        "movl 0x14(%ebp), %edx\n" /* coordCount */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 615 */
        "jle .Lf2a354_0002a3a0\n"
        "movss (%ebx), %xmm0\n" /* line 617 | v0 */
        "subss (%ecx), %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf2a354_0002a39b\n"
        "xorl %eax, %eax\n"
        ".Lf2a354_0002a381:\n"
        "addl $1, %eax\n" /* line 615 */
        "cmpl %eax, %edx\n"
        "je .Lf2a354_0002a3a0\n"
        "movss (%ebx, %eax, 4), %xmm0\n" /* line 617 | v0 */
        "subss (%ecx, %eax, 4), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2a354_0002a381\n"
        ".Lf2a354_0002a39b:\n"
        "xorl %eax, %eax\n" /* line 615 */
        /* } scope */
        "popl %ebx\n" /* line 622 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a354_0002a3a0:\n"
        "movl $1, %eax\n" /* line 615 */
        /* } scope */
        "popl %ebx\n" /* line 622 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 141 */
__attribute__((naked))
float randomf(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 141 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll rand\n" /* line 144 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed630, %xmm0\n" /* 4.656612873077393e-10f */
        "movss %xmm0, -0xc(%ebp)\n" /* line 145 */
        "flds -0xc(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 449 */
__attribute__((naked))
float GraphGetValueFromFraction(const int knotCount, vec2_t *knots, const float fraction)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 449 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* knots */
        "movss 0x10(%ebp), %xmm3\n" /* fraction */
        /* { scope 1 */
        "cmpl $1, 8(%ebp)\n" /* line 459 | knotCount */
        "jle .Lf2a3ca_0002a419\n"
        "leal 8(%edi), %esi\n" /* line 461 | knots */
        "movss 8(%edi), %xmm0\n" /* knots */
        "ucomiss %xmm3, %xmm0\n"
        "jae .Lf2a3ca_0002a431\n"
        "leal 0x10(%edi), %ebx\n" /* knots */
        "movl $1, %ecx\n"
        "movl $0x10, %eax\n"
        "jmp .Lf2a3ca_0002a411\n"
        ".Lf2a3ca_0002a3fd:\n"
        "leal (%edi, %eax), %edx\n" /* line 459 | knots */
        "movl %edx, %esi\n"
        "movss (%ebx), %xmm0\n" /* line 461 */
        "addl $8, %eax\n"
        "addl $8, %ebx\n"
        "ucomiss %xmm3, %xmm0\n"
        "jae .Lf2a3ca_0002a433\n"
        ".Lf2a3ca_0002a411:\n"
        "addl $1, %ecx\n" /* line 459 */
        "cmpl %ecx, 8(%ebp)\n" /* knotCount */
        "jne .Lf2a3ca_0002a3fd\n"
        ".Lf2a3ca_0002a419:\n"
        "movss 0x2ed5dc, %xmm3\n" /* -1.0f */
        /* } scope */
        "movss %xmm3, -0x10(%ebp)\n" /* line 476 */
        "flds -0x10(%ebp)\n"
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2a3ca_0002a431:\n"
        "movl %esi, %edx\n"
        /* { scope 1 */
        ".Lf2a3ca_0002a433:\n"
        "movss -8(%edx), %xmm1\n" /* line 463 */
        "movss -4(%edx), %xmm2\n" /* line 469 */
        "subss %xmm1, %xmm3\n"
        "movss (%esi), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "movss 4(%esi), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        /* } scope */
        "movss %xmm3, -0x10(%ebp)\n" /* line 476 */
        "flds -0x10(%ebp)\n"
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 510 */
__attribute__((naked))
const float Q_acos(const float c)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 510 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 514 | c */
        "movl %eax, (%esp)\n"
        "calll acosf\n"
        "fsts -0xc(%ebp)\n" /* line 516 */
        "movss -0xc(%ebp), %xmm1\n"
        "cvtss2sd %xmm1, %xmm0\n"
        "ucomisd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "ja .Lf2a470_0002a4a3\n"
        "ucomisd 0x307c30, %xmm0\n" /* line 520 | -3.141592653589793 */
        "jae .Lf2a470_0002a4ab\n"
        "jp .Lf2a470_0002a4ab\n"
        ".Lf2a470_0002a4a3:\n"
        "fstp %st(0)\n"
        "flds 0x2ed634\n" /* 3.1415927410125732f */
        /* } scope */
        ".Lf2a470_0002a4ab:\n"
        "leave\n" /* line 525 */
        "retl\n"
    );
}

/* line 535 */
__attribute__((naked))
const signed char ClampChar(const int i)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 535 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* i */
        "cmpl $-0x80, %eax\n" /* line 537 */
        "jl .Lf2a4ae_0002a4ca\n"
        "cmpl $0x7f, %eax\n" /* line 540 */
        "jg .Lf2a4ae_0002a4c3\n"
        "movsbl %al, %eax\n" /* line 543 */
        "popl %ebp\n" /* line 544 */
        "retl\n"
        ".Lf2a4ae_0002a4c3:\n"
        "movl $0x7f, %eax\n" /* line 540 */
        "popl %ebp\n" /* line 544 */
        "retl\n"
        ".Lf2a4ae_0002a4ca:\n"
        "movl $0xffffff80, %eax\n" /* line 537 */
        "popl %ebp\n" /* line 544 */
        "retl\n"
    );
}

/* line 697 */
__attribute__((naked))
const vec_t Vec2DistanceSq(const vec_t *p1, const vec_t *p2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 697 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edx\n" /* p1 */
        "movl 0xc(%ebp), %eax\n" /* p2 */
        "movss (%eax), %xmm0\n" /* line 65 */
        "subss (%edx), %xmm0\n"
        "movss 4(%eax), %xmm1\n" /* line 66 */
        "subss 4(%edx), %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%ebp)\n" /* line 703 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 711 */
__attribute__((naked))
jpeg_alloc Vec3Cross(const vec_t *v0, const vec_t *v1, vec_t *cross)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 711 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* v0 */
        "movl 0xc(%ebp), %edx\n" /* v1 */
        "movl 0x10(%ebp), %ecx\n" /* cross */
        "movss 4(%eax), %xmm1\n" /* line 713 */
        "mulss 8(%edx), %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss 8(%eax), %xmm1\n" /* line 714 */
        "mulss (%edx), %xmm1\n"
        "movss (%eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 715 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "popl %ebp\n" /* line 716 */
        "retl\n"
    );
}

/* line 965 */
__attribute__((naked))
jpeg_alloc Vec3RotateTranspose(const vec_t *in, vec3_t *matrix, vec_t *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 965 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* in */
        "movl 0xc(%ebp), %edx\n" /* matrix */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "leal 0xc(%edx), %ebx\n" /* line 968 */
        "leal 0x18(%edx), %esi\n"
        "movss (%eax), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 969 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 970 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "popl %ebx\n" /* line 971 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1541 */
__attribute__((naked))
jpeg_alloc MatrixMultiply(const float (*in1)[3], const float (*in2)[3], float (*out)[3])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1541 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* in1 */
        "movl 0xc(%ebp), %edx\n" /* in2 */
        "movl 0x10(%ebp), %ebx\n" /* out */
        "leal 0xc(%edx), %ecx\n" /* line 1543 */
        "movl %ecx, -0x14(%ebp)\n"
        "leal 0x18(%edx), %edi\n"
        "movl %edi, -0x10(%ebp)\n"
        "movss (%eax), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* out */
        "movss (%eax), %xmm1\n" /* line 1544 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ebx)\n" /* out */
        "movss (%eax), %xmm1\n" /* line 1545 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n" /* out */
        "leal 0xc(%ebx), %esi\n" /* line 1547 | out */
        "leal 0xc(%eax), %ecx\n"
        "movss 0xc(%eax), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ebx)\n" /* out */
        "movss 0xc(%eax), %xmm1\n" /* line 1548 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x14(%ebp), %edi\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x10(%ebp), %edi\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 0xc(%eax), %xmm1\n" /* line 1549 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x14(%ebp), %edi\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x10(%ebp), %ecx\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        "leal 0x18(%ebx), %edi\n" /* line 1551 | out */
        "leal 0x18(%eax), %ecx\n"
        "movss 0x18(%eax), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x18(%ebx)\n" /* out */
        "movss 0x18(%eax), %xmm1\n" /* line 1552 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x14(%ebp), %ebx\n" /* out */
        "mulss 4(%ebx), %xmm0\n" /* out */
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x10(%ebp), %ebx\n" /* out */
        "mulss 4(%ebx), %xmm0\n" /* out */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "movss 0x18(%eax), %xmm1\n" /* line 1553 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x14(%ebp), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n" /* out */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "addl $8, %esp\n" /* line 1554 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1099 */
__attribute__((naked))
const float vectoyaw(const vec_t *vec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1099 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl 8(%ebp), %eax\n" /* vec */
        /* { scope 1 */
        "movss 4(%eax), %xmm1\n" /* line 1103 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jne .Lf2a7c2_0002a7e0\n"
        "jp .Lf2a7c2_0002a7e0\n"
        "ucomiss (%eax), %xmm2\n"
        "je .Lf2a7c2_0002a83f\n"
        ".Lf2a7c2_0002a7e0:\n"
        "cvtss2sd (%eax), %xmm0\n" /* line 1109 */
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "movss %xmm2, -0x18(%ebp)\n"
        "calll atan2\n"
        "fstpl -0x20(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "mulsd 0x307c38, %xmm0\n" /* 180.0 */
        "divsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss -0x18(%ebp), %xmm2\n" /* line 1110 */
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf2a7c2_0002a82d\n"
        /* } scope */
        "movss %xmm0, -0x24(%ebp)\n" /* line 1115 */
        "flds -0x24(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a7c2_0002a82d:\n"
        "addss 0x2ed638, %xmm0\n" /* line 1111 | 360.0f */
        /* } scope */
        "movss %xmm0, -0x24(%ebp)\n" /* line 1115 */
        "flds -0x24(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a7c2_0002a83f:\n"
        "jp .Lf2a7c2_0002a7e0\n" /* line 1103 */
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        "movss %xmm0, -0x24(%ebp)\n" /* line 1115 */
        "flds -0x24(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 1123 */
__attribute__((naked))
const float vectosignedyaw(const vec_t *vec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1123 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* vec */
        /* { scope 1 */
        "movss 4(%eax), %xmm1\n" /* line 1127 */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf2a84e_0002a86c\n"
        "jp .Lf2a84e_0002a86c\n"
        "ucomiss (%eax), %xmm0\n"
        "je .Lf2a84e_0002a8b0\n"
        ".Lf2a84e_0002a86c:\n"
        "cvtss2sd (%eax), %xmm0\n" /* line 1133 */
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "calll atan2\n"
        "fstpl -0x18(%ebp)\n"
        "movsd -0x18(%ebp), %xmm0\n"
        "mulsd 0x307c38, %xmm0\n" /* 180.0 */
        "divsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "movl -0xc(%ebp), %eax\n"
        /* } scope */
        "movl %eax, -0xc(%ebp)\n" /* line 1140 */
        "flds -0xc(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a84e_0002a8b0:\n"
        "jp .Lf2a84e_0002a86c\n" /* line 1127 */
        "movss %xmm0, -0xc(%ebp)\n" /* line 1133 */
        "movl -0xc(%ebp), %eax\n"
        /* } scope */
        "movl %eax, -0xc(%ebp)\n" /* line 1140 */
        "flds -0xc(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 1459 */
__attribute__((naked))
float PointToBoxDistSq(const vec_t *pt, const vec_t *mins, const vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1459 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pt */
        "movl 0xc(%ebp), %ecx\n" /* mins */
        "pxor %xmm2, %xmm2\n"
        "movl $1, %edx\n"
        "movaps %xmm2, %xmm3\n"
        ".Lf2a8c2_0002a8dc:\n"
        "leal (, %edx, 4), %eax\n"
        /* { scope 1 */
        "movss -4(%ebx, %eax), %xmm1\n" /* line 1468 | pt */
        "movss -4(%ecx, %eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n" /* line 1469 */
        "jbe .Lf2a8c2_0002a917\n"
        ".Lf2a8c2_0002a8f8:\n"
        "mulss %xmm0, %xmm0\n" /* line 1477 */
        "addss %xmm0, %xmm2\n"
        ".Lf2a8c2_0002a900:\n"
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 1466 */
        "jne .Lf2a8c2_0002a8dc\n"
        /* } scope */
        "movss %xmm2, -0xc(%ebp)\n" /* line 1481 */
        "flds -0xc(%ebp)\n"
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a8c2_0002a917:\n"
        "movaps %xmm1, %xmm0\n" /* line 1475 */
        "movl 0x10(%ebp), %esi\n" /* maxs */
        "subss -4(%eax, %esi), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n" /* line 1476 */
        "ja .Lf2a8c2_0002a8f8\n"
        "jmp .Lf2a8c2_0002a900\n"
    );
}

/* line 1505 */
__attribute__((naked))
jpeg_alloc MatrixIdentity44(float (*out)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1505 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* out */
        "movl identityMatrix44, %edx\n" /* line 1508 */
        "movl %edx, (%eax)\n"
        "movl 0x2efb24, %edx\n"
        "movl %edx, 4(%eax)\n"
        "movl 0x2efb28, %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl 0x2efb2c, %edx\n"
        "movl %edx, 0xc(%eax)\n"
        "movl 0x2efb30, %edx\n"
        "movl %edx, 0x10(%eax)\n"
        "movl 0x2efb34, %edx\n"
        "movl %edx, 0x14(%eax)\n"
        "movl 0x2efb38, %edx\n"
        "movl %edx, 0x18(%eax)\n"
        "movl 0x2efb3c, %edx\n"
        "movl %edx, 0x1c(%eax)\n"
        "movl 0x2efb40, %edx\n"
        "movl %edx, 0x20(%eax)\n"
        "movl 0x2efb44, %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "movl 0x2efb48, %edx\n"
        "movl %edx, 0x28(%eax)\n"
        "movl 0x2efb4c, %edx\n"
        "movl %edx, 0x2c(%eax)\n"
        "movl 0x2efb50, %edx\n"
        "movl %edx, 0x30(%eax)\n"
        "movl 0x2efb54, %edx\n"
        "movl %edx, 0x34(%eax)\n"
        "movl 0x2efb58, %edx\n"
        "movl %edx, 0x38(%eax)\n"
        "movl 0x2efb5c, %edx\n"
        "movl %edx, 0x3c(%eax)\n"
        "popl %ebp\n" /* line 1509 */
        "retl\n"
    );
}

/* line 1512 */
__attribute__((naked))
jpeg_alloc MatrixSet44(float (*out)[4], const vec_t *origin, vec3_t *axis, vec_t scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1512 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* out */
        "movl 0xc(%ebp), %edi\n" /* origin */
        "movl 0x10(%ebp), %eax\n" /* axis */
        "movss 0x14(%ebp), %xmm1\n" /* scale */
        "movaps %xmm1, %xmm0\n" /* line 1514 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 1515 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 1516 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "xorl %esi, %esi\n" /* line 1517 */
        "movl %esi, 0xc(%ecx)\n"
        "leal 0x10(%ecx), %edx\n" /* line 1519 */
        "leal 0xc(%eax), %ebx\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0xc(%eax), %xmm0\n"
        "movss %xmm0, 0x10(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 1520 */
        "mulss 4(%ebx), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 1521 */
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movl %esi, 0xc(%edx)\n" /* line 1522 */
        "leal 0x20(%ecx), %edx\n" /* line 1524 */
        "leal 0x18(%eax), %ebx\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, 0x20(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 1525 */
        "mulss 4(%ebx), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "mulss 8(%ebx), %xmm1\n" /* line 1526 */
        "movss %xmm1, 8(%edx)\n"
        "movl %esi, 0xc(%edx)\n" /* line 1527 */
        "leal 0x30(%ecx), %edx\n" /* line 1529 */
        "movl (%edi), %eax\n" /* origin */
        "movl %eax, 0x30(%ecx)\n"
        "movl 4(%edi), %eax\n" /* line 1530 | origin */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 1531 | origin */
        "movl %eax, 8(%edx)\n"
        "movl $0x3f800000, 0xc(%edx)\n" /* line 1532 */
        "popl %ebx\n" /* line 1533 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1621 */
__attribute__((naked))
jpeg_alloc MatrixMultiply43(const float (*in1)[3], const float (*in2)[3], float (*out)[3])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1621 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* in1 */
        "movl 0x10(%ebp), %ebx\n" /* out */
        "movl 0xc(%ebp), %eax\n" /* line 1626 | in2 */
        "addl $0xc, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %ecx\n" /* in2 */
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x18(%ebp)\n"
        "movss (%edx), %xmm1\n"
        "movl 0xc(%ebp), %esi\n" /* in2 */
        "mulss (%esi), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0xc(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x18(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* out */
        "leal 0xc(%ebx), %eax\n" /* line 1627 | out */
        "movl %eax, -0x14(%ebp)\n"
        "leal 0xc(%edx), %eax\n"
        "movss 0xc(%edx), %xmm1\n"
        "mulss (%esi), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0xc(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x18(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ebx)\n" /* out */
        "leal 0x18(%ebx), %ecx\n" /* line 1628 | out */
        "movl %ecx, -0x10(%ebp)\n"
        "leal 0x18(%edx), %ecx\n"
        "movss 0x18(%edx), %xmm1\n"
        "mulss (%esi), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0xc(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x18(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x18(%ebx)\n" /* out */
        "movss (%edx), %xmm1\n" /* line 1630 */
        "mulss 4(%esi), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x1c(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ebx)\n" /* out */
        "movss 0xc(%edx), %xmm1\n" /* line 1631 */
        "movl 0xc(%ebp), %esi\n" /* in2 */
        "mulss 4(%esi), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x1c(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x14(%ebp), %esi\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 0x18(%edx), %xmm1\n" /* line 1632 */
        "movl 0xc(%ebp), %esi\n" /* in2 */
        "mulss 4(%esi), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x1c(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x10(%ebp), %esi\n"
        "movss %xmm1, 4(%esi)\n"
        "movss (%edx), %xmm1\n" /* line 1634 */
        "movl 0xc(%ebp), %esi\n" /* in2 */
        "mulss 8(%esi), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x1c(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n" /* out */
        "movss 0xc(%edx), %xmm1\n" /* line 1635 */
        "movl 0xc(%ebp), %esi\n" /* in2 */
        "mulss 8(%esi), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x1c(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x18(%ebp), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x14(%ebp), %esi\n"
        "movss %xmm1, 8(%esi)\n"
        "movss 0x18(%edx), %xmm1\n" /* line 1636 */
        "movl 0xc(%ebp), %eax\n" /* in2 */
        "mulss 8(%eax), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x1c(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x18(%ebp), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x10(%ebp), %ecx\n"
        "movss %xmm1, 8(%ecx)\n"
        "leal 0x24(%ebx), %esi\n" /* line 1638 | out */
        "leal 0x24(%edx), %ecx\n"
        "movl 0xc(%ebp), %edi\n" /* in2 */
        "addl $0x24, %edi\n"
        "movss 0x24(%edx), %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* in2 */
        "mulss (%eax), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x24(%eax), %xmm1\n"
        "movss %xmm1, 0x24(%ebx)\n" /* out */
        "movss 0x24(%edx), %xmm1\n" /* line 1639 */
        "mulss 4(%eax), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x1c(%ebp), %eax\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x18(%ebp), %eax\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 4(%edi), %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 0x24(%edx), %xmm1\n" /* line 1640 */
        "movl 0xc(%ebp), %eax\n" /* in2 */
        "mulss 8(%eax), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "movl -0x1c(%ebp), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x18(%ebp), %ecx\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 8(%edi), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        "addl $0x10, %esp\n" /* line 1641 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1649 */
__attribute__((naked))
jpeg_alloc MatrixMultiply44(const float (*in1)[4], const float (*in2)[4], float (*out)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1649 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %edx\n" /* in1 */
        "movl 0xc(%ebp), %ecx\n" /* in2 */
        "leal 0x10(%ecx), %eax\n" /* line 1654 */
        "movl %eax, -0x18(%ebp)\n"
        "leal 0x20(%ecx), %ebx\n"
        "movl %ebx, -0x14(%ebp)\n"
        "leal 0x30(%ecx), %edi\n"
        "movss (%edx), %xmm1\n"
        "mulss (%ecx), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x10(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x20(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "mulss 0x30(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl 0x10(%ebp), %esi\n" /* out */
        "movss %xmm1, (%esi)\n"
        "movss (%edx), %xmm1\n" /* line 1655 */
        "mulss 4(%ecx), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss (%edx), %xmm1\n" /* line 1656 */
        "mulss 8(%ecx), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        "movss (%edx), %xmm1\n" /* line 1657 */
        "mulss 0xc(%ecx), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0xc(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "mulss 0xc(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esi)\n"
        "addl $0x10, %esi\n" /* line 1659 */
        "movl %esi, -0x10(%ebp)\n"
        "leal 0x10(%edx), %eax\n"
        "movss 0x10(%edx), %xmm1\n"
        "mulss (%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x10(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x20(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0x30(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl 0x10(%ebp), %ebx\n" /* out */
        "movss %xmm1, 0x10(%ebx)\n"
        "movss 0x10(%edx), %xmm1\n" /* line 1660 */
        "mulss 4(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %ebx\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x10(%ebp), %esi\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 0x10(%edx), %xmm1\n" /* line 1661 */
        "mulss 8(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %ebx\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x10(%ebp), %ebx\n"
        "movss %xmm1, 8(%ebx)\n"
        "movss 0x10(%edx), %xmm1\n" /* line 1662 */
        "mulss 0xc(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 0xc(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %ebx\n"
        "mulss 0xc(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0xc(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x10(%ebp), %esi\n"
        "movss %xmm1, 0xc(%esi)\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1664 | out */
        "addl $0x20, %ebx\n"
        "leal 0x20(%edx), %eax\n"
        "movss 0x20(%edx), %xmm1\n"
        "mulss (%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x10(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x20(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0x30(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl 0x10(%ebp), %esi\n" /* out */
        "movss %xmm1, 0x20(%esi)\n"
        "movss 0x20(%edx), %xmm1\n" /* line 1665 */
        "mulss 4(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %esi\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ebx)\n"
        "movss 0x20(%edx), %xmm1\n" /* line 1666 */
        "mulss 8(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n"
        "movss 0x20(%edx), %xmm1\n" /* line 1667 */
        "mulss 0xc(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %esi\n"
        "mulss 0xc(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %esi\n"
        "mulss 0xc(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0xc(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ebx)\n"
        "movl 0x10(%ebp), %esi\n" /* line 1669 | out */
        "addl $0x30, %esi\n"
        "leal 0x30(%edx), %eax\n"
        "movss 0x30(%edx), %xmm1\n"
        "mulss (%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x10(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x20(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0x30(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl 0x10(%ebp), %ebx\n" /* out */
        "movss %xmm1, 0x30(%ebx)\n"
        "movss 0x30(%edx), %xmm1\n" /* line 1670 */
        "mulss 4(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %ebx\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %ebx\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 0x30(%edx), %xmm1\n" /* line 1671 */
        "mulss 8(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %ebx\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x14(%ebp), %ebx\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        "movss 0x30(%edx), %xmm1\n" /* line 1672 */
        "mulss 0xc(%ecx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x18(%ebp), %edx\n"
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0xc(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0xc(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esi)\n"
        "addl $0xc, %esp\n" /* line 1673 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1681 */
__attribute__((naked))
jpeg_alloc MatrixTranspose(const float (*in)[3], float (*out)[3])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1681 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* in */
        "movl 0xc(%ebp), %ecx\n" /* out */
        "movl (%edx), %eax\n" /* line 1685 */
        "movl %eax, (%ecx)\n"
        "leal 0xc(%edx), %edi\n" /* line 1686 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "leal 0x18(%edx), %esi\n" /* line 1687 */
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "leal 0xc(%ecx), %ebx\n" /* line 1688 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%edi), %eax\n" /* line 1689 */
        "movl %eax, 4(%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 1690 */
        "movl %eax, 8(%ebx)\n"
        "leal 0x18(%ecx), %ebx\n" /* line 1691 */
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x18(%ecx)\n"
        "movl 8(%edi), %eax\n" /* line 1692 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%esi), %eax\n" /* line 1693 */
        "movl %eax, 8(%ebx)\n"
        "popl %ebx\n" /* line 1694 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1697 */
__attribute__((naked))
jpeg_alloc MatrixTranspose44(const float *in, float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1697 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* in */
        "movl 0xc(%ebp), %edx\n" /* out */
        "movl (%eax), %ecx\n" /* line 1701 */
        "movl %ecx, (%edx)\n"
        "movl 0x10(%eax), %ecx\n" /* line 1702 */
        "movl %ecx, 4(%edx)\n"
        "movl 0x20(%eax), %ecx\n" /* line 1703 */
        "movl %ecx, 8(%edx)\n"
        "movl 0x30(%eax), %ecx\n" /* line 1704 */
        "movl %ecx, 0xc(%edx)\n"
        "movl 4(%eax), %ecx\n" /* line 1705 */
        "movl %ecx, 0x10(%edx)\n"
        "movl 0x14(%eax), %ecx\n" /* line 1706 */
        "movl %ecx, 0x14(%edx)\n"
        "movl 0x24(%eax), %ecx\n" /* line 1707 */
        "movl %ecx, 0x18(%edx)\n"
        "movl 0x34(%eax), %ecx\n" /* line 1708 */
        "movl %ecx, 0x1c(%edx)\n"
        "movl 8(%eax), %ecx\n" /* line 1709 */
        "movl %ecx, 0x20(%edx)\n"
        "movl 0x18(%eax), %ecx\n" /* line 1710 */
        "movl %ecx, 0x24(%edx)\n"
        "movl 0x28(%eax), %ecx\n" /* line 1711 */
        "movl %ecx, 0x28(%edx)\n"
        "movl 0x38(%eax), %ecx\n" /* line 1712 */
        "movl %ecx, 0x2c(%edx)\n"
        "movl 0xc(%eax), %ecx\n" /* line 1713 */
        "movl %ecx, 0x30(%edx)\n"
        "movl 0x1c(%eax), %ecx\n" /* line 1714 */
        "movl %ecx, 0x34(%edx)\n"
        "movl 0x2c(%eax), %ecx\n" /* line 1715 */
        "movl %ecx, 0x38(%edx)\n"
        "movl 0x3c(%eax), %eax\n" /* line 1716 */
        "movl %eax, 0x3c(%edx)\n"
        "popl %ebp\n" /* line 1717 */
        "retl\n"
    );
}

/* line 1725 */
__attribute__((naked))
jpeg_alloc MatrixInverse(const float (*in)[3], float (*out)[3])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1725 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* in */
        "movl 0xc(%ebp), %ebx\n" /* out */
        "leal 0x18(%eax), %edx\n" /* line 1731 */
        "movss 8(%edx), %xmm1\n"
        "leal 0xc(%eax), %ecx\n"
        "movss 4(%ecx), %xmm5\n"
        "movss 4(%edx), %xmm3\n"
        "movss 8(%ecx), %xmm2\n"
        "movaps %xmm1, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm4\n"
        "movss 4(%eax), %xmm6\n"
        "movss 8(%eax), %xmm7\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "mulss %xmm6, %xmm1\n"
        "mulss %xmm7, %xmm3\n"
        "subss %xmm3, %xmm1\n"
        "mulss 0xc(%eax), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm2\n"
        "mulss %xmm7, %xmm5\n"
        "subss %xmm5, %xmm2\n"
        "mulss 0x18(%eax), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* line 1735 | 1.0f */
        "divss %xmm0, %xmm3\n"
        "mulss %xmm3, %xmm4\n" /* line 1737 */
        "movss %xmm4, (%ebx)\n" /* out */
        "movss 8(%edx), %xmm1\n" /* line 1738 */
        "mulss 4(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss 0x2efb90, %xmm2\n"
        "xorps %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, 4(%ebx)\n" /* out */
        "movss 8(%ecx), %xmm0\n" /* line 1739 */
        "mulss 4(%eax), %xmm0\n"
        "movss 4(%ecx), %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 8(%ebx)\n" /* out */
        "leal 0xc(%ebx), %esi\n" /* line 1741 | out */
        "movss 8(%edx), %xmm0\n"
        "mulss 0xc(%eax), %xmm0\n"
        "movss 0x18(%eax), %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "xorps %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n" /* out */
        "movss 8(%edx), %xmm0\n" /* line 1742 */
        "mulss (%eax), %xmm0\n"
        "movss 0x18(%eax), %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss 8(%ecx), %xmm0\n" /* line 1743 */
        "mulss (%eax), %xmm0\n"
        "movss 0xc(%eax), %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "xorps %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "leal 0x18(%ebx), %esi\n" /* line 1745 | out */
        "movss 4(%edx), %xmm0\n"
        "mulss 0xc(%eax), %xmm0\n"
        "movss 0x18(%eax), %xmm1\n"
        "mulss 4(%ecx), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 0x18(%ebx)\n" /* out */
        "movss 4(%edx), %xmm0\n" /* line 1746 */
        "mulss (%eax), %xmm0\n"
        "movss 0x18(%eax), %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "xorps %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss 4(%ecx), %xmm1\n" /* line 1747 */
        "mulss (%eax), %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm3\n"
        "movss %xmm3, 8(%esi)\n"
        "popl %ebx\n" /* line 1748 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1865 */
__attribute__((naked))
jpeg_alloc MatrixTransformVector(const float *in1, const float (*in2)[3], float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1865 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* in1 */
        "movl 0xc(%ebp), %edx\n" /* in2 */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "leal 0xc(%edx), %ebx\n" /* line 1868 */
        "leal 0x18(%edx), %esi\n"
        "movss (%eax), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1869 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1870 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "popl %ebx\n" /* line 1871 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1773 */
__attribute__((naked))
jpeg_alloc MatrixInverse44(const float *mat, float *dst)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1773 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc0, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* dst */
        "xorl %ecx, %ecx\n"
        "leal -0x48(%ebp), %ebx\n" /* src */
        "movl 8(%ebp), %edx\n" /* mat */
        /* { scope 1 */
        ".Lf2b42e_0002b444:\n"
        "movl (%edx), %eax\n" /* line 1785 */
        "movl %eax, (%ecx, %ebx)\n"
        "movl 4(%edx), %eax\n" /* line 1786 */
        "movl %eax, 0x10(%ebx, %ecx)\n"
        "movl 8(%edx), %eax\n" /* line 1787 */
        "movl %eax, 0x20(%ebx, %ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 1788 */
        "movl %eax, 0x30(%ebx, %ecx)\n"
        "addl $4, %ecx\n"
        "addl $0x10, %edx\n"
        "cmpl $0x10, %ecx\n" /* line 1783 */
        "jne .Lf2b42e_0002b444\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 1791 */
        "movss %xmm0, -0xbc(%ebp)\n"
        "movss -0xc(%ebp), %xmm1\n"
        "movss %xmm1, -0xb8(%ebp)\n"
        "movaps %xmm0, %xmm6\n"
        "mulss %xmm1, %xmm6\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 1792 */
        "movss %xmm2, -0xb4(%ebp)\n"
        "movss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n"
        "mulss %xmm0, %xmm2\n"
        "movss %xmm2, -0x6c(%ebp)\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1793 */
        "movss %xmm1, -0xac(%ebp)\n"
        "movss -0xb8(%ebp), %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x70(%ebp)\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 1794 */
        "movss %xmm0, -0xa8(%ebp)\n"
        "movss -0xb4(%ebp), %xmm7\n"
        "mulss %xmm0, %xmm7\n"
        "movss -0xb0(%ebp), %xmm2\n" /* line 1795 */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x74(%ebp)\n"
        "movss -0xbc(%ebp), %xmm1\n" /* line 1796 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "movss -0x28(%ebp), %xmm2\n" /* line 1797 */
        "movss %xmm2, -0xa4(%ebp)\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "movss -0x18(%ebp), %xmm1\n" /* line 1798 */
        "movss %xmm1, -0xa0(%ebp)\n"
        "movss -0xb4(%ebp), %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x80(%ebp)\n"
        "movss -0xb0(%ebp), %xmm0\n" /* line 1799 */
        "mulss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n"
        "movss -0xbc(%ebp), %xmm2\n" /* line 1800 */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "movss -0xa8(%ebp), %xmm0\n" /* line 1801 */
        "mulss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movss -0xac(%ebp), %xmm2\n" /* line 1802 */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x90(%ebp)\n"
        "movss -0x34(%ebp), %xmm5\n" /* line 1804 */
        "movss -0x2c(%ebp), %xmm4\n"
        "movaps %xmm6, %xmm1\n" /* line 1805 */
        "mulss %xmm5, %xmm1\n"
        "movss -0x30(%ebp), %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x74(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x70(%ebp), %xmm2\n"
        "mulss -0x30(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0x78(%ebp), %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n" /* dst */
        "movss -0x6c(%ebp), %xmm1\n" /* line 1807 */
        "mulss -0x38(%ebp), %xmm1\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss -0x30(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x88(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x38(%ebp), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss -0x80(%ebp), %xmm2\n"
        "mulss -0x30(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0x84(%ebp), %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n" /* dst */
        "movss -0x70(%ebp), %xmm1\n" /* line 1809 */
        "mulss -0x38(%ebp), %xmm1\n"
        "movss -0x80(%ebp), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x8c(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x38(%ebp), %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "movss -0x7c(%ebp), %xmm2\n"
        "mulss %xmm5, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0x90(%ebp), %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esi)\n" /* dst */
        "movss -0x78(%ebp), %xmm1\n" /* line 1811 */
        "mulss -0x38(%ebp), %xmm1\n"
        "movss -0x84(%ebp), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x90(%ebp), %xmm0\n"
        "mulss -0x30(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x74(%ebp), %xmm0\n"
        "mulss -0x38(%ebp), %xmm0\n"
        "movss -0x88(%ebp), %xmm2\n"
        "mulss %xmm5, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0x8c(%ebp), %xmm2\n"
        "mulss -0x30(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esi)\n" /* dst */
        "movss -0x44(%ebp), %xmm0\n" /* line 1812 */
        "movss %xmm0, -0x9c(%ebp)\n"
        "movss -0x40(%ebp), %xmm1\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "movss %xmm2, -0x94(%ebp)\n"
        "movss -0x6c(%ebp), %xmm1\n" /* line 1813 */
        "mulss %xmm0, %xmm1\n"
        "movss -0x70(%ebp), %xmm0\n"
        "mulss -0x98(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x78(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss -0x98(%ebp), %xmm2\n"
        "mulss %xmm7, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0x74(%ebp), %xmm2\n"
        "mulss -0x94(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x10(%esi)\n" /* dst */
        "movss -0x48(%ebp), %xmm3\n" /* line 1814 | src */
        "mulss %xmm3, %xmm6\n" /* line 1815 */
        "movss -0x80(%ebp), %xmm0\n"
        "mulss -0x98(%ebp), %xmm0\n"
        "addss %xmm0, %xmm6\n"
        "movss -0x84(%ebp), %xmm0\n"
        "mulss -0x94(%ebp), %xmm0\n"
        "addss %xmm0, %xmm6\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss -0x98(%ebp), %xmm0\n"
        "addss -0x6c(%ebp), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "mulss -0x94(%ebp), %xmm0\n"
        "addss -0x6c(%ebp), %xmm0\n"
        "subss %xmm0, %xmm6\n"
        "movss %xmm6, 0x14(%esi)\n" /* dst */
        "mulss %xmm3, %xmm7\n" /* line 1817 */
        "movss -0x7c(%ebp), %xmm1\n"
        "mulss -0x9c(%ebp), %xmm1\n"
        "addss %xmm1, %xmm7\n"
        "movss -0x90(%ebp), %xmm0\n"
        "mulss -0x94(%ebp), %xmm0\n"
        "addss %xmm0, %xmm7\n"
        "movss -0x70(%ebp), %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss %xmm2, -0x70(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n"
        "mulss -0x9c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x8c(%ebp), %xmm0\n"
        "mulss -0x94(%ebp), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm7\n"
        "movss %xmm7, 0x18(%esi)\n" /* dst */
        "movss -0x74(%ebp), %xmm1\n" /* line 1819 */
        "mulss %xmm3, %xmm1\n"
        "movss -0x88(%ebp), %xmm2\n"
        "mulss -0x9c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x8c(%ebp), %xmm0\n"
        "mulss -0x98(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x74(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss -0x84(%ebp), %xmm2\n"
        "mulss -0x9c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "movss -0x90(%ebp), %xmm0\n"
        "mulss -0x98(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x74(%ebp), %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movss %xmm2, 0x1c(%esi)\n" /* dst */
        "movss -0x98(%ebp), %xmm6\n" /* line 1821 */
        "mulss %xmm4, %xmm6\n"
        "movss -0x30(%ebp), %xmm7\n" /* line 1822 */
        "mulss -0x94(%ebp), %xmm7\n"
        "movss -0x9c(%ebp), %xmm0\n" /* line 1823 */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0x94(%ebp), %xmm1\n" /* line 1824 */
        "mulss %xmm5, %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movss -0x30(%ebp), %xmm2\n" /* line 1825 */
        "mulss -0x9c(%ebp), %xmm2\n"
        "movss %xmm2, -0x54(%ebp)\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 1826 */
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "mulss %xmm3, %xmm4\n" /* line 1827 */
        "movss -0x38(%ebp), %xmm1\n" /* line 1828 */
        "mulss -0x94(%ebp), %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "movss -0x30(%ebp), %xmm2\n" /* line 1829 */
        "mulss %xmm3, %xmm2\n"
        "movss %xmm2, -0x60(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 1830 */
        "mulss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "mulss %xmm3, %xmm5\n" /* line 1831 */
        "movss -0x38(%ebp), %xmm1\n" /* line 1832 */
        "mulss -0x9c(%ebp), %xmm1\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "movss -0xa8(%ebp), %xmm1\n" /* line 1835 */
        "mulss %xmm6, %xmm1\n"
        "movss -0xb0(%ebp), %xmm0\n"
        "mulss -0x50(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "mulss -0x54(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xa8(%ebp), %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "movss -0xb0(%ebp), %xmm2\n"
        "mulss -0x4c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0xb8(%ebp), %xmm2\n"
        "mulss -0x58(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%esi)\n" /* dst */
        "movss -0xa0(%ebp), %xmm1\n" /* line 1837 */
        "mulss %xmm7, %xmm1\n"
        "movss -0xb0(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "mulss -0x64(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xa0(%ebp), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss -0xb0(%ebp), %xmm2\n"
        "mulss -0x5c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0xb8(%ebp), %xmm2\n"
        "mulss -0x60(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x24(%esi)\n" /* dst */
        "movss -0xa0(%ebp), %xmm1\n" /* line 1839 */
        "mulss -0x4c(%ebp), %xmm1\n"
        "movss -0xa8(%ebp), %xmm0\n"
        "mulss -0x5c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xa0(%ebp), %xmm0\n"
        "mulss -0x50(%ebp), %xmm0\n"
        "movss -0xa8(%ebp), %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0xb8(%ebp), %xmm2\n"
        "mulss -0x68(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x28(%esi)\n" /* dst */
        "movss -0xa0(%ebp), %xmm0\n" /* line 1841 */
        "mulss -0x58(%ebp), %xmm0\n"
        "movss -0xa8(%ebp), %xmm1\n"
        "mulss -0x60(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0xb0(%ebp), %xmm1\n"
        "mulss -0x68(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0xa0(%ebp), %xmm1\n"
        "mulss -0x54(%ebp), %xmm1\n"
        "movss -0xa8(%ebp), %xmm2\n"
        "mulss -0x64(%ebp), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0xa0(%ebp)\n"
        "movss -0xb0(%ebp), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "movss -0xa0(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 0x2c(%esi)\n" /* dst */
        "movss -0xbc(%ebp), %xmm1\n" /* line 1843 */
        "mulss -0x4c(%ebp), %xmm1\n"
        "movss -0xb4(%ebp), %xmm0\n"
        "mulss -0x58(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xac(%ebp), %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xb4(%ebp), %xmm0\n"
        "mulss -0x54(%ebp), %xmm0\n"
        "movss -0xac(%ebp), %xmm2\n"
        "mulss %xmm6, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0xbc(%ebp), %xmm2\n"
        "mulss -0x50(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x30(%esi)\n" /* dst */
        "movss -0xb4(%ebp), %xmm1\n" /* line 1845 */
        "mulss -0x60(%ebp), %xmm1\n"
        "mulss -0xa4(%ebp), %xmm6\n"
        "addss %xmm6, %xmm1\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss -0x5c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss -0xb4(%ebp), %xmm2\n"
        "mulss -0x64(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss -0xa4(%ebp), %xmm7\n"
        "addss %xmm7, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x34(%esi)\n" /* dst */
        "mulss -0xac(%ebp), %xmm4\n" /* line 1847 */
        "movss -0xb4(%ebp), %xmm0\n"
        "mulss -0x68(%ebp), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss -0xa4(%ebp), %xmm0\n"
        "mulss -0x50(%ebp), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss -0xb4(%ebp), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "movss -0xa4(%ebp), %xmm2\n"
        "mulss -0x4c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0xb4(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n"
        "mulss -0x5c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm1, %xmm4\n"
        "movss %xmm4, 0x38(%esi)\n" /* dst */
        "mulss -0xbc(%ebp), %xmm5\n" /* line 1849 */
        "movss -0xa4(%ebp), %xmm1\n"
        "mulss -0x54(%ebp), %xmm1\n"
        "addss %xmm1, %xmm5\n"
        "movss -0xac(%ebp), %xmm2\n"
        "mulss -0x64(%ebp), %xmm2\n"
        "addss %xmm2, %xmm5\n"
        "movss -0xac(%ebp), %xmm0\n"
        "mulss -0x60(%ebp), %xmm0\n"
        "movss -0xbc(%ebp), %xmm1\n"
        "mulss -0x68(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0xac(%ebp)\n"
        "movss -0xa4(%ebp), %xmm2\n"
        "mulss -0x58(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm5\n"
        "movss %xmm5, 0x3c(%esi)\n" /* dst */
        "mulss (%esi), %xmm3\n" /* line 1851 | dst */
        "movss -0x9c(%ebp), %xmm0\n"
        "mulss 4(%esi), %xmm0\n" /* dst */
        "addss %xmm0, %xmm3\n"
        "movss -0x98(%ebp), %xmm1\n"
        "mulss 8(%esi), %xmm1\n" /* dst */
        "addss %xmm1, %xmm3\n"
        "movss -0x94(%ebp), %xmm2\n"
        "mulss 0xc(%esi), %xmm2\n" /* dst */
        "addss %xmm2, %xmm3\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 1854 | 1.0f */
        "divss %xmm3, %xmm1\n"
        "movl $1, %edx\n"
        "leal 4(%esi), %eax\n" /* dst */
        ".Lf2b42e_0002bcff:\n"
        "movaps %xmm1, %xmm0\n" /* line 1856 */
        "mulss -4(%eax), %xmm0\n"
        "movss %xmm0, -4(%eax)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $0x11, %edx\n" /* line 1855 */
        "jne .Lf2b42e_0002bcff\n"
        /* } scope */
        "addl $0xc0, %esp\n" /* line 1857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1879 */
__attribute__((naked))
jpeg_alloc MatrixTransformVector44(const float *vec, const float (*mat)[4], float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1879 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* vec */
        "movl 0xc(%ebp), %edx\n" /* mat */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "leal 0x10(%edx), %ebx\n" /* line 1882 */
        "leal 0x20(%edx), %esi\n"
        "leal 0x30(%edx), %edi\n"
        "movss (%eax), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0x30(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1883 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1884 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1885 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0xc(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0xc(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 0xc(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ecx)\n"
        "popl %ebx\n" /* line 1886 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1894 */
__attribute__((naked))
jpeg_alloc MatrixTransposeTransformVector(const float *in1, const float (*in2)[3], float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1894 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* in1 */
        "movl 0xc(%ebp), %edx\n" /* in2 */
        "movl 0x10(%ebp), %ebx\n" /* out */
        "movss (%eax), %xmm1\n" /* line 1897 */
        "mulss (%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* out */
        "leal 0xc(%edx), %ecx\n" /* line 1898 */
        "movss (%eax), %xmm1\n"
        "mulss 0xc(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ebx)\n" /* out */
        "leal 0x18(%edx), %ecx\n" /* line 1899 */
        "movss (%eax), %xmm1\n"
        "mulss 0x18(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n" /* out */
        "popl %ebx\n" /* line 1900 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1908 */
__attribute__((naked))
jpeg_alloc MatrixTransformVector43(const float *in1, const float (*in2)[3], float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1908 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* in1 */
        "movl 0xc(%ebp), %eax\n" /* in2 */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "leal 0xc(%eax), %ebx\n" /* line 1911 */
        "leal 0x18(%eax), %esi\n"
        "leal 0x24(%eax), %edi\n"
        "movss (%edx), %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x24(%eax), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss (%edx), %xmm1\n" /* line 1912 */
        "mulss 4(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 4(%edi), %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%edx), %xmm1\n" /* line 1913 */
        "mulss 8(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 8(%edi), %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "popl %ebx\n" /* line 1914 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1976 */
__attribute__((naked))
jpeg_alloc QuatMultiply(const float *in1, const float *in2, float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1976 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* in1 */
        "movl 0xc(%ebp), %edx\n" /* in2 */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "movss (%eax), %xmm1\n" /* line 1978 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss 4(%eax), %xmm1\n" /* line 1979 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss (%eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss 8(%eax), %xmm1\n" /* line 1980 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss (%eax), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "movss 0xc(%eax), %xmm1\n" /* line 1981 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss (%eax), %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ecx)\n"
        "popl %ebp\n" /* line 1982 */
        "retl\n"
    );
}

/* line 2004 */
__attribute__((naked))
jpeg_alloc QuatToAxis(const vec_t *quat, double (*axis)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2004 */
        "movl %esp, %ebp\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* quat */
        "movl 0xc(%ebp), %edx\n" /* axis */
        /* { scope 1 */
        "movss (%eax), %xmm2\n" /* line 2009 */
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* xx */
        "movss 4(%eax), %xmm3\n" /* line 2010 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm3, %xmm7\n"
        "movss 8(%eax), %xmm4\n" /* line 2011 */
        "movaps %xmm4, %xmm5\n"
        "mulss %xmm4, %xmm5\n"
        "movss 0xc(%eax), %xmm6\n" /* line 2012 */
        "movaps %xmm6, %xmm1\n" /* line 2018 */
        "mulss %xmm6, %xmm1\n"
        "addss %xmm7, %xmm0\n"
        "addss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x2ed62c, %xmm0\n" /* 2.0f */
        "divss %xmm1, %xmm0\n"
        "movss -0x14(%ebp), %xmm1\n" /* line 2020 | xx */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -4(%ebp)\n"
        "mulss %xmm0, %xmm7\n" /* line 2021 */
        "movss %xmm7, -8(%ebp)\n"
        "mulss %xmm0, %xmm5\n" /* line 2022 */
        "mulss %xmm0, %xmm2\n" /* line 2024 */
        "movaps %xmm3, %xmm7\n" /* line 2025 */
        "mulss %xmm2, %xmm7\n"
        "movaps %xmm4, %xmm1\n" /* line 2026 */
        "mulss %xmm2, %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n" /* xz */
        "mulss %xmm6, %xmm2\n" /* line 2027 */
        "movss %xmm2, -0xc(%ebp)\n" /* xw */
        "mulss %xmm0, %xmm3\n" /* line 2029 */
        "movaps %xmm4, %xmm2\n" /* line 2030 */
        "mulss %xmm3, %xmm2\n"
        "mulss %xmm6, %xmm3\n" /* line 2031 */
        "mulss %xmm0, %xmm4\n" /* line 2033 */
        "mulss %xmm6, %xmm4\n"
        "movss -8(%ebp), %xmm0\n" /* line 2035 */
        "addss %xmm5, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movaps %xmm1, %xmm6\n"
        "subss %xmm0, %xmm6\n"
        "movss %xmm6, (%edx)\n"
        "movaps %xmm7, %xmm0\n" /* line 2036 */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 2037 | xz */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "leal 0xc(%edx), %eax\n" /* line 2039 */
        "subss %xmm4, %xmm7\n"
        "movss %xmm7, 0xc(%edx)\n"
        "addss -4(%ebp), %xmm5\n" /* line 2040 */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm5, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 2041 | xw */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x18(%edx), %eax\n" /* line 2043 */
        "addss -0x10(%ebp), %xmm3\n" /* xz */
        "movss %xmm3, 0x18(%edx)\n"
        "subss -0xc(%ebp), %xmm2\n" /* line 2044 | xw */
        "movss %xmm2, 4(%eax)\n"
        "movss -4(%ebp), %xmm6\n" /* line 2045 */
        "addss -8(%ebp), %xmm6\n"
        "subss %xmm6, %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "leave\n" /* line 2046 */
        "retl\n"
    );
}

/* line 2120 */
__attribute__((naked))
float RotationToYaw(const vec_t *rot)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2120 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl 8(%ebp), %eax\n" /* rot */
        /* { scope 1 */
        "movss (%eax), %xmm3\n" /* line 2125 */
        "movaps %xmm3, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss 4(%eax), %xmm4\n" /* line 2126 */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed62c, %xmm1\n" /* line 2128 | 2.0f */
        "divss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm2\n" /* line 2130 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm4, %xmm3\n"
        "mulss %xmm3, %xmm1\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "calll atan2\n"
        "fstpl -0x20(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "mulsd 0x307c40, %xmm0\n" /* 57.29577951308232 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "flds -0xc(%ebp)\n" /* line 2131 */
        "leave\n"
        "retl\n"
    );
}

/* line 2263 */
__attribute__((naked))
jpeg_alloc InfinitePerspectiveMatrix(float (*mtx)[4], float fov_x, float fov_y, float zNear)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2263 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %ebx\n" /* mtx */
        "movss 0x10(%ebp), %xmm1\n" /* fov_y */
        "cld\n" /* line 2270 */
        "movl $0x10, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* mtx */
        "rep stosl %eax, %es:(%edi)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 2276 | fov_x */
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "addss 0x2ed5f8, %xmm0\n" /* 90.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x18(%ebp)\n"
        "calll tan\n"
        "fstpl -0x20(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "mulsd 0x307c50, %xmm0\n" /* 0.9995002746582031 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* mtx */
        "movss -0x18(%ebp), %xmm1\n" /* line 2277 */
        "mulss 0x2ed63c, %xmm1\n" /* -0.5f */
        "addss 0x2ed5f8, %xmm1\n" /* 90.0f */
        "cvtss2sd %xmm1, %xmm1\n"
        "mulsd 0x307c48, %xmm1\n" /* 0.017453292519943295 */
        "movsd %xmm1, (%esp)\n"
        "calll tan\n"
        "fstpl -0x20(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "mulsd 0x307c50, %xmm0\n" /* 0.9995002746582031 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x14(%ebx)\n" /* mtx */
        "leal 0x20(%ebx), %eax\n" /* line 2278 | mtx */
        "movss 0x2ed640, %xmm0\n" /* 0.9995002746582031f */
        "movss %xmm0, 8(%eax)\n"
        "movl $0x3f800000, 0xc(%eax)\n" /* line 2279 */
        "xorl $0x80000000, 0x14(%ebp)\n" /* line 2280 | zNear */
        "mulss 0x14(%ebp), %xmm0\n" /* zNear */
        "movss %xmm0, 0x38(%ebx)\n" /* mtx */
        "addl $0x30, %esp\n" /* line 2281 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2301 */
__attribute__((naked))
jpeg_alloc MatrixForViewer(float (*mtx)[4], const vec_t *origin, vec3_t *axis)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2301 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %edx\n" /* mtx */
        "movl 0xc(%ebp), %ebx\n" /* origin */
        "movl 0x10(%ebp), %esi\n" /* axis */
        "leal 0xc(%esi), %eax\n" /* line 2307 | axis */
        "movss 0x2efbb0, %xmm3\n"
        "movss 0xc(%esi), %xmm0\n" /* axis */
        "xorps %xmm3, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "leal 0x10(%edx), %edi\n" /* line 2308 */
        "movss 4(%eax), %xmm0\n"
        "xorps %xmm3, %xmm0\n"
        "movss %xmm0, 0x10(%edx)\n"
        "leal 0x20(%edx), %ecx\n" /* line 2309 */
        "movl %ecx, -0x14(%ebp)\n"
        "movss 8(%eax), %xmm2\n"
        "xorps %xmm3, %xmm2\n"
        "movss %xmm2, 0x20(%edx)\n"
        "leal 0x30(%edx), %eax\n" /* line 2310 */
        "movl %eax, -0x10(%ebp)\n"
        "movss (%ebx), %xmm1\n" /* origin */
        "mulss (%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n" /* origin */
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss 8(%ebx), %xmm2\n" /* origin */
        "addss %xmm2, %xmm1\n"
        "xorps %xmm3, %xmm1\n"
        "movss %xmm1, 0x30(%edx)\n"
        "leal 0x18(%esi), %ecx\n" /* line 2312 | axis */
        "movl 0x18(%esi), %eax\n" /* axis */
        "movl %eax, 4(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 2313 */
        "movl %eax, 4(%edi)\n"
        "movss 8(%ecx), %xmm2\n" /* line 2314 */
        "movl -0x14(%ebp), %ecx\n"
        "movss %xmm2, 4(%ecx)\n"
        "movss (%ebx), %xmm1\n" /* line 2315 | origin */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n" /* origin */
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss 8(%ebx), %xmm2\n" /* origin */
        "addss %xmm2, %xmm1\n"
        "xorps %xmm3, %xmm1\n"
        "movl -0x10(%ebp), %eax\n"
        "movss %xmm1, 4(%eax)\n"
        "movl (%esi), %eax\n" /* line 2317 | axis */
        "movl %eax, 8(%edx)\n"
        "movl 4(%esi), %eax\n" /* line 2318 | axis */
        "movl %eax, 8(%edi)\n"
        "movss 8(%esi), %xmm2\n" /* line 2319 | axis */
        "movss %xmm2, 8(%ecx)\n"
        "movss (%ebx), %xmm1\n" /* line 2320 | origin */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n" /* origin */
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss 8(%ebx), %xmm2\n" /* origin */
        "addss %xmm2, %xmm1\n"
        "xorps %xmm3, %xmm1\n"
        "movl -0x10(%ebp), %ecx\n"
        "movss %xmm1, 8(%ecx)\n"
        "xorl %eax, %eax\n" /* line 2322 */
        "movl %eax, 0xc(%edx)\n"
        "movl %eax, 0xc(%edi)\n" /* line 2323 */
        "movl -0x14(%ebp), %edx\n" /* line 2324 */
        "movl %eax, 0xc(%edx)\n"
        "movl $0x3f800000, 0xc(%ecx)\n" /* line 2325 */
        "addl $8, %esp\n" /* line 2326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2405 */
__attribute__((naked))
const float AngleMod(const float a)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2405 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 0x2ed644, %xmm0\n" /* 182.04444885253906f */
        "mulss 8(%ebp), %xmm0\n" /* a */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed648, %xmm0\n" /* 0.0054931640625f */
        "movss %xmm0, -4(%ebp)\n" /* line 2408 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 2416 */
__attribute__((naked))
const float LerpAngle(const float from, const float to, const float frac)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2416 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm1\n" /* from */
        "movss 0xc(%ebp), %xmm2\n" /* to */
        "movss 0x10(%ebp), %xmm3\n" /* frac */
        /* { scope 1 */
        "movaps %xmm2, %xmm0\n" /* line 2421 */
        "subss %xmm1, %xmm0\n"
        "ucomiss 0x2ed64c, %xmm0\n" /* 180.0f */
        "jbe .Lf2c422_0002c456\n"
        "subss 0x2ed638, %xmm2\n" /* line 2422 | 360.0f */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        ".Lf2c422_0002c456:\n"
        "ucomiss 0x2ed650, %xmm0\n" /* line 2424 | -180.0f */
        "jae .Lf2c422_0002c470\n"
        "jp .Lf2c422_0002c470\n"
        "movaps %xmm2, %xmm0\n"
        "addss 0x2ed638, %xmm0\n" /* 360.0f */
        "subss %xmm1, %xmm0\n"
        ".Lf2c422_0002c470:\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        /* } scope */
        "movss %xmm1, -4(%ebp)\n" /* line 2429 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 2439 */
__attribute__((naked))
const float AngleSubtract(const float a1, const float a2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2439 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* a1 */
        /* { scope 1 */
        "subss 0xc(%ebp), %xmm0\n" /* line 2443 | a2 */
        "ucomiss 0x2ed64c, %xmm0\n" /* line 2444 | 180.0f */
        "jbe .Lf2c482_0002c4b4\n"
        "movss 0x2ed638, %xmm2\n" /* 360.0f */
        "movss 0x2ed64c, %xmm1\n" /* 180.0f */
        ".Lf2c482_0002c4ab:\n"
        "subss %xmm2, %xmm0\n" /* line 2445 */
        "ucomiss %xmm1, %xmm0\n" /* line 2444 */
        "ja .Lf2c482_0002c4ab\n"
        ".Lf2c482_0002c4b4:\n"
        "movss 0x2ed650, %xmm1\n" /* line 2447 | -180.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf2c482_0002c4d2\n"
        "movss 0x2ed638, %xmm2\n" /* 360.0f */
        ".Lf2c482_0002c4c9:\n"
        "addss %xmm2, %xmm0\n" /* line 2448 */
        "ucomiss %xmm0, %xmm1\n" /* line 2447 */
        "ja .Lf2c482_0002c4c9\n"
        /* } scope */
        ".Lf2c482_0002c4d2:\n"
        "movss %xmm0, -4(%ebp)\n" /* line 2451 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 2474 */
__attribute__((naked))
const float AngleNormalize360(const float angle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2474 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 0x2ed644, %xmm0\n" /* 182.04444885253906f */
        "mulss 8(%ebp), %xmm0\n" /* angle */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed648, %xmm0\n" /* 0.0054931640625f */
        "movss %xmm0, -4(%ebp)\n" /* line 2477 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 2505 */
__attribute__((naked))
const float AngleNormalize360Accurate(float angle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2505 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* angle */
        "pxor %xmm1, %xmm1\n" /* line 2507 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf2c50e_0002c549\n"
        "ucomiss 0x2ed638, %xmm0\n" /* line 2516 | 360.0f */
        "jb .Lf2c50e_0002c53f\n"
        "movss 0x2ed638, %xmm1\n" /* 360.0f */
        "movaps %xmm1, %xmm2\n"
        ".Lf2c50e_0002c536:\n"
        "subss %xmm2, %xmm0\n" /* line 2520 */
        "ucomiss %xmm1, %xmm0\n" /* line 2518 */
        "jae .Lf2c50e_0002c536\n"
        ".Lf2c50e_0002c53f:\n"
        "movss %xmm0, -4(%ebp)\n" /* line 2526 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
        ".Lf2c50e_0002c549:\n"
        "movss 0x2ed638, %xmm2\n" /* 360.0f */
        ".Lf2c50e_0002c551:\n"
        "addss %xmm2, %xmm0\n" /* line 2511 */
        "ucomiss %xmm0, %xmm1\n" /* line 2509 */
        "ja .Lf2c50e_0002c551\n"
        "movss %xmm0, -4(%ebp)\n" /* line 2526 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 2536 */
__attribute__((naked))
const float AngleNormalize180Accurate(float angle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2536 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* angle */
        "movss 0x2ed650, %xmm1\n" /* line 2538 | -180.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf2c564_0002c597\n"
        "movss 0x2ed638, %xmm2\n" /* 360.0f */
        ".Lf2c564_0002c584:\n"
        "addss %xmm2, %xmm0\n" /* line 2542 */
        "ucomiss %xmm0, %xmm1\n" /* line 2540 */
        "jae .Lf2c564_0002c584\n"
        ".Lf2c564_0002c58d:\n"
        "movss %xmm0, -4(%ebp)\n" /* line 2557 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
        ".Lf2c564_0002c597:\n"
        "ucomiss 0x2ed64c, %xmm0\n" /* line 2547 | 180.0f */
        "jbe .Lf2c564_0002c58d\n"
        "movss 0x2ed638, %xmm2\n" /* 360.0f */
        "movss 0x2ed64c, %xmm1\n" /* 180.0f */
        ".Lf2c564_0002c5b0:\n"
        "subss %xmm2, %xmm0\n" /* line 2551 */
        "ucomiss %xmm1, %xmm0\n" /* line 2549 */
        "ja .Lf2c564_0002c5b0\n"
        "movss %xmm0, -4(%ebp)\n" /* line 2557 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 2697 */
__attribute__((naked))
jpeg_alloc AddPointToBounds(const vec_t *v, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2697 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* v */
        "movl 0xc(%ebp), %eax\n" /* mins */
        "movl 0x10(%ebp), %ecx\n" /* maxs */
        "movss (%edx), %xmm1\n" /* line 2699 */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2c5c6_0002c5e7\n"
        "movss %xmm1, (%eax)\n" /* line 2700 */
        "movss (%edx), %xmm1\n"
        ".Lf2c5c6_0002c5e7:\n"
        "ucomiss (%ecx), %xmm1\n" /* line 2701 */
        "jbe .Lf2c5c6_0002c5f0\n"
        "movss %xmm1, (%ecx)\n" /* line 2702 */
        ".Lf2c5c6_0002c5f0:\n"
        "movss 4(%edx), %xmm1\n" /* line 2704 */
        "movss 4(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2c5c6_0002c609\n"
        "movss %xmm1, 4(%eax)\n" /* line 2705 */
        "movss 4(%edx), %xmm1\n"
        ".Lf2c5c6_0002c609:\n"
        "ucomiss 4(%ecx), %xmm1\n" /* line 2706 */
        "jbe .Lf2c5c6_0002c614\n"
        "movss %xmm1, 4(%ecx)\n" /* line 2707 */
        ".Lf2c5c6_0002c614:\n"
        "movss 8(%edx), %xmm1\n" /* line 2709 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2c5c6_0002c62d\n"
        "movss %xmm1, 8(%eax)\n" /* line 2710 */
        "movss 8(%edx), %xmm1\n"
        ".Lf2c5c6_0002c62d:\n"
        "ucomiss 8(%ecx), %xmm1\n" /* line 2711 */
        "jbe .Lf2c5c6_0002c638\n"
        "movss %xmm1, 8(%ecx)\n" /* line 2712 */
        ".Lf2c5c6_0002c638:\n"
        "popl %ebp\n" /* line 2713 */
        "retl\n"
    );
}

/* line 2804 */
__attribute__((naked))
jpeg_alloc ExpandBounds(const vec_t *addedmins, const vec_t *addedmaxs, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2804 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* addedmins */
        "movl 0xc(%ebp), %ebx\n" /* addedmaxs */
        "movl 0x10(%ebp), %eax\n" /* mins */
        "movl 0x14(%ebp), %edx\n" /* maxs */
        "movss (%ecx), %xmm1\n" /* line 2806 */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2c63a_0002c65b\n"
        "movss %xmm1, (%eax)\n" /* line 2807 */
        ".Lf2c63a_0002c65b:\n"
        "movss (%ebx), %xmm0\n" /* line 2808 | addedmaxs */
        "ucomiss (%edx), %xmm0\n"
        "jbe .Lf2c63a_0002c668\n"
        "movss %xmm0, (%edx)\n" /* line 2809 */
        ".Lf2c63a_0002c668:\n"
        "movss 4(%ecx), %xmm1\n" /* line 2811 */
        "movss 4(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2c63a_0002c67c\n"
        "movss %xmm1, 4(%eax)\n" /* line 2812 */
        ".Lf2c63a_0002c67c:\n"
        "movss 4(%ebx), %xmm0\n" /* line 2813 | addedmaxs */
        "ucomiss 4(%edx), %xmm0\n"
        "jbe .Lf2c63a_0002c68c\n"
        "movss %xmm0, 4(%edx)\n" /* line 2814 */
        ".Lf2c63a_0002c68c:\n"
        "movss 8(%ecx), %xmm1\n" /* line 2816 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2c63a_0002c6a0\n"
        "movss %xmm1, 8(%eax)\n" /* line 2817 */
        ".Lf2c63a_0002c6a0:\n"
        "movss 8(%ebx), %xmm0\n" /* line 2818 | addedmaxs */
        "ucomiss 8(%edx), %xmm0\n"
        "jbe .Lf2c63a_0002c6b0\n"
        "movss %xmm0, 8(%edx)\n" /* line 2819 */
        ".Lf2c63a_0002c6b0:\n"
        "popl %ebx\n" /* line 2820 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2921 */
__attribute__((naked))
jpeg_alloc AxisTransformVector(vec3_t *axes, const vec_t x, const vec_t y, const vec_t z, vec_t *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2921 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* axes */
        "movss 0xc(%ebp), %xmm2\n" /* x */
        "movss 0x10(%ebp), %xmm3\n" /* y */
        "movss 0x14(%ebp), %xmm4\n" /* z */
        "movl 0x18(%ebp), %edx\n" /* out */
        "leal 0xc(%eax), %ecx\n" /* line 2923 */
        "leal 0x18(%eax), %ebx\n"
        "movaps %xmm2, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0xc(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x18(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movaps %xmm2, %xmm0\n" /* line 2924 */
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "mulss 8(%eax), %xmm2\n" /* line 2925 */
        "mulss 8(%ecx), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss 8(%ebx), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, 8(%edx)\n"
        "popl %ebx\n" /* line 2926 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3232 */
__attribute__((naked))
jpeg_alloc ProjectPointOnPlane(const vec_t *p, const vec_t *normal, vec_t *dst)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3232 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* p */
        "movl 0xc(%ebp), %eax\n" /* normal */
        "movl 0x10(%ebp), %ecx\n" /* dst */
        /* { scope 1 */
        "movss (%eax), %xmm2\n" /* line 304 */
        "movss (%edx), %xmm3\n"
        "movaps %xmm2, %xmm1\n" /* line 3238 */
        "mulss %xmm3, %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "xorps 0x2efbd0, %xmm1\n"
        "mulss %xmm1, %xmm2\n" /* line 288 */
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, (%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 3240 */
        "retl\n"
    );
}

/* line 3329 */
__attribute__((naked))
const int BoxOnPlaneSide(const vec_t *emins, const vec_t *emaxs, const cplane_s *p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3329 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* emins */
        "movl 0xc(%ebp), %ebx\n" /* emaxs */
        "movl 0x10(%ebp), %edx\n" /* p */
        /* { scope 1 */
        "movzbl 0x10(%edx), %eax\n" /* line 3335 */
        "cmpb $2, %al\n"
        "ja .Lf2c7ac_0002c7ea\n"
        "movss 0xc(%edx), %xmm3\n" /* line 3337 */
        "movzbl %al, %eax\n"
        "shll $2, %eax\n"
        "movss (%ecx, %eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jae .Lf2c7ac_0002ca5b\n"
        "ucomiss (%ebx, %eax), %xmm3\n" /* line 3339 | emaxs */
        "sbbl %edx, %edx\n"
        "notl %edx\n"
        "addl $3, %edx\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 3391 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c7ac_0002c7ea:\n"
        "movzbl 0x11(%edx), %eax\n" /* line 3345 */
        "cmpl $7, %eax\n"
        "jbe .Lf2c7ac_0002c817\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm4\n"
        ".Lf2c7ac_0002c7fa:\n"
        "movss 0xc(%edx), %xmm0\n" /* line 3385 */
        "xorl %edx, %edx\n"
        "ucomiss %xmm0, %xmm4\n"
        "setae %dl\n"
        "movl %edx, %eax\n" /* line 3388 */
        "orl $2, %eax\n"
        "ucomiss %xmm3, %xmm0\n"
        "cmoval %eax, %edx\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 3391 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c7ac_0002c817:\n"
        "jmpl *0x2efbe0(, %eax, 4)\n" /* line 3345 */
        "movss (%edx), %xmm3\n" /* line 3348 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ebx), %xmm4\n" /* emaxs */
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "mulss (%ecx), %xmm3\n" /* line 3349 */
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ecx), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        "movss (%edx), %xmm3\n" /* line 3376 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ecx), %xmm4\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss (%ebx), %xmm3\n" /* line 3377 | emaxs */
        "mulss 4(%ebx), %xmm1\n" /* emaxs */
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ebx), %xmm2\n" /* emaxs */
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        "movss (%edx), %xmm3\n" /* line 3372 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ebx), %xmm4\n" /* emaxs */
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss (%ecx), %xmm3\n" /* line 3373 */
        "mulss 4(%ebx), %xmm1\n" /* emaxs */
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ebx), %xmm2\n" /* emaxs */
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        "movss (%edx), %xmm3\n" /* line 3368 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ecx), %xmm4\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss (%ebx), %xmm3\n" /* line 3369 | emaxs */
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ebx), %xmm2\n" /* emaxs */
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        "movss (%edx), %xmm3\n" /* line 3364 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ebx), %xmm4\n" /* emaxs */
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss (%ecx), %xmm3\n" /* line 3365 */
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ebx), %xmm2\n" /* emaxs */
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        "movss (%edx), %xmm3\n" /* line 3360 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ecx), %xmm4\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "mulss (%ebx), %xmm3\n" /* line 3361 | emaxs */
        "mulss 4(%ebx), %xmm1\n" /* emaxs */
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ecx), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        "movss (%edx), %xmm3\n" /* line 3356 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ebx), %xmm4\n" /* emaxs */
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "mulss (%ecx), %xmm3\n" /* line 3357 */
        "mulss 4(%ebx), %xmm1\n" /* emaxs */
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ecx), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        "movss (%edx), %xmm3\n" /* line 3352 */
        "movss 4(%edx), %xmm1\n"
        "movss 8(%edx), %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "mulss (%ecx), %xmm4\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 4(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%ebx), %xmm0\n" /* emaxs */
        "addss %xmm0, %xmm4\n"
        "mulss (%ebx), %xmm3\n" /* line 3353 | emaxs */
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss 8(%ecx), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "jmp .Lf2c7ac_0002c7fa\n"
        ".Lf2c7ac_0002ca5b:\n"
        "movl $1, %edx\n" /* line 3337 */
        /* } scope */
        "movl %edx, %eax\n" /* line 3391 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3865 */
__attribute__((naked))
jpeg_alloc Rand_Init(int seed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3865 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 3867 | seed */
        "movl %eax, holdrand\n"
        "popl %ebp\n" /* line 3868 */
        "retl\n"
    );
}

/* line 3873 */
__attribute__((naked))
float flrand(float min, float max)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3873 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm1\n" /* min */
        "movss 0xc(%ebp), %xmm2\n" /* max */
        "movl holdrand, %edx\n" /* line 3877 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x269ec3(%edx, %eax, 4), %eax\n"
        "movl %eax, holdrand\n"
        "movl %eax, %edx\n"
        "shrl $0x11, %edx\n"
        "js .Lf2ca74_0002cacf\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "subss %xmm1, %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "mulss 0x2ed654, %xmm0\n" /* 3.0517578125e-05f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -4(%ebp)\n" /* line 3882 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
        ".Lf2ca74_0002cacf:\n"
        "shrl $0x12, %eax\n" /* line 3877 */
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "subss %xmm1, %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "mulss 0x2ed654, %xmm0\n" /* 3.0517578125e-05f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -4(%ebp)\n" /* line 3882 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 3887 */
__attribute__((naked))
int irand(int min, int max)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3887 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* min */
        "movl 0xc(%ebp), %ebx\n" /* max */
        "movl holdrand, %ecx\n" /* line 3891 */
        "leal (%ecx, %ecx, 2), %edx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "shll $4, %edx\n"
        "addl %ecx, %edx\n"
        "shll $8, %edx\n"
        "subl %ecx, %edx\n"
        "leal 0x269ec3(%ecx, %edx, 4), %edx\n"
        "movl %edx, holdrand\n"
        "shrl $0x11, %edx\n"
        "subl %eax, %ebx\n" /* max */
        "imull %ebx, %edx\n" /* max */
        "sarl $0xf, %edx\n"
        "addl %edx, %eax\n"
        "popl %ebx\n" /* line 3895 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3898 */
__attribute__((naked))
jpeg_alloc MatrixTransformVectorQuatTrans(const vec_t *in, const DObjAnimMat *mat, vec_t *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3898 */
        "movl %esp, %ebp\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* in */
        "movl 0xc(%ebp), %eax\n" /* mat */
        "movl 0x10(%ebp), %ecx\n" /* out */
        /* { scope 1 */
        "movss 0x1c(%eax), %xmm3\n" /* line 306 | scale */
        /* { scope 2 */
        "movaps %xmm3, %xmm6\n" /* line 272 */
        "mulss (%eax), %xmm6\n"
        "movaps %xmm3, %xmm7\n" /* line 273 */
        "mulss 4(%eax), %xmm7\n"
        "mulss 8(%eax), %xmm3\n" /* line 274 */
        /* } scope */
        "movaps %xmm6, %xmm0\n" /* line 308 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n" /* xx */
        "movss 4(%eax), %xmm4\n" /* line 309 */
        "movaps %xmm6, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "movss 8(%eax), %xmm1\n" /* line 310 */
        "movaps %xmm6, %xmm5\n"
        "mulss %xmm1, %xmm5\n"
        "movss 0xc(%eax), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm6\n"
        "mulss %xmm7, %xmm4\n" /* line 313 */
        "movss %xmm4, -0xc(%ebp)\n" /* yy */
        "movaps %xmm7, %xmm4\n" /* line 314 */
        "mulss %xmm1, %xmm4\n"
        "movss %xmm4, -8(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm7\n" /* line 315 */
        "movss %xmm7, -4(%ebp)\n" /* yw */
        "movaps %xmm3, %xmm7\n" /* line 317 */
        "mulss %xmm1, %xmm7\n"
        "mulss %xmm0, %xmm3\n" /* line 318 */
        /* } scope */
        "movss -0xc(%ebp), %xmm0\n" /* line 398 | yy */
        "addss %xmm7, %xmm0\n"
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "movaps %xmm4, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -4(%ebp), %xmm0\n" /* yw */
        "addss %xmm5, %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x10(%eax), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "addss %xmm3, %xmm2\n" /* line 399 */
        "mulss (%edx), %xmm2\n"
        "addss -0x10(%ebp), %xmm7\n" /* xx */
        "movaps %xmm4, %xmm0\n"
        "subss %xmm7, %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -8(%ebp), %xmm0\n" /* yz */
        "subss %xmm6, %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x14(%eax), %xmm2\n"
        "movss %xmm2, 4(%ecx)\n"
        "subss -4(%ebp), %xmm5\n" /* line 400 | yw */
        "mulss (%edx), %xmm5\n"
        "addss -8(%ebp), %xmm6\n" /* yz */
        "mulss 4(%edx), %xmm6\n"
        "addss %xmm6, %xmm5\n"
        "movss -0x10(%ebp), %xmm0\n" /* xx */
        "addss -0xc(%ebp), %xmm0\n" /* yy */
        "subss %xmm0, %xmm4\n"
        "mulss 8(%edx), %xmm4\n"
        "addss %xmm4, %xmm5\n"
        "addss 0x18(%eax), %xmm5\n"
        "movss %xmm5, 8(%ecx)\n"
        "leave\n" /* line 3901 */
        "retl\n"
    );
}

/* line 405 */
__attribute__((naked))
float DiffTrack(float tgt, float cur, float rate, float deltaTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 405 */
        "movl %esp, %ebp\n"
        "movss 0xc(%ebp), %xmm4\n" /* cur */
        /* { scope 1 */
        "movss 8(%ebp), %xmm0\n" /* line 409 | tgt */
        "subss %xmm4, %xmm0\n"
        "movaps %xmm0, %xmm2\n" /* line 410 */
        "mulss 0x10(%ebp), %xmm2\n" /* rate */
        "mulss 0x14(%ebp), %xmm2\n" /* deltaTime */
        "movss 0x2efc20, %xmm1\n" /* line 54 */
        "movaps %xmm0, %xmm3\n"
        "andps %xmm1, %xmm3\n"
        "ucomiss 0x2ed658, %xmm3\n" /* line 412 | 0.0010000000474974513f */
        "jbe .Lf2cc74_0002ccbd\n"
        "movaps %xmm2, %xmm0\n" /* line 414 */
        "andps %xmm1, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lf2cc74_0002ccbd\n"
        "addss %xmm2, %xmm4\n" /* line 417 */
        "movss %xmm4, 8(%ebp)\n" /* tgt */
        /* } scope */
        ".Lf2cc74_0002ccbd:\n"
        "flds 8(%ebp)\n" /* line 421 | tgt */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2597 */
__attribute__((naked))
const vec_t RadiusFromBounds2D(const vec_t *mins, const vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2597 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %esi\n" /* mins */
        "movl 0xc(%ebp), %ebx\n" /* maxs */
        "movl $1, %edx\n"
        "movss 0x2efc30, %xmm2\n"
        "leal -0x10(%ebp), %ecx\n" /* corner */
        ".Lf2ccc2_0002cce0:\n"
        "leal (, %edx, 4), %eax\n"
        /* { scope 1 */
        "movss -4(%esi, %eax), %xmm1\n" /* line 54 */
        "andps %xmm2, %xmm1\n"
        "movss -4(%ebx, %eax), %xmm0\n"
        "andps %xmm2, %xmm0\n"
        "maxss %xmm0, %xmm1\n" /* line 2607 */
        "movss %xmm1, -4(%ecx, %eax)\n"
        "addl $1, %edx\n"
        "cmpl $3, %edx\n" /* line 2603 */
        "jne .Lf2ccc2_0002cce0\n"
        "movss -0x10(%ebp), %xmm1\n" /* line 134 | corner */
        "movss -0xc(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "flds -0x1c(%ebp)\n" /* line 2611 */
        "addl $0x18, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 599 */
__attribute__((naked))
jpeg_alloc ByteToDir(const int b, vec_t *dir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 599 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* b */
        "movl 0xc(%ebp), %ecx\n" /* dir */
        "cmpl $0xa1, %eax\n" /* line 601 */
        "jbe .Lf2cd34_0002cd50\n"
        "xorl %eax, %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl %eax, 4(%ecx)\n" /* line 200 */
        "movl %eax, 8(%ecx)\n" /* line 201 */
        "popl %ebp\n" /* line 608 */
        "retl\n"
        ".Lf2cd34_0002cd50:\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 604 */
        "shll $2, %eax\n"
        "leal bytedirs(%eax), %edx\n"
        /* { scope 1 */
        "movl bytedirs(%eax), %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 608 */
        "retl\n"
    );
}

/* line 2895 */
__attribute__((naked))
jpeg_alloc AxisCopy(vec3_t *in, double (*out)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2895 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* in */
        "movl 0xc(%ebp), %ecx\n" /* out */
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "leal 0xc(%ecx), %esi\n" /* line 2898 | to */
        "leal 0xc(%edx), %ebx\n" /* from */
        /* { scope 1 */
        "movl 0xc(%edx), %eax\n" /* line 199 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        /* } scope */
        "leal 0x18(%ecx), %esi\n" /* line 2899 | to */
        "leal 0x18(%edx), %ebx\n" /* from */
        /* { scope 1 */
        "movl 0x18(%edx), %eax\n" /* line 199 */
        "movl %eax, 0x18(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        /* } scope */
        "popl %ebx\n" /* line 2900 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 644 */
__attribute__((naked))
const vec_t Vec3DistanceSq(const vec_t *p1, const vec_t *p2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 644 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edx\n" /* p1 */
        "movl 0xc(%ebp), %eax\n" /* p2 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%edx), %xmm0\n"
        "movss 4(%eax), %xmm1\n" /* line 249 */
        "subss 4(%edx), %xmm1\n"
        "movss 8(%eax), %xmm2\n" /* line 250 */
        "subss 8(%edx), %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -4(%ebp)\n" /* line 650 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 1922 */
__attribute__((naked))
jpeg_alloc MatrixTransposeTransformVector43(const float *in1, const float (*in2)[3], float *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1922 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* in1 */
        "movl 0xc(%ebp), %eax\n" /* in2 */
        "movl 0x10(%ebp), %ebx\n" /* out */
        "leal 0x24(%eax), %ecx\n" /* line 1927 | b */
        /* { scope 1 */
        "movss (%edx), %xmm2\n" /* line 248 */
        "subss 0x24(%eax), %xmm2\n"
        "movss 4(%edx), %xmm3\n" /* line 249 */
        "subss 4(%ecx), %xmm3\n"
        "movss 8(%edx), %xmm4\n" /* line 250 */
        "subss 8(%ecx), %xmm4\n"
        /* } scope */
        "movaps %xmm2, %xmm0\n" /* line 1928 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* out */
        "leal 0xc(%eax), %edx\n" /* line 1929 */
        "movaps %xmm2, %xmm0\n"
        "mulss 0xc(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* out */
        "leal 0x18(%eax), %edx\n" /* line 1930 */
        "mulss 0x18(%eax), %xmm2\n"
        "mulss 4(%edx), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss 8(%edx), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, 8(%ebx)\n" /* out */
        "popl %ebx\n" /* line 1931 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2633 */
__attribute__((naked))
jpeg_alloc ExpandBoundsToWidth(vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2633 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* mins */
        "movl 0xc(%ebp), %edx\n" /* maxs */
        /* { scope 1 */
        "movss (%edx), %xmm1\n" /* line 248 */
        "subss (%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n" /* line 249 */
        "subss 4(%eax), %xmm0\n"
        "movss 8(%edx), %xmm3\n" /* line 250 */
        "subss 8(%eax), %xmm3\n"
        "movaps %xmm1, %xmm2\n" /* line 45 */
        "subss %xmm0, %xmm2\n"
        "movaps %xmm1, %xmm4\n"
        "cmpnltss 0x2ed5e8, %xmm2\n" /* 0.0f */
        "andps %xmm2, %xmm4\n"
        "andnps %xmm0, %xmm2\n"
        "orps %xmm4, %xmm2\n"
        "ucomiss %xmm3, %xmm2\n" /* line 2647 */
        "jbe .Lf2cea6_0002cf13\n"
        "movaps %xmm2, %xmm1\n" /* line 2649 */
        "subss %xmm3, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss 8(%eax), %xmm0\n" /* line 2650 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "addss 8(%edx), %xmm1\n" /* line 2651 */
        "movss %xmm1, 8(%edx)\n"
        /* } scope */
        ".Lf2cea6_0002cf13:\n"
        "popl %ebp\n" /* line 2653 */
        "retl\n"
    );
}

/* line 2656 */
__attribute__((naked))
jpeg_alloc ShrinkBoundsToHeight(vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2656 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* mins */
        "movl 0xc(%ebp), %edx\n" /* maxs */
        /* { scope 1 */
        "movss (%edx), %xmm0\n" /* line 248 */
        "subss (%eax), %xmm0\n"
        "movss 4(%edx), %xmm3\n" /* line 249 */
        "subss 4(%eax), %xmm3\n"
        "movss 8(%edx), %xmm2\n" /* line 250 */
        "subss 8(%eax), %xmm2\n"
        "ucomiss %xmm2, %xmm0\n" /* line 2667 */
        "jbe .Lf2cf16_0002cf63\n"
        "subss %xmm2, %xmm0\n" /* line 2669 */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movaps %xmm0, %xmm1\n" /* line 2670 */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movss (%edx), %xmm1\n" /* line 2671 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%edx)\n"
        ".Lf2cf16_0002cf63:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 2674 */
        "jbe .Lf2cf16_0002cf92\n"
        "movaps %xmm3, %xmm0\n" /* line 2676 */
        "subss %xmm2, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movaps %xmm0, %xmm1\n" /* line 2677 */
        "addss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "movss 4(%edx), %xmm1\n" /* line 2678 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        /* } scope */
        ".Lf2cf16_0002cf92:\n"
        "popl %ebp\n" /* line 2680 */
        "retl\n"
    );
}

/* line 3686 */
__attribute__((naked))
qboolean BoxDistSqrdExceeds(const vec_t *absmin, const vec_t *absmax, const vec_t *org, const float fogOpaqueDistSqrd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3686 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %edx\n" /* absmin */
        "movl 0xc(%ebp), %ecx\n" /* absmax */
        "movl 0x10(%ebp), %eax\n" /* org */
        /* { scope 1 */
        "movss (%eax), %xmm3\n" /* line 248 */
        "movss (%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* mins */
        "movss 4(%eax), %xmm2\n" /* line 249 */
        "movss 4(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 250 */
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "movss (%ecx), %xmm0\n" /* line 248 */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* maxs */
        "movss 4(%ecx), %xmm0\n" /* line 249 */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss 8(%ecx), %xmm0\n" /* line 250 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm4\n"
        "movl $1, %edx\n"
        "leal -0x14(%ebp), %ebx\n" /* mins */
        "leal -0x20(%ebp), %ecx\n" /* maxs */
        ".Lf2cf94_0002d016:\n"
        "leal (, %edx, 4), %eax\n" /* line 3701 */
        "movss -4(%ebx, %eax), %xmm1\n"
        "movss -4(%ecx, %eax), %xmm2\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jae .Lf2cf94_0002d048\n"
        "mulss %xmm1, %xmm1\n" /* line 3703 */
        "movaps %xmm2, %xmm0\n" /* line 3704 */
        "mulss %xmm2, %xmm0\n"
        "minss %xmm1, %xmm0\n" /* line 3705 */
        "addss %xmm0, %xmm3\n"
        ".Lf2cf94_0002d048:\n"
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 3699 */
        "jne .Lf2cf94_0002d016\n"
        "xorl %eax, %eax\n"
        "ucomiss 0x14(%ebp), %xmm3\n" /* fogOpaqueDistSqrd */
        "seta %al\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 3709 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 570 */
__attribute__((naked))
const byte DirToByte(const vec_t *dir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 570 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* dir */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 575 */
        "je .Lf2d060_0002d0c6\n"
        "movss (%eax), %xmm4\n" /* line 304 */
        "movss 4(%eax), %xmm3\n"
        "movss 8(%eax), %xmm2\n"
        "pxor %xmm5, %xmm5\n"
        "xorl %eax, %eax\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf2d060_0002d082:\n"
        "movaps %xmm4, %xmm1\n"
        "mulss bytedirs(%edx), %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x3083c4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x3083c8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm5, %xmm1\n" /* line 583 */
        "jbe .Lf2d060_0002d0b5\n"
        "movaps %xmm1, %xmm5\n"
        "movl %ecx, %eax\n"
        ".Lf2d060_0002d0b5:\n"
        "addl $1, %ecx\n"
        "addl $0xc, %edx\n"
        "cmpl $0xa2, %ecx\n" /* line 580 */
        "jne .Lf2d060_0002d082\n"
        "movzbl %al, %eax\n" /* line 590 */
        /* } scope */
        ".Lf2d060_0002d0c6:\n"
        "popl %ebp\n" /* line 591 */
        "retl\n"
    );
}

/* line 2837 */
__attribute__((naked))
jpeg_alloc GetRotatedBounds(vec3_t *baseBounds, const vec_t *origin, vec3_t *axis, double (*rotatedBounds)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2837 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* baseBounds */
        "addl $0xc, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* axis */
        "addl $0xc, %edi\n"
        "movl %edi, -0x24(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* axis */
        "addl $0x18, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* rotatedBounds */
        "leal 0xc(%edx), %ecx\n"
        "movl %eax, %esi\n"
        "movl $0, -0x18(%ebp)\n" /* axisIndex */
        "movl 8(%ebp), %edi\n" /* baseBounds */
        "addl $0x10, %edi\n"
        "movl %edi, -0x1c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* baseBounds */
        "addl $0x14, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "xorl %ebx, %ebx\n"
        /* { scope 1 */
        ".Lf2d0c8_0002d10f:\n"
        "movl 0xc(%ebp), %edi\n" /* line 2844 | origin */
        "movss (%ebx, %edi), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%ebx, %edi), %xmm0\n" /* line 2845 */
        "movss %xmm0, (%ecx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 2847 | axis */
        "movl (%ebx, %eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movl 8(%ebp), %edi\n" /* line 2848 | baseBounds */
        "movss (%edi, %eax), %xmm0\n"
        "movl 0x10(%ebp), %edi\n" /* axis */
        "mulss (%ebx, %edi), %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl -0x14(%ebp), %edi\n" /* line 2849 */
        "subl %eax, %edi\n"
        "movss (%edi), %xmm0\n"
        "movl 0x10(%ebp), %eax\n" /* axis */
        "mulss (%ebx, %eax), %xmm0\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movl -0x24(%ebp), %edi\n" /* line 2851 */
        "movl (%ebx, %edi), %eax\n"
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movl 8(%ebp), %edi\n" /* line 2852 | baseBounds */
        "movss 4(%edi, %eax), %xmm0\n"
        "movl -0x24(%ebp), %edi\n"
        "mulss (%ebx, %edi), %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl -0x1c(%ebp), %edi\n" /* line 2853 */
        "subl %eax, %edi\n"
        "movss (%edi), %xmm0\n"
        "movl -0x24(%ebp), %eax\n"
        "mulss (%ebx, %eax), %xmm0\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movl -0x10(%ebp), %edi\n" /* line 2855 */
        "movl (%ebx, %edi), %eax\n"
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movl 8(%ebp), %edi\n" /* line 2856 | baseBounds */
        "movss 8(%edi, %eax), %xmm0\n"
        "mulss (%esi), %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl -0x20(%ebp), %edi\n" /* line 2857 */
        "subl %eax, %edi\n"
        "movss (%edi), %xmm0\n"
        "mulss (%esi), %xmm0\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "addl $1, -0x18(%ebp)\n" /* line 2842 | axisIndex */
        "addl $4, %ebx\n"
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "addl $4, %esi\n"
        "cmpl $3, -0x18(%ebp)\n" /* axisIndex */
        "jne .Lf2d0c8_0002d10f\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 2859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3733 */
__attribute__((naked))
const vec_t ColorNormalize(const vec_t *in, vec_t *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3733 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* in */
        "movl 0xc(%ebp), %edx\n" /* out */
        /* { scope 1 */
        "movss (%eax), %xmm1\n" /* line 3737 */
        "leal 4(%eax), %ebx\n" /* line 3738 */
        "movss 4(%eax), %xmm0\n"
        "maxss %xmm1, %xmm0\n"
        "leal 8(%eax), %ecx\n" /* line 3740 */
        "movss 8(%eax), %xmm2\n"
        "maxss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 3743 */
        "ucomiss %xmm0, %xmm2\n"
        "jne .Lf2d1fa_0002d24c\n"
        "jp .Lf2d1fa_0002d24c\n"
        "movl $0x3f800000, %eax\n" /* line 3745 */
        "movl %eax, 8(%edx)\n"
        "movl %eax, 4(%edx)\n"
        "movl %eax, (%edx)\n"
        "movaps %xmm0, %xmm2\n"
        /* } scope */
        "movss %xmm2, -8(%ebp)\n" /* line 3754 */
        "flds -8(%ebp)\n"
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2d1fa_0002d24c:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 3749 | 1.0f */
        "divss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n" /* line 272 */
        "movss %xmm1, (%edx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss (%ebx), %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "mulss (%ecx), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "movss %xmm2, -8(%ebp)\n" /* line 3754 */
        "flds -8(%ebp)\n"
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2683 */
__attribute__((naked))
jpeg_alloc ClearBounds(vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2683 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* mins */
        "movl 0xc(%ebp), %ecx\n" /* maxs */
        "movl $0x48000000, %eax\n" /* line 191 */
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        "movl $0xc8000000, %eax\n" /* line 191 */
        "movl %eax, (%ecx)\n"
        "movl %eax, 4(%ecx)\n" /* line 192 */
        "movl %eax, 8(%ecx)\n" /* line 193 */
        "popl %ebp\n" /* line 2687 */
        "retl\n"
    );
}

/* line 790 */
__attribute__((naked))
const vec_t Vec3Normalize(vec_t *v)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 790 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* v */
        /* { scope 1 */
        "movss (%eax), %xmm3\n" /* line 794 */
        "movss 4(%eax), %xmm0\n"
        "movss 8(%eax), %xmm2\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm2\n" /* line 81 */
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 797 | 0.0f */
        "jp .Lf2d2aa_0002d2e7\n"
        "je .Lf2d2aa_0002d312\n"
        ".Lf2d2aa_0002d2e7:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 799 | 1.0f */
        "divss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n" /* line 800 */
        "movss %xmm3, (%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 801 */
        "mulss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%eax), %xmm0\n" /* line 802 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lf2d2aa_0002d312:\n"
        "movss %xmm2, -4(%ebp)\n" /* line 806 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 814 */
__attribute__((naked))
const vec_t Vec2Normalize(vec_t *v)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 814 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* v */
        /* { scope 1 */
        "movss (%eax), %xmm2\n" /* line 818 */
        "movss 4(%eax), %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n" /* line 81 */
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 821 | 0.0f */
        "jp .Lf2d31c_0002d34c\n"
        "je .Lf2d31c_0002d36a\n"
        ".Lf2d31c_0002d34c:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 823 | 1.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n" /* line 824 */
        "movss %xmm2, (%eax)\n"
        "mulss 4(%eax), %xmm0\n" /* line 825 */
        "movss %xmm0, 4(%eax)\n"
        /* } scope */
        ".Lf2d31c_0002d36a:\n"
        "movss %xmm1, -4(%ebp)\n" /* line 829 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 1148 */
__attribute__((naked))
const float vectopitch(const vec_t *vec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1148 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl 8(%ebp), %eax\n" /* vec */
        /* { scope 1 */
        "movss 4(%eax), %xmm1\n" /* line 1153 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jne .Lf2d376_0002d3b2\n"
        "jp .Lf2d376_0002d3b2\n"
        "ucomiss (%eax), %xmm2\n"
        "jne .Lf2d376_0002d3b2\n"
        "jp .Lf2d376_0002d3b2\n"
        "movss 8(%eax), %xmm0\n" /* line 1155 */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf2d376_0002d41c\n"
        "movss 0x2ed65c, %xmm0\n" /* 270.0f */
        /* } scope */
        ".Lf2d376_0002d3a8:\n"
        "movss %xmm0, -0x24(%ebp)\n" /* line 1169 */
        "flds -0x24(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2d376_0002d3b2:\n"
        "movss (%eax), %xmm0\n" /* line 1162 */
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "cvtss2sd 8(%eax), %xmm1\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movsd %xmm1, (%esp)\n"
        "movss %xmm2, -0x18(%ebp)\n"
        "calll atan2\n"
        "fstpl -0x20(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "mulsd 0x307c58, %xmm0\n" /* -180.0 */
        "divsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss -0x18(%ebp), %xmm2\n" /* line 1164 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf2d376_0002d3a8\n"
        "addss 0x2ed638, %xmm0\n" /* line 1165 | 360.0f */
        /* } scope */
        "movss %xmm0, -0x24(%ebp)\n" /* line 1169 */
        "flds -0x24(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2d376_0002d41c:\n"
        "movss 0x2ed5f8, %xmm0\n" /* line 1155 | 90.0f */
        "jmp .Lf2d376_0002d3a8\n"
    );
}

/* line 1204 */
__attribute__((naked))
jpeg_alloc vectoangles(const vec_t *vec, vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1204 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %ebx\n" /* vec */
        "movl 0xc(%ebp), %esi\n" /* angles */
        /* { scope 1 */
        "movss 4(%ebx), %xmm2\n" /* line 1209 | vec */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jne .Lf2d426_0002d480\n"
        "jp .Lf2d426_0002d480\n"
        "ucomiss (%ebx), %xmm0\n" /* vec */
        "jne .Lf2d426_0002d480\n"
        "jp .Lf2d426_0002d480\n"
        "movss 8(%ebx), %xmm0\n" /* line 1212 | vec */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf2d426_0002d55d\n"
        "pxor %xmm3, %xmm3\n"
        "movss 0x2ed65c, %xmm0\n" /* 270.0f */
        ".Lf2d426_0002d469:\n"
        "movss %xmm0, (%esi)\n" /* line 1229 | angles */
        "movss %xmm3, 4(%esi)\n" /* line 1230 | angles */
        "movl $0, 8(%esi)\n" /* line 1231 | angles */
        /* } scope */
        "addl $0x50, %esp\n" /* line 1232 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2d426_0002d480:\n"
        "movss (%ebx), %xmm1\n" /* line 1219 | vec */
        "cvtss2sd %xmm1, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x18(%ebp)\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "calll atan2\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x40(%ebp), %xmm0\n"
        "mulsd 0x307c38, %xmm0\n" /* 180.0 */
        "divsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm3\n"
        "pxor %xmm0, %xmm0\n" /* line 1220 */
        "ucomiss %xmm3, %xmm0\n"
        "movss -0x18(%ebp), %xmm1\n"
        "movss -0x28(%ebp), %xmm2\n"
        "ja .Lf2d426_0002d550\n"
        ".Lf2d426_0002d4d5:\n"
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "cvtss2sd 8(%ebx), %xmm0\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 8(%esp)\n"
        "movsd %xmm0, (%esp)\n"
        "movss %xmm3, -0x38(%ebp)\n"
        "calll atan2\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x40(%ebp), %xmm0\n"
        "mulsd 0x307c58, %xmm0\n" /* -180.0 */
        "divsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "pxor %xmm1, %xmm1\n" /* line 1225 */
        "ucomiss %xmm0, %xmm1\n"
        "movss -0x38(%ebp), %xmm3\n"
        "jbe .Lf2d426_0002d469\n"
        "addss 0x2ed638, %xmm0\n" /* line 1226 | 360.0f */
        "movss %xmm0, (%esi)\n" /* line 1229 | angles */
        "movss %xmm3, 4(%esi)\n" /* line 1230 | angles */
        "movl $0, 8(%esi)\n" /* line 1231 | angles */
        /* } scope */
        "addl $0x50, %esp\n" /* line 1232 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2d426_0002d550:\n"
        "addss 0x2ed638, %xmm3\n" /* line 1221 | 360.0f */
        "jmp .Lf2d426_0002d4d5\n"
        ".Lf2d426_0002d55d:\n"
        "pxor %xmm3, %xmm3\n" /* line 1212 */
        "movss 0x2ed5f8, %xmm0\n" /* 90.0f */
        "jmp .Lf2d426_0002d469\n"
    );
}

/* line 2580 */
__attribute__((naked))
const vec_t RadiusFromBounds(const vec_t *mins, const vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2580 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* mins */
        "movl 0xc(%ebp), %ebx\n" /* maxs */
        "movl $1, %edx\n"
        "movss 0x2efc50, %xmm2\n"
        "leal -0x14(%ebp), %ecx\n" /* corner */
        ".Lf2d570_0002d58e:\n"
        "leal (, %edx, 4), %eax\n"
        /* { scope 1 */
        "movss -4(%esi, %eax), %xmm1\n" /* line 54 */
        "andps %xmm2, %xmm1\n"
        "movss -4(%ebx, %eax), %xmm0\n"
        "andps %xmm2, %xmm0\n"
        "maxss %xmm0, %xmm1\n" /* line 2590 */
        "movss %xmm1, -4(%ecx, %eax)\n"
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 2586 */
        "jne .Lf2d570_0002d58e\n"
        "movss -0x14(%ebp), %xmm2\n" /* line 324 | corner */
        "movss -0x10(%ebp), %xmm0\n"
        "movss -0xc(%ebp), %xmm1\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "movss %xmm2, -0x1c(%ebp)\n"
        /* } scope */
        "flds -0x1c(%ebp)\n" /* line 2594 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2459 */
__attribute__((naked))
jpeg_alloc AnglesSubtract(const vec_t *v1, const vec_t *v2, vec_t *v3)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2459 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* v1 */
        "movl 0xc(%ebp), %ebx\n" /* v2 */
        "movl 0x10(%ebp), %edx\n" /* v3 */
        /* { scope 1 */
        "movss (%ecx), %xmm0\n" /* line 2443 */
        "subss (%ebx), %xmm0\n"
        "ucomiss 0x2ed64c, %xmm0\n" /* line 2444 | 180.0f */
        "jbe .Lf2d5f0_0002d627\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        "movss 0x2ed64c, %xmm1\n" /* 180.0f */
        ".Lf2d5f0_0002d61e:\n"
        "subss %xmm3, %xmm0\n" /* line 2445 */
        "ucomiss %xmm1, %xmm0\n" /* line 2444 */
        "ja .Lf2d5f0_0002d61e\n"
        ".Lf2d5f0_0002d627:\n"
        "movss 0x2ed650, %xmm2\n" /* line 2447 | -180.0f */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf2d5f0_0002d645\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        ".Lf2d5f0_0002d63c:\n"
        "addss %xmm3, %xmm0\n" /* line 2448 */
        "ucomiss %xmm0, %xmm2\n" /* line 2447 */
        "ja .Lf2d5f0_0002d63c\n"
        /* } scope */
        ".Lf2d5f0_0002d645:\n"
        "movss %xmm0, (%edx)\n" /* line 2461 */
        "leal 4(%edx), %eax\n" /* line 2462 */
        /* { scope 1 */
        "movss 4(%ecx), %xmm0\n" /* line 2443 */
        "subss 4(%ebx), %xmm0\n"
        "ucomiss 0x2ed64c, %xmm0\n" /* line 2444 | 180.0f */
        "jbe .Lf2d5f0_0002d678\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        "movss 0x2ed64c, %xmm1\n" /* 180.0f */
        ".Lf2d5f0_0002d66f:\n"
        "subss %xmm3, %xmm0\n" /* line 2445 */
        "ucomiss %xmm1, %xmm0\n" /* line 2444 */
        "ja .Lf2d5f0_0002d66f\n"
        ".Lf2d5f0_0002d678:\n"
        "ucomiss %xmm0, %xmm2\n" /* line 2447 */
        "jbe .Lf2d5f0_0002d68e\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        ".Lf2d5f0_0002d685:\n"
        "addss %xmm3, %xmm0\n" /* line 2448 */
        "ucomiss %xmm0, %xmm2\n" /* line 2447 */
        "ja .Lf2d5f0_0002d685\n"
        /* } scope */
        ".Lf2d5f0_0002d68e:\n"
        "movss %xmm0, (%eax)\n" /* line 2462 */
        "leal 8(%edx), %eax\n" /* line 2463 */
        /* { scope 1 */
        "movss 8(%ecx), %xmm0\n" /* line 2443 */
        "subss 8(%ebx), %xmm0\n"
        "ucomiss 0x2ed64c, %xmm0\n" /* line 2444 | 180.0f */
        "jbe .Lf2d5f0_0002d6c1\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        "movss 0x2ed64c, %xmm1\n" /* 180.0f */
        ".Lf2d5f0_0002d6b8:\n"
        "subss %xmm3, %xmm0\n" /* line 2445 */
        "ucomiss %xmm1, %xmm0\n" /* line 2444 */
        "ja .Lf2d5f0_0002d6b8\n"
        ".Lf2d5f0_0002d6c1:\n"
        "ucomiss %xmm0, %xmm2\n" /* line 2447 */
        "jbe .Lf2d5f0_0002d6d7\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        ".Lf2d5f0_0002d6ce:\n"
        "addss %xmm3, %xmm0\n" /* line 2448 */
        "ucomiss %xmm0, %xmm2\n" /* line 2447 */
        "ja .Lf2d5f0_0002d6ce\n"
        /* } scope */
        ".Lf2d5f0_0002d6d7:\n"
        "movss %xmm0, (%eax)\n" /* line 2463 */
        "popl %ebx\n" /* line 2464 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 862 */
__attribute__((naked))
const vec_t Vec3NormalizeTo(const vec_t *v, vec_t *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 862 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* v */
        "movl 0xc(%ebp), %edx\n" /* out */
        /* { scope 1 */
        "movss (%eax), %xmm3\n" /* line 866 */
        "movss 4(%eax), %xmm0\n"
        "movss 8(%eax), %xmm2\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm2\n" /* line 81 */
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 869 | 0.0f */
        "jp .Lf2d6de_0002d71e\n"
        "je .Lf2d6de_0002d753\n"
        ".Lf2d6de_0002d71e:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 871 | 1.0f */
        "divss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n" /* line 872 */
        "movss %xmm3, (%edx)\n"
        "movaps %xmm0, %xmm1\n" /* line 873 */
        "mulss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "mulss 8(%eax), %xmm0\n" /* line 874 */
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "movss %xmm2, -4(%ebp)\n" /* line 883 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2d6de_0002d753:\n"
        "movl $0, (%edx)\n" /* line 183 */
        "movl $0, 4(%edx)\n" /* line 184 */
        "movl $0, 8(%edx)\n" /* line 185 */
        /* } scope */
        "movss %xmm2, -4(%ebp)\n" /* line 883 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 720 */
__attribute__((naked))
int Vec3MajorAxis(const vec_t *dir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 720 */
        "movl %esp, %ebp\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* dir */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 280 */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n" /* dirSq */
        "movss 4(%eax), %xmm0\n" /* line 281 */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -8(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 282 */
        "mulss %xmm1, %xmm1\n"
        "movss %xmm1, -4(%ebp)\n"
        "xorl %edx, %edx\n"
        "ucomiss -0xc(%ebp), %xmm0\n" /* dirSq */
        "seta %dl\n"
        "movl $2, %eax\n" /* line 729 */
        "ucomiss -0xc(%ebp, %edx, 4), %xmm1\n"
        "cmovbel %edx, %eax\n"
        /* } scope */
        "leave\n" /* line 732 */
        "retl\n"
    );
}

/* line 2487 */
__attribute__((naked))
const float AngleNormalize180(const float angle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2487 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        /* { scope 1 */
        "movss 0x2ed644, %xmm0\n" /* line 2476 | 182.04444885253906f */
        "mulss 8(%ebp), %xmm0\n" /* angle */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed648, %xmm0\n" /* 0.0054931640625f */
        "ucomiss 0x2ed64c, %xmm0\n" /* line 2491 | 180.0f */
        "jbe .Lf2d7bc_0002d7f5\n"
        "subss 0x2ed638, %xmm0\n" /* line 2492 | 360.0f */
        /* } scope */
        ".Lf2d7bc_0002d7f5:\n"
        "movss %xmm0, -4(%ebp)\n" /* line 2495 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 2567 */
__attribute__((naked))
const float AngleDelta(const float angle1, const float angle2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2567 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* angle1 */
        /* { scope 1 */
        "subss 0xc(%ebp), %xmm0\n" /* line 2476 | angle2 */
        "mulss 0x2ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed648, %xmm0\n" /* 0.0054931640625f */
        "ucomiss 0x2ed64c, %xmm0\n" /* line 2491 | 180.0f */
        "jbe .Lf2d800_0002d83e\n"
        "subss 0x2ed638, %xmm0\n" /* line 2492 | 360.0f */
        /* } scope */
        ".Lf2d800_0002d83e:\n"
        "movss %xmm0, -4(%ebp)\n" /* line 2570 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 630 */
__attribute__((naked))
const vec_t Vec3Distance(const vec_t *v1, const vec_t *v2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 630 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edx\n" /* v1 */
        "movl 0xc(%ebp), %eax\n" /* v2 */
        "movss (%eax), %xmm2\n" /* line 248 */
        "subss (%edx), %xmm2\n"
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edx), %xmm0\n"
        "movss 8(%eax), %xmm1\n" /* line 250 */
        "subss 8(%edx), %xmm1\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "movss %xmm2, -4(%ebp)\n"
        "flds -4(%ebp)\n" /* line 636 */
        "leave\n"
        "retl\n"
    );
}

/* line 429 */
__attribute__((naked))
float DiffTrackAngle(float tgt, float cur, float rate, float deltaTime, float f, float granularity, float epsilon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 429 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm1\n" /* tgt */
        "movss 0xc(%ebp), %xmm5\n" /* cur */
        /* { scope 1 */
        "movaps %xmm1, %xmm0\n" /* line 433 */
        "subss %xmm5, %xmm0\n"
        "ucomiss 0x2ed64c, %xmm0\n" /* 180.0f */
        "jbe .Lf2d894_0002d8d4\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        "movss 0x2ed64c, %xmm2\n" /* 180.0f */
        ".Lf2d894_0002d8c4:\n"
        "subss %xmm3, %xmm1\n" /* line 434 */
        "movaps %xmm1, %xmm0\n" /* line 433 */
        "subss %xmm5, %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf2d894_0002d8c4\n"
        ".Lf2d894_0002d8d4:\n"
        "movss 0x2ed650, %xmm2\n" /* line 435 | -180.0f */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf2d894_0002d8f9\n"
        "movss 0x2ed638, %xmm3\n" /* 360.0f */
        ".Lf2d894_0002d8e9:\n"
        "addss %xmm3, %xmm1\n" /* line 436 */
        "movaps %xmm1, %xmm0\n" /* line 435 */
        "subss %xmm5, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf2d894_0002d8e9\n"
        ".Lf2d894_0002d8f9:\n"
        "movaps %xmm0, %xmm3\n" /* line 410 */
        "mulss 0x10(%ebp), %xmm3\n" /* rate */
        "mulss 0x14(%ebp), %xmm3\n" /* deltaTime */
        "movss 0x2efc90, %xmm2\n" /* line 54 */
        "movaps %xmm0, %xmm4\n"
        "andps %xmm2, %xmm4\n"
        "ucomiss 0x2ed658, %xmm4\n" /* line 412 | 0.0010000000474974513f */
        "jbe 0x2d928\n"
    );
}

/* line 153 */
__attribute__((naked))
float crandom(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll rand\n" /* line 144 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed630, %xmm0\n" /* 4.656612873077393e-10f */
        "addss %xmm0, %xmm0\n"
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0xc(%ebp)\n" /* line 156 */
        "flds -0xc(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 159 */
__attribute__((naked))
jpeg_alloc GaussianRandom(float *f0, float *f1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "subl $0x58, %esp\n"
        /* { scope 1 */
        ".Lf2d99c_0002d9a2:\n"
        "calll rand\n" /* line 144 */
        "cvtsi2ssl %eax, %xmm3\n" /* line 155 */
        "mulss 0x2ed630, %xmm3\n" /* 4.656612873077393e-10f */
        "addss %xmm3, %xmm3\n"
        "subss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movss %xmm3, -0x38(%ebp)\n" /* line 144 */
        "calll rand\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 155 */
        "mulss 0x2ed630, %xmm2\n" /* 4.656612873077393e-10f */
        "addss %xmm2, %xmm2\n"
        "subss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm3\n" /* line 172 */
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5d0, %xmm1\n" /* line 168 | 1.0f */
        "ja .Lf2d99c_0002d9a2\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 176 */
        "movsd %xmm1, -0x10(%ebp)\n"
        "movsd %xmm1, (%esp)\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "calll log\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x40(%ebp), %xmm0\n"
        "mulsd 0x307c60, %xmm0\n" /* -2.0 */
        "divsd -0x10(%ebp), %xmm0\n"
        "cvtsd2ss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "movss -0x38(%ebp), %xmm3\n" /* line 177 */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movl 8(%ebp), %eax\n" /* f0 */
        "movss %xmm0, (%eax)\n"
        "movss -0x28(%ebp), %xmm2\n" /* line 178 */
        "mulss %xmm2, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* f1 */
        "movss %xmm1, (%eax)\n"
        /* } scope */
        "leave\n" /* line 179 */
        "retl\n"
    );
}

/* line 1756 */
__attribute__((naked))
jpeg_alloc MatrixInverseOrthogonal43(const float (*in)[3], float (*out)[3])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1756 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edx\n" /* in */
        "movl 0xc(%ebp), %ecx\n" /* out */
        "movl (%edx), %eax\n" /* line 1685 */
        "movl %eax, (%ecx)\n"
        "leal 0xc(%edx), %esi\n" /* line 1686 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "leal 0x18(%edx), %edi\n" /* line 1687 */
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "leal 0xc(%ecx), %eax\n" /* line 1688 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%esi), %eax\n" /* line 1689 */
        "movl -0x10(%ebp), %ebx\n"
        "movl %eax, 4(%ebx)\n"
        "movl 4(%edi), %eax\n" /* line 1690 */
        "movl %eax, 8(%ebx)\n"
        "leal 0x18(%ecx), %ebx\n" /* line 1691 */
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x18(%ecx)\n"
        "movl 8(%esi), %eax\n" /* line 1692 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edi), %eax\n" /* line 1693 */
        "movl %eax, 8(%ebx)\n"
        "leal 0x24(%edx), %eax\n" /* line 1761 | b */
        /* { scope 1 */
        "pxor %xmm2, %xmm2\n" /* line 248 */
        "movaps %xmm2, %xmm3\n"
        "subss 0x24(%edx), %xmm3\n"
        "movaps %xmm2, %xmm4\n" /* line 249 */
        "subss 4(%eax), %xmm4\n"
        "subss 8(%eax), %xmm2\n" /* line 250 */
        /* } scope */
        "leal 0x24(%ecx), %eax\n" /* line 1762 | out */
        /* { scope 1 */
        "movaps %xmm3, %xmm0\n" /* line 1868 */
        "mulss (%ecx), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0xc(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 0x18(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x24(%ecx)\n"
        "movaps %xmm3, %xmm0\n" /* line 1869 */
        "mulss 4(%ecx), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "movl -0x10(%ebp), %edx\n"
        "mulss 4(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%ecx), %xmm3\n" /* line 1870 */
        "mulss 8(%edx), %xmm4\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%ebx), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, 8(%eax)\n"
        /* } scope */
        "addl $4, %esp\n" /* line 1763 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3177 */
__attribute__((naked))
qboolean WindingContainsCoplanarPoint(vec3_t *verts, int vertCount, const vec_t *normal, const vec_t *point)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3177 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* normal */
        /* { scope 1 */
        "movss (%eax), %xmm4\n" /* line 280 */
        "movaps %xmm4, %xmm5\n"
        "mulss %xmm4, %xmm5\n"
        "movss 4(%eax), %xmm3\n" /* line 281 */
        "movaps %xmm3, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss 8(%eax), %xmm0\n" /* line 282 */
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "ucomiss %xmm5, %xmm1\n" /* line 742 */
        "jb .Lf2db42_0002db7f\n"
        "ucomiss %xmm2, %xmm1\n"
        "jae .Lf2db42_0002dc5b\n"
        ".Lf2db42_0002db7f:\n"
        "ucomiss %xmm5, %xmm2\n" /* line 755 */
        "jae .Lf2db42_0002dc3d\n"
        ".Lf2db42_0002db88:\n"
        "pxor %xmm6, %xmm6\n" /* line 770 */
        "ucomiss %xmm6, %xmm4\n"
        "jbe .Lf2db42_0002dc70\n"
        "movl $1, %edi\n"
        "movl $2, %esi\n"
        ".Lf2db42_0002db9f:\n"
        "movl 0xc(%ebp), %edx\n" /* line 3189 | vertCount */
        "subl $1, %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* vertCount */
        "testl %ecx, %ecx\n"
        "jle .Lf2db42_0002dc30\n"
        "movl 0x14(%ebp), %eax\n" /* line 3193 | point */
        "movss (%eax, %edi, 4), %xmm5\n"
        "movss (%eax, %esi, 4), %xmm4\n" /* line 3194 */
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n"
        "leal (, %esi, 4), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "leal (, %edi, 4), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "jmp .Lf2db42_0002dbd9\n"
        ".Lf2db42_0002dbd7:\n"
        "movl %eax, %ecx\n" /* line 3189 */
        ".Lf2db42_0002dbd9:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 3191 */
        "movl 8(%ebp), %edx\n" /* verts */
        "leal (%edx, %eax, 4), %eax\n"
        "movss (%eax, %esi, 4), %xmm3\n"
        "movss (%eax, %edi, 4), %xmm2\n" /* line 3192 */
        "movl %edx, %eax\n" /* line 3196 */
        "addl %ebx, %eax\n"
        "movl -0x10(%ebp), %edx\n"
        "movss (%eax, %edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "movl -0x14(%ebp), %edx\n"
        "subss (%eax, %edx), %xmm2\n"
        "movaps %xmm4, %xmm1\n"
        "subss %xmm3, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm6\n"
        "ja .Lf2db42_0002dc8b\n"
        "leal 1(%ecx), %eax\n" /* line 3189 */
        "addl $0xc, %ebx\n"
        "movl %ecx, %edx\n"
        "cmpl %eax, 0xc(%ebp)\n" /* vertCount */
        "jne .Lf2db42_0002dbd7\n"
        ".Lf2db42_0002dc30:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $8, %esp\n" /* line 3201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2db42_0002dc3d:\n"
        "ucomiss %xmm1, %xmm2\n" /* line 755 */
        "jb .Lf2db42_0002db88\n"
        "pxor %xmm6, %xmm6\n" /* line 757 */
        "ucomiss %xmm6, %xmm3\n"
        "jbe .Lf2db42_0002dc95\n"
        "movl $2, %edi\n"
        "xorl %esi, %esi\n"
        "jmp .Lf2db42_0002db9f\n"
        ".Lf2db42_0002dc5b:\n"
        "pxor %xmm6, %xmm6\n" /* line 744 */
        "ucomiss %xmm6, %xmm0\n"
        "jbe .Lf2db42_0002dc7f\n"
        "xorl %edi, %edi\n"
        "movl $1, %esi\n"
        "jmp .Lf2db42_0002db9f\n"
        ".Lf2db42_0002dc70:\n"
        "movl $2, %edi\n" /* line 770 */
        "movl $1, %esi\n"
        "jmp .Lf2db42_0002db9f\n"
        ".Lf2db42_0002dc7f:\n"
        "movl $1, %edi\n" /* line 744 */
        "xorl %esi, %esi\n"
        "jmp .Lf2db42_0002db9f\n"
        ".Lf2db42_0002dc8b:\n"
        "xorl %eax, %eax\n" /* line 3189 */
        /* } scope */
        "addl $8, %esp\n" /* line 3201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2db42_0002dc95:\n"
        "xorl %edi, %edi\n" /* line 757 */
        "movl $2, %esi\n"
        "jmp .Lf2db42_0002db9f\n"
    );
}

/* line 1077 */
__attribute__((naked))
jpeg_alloc MakeNormalVectors(const vec_t *forward, vec_t *right, vec_t *up)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1077 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %ecx\n" /* forward */
        "movl 0xc(%ebp), %edx\n" /* right */
        "movl 0x10(%ebp), %edi\n" /* up */
        "leal 4(%edx), %eax\n" /* line 1083 */
        "movl %eax, -0x14(%ebp)\n"
        "movss 0x2efcd0, %xmm3\n"
        "movss (%ecx), %xmm1\n"
        "xorps %xmm3, %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "leal 8(%edx), %esi\n" /* line 1084 */
        "leal 4(%ecx), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movss 4(%ecx), %xmm2\n"
        "movss %xmm2, 8(%edx)\n"
        "leal 8(%ecx), %ebx\n" /* line 1085 */
        "movl 8(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movss (%ecx), %xmm4\n" /* line 304 */
        "movaps %xmm4, %xmm0\n" /* line 1088 | scale */
        "mulss (%edx), %xmm0\n" /* scale */
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n" /* scale */
        "mulss 8(%ecx), %xmm2\n"
        "addss %xmm2, %xmm0\n" /* scale */
        "xorps %xmm3, %xmm0\n" /* scale */
        /* { scope 1 */
        "mulss %xmm0, %xmm4\n" /* line 288 */
        "addss (%edx), %xmm4\n"
        "movss %xmm4, (%edx)\n"
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss 4(%ecx), %xmm1\n"
        "addss 4(%edx), %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 290 */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        /* { scope 1 */
        "movaps %xmm4, %xmm2\n" /* line 81 */
        "mulss %xmm4, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 797 | 0.0f */
        "jp .Lf2dca2_0002dd5c\n"
        "je .Lf2dca2_0002dd87\n"
        ".Lf2dca2_0002dd5c:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 799 | 1.0f */
        "divss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n" /* line 800 */
        "movss %xmm4, (%edx)\n"
        "movaps %xmm0, %xmm1\n" /* line 801 */
        "mulss 4(%edx), %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "mulss 8(%edx), %xmm0\n" /* line 802 */
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        ".Lf2dca2_0002dd87:\n"
        "movl -0x14(%ebp), %eax\n" /* line 713 */
        "movss (%eax), %xmm1\n"
        "mulss (%ebx), %xmm1\n"
        "movss (%esi), %xmm0\n"
        "movl -0x10(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movss (%esi), %xmm1\n" /* line 714 */
        "mulss (%ecx), %xmm1\n"
        "movss (%edx), %xmm0\n"
        "mulss (%ebx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "movss (%edx), %xmm1\n" /* line 715 */
        "mulss (%eax), %xmm1\n"
        "movl -0x14(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "mulss (%ecx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "addl $8, %esp\n" /* line 1091 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1349 */
__attribute__((naked))
jpeg_alloc PerpendicularVector(const vec_t *src, vec_t *dst)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1349 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* src */
        "movl 0xc(%ebp), %ebx\n" /* dst */
        /* { scope 1 */
        "movss (%ecx), %xmm2\n" /* line 1358 */
        "movaps %xmm2, %xmm3\n"
        "mulss %xmm2, %xmm3\n"
        "movss %xmm3, -0x10(%ebp)\n" /* srcSq */
        "movss 4(%ecx), %xmm0\n" /* line 1359 */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "movss 8(%ecx), %xmm1\n" /* line 1360 */
        "mulss %xmm1, %xmm1\n"
        "movss %xmm1, -8(%ebp)\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm0, %xmm3\n"
        "seta %al\n"
        "movss -0x10(%ebp, %eax, 4), %xmm0\n" /* line 1362 */
        "movl $2, %edx\n"
        "ucomiss %xmm1, %xmm0\n"
        "cmovbel %eax, %edx\n"
        "shll $2, %edx\n" /* line 1370 */
        "movss (%ecx, %edx), %xmm0\n"
        "xorps 0x2efce0, %xmm0\n"
        "mulss %xmm0, %xmm2\n" /* line 272 */
        "movss %xmm2, (%ebx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%ecx), %xmm1\n"
        "movss %xmm1, 4(%ebx)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%ebx)\n"
        "leal (%ebx, %edx), %edx\n" /* line 1372 | dst */
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "movss (%edx), %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        /* { scope 2 */
        "movss (%ebx), %xmm3\n" /* line 794 */
        "movss 4(%ebx), %xmm0\n"
        "movss 8(%ebx), %xmm2\n"
        "movaps %xmm3, %xmm1\n" /* line 81 */
        "mulss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 797 | 0.0f */
        "jp .Lf2dde2_0002dead\n"
        "je .Lf2dde2_0002ded3\n"
        ".Lf2dde2_0002dead:\n"
        "movaps %xmm4, %xmm0\n" /* line 799 */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n" /* line 800 */
        "movss %xmm3, (%ebx)\n"
        "movaps %xmm0, %xmm1\n" /* line 801 */
        "mulss 4(%ebx), %xmm1\n"
        "movss %xmm1, 4(%ebx)\n"
        "mulss 8(%ebx), %xmm0\n" /* line 802 */
        "movss %xmm0, 8(%ebx)\n"
        /* } scope */
        /* } scope */
        ".Lf2dde2_0002ded3:\n"
        "addl $0x10, %esp\n" /* line 1375 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3842 */
__attribute__((naked))
float PitchForYawOnNormal(const float fYaw, const vec_t *normal)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3842 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* normal */
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 1323 | fYaw */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n" /* radians */
        /* { scope 1 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x10(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm4\n"
        /* } scope */
        "movss (%ebx), %xmm2\n" /* line 304 */
        "movss 4(%ebx), %xmm3\n"
        "movss 8(%ebx), %xmm5\n"
        "movaps %xmm4, %xmm0\n" /* line 3238 */
        "mulss %xmm2, %xmm0\n"
        "movss -0x10(%ebp), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "pxor %xmm6, %xmm6\n"
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "xorps 0x2efcf0, %xmm0\n"
        /* { scope 1 */
        "mulss %xmm0, %xmm2\n" /* line 288 */
        "addss %xmm4, %xmm2\n"
        "mulss %xmm0, %xmm3\n" /* line 289 */
        "addss -0x10(%ebp), %xmm3\n"
        "mulss %xmm0, %xmm5\n" /* line 290 */
        "addss %xmm6, %xmm5\n"
        /* } scope */
        /* { scope 1 */
        "ucomiss %xmm6, %xmm3\n" /* line 1153 */
        "jne .Lf2deda_0002df98\n"
        "jp .Lf2deda_0002df98\n"
        "ucomiss %xmm6, %xmm2\n"
        "jne .Lf2deda_0002df98\n"
        "jp .Lf2deda_0002df98\n"
        "ucomiss %xmm6, %xmm5\n" /* line 1155 */
        "jbe .Lf2deda_0002e001\n"
        "movss 0x2ed65c, %xmm0\n" /* 270.0f */
        /* } scope */
        ".Lf2deda_0002df8a:\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* line 3853 */
        "flds -0x2c(%ebp)\n"
        "addl $0x44, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2deda_0002df98:\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm3, %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "sqrtss %xmm2, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd %xmm5, %xmm5\n"
        "movsd %xmm5, (%esp)\n"
        "movss %xmm6, -0x28(%ebp)\n"
        "calll atan2\n"
        "fstpl -0x38(%ebp)\n"
        "movsd -0x38(%ebp), %xmm0\n"
        "mulsd 0x307c58, %xmm0\n" /* -180.0 */
        "divsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss -0x28(%ebp), %xmm6\n" /* line 1164 */
        "ucomiss %xmm0, %xmm6\n"
        "jbe .Lf2deda_0002df8a\n"
        "addss 0x2ed638, %xmm0\n" /* line 1165 | 360.0f */
        /* } scope */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 3853 */
        "flds -0x2c(%ebp)\n"
        "addl $0x44, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2deda_0002e001:\n"
        "movss 0x2ed5f8, %xmm0\n" /* line 1155 | 90.0f */
        "jmp .Lf2deda_0002df8a\n"
    );
}

/* line 2949 */
__attribute__((naked))
jpeg_alloc YawToAxis(float yaw, double (*axis)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2949 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* axis */
        /* { scope 1: radians */
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 1323 | yaw */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x14(%ebp)\n" /* sy */
        "movss -0xc(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x10(%ebp)\n" /* cy */
        "pxor %xmm1, %xmm1\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1326 */
        "je .Lf2e00e_0002e071\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 1328 | cy */
        "movss %xmm0, (%ebx)\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 1329 | sy */
        "movss %xmm0, 4(%ebx)\n"
        "pxor %xmm1, %xmm1\n" /* line 1330 */
        "movss %xmm1, 8(%ebx)\n"
        /* } scope */
        ".Lf2e00e_0002e071:\n"
        "leal 0x18(%ebx), %eax\n" /* line 2955 | axis */
        "movl $0, 0x18(%ebx)\n" /* axis */
        "movl $0, 4(%eax)\n" /* line 2956 */
        "movl $0x3f800000, 8(%eax)\n" /* line 2957 */
        "leal 0xc(%ebx), %eax\n" /* line 2958 | axis, diff */
        /* { scope 1: radians */
        "movaps %xmm1, %xmm0\n" /* line 248 */
        "subss -0x14(%ebp), %xmm0\n" /* sy */
        "movss %xmm0, 0xc(%ebx)\n"
        "addss -0x10(%ebp), %xmm1\n" /* line 249 | cy */
        "movss %xmm1, 4(%eax)\n"
        "movl $0, 8(%eax)\n" /* line 250 */
        /* } scope */
        "addl $0x24, %esp\n" /* line 2959 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 981 */
__attribute__((naked))
jpeg_alloc RotatePointAroundVector(vec_t *dst, const vec_t *dir, const vec_t *point, const float degrees)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 981 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        "movl 0xc(%ebp), %ecx\n" /* dir */
        /* { scope 1: srcSq */
        "movss (%ecx), %xmm6\n" /* line 994 */
        "movss 4(%ecx), %xmm0\n" /* line 995 */
        "movss %xmm0, -0xec(%ebp)\n"
        "movss 8(%ecx), %xmm7\n" /* line 996 */
        /* { scope 2 */
        "movaps %xmm6, %xmm1\n" /* line 1358 */
        "mulss %xmm6, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* srcSq */
        "mulss %xmm0, %xmm0\n" /* line 1359 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movaps %xmm7, %xmm2\n" /* line 1360 */
        "mulss %xmm7, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm0, %xmm1\n"
        "seta %al\n"
        "movss -0x30(%ebp, %eax, 4), %xmm0\n" /* line 1362 */
        "movl $2, %edx\n"
        "ucomiss %xmm2, %xmm0\n"
        "cmovbel %eax, %edx\n"
        "shll $2, %edx\n" /* line 1370 */
        "movss (%ecx, %edx), %xmm0\n"
        "xorps 0x2efd00, %xmm0\n"
        /* { scope 3 */
        "movaps %xmm6, %xmm3\n" /* line 272 */
        "mulss %xmm0, %xmm3\n"
        "movss %xmm3, -0x24(%ebp)\n" /* vr */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%ecx), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x24(%ebp, %edx), %eax\n" /* line 1372 */
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movss (%eax), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        /* { scope 3 */
        "movss -0x24(%ebp), %xmm3\n" /* line 794 | vr */
        "movss -0x20(%ebp), %xmm5\n"
        "movss -0x1c(%ebp), %xmm4\n"
        "movaps %xmm3, %xmm0\n" /* line 81 */
        "mulss %xmm3, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 797 | 0.0f */
        "jp .Lf2e0b0_0002e194\n"
        "je .Lf2e0b0_0002e1bf\n"
        ".Lf2e0b0_0002e194:\n"
        "movaps %xmm2, %xmm0\n" /* line 799 */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n" /* line 800 */
        "movss %xmm3, -0x24(%ebp)\n" /* vr */
        "movaps %xmm0, %xmm1\n" /* line 801 */
        "mulss %xmm5, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss %xmm4, %xmm0\n" /* line 802 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movaps %xmm1, %xmm5\n"
        "movaps %xmm0, %xmm4\n"
        /* } scope */
        /* } scope */
        ".Lf2e0b0_0002e1bf:\n"
        "movss %xmm3, -0x78(%ebp)\n" /* line 1001 | m */
        "movss %xmm5, -0x6c(%ebp)\n" /* line 1002 */
        "movss %xmm4, -0x60(%ebp)\n" /* line 1003 */
        "movaps %xmm7, %xmm2\n" /* line 1005 */
        "mulss %xmm5, %xmm2\n"
        "movss -0xec(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, -0x74(%ebp)\n"
        "movaps %xmm6, %xmm0\n" /* line 1006 */
        "mulss %xmm4, %xmm0\n"
        "movaps %xmm7, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "movss -0xec(%ebp), %xmm1\n" /* line 1007 */
        "mulss %xmm3, %xmm1\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "movss %xmm6, -0x70(%ebp)\n" /* line 1009 */
        "movss -0xec(%ebp), %xmm0\n" /* line 1010 */
        "movss %xmm0, -0x64(%ebp)\n"
        "movss %xmm7, -0x58(%ebp)\n" /* line 1011 */
        "movl -0x78(%ebp), %eax\n" /* line 1013 | m */
        "movl %eax, -0xe4(%ebp)\n" /* im */
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, -0xd4(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, -0xc4(%ebp)\n"
        "movss %xmm5, -0xe0(%ebp)\n" /* line 1015 */
        "movss %xmm4, -0xdc(%ebp)\n" /* line 1016 */
        "movss %xmm2, -0xd8(%ebp)\n" /* line 1017 */
        "movss %xmm1, -0xd0(%ebp)\n" /* line 1018 */
        "movss %xmm6, -0xcc(%ebp)\n" /* line 1019 */
        "movss %xmm0, -0xc8(%ebp)\n" /* line 1020 */
        "leal -0x54(%ebp), %esi\n" /* line 1022 | zrot */
        "cld\n"
        "movl $9, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $0x3f800000, -0x34(%ebp)\n" /* line 1023 */
        "movl $0x3f800000, -0x44(%ebp)\n"
        "movl $0x3f800000, -0x54(%ebp)\n" /* zrot */
        "cvtss2sd 0x14(%ebp), %xmm0\n" /* line 1025 | degrees */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xf0(%ebp)\n" /* rad */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0xf4(%ebp)\n"
        "movss -0xf4(%ebp), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movss -0xf0(%ebp), %xmm0\n" /* line 486 | rad */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fsts -0x54(%ebp)\n" /* zrot */
        "movss -0xf4(%ebp), %xmm0\n" /* line 1034 */
        "xorps 0x2efd00, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "fstps -0x44(%ebp)\n" /* line 1035 */
        "leal -0xc0(%ebp), %ebx\n" /* line 1037 | tmpmat */
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* m */
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply\n"
        "leal -0x9c(%ebp), %esi\n" /* line 1038 | rot */
        "movl %esi, 8(%esp)\n"
        "leal -0xe4(%ebp), %edi\n" /* im */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MatrixMultiply\n"
        "movl 0x10(%ebp), %ebx\n" /* point */
        "addl $4, %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* point */
        "addl $8, %ecx\n"
        "movl 8(%ebp), %edx\n" /* dst */
        "movl %esi, %eax\n"
        ".Lf2e0b0_0002e34b:\n"
        "movss (%eax), %xmm0\n" /* line 1041 */
        "movl 0x10(%ebp), %esi\n" /* point */
        "mulss (%esi), %xmm0\n"
        "movss 4(%eax), %xmm1\n"
        "mulss (%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss 8(%eax), %xmm1\n"
        "mulss (%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $0xc, %eax\n"
        "addl $4, %edx\n"
        "leal -0x78(%ebp), %edi\n" /* line 1040 | m */
        "cmpl %eax, %edi\n"
        "jne .Lf2e0b0_0002e34b\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 1042 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1271 */
__attribute__((naked))
jpeg_alloc AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1271 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* angles */
        "movl 0xc(%ebp), %ebx\n" /* forward */
        "movl 0x10(%ebp), %edi\n" /* right */
        /* { scope 1 */
        "cvtss2sd 4(%esi), %xmm0\n" /* line 1278 | angles */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n" /* angle */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x2c(%ebp)\n" /* sy */
        "movss -0x38(%ebp), %xmm0\n" /* line 486 | angle */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x24(%ebp)\n" /* cy */
        "cvtss2sd (%esi), %xmm0\n" /* line 1280 | angles */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x30(%ebp)\n" /* sp */
        "movss -0x20(%ebp), %xmm0\n" /* line 486 */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x28(%ebp)\n" /* cp */
        "testl %ebx, %ebx\n" /* line 1283 | forward */
        "je .Lf2e38c_0002e43f\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 1285 | cy */
        "mulss -0x28(%ebp), %xmm0\n" /* cp */
        "movss %xmm0, (%ebx)\n" /* forward */
        "movss -0x2c(%ebp), %xmm0\n" /* line 1286 | sy */
        "mulss -0x28(%ebp), %xmm0\n" /* cp */
        "movss %xmm0, 4(%ebx)\n" /* forward */
        "movss -0x30(%ebp), %xmm0\n" /* line 1287 | sp */
        "xorps 0x2efd20, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n" /* forward */
        ".Lf2e38c_0002e43f:\n"
        "testl %edi, %edi\n" /* line 1290 | right */
        "je .Lf2e38c_0002e531\n"
        ".Lf2e38c_0002e447:\n"
        "cvtss2sd 8(%esi), %xmm0\n" /* line 1292 | angles */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x34(%ebp)\n" /* sr */
        "movss -0x1c(%ebp), %xmm0\n" /* line 486 */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm4\n"
        "testl %edi, %edi\n" /* line 1295 | right */
        "je .Lf2e38c_0002e4d5\n"
        "movss -0x34(%ebp), %xmm3\n" /* line 1297 | sr */
        "xorps 0x2efd20, %xmm3\n"
        "movss -0x30(%ebp), %xmm2\n" /* sp */
        "mulss %xmm3, %xmm2\n"
        "movss -0x24(%ebp), %xmm0\n" /* cy */
        "mulss %xmm2, %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n" /* sy */
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edi)\n" /* right */
        "mulss -0x2c(%ebp), %xmm2\n" /* line 1298 | sy */
        "movss -0x24(%ebp), %xmm0\n" /* cy */
        "mulss %xmm4, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, 4(%edi)\n" /* right */
        "mulss -0x28(%ebp), %xmm3\n" /* line 1299 | cp */
        "movss %xmm3, 8(%edi)\n" /* right */
        ".Lf2e38c_0002e4d5:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1301 | up, forward */
        "testl %ebx, %ebx\n" /* forward */
        "je .Lf2e38c_0002e529\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1303 | sp */
        "mulss %xmm4, %xmm1\n"
        "movss -0x24(%ebp), %xmm0\n" /* cy */
        "mulss %xmm1, %xmm0\n"
        "movss -0x2c(%ebp), %xmm2\n" /* sy */
        "mulss -0x34(%ebp), %xmm2\n" /* sr */
        "addss %xmm2, %xmm0\n"
        "movl 0x14(%ebp), %eax\n" /* up */
        "movss %xmm0, (%eax)\n"
        "mulss -0x2c(%ebp), %xmm1\n" /* line 1304 | sy */
        "movss -0x34(%ebp), %xmm0\n" /* sr */
        "mulss -0x24(%ebp), %xmm0\n" /* cy */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 1305 | cp */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lf2e38c_0002e529:\n"
        "addl $0x4c, %esp\n" /* line 1308 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2e38c_0002e531:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1290 | up */
        "testl %eax, %eax\n"
        "jne .Lf2e38c_0002e447\n"
        "jmp .Lf2e38c_0002e529\n"
    );
}

/* line 2934 */
__attribute__((naked))
jpeg_alloc AnglesToAxis(const vec_t *angles, double (*axis)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2934 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* axis */
        /* { scope 1 */
        "leal 0x18(%ebx), %eax\n" /* line 2939 | axis */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* right */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* axis */
        "movl 8(%ebp), %eax\n" /* angles */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal 0xc(%ebx), %eax\n" /* line 2940 | axis, diff */
        /* { scope 2 */
        "pxor %xmm0, %xmm0\n" /* line 248 */
        "movaps %xmm0, %xmm1\n"
        "subss -0x14(%ebp), %xmm1\n" /* right */
        "movss %xmm1, 0xc(%ebx)\n"
        "movaps %xmm0, %xmm1\n" /* line 249 */
        "subss -0x10(%ebp), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "subss -0xc(%ebp), %xmm0\n" /* line 250 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        /* } scope */
        "addl $0x24, %esp\n" /* line 2941 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1316 */
__attribute__((naked))
jpeg_alloc YawVectors(const vec_t yaw, vec_t *forward, vec_t *right)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1316 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* forward */
        "movl 0x10(%ebp), %esi\n" /* right */
        /* { scope 1 */
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 1323 | yaw */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n" /* angle */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0xc(%ebp)\n" /* sy */
        "movss -0x10(%ebp), %xmm0\n" /* line 486 | angle */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "testl %ebx, %ebx\n" /* line 1326 | forward */
        "je .Lf2e596_0002e5ed\n"
        "fsts (%ebx)\n" /* line 1328 | forward */
        "movss -0xc(%ebp), %xmm0\n" /* line 1329 | sy */
        "movss %xmm0, 4(%ebx)\n" /* forward */
        "movl $0, 8(%ebx)\n" /* line 1330 | forward */
        ".Lf2e596_0002e5ed:\n"
        "testl %esi, %esi\n" /* line 1333 | right */
        "je .Lf2e596_0002e611\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 1335 | sy */
        "movss %xmm0, (%esi)\n" /* right */
        "fstps -0x1c(%ebp)\n" /* line 1336 */
        "movl -0x1c(%ebp), %eax\n"
        "xorl $0x80000000, %eax\n"
        "movl %eax, 4(%esi)\n" /* right */
        "movl $0, 8(%esi)\n" /* line 1337 | right */
        "jmp .Lf2e596_0002e613\n"
        ".Lf2e596_0002e611:\n"
        "fstp %st(0)\n"
        /* } scope */
        ".Lf2e596_0002e613:\n"
        "addl $0x30, %esp\n" /* line 1339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1957 */
__attribute__((naked))
jpeg_alloc VectorAngleMultiply(vec_t *vec, float angle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1957 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* vec */
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* line 1963 | angle */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n" /* radians */
        /* { scope 1 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x10(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm4\n"
        /* } scope */
        "movss (%ebx), %xmm2\n" /* line 1965 | vec */
        "movss 4(%ebx), %xmm3\n" /* vec */
        "movaps %xmm4, %xmm0\n" /* line 1966 */
        "mulss %xmm3, %xmm0\n"
        "movss -0x10(%ebp), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* vec */
        "mulss %xmm4, %xmm2\n" /* line 1967 */
        "mulss -0x10(%ebp), %xmm3\n"
        "subss %xmm3, %xmm2\n"
        "movss %xmm2, (%ebx)\n" /* vec */
        "addl $0x34, %esp\n" /* line 1968 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2181 */
__attribute__((naked))
jpeg_alloc AngleAxisToQuat(float angle, const vec_t *axis, vec_t *quat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2181 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* axis */
        "movl 0x10(%ebp), %ebx\n" /* quat */
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 2184 | angle */
        "mulsd 0x307c68, %xmm0\n" /* 0.008726646259971648 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss -0xc(%ebp), %xmm1\n" /* line 486 */
        "movss %xmm1, (%esp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "calll cosf\n"
        "fstps 0xc(%ebx)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 272 */
        "movaps %xmm0, %xmm1\n"
        "mulss (%esi), %xmm1\n"
        "movss %xmm1, (%ebx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%esi), %xmm1\n"
        "movss %xmm1, 4(%ebx)\n"
        "mulss 8(%esi), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%ebx)\n"
        "addl $0x40, %esp\n" /* line 2187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2969 */
__attribute__((naked))
jpeg_alloc AxisToAngles(double (*axis)[16], vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2969 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %ebx\n" /* axis */
        "movl 0xc(%ebp), %esi\n" /* angles */
        /* { scope 1 */
        "movl %esi, 4(%esp)\n" /* line 2979 | angles */
        "movl %ebx, (%esp)\n" /* axis */
        "calll vectoangles\n"
        "leal 0xc(%ebx), %eax\n" /* axis */
        /* { scope 2 */
        "movss 0xc(%ebx), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x14(%ebp)\n"
        "movss 4(%eax), %xmm2\n" /* line 200 */
        "movss %xmm2, -0x18(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movss 4(%esi), %xmm0\n" /* line 2984 | angles */
        "xorps 0x2efd50, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* rad */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x28(%ebp)\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 486 | rad */
        "movss %xmm2, (%esp)\n"
        "calll cosf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 2987 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* temp */
        "movss -0x18(%ebp), %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm2\n" /* temp */
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n" /* temp */
        "movss -0x28(%ebp), %xmm0\n" /* line 2988 */
        "movss -0x14(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "mulss -0x18(%ebp), %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0xc(%ebp)\n"
        "movss (%esi), %xmm0\n" /* line 2990 | angles */
        "xorps 0x2efd50, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 486 */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 2993 */
        "mulss -0x2c(%ebp), %xmm2\n"
        "movss -0x20(%ebp), %xmm0\n" /* temp */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 2994 */
        "movss -0x20(%ebp), %xmm0\n" /* temp */
        "mulss -0x2c(%ebp), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 1182 */
        "movss -0xc(%ebp), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf2e716_0002e8a1\n"
        "jp .Lf2e716_0002e8a1\n"
        "ucomiss %xmm3, %xmm2\n"
        "jne .Lf2e716_0002e89c\n"
        "jp .Lf2e716_0002e89c\n"
        "ucomiss %xmm3, %xmm1\n" /* line 1184 */
        "jbe .Lf2e716_0002e908\n"
        "movss 0x2ed660, %xmm0\n" /* -90.0f */
        "ucomiss -0xc(%ebp), %xmm3\n" /* line 2999 */
        "jbe .Lf2e716_0002e8f5\n"
        ".Lf2e716_0002e879:\n"
        "leal 8(%esi), %eax\n" /* line 3000 | angles */
        "ucomiss %xmm0, %xmm3\n"
        "ja .Lf2e716_0002e912\n"
        "movss 0x2ed650, %xmm1\n" /* -180.0f */
        ".Lf2e716_0002e88d:\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 3003 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2e716_0002e89c:\n"
        "movss -0xc(%ebp), %xmm0\n"
        /* { scope 1 */
        ".Lf2e716_0002e8a1:\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "movss %xmm3, -0x48(%ebp)\n"
        "calll atan2\n"
        "fstpl -0x58(%ebp)\n"
        "movsd -0x58(%ebp), %xmm0\n"
        "mulsd 0x307c58, %xmm0\n" /* -180.0 */
        "divsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss -0x48(%ebp), %xmm3\n"
        ".Lf2e716_0002e8ef:\n"
        "ucomiss -0xc(%ebp), %xmm3\n" /* line 2999 */
        "ja .Lf2e716_0002e879\n"
        ".Lf2e716_0002e8f5:\n"
        "xorps 0x2efd50, %xmm0\n" /* line 3002 */
        "movss %xmm0, 8(%esi)\n" /* angles */
        /* } scope */
        "addl $0x60, %esp\n" /* line 3003 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2e716_0002e908:\n"
        "movss 0x2ed5f8, %xmm0\n" /* line 1184 | 90.0f */
        "jmp .Lf2e716_0002e8ef\n"
        ".Lf2e716_0002e912:\n"
        "movss 0x2ed64c, %xmm1\n" /* line 3000 | 180.0f */
        "jmp .Lf2e716_0002e88d\n"
    );
}

