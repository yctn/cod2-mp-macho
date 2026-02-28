/* ASM dump from: FxPrimitives.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxPrimitives.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/FxMemMgr.h"
 *   #include "PC/EffectsCore/FxPrimitives.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxCurve.h"
 *   #include "PC/EffectsCore/FxChannel.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 *   #include "Mac/Tools/MacSwap.h"
 *   #include "PC/universal/q_shared.h"
 */

extern FxBoltFrame *FxBoltFrame_g_mFrameList; /* 0x0 */
extern void * Hunk_AllocInternal(int size);
extern struct XModel * XModelPrecache(const char *name, void *(*alloc1)(int), void *(*alloc2)(int));

void FxBoltFrame_Release(const FxBoltFrame * _this);
const orientation_t * FxBoltFrame_GetOrientation(const FxBoltFrame * _this);
static void * FxModelAlloc(int size);
struct XModel * FX_XModelPrecache(const char *name);
void Effect_Die(const Effect * _this);
Bool Effect_Cull(const Effect * _this);
void Effect_Draw(const Effect * _this);
void Effect_SetTimeStartEnd(const Effect * _this, int start, int end);
unsigned char Effect_TypeID(const Effect * _this);
void Effect_FixupArchiveLoad(const Effect * _this, const PrimitiveTemplate *primTemplate);
void FxChannelInstance_Create(const FxChannel *master, FxChannelInstance *createe);
void Particle_CreateChannelInstances(const Particle * _this, const PrimitiveTemplate *primTemp);
void Particle_SetRandomVelocity2Weights(const Particle * _this, float weight1, float weight2, float weight3);
unsigned char Particle_TypeID(const Particle * _this);
unsigned char OrientedParticle_TypeID(const OrientedParticle * _this);
void Cloud_Die(const Cloud * _this);
void Cloud_CreateChannelInstances(const Cloud * _this, const PrimitiveTemplate *primTemp);
unsigned char Cloud_TypeID(const Cloud * _this);
void Line_Die(const Line * _this);
unsigned char Line_TypeID(const Line * _this);
void Tail_CreateChannelInstances(const Tail * _this, const PrimitiveTemplate *primTemp);
unsigned char Tail_TypeID(const Tail * _this);
unsigned char Cylinder_TypeID(const Cylinder * _this);
Bool Emitter_Cull(const Emitter * _this);
unsigned char Emitter_TypeID(const Emitter * _this);
void Light_CreateChannelInstances(const Light * _this, const PrimitiveTemplate *primTemp);
void Light_Draw(const Light * _this);
unsigned char Light_TypeID(const Light * _this);
void Flash_Init(const Flash * _this);
unsigned char Flash_TypeID(const Flash * _this);
static void GLOBAL__I__ZN11FxBoltFrame12g_mFrameListE(void); /* global constructors keyed to FxBoltFrame_g_mFrameList */
void Particle_AddVisibility(const Particle * _this);
static void FX_AddFxToScene(void);
void Emitter_Draw(const Emitter * _this);
void Cylinder_Draw(const Cylinder * _this);
void Tail_Draw(const Tail * _this);
void Line_Draw(const Line * _this);
void Cloud_Draw(const Cloud * _this);
void OrientedParticle_Draw(const OrientedParticle * _this);
void Particle_Draw(const Particle * _this);
Bool Effect_Update(const Effect * _this);
Bool Particle_Cull(const Particle * _this);
Bool OrientedParticle_Cull(const OrientedParticle * _this);
Bool Cloud_Cull(const Cloud * _this);
Bool Line_Cull(const Line * _this);
Bool Tail_Cull(const Tail * _this);
Bool Cylinder_Cull(const Cylinder * _this);
Bool Light_Cull(const Light * _this);
void Particle_SetRandomVelocityWeights(const Particle * _this, float weight1, float weight2, float weight3);
float Particle_GetVisibility(const Particle * _this, const vec_t *start, const vec_t *dir, float halfLen);
void Particle_FixupArchiveLoad(const Particle * _this, const PrimitiveTemplate *primTemplate);
void Light_FixupArchiveLoad(const Light * _this, const PrimitiveTemplate *primTemplate);
void Particle_SetAxis(const Particle * _this, vec3_t *ax);
void Flash_Draw(const Flash * _this);
const FxBoltFramePtr FxBoltFrame_Acquire(const FxBoltInfo *bolt);
void Particle_Die(const Particle * _this);
void Tail_CalcNewEndpoint(const Tail * _this, const orientation_t *or_);
void Cloud_FixupArchiveLoad(const Cloud * _this, const PrimitiveTemplate *primTemplate);
void Tail_FixupArchiveLoad(const Tail * _this, const PrimitiveTemplate *primTemplate);
void Light_UpdateRGB(const Light * _this, const Light * _this_1);
void ZN6EffectD1Ev(void); /* Effect_~Effect */
void FxBoltFramePtr_Archive(const FxBoltFramePtr * _this, FxArchive *arch);
void ZN6EffectD0Ev(void); /* Effect_~Effect */
void Effect_SetBoltFrame(const Effect * _this, FxBoltFramePtr *boltFrame);
void Particle_UpdateRGB(const Particle * _this);
Bool Flash_Update(const Flash * _this);
void Particle_IntegrateVelocity(const Particle * _this, float normDuration, vec_t *outVector);
void Particle_IntegrateVelocity2(const Particle * _this, float normDuration, vec_t *outVector);
void Particle_IntegrateTotalVelocity(const Particle * _this, int duration, vec_t *outVector);
void Particle_Particle(const Particle * _this);
void ZN8ParticleD1Ev(void); /* Particle_~Particle */
void ZN8ParticleD0Ev(void); /* Particle_~Particle */
void Light_Light(const Light * _this);
void ZN5LightD1Ev(void); /* Light_~Light */
void ZN5LightD0Ev(void); /* Light_~Light */
void Tail_InitEndPoint(const Tail * _this);
Bool Light_Update(const Light * _this);
void Particle_CalcVelocityValue(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_);
void Particle_CalcVelocity2Value(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_);
void Particle_GetTotalVelocity(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_);
void Emitter_UpdateEmitFx(const Emitter * _this, vec_t *bindVelocity, const orientation_t *or_);
void Particle_GetTotalVelocityAtTime0(const Particle * _this, vec_t *outVector);
void Particle_ApplyImpact(const Particle * _this, const orientation_t *or_, float normTime, const vec_t *velocity, float traceFraction, const vec_t *traceNormal);
Bool Particle_UpdateOrigin(const Particle * _this, const orientation_t *or_);
Bool Emitter_Update(const Emitter * _this);
void Particle_UpdateAlpha(const Particle * _this);
Bool Cylinder_Update(const Cylinder * _this);
Bool Tail_Update(const Tail * _this);
Bool Line_Update(const Line * _this);
Bool Cloud_Update(const Cloud * _this);
Bool OrientedParticle_Update(const OrientedParticle * _this);
Bool Particle_Update(const Particle * _this, const Particle * _this_1, const Cloud * _this_2);
void Effect_Archive(const Effect * _this, FxArchive *arch);
void Light_Archive(const Light * _this, FxArchive *arch);
void Flash_Archive(const Flash * _this, FxArchive *arch);
void Particle_Archive(const Particle * _this, FxArchive *arch);
void OrientedParticle_Archive(const OrientedParticle * _this, FxArchive *arch);
void Cloud_Archive(const Cloud * _this, FxArchive *arch);
void Line_Archive(const Line * _this, FxArchive *arch);
void Tail_Archive(const Tail * _this, FxArchive *arch);
void Cylinder_Archive(const Cylinder * _this, FxArchive *arch);
void Emitter_Archive(const Emitter * _this, FxArchive *arch);
void ZN8CylinderD0Ev(void); /* Cylinder_~Cylinder */
void ZN8CylinderD1Ev(void); /* Cylinder_~Cylinder */
void Cylinder_Cylinder(const Cylinder * _this);
void OrientedParticle_OrientedParticle(const OrientedParticle * _this);
void ZN16OrientedParticleD1Ev(void); /* OrientedParticle_~OrientedParticle */
void ZN16OrientedParticleD0Ev(void); /* OrientedParticle_~OrientedParticle */
void Cloud_Cloud(const Cloud * _this, const Cloud * _this_1);
void ZN5CloudD1Ev(void); /* Cloud_~Cloud */
void ZN5CloudD0Ev(void); /* Cloud_~Cloud */
void Line_Line(const Line * _this);
void ZN4LineD1Ev(void); /* Line_~Line */
void ZN4LineD0Ev(void); /* Line_~Line */
void Tail_Tail(const Tail * _this);
void ZN4TailD1Ev(void); /* Tail_~Tail */
void ZN4TailD0Ev(void); /* Tail_~Tail */
void Emitter_Emitter(const Emitter * _this);
void ZN7EmitterD1Ev(void); /* Emitter_~Emitter */
void ZN7EmitterD0Ev(void); /* Emitter_~Emitter */
float Effect_GetVisibility(const Effect * _this, const vec_t *start, const vec_t *dir, float halfLen);
void Effect_AddVisibility(const Effect * _this);
Bool Flash_Cull(const Flash * _this);
void ZN5FlashD0Ev(void); /* Flash_~Flash */
void ZN5FlashD1Ev(void); /* Flash_~Flash */

/* line 69 */
__attribute__((naked))
void FxBoltFrame_Release(const FxBoltFrame * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa0570_000a05ae\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa0570_000a05a1\n"
        "cmpl %eax, %edx\n" /* line 77 */
        "je .Lfa0570_000a05b0\n"
        ".Lfa0570_000a058e:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa0570_000a05a1\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa0570_000a058e\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa0570_000a05a1:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa0570_000a05ae\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 85 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfa0570_000a05ae:\n"
        "popl %ebp\n" /* line 85 */
        "retl\n"
        /* { scope 1 */
        ".Lfa0570_000a05b0:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa0570_000a05a1\n"
    );
}

/* line 88 */
__attribute__((naked))
const orientation_t * FxBoltFrame_GetOrientation(const FxBoltFrame * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x3c(%esi), %eax\n" /* line 90 | this */
        "testl %eax, %eax\n"
        "js .Lfa05be_000a0617\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%esi)\n" /* this */
        "je .Lfa05be_000a0604\n"
        "movl %eax, 4(%esi)\n" /* line 96 | this */
        "leal 8(%esi), %ebx\n" /* line 102 | this */
        "movl %ebx, 4(%esp)\n"
        "leal 0x3c(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "je .Lfa05be_000a0609\n"
        ".Lfa05be_000a05fb:\n"
        "movl %ebx, %eax\n" /* line 111 */
        "addl $0x10, %esp\n" /* line 112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa05be_000a0604:\n"
        "leal 8(%esi), %ebx\n" /* this */
        "jmp .Lfa05be_000a05fb\n"
        ".Lfa05be_000a0609:\n"
        "movl $0xffffffff, 0x3c(%esi)\n" /* line 105 | this */
        "movl $0xffffffff, 0x40(%esi)\n" /* line 106 | this */
        ".Lfa05be_000a0617:\n"
        "xorl %eax, %eax\n"
        "addl $0x10, %esp\n" /* line 112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 165 */
static void * FxModelAlloc(int size)
{
    return Hunk_AllocInternal(size);
}

/* line 171 */
struct XModel * FX_XModelPrecache(const char *name)
{
    return XModelPrecache(name, FxModelAlloc, FxModelAlloc);
}

/* line 187 */
void Effect_Die(const Effect * _this)
{
}

/* line 192 */
Bool Effect_Cull(const Effect * _this)
{
    return 0;
}

/* line 198 */
void Effect_Draw(const Effect * _this)
{
}

/* line 250 */
void Effect_SetTimeStartEnd(const Effect * _this, int start, int end)
{
    *(int *)((byte *)_this + 0xb8) = start;
    *(int *)((byte *)_this + 0xbc) = end;
}

/* line 278 */
unsigned char Effect_TypeID(const Effect * _this)
{
    return 0;
}

/* line 322 */
void Effect_FixupArchiveLoad(const Effect * _this, const PrimitiveTemplate *primTemplate)
{
}

/* line 468 */
__attribute__((naked))
void FxChannelInstance_Create(const FxChannel *master, FxChannelInstance *createe)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 468 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* master */
        "movl 0xc(%ebp), %esi\n" /* createe */
        "movl (%ebx), %eax\n" /* line 473 | master */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* createe */
        "calll FxCurveIterator_Create\n"
        "addl $4, %ebx\n" /* line 474 | master */
        "movl %ebx, (%esp)\n" /* master */
        "calll FxRange_GetVal\n"
        "fstps 8(%esi)\n" /* createe */
        "addl $0x10, %esp\n" /* line 475 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 478 */
__attribute__((naked))
void Particle_CreateChannelInstances(const Particle * _this, const PrimitiveTemplate *primTemp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 478 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* primTemp */
        "leal 0x144(%ebx), %eax\n" /* line 482 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x100(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x150(%ebx), %eax\n" /* line 483 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x10c(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x15c(%ebx), %eax\n" /* line 484 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x118(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x168(%ebx), %eax\n" /* line 485 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x124(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x174(%ebx), %eax\n" /* line 486 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x130(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x180(%ebx), %eax\n" /* line 487 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x13c(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x18c(%ebx), %eax\n" /* line 488 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x148(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x198(%ebx), %eax\n" /* line 489 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x154(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1a4(%ebx), %eax\n" /* line 490 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x178(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1b0(%ebx), %eax\n" /* line 491 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x184(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1bc(%ebx), %eax\n" /* line 493 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x190(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1c8(%ebx), %eax\n" /* line 494 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x19c(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1d4(%ebx), %eax\n" /* line 495 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1a8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1e0(%ebx), %eax\n" /* line 496 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1b4(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1ec(%ebx), %eax\n" /* line 497 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1c0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x1f8(%ebx), %eax\n" /* line 498 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1cc(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x204(%ebx), %eax\n" /* line 500 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1d8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x210(%ebx), %eax\n" /* line 501 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1e4(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x21c(%ebx), %eax\n" /* line 502 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1f0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x228(%ebx), %eax\n" /* line 503 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x1fc(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0x234(%ebx), %eax\n" /* line 504 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x208(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "addl $0x240, %ebx\n" /* line 505 | this */
        "movl %ebx, 0xc(%ebp)\n" /* this, primTemp */
        "addl $0x214, %esi\n" /* primTemp */
        "movl %esi, 8(%ebp)\n" /* primTemp, this */
        "addl $0x10, %esp\n" /* line 506 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp FxChannelInstance_Create\n" /* line 505 */
    );
}

/* line 522 */
void Particle_SetRandomVelocity2Weights(const Particle * _this, float weight1, float weight2, float weight3)
{
    *(float *)((byte *)_this + 0x138) = weight1;
    *(float *)((byte *)_this + 0x13c) = weight2;
    *(float *)((byte *)_this + 0x140) = weight3;
}

/* line 1160 */
unsigned char Particle_TypeID(const Particle * _this)
{
    return 1;
}

/* line 1323 */
unsigned char OrientedParticle_TypeID(const OrientedParticle * _this)
{
    return 7;
}

/* line 1352 */
void Cloud_Die(const Cloud * _this)
{
}

/* line 1395 */
__attribute__((naked))
void Cloud_CreateChannelInstances(const Cloud * _this, const PrimitiveTemplate *primTemp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1395 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* primTemp */
        "movl %esi, 4(%esp)\n" /* line 1399 | primTemp */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_CreateChannelInstances\n"
        "leal 0x264(%ebx), %eax\n" /* line 1401 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x160(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "addl $0x270, %ebx\n" /* line 1402 | this */
        "movl %ebx, 0xc(%ebp)\n" /* this, primTemp */
        "addl $0x16c, %esi\n" /* primTemp */
        "movl %esi, 8(%ebp)\n" /* primTemp, this */
        "addl $0x10, %esp\n" /* line 1403 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp FxChannelInstance_Create\n" /* line 1402 */
    );
}

/* line 1466 */
unsigned char Cloud_TypeID(const Cloud * _this)
{
    return 12;
}

/* line 1509 */
void Line_Die(const Line * _this)
{
}

/* line 1561 */
unsigned char Line_TypeID(const Line * _this)
{
    return 2;
}

/* line 1602 */
__attribute__((naked))
void Tail_CreateChannelInstances(const Tail * _this, const PrimitiveTemplate *primTemp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1602 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* primTemp */
        "movl %esi, 4(%esp)\n" /* line 1606 | primTemp */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_CreateChannelInstances\n"
        "leal 0x260(%ebx), %eax\n" /* line 1608 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x160(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "addl $0x26c, %ebx\n" /* line 1609 | this */
        "movl %ebx, 0xc(%ebp)\n" /* this, primTemp */
        "addl $0x16c, %esi\n" /* primTemp */
        "movl %esi, 8(%ebp)\n" /* primTemp, this */
        "addl $0x10, %esp\n" /* line 1610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp FxChannelInstance_Create\n" /* line 1609 */
    );
}

/* line 1693 */
unsigned char Tail_TypeID(const Tail * _this)
{
    return 3;
}

/* line 1788 */
unsigned char Cylinder_TypeID(const Cylinder * _this)
{
    return 4;
}

/* line 1814 */
Bool Emitter_Cull(const Emitter * _this)
{
    return 0;
}

/* line 2098 */
unsigned char Emitter_TypeID(const Emitter * _this)
{
    return 5;
}

/* line 2141 */
__attribute__((naked))
void Light_CreateChannelInstances(const Light * _this, const PrimitiveTemplate *primTemp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2141 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* primTemp */
        "leal 0xcc(%ebx), %eax\n" /* line 2145 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x100(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0xd8(%ebx), %eax\n" /* line 2146 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x10c(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "leal 0xe4(%ebx), %eax\n" /* line 2147 | this */
        "movl %eax, 4(%esp)\n"
        "leal 0x130(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "addl $0xf0, %ebx\n" /* line 2148 | this */
        "movl %ebx, 0xc(%ebp)\n" /* this, primTemp */
        "addl $0x13c, %esi\n" /* primTemp */
        "movl %esi, 8(%ebp)\n" /* primTemp, this */
        "addl $0x10, %esp\n" /* line 2149 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp FxChannelInstance_Create\n" /* line 2148 */
    );
}

/* line 2158 */
__attribute__((naked))
void Light_Draw(const Light * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2158 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x74(%eax), %edx\n" /* line 2160 */
        "movl %edx, 0x14(%esp)\n"
        "movl 0x70(%eax), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x6c(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x88(%eax), %edx\n"
        "movl %edx, 8(%esp)\n"
        "addl $0x7c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_AddLightToScene\n"
        "leave\n" /* line 2161 */
        "retl\n"
    );
}

/* line 2214 */
unsigned char Light_TypeID(const Light * _this)
{
    return 9;
}

/* line 2264 */
__attribute__((naked))
void Flash_Init(const Flash * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2264 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "leal 4(%esi), %ecx\n" /* this */
        "movl 0x195ed88, %ebx\n"
        "movl (%ebx), %eax\n"
        "leal 0x14(%eax), %edx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movss 4(%esi), %xmm0\n" /* line 248 */
        "subss 0x14(%eax), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* dif */
        "movss 4(%ecx), %xmm0\n" /* line 249 */
        "subss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 8(%ecx), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "leal -0x14(%ebp), %eax\n" /* line 2270 | dif */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm2\n"
        "movl (%ebx), %eax\n"
        "leal 0x20(%eax), %edx\n"
        /* { scope 2 */
        "movss -0x14(%ebp), %xmm1\n" /* line 304 | dif */
        "mulss 0x20(%eax), %xmm1\n"
        "movss -0x10(%ebp), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0xc(%ebp), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "ucomiss 0x2ed804, %xmm2\n" /* line 2274 | 600.0f */
        "ja .Lfa0ac2_000a0ba5\n"
        "ucomiss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "jae .Lfa0ac2_000a0b76\n"
        "jp .Lfa0ac2_000a0b76\n"
        "ucomiss 0x2ed798, %xmm2\n" /* 100.0f */
        "ja .Lfa0ac2_000a0ba5\n"
        "ucomiss 0x2ed798, %xmm2\n" /* line 2276 | 100.0f */
        "ja .Lfa0ac2_000a0b76\n"
        "jp .Lfa0ac2_000a0b76\n"
        "addss 0x2ed808, %xmm1\n" /* line 2277 | 1.100000023841858f */
        ".Lfa0ac2_000a0b76:\n"
        "mulss %xmm2, %xmm2\n" /* line 2281 */
        "divss 0x2ed80c, %xmm2\n" /* -360000.0f */
        "addss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "mulss %xmm2, %xmm1\n"
        "mulss 0xd4(%esi), %xmm1\n" /* this */
        "movss %xmm1, 0xd4(%esi)\n" /* this */
        /* } scope */
        "addl $0x30, %esp\n" /* line 2282 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa0ac2_000a0ba5:\n"
        "pxor %xmm1, %xmm1\n" /* line 2277 */
        "jmp .Lfa0ac2_000a0b76\n"
    );
}

/* line 2305 */
unsigned char Flash_TypeID(const Flash * _this)
{
    return 11;
}

/* line 2322 */
static void GLOBAL__I__ZN11FxBoltFrame12g_mFrameListE(void) /* global constructors keyed to FxBoltFrame_g_mFrameList */
{
}

/* line 563 */
__attribute__((naked))
void Particle_AddVisibility(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 563 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movl 0x195ee74, %esi\n" /* line 570 */
        "movl (%esi), %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl 0x195ee70, %edx\n"
        "leal (%edx, %ecx, 4), %ecx\n"
        "addl $1, %eax\n" /* line 571 */
        "movl %eax, (%esi)\n"
        "leal 0x7c(%ebx), %edx\n" /* line 573 | this, from */
        /* { scope 2 */
        "movl 0x7c(%ebx), %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movss 0x88(%ebx), %xmm0\n" /* line 574 | this */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, 0xc(%ecx)\n"
        "movzbl 0x93(%ebx), %eax\n" /* line 575 | this */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed810, %xmm0\n" /* -0.003921568859368563f */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 0x10(%ecx)\n"
        /* } scope */
        "popl %ebx\n" /* line 576 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 329 */
static __attribute__((naked))
void FX_AddFxToScene(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 329 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %esi\n" /* effect */
        "movl %edx, %ebx\n" /* reType */
        /* { scope 1 */
        "leal -0x8c(%ebp), %edi\n" /* line 333 | ent */
        "movl $0x74, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "movl %ebx, -0x8c(%ebp)\n" /* line 335 | reType, ent */
        "movl 0x40(%esi), %eax\n" /* line 337 | effect */
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x44(%esi), %eax\n" /* line 338 | effect */
        "movl %eax, -0x20(%ebp)\n"
        "leal -0x78(%ebp), %eax\n" /* line 339 */
        "movl %eax, 4(%esp)\n"
        "leal 0x48(%esi), %eax\n" /* effect */
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "leal 0x7c(%esi), %edx\n" /* effect */
        /* { scope 2 */
        "movl 0x7c(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x48(%ebp)\n"
        /* } scope */
        "movl 0x88(%esi), %eax\n" /* line 341 | effect */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x8c(%esi), %eax\n" /* line 342 | effect */
        "movl %eax, -0x24(%ebp)\n"
        "movzbl 0x90(%esi), %eax\n" /* line 343 | effect */
        "movb %al, -0x34(%ebp)\n"
        "movzbl 0x91(%esi), %eax\n" /* line 344 | effect */
        "movb %al, -0x33(%ebp)\n"
        "movzbl 0x92(%esi), %eax\n" /* line 345 | effect */
        "movb %al, -0x32(%ebp)\n"
        "movzbl 0x93(%esi), %eax\n" /* line 346 | effect */
        "movb %al, -0x31(%ebp)\n"
        "movl 0x94(%esi), %eax\n" /* line 347 | effect */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x98(%esi), %eax\n" /* line 348 | effect */
        "movl %eax, -0x54(%ebp)\n"
        "leal 0x9c(%esi), %edx\n" /* effect */
        /* { scope 2 */
        "movl 0x9c(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x3c(%ebp)\n"
        /* } scope */
        "movl 0xa8(%esi), %eax\n" /* line 351 | effect */
        "testb $1, %al\n"
        "je .Lfa0c28_000a0d07\n"
        "orl $8, -0x88(%ebp)\n" /* line 352 */
        ".Lfa0c28_000a0d07:\n"
        "testl $0x4000000, %eax\n" /* line 353 */
        "je .Lfa0c28_000a0d18\n"
        "orl $0x80, -0x88(%ebp)\n" /* line 354 */
        ".Lfa0c28_000a0d18:\n"
        "movl 0xb4(%esi), %eax\n" /* line 356 | effect */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_AddFxToScene\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 357 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1820 */
__attribute__((naked))
void Emitter_Draw(const Emitter * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1820 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "testb $0x10, 0xa8(%eax)\n" /* line 1823 */
        "je .Lfa0d40_000a0d5e\n"
        "pxor %xmm0, %xmm0\n" /* line 1827 */
        "ucomiss 0x98(%eax), %xmm0\n"
        "jp .Lfa0d40_000a0d60\n"
        "jne .Lfa0d40_000a0d60\n"
        ".Lfa0d40_000a0d5e:\n"
        "popl %ebp\n" /* line 1830 */
        "retl\n"
        ".Lfa0d40_000a0d60:\n"
        "movl $1, %edx\n" /* line 1828 */
        "popl %ebp\n" /* line 1830 */
        "jmp FX_AddFxToScene\n" /* line 1828 */
    );
}

/* line 1743 */
__attribute__((naked))
void Cylinder_Draw(const Cylinder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1743 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $9, %edx\n" /* line 1745 */
        "popl %ebp\n" /* line 1746 */
        "jmp FX_AddFxToScene\n" /* line 1745 */
    );
}

/* line 1613 */
__attribute__((naked))
void Tail_Draw(const Tail * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1613 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $8, %edx\n" /* line 1615 */
        "popl %ebp\n" /* line 1616 */
        "jmp FX_AddFxToScene\n" /* line 1615 */
    );
}

/* line 1520 */
__attribute__((naked))
void Line_Draw(const Line * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1520 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $8, %edx\n" /* line 1522 */
        "popl %ebp\n" /* line 1523 */
        "jmp FX_AddFxToScene\n" /* line 1522 */
    );
}

/* line 1389 */
__attribute__((naked))
void Cloud_Draw(const Cloud * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1389 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $6, %edx\n" /* line 1391 */
        "popl %ebp\n" /* line 1392 */
        "jmp FX_AddFxToScene\n" /* line 1391 */
    );
}

/* line 1276 */
__attribute__((naked))
void OrientedParticle_Draw(const OrientedParticle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1276 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $7, %edx\n" /* line 1278 */
        "popl %ebp\n" /* line 1279 */
        "jmp FX_AddFxToScene\n" /* line 1278 */
    );
}

/* line 401 */
__attribute__((naked))
void Particle_Draw(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 401 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "pxor %xmm0, %xmm0\n" /* line 403 */
        "ucomiss 0x88(%eax), %xmm0\n"
        "jp .Lfa0dc6_000a0ddb\n"
        "je .Lfa0dc6_000a0de6\n"
        ".Lfa0dc6_000a0ddb:\n"
        "ucomiss 0x8c(%eax), %xmm0\n"
        "jp .Lfa0dc6_000a0de8\n"
        "jne .Lfa0dc6_000a0de8\n"
        ".Lfa0dc6_000a0de6:\n"
        "popl %ebp\n" /* line 407 */
        "retl\n"
        ".Lfa0dc6_000a0de8:\n"
        "movl $4, %edx\n" /* line 406 */
        "popl %ebp\n" /* line 407 */
        "jmp FX_AddFxToScene\n" /* line 406 */
    );
}

/* line 227 */
__attribute__((naked))
Bool Effect_Update(const Effect * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 227 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xb8(%ecx), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa0df4_000a0e58\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%ecx)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa0df4_000a0e3b\n"
        "movss %xmm1, 0x3c(%ecx)\n" /* line 242 */
        ".Lfa0df4_000a0e3b:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%ecx), %xmm0\n"
        "ja .Lfa0df4_000a0e4c\n"
        "movl $1, %eax\n" /* line 244 */
        ".Lfa0df4_000a0e4a:\n"
        "popl %ebp\n" /* line 247 */
        "retl\n"
        ".Lfa0df4_000a0e4c:\n"
        "movss %xmm0, 0x3c(%ecx)\n" /* line 244 */
        "movl $1, %eax\n"
        "jmp .Lfa0df4_000a0e4a\n"
        ".Lfa0df4_000a0e58:\n"
        "xorl %eax, %eax\n" /* line 232 */
        "popl %ebp\n" /* line 247 */
        "retl\n"
    );
}

/* line 395 */
__attribute__((naked))
Bool Particle_Cull(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 395 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "testb $2, 0xab(%edx)\n" /* line 220 */
        "je .Lfa0e5c_000a0eb1\n"
        "movl 0x195ed88, %ecx\n" /* line 221 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        /* { scope 1 */
        "movl %eax, %ebx\n" /* line 154 */
        "subl $5, %ebx\n"
        "js .Lfa0e5c_000a0e89\n"
        "movl $5, %eax\n"
        /* } scope */
        ".Lfa0e5c_000a0e89:\n"
        "movl %eax, 0xc(%esp)\n" /* line 397 */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "movzbl %al, %eax\n"
        "addl $0x14, %esp\n" /* line 398 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa0e5c_000a0eb1:\n"
        "movl 0x195ed88, %ecx\n" /* line 223 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n" /* line 397 */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "movzbl %al, %eax\n"
        "addl $0x14, %esp\n" /* line 398 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1270 */
__attribute__((naked))
Bool OrientedParticle_Cull(const OrientedParticle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1270 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "testb $2, 0xab(%edx)\n" /* line 220 */
        "je .Lfa0ee8_000a0f3d\n"
        "movl 0x195ed88, %ecx\n" /* line 221 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        /* { scope 1 */
        "movl %eax, %ebx\n" /* line 154 */
        "subl $5, %ebx\n"
        "js .Lfa0ee8_000a0f15\n"
        "movl $5, %eax\n"
        /* } scope */
        ".Lfa0ee8_000a0f15:\n"
        "movl %eax, 0xc(%esp)\n" /* line 1272 */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "movzbl %al, %eax\n"
        "addl $0x14, %esp\n" /* line 1273 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa0ee8_000a0f3d:\n"
        "movl 0x195ed88, %ecx\n" /* line 223 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n" /* line 1272 */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "movzbl %al, %eax\n"
        "addl $0x14, %esp\n" /* line 1273 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1357 */
__attribute__((naked))
Bool Cloud_Cull(const Cloud * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1357 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "testb $2, 0xab(%edx)\n" /* line 220 */
        "je .Lfa0f74_000a0ffd\n"
        "movl 0x195ed88, %ecx\n" /* line 221 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        /* { scope 1 */
        "movl %eax, %ebx\n" /* line 154 */
        "subl $5, %ebx\n"
        "js .Lfa0f74_000a0fa1\n"
        "movl $5, %eax\n"
        /* } scope */
        ".Lfa0f74_000a0fa1:\n"
        "movss 0x98(%edx), %xmm3\n" /* line 1359 */
        "movss 0x8c(%edx), %xmm2\n"
        "movss 0x88(%edx), %xmm1\n"
        /* { scope 1 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm2, %xmm4\n"
        "cmpltss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movl %eax, 0xc(%esp)\n" /* line 1359 */
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "movzbl %al, %eax\n"
        "addl $0x14, %esp\n" /* line 1360 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa0f74_000a0ffd:\n"
        "movl 0x195ed88, %ecx\n" /* line 223 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        "jmp .Lfa0f74_000a0fa1\n"
    );
}

/* line 1514 */
__attribute__((naked))
Bool Line_Cull(const Line * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1514 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "testb $2, 0xab(%ecx)\n" /* line 220 */
        "je .Lfa100e_000a1071\n"
        "movl 0x195ed88, %ebx\n" /* line 221 */
        "movl (%ebx), %eax\n"
        "movl 0x80(%eax), %edx\n"
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 154 */
        "subl $5, %eax\n"
        "js .Lfa100e_000a103b\n"
        "movl $5, %edx\n"
        /* } scope */
        ".Lfa100e_000a103b:\n"
        "movl 0x88(%ecx), %eax\n" /* line 1516 */
        "movl %edx, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x9c(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullCylinder\n"
        "movzbl %al, %eax\n"
        "addl $0x24, %esp\n" /* line 1517 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa100e_000a1071:\n"
        "movl 0x195ed88, %ebx\n" /* line 223 */
        "movl (%ebx), %eax\n"
        "movl 0x80(%eax), %edx\n"
        "jmp .Lfa100e_000a103b\n"
    );
}

/* line 1596 */
__attribute__((naked))
Bool Tail_Cull(const Tail * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1596 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "testb $2, 0xab(%ecx)\n" /* line 220 */
        "je .Lfa1082_000a10e5\n"
        "movl 0x195ed88, %ebx\n" /* line 221 */
        "movl (%ebx), %eax\n"
        "movl 0x80(%eax), %edx\n"
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 154 */
        "subl $5, %eax\n"
        "js .Lfa1082_000a10af\n"
        "movl $5, %edx\n"
        /* } scope */
        ".Lfa1082_000a10af:\n"
        "movl 0x88(%ecx), %eax\n" /* line 1598 */
        "movl %edx, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x9c(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullCylinder\n"
        "movzbl %al, %eax\n"
        "addl $0x24, %esp\n" /* line 1599 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa1082_000a10e5:\n"
        "movl 0x195ed88, %ebx\n" /* line 223 */
        "movl (%ebx), %eax\n"
        "movl 0x80(%eax), %edx\n"
        "jmp .Lfa1082_000a10af\n"
    );
}

/* line 1737 */
__attribute__((naked))
Bool Cylinder_Cull(const Cylinder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1737 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "testb $2, 0xab(%edx)\n" /* line 220 */
        "je .Lfa10f6_000a115f\n"
        "movl 0x195ed88, %ecx\n" /* line 221 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        /* { scope 1 */
        "movl %eax, %ebx\n" /* line 154 */
        "subl $5, %ebx\n"
        "js .Lfa10f6_000a1123\n"
        "movl $5, %eax\n"
        /* } scope */
        ".Lfa10f6_000a1123:\n"
        "movl %eax, 0x14(%esp)\n" /* line 1739 */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x8c(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x9c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullCylinder\n"
        "movzbl %al, %eax\n"
        "addl $0x24, %esp\n" /* line 1740 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa10f6_000a115f:\n"
        "movl 0x195ed88, %ecx\n" /* line 223 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        "jmp .Lfa10f6_000a1123\n"
    );
}

/* line 2152 */
__attribute__((naked))
Bool Light_Cull(const Light * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2152 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "testb $2, 0xab(%edx)\n" /* line 220 */
        "je .Lfa1170_000a11c5\n"
        "movl 0x195ed88, %ecx\n" /* line 221 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        /* { scope 1 */
        "movl %eax, %ebx\n" /* line 154 */
        "subl $5, %ebx\n"
        "js .Lfa1170_000a119d\n"
        "movl $5, %eax\n"
        /* } scope */
        ".Lfa1170_000a119d:\n"
        "movl %eax, 0xc(%esp)\n" /* line 2154 */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "movzbl %al, %eax\n"
        "addl $0x14, %esp\n" /* line 2155 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa1170_000a11c5:\n"
        "movl 0x195ed88, %ecx\n" /* line 223 */
        "movl (%ecx), %eax\n"
        "movl 0x80(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n" /* line 2154 */
        "movl 0x88(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x7c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "movzbl %al, %eax\n"
        "addl $0x14, %esp\n" /* line 2155 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 509 */
void Particle_SetRandomVelocityWeights(const Particle * _this, float weight1, float weight2, float weight3)
{
    *(float *)((byte *)_this + 0x12c) = weight1;
    *(float *)((byte *)_this + 0x130) = weight2;
    *(float *)((byte *)_this + 0x134) = weight3;
}

/* line 535 */
__attribute__((naked))
float Particle_GetVisibility(const Particle * _this, const vec_t *start, const vec_t *dir, float halfLen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 535 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* start */
        "movl 0x10(%ebp), %eax\n" /* dir */
        "movss 0x14(%ebp), %xmm1\n" /* halfLen */
        /* { scope 1 */
        "leal 0x7c(%ebx), %edx\n" /* line 544 | this */
        "movss (%ecx), %xmm4\n" /* line 248 */
        "movss (%eax), %xmm3\n" /* line 304 */
        "movss 0x7c(%ebx), %xmm2\n"
        "subss %xmm4, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss 4(%edx), %xmm0\n"
        "subss 4(%ecx), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss 8(%edx), %xmm0\n"
        "subss 8(%ecx), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n" /* line 547 */
        "subss %xmm1, %xmm0\n"
        "andps 0x2f1c00, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa1220_000a129c\n"
        ".Lfa1220_000a1286:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 554 | 1.0f */
        /* } scope */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 558 */
        "flds -0x2c(%ebp)\n"
        "addl $0x44, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa1220_000a129c:\n"
        "mulss %xmm2, %xmm3\n" /* line 288 */
        "addss %xmm3, %xmm4\n"
        "movss %xmm4, -0x14(%ebp)\n" /* projPt */
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss 8(%eax), %xmm2\n" /* line 290 */
        "addss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0xc(%ebp)\n"
        "leal -0x14(%ebp), %eax\n" /* line 552 | projPt */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x1c(%ebp)\n" /* distSq */
        "movss 0x88(%ebx), %xmm0\n" /* line 554 | this */
        "mulss %xmm0, %xmm0\n"
        "ucomiss -0x1c(%ebp), %xmm0\n" /* distSq */
        "jbe .Lfa1220_000a1286\n"
        "movzbl 0x93(%ebx), %eax\n" /* line 555 | this */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed810, %xmm0\n" /* -0.003921568859368563f */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 558 */
        "flds -0x2c(%ebp)\n"
        "addl $0x44, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1225 */
__attribute__((naked))
void Particle_FixupArchiveLoad(const Particle * _this, const PrimitiveTemplate *primTemplate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1225 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* primTemplate */
        "movl 0x100(%eax), %ecx\n" /* line 1231 */
        "movl %ecx, 0x144(%edx)\n"
        "movl 0x10c(%eax), %ecx\n" /* line 1232 */
        "movl %ecx, 0x150(%edx)\n"
        "movl 0x118(%eax), %ecx\n" /* line 1233 */
        "movl %ecx, 0x15c(%edx)\n"
        "movl 0x124(%eax), %ecx\n" /* line 1234 */
        "movl %ecx, 0x168(%edx)\n"
        "movl 0x130(%eax), %ecx\n" /* line 1235 */
        "movl %ecx, 0x174(%edx)\n"
        "movl 0x13c(%eax), %ecx\n" /* line 1236 */
        "movl %ecx, 0x180(%edx)\n"
        "movl 0x148(%eax), %ecx\n" /* line 1237 */
        "movl %ecx, 0x18c(%edx)\n"
        "movl 0x154(%eax), %ecx\n" /* line 1238 */
        "movl %ecx, 0x198(%edx)\n"
        "movl 0x178(%eax), %ecx\n" /* line 1239 */
        "movl %ecx, 0x1a4(%edx)\n"
        "movl 0x184(%eax), %ecx\n" /* line 1240 */
        "movl %ecx, 0x1b0(%edx)\n"
        "movl 0x190(%eax), %ecx\n" /* line 1242 */
        "movl %ecx, 0x1bc(%edx)\n"
        "movl 0x19c(%eax), %ecx\n" /* line 1243 */
        "movl %ecx, 0x1c8(%edx)\n"
        "movl 0x1a8(%eax), %ecx\n" /* line 1244 */
        "movl %ecx, 0x1d4(%edx)\n"
        "movl 0x1b4(%eax), %ecx\n" /* line 1245 */
        "movl %ecx, 0x1e0(%edx)\n"
        "movl 0x1c0(%eax), %ecx\n" /* line 1246 */
        "movl %ecx, 0x1ec(%edx)\n"
        "movl 0x1cc(%eax), %ecx\n" /* line 1247 */
        "movl %ecx, 0x1f8(%edx)\n"
        "movl 0x1d8(%eax), %ecx\n" /* line 1249 */
        "movl %ecx, 0x204(%edx)\n"
        "movl 0x1e4(%eax), %ecx\n" /* line 1250 */
        "movl %ecx, 0x210(%edx)\n"
        "movl 0x1f0(%eax), %ecx\n" /* line 1251 */
        "movl %ecx, 0x21c(%edx)\n"
        "movl 0x1fc(%eax), %ecx\n" /* line 1252 */
        "movl %ecx, 0x228(%edx)\n"
        "movl 0x208(%eax), %ecx\n" /* line 1253 */
        "movl %ecx, 0x234(%edx)\n"
        "movl 0x214(%eax), %eax\n" /* line 1254 */
        "movl %eax, 0x240(%edx)\n"
        "popl %ebp\n" /* line 1255 */
        "retl\n"
    );
}

/* line 2236 */
__attribute__((naked))
void Light_FixupArchiveLoad(const Light * _this, const PrimitiveTemplate *primTemplate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2236 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* primTemplate */
        "movl 0x100(%edx), %eax\n" /* line 2242 */
        "movl %eax, 0xcc(%ecx)\n"
        "movl 0x10c(%edx), %eax\n" /* line 2243 */
        "movl %eax, 0xd8(%ecx)\n"
        "movl 0x130(%edx), %eax\n" /* line 2244 */
        "movl %eax, 0xe4(%ecx)\n"
        "movl 0x13c(%edx), %eax\n" /* line 2245 */
        "movl %eax, 0xf0(%ecx)\n"
        "popl %ebp\n" /* line 2246 */
        "retl\n"
    );
}

/* line 456 */
__attribute__((naked))
void Particle_SetAxis(const Particle * _this, vec3_t *ax)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 456 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* ax */
        "leal 0xd0(%esi), %edx\n" /* line 462 | this */
        "testl %ecx, %ecx\n" /* line 207 */
        "je .Lfa1468_000a14d9\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, 0xd0(%esi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0xdc(%esi), %edx\n" /* line 463 | this */
        "movl %ecx, %ebx\n" /* line 207 */
        "addl $0xc, %ebx\n"
        "je .Lfa1468_000a14f4\n"
        /* { scope 1 */
        ".Lfa1468_000a149e:\n"
        "movl 0xc(%ecx), %eax\n" /* line 199 */
        "movl %eax, 0xdc(%esi)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0xe8(%esi), %edx\n" /* line 464 | this */
        "movl %ecx, %ebx\n" /* line 207 */
        "addl $0x18, %ebx\n"
        "je .Lfa1468_000a150f\n"
        /* { scope 1 */
        ".Lfa1468_000a14c0:\n"
        "movl 0x18(%ecx), %eax\n" /* line 199 */
        "movl %eax, 0xe8(%esi)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "popl %ebx\n" /* line 465 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa1468_000a14d9:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0xd0(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0xdc(%esi), %edx\n" /* line 463 | this */
        "movl %ecx, %ebx\n" /* line 207 */
        "addl $0xc, %ebx\n"
        "jne .Lfa1468_000a149e\n"
        /* { scope 1 */
        ".Lfa1468_000a14f4:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0xdc(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "leal 0xe8(%esi), %edx\n" /* line 464 | this */
        "movl %ecx, %ebx\n" /* line 207 */
        "addl $0x18, %ebx\n"
        "jne .Lfa1468_000a14c0\n"
        /* { scope 1 */
        ".Lfa1468_000a150f:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0xe8(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "popl %ebx\n" /* line 465 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2285 */
__attribute__((naked))
void Flash_Draw(const Flash * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl %esi, %eax\n" /* this */
        "movl $1, %edx\n"
        "pxor %xmm2, %xmm2\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "leal -0x28(%ebp), %ecx\n" /* color */
        /* { scope 1 */
        ".Lfa1522_000a1544:\n"
        "movss 0x6c(%eax), %xmm0\n" /* line 2291 | x */
        /* { scope 2 */
        "ucomiss %xmm0, %xmm2\n" /* line 406 */
        "ja .Lfa1522_000a1709\n"
        "movaps %xmm1, %xmm3\n" /* line 408 */
        "minss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        ".Lfa1522_000a155c:\n"
        "movss %xmm0, -4(%ecx, %edx, 4)\n" /* line 2291 | x */
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 2290 */
        "jne .Lfa1522_000a1544\n"
        "movl $0x3f800000, -0x1c(%ebp)\n" /* line 2292 */
        "leal 0x90(%esi), %ebx\n" /* line 2293 | this, to */
        /* { scope 2 */
        "movss -0x28(%ebp), %xmm0\n" /* line 428 | color */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a1711\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a15b3:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a15b5:\n"
        "movb %al, (%ebx)\n" /* line 696 */
        "leal 1(%ebx), %edi\n" /* line 697 */
        "movss -0x24(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a174a\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a15f3:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a15f5:\n"
        "movb %al, (%edi)\n" /* line 697 */
        "leal 2(%ebx), %edi\n" /* line 698 */
        "movss -0x20(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x34(%ebp)\n"
        "cvttss2si -0x34(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a1737\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a1633:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a1635:\n"
        "movb %al, (%edi)\n" /* line 698 */
        "addl $3, %ebx\n" /* line 699 */
        "movss 0x2ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfa1522_000a1724\n"
        "movl $0xff, %edx\n"
        /* { scope 3 */
        ".Lfa1522_000a1673:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfa1522_000a1675:\n"
        "movb %al, (%ebx)\n" /* line 699 */
        /* } scope */
        "leal 0x7c(%esi), %ebx\n" /* line 2295 | this, to */
        "movl 0x195ed88, %ecx\n"
        "movl (%ecx), %eax\n"
        "leal 0x14(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movl 0x14(%eax), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x80(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x84(%esi)\n"
        "movl (%ecx), %eax\n"
        "leal 0x20(%eax), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movss 0x2ed740, %xmm1\n" /* line 288 | 8.0f */
        "movss 0x20(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x7c(%esi), %xmm0\n"
        "movss %xmm0, 0x7c(%esi)\n"
        "movss 4(%edx), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, 0x80(%esi)\n"
        "mulss 8(%edx), %xmm1\n" /* line 290 */
        "addss 8(%ebx), %xmm1\n"
        "movss %xmm1, 0x84(%esi)\n"
        /* } scope */
        "movl $0x41400000, %eax\n" /* line 2297 */
        "movl %eax, 0x88(%esi)\n" /* this */
        "movl %eax, 0x8c(%esi)\n" /* line 2298 | this */
        "movl $4, %edx\n" /* line 2300 */
        "movl %esi, %eax\n" /* this */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2301 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp FX_AddFxToScene\n" /* line 2300 */
        /* { scope 2 */
        ".Lfa1522_000a1709:\n"
        "movaps %xmm2, %xmm0\n" /* line 406 */
        "jmp .Lfa1522_000a155c\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa1522_000a1711:\n"
        "movl %edx, %eax\n" /* line 154 */
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a15b3\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a15b5\n"
        /* } scope */
        ".Lfa1522_000a1724:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a1673\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a1675\n"
        /* } scope */
        ".Lfa1522_000a1737:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a1633\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a1635\n"
        /* } scope */
        ".Lfa1522_000a174a:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 3 */
        "testl %eax, %eax\n"
        "js .Lfa1522_000a15f3\n"
        "xorl %eax, %eax\n"
        "jmp .Lfa1522_000a15f5\n"
    );
}

/* line 55 */
__attribute__((naked))
const FxBoltFramePtr FxBoltFrame_Acquire(const FxBoltInfo *bolt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n"
        "movl 0xc(%ebp), %esi\n" /* bolt */
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %edx\n" /* line 59 */
        "testl %edx, %edx\n"
        "je .Lfa175e_000a17a0\n"
        "movl (%esi), %ecx\n" /* line 61 | bolt */
        "jmp .Lfa175e_000a1782\n"
        ".Lfa175e_000a177b:\n"
        "movl 0x38(%edx), %edx\n" /* line 59 */
        "testl %edx, %edx\n"
        "je .Lfa175e_000a17a0\n"
        ".Lfa175e_000a1782:\n"
        "cmpl %ecx, 0x3c(%edx)\n" /* line 61 */
        "jne .Lfa175e_000a177b\n"
        "movl 0x40(%edx), %eax\n"
        "cmpl 4(%esi), %eax\n" /* bolt */
        "jne .Lfa175e_000a177b\n"
        "addl $1, (%edx)\n" /* line 39 */
        "movl %edx, (%edi)\n" /* line 59 */
        /* } scope */
        "movl %edi, %eax\n" /* line 66 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl $4\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa175e_000a17a0:\n"
        "movl $0x44, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lfa175e_000a17ca\n"
        "movl $0x44, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lfa175e_000a17ca:\n"
        "movl $0, (%ebx)\n" /* line 117 | ptr */
        "movl $0, 4(%ebx)\n" /* line 119 | ptr */
        "movl (%esi), %eax\n" /* line 123 | bolt */
        "movl 4(%esi), %edx\n" /* bolt */
        "movl %eax, 0x3c(%ebx)\n" /* ptr */
        "movl %edx, 0x40(%ebx)\n" /* ptr */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 125 */
        "movl %eax, 0x38(%ebx)\n" /* ptr */
        "movl %ebx, __ZN11FxBoltFrame12g_mFrameListE\n" /* line 126 | ptr */
        "addl $1, (%ebx)\n" /* line 39 | ptr */
        "movl %ebx, (%edi)\n" /* line 59 | ptr */
        /* } scope */
        "movl %edi, %eax\n" /* line 66 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl $4\n"
    );
}

/* line 371 */
__attribute__((naked))
void Particle_Die(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 371 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: z */
        "movl 0xa8(%esi), %eax\n" /* line 376 | this */
        "testb $2, %ah\n"
        "je .Lfa1802_000a18ef\n"
        "testb $4, %ah\n"
        "jne .Lfa1802_000a18ef\n"
        "movl 0x30(%esi), %edx\n" /* line 379 | this */
        "testl %edx, %edx\n"
        "je .Lfa1802_000a18ef\n"
        "movl $0x3f800000, %edi\n" /* line 381 */
        "movl %edi, 4(%esp)\n"
        "movl $0xbf800000, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "fstps -0x2c(%ebp)\n" /* z */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n" /* y */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n" /* y */
        "calll flrand\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm2\n" /* x */
        /* { scope 2 */
        "movss %xmm2, -0x24(%ebp)\n" /* line 191 | norm */
        "movss -0x48(%ebp), %xmm1\n" /* line 192 */
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 193 | z */
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movaps %xmm2, %xmm0\n" /* line 81 */
        "mulss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n" /* z */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "cvtss2sd %xmm1, %xmm0\n" /* line 384 */
        "ucomisd 0x307cc0, %xmm0\n" /* 1e-06 */
        "jae .Lfa1802_000a18f7\n"
        "jp .Lfa1802_000a18f7\n"
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, -0x24(%ebp)\n" /* norm */
        "movl %eax, -0x20(%ebp)\n" /* line 192 */
        "movl %edi, -0x1c(%ebp)\n" /* line 193 */
        ".Lfa1802_000a18cb:\n"
        "leal -0x24(%ebp), %eax\n" /* line 389 | norm */
        "movl %eax, 0xc(%esp)\n"
        "leal 4(%esi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 0x30(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        /* } scope */
        ".Lfa1802_000a18ef:\n"
        "addl $0x5c, %esp\n" /* line 392 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: z */
        ".Lfa1802_000a18f7:\n"
        "movl %edi, -0x4c(%ebp)\n" /* line 387 */
        "movss -0x4c(%ebp), %xmm0\n" /* scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm0, %xmm2\n" /* line 272 */
        "movss %xmm2, -0x24(%ebp)\n" /* norm */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "jmp .Lfa1802_000a18cb\n"
    );
}

/* line 1665 */
__attribute__((naked))
void Tail_CalcNewEndpoint(const Tail * _this, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1665 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* or_ */
        /* { scope 1 */
        "leal 0x24c(%edx), %eax\n" /* line 1670 | a */
        /* { scope 2 */
        "movss 0x24c(%edx), %xmm3\n" /* line 248 */
        "subss 4(%edx), %xmm3\n"
        "movss %xmm3, -0x14(%ebp)\n" /* direction */
        "movss 4(%eax), %xmm1\n" /* line 249 */
        "subss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 0xc(%edx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "movaps %xmm3, %xmm2\n" /* line 81 */
        "mulss %xmm3, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 1674 | 0.0f */
        "jbe .Lfa1926_000a1a13\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1676 | 1.0f, scale */
        "divss %xmm2, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm0, %xmm3\n" /* line 272 */
        "movss %xmm3, -0x14(%ebp)\n" /* direction */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x10(%ebp), %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        "mulss -0xc(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 1678 */
        "je .Lfa1926_000a1a15\n"
        "movss 0x258(%edx), %xmm1\n" /* line 1680 | scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss %xmm3, %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* direction */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x10(%ebp), %xmm0\n"
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss -0xc(%ebp), %xmm1\n" /* line 290 */
        "addss 0xc(%edx), %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        /* } scope */
        "leal 0x9c(%edx), %eax\n" /* line 1681 */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* direction */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        /* } scope */
        ".Lfa1926_000a1a13:\n"
        "leave\n" /* line 1688 */
        "retl\n"
        /* { scope 1 */
        ".Lfa1926_000a1a15:\n"
        "leal 0x9c(%edx), %eax\n" /* line 1685 | result */
        "movss 0x258(%edx), %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x14(%ebp), %xmm0\n" /* direction */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 0x9c(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x10(%ebp), %xmm0\n"
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0xc(%ebp), %xmm1\n" /* line 290 */
        "addss 0xc(%edx), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        /* } scope */
        "leave\n" /* line 1688 */
        "retl\n"
    );
}

/* line 1486 */
__attribute__((naked))
void Cloud_FixupArchiveLoad(const Cloud * _this, const PrimitiveTemplate *primTemplate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1486 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* primTemplate */
        "movl 0x100(%eax), %ecx\n" /* line 1231 */
        "movl %ecx, 0x144(%edx)\n"
        "movl 0x10c(%eax), %ecx\n" /* line 1232 */
        "movl %ecx, 0x150(%edx)\n"
        "movl 0x118(%eax), %ecx\n" /* line 1233 */
        "movl %ecx, 0x15c(%edx)\n"
        "movl 0x124(%eax), %ecx\n" /* line 1234 */
        "movl %ecx, 0x168(%edx)\n"
        "movl 0x130(%eax), %ecx\n" /* line 1235 */
        "movl %ecx, 0x174(%edx)\n"
        "movl 0x13c(%eax), %ecx\n" /* line 1236 */
        "movl %ecx, 0x180(%edx)\n"
        "movl 0x148(%eax), %ecx\n" /* line 1237 */
        "movl %ecx, 0x18c(%edx)\n"
        "movl 0x154(%eax), %ecx\n" /* line 1238 */
        "movl %ecx, 0x198(%edx)\n"
        "movl 0x178(%eax), %ecx\n" /* line 1239 */
        "movl %ecx, 0x1a4(%edx)\n"
        "movl 0x184(%eax), %ecx\n" /* line 1240 */
        "movl %ecx, 0x1b0(%edx)\n"
        "movl 0x190(%eax), %ecx\n" /* line 1242 */
        "movl %ecx, 0x1bc(%edx)\n"
        "movl 0x19c(%eax), %ecx\n" /* line 1243 */
        "movl %ecx, 0x1c8(%edx)\n"
        "movl 0x1a8(%eax), %ecx\n" /* line 1244 */
        "movl %ecx, 0x1d4(%edx)\n"
        "movl 0x1b4(%eax), %ecx\n" /* line 1245 */
        "movl %ecx, 0x1e0(%edx)\n"
        "movl 0x1c0(%eax), %ecx\n" /* line 1246 */
        "movl %ecx, 0x1ec(%edx)\n"
        "movl 0x1cc(%eax), %ecx\n" /* line 1247 */
        "movl %ecx, 0x1f8(%edx)\n"
        "movl 0x1d8(%eax), %ecx\n" /* line 1249 */
        "movl %ecx, 0x204(%edx)\n"
        "movl 0x1e4(%eax), %ecx\n" /* line 1250 */
        "movl %ecx, 0x210(%edx)\n"
        "movl 0x1f0(%eax), %ecx\n" /* line 1251 */
        "movl %ecx, 0x21c(%edx)\n"
        "movl 0x1fc(%eax), %ecx\n" /* line 1252 */
        "movl %ecx, 0x228(%edx)\n"
        "movl 0x208(%eax), %ecx\n" /* line 1253 */
        "movl %ecx, 0x234(%edx)\n"
        "movl 0x214(%eax), %ecx\n" /* line 1254 */
        "movl %ecx, 0x240(%edx)\n"
        "movl 0x160(%eax), %ecx\n" /* line 1492 */
        "movl %ecx, 0x264(%edx)\n"
        "movl 0x16c(%eax), %eax\n" /* line 1493 */
        "movl %eax, 0x270(%edx)\n"
        "popl %ebp\n" /* line 1494 */
        "retl\n"
    );
}

/* line 1714 */
__attribute__((naked))
void Tail_FixupArchiveLoad(const Tail * _this, const PrimitiveTemplate *primTemplate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1714 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* primTemplate */
        "movl 0x100(%eax), %ecx\n" /* line 1231 */
        "movl %ecx, 0x144(%edx)\n"
        "movl 0x10c(%eax), %ecx\n" /* line 1232 */
        "movl %ecx, 0x150(%edx)\n"
        "movl 0x118(%eax), %ecx\n" /* line 1233 */
        "movl %ecx, 0x15c(%edx)\n"
        "movl 0x124(%eax), %ecx\n" /* line 1234 */
        "movl %ecx, 0x168(%edx)\n"
        "movl 0x130(%eax), %ecx\n" /* line 1235 */
        "movl %ecx, 0x174(%edx)\n"
        "movl 0x13c(%eax), %ecx\n" /* line 1236 */
        "movl %ecx, 0x180(%edx)\n"
        "movl 0x148(%eax), %ecx\n" /* line 1237 */
        "movl %ecx, 0x18c(%edx)\n"
        "movl 0x154(%eax), %ecx\n" /* line 1238 */
        "movl %ecx, 0x198(%edx)\n"
        "movl 0x178(%eax), %ecx\n" /* line 1239 */
        "movl %ecx, 0x1a4(%edx)\n"
        "movl 0x184(%eax), %ecx\n" /* line 1240 */
        "movl %ecx, 0x1b0(%edx)\n"
        "movl 0x190(%eax), %ecx\n" /* line 1242 */
        "movl %ecx, 0x1bc(%edx)\n"
        "movl 0x19c(%eax), %ecx\n" /* line 1243 */
        "movl %ecx, 0x1c8(%edx)\n"
        "movl 0x1a8(%eax), %ecx\n" /* line 1244 */
        "movl %ecx, 0x1d4(%edx)\n"
        "movl 0x1b4(%eax), %ecx\n" /* line 1245 */
        "movl %ecx, 0x1e0(%edx)\n"
        "movl 0x1c0(%eax), %ecx\n" /* line 1246 */
        "movl %ecx, 0x1ec(%edx)\n"
        "movl 0x1cc(%eax), %ecx\n" /* line 1247 */
        "movl %ecx, 0x1f8(%edx)\n"
        "movl 0x1d8(%eax), %ecx\n" /* line 1249 */
        "movl %ecx, 0x204(%edx)\n"
        "movl 0x1e4(%eax), %ecx\n" /* line 1250 */
        "movl %ecx, 0x210(%edx)\n"
        "movl 0x1f0(%eax), %ecx\n" /* line 1251 */
        "movl %ecx, 0x21c(%edx)\n"
        "movl 0x1fc(%eax), %ecx\n" /* line 1252 */
        "movl %ecx, 0x228(%edx)\n"
        "movl 0x208(%eax), %ecx\n" /* line 1253 */
        "movl %ecx, 0x234(%edx)\n"
        "movl 0x214(%eax), %ecx\n" /* line 1254 */
        "movl %ecx, 0x240(%edx)\n"
        "movl 0x160(%eax), %ecx\n" /* line 1720 */
        "movl %ecx, 0x260(%edx)\n"
        "movl 0x16c(%eax), %eax\n" /* line 1721 */
        "movl %eax, 0x26c(%edx)\n"
        "popl %ebp\n" /* line 1722 */
        "retl\n"
    );
}

/* line 2199 */
__attribute__((naked))
void Light_UpdateRGB(const Light * _this, const Light * _this_1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2199 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "testb $0x20, 0xa9(%eax)\n" /* line 2203 */
        "je .Lfa1cb4_000a1edb\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 2204 */
        "leal 0x6c(%eax), %ecx\n"
        "movss 0xc4(%eax), %xmm5\n"
        "leal 0xd8(%eax), %edi\n" /* source1 */
        "leal 0xcc(%eax), %esi\n" /* source0 */
        /* { scope 1: keySize */
        /* { scope 2 */
        "movl 0xcc(%eax), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* keySize */
        "imull 4(%esi), %eax\n" /* line 92 | keySize */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja 0xa2007\n"
        "movl -0x1c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa1cb4_000a1ebc\n"
        /* } scope */
        ".Lfa1cb4_000a1d21:\n"
        "movl 4(%esi), %eax\n" /* line 148 | keySize */
        "shll $4, %eax\n"
        "addl (%esi), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "movaps %xmm3, %xmm2\n" /* line 74 | frac */
        "subss %xmm1, %xmm2\n" /* frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 4 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "leal 4(%ecx), %ebx\n" /* line 265 | key */
        "movl %ebx, -0x18(%ebp)\n" /* key */
        "movss 8(%edx), %xmm1\n"
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "leal 8(%ecx), %eax\n" /* line 266 */
        "movl %eax, -0x14(%ebp)\n"
        "movss 0xc(%edx), %xmm1\n"
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl (%edi), %ebx\n" /* line 91 | keySize, key */
        "movl %ebx, -0x24(%ebp)\n" /* key */
        "movl (%ebx), %edx\n" /* key */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%edi), %eax\n" /* keySize */
        "leal (%ebx, %eax, 4), %eax\n" /* key */
        "movl %eax, -0x20(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe 0xa1fff\n"
        "movl $0, 4(%edi)\n" /* line 96 | keySize */
        "addl $8, %ebx\n" /* line 97 | key */
        "movl %ebx, -0x10(%ebp)\n" /* key */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa1cb4_000a1df1\n"
        ".Lfa1cb4_000a1de6:\n"
        "addl $1, 4(%edi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa1cb4_000a1de6\n"
        /* } scope */
        ".Lfa1cb4_000a1df1:\n"
        "movl 4(%edi), %eax\n" /* line 148 | keySize */
        "shll $4, %eax\n"
        "addl -0x24(%ebp), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "subss %xmm1, %xmm3\n" /* line 74 | frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm3\n" /* scale, frac */
        /* { scope 4 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 8(%edx), %xmm2\n" /* line 265 */
        "movss 0xc(%edx), %xmm4\n" /* line 266 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movss 0x18(%edx), %xmm0\n" /* line 249 */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "subss 4(%ecx), %xmm2\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 250 */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss 8(%ecx), %xmm4\n"
        /* { scope 2 */
        "movss 0x14(%edx), %xmm0\n" /* line 288 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss (%ecx), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss (%ecx), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss %xmm5, %xmm2\n" /* line 289 */
        "addss 4(%ecx), %xmm2\n"
        "movl -0x18(%ebp), %eax\n"
        "movss %xmm2, (%eax)\n"
        "mulss %xmm4, %xmm5\n" /* line 290 */
        "addss 8(%ecx), %xmm5\n"
        "movl -0x14(%ebp), %ebx\n" /* key */
        "movss %xmm5, (%ebx)\n" /* key */
        /* } scope */
        "movss 8(%esi), %xmm0\n" /* line 74 | scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%ecx), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%ecx), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 274 */
        "movss %xmm0, (%ebx)\n" /* key */
        /* } scope */
        /* } scope */
        "addl $0x18, %esp\n" /* line 2209 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keySize */
        /* { scope 2 */
        ".Lfa1cb4_000a1ebc:\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa1cb4_000a1d21\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa1cb4_000a1ebc\n"
        "jmp .Lfa1cb4_000a1d21\n"
        /* } scope */
        /* } scope */
        ".Lfa1cb4_000a1edb:\n"
        "movss 0x3c(%eax), %xmm2\n" /* line 2206 */
        "leal 0x6c(%eax), %ebx\n" /* source1 */
        "leal 0xcc(%eax), %ecx\n" /* source */
        /* { scope 1: keySize */
        /* { scope 2 */
        "movl 0xcc(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm2, %xmm0\n"
        "ja 0xa1fe0\n"
    );
}

/* line 182 */
__attribute__((naked))
void ZN6EffectD1Ev(void) /* Effect_~Effect */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 182 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n"
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa202a_000a2078\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa202a_000a2078\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa202a_000a206b\n"
        "cmpl %eax, %edx\n" /* line 77 */
        "je .Lfa202a_000a207a\n"
        ".Lfa202a_000a2058:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa202a_000a206b\n"
        "cmpl %eax, %edx\n" /* line 77 */
        "jne .Lfa202a_000a2058\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa202a_000a206b:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa202a_000a2078\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 184 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfa202a_000a2078:\n"
        "popl %ebp\n" /* line 184 */
        "retl\n"
        /* { scope 1 */
        ".Lfa202a_000a207a:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa202a_000a206b\n"
    );
}

/* line 132 */
__attribute__((naked))
void FxBoltFramePtr_Archive(const FxBoltFramePtr * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 132 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* arch */
        "cmpb $0, 4(%esi)\n" /* line 134 | arch */
        "jne .Lfa2086_000a20e6\n"
        "movl (%edi), %eax\n" /* line 150 | this */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a223b\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* i */
        /* { scope 1: i */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x20(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_WriteData\n"
        "movl (%edi), %eax\n" /* this */
        "movl 0x40(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* i */
        /* } scope */
        /* { scope 1: i */
        "movl $4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_WriteData\n"
        /* } scope */
        ".Lfa2086_000a20de:\n"
        "leal -0xc(%ebp), %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2 */
        ".Lfa2086_000a20e6:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x20(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "movl -0x20(%ebp), %eax\n" /* line 46 | i */
        /* } scope */
        "movl %eax, -0x28(%ebp)\n" /* line 137 | bolt */
        "testl %eax, %eax\n" /* line 138 */
        "js .Lfa2086_000a21e5\n"
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 100 */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 140 | i */
        "movl %eax, -0x24(%ebp)\n"
        "leal -0x1c(%ebp), %edx\n" /* line 141 */
        "leal -0x28(%ebp), %eax\n" /* bolt */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FxBoltFrame_Acquire\n"
        "subl $4, %esp\n"
        "movl (%edi), %edx\n" /* line 78 */
        "cmpl -0x1c(%ebp), %edx\n"
        "je .Lfa2086_000a2195\n"
        "testl %edx, %edx\n" /* line 80 */
        "je .Lfa2086_000a2186\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2086_000a2180\n"
        /* { scope 2 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a2174\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2086_000a226b\n"
        ".Lfa2086_000a2161:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2086_000a2174\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2086_000a2161\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2086_000a2174:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2086_000a2180\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa2086_000a2180:\n"
        "movl $0, (%edi)\n" /* line 83 */
        ".Lfa2086_000a2186:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 106 */
        "testl %edx, %edx\n" /* line 85 */
        "je .Lfa2086_000a2195\n"
        "addl $1, (%edx)\n" /* line 39 */
        "movl %edx, (%edi)\n" /* line 86 */
        "movl -0x1c(%ebp), %edx\n"
        ".Lfa2086_000a2195:\n"
        "testl %edx, %edx\n" /* line 60 */
        "je .Lfa2086_000a20de\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2086_000a20de\n"
        /* { scope 2 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a21d0\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2086_000a2261\n"
        ".Lfa2086_000a21bd:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2086_000a21d0\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2086_000a21bd\n"
        ".Lfa2086_000a21cb:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2086_000a21d0:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2086_000a20de\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        "jmp .Lfa2086_000a20de\n"
        /* } scope */
        ".Lfa2086_000a21e5:\n"
        "movl (%edi), %edx\n" /* line 91 */
        "testl %edx, %edx\n"
        "je .Lfa2086_000a20de\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2086_000a2226\n"
        /* { scope 2 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2086_000a221a\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2086_000a227a\n"
        ".Lfa2086_000a2207:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2086_000a221a\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2086_000a2207\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2086_000a221a:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2086_000a2226\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa2086_000a2226:\n"
        "addl $1, 0\n" /* line 39 */
        "movl $0, (%edi)\n" /* line 95 */
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lfa2086_000a223b:\n"
        "movl $0xffffffff, -0x20(%ebp)\n" /* line 137 | i */
        /* } scope */
        /* { scope 1: i */
        "movl $4, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_WriteData\n"
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2 */
        ".Lfa2086_000a2261:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa2086_000a21cb\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa2086_000a226b:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa2086_000a2174\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa2086_000a227a:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa2086_000a221a\n"
    );
}

/* line 182 */
__attribute__((naked))
void ZN6EffectD0Ev(void) /* Effect_~Effect */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 182 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* this */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa2286_000a22d7\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2286_000a22d7\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2286_000a22cb\n"
        "cmpl %eax, %edx\n" /* line 77 */
        "je .Lfa2286_000a22ee\n"
        ".Lfa2286_000a22b8:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2286_000a22cb\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2286_000a22b8\n"
        ".Lfa2286_000a22c6:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2286_000a22cb:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2286_000a22d7\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa2286_000a22d7:\n"
        "testl %ebx, %ebx\n"
        "je .Lfa2286_000a22e8\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 184 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfa2286_000a22e8:\n"
        "addl $0x14, %esp\n" /* line 184 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa2286_000a22ee:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa2286_000a22c6\n"
    );
}

/* line 269 */
__attribute__((naked))
void Effect_SetBoltFrame(const Effect * _this, FxBoltFramePtr *boltFrame)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 269 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* boltFrame */
        "leal 0xc0(%eax), %ebx\n" /* line 272 | this */
        /* { scope 1 */
        "movl 0xc0(%eax), %edx\n" /* line 78 */
        "cmpl (%esi), %edx\n"
        "je .Lfa22f6_000a2360\n"
        "testl %edx, %edx\n" /* line 80 */
        "je .Lfa22f6_000a2355\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa22f6_000a234f\n"
        /* { scope 2 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa22f6_000a2343\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa22f6_000a2367\n"
        ".Lfa22f6_000a2330:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa22f6_000a2343\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa22f6_000a2330\n"
        ".Lfa22f6_000a233e:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa22f6_000a2343:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa22f6_000a234f\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa22f6_000a234f:\n"
        "movl $0, (%ebx)\n" /* line 83 */
        ".Lfa22f6_000a2355:\n"
        "movl (%esi), %eax\n" /* line 106 */
        "testl %eax, %eax\n" /* line 85 */
        "je .Lfa22f6_000a2360\n"
        "addl $1, (%eax)\n" /* line 39 */
        "movl %eax, (%ebx)\n" /* line 86 */
        /* } scope */
        ".Lfa22f6_000a2360:\n"
        "addl $0x10, %esp\n" /* line 273 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa22f6_000a2367:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa22f6_000a233e\n"
    );
}

/* line 1041 */
__attribute__((naked))
void Particle_UpdateRGB(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1041 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1047 | this */
        "testb $0x20, 0xa9(%eax)\n"
        "je .Lfa236e_000a25d8\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1048 */
        "movss 0x118(%eax), %xmm6\n"
        "movl %eax, %esi\n" /* source1 */
        "addl $0x150, %esi\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x144, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x144(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa236e_000a2719\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a259a\n"
        /* } scope */
        ".Lfa236e_000a23dc:\n"
        "movl 4(%ecx), %eax\n" /* line 148 */
        "shll $4, %eax\n"
        "addl (%ecx), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "movaps %xmm3, %xmm2\n" /* line 74 | frac */
        "subss %xmm1, %xmm2\n" /* frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 5 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movss 8(%edx), %xmm1\n" /* line 265 */
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "movss 0xc(%edx), %xmm1\n" /* line 266 */
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%esi), %ebx\n" /* line 91 | keySize */
        "movl (%ebx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%esi), %eax\n" /* keySize */
        "leal (%ebx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa236e_000a26fb\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a25b9\n"
        /* } scope */
        ".Lfa236e_000a2481:\n"
        "movl 4(%esi), %eax\n" /* line 148 | keySize */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "subss %xmm1, %xmm3\n" /* line 74 | frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm3\n" /* scale, frac */
        /* { scope 5 */
        "movss 4(%edx), %xmm2\n" /* line 264 */
        "movss 8(%edx), %xmm1\n" /* line 265 */
        "movss 0xc(%edx), %xmm4\n" /* line 266 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movss -0x18(%ebp), %xmm5\n" /* line 248 | rgbVal */
        "movss 0x18(%edx), %xmm0\n" /* line 249 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss -0x14(%ebp), %xmm1\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 250 */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss -0x10(%ebp), %xmm4\n"
        /* { scope 3 */
        "movss 0x14(%edx), %xmm0\n" /* line 288 */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm6, %xmm2\n"
        "addss %xmm2, %xmm5\n"
        "movss %xmm5, -0x18(%ebp)\n" /* rgbVal */
        "mulss %xmm6, %xmm1\n" /* line 289 */
        "addss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss %xmm4, %xmm6\n" /* line 290 */
        "addss -0x10(%ebp), %xmm6\n"
        "movss %xmm6, -0x10(%ebp)\n"
        /* } scope */
        "movss 8(%ecx), %xmm0\n" /* line 74 | scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss %xmm5, %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss %xmm6, %xmm0\n" /* line 274 */
        "movss %xmm0, -0x10(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lfa236e_000a2547:\n"
        "movl 8(%ebp), %esi\n" /* line 1052 | this, res */
        "addl $0x90, %esi\n" /* res */
        "movl $1, %ebx\n"
        "leal -0x18(%ebp), %edi\n" /* rgbVal, keySize */
        "movss 0x2ed5d4, %xmm1\n" /* 255.0f */
        /* { scope 2 */
        ".Lfa236e_000a2560:\n"
        "movss -4(%edi, %ebx, 4), %xmm0\n" /* line 49 */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "movl $0xff, %ecx\n" /* line 154 */
        "movl %edx, %eax\n"
        "subl $0xff, %eax\n"
        "cmovsl %edx, %ecx\n"
        "negl %edx\n"
        "xorl %eax, %eax\n"
        "testl %edx, %edx\n"
        "cmovsl %ecx, %eax\n"
        "movb %al, -1(%esi, %ebx)\n" /* line 50 */
        "addl $1, %ebx\n"
        "cmpl $4, %ebx\n" /* line 47 */
        "jne .Lfa236e_000a2560\n"
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1055 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa236e_000a259a:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a23dc\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a259a\n"
        "jmp .Lfa236e_000a23dc\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa236e_000a25b9:\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a2481\n"
        "addl $1, 4(%esi)\n" /* line 102 | keySize */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa236e_000a25b9\n"
        "jmp .Lfa236e_000a2481\n"
        /* } scope */
        /* } scope */
        ".Lfa236e_000a25d8:\n"
        "movss 0x3c(%eax), %xmm2\n" /* line 1050 */
        "movl %eax, %ecx\n" /* source */
        "addl $0x144, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x144(%eax), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lfa236e_000a26dc\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n"
        "ucomiss (%eax), %xmm2\n"
        "ja .Lfa236e_000a26bd\n"
        /* } scope */
        ".Lfa236e_000a261d:\n"
        "movl 4(%ecx), %eax\n" /* line 148 */
        "shll $4, %eax\n"
        "addl (%ecx), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "subss %xmm1, %xmm2\n" /* line 74 | frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 5 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movss 8(%edx), %xmm1\n" /* line 265 */
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "movss 0xc(%edx), %xmm1\n" /* line 266 */
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movss 8(%ecx), %xmm0\n" /* line 39 | scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x18(%ebp), %xmm1\n" /* rgbVal */
        "movss %xmm1, -0x18(%ebp)\n" /* rgbVal */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss -0x10(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x10(%ebp)\n"
        "jmp .Lfa236e_000a2547\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa236e_000a26bd:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm2\n"
        "jbe .Lfa236e_000a261d\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm2\n"
        "ja .Lfa236e_000a26bd\n"
        "jmp .Lfa236e_000a261d\n"
        ".Lfa236e_000a26dc:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n"
        "ucomiss (%eax), %xmm2\n"
        "jbe .Lfa236e_000a261d\n"
        "jmp .Lfa236e_000a26bd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa236e_000a26fb:\n"
        "movl $0, 4(%esi)\n" /* line 96 | keySize */
        "leal 8(%ebx), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a2481\n"
        "jmp .Lfa236e_000a25b9\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa236e_000a2719:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa236e_000a23dc\n"
        "jmp .Lfa236e_000a259a\n"
    );
}

/* line 2251 */
__attribute__((naked))
Bool Flash_Update(const Flash * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2251 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xb8(%ecx), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jle .Lfa273c_000a275d\n"
        "xorl %eax, %eax\n" /* line 2253 */
        "leave\n" /* line 2261 */
        "retl\n"
        ".Lfa273c_000a275d:\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%ecx)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa273c_000a278a\n"
        "movss %xmm1, 0x3c(%ecx)\n" /* line 242 */
        ".Lfa273c_000a278a:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%ecx), %xmm0\n"
        "ja .Lfa273c_000a27a3\n"
        "movl %ecx, (%esp)\n" /* line 2257 */
        "calll Light_UpdateRGB\n"
        "movl $1, %eax\n"
        ".Lfa273c_000a27a1:\n"
        "leave\n" /* line 2261 */
        "retl\n"
        ".Lfa273c_000a27a3:\n"
        "movss %xmm0, 0x3c(%ecx)\n" /* line 244 */
        "movl %ecx, (%esp)\n" /* line 2257 */
        "calll Light_UpdateRGB\n"
        "movl $1, %eax\n"
        "jmp .Lfa273c_000a27a1\n"
    );
}

/* line 880 */
__attribute__((naked))
void Particle_IntegrateVelocity(const Particle * _this, float normDuration, vec_t *outVector)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 880 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* outVector */
        "testb $8, 0xaa(%esi)\n" /* line 884 | this */
        "je .Lfa27b8_000a2987\n"
        "movss 0x12c(%esi), %xmm0\n" /* line 886 | this */
        "movss %xmm0, -0x24(%ebp)\n"
        "leal 0x1bc(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x2c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x1e0(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x2c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x24(%ebp), %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        /* } scope */
        "movss 0x130(%esi), %xmm0\n" /* line 887 | this */
        "movss %xmm0, -0x28(%ebp)\n"
        "leal 0x1c8(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1c8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x20(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x1ec(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x28(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        "movss 0x134(%esi), %xmm0\n" /* line 888 | this */
        "movss %xmm0, -0x30(%ebp)\n" /* blendFactor */
        "leal 0x1d4(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1d4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x1c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x1f8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x1c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x30(%ebp), %xmm0\n" /* blendFactor */
        "addss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x20, 0xaa(%esi)\n" /* line 897 | this */
        "je .Lfa27b8_000a2a22\n"
        ".Lfa27b8_000a2929:\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, (%edi)\n"
        "leal 4(%edi), %ecx\n" /* line 200 */
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "leal 8(%edi), %edx\n" /* line 201 */
        "movss %xmm0, 8(%edi)\n"
        ".Lfa27b8_000a2947:\n"
        "movl 0xbc(%esi), %eax\n" /* line 902 | this */
        "subl 0xb8(%esi), %eax\n" /* this */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 1 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%edi), %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edi), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss 8(%edi), %xmm0\n" /* line 274 */
        "movss %xmm0, (%edx)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa27b8_000a2987:\n"
        "leal 0x1bc(%esi), %ebx\n" /* line 892 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        /* } scope */
        "leal 0x1c8(%esi), %ebx\n" /* line 893 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1c8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x28(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal 0x1d4(%esi), %ebx\n" /* line 894 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1d4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x20, 0xaa(%esi)\n" /* line 897 | this */
        "jne .Lfa27b8_000a2929\n"
        ".Lfa27b8_000a2a22:\n"
        "movl %edi, 0x10(%esp)\n" /* line 900 | outVector */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x24(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "leal 0xd0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "leal 4(%edi), %ecx\n" /* outVector */
        "leal 8(%edi), %edx\n" /* outVector */
        "jmp .Lfa27b8_000a2947\n"
    );
}

/* line 906 */
__attribute__((naked))
void Particle_IntegrateVelocity2(const Particle * _this, float normDuration, vec_t *outVector)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 906 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* outVector */
        "testb $8, 0xaa(%esi)\n" /* line 910 | this */
        "je .Lfa2a5c_000a2c2b\n"
        "movss 0x138(%esi), %xmm0\n" /* line 912 | this */
        "movss %xmm0, -0x24(%ebp)\n"
        "leal 0x204(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x204(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x2c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x228(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x2c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x24(%ebp), %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        /* } scope */
        "movss 0x13c(%esi), %xmm0\n" /* line 913 | this */
        "movss %xmm0, -0x28(%ebp)\n"
        "leal 0x210(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x210(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x20(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x234(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x28(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        "movss 0x140(%esi), %xmm0\n" /* line 914 | this */
        "movss %xmm0, -0x30(%ebp)\n" /* blendFactor */
        "leal 0x21c(%esi), %ebx\n" /* this, source0 */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 92 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x21c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x1c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 93 | normDuration */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x240(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x1c(%ebp), %xmm0\n" /* line 96 */
        "mulss -0x30(%ebp), %xmm0\n" /* blendFactor */
        "addss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x40, 0xaa(%esi)\n" /* line 923 | this */
        "je .Lfa2a5c_000a2cc6\n"
        ".Lfa2a5c_000a2bcd:\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, (%edi)\n"
        "leal 4(%edi), %ecx\n" /* line 200 */
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "leal 8(%edi), %edx\n" /* line 201 */
        "movss %xmm0, 8(%edi)\n"
        ".Lfa2a5c_000a2beb:\n"
        "movl 0xbc(%esi), %eax\n" /* line 928 | this */
        "subl 0xb8(%esi), %eax\n" /* this */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 1 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%edi), %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edi), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss 8(%edi), %xmm0\n" /* line 274 */
        "movss %xmm0, (%edx)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 929 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa2a5c_000a2c2b:\n"
        "leal 0x204(%esi), %ebx\n" /* line 918 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x204(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        /* } scope */
        "leal 0x210(%esi), %ebx\n" /* line 919 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x210(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x28(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal 0x21c(%esi), %ebx\n" /* line 920 | this, source */
        /* { scope 1 */
        "movss 0xc(%ebp), %xmm1\n" /* line 80 | normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x21c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxCurve_Integrate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        /* } scope */
        "testb $0x40, 0xaa(%esi)\n" /* line 923 | this */
        "jne .Lfa2a5c_000a2bcd\n"
        ".Lfa2a5c_000a2cc6:\n"
        "movl %edi, 0x10(%esp)\n" /* line 926 | outVector */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x24(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "leal 0xd0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "leal 4(%edi), %ecx\n" /* outVector */
        "leal 8(%edi), %edx\n" /* outVector */
        "jmp .Lfa2a5c_000a2beb\n"
    );
}

/* line 942 */
__attribute__((naked))
void Particle_IntegrateTotalVelocity(const Particle * _this, int duration, vec_t *outVector)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 942 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* duration */
        "movl 0x10(%ebp), %ebx\n" /* outVector */
        /* { scope 1 */
        "movl 0xbc(%esi), %eax\n" /* line 222 */
        "subl 0xb8(%esi), %eax\n"
        "cmpl %edx, %eax\n" /* line 955 */
        "jle .Lfa2d00_000a2df1\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* normDuration */
        "movaps %xmm1, %xmm0\n"
        ".Lfa2d00_000a2d43:\n"
        "leal -0x14(%ebp), %eax\n" /* line 958 | velocitySum */
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_IntegrateVelocity\n"
        "leal -0x20(%ebp), %eax\n" /* line 959 | velocity2Sum */
        "movl %eax, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* normDuration */
        "movss %xmm1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_IntegrateVelocity2\n"
        "movss -0x2c(%ebp), %xmm2\n" /* line 938 */
        "mulss 0xf4(%esi), %xmm2\n"
        "movss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "mulss %xmm1, %xmm2\n"
        "mulss -0x2c(%ebp), %xmm1\n" /* line 961 | scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss 0x2ed5e8, %xmm3\n" /* 0.0f */
        /* } scope */
        "movss -0x14(%ebp), %xmm0\n" /* line 240 | velocitySum */
        "addss -0x20(%ebp), %xmm0\n" /* velocity2Sum */
        "movss %xmm0, (%ebx)\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 241 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 242 */
        "addss -0x18(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "movaps %xmm3, %xmm0\n" /* line 240 */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "addss 4(%ebx), %xmm3\n" /* line 241 */
        "movss %xmm3, 4(%ebx)\n"
        "mulss %xmm1, %xmm2\n" /* line 242 */
        "addss 8(%ebx), %xmm2\n"
        "movss %xmm2, 8(%ebx)\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 965 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa2d00_000a2df1:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 955 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movss %xmm1, -0x30(%ebp)\n" /* normDuration */
        "movaps %xmm1, %xmm0\n"
        "jmp .Lfa2d00_000a2d43\n"
    );
}

/* line 360 */
void Particle_Particle(const Particle * _this)
{
    *(int *)((byte *)_this + 0xc0) = 0;
    *(int *)_this = 0x32ffc8;
    *(int *)((byte *)_this + 0xc4) = 0;
    *(int *)((byte *)_this + 0xc8) = 0;
    *(int *)((byte *)_this + 0xcc) = 0;
}

/* overload skip: Particle_Particle (0xa2e3c) */

/* line 366 */
__attribute__((naked))
void ZN8ParticleD1Ev(void) /* Particle_~Particle */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 366 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa2e68_000a2eb6\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2e68_000a2eb6\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2e68_000a2ea9\n"
        "cmpl %eax, %edx\n" /* line 77 */
        "je .Lfa2e68_000a2eb8\n"
        ".Lfa2e68_000a2e96:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2e68_000a2ea9\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2e68_000a2e96\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2e68_000a2ea9:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2e68_000a2eb6\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 368 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfa2e68_000a2eb6:\n"
        "popl %ebp\n" /* line 368 */
        "retl\n"
        /* { scope 1 */
        ".Lfa2e68_000a2eb8:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa2e68_000a2ea9\n"
    );
}

/* line 366 */
__attribute__((naked))
void ZN8ParticleD0Ev(void) /* Particle_~Particle */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 366 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa2ec4_000a2f15\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2ec4_000a2f15\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2ec4_000a2f09\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2ec4_000a2f2c\n"
        ".Lfa2ec4_000a2ef6:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2ec4_000a2f09\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2ec4_000a2ef6\n"
        ".Lfa2ec4_000a2f04:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2ec4_000a2f09:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2ec4_000a2f15\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa2ec4_000a2f15:\n"
        "testl %ebx, %ebx\n"
        "je .Lfa2ec4_000a2f26\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 368 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfa2ec4_000a2f26:\n"
        "addl $0x14, %esp\n" /* line 368 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa2ec4_000a2f2c:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa2ec4_000a2f04\n"
    );
}

/* line 2131 */
void Light_Light(const Light * _this)
{
    *(int *)((byte *)_this + 0xc0) = 0;
    *(int *)_this = 0x330188;
}

/* overload skip: Light_Light (0xa2f4c) */

/* line 2136 */
__attribute__((naked))
void ZN5LightD1Ev(void) /* Light_~Light */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2136 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa2f64_000a2fb2\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2f64_000a2fb2\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2f64_000a2fa5\n"
        "cmpl %eax, %edx\n" /* line 77 */
        "je .Lfa2f64_000a2fb4\n"
        ".Lfa2f64_000a2f92:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2f64_000a2fa5\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2f64_000a2f92\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2f64_000a2fa5:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2f64_000a2fb2\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 2138 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfa2f64_000a2fb2:\n"
        "popl %ebp\n" /* line 2138 */
        "retl\n"
        /* { scope 1 */
        ".Lfa2f64_000a2fb4:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa2f64_000a2fa5\n"
    );
}

/* line 2136 */
__attribute__((naked))
void ZN5LightD0Ev(void) /* Light_~Light */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2136 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa2fc0_000a3011\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa2fc0_000a3011\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa2fc0_000a3005\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa2fc0_000a3028\n"
        ".Lfa2fc0_000a2ff2:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa2fc0_000a3005\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa2fc0_000a2ff2\n"
        ".Lfa2fc0_000a3000:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa2fc0_000a3005:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa2fc0_000a3011\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa2fc0_000a3011:\n"
        "testl %ebx, %ebx\n"
        "je .Lfa2fc0_000a3022\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 2138 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfa2fc0_000a3022:\n"
        "addl $0x14, %esp\n" /* line 2138 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa2fc0_000a3028:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa2fc0_000a3000\n"
    );
}

/* line 1589 */
__attribute__((naked))
void Tail_InitEndPoint(const Tail * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1589 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 1658 | this */
        "testb $2, 0xaa(%eax)\n"
        "je .Lfa3030_000a31b2\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1659 */
        "movss 0x25c(%eax), %xmm5\n" /* blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x26c, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x260, %ecx\n" /* source0 */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x260(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa3030_000a32aa\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3174\n"
        /* } scope */
        ".Lfa3030_000a309e:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa3030_000a328c\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3193\n"
        /* } scope */
        ".Lfa3030_000a3108:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1659 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movss %xmm4, 0x258(%eax)\n"
        "movl $0, 4(%esp)\n" /* line 1592 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll Tail_CalcNewEndpoint\n"
        "addl $0x1c, %esp\n" /* line 1593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa3030_000a3174:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a309e\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3174\n"
        "jmp .Lfa3030_000a309e\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa3030_000a3193:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a3108\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3193\n"
        "jmp .Lfa3030_000a3108\n"
        /* } scope */
        /* } scope */
        ".Lfa3030_000a31b2:\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1661 */
        "movl %eax, %ecx\n" /* source */
        "addl $0x260, %ecx\n" /* source */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x260(%eax), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa3030_000a326d\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3255\n"
        /* } scope */
        ".Lfa3030_000a31f3:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1661 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movss %xmm1, 0x258(%eax)\n"
        "movl $0, 4(%esp)\n" /* line 1592 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll Tail_CalcNewEndpoint\n"
        "addl $0x1c, %esp\n" /* line 1593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa3030_000a3255:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a31f3\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa3030_000a3255\n"
        "jmp .Lfa3030_000a31f3\n"
        ".Lfa3030_000a326d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a31f3\n"
        "jmp .Lfa3030_000a3255\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa3030_000a328c:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a3108\n"
        "jmp .Lfa3030_000a3193\n"
        /* } scope */
        /* { scope 2 */
        ".Lfa3030_000a32aa:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa3030_000a309e\n"
        "jmp .Lfa3030_000a3174\n"
    );
}

/* line 2164 */
__attribute__((naked))
Bool Light_Update(const Light * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2164 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa32cc_000a3468\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa32cc_000a331d\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa32cc_000a331d:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa32cc_000a35e6\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa32cc_000a341a\n"
        ".Lfa32cc_000a3339:\n"
        "movl $0, -0x24(%ebp)\n" /* or_ */
        ".Lfa32cc_000a3340:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 2192 | this */
        "js .Lfa32cc_000a3472\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 2195 | this */
        "leal 0xe4(%esi), %ecx\n" /* this, source */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0xe4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa32cc_000a3384\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        ".Lfa32cc_000a3384:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa32cc_000a339e\n"
        ".Lfa32cc_000a3393:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa32cc_000a3393\n"
        /* } scope */
        ".Lfa32cc_000a339e:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 2195 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n" /* this */
        "movl %esi, (%esp)\n" /* line 2178 | this */
        "calll Light_UpdateRGB\n"
        "movl -0x24(%ebp), %edi\n" /* line 2181 | or_, keySize */
        "testl %edi, %edi\n" /* keySize */
        "jne .Lfa32cc_000a35c0\n"
        ".Lfa32cc_000a33f5:\n"
        "leal 0x7c(%esi), %ecx\n" /* line 2184 | this, to */
        "leal 4(%esi), %edx\n" /* this, from */
        /* { scope 2: keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa32cc_000a341a:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 */
        /* { scope 2: keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 */
        "testl %eax, %eax\n"
        "js .Lfa32cc_000a3468\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n"
        "je .Lfa32cc_000a35fe\n"
        "movl %eax, 4(%ebx)\n" /* line 96 */
        "leal 8(%ebx), %edi\n" /* line 102 | keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa32cc_000a3601\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 */
        /* } scope */
        /* { scope 2: keySize */
        ".Lfa32cc_000a3468:\n"
        "xorl %eax, %eax\n" /* line 201 */
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa32cc_000a3472:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 2193 | this */
        "movss 0xc8(%esi), %xmm5\n" /* this, blendFactor */
        "leal 0xf0(%esi), %ebx\n" /* this, source1 */
        "leal 0xe4(%esi), %ecx\n" /* this, source0 */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0xe4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa32cc_000a34b7\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa32cc_000a34b7:\n"
        "movl -0x20(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa32cc_000a34d0\n"
        ".Lfa32cc_000a34c5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa32cc_000a34c5\n"
        /* } scope */
        ".Lfa32cc_000a34d0:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 */
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x2c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa32cc_000a3611\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x1c(%ebp)\n" /* keySize */
        ".Lfa32cc_000a3546:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa32cc_000a355c\n"
        ".Lfa32cc_000a3551:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa32cc_000a3551\n"
        /* } scope */
        ".Lfa32cc_000a355c:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "movl -0x30(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 2193 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n" /* this */
        "movl %esi, (%esp)\n" /* line 2178 | this */
        "calll Light_UpdateRGB\n"
        "movl -0x24(%ebp), %edi\n" /* line 2181 | or_, keySize */
        "testl %edi, %edi\n" /* keySize */
        "je .Lfa32cc_000a33f5\n"
        ".Lfa32cc_000a35c0:\n"
        "leal 0x7c(%esi), %eax\n" /* line 2182 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %edi\n" /* or_, keySize */
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa32cc_000a35e6:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa32cc_000a341a\n"
        "jmp .Lfa32cc_000a3339\n"
        ".Lfa32cc_000a35fe:\n"
        "leal 8(%ebx), %edi\n" /* keySize */
        /* { scope 2: keySize */
        ".Lfa32cc_000a3601:\n"
        "movl %edi, -0x24(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa32cc_000a3340\n"
        "jmp .Lfa32cc_000a3468\n"
        ".Lfa32cc_000a3611:\n"
        "movl -0x1c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa32cc_000a3546\n"
    );
}

/* line 782 */
__attribute__((naked))
void Particle_CalcVelocityValue(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 782 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movss 0xc(%ebp), %xmm4\n" /* normTime */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 786 | this */
        "testb $8, 0xaa(%eax)\n"
        "je .Lfa361a_000a3a70\n"
        "movss 0x12c(%eax), %xmm6\n" /* line 788 | blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x1e0, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x1bc, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x1bc(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d04\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a398f\n"
        /* } scope */
        ".Lfa361a_000a3688:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3ce6\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ae\n"
        /* } scope */
        ".Lfa361a_000a36f2:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 788 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %edx\n" /* line 789 | this */
        "movss 0x130(%edx), %xmm6\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x1ec, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x1c8, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x1c8(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3cc4\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39cd\n"
        /* } scope */
        ".Lfa361a_000a3793:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3ca6\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ec\n"
        /* } scope */
        ".Lfa361a_000a37fd:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 789 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x20(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 790 | this */
        "movss 0x134(%edx), %xmm5\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x1f8, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x1d4, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x1d4(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3c84\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a0b\n"
        /* } scope */
        ".Lfa361a_000a389e:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm3\n" /* line 56 */
        "subss %xmm1, %xmm3\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3c66\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a2a\n"
        /* } scope */
        ".Lfa361a_000a3908:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 790 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "subss %xmm3, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm3\n" /* blendFactor */
        "mulss 8(%ecx), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        ".Lfa361a_000a3953:\n"
        "movl 8(%ebp), %edx\n" /* line 799 | this */
        "testb $0x20, 0xaa(%edx)\n"
        "je .Lfa361a_000a3a49\n"
        "movl 0x14(%ebp), %eax\n" /* line 801 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa361a_000a3a54\n"
        "movl 0x10(%ebp), %eax\n" /* line 802 | outVector */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a398f:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3688\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a398f\n"
        "jmp .Lfa361a_000a3688\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a39ae:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a36f2\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ae\n"
        "jmp .Lfa361a_000a36f2\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a39cd:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3793\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39cd\n"
        "jmp .Lfa361a_000a3793\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a39ec:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a37fd\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a39ec\n"
        "jmp .Lfa361a_000a37fd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3a0b:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a389e\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a0b\n"
        "jmp .Lfa361a_000a389e\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3a2a:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3908\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3a2a\n"
        "jmp .Lfa361a_000a3908\n"
        /* } scope */
        /* } scope */
        ".Lfa361a_000a3a49:\n"
        "movl 0x14(%ebp), %eax\n" /* line 808 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa361a_000a3d8c\n"
        ".Lfa361a_000a3a54:\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | sampledVel */
        "movl 0x10(%ebp), %edx\n" /* outVector */
        "movl %eax, (%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lfa361a_000a3a68:\n"
        "addl $0x3c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa361a_000a3a70:\n"
        "movl %eax, %ecx\n"
        /* { scope 1 */
        "addl $0x1bc, %ecx\n" /* line 794 | source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x1bc(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d6a\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c09\n"
        /* } scope */
        ".Lfa361a_000a3ab3:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 794 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %ecx\n" /* line 795 | this, source */
        "addl $0x1c8, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x1c8(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d48\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c28\n"
        /* } scope */
        ".Lfa361a_000a3b3b:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 795 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 796 | this, source */
        "addl $0x1d4, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x1d4(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa361a_000a3d26\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c47\n"
        /* } scope */
        ".Lfa361a_000a3bc3:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 796 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "jmp .Lfa361a_000a3953\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c09:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3ab3\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c09\n"
        "jmp .Lfa361a_000a3ab3\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c28:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3b3b\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c28\n"
        "jmp .Lfa361a_000a3b3b\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c47:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3bc3\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa361a_000a3c47\n"
        "jmp .Lfa361a_000a3bc3\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3c66:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3908\n"
        "jmp .Lfa361a_000a3a2a\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3c84:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a389e\n"
        "jmp .Lfa361a_000a3a0b\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3ca6:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a37fd\n"
        "jmp .Lfa361a_000a39ec\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3cc4:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3793\n"
        "jmp .Lfa361a_000a39cd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3ce6:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a36f2\n"
        "jmp .Lfa361a_000a39ae\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa361a_000a3d04:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3688\n"
        "jmp .Lfa361a_000a398f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3d26:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3bc3\n"
        "jmp .Lfa361a_000a3c47\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3d48:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3b3b\n"
        "jmp .Lfa361a_000a3c28\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa361a_000a3d6a:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa361a_000a3ab3\n"
        "jmp .Lfa361a_000a3c09\n"
        /* } scope */
        /* } scope */
        ".Lfa361a_000a3d8c:\n"
        "movl 0x10(%ebp), %eax\n" /* line 811 | outVector */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0xd0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "jmp .Lfa361a_000a3a68\n"
    );
}

/* line 816 */
__attribute__((naked))
void Particle_CalcVelocity2Value(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 816 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movss 0xc(%ebp), %xmm4\n" /* normTime */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 820 | this */
        "testb $0x10, 0xaa(%eax)\n"
        "je .Lfa3dbe_000a4214\n"
        "movss 0x138(%eax), %xmm6\n" /* line 822 | blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x228, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x204, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x204(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a44a8\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4133\n"
        /* } scope */
        ".Lfa3dbe_000a3e2c:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a448a\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4152\n"
        /* } scope */
        ".Lfa3dbe_000a3e96:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 822 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %edx\n" /* line 823 | this */
        "movss 0x13c(%edx), %xmm6\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x234, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x210, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x210(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a4468\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4171\n"
        /* } scope */
        ".Lfa3dbe_000a3f37:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm5\n" /* line 56 */
        "subss %xmm1, %xmm5\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "addss %xmm2, %xmm5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a444a\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4190\n"
        /* } scope */
        ".Lfa3dbe_000a3fa1:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 823 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss %xmm5, %xmm2\n"
        "mulss %xmm2, %xmm6\n" /* blendFactor */
        "addss %xmm6, %xmm5\n" /* blendFactor */
        "mulss 8(%ecx), %xmm5\n"
        "movss %xmm5, -0x20(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 824 | this */
        "movss 0x140(%edx), %xmm5\n" /* blendFactor */
        "movl %edx, %ebx\n" /* source1 */
        "addl $0x240, %ebx\n" /* source1 */
        "movl %edx, %ecx\n" /* source0 */
        "addl $0x21c, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x21c(%edx), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a4428\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41af\n"
        /* } scope */
        ".Lfa3dbe_000a4042:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm4, %xmm3\n" /* line 56 */
        "subss %xmm1, %xmm3\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a440a\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41ce\n"
        /* } scope */
        ".Lfa3dbe_000a40ac:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 824 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "subss %xmm3, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm3\n" /* blendFactor */
        "mulss 8(%ecx), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        ".Lfa3dbe_000a40f7:\n"
        "movl 8(%ebp), %edx\n" /* line 833 | this */
        "testb $0x40, 0xaa(%edx)\n"
        "je .Lfa3dbe_000a41ed\n"
        "movl 0x14(%ebp), %eax\n" /* line 835 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa3dbe_000a41f8\n"
        "movl 0x10(%ebp), %eax\n" /* line 836 | outVector */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 847 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a4133:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e2c\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4133\n"
        "jmp .Lfa3dbe_000a3e2c\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4152:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e96\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4152\n"
        "jmp .Lfa3dbe_000a3e96\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a4171:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3f37\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4171\n"
        "jmp .Lfa3dbe_000a3f37\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4190:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3fa1\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a4190\n"
        "jmp .Lfa3dbe_000a3fa1\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a41af:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4042\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41af\n"
        "jmp .Lfa3dbe_000a4042\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a41ce:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a40ac\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a41ce\n"
        "jmp .Lfa3dbe_000a40ac\n"
        /* } scope */
        /* } scope */
        ".Lfa3dbe_000a41ed:\n"
        "movl 0x14(%ebp), %eax\n" /* line 842 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa3dbe_000a4530\n"
        ".Lfa3dbe_000a41f8:\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | sampledVel */
        "movl 0x10(%ebp), %edx\n" /* outVector */
        "movl %eax, (%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lfa3dbe_000a420c:\n"
        "addl $0x3c, %esp\n" /* line 847 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa3dbe_000a4214:\n"
        "movl %eax, %ecx\n"
        /* { scope 1 */
        "addl $0x204, %ecx\n" /* line 828 | source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x204(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a450e\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43ad\n"
        /* } scope */
        ".Lfa3dbe_000a4257:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 828 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* sampledVel */
        "movl 8(%ebp), %ecx\n" /* line 829 | this, source */
        "addl $0x210, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x210(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a44ec\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43cc\n"
        /* } scope */
        ".Lfa3dbe_000a42df:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm3\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movaps %xmm4, %xmm1\n" /* line 829 */
        "subss %xmm3, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 8(%ecx), %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 830 | this, source */
        "addl $0x21c, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "movl 0x21c(%eax), %edx\n"
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lfa3dbe_000a44ca\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43eb\n"
        /* } scope */
        ".Lfa3dbe_000a4367:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm4\n" /* line 830 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "jmp .Lfa3dbe_000a40f7\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a43ad:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4257\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43ad\n"
        "jmp .Lfa3dbe_000a4257\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a43cc:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a42df\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43cc\n"
        "jmp .Lfa3dbe_000a42df\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a43eb:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4367\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm4\n"
        "ja .Lfa3dbe_000a43eb\n"
        "jmp .Lfa3dbe_000a4367\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a440a:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a40ac\n"
        "jmp .Lfa3dbe_000a41ce\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4428:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4042\n"
        "jmp .Lfa3dbe_000a41af\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a444a:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3fa1\n"
        "jmp .Lfa3dbe_000a4190\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a4468:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3f37\n"
        "jmp .Lfa3dbe_000a4171\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a448a:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e96\n"
        "jmp .Lfa3dbe_000a4152\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa3dbe_000a44a8:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a3e2c\n"
        "jmp .Lfa3dbe_000a4133\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a44ca:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4367\n"
        "jmp .Lfa3dbe_000a43eb\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a44ec:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a42df\n"
        "jmp .Lfa3dbe_000a43cc\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa3dbe_000a450e:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm4\n"
        "jbe .Lfa3dbe_000a4257\n"
        "jmp .Lfa3dbe_000a43ad\n"
        /* } scope */
        /* } scope */
        ".Lfa3dbe_000a4530:\n"
        "movl 0x10(%ebp), %eax\n" /* line 845 | outVector */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* sampledVel */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0xd0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "jmp .Lfa3dbe_000a420c\n"
    );
}

/* line 988 */
__attribute__((naked))
void Particle_GetTotalVelocity(const Particle * _this, float normTime, vec_t *outVector, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 988 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* outVector */
        "movl 0x14(%ebp), %esi\n" /* or_ */
        /* { scope 1: gravityValue */
        "movl %esi, 0xc(%esp)\n" /* line 1000 | or_ */
        "leal -0x24(%ebp), %eax\n" /* velocityValue */
        "movl %eax, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* normTime */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_CalcVelocityValue\n"
        "movl %esi, 0xc(%esp)\n" /* line 1001 | or_ */
        "leal -0x30(%ebp), %eax\n" /* velocity2Value */
        "movl %eax, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* normTime */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_CalcVelocity2Value\n"
        /* { scope 2 */
        "movl 0xbc(%ebx), %eax\n" /* line 854 | duration */
        "subl 0xb8(%ebx), %eax\n" /* duration */
        "cvtsi2ssl %eax, %xmm0\n" /* duration */
        "mulss 0xc(%ebp), %xmm0\n" /* normTime */
        "cvttss2si %xmm0, %eax\n" /* duration */
        /* { scope 3 */
        "xorl %edx, %edx\n" /* line 936 */
        "movl %edx, -0x48(%ebp)\n" /* gravityValue */
        "movl %edx, -0x44(%ebp)\n" /* line 937 */
        "cvtsi2ssl %eax, %xmm0\n" /* line 938 */
        "mulss 0xf4(%ebx), %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 856 */
        "je .Lfa4562_000a466d\n"
        "leal -0x3c(%ebp), %eax\n" /* line 857 | gravityValue */
        "movl %eax, 8(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* gravityValue */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        /* } scope */
        ".Lfa4562_000a4604:\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 240 | velocityValue */
        "addss -0x30(%ebp), %xmm0\n" /* velocity2Value */
        "movss -0x20(%ebp), %xmm1\n" /* line 241 */
        "addss -0x2c(%ebp), %xmm1\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 242 */
        "addss -0x28(%ebp), %xmm2\n"
        "addss -0x3c(%ebp), %xmm0\n" /* line 240 | gravityValue */
        "movss %xmm0, (%edi)\n"
        "addss -0x38(%ebp), %xmm1\n" /* line 241 */
        "movss %xmm1, 4(%edi)\n"
        "addss -0x34(%ebp), %xmm2\n" /* line 242 */
        "movss %xmm2, 8(%edi)\n"
        "leal 0xc4(%ebx), %eax\n"
        /* { scope 2 */
        "addss 0xc4(%ebx), %xmm0\n" /* line 240 */
        "movss %xmm0, (%edi)\n"
        "addss 4(%eax), %xmm1\n" /* line 241 */
        "movss %xmm1, 4(%edi)\n"
        "addss 8(%eax), %xmm2\n" /* line 242 */
        "movss %xmm2, 8(%edi)\n"
        /* } scope */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1013 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: gravityValue */
        /* { scope 2 */
        ".Lfa4562_000a466d:\n"
        "movl %edx, -0x3c(%ebp)\n" /* line 199 | gravityValue */
        "movl %edx, -0x38(%ebp)\n" /* line 200 */
        "movss %xmm0, -0x34(%ebp)\n" /* line 201 */
        "jmp .Lfa4562_000a4604\n"
    );
}

/* line 1911 */
__attribute__((naked))
void Emitter_UpdateEmitFx(const Emitter * _this, vec_t *bindVelocity, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1911 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: time, worldorg */
        "testb $1, 0xa9(%ebx)\n" /* line 1927 | this */
        "je .Lfa467a_000a48c2\n"
        "movl 0x195ed88, %ecx\n" /* line 1930 */
        "movl (%ecx), %eax\n"
        "movl 0xc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfa467a_000a48c2\n"
        "movss 0x274(%ebx), %xmm0\n" /* line 1937 | this */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n" /* step2 */
        "movl 0x270(%ebx), %esi\n" /* line 1942 | this, t */
        "movl 0xb8(%ebx), %edx\n" /* line 261 */
        "movl 4(%eax), %eax\n" /* line 1944 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x88(%ebp)\n" /* age */
        "movl 0xbc(%ebx), %eax\n" /* line 1945 | this */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n" /* lifeTime */
        "xorl %edi, %edi\n" /* dif */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* ftimeTotal */
        "leal 0x264(%ebx), %eax\n" /* this */
        "movl %eax, -0xa4(%ebp)\n"
        "leal 0x24c(%ebx), %edx\n" /* this */
        "movl %edx, -0xa8(%ebp)\n"
        "leal 0x250(%ebx), %eax\n" /* this */
        "movl %eax, -0xac(%ebp)\n"
        "leal 0x268(%ebx), %edx\n" /* this */
        "movl %edx, -0xb0(%ebp)\n"
        "leal 0x254(%ebx), %eax\n" /* this */
        "movl %eax, -0xb4(%ebp)\n"
        "leal 0x26c(%ebx), %edx\n" /* this */
        "movl %edx, -0xb8(%ebp)\n"
        ".Lfa467a_000a4754:\n"
        "movl (%ecx), %eax\n" /* line 1949 */
        "cmpl 4(%eax), %esi\n" /* t */
        "jge .Lfa467a_000a48c2\n"
        ".Lfa467a_000a475f:\n"
        "addl $0xc, %edi\n" /* line 1951 | dif */
        "cvtsi2ssl %edi, %xmm0\n" /* line 1954 | dif */
        "movss %xmm0, -0xa0(%ebp)\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x94(%ebp)\n" /* ftime */
        "movss 0x24c(%ebx), %xmm0\n" /* line 240 */
        "addss 0x264(%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* oldorg */
        "movss 0x250(%ebx), %xmm0\n" /* line 241 */
        "addss 0x268(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 0x254(%ebx), %xmm0\n" /* line 242 */
        "addss 0x26c(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0x8c(%ebp), %xmm1\n" /* line 1966 | ftimeTotal */
        "addss -0x88(%ebp), %xmm1\n" /* age */
        "movss %xmm1, -0x80(%ebp)\n" /* time */
        /* { scope 2 */
        "divss -0x84(%ebp), %xmm1\n" /* line 588 | lifeTime */
        "movss 0x2ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1967 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* velocity */
        "movl %edx, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 288 | ftime */
        "mulss -0x48(%ebp), %xmm0\n" /* velocity */
        "addss 0x24c(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* org */
        "movss -0x94(%ebp), %xmm0\n" /* line 289 | ftime */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss 0x250(%ebx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 290 | ftime */
        "mulss -0x40(%ebp), %xmm0\n"
        "addss 0x254(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1972 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa467a_000a4885\n"
        "movl $1, %edx\n"
        "leal -0x20(%ebp), %eax\n"
        ".Lfa467a_000a485f:\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 1977 | ftime */
        "movl 0xc(%ebp), %ecx\n" /* bindVelocity */
        "mulss -4(%ecx, %edx, 4), %xmm0\n"
        "addss -4(%eax), %xmm0\n"
        "movss %xmm0, -4(%eax)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 1976 */
        "jne .Lfa467a_000a485f\n"
        ".Lfa467a_000a4885:\n"
        "leal -0x30(%ebp), %eax\n" /* line 1983 | oldorg */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x98(%ebp)\n"
        "movss -0x90(%ebp), %xmm0\n" /* step2 */
        "ucomiss -0x98(%ebp), %xmm0\n"
        "jbe .Lfa467a_000a48cd\n"
        "addl $0xc, %esi\n" /* line 1985 | t */
        "movl 0x195ed88, %ecx\n"
        "movl (%ecx), %eax\n" /* line 1949 */
        "cmpl 4(%eax), %esi\n" /* t */
        "jl .Lfa467a_000a475f\n"
        /* } scope */
        ".Lfa467a_000a48c2:\n"
        "addl $0xec, %esp\n" /* line 2082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: time, worldorg */
        ".Lfa467a_000a48cd:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1990 | or_ */
        "testl %ecx, %ecx\n"
        "je .Lfa467a_000a4bb9\n"
        /* { scope 2 */
        "leal -0x54(%ebp), %eax\n" /* line 1993 | worldorg */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* org */
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* or_ */
        "movl %ecx, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "movl 0xc0(%ebx), %eax\n" /* line 1994 | this */
        "addl $0x3c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* worldorg */
        /* } scope */
        ".Lfa467a_000a4909:\n"
        "movl %eax, 8(%esp)\n" /* line 2015 */
        "movl 0x290(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        /* { scope 2 */
        "movss -0x48(%ebp), %xmm2\n" /* line 304 | velocity */
        "movss -0x44(%ebp), %xmm0\n"
        "movss -0x40(%ebp), %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "movss -0x94(%ebp), %xmm1\n" /* line 2024 | ftime, t2 */
        "mulss %xmm1, %xmm1\n" /* t2 */
        "movaps %xmm2, %xmm0\n" /* line 2026 | dF */
        "addss %xmm2, %xmm0\n" /* dF */
        "mulss -0x94(%ebp), %xmm0\n" /* ftime, dF */
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 2027 | 0.0f */
        "jne .Lfa467a_000a4ab4\n"
        "jp .Lfa467a_000a4ab4\n"
        "movss -0x94(%ebp), %xmm1\n" /* ftime */
        "addss -0x80(%ebp), %xmm1\n" /* time */
        "divss -0x84(%ebp), %xmm1\n" /* lifeTime */
        /* } scope */
        ".Lfa467a_000a498c:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2052 | or_ */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* v */
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | org */
        "movl -0xa8(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x258(%ebx), %edx\n" /* line 2061 | this, to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | v */
        "movl %eax, 0x258(%ebx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x10(%ebp), %edx\n" /* line 2065 | or_ */
        "testl %edx, %edx\n"
        "je .Lfa467a_000a4a40\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 2069 | scale */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "movl 0xc(%ebp), %ecx\n" /* bindVelocity */
        "mulss (%ecx), %xmm1\n"
        "movl -0xa4(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss 4(%ecx), %xmm1\n"
        "movl -0xb0(%ebp), %edx\n"
        "addss (%edx), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 290 */
        "movl -0xb8(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lfa467a_000a4a40:\n"
        "movl %edi, %esi\n" /* line 2073 | dif, t */
        "addl 0x270(%ebx), %esi\n" /* this, t */
        "movl %esi, 0x270(%ebx)\n" /* t, this */
        "movss -0x8c(%ebp), %xmm0\n" /* line 2074 | ftimeTotal */
        "addss -0x94(%ebp), %xmm0\n" /* ftime */
        "movss %xmm0, -0x8c(%ebp)\n" /* ftimeTotal */
        "movss 0x294(%ebx), %xmm1\n" /* line 668 */
        "movss %xmm1, -0x7c(%ebp)\n"
        "calll crandom\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "mulss 0x298(%ebx), %xmm0\n"
        "addss -0x7c(%ebp), %xmm0\n"
        "movss %xmm0, 0x274(%ebx)\n"
        "mulss %xmm0, %xmm0\n" /* line 2080 */
        "movss %xmm0, -0x90(%ebp)\n" /* step2 */
        "xorl %edi, %edi\n" /* dif */
        "movl 0x195ed88, %ecx\n"
        "jmp .Lfa467a_000a4754\n"
        /* { scope 2 */
        ".Lfa467a_000a4ab4:\n"
        "mulss %xmm1, %xmm2\n" /* line 428 */
        "subss -0x90(%ebp), %xmm2\n" /* step2 */
        "divss %xmm0, %xmm2\n"
        "mulss 0x2ed5c8, %xmm2\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm2\n" /* 0.5f */
        "movss %xmm2, (%esp)\n"
        "calll floorf\n"
        "fstps -0x9c(%ebp)\n"
        "cvttss2si -0x9c(%ebp), %eax\n"
        "subl %eax, %edi\n"
        "movl %esi, %eax\n" /* line 2033 | t */
        "subl 0x270(%ebx), %eax\n" /* this */
        "cmpl %eax, %edi\n" /* dif */
        "cmovll %eax, %edi\n" /* dif */
        "cvtsi2ssl %edi, %xmm0\n" /* line 2039 | dif */
        "movss %xmm0, -0xa0(%ebp)\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x94(%ebp)\n" /* ftime */
        "movss -0x80(%ebp), %xmm1\n" /* line 588 | time */
        "addss %xmm0, %xmm1\n"
        "divss -0x84(%ebp), %xmm1\n" /* lifeTime */
        "movss 0x2ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movl 0x10(%ebp), %eax\n" /* line 2041 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* velocity */
        "movl %edx, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "movss %xmm1, -0xc8(%ebp)\n"
        "calll Particle_GetTotalVelocity\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 288 | ftime */
        "mulss -0x48(%ebp), %xmm0\n" /* velocity */
        "movl -0xa8(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* org */
        "movss -0x94(%ebp), %xmm0\n" /* line 289 | ftime */
        "mulss -0x44(%ebp), %xmm0\n"
        "movl -0xac(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 290 | ftime */
        "mulss -0x40(%ebp), %xmm0\n"
        "movl -0xb4(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0xc8(%ebp), %xmm1\n"
        "jmp .Lfa467a_000a498c\n"
        /* } scope */
        ".Lfa467a_000a4bb9:\n"
        "movss -0x48(%ebp), %xmm3\n" /* line 324 | velocity */
        "movss -0x44(%ebp), %xmm0\n"
        "movss -0x40(%ebp), %xmm2\n"
        "movaps %xmm3, %xmm1\n" /* line 81 */
        "mulss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 1999 | 0.0f */
        "jbe .Lfa467a_000a4c48\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 2001 | 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm0, %xmm3\n" /* line 272 */
        "movss %xmm3, -0x78(%ebp)\n" /* newEffectAxis */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x44(%ebp), %xmm1\n"
        "movss %xmm1, -0x74(%ebp)\n"
        "mulss -0x40(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x70(%ebp)\n"
        /* } scope */
        "leal -0x60(%ebp), %eax\n" /* line 2002 */
        "movl %eax, 8(%esp)\n"
        "leal -0x6c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %edx\n" /* newEffectAxis */
        "movl %edx, (%esp)\n"
        "calll MakeNormalVectors\n"
        ".Lfa467a_000a4c31:\n"
        "movl $0, 0x10(%esp)\n" /* line 2015 */
        "leal -0x78(%ebp), %ecx\n" /* newEffectAxis */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* org */
        "jmp .Lfa467a_000a4909\n"
        ".Lfa467a_000a4c48:\n"
        "leal 0x48(%ebx), %edx\n" /* line 2002 | this */
        /* { scope 2 */
        "movl 0x48(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x78(%ebp)\n" /* newEffectAxis */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x70(%ebp)\n"
        "leal 0x54(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x54(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "leal 0x60(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x60(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x60(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "jmp .Lfa467a_000a4c31\n"
    );
}

/* line 968 */
__attribute__((naked))
void Particle_GetTotalVelocityAtTime0(const Particle * _this, vec_t *outVector)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 968 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        "movl 0xc0(%edi), %ebx\n" /* line 972 | this */
        "testl %ebx, %ebx\n"
        "je .Lfa4c8a_000a4d2b\n"
        "movl 0xc0(%edi), %ebx\n" /* line 101 */
        /* { scope 2 */
        "movl 0x3c(%ebx), %ecx\n" /* line 90 */
        "testl %ecx, %ecx\n"
        "js .Lfa4c8a_000a4cea\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n"
        "je .Lfa4c8a_000a4cff\n"
        "movl %eax, 4(%ebx)\n" /* line 96 */
        "leal 8(%ebx), %esi\n" /* line 102 */
        "movl %esi, 4(%esp)\n"
        "leal 0x3c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa4c8a_000a4d02\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 */
        /* } scope */
        ".Lfa4c8a_000a4cea:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl 0xc(%ebp), %edx\n" /* outVector */
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 985 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa4c8a_000a4cff:\n"
        "leal 8(%ebx), %esi\n" /* this */
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa4c8a_000a4d02:\n"
        "movl %esi, %eax\n" /* line 111 */
        /* } scope */
        "testl %esi, %esi\n" /* line 975 */
        "je .Lfa4c8a_000a4cea\n"
        ".Lfa4c8a_000a4d08:\n"
        "movl %eax, 0xc(%esp)\n" /* line 984 */
        "movl 0xc(%ebp), %eax\n" /* outVector */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 985 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4c8a_000a4d2b:\n"
        "xorl %eax, %eax\n" /* line 978 */
        "jmp .Lfa4c8a_000a4d08\n"
    );
}

/* line 621 */
__attribute__((naked))
void Particle_ApplyImpact(const Particle * _this, const orientation_t *or_, float normTime, const vec_t *velocity, float traceFraction, const vec_t *traceNormal)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 621 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* velocity */
        "movl 0x1c(%ebp), %edx\n" /* traceNormal */
        /* { scope 1 */
        "leal 8(%edx), %ecx\n" /* line 602 */
        "pxor %xmm3, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa4d30_000a4d80\n"
        "movss (%eax), %xmm0\n" /* line 316 */
        "movss 4(%eax), %xmm1\n"
        "movss 8(%eax), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 602 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss 0x2ed6a8, %xmm0\n" /* 16.0f */
        "jb .Lfa4d30_000a4ebc\n"
        ".Lfa4d30_000a4d80:\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 607 | traceFraction */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lfa4d30_000a4d90\n"
        "je .Lfa4d30_000a4ec2\n"
        ".Lfa4d30_000a4d90:\n"
        "movl 0xc(%ebp), %eax\n" /* line 636 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa4d30_000a4ede\n"
        "leal -0x14(%ebp), %eax\n" /* line 637 | normal */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        ".Lfa4d30_000a4db1:\n"
        "movl 0xc(%ebp), %eax\n" /* line 641 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* reflectVelocity */
        "movl %eax, 8(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* normTime */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 248 | reflectVelocity */
        "movaps %xmm0, %xmm5\n"
        "subss 0xc4(%ebx), %xmm5\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 249 */
        "subss 0xc8(%ebx), %xmm1\n"
        "movss -0x18(%ebp), %xmm4\n" /* line 250 */
        "subss 0xcc(%ebx), %xmm4\n"
        "movss 0x100(%ebx), %xmm2\n" /* line 646 | this, scale */
        /* { scope 2 */
        "mulss %xmm2, %xmm0\n" /* line 272 */
        "movss %xmm0, -0x20(%ebp)\n" /* reflectVelocity */
        "movaps %xmm2, %xmm3\n" /* line 273 */
        "mulss -0x1c(%ebp), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        "mulss -0x18(%ebp), %xmm2\n" /* line 274 */
        "movss %xmm2, -0x18(%ebp)\n"
        /* } scope */
        "subss %xmm5, %xmm0\n" /* line 248 */
        "movss %xmm0, 0xc4(%ebx)\n"
        "movaps %xmm3, %xmm0\n" /* line 249 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc8(%ebx)\n"
        "movaps %xmm2, %xmm0\n" /* line 250 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, 0xcc(%ebx)\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 304 | normal */
        "movaps %xmm0, %xmm1\n" /* line 655 | scale */
        "mulss -0x20(%ebp), %xmm1\n" /* reflectVelocity, scale */
        "mulss -0x10(%ebp), %xmm3\n"
        "addss %xmm3, %xmm1\n" /* scale */
        "mulss -0xc(%ebp), %xmm2\n"
        "addss %xmm2, %xmm1\n" /* scale */
        "mulss 0x2ed628, %xmm1\n" /* -2.0f, scale */
        /* { scope 2 */
        "mulss %xmm1, %xmm0\n" /* line 288 */
        "addss 0xc4(%ebx), %xmm0\n"
        "movss %xmm0, 0xc4(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x10(%ebp), %xmm0\n"
        "addss 0xc8(%ebx), %xmm0\n"
        "movss %xmm0, 0xc8(%ebx)\n"
        "mulss -0xc(%ebp), %xmm1\n" /* line 290 */
        "addss 0xcc(%ebx), %xmm1\n"
        "movss %xmm1, 0xcc(%ebx)\n"
        /* } scope */
        /* } scope */
        "addl $0x34, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4d30_000a4ebc:\n"
        "jp .Lfa4d30_000a4d80\n" /* line 602 */
        ".Lfa4d30_000a4ec2:\n"
        "movl 0xa8(%ebx), %eax\n" /* line 616 */
        "andl $0xfffff7df, %eax\n"
        "orl $0x1000000, %eax\n" /* line 617 */
        "movl %eax, 0xa8(%ebx)\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4d30_000a4ede:\n"
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* normal */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        "jmp .Lfa4d30_000a4db1\n"
    );
}

/* line 677 */
__attribute__((naked))
Bool Particle_UpdateOrigin(const Particle * _this, const orientation_t *or_)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 677 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "testb $1, 0xab(%ebx)\n" /* line 694 | this */
        "jne .Lfa4ef4_000a510f\n"
        "movl 0x195ed88, %eax\n" /* line 697 */
        "movl (%eax), %eax\n"
        "movl 0xc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfa4ef4_000a510f\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 703 */
        "movss %xmm0, -0xac(%ebp)\n" /* ftime */
        "movss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss -0xac(%ebp), %xmm1\n" /* ftime */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0xac(%ebp)\n" /* ftime */
        "movl 0xb8(%ebx), %edx\n" /* line 261 */
        "movl 4(%eax), %eax\n" /* line 707 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0xa4(%ebp)\n" /* age */
        "movl 0xbc(%ebx), %eax\n" /* line 708 | this */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n" /* lifeTime */
        "movss -0xa4(%ebp), %xmm1\n" /* line 588 | age */
        "divss %xmm0, %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* line 712 | or_ */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* velocity */
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_GetTotalVelocity\n"
        "leal 4(%ebx), %esi\n" /* line 714 | this */
        "movss -0xac(%ebp), %xmm2\n" /* line 288 | ftime */
        "mulss -0x3c(%ebp), %xmm2\n" /* velocity */
        "addss 4(%ebx), %xmm2\n"
        "movss %xmm2, -0x30(%ebp)\n" /* new_origin */
        "leal 8(%ebx), %eax\n" /* line 289 */
        "movl %eax, -0xa0(%ebp)\n"
        "movss -0xac(%ebp), %xmm1\n" /* ftime */
        "mulss -0x38(%ebp), %xmm1\n"
        "addss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "leal 0xc(%ebx), %eax\n" /* line 290 */
        "movl %eax, -0x9c(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n" /* ftime */
        "mulss -0x34(%ebp), %xmm0\n"
        "addss 0xc(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movl 0xa8(%ebx), %edx\n" /* line 719 | this */
        "testb $0x20, %dl\n"
        "je .Lfa4ef4_000a50ee\n"
        "movl 0xc(%ebp), %eax\n" /* line 721 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa4ef4_000a511f\n"
        "leal -0x60(%ebp), %eax\n" /* line 723 | start */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "leal -0x6c(%ebp), %edi\n" /* line 724 | end */
        "movl %edi, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* new_origin */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "movl 0xa8(%ebx), %edx\n" /* this */
        ".Lfa4ef4_000a505a:\n"
        "andb $0x40, %dl\n" /* line 734 */
        "je .Lfa4ef4_000a5148\n"
        "leal 0x14(%ebx), %edx\n" /* this */
        /* { scope 2 */
        "movl 0x14(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x48(%ebp)\n" /* mins */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        "leal 0x20(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x20(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x54(%ebp)\n" /* maxs */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x4c(%ebp)\n"
        /* } scope */
        "movl $1, 0x1c(%esp)\n" /* line 738 */
        "movl $0xffffffff, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* maxs */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* mins */
        ".Lfa4ef4_000a50ab:\n"
        "movl %eax, 0xc(%esp)\n" /* line 742 */
        "leal -0x60(%ebp), %eax\n" /* start */
        "movl %eax, 8(%esp)\n"
        "leal -0x90(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_Trace\n"
        "cmpb $0, -0x6d(%ebp)\n" /* line 664 */
        "jne .Lfa4ef4_000a50ee\n"
        "cmpb $0, -0x6e(%ebp)\n" /* line 667 */
        "jne .Lfa4ef4_000a50ee\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 670 | 1.0f */
        "ucomiss -0x90(%ebp), %xmm0\n" /* trace */
        "jp .Lfa4ef4_000a516a\n"
        "jne .Lfa4ef4_000a516a\n"
        ".Lfa4ef4_000a50ee:\n"
        "movl -0x30(%ebp), %eax\n" /* line 199 | new_origin */
        "movl %eax, (%esi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 779 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4ef4_000a510f:\n"
        "movl $1, %eax\n" /* line 778 */
        /* } scope */
        ".Lfa4ef4_000a5114:\n"
        "addl $0xcc, %esp\n" /* line 779 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa4ef4_000a511f:\n"
        "movl 4(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x60(%ebp)\n" /* start */
        "movl 8(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "movss %xmm2, -0x6c(%ebp)\n" /* line 199 | end */
        "movss %xmm1, -0x68(%ebp)\n" /* line 200 */
        "movss %xmm0, -0x64(%ebp)\n" /* line 201 */
        "leal -0x6c(%ebp), %edi\n" /* end */
        "jmp .Lfa4ef4_000a505a\n"
        ".Lfa4ef4_000a5148:\n"
        "movl $1, 0x1c(%esp)\n" /* line 742 */
        "movl $0xffffffff, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "jmp .Lfa4ef4_000a50ab\n"
        ".Lfa4ef4_000a516a:\n"
        "movl 0xa8(%ebx), %edx\n" /* line 748 | this */
        "testb $8, %dh\n"
        "je .Lfa4ef4_000a51ff\n"
        "movss -0x90(%ebp), %xmm2\n" /* line 750 | trace, fraction */
        /* { scope 2 */
        "movss -0x60(%ebp), %xmm1\n" /* line 1203 | start */
        "movss -0x6c(%ebp), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* endpos */
        "movss -0x5c(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x68(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x58(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x64(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x8c(%ebp), %eax\n" /* line 751 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, 8(%esp)\n"
        "movl 0x2c(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        "movl 0xa8(%ebx), %edx\n" /* this */
        ".Lfa4ef4_000a51ff:\n"
        "andb $4, %dh\n" /* line 754 */
        "jne .Lfa4ef4_000a52eb\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 761 | trace */
        "movss -0xac(%ebp), %xmm0\n" /* line 588 | ftime */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xac(%ebp)\n" /* ftime */
        "movss -0xa4(%ebp), %xmm0\n" /* age */
        "addss -0xac(%ebp), %xmm0\n" /* ftime */
        "divss -0xa8(%ebp), %xmm0\n" /* lifeTime */
        "movss %xmm0, -0xa4(%ebp)\n" /* age */
        "movss 0x2ed5d0, %xmm0\n" /* line 590 | 1.0f */
        "minss -0xa4(%ebp), %xmm0\n" /* age */
        "leal -0x8c(%ebp), %eax\n" /* line 762 */
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* velocity */
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* or_ */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_ApplyImpact\n"
        "movss -0x90(%ebp), %xmm2\n" /* line 766 | trace, fraction */
        /* { scope 2 */
        "movss (%esi), %xmm1\n" /* line 1203 */
        "movss -0x30(%ebp), %xmm0\n" /* new_origin */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movl -0xa0(%ebp), %eax\n" /* line 1204 */
        "movss (%eax), %xmm1\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 1205 */
        "movss (%eax), %xmm1\n"
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        "movl $1, %eax\n"
        "jmp .Lfa4ef4_000a5114\n"
        /* } scope */
        ".Lfa4ef4_000a52eb:\n"
        "xorl %eax, %eax\n" /* line 754 */
        "jmp .Lfa4ef4_000a5114\n"
    );
}

/* line 1833 */
__attribute__((naked))
Bool Emitter_Update(const Emitter * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1833 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: axis */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa52f2_000a56e9\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa52f2_000a5346\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa52f2_000a5346:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa52f2_000a5701\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa52f2_000a56a3\n"
        ".Lfa52f2_000a5362:\n"
        "movl $0, -0x6c(%ebp)\n" /* or_ */
        ".Lfa52f2_000a5369:\n"
        "leal 4(%esi), %eax\n" /* line 1851 | this */
        "movl %eax, -0x70(%ebp)\n"
        "movss 4(%esi), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x50(%ebp)\n"
        "leal 8(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movss 8(%esi), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "leal 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "movss 0xc(%esi), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1853 | or_ */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa52f2_000a56e9\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 310 */
        "ucomiss 4(%esi), %xmm0\n"
        "jne .Lfa52f2_000a53d9\n"
        "jp .Lfa52f2_000a53d9\n"
        "movss -0x54(%ebp), %xmm0\n"
        "ucomiss 8(%esi), %xmm0\n"
        "jne .Lfa52f2_000a53d9\n"
        "jp .Lfa52f2_000a53d9\n"
        "movss -0x58(%ebp), %xmm0\n"
        "ucomiss 0xc(%esi), %xmm0\n"
        "je .Lfa52f2_000a583a\n"
        ".Lfa52f2_000a53d9:\n"
        "xorl %eax, %eax\n"
        ".Lfa52f2_000a53db:\n"
        "testl %eax, %eax\n" /* line 1858 */
        "je .Lfa52f2_000a56f6\n"
        "leal 0x284(%esi), %ecx\n" /* line 1859 | this */
        "movss 0x2ed6ac, %xmm0\n" /* line 272 | 0.699999988079071f */
        "movss 0x284(%esi), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0x284(%esi)\n"
        "movss 4(%ecx), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%ecx)\n"
        ".Lfa52f2_000a541d:\n"
        "movl 0x195ed88, %eax\n" /* line 2089 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0xc(%eax), %xmm1\n" /* scale */
        "mulss 0x2ed738, %xmm1\n" /* 0.009999999776482582f, scale */
        "leal 0x278(%esi), %edx\n" /* this, result */
        /* { scope 2: keySize, i */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x284(%esi), %xmm0\n"
        "addss 0x278(%esi), %xmm0\n"
        "movss %xmm0, 0x278(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%ecx), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "mulss 8(%ecx), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, 8(%edx)\n"
        /* } scope */
        "leal 0x48(%esi), %eax\n" /* line 2090 | this */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll AnglesToAxis\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "jns .Lfa52f2_000a5725\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, i */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa52f2_000a54d5\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa52f2_000a54d5:\n"
        "movl -0x60(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa52f2_000a54ee\n"
        ".Lfa52f2_000a54e3:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa52f2_000a54e3\n"
        /* } scope */
        ".Lfa52f2_000a54ee:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 | key */
        "movl %edx, -0x80(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x7c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa52f2_000a57be\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x4c(%ebp)\n" /* keySize */
        ".Lfa52f2_000a5564:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa52f2_000a557a\n"
        ".Lfa52f2_000a556f:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa52f2_000a556f\n"
        /* } scope */
        ".Lfa52f2_000a557a:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x80(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        ".Lfa52f2_000a55cb:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1866 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa52f2_000a55dd\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x24(%ebp)\n" /* bindVelocity */
        "movl %eax, -0x20(%ebp)\n" /* line 184 */
        "movl %eax, -0x1c(%ebp)\n" /* line 185 */
        ".Lfa52f2_000a55dd:\n"
        "testb $0x10, 0xa8(%esi)\n" /* line 1869 | this */
        "je .Lfa52f2_000a567d\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1872 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa52f2_000a584a\n"
        /* { scope 2: keySize, i */
        "leal 0x7c(%esi), %eax\n" /* line 1876 | this */
        "movl %eax, 8(%esp)\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x6c(%ebp), %ebx\n" /* or_, source1 */
        "movl %ebx, (%esp)\n" /* source1 */
        "calll OrientationPosToWorldPos\n"
        "movl $0, -0x5c(%ebp)\n" /* i */
        "leal 0x40(%esi), %edi\n" /* this, keySize */
        "xorl %ebx, %ebx\n" /* source1 */
        /* { scope 3 */
        ".Lfa52f2_000a561a:\n"
        "leal -0x48(%ebp), %edx\n" /* line 1879 | axis, to */
        "addl %ebx, %edx\n" /* source1, to */
        "leal 8(%edi), %ecx\n" /* keySize */
        /* { scope 4 */
        "movl 0x48(%ebx, %esi), %eax\n" /* line 199 | key */
        "movl %eax, (%edx)\n"
        "movl 0x4c(%ebx, %esi), %eax\n" /* line 200 | key */
        "movl %eax, -0x44(%ebx, %ebp)\n" /* key */
        "movl 0x50(%ebx, %esi), %eax\n" /* line 201 | key */
        "movl %eax, -0x40(%ebx, %ebp)\n" /* key */
        /* } scope */
        "movl %ecx, 8(%esp)\n" /* line 1880 */
        "movl %edx, 4(%esp)\n"
        "movl -0x6c(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "calll OrientationDirToWorldDir\n"
        "addl $1, -0x5c(%ebp)\n" /* line 1877 | i */
        "addl $0xc, %ebx\n" /* source1 */
        "addl $0xc, %edi\n" /* keySize */
        "cmpl $3, -0x5c(%ebp)\n" /* i */
        "jne .Lfa52f2_000a561a\n"
        /* } scope */
        "movl 0x88(%esi), %eax\n" /* line 1882 | this */
        "movl %eax, 0x98(%esi)\n" /* this */
        "movl 0x195ed88, %eax\n" /* line 1884 */
        "movl (%eax), %edx\n"
        "movl 0x270(%esi), %ecx\n" /* this */
        "cmpl 4(%edx), %ecx\n"
        "jl .Lfa52f2_000a57c6\n"
        ".Lfa52f2_000a567d:\n"
        "movl -0x6c(%ebp), %edi\n" /* or_, keySize */
        /* } scope */
        ".Lfa52f2_000a5680:\n"
        "movl %edi, 8(%esp)\n" /* line 1905 | keySize */
        "leal -0x24(%ebp), %eax\n" /* bindVelocity */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Emitter_UpdateEmitFx\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1908 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: axis */
        ".Lfa52f2_000a56a3:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, i */
        "movl 0x3c(%ebx), %eax\n" /* line 90 | key */
        "testl %eax, %eax\n"
        "js .Lfa52f2_000a56e9\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa52f2_000a5715\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa52f2_000a5718\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        ".Lfa52f2_000a56e9:\n"
        "xorl %eax, %eax\n" /* line 1907 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1908 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa52f2_000a56f6:\n"
        "leal 0x284(%esi), %ecx\n" /* this */
        "jmp .Lfa52f2_000a541d\n"
        /* { scope 1: axis */
        ".Lfa52f2_000a5701:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa52f2_000a56a3\n"
        "jmp .Lfa52f2_000a5362\n"
        ".Lfa52f2_000a5715:\n"
        "leal 8(%ebx), %edi\n" /* key, keySize */
        /* { scope 2: keySize, i */
        ".Lfa52f2_000a5718:\n"
        "movl %edi, -0x6c(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa52f2_000a5369\n"
        "jmp .Lfa52f2_000a56e9\n"
        ".Lfa52f2_000a5725:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, i */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa52f2_000a575b\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa52f2_000a575b:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n" /* key */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa52f2_000a5775\n"
        ".Lfa52f2_000a576a:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa52f2_000a576a\n"
        /* } scope */
        ".Lfa52f2_000a5775:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "jmp .Lfa52f2_000a55cb\n"
        ".Lfa52f2_000a57be:\n"
        "movl -0x4c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa52f2_000a5564\n"
        /* { scope 2: keySize, i */
        ".Lfa52f2_000a57c6:\n"
        "leal 0x264(%esi), %eax\n" /* line 1889 | this, b */
        /* { scope 3 */
        "movl -0x6c(%ebp), %ebx\n" /* line 248 | or_, this */
        "movss (%ebx), %xmm0\n" /* this */
        "subss 0x264(%esi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* bindVelocity */
        "movss 4(%ebx), %xmm0\n" /* line 249 | this */
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* line 250 | this */
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movl 4(%edx), %eax\n" /* line 1893 */
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f, scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* bindVelocity */
        "movss %xmm1, -0x24(%ebp)\n" /* bindVelocity */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl %ebx, %edi\n" /* this, keySize */
        "jmp .Lfa52f2_000a5680\n"
        /* } scope */
        /* } scope */
        ".Lfa52f2_000a583a:\n"
        "jp .Lfa52f2_000a53d9\n" /* line 310 */
        "movl $1, %eax\n"
        "jmp .Lfa52f2_000a53db\n"
        ".Lfa52f2_000a584a:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1900 | this, to */
        /* { scope 2: keySize, i */
        "movl -0x70(%ebp), %edi\n" /* line 199 | keySize */
        "movl (%edi), %eax\n" /* keySize */
        "movl %eax, 0x7c(%esi)\n"
        "movl -0x68(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x64(%ebp), %ebx\n" /* line 201 | key */
        "movl (%ebx), %eax\n" /* key */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x88(%esi), %eax\n" /* line 1901 | this */
        "movl %eax, 0x98(%esi)\n" /* this */
        "movl -0x6c(%ebp), %edi\n" /* or_, keySize */
        "jmp .Lfa52f2_000a5680\n"
    );
}

/* line 1058 */
__attribute__((naked))
void Particle_UpdateAlpha(const Particle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1058 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1062 | this */
        "testb $0x40, 0xa9(%eax)\n"
        "je .Lfa587c_000a5a92\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1063 */
        "movss 0x11c(%eax), %xmm5\n" /* blendFactor */
        "movl %eax, %ebx\n" /* source1 */
        "addl $0x168, %ebx\n" /* source1 */
        "movl %eax, %ecx\n" /* source0 */
        "addl $0x15c, %ecx\n" /* source0 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x15c(%eax), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa587c_000a5b61\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a59fb\n"
        /* } scope */
        ".Lfa587c_000a58e7:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %esi\n" /* line 91 | keySize */
        "movl (%esi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa587c_000a5b43\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5a1a\n"
        /* } scope */
        ".Lfa587c_000a5951:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "leal (%esi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 55 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        /* } scope */
        ".Lfa587c_000a5997:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 45 | 1.0f */
        "movaps %xmm3, %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm0, %xmm2\n"
        "cmpnltss %xmm1, %xmm4\n"
        "andps %xmm4, %xmm2\n"
        "andnps %xmm3, %xmm4\n"
        "orps %xmm2, %xmm4\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movaps %xmm4, %xmm2\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm4\n"
        "movl 8(%ebp), %eax\n" /* line 1069 | this */
        "cmpb $0, 0xa8(%eax)\n"
        "jns .Lfa587c_000a5a39\n"
        "movl %eax, %edx\n"
        "mulss 0x2ed5d4, %xmm4\n" /* line 1072 | 255.0f */
        "cvttss2si %xmm4, %eax\n"
        "movb %al, 0x93(%edx)\n"
        /* } scope */
        "popl %ebx\n" /* line 1082 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa587c_000a59fb:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a58e7\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a59fb\n"
        "jmp .Lfa587c_000a58e7\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa587c_000a5a1a:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5951\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5a1a\n"
        "jmp .Lfa587c_000a5951\n"
        ".Lfa587c_000a5a39:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        "movzbl 0x90(%eax), %eax\n" /* line 1077 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movb %al, 0x90(%edx)\n"
        "movzbl 0x91(%edx), %eax\n" /* line 1078 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movb %al, 0x91(%edx)\n"
        "movzbl 0x92(%edx), %eax\n" /* line 1079 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "cvttss2si %xmm4, %eax\n"
        "movb %al, 0x92(%edx)\n"
        "movb $0xff, 0x93(%edx)\n" /* line 1080 */
        /* } scope */
        "popl %ebx\n" /* line 1082 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa587c_000a5a92:\n"
        "movss 0x3c(%eax), %xmm3\n" /* line 1065 */
        "movl %eax, %ecx\n" /* source */
        "addl $0x15c, %ecx\n" /* source */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x15c(%eax), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa587c_000a5b28\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5b10\n"
        /* } scope */
        ".Lfa587c_000a5acf:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 32 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        "jmp .Lfa587c_000a5997\n"
        /* { scope 3 */
        ".Lfa587c_000a5b10:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5acf\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa587c_000a5b10\n"
        "jmp .Lfa587c_000a5acf\n"
        ".Lfa587c_000a5b28:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5acf\n"
        "jmp .Lfa587c_000a5b10\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa587c_000a5b43:\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "leal 8(%esi), %edi\n" /* line 97 | keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a5951\n"
        "jmp .Lfa587c_000a5a1a\n"
        /* } scope */
        /* { scope 3 */
        ".Lfa587c_000a5b61:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa587c_000a58e7\n"
        "jmp .Lfa587c_000a59fb\n"
    );
}

/* line 1749 */
__attribute__((naked))
Bool Cylinder_Update(const Cylinder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1749 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa5b84_000a5ee4\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa5b84_000a5bd5\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa5b84_000a5bd5:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa5b84_000a6179\n"
        "movl 0xc0(%esi), %ebx\n" /* line 207 | key */
        "testl %ebx, %ebx\n" /* key */
        "jne .Lfa5b84_000a5e96\n"
        ".Lfa5b84_000a5bf1:\n"
        "movl $0, -0x44(%ebp)\n" /* or_ */
        ".Lfa5b84_000a5bf8:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "js .Lfa5b84_000a5eee\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a5c3c\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa5b84_000a5c3c:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5c56\n"
        ".Lfa5b84_000a5c4b:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5c4b\n"
        /* } scope */
        ".Lfa5b84_000a5c56:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "jne .Lfa5b84_000a6036\n"
        ".Lfa5b84_000a5ca7:\n"
        "movl 0x88(%esi), %eax\n" /* line 1036 */
        "movl %eax, 0x8c(%esi)\n"
        ".Lfa5b84_000a5cb3:\n"
        "testb $2, 0xaa(%esi)\n" /* line 1658 */
        "je .Lfa5b84_000a61b0\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1659 */
        "movss 0x25c(%esi), %xmm5\n" /* blendFactor */
        "leal 0x26c(%esi), %ebx\n" /* source1 */
        "leal 0x260(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x38(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a5d07\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa5b84_000a5d07:\n"
        "movl -0x38(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5d20\n"
        ".Lfa5b84_000a5d15:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5d15\n"
        /* } scope */
        ".Lfa5b84_000a5d20:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x50(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x50(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x4c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a62db\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x2c(%ebp)\n" /* keySize */
        ".Lfa5b84_000a5d97:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5dad\n"
        ".Lfa5b84_000a5da2:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5da2\n"
        /* } scope */
        ".Lfa5b84_000a5dad:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x50(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1659 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x258(%esi)\n"
        "movl %esi, (%esp)\n" /* line 1766 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1767 | this */
        "calll Particle_UpdateAlpha\n"
        "movl -0x44(%ebp), %edx\n" /* line 1770 | or_ */
        "testl %edx, %edx\n"
        "je .Lfa5b84_000a625f\n"
        ".Lfa5b84_000a5e19:\n"
        "leal 4(%esi), %ebx\n" /* line 1772 | this, source1 */
        "leal 0x7c(%esi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* source1 */
        "movl -0x44(%ebp), %edi\n" /* or_, keySize */
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "movss 0x258(%esi), %xmm1\n" /* line 1773 | this, scale */
        "leal 0x48(%esi), %eax\n" /* this, dir */
        /* { scope 2: keySize, keySize, keySize */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x48(%esi), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* endpos */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ebx), %xmm0\n" /* this */
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%ebx), %xmm1\n" /* this */
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "leal 0x9c(%esi), %eax\n" /* line 1774 | this */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa5b84_000a5e96:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize, keySize */
        "movl 0x3c(%ebx), %ecx\n" /* line 90 | key */
        "testl %ecx, %ecx\n"
        "js .Lfa5b84_000a5ee4\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa5b84_000a62c8\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa5b84_000a62cb\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa5b84_000a5ee4:\n"
        "xorl %eax, %eax\n" /* line 290 */
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa5b84_000a5eee:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a5f33\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa5b84_000a5f33:\n"
        "movl -0x40(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5f4c\n"
        ".Lfa5b84_000a5f41:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5f41\n"
        /* } scope */
        ".Lfa5b84_000a5f4c:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 | key */
        "movl %edx, -0x50(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x4c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a62e3\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x34(%ebp)\n" /* keySize */
        ".Lfa5b84_000a5fc2:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a5fd8\n"
        ".Lfa5b84_000a5fcd:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a5fcd\n"
        /* } scope */
        ".Lfa5b84_000a5fd8:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x50(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "je .Lfa5b84_000a5ca7\n"
        ".Lfa5b84_000a6036:\n"
        "testb $1, 0xaa(%esi)\n" /* line 1029 */
        "je .Lfa5b84_000a62eb\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1030 */
        "movss 0x124(%esi), %xmm5\n" /* blendFactor */
        "leal 0x198(%esi), %ebx\n" /* source1 */
        "leal 0x18c(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x3c(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa5b84_000a639b\n"
        ".Lfa5b84_000a6084:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a6191\n"
        /* } scope */
        ".Lfa5b84_000a6096:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x50(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x50(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x4c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a6393\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x30(%ebp)\n" /* keySize */
        ".Lfa5b84_000a610d:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6123\n"
        ".Lfa5b84_000a6118:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a6118\n"
        /* } scope */
        ".Lfa5b84_000a6123:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x50(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1030 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x8c(%esi)\n"
        "jmp .Lfa5b84_000a5cb3\n"
        ".Lfa5b84_000a6179:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %ebx\n" /* line 207 | key */
        "testl %ebx, %ebx\n" /* key */
        "jne .Lfa5b84_000a5e96\n"
        "jmp .Lfa5b84_000a5bf1\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        ".Lfa5b84_000a6191:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6096\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a6191\n"
        "jmp .Lfa5b84_000a6096\n"
        /* } scope */
        /* } scope */
        ".Lfa5b84_000a61b0:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1661 */
        "leal 0x260(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa5b84_000a61e6\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa5b84_000a61e6:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6200\n"
        ".Lfa5b84_000a61f5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a61f5\n"
        /* } scope */
        ".Lfa5b84_000a6200:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1661 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x258(%esi)\n"
        "movl %esi, (%esp)\n" /* line 1766 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1767 | this */
        "calll Particle_UpdateAlpha\n"
        "movl -0x44(%ebp), %edx\n" /* line 1770 | or_ */
        "testl %edx, %edx\n"
        "jne .Lfa5b84_000a5e19\n"
        ".Lfa5b84_000a625f:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1778 | this, to */
        /* { scope 2: keySize, keySize, keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 8(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x9c(%esi), %edx\n" /* line 1779 | this, result */
        "movss 0x258(%esi), %xmm1\n" /* this, scale */
        "leal 0x48(%esi), %eax\n" /* this, dir */
        /* { scope 2: keySize, keySize, keySize */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x48(%esi), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 0x9c(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 8(%esi), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 0xc(%esi), %xmm1\n"
        "movss %xmm1, 8(%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa5b84_000a62c8:\n"
        "leal 8(%ebx), %edi\n" /* source1, keySize */
        /* { scope 1 */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa5b84_000a62cb:\n"
        "movl %edi, -0x44(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa5b84_000a5bf8\n"
        "jmp .Lfa5b84_000a5ee4\n"
        ".Lfa5b84_000a62db:\n"
        "movl -0x2c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa5b84_000a5d97\n"
        ".Lfa5b84_000a62e3:\n"
        "movl -0x34(%ebp), %edi\n" /* keySize */
        "jmp .Lfa5b84_000a5fc2\n"
        ".Lfa5b84_000a62eb:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1032 */
        "leal 0x18c(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa5b84_000a6387\n"
        ".Lfa5b84_000a6317:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a636f\n"
        /* } scope */
        ".Lfa5b84_000a6326:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x8c(%esi)\n"
        "jmp .Lfa5b84_000a5cb3\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        ".Lfa5b84_000a636f:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa5b84_000a6326\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa5b84_000a636f\n"
        "jmp .Lfa5b84_000a6326\n"
        ".Lfa5b84_000a6387:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa5b84_000a6317\n"
        ".Lfa5b84_000a6393:\n"
        "movl -0x30(%ebp), %edi\n" /* keySize */
        "jmp .Lfa5b84_000a610d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3 */
        ".Lfa5b84_000a639b:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        "jmp .Lfa5b84_000a6084\n"
    );
}

/* line 1619 */
__attribute__((naked))
Bool Tail_Update(const Tail * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1619 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa63aa_000a67d2\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa63aa_000a63fb\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa63aa_000a63fb:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa63aa_000a67dc\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa63aa_000a678c\n"
        ".Lfa63aa_000a6417:\n"
        "movl $0, -0x2c(%ebp)\n" /* or_ */
        ".Lfa63aa_000a641e:\n"
        "leal 0x24c(%esi), %edx\n" /* line 1631 | this, to */
        "leal 4(%esi), %ebx\n" /* this, source1 */
        /* { scope 2: keySize, keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x24c(%esi)\n"
        "movl 8(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 1634 | or_ */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa63aa_000a67d2\n"
        "movl -0x2c(%ebp), %edi\n" /* line 1637 | or_, keySize */
        "testl %edi, %edi\n" /* keySize */
        "je .Lfa63aa_000a67f0\n"
        "leal 0x7c(%esi), %eax\n" /* line 1638 | this */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* source1 */
        "movl -0x2c(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        ".Lfa63aa_000a6474:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "jns .Lfa63aa_000a682a\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x28(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a64c9\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa63aa_000a64c9:\n"
        "movl -0x28(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a64e2\n"
        ".Lfa63aa_000a64d7:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a64d7\n"
        /* } scope */
        ".Lfa63aa_000a64e2:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a69bc\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x20(%ebp)\n" /* keySize */
        ".Lfa63aa_000a6559:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a656f\n"
        ".Lfa63aa_000a6564:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a6564\n"
        /* } scope */
        ".Lfa63aa_000a656f:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        "testb $2, 0xaa(%esi)\n" /* line 1658 | this */
        "je .Lfa63aa_000a68cb\n"
        ".Lfa63aa_000a65cd:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1659 | this */
        "movss 0x25c(%esi), %xmm5\n" /* this, blendFactor */
        "leal 0x26c(%esi), %ebx\n" /* this, source1 */
        "leal 0x260(%esi), %ecx\n" /* this, source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x24(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a6614\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa63aa_000a6614:\n"
        "movl -0x24(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edi, %edx), %eax\n" /* keySize */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a662d\n"
        ".Lfa63aa_000a6622:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a6622\n"
        /* } scope */
        ".Lfa63aa_000a662d:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edi\n" /* line 91 | key, keySize */
        "movl (%edi), %edx\n" /* keySize */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a69b4\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%edi), %eax\n" /* line 97 | keySize */
        "movl %eax, -0x1c(%ebp)\n"
        ".Lfa63aa_000a669e:\n"
        "shll $2, %edx\n" /* line 100 */
        "addl %edx, %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a66b3\n"
        ".Lfa63aa_000a66a8:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a66a8\n"
        /* } scope */
        ".Lfa63aa_000a66b3:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "leal (%edi, %eax, 8), %eax\n" /* keySize */
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1659 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x258(%esi)\n" /* this */
        ".Lfa63aa_000a6701:\n"
        "movl %esi, (%esp)\n" /* line 1645 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1646 | this */
        "calll Particle_UpdateAlpha\n"
        /* { scope 2: keySize, keySize */
        "movl 0x40(%esi), %eax\n" /* line 1110 */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed88, %ebx\n" /* source1 */
        "movl (%ebx), %eax\n" /* source1 */
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetMaterialSubimageCount\n"
        "movl %eax, %ecx\n"
        "cmpl $1, %eax\n" /* line 1112 */
        "je .Lfa63aa_000a69a5\n"
        "movl (%ebx), %eax\n" /* line 1118 | source1 */
        "movl 4(%eax), %eax\n"
        "subl 0xb8(%esi), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x10c(%esi), %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "addl 0x108(%esi), %edx\n"
        "movl %edx, 0x94(%esi)\n"
        "movl 0x110(%esi), %eax\n" /* line 1120 */
        "testl %eax, %eax\n"
        "jne .Lfa63aa_000a6964\n"
        "cmpl %edx, %ecx\n" /* line 1122 */
        "jle .Lfa63aa_000a680a\n"
        /* } scope */
        ".Lfa63aa_000a6770:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1650 | or_ */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Tail_CalcNewEndpoint\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa63aa_000a678c:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 | key */
        "testl %eax, %eax\n"
        "js .Lfa63aa_000a67d2\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa63aa_000a681a\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa63aa_000a681d\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        ".Lfa63aa_000a67d2:\n"
        "xorl %eax, %eax\n" /* line 1652 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa63aa_000a67dc:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa63aa_000a678c\n"
        "jmp .Lfa63aa_000a6417\n"
        ".Lfa63aa_000a67f0:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1640 | this, to */
        /* { scope 2: keySize, keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 8(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lfa63aa_000a6474\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa63aa_000a680a:\n"
        "movl %edx, %eax\n" /* line 1138 */
        "cltd\n"
        "idivl %ecx\n"
        "movl %edx, 0x94(%esi)\n"
        "jmp .Lfa63aa_000a6770\n"
        ".Lfa63aa_000a681a:\n"
        "leal 8(%ebx), %edi\n" /* source1, keySize */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa63aa_000a681d:\n"
        "movl %edi, -0x2c(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa63aa_000a641e\n"
        "jmp .Lfa63aa_000a67d2\n"
        ".Lfa63aa_000a682a:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a6860\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa63aa_000a6860:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a687a\n"
        ".Lfa63aa_000a686f:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a686f\n"
        /* } scope */
        ".Lfa63aa_000a687a:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "testb $2, 0xaa(%esi)\n" /* line 1658 | this */
        "jne .Lfa63aa_000a65cd\n"
        ".Lfa63aa_000a68cb:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1661 | this */
        "leal 0x260(%esi), %ecx\n" /* this, source */
        /* { scope 2: keySize, keySize */
        /* { scope 3 */
        "movl 0x260(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa63aa_000a6901\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa63aa_000a6901:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n" /* key */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa63aa_000a691b\n"
        ".Lfa63aa_000a6910:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa63aa_000a6910\n"
        /* } scope */
        ".Lfa63aa_000a691b:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1661 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x258(%esi)\n" /* this */
        "jmp .Lfa63aa_000a6701\n"
        /* { scope 2: keySize, keySize */
        ".Lfa63aa_000a6964:\n"
        "subl $1, %eax\n" /* line 1125 */
        "jne .Lfa63aa_000a6770\n"
        "movl 0x114(%esi), %eax\n" /* line 1127 */
        "testl %eax, %eax\n"
        "jle .Lfa63aa_000a69c4\n"
        "cmpl %edx, %ecx\n" /* line 1129 */
        "jg .Lfa63aa_000a6770\n"
        "addl $1, %eax\n" /* line 1131 */
        "imull %ecx, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lfa63aa_000a680a\n"
        "movl $0, 0x114(%esi)\n" /* line 1133 */
        "leal -1(%ecx), %eax\n" /* line 1134 */
        "movl %eax, 0x94(%esi)\n"
        "jmp .Lfa63aa_000a6770\n"
        ".Lfa63aa_000a69a5:\n"
        "movl $0, 0x94(%esi)\n" /* line 1114 */
        "jmp .Lfa63aa_000a6770\n"
        ".Lfa63aa_000a69b4:\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lfa63aa_000a669e\n"
        ".Lfa63aa_000a69bc:\n"
        "movl -0x20(%ebp), %edi\n" /* keySize */
        "jmp .Lfa63aa_000a6559\n"
        ".Lfa63aa_000a69c4:\n"
        "cmpl %edx, %ecx\n" /* line 1144 */
        "jg .Lfa63aa_000a6770\n"
        "leal -1(%ecx), %eax\n" /* line 1145 */
        "movl %eax, 0x94(%esi)\n"
        "jmp .Lfa63aa_000a6770\n"
    );
}

/* line 1526 */
__attribute__((naked))
Bool Line_Update(const Line * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1526 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa69da_000a6b78\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa69da_000a6a2b\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa69da_000a6a2b:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa69da_000a6cda\n"
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa69da_000a6b2a\n"
        ".Lfa69da_000a6a47:\n"
        "leal 0x7c(%esi), %ecx\n" /* line 1545 | this, to */
        "leal 4(%esi), %edx\n" /* this, from */
        /* { scope 2: keySize */
        "movl 4(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x9c(%esi), %ecx\n" /* line 1546 | this, to */
        "leal 0x24c(%esi), %edx\n" /* this, from */
        /* { scope 2: keySize */
        "movl 0x24c(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x9c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lfa69da_000a6a83:\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "js .Lfa69da_000a6b82\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa69da_000a6ac7\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 */
        ".Lfa69da_000a6ac7:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa69da_000a6ae1\n"
        ".Lfa69da_000a6ad6:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa69da_000a6ad6\n"
        /* } scope */
        ".Lfa69da_000a6ae1:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "jmp .Lfa69da_000a6cbd\n"
        ".Lfa69da_000a6b2a:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 */
        /* { scope 2: keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 */
        "testl %eax, %eax\n"
        "js .Lfa69da_000a6b78\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n"
        "je .Lfa69da_000a6cf2\n"
        "movl %eax, 4(%ebx)\n" /* line 96 */
        "leal 8(%ebx), %edi\n" /* line 102 | keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa69da_000a6cf5\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 */
        /* } scope */
        ".Lfa69da_000a6b78:\n"
        "xorl %eax, %eax\n" /* line 1555 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1556 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa69da_000a6b82:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize */
        /* { scope 3 */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa69da_000a6bc7\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa69da_000a6bc7:\n"
        "movl -0x20(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa69da_000a6be0\n"
        ".Lfa69da_000a6bd5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa69da_000a6bd5\n"
        /* } scope */
        ".Lfa69da_000a6be0:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %edx\n" /* line 91 */
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, %edi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n"
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x2c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa69da_000a6d34\n"
        "movl $0, 4(%ebx)\n" /* line 96 */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x1c(%ebp)\n" /* keySize */
        ".Lfa69da_000a6c56:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa69da_000a6c6c\n"
        ".Lfa69da_000a6c61:\n"
        "addl $1, 4(%ebx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa69da_000a6c61\n"
        /* } scope */
        ".Lfa69da_000a6c6c:\n"
        "movl 4(%ebx), %eax\n" /* line 126 */
        "movl -0x30(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        ".Lfa69da_000a6cbd:\n"
        "movl %esi, (%esp)\n" /* line 1551 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1552 | this */
        "calll Particle_UpdateAlpha\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1556 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa69da_000a6cda:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "je .Lfa69da_000a6a47\n"
        "jmp .Lfa69da_000a6b2a\n"
        ".Lfa69da_000a6cf2:\n"
        "leal 8(%ebx), %edi\n" /* keySize */
        ".Lfa69da_000a6cf5:\n"
        "testl %edi, %edi\n" /* line 210 | keySize */
        "je .Lfa69da_000a6b78\n"
        "leal 0x7c(%esi), %eax\n" /* line 1540 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "leal 0x9c(%esi), %eax\n" /* line 1541 | this */
        "movl %eax, 8(%esp)\n"
        "leal 0x24c(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        "jmp .Lfa69da_000a6a83\n"
        ".Lfa69da_000a6d34:\n"
        "movl -0x1c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa69da_000a6c56\n"
    );
}

/* line 1418 */
__attribute__((naked))
Bool Cloud_Update(const Cloud * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1418 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%esi), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa6d3c_000a7265\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa6d3c_000a6d8d\n"
        "movss %xmm1, 0x3c(%esi)\n" /* line 242 */
        ".Lfa6d3c_000a6d8d:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%esi), %xmm0\n"
        "ja .Lfa6d3c_000a74f3\n"
        "movl 0xc0(%esi), %edx\n" /* line 207 */
        "testl %edx, %edx\n"
        "jne .Lfa6d3c_000a7217\n"
        ".Lfa6d3c_000a6da9:\n"
        "movl $0, -0x60(%ebp)\n" /* or_ */
        ".Lfa6d3c_000a6db0:\n"
        "leal 4(%esi), %eax\n" /* line 1432 | this */
        "movl %eax, -0x64(%ebp)\n"
        "movss 4(%esi), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "leal 8(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movss 8(%esi), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "leal 0xc(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "movss 0xc(%esi), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movl -0x60(%ebp), %eax\n" /* line 1435 | or_ */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa6d3c_000a7265\n"
        "cmpw $0, 0xa8(%esi)\n" /* line 1018 */
        "js .Lfa6d3c_000a726f\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1021 */
        "leal 0x174(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a6e3b\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa6d3c_000a6e3b:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n" /* key */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a6e55\n"
        ".Lfa6d3c_000a6e4a:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a6e4a\n"
        /* } scope */
        ".Lfa6d3c_000a6e55:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "jne .Lfa6d3c_000a73ba\n"
        ".Lfa6d3c_000a6ea6:\n"
        "movl 0x88(%esi), %eax\n" /* line 1036 */
        "movl %eax, 0x8c(%esi)\n"
        ".Lfa6d3c_000a6eb2:\n"
        "cmpb $0, 0x25c(%esi)\n" /* line 1408 */
        "je .Lfa6d3c_000a6ff3\n"
        "testb $2, 0xaa(%esi)\n" /* line 1411 */
        "je .Lfa6d3c_000a761d\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1412 */
        "movss 0x260(%esi), %xmm5\n" /* blendFactor */
        "leal 0x270(%esi), %ebx\n" /* source1 */
        "leal 0x264(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x264(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x4c(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a775d\n"
        ".Lfa6d3c_000a6f0d:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a753d\n"
        /* } scope */
        ".Lfa6d3c_000a6f1f:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a77ab\n"
        "movl -0x30(%ebp), %edi\n" /* keySize */
        ".Lfa6d3c_000a6f8c:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a6fa2\n"
        ".Lfa6d3c_000a6f97:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a6f97\n"
        /* } scope */
        ".Lfa6d3c_000a6fa2:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1412 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x258(%esi)\n"
        ".Lfa6d3c_000a6ff3:\n"
        "movl %esi, (%esp)\n" /* line 1442 | this */
        "calll Particle_UpdateRGB\n"
        "movl %esi, (%esp)\n" /* line 1443 | this */
        "calll Particle_UpdateAlpha\n"
        /* { scope 2: keySize, keySize, keySize */
        "testb $4, 0xaa(%esi)\n" /* line 1089 */
        "je .Lfa6d3c_000a755c\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1090 */
        "movss 0x128(%esi), %xmm5\n" /* blendFactor */
        "leal 0x1b0(%esi), %ebx\n" /* source1 */
        "leal 0x1a4(%esi), %ecx\n" /* source0 */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x48(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a7057\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa6d3c_000a7057:\n"
        "movl -0x48(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a7070\n"
        ".Lfa6d3c_000a7065:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7065\n"
        /* } scope */
        ".Lfa6d3c_000a7070:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a7615\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x2c(%ebp)\n" /* keySize */
        ".Lfa6d3c_000a70e7:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a70fd\n"
        ".Lfa6d3c_000a70f2:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a70f2\n"
        /* } scope */
        ".Lfa6d3c_000a70fd:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 55 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        /* } scope */
        ".Lfa6d3c_000a7146:\n"
        "movl 0x195ed88, %eax\n" /* line 1094 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "mulss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "mulss %xmm3, %xmm0\n"
        "addss 0x44(%esi), %xmm0\n"
        "movss %xmm0, 0x44(%esi)\n"
        /* } scope */
        "leal -0x28(%ebp), %ebx\n" /* line 1447 | quat, source1 */
        "movl %ebx, 8(%esp)\n" /* source1 */
        "leal 0x24c(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleAxisToQuat\n"
        "leal 0x48(%esi), %eax\n" /* line 1448 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* source1 */
        "calll QuatToAxis\n"
        "movl 0x88(%esi), %eax\n" /* line 1450 | this */
        "movl %eax, 0x98(%esi)\n" /* this */
        "movl 0x8c(%esi), %eax\n" /* line 1451 | this */
        "movl %eax, 0x88(%esi)\n" /* this */
        "cmpb $0, 0x25c(%esi)\n" /* line 1452 | this */
        "je .Lfa6d3c_000a71b9\n"
        "movl 0x258(%esi), %eax\n" /* this */
        ".Lfa6d3c_000a71b9:\n"
        "movl %eax, 0x8c(%esi)\n" /* this */
        "movl -0x60(%ebp), %eax\n" /* line 1454 | or_ */
        "testl %eax, %eax\n"
        "je .Lfa6d3c_000a75ed\n"
        "leal 0x7c(%esi), %eax\n" /* line 1455 | this */
        "movl %eax, 8(%esp)\n"
        "movl -0x64(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x60(%ebp), %edi\n" /* or_, keySize */
        "movl %edi, (%esp)\n" /* keySize */
        "calll OrientationPosToWorldPos\n"
        ".Lfa6d3c_000a71e3:\n"
        "leal 0x9c(%esi), %eax\n" /* line 1458 | this, to */
        /* { scope 2: keySize, keySize, keySize */
        "movss -0x3c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x9c(%esi)\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa6d3c_000a7217:\n"
        "movl 0xc0(%esi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize, keySize */
        "movl 0x3c(%ebx), %eax\n" /* line 90 | key */
        "testl %eax, %eax\n"
        "js .Lfa6d3c_000a7265\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa6d3c_000a752a\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %edi\n" /* line 102 | key, keySize */
        "movl %edi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa6d3c_000a752d\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa6d3c_000a7265:\n"
        "xorl %eax, %eax\n" /* line 1460 */
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa6d3c_000a726f:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1019 */
        "movss 0x120(%esi), %xmm5\n" /* blendFactor */
        "leal 0x180(%esi), %ebx\n" /* source1 */
        "leal 0x174(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x54(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a72b6\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        ".Lfa6d3c_000a72b6:\n"
        "movl -0x54(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a72cf\n"
        ".Lfa6d3c_000a72c4:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a72c4\n"
        /* } scope */
        ".Lfa6d3c_000a72cf:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a760d\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x38(%ebp)\n" /* keySize */
        ".Lfa6d3c_000a7346:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a735c\n"
        ".Lfa6d3c_000a7351:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7351\n"
        /* } scope */
        ".Lfa6d3c_000a735c:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%esi)\n"
        "cmpb $0, 0x104(%esi)\n" /* line 1027 */
        "je .Lfa6d3c_000a6ea6\n"
        ".Lfa6d3c_000a73ba:\n"
        "testb $1, 0xaa(%esi)\n" /* line 1029 */
        "je .Lfa6d3c_000a76bd\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1030 */
        "movss 0x124(%esi), %xmm5\n" /* blendFactor */
        "leal 0x198(%esi), %ebx\n" /* source1 */
        "leal 0x18c(%esi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, -0x50(%ebp)\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a777e\n"
        ".Lfa6d3c_000a7408:\n"
        "movl -0x50(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a750b\n"
        /* } scope */
        ".Lfa6d3c_000a741a:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x70(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x70(%ebp), %edi\n" /* keySize */
        "leal (%edi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x6c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a776c\n"
        "movl -0x34(%ebp), %edi\n" /* keySize */
        ".Lfa6d3c_000a7487:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %edi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a749d\n"
        ".Lfa6d3c_000a7492:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7492\n"
        /* } scope */
        ".Lfa6d3c_000a749d:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1030 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x8c(%esi)\n"
        "jmp .Lfa6d3c_000a6eb2\n"
        ".Lfa6d3c_000a74f3:\n"
        "movss %xmm0, 0x3c(%esi)\n" /* line 244 */
        "movl 0xc0(%esi), %edx\n" /* line 207 */
        "testl %edx, %edx\n"
        "jne .Lfa6d3c_000a7217\n"
        "jmp .Lfa6d3c_000a6da9\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a750b:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a741a\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a750b\n"
        "jmp .Lfa6d3c_000a741a\n"
        ".Lfa6d3c_000a752a:\n"
        "leal 8(%ebx), %edi\n" /* key, keySize */
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa6d3c_000a752d:\n"
        "movl %edi, -0x60(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %edi, %edi\n" /* line 210 | keySize */
        "jne .Lfa6d3c_000a6db0\n"
        "jmp .Lfa6d3c_000a7265\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a753d:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a6f1f\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a753d\n"
        "jmp .Lfa6d3c_000a6f1f\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        ".Lfa6d3c_000a755c:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1092 */
        "leal 0x1a4(%esi), %ecx\n" /* source */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa6d3c_000a7592\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa6d3c_000a7592:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a75ac\n"
        ".Lfa6d3c_000a75a1:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a75a1\n"
        /* } scope */
        ".Lfa6d3c_000a75ac:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 32 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        "jmp .Lfa6d3c_000a7146\n"
        /* } scope */
        /* } scope */
        ".Lfa6d3c_000a75ed:\n"
        "leal 0x7c(%esi), %edx\n" /* line 1457 | this, to */
        /* { scope 2: keySize, keySize, keySize */
        "movl -0x64(%ebp), %ecx\n" /* line 199 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x7c(%esi)\n"
        "movl -0x5c(%ebp), %edi\n" /* line 200 | keySize */
        "movl (%edi), %eax\n" /* keySize */
        "movl %eax, 4(%edx)\n"
        "movl -0x58(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "jmp .Lfa6d3c_000a71e3\n"
        ".Lfa6d3c_000a760d:\n"
        "movl -0x38(%ebp), %edi\n" /* keySize */
        "jmp .Lfa6d3c_000a7346\n"
        ".Lfa6d3c_000a7615:\n"
        "movl -0x2c(%ebp), %edi\n" /* keySize */
        "jmp .Lfa6d3c_000a70e7\n"
        /* } scope */
        ".Lfa6d3c_000a761d:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1414 */
        "leal 0x264(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x264(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a779c\n"
        ".Lfa6d3c_000a764d:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a76a5\n"
        /* } scope */
        ".Lfa6d3c_000a765c:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1414 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x258(%esi)\n"
        "jmp .Lfa6d3c_000a6ff3\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a76a5:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a765c\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a76a5\n"
        "jmp .Lfa6d3c_000a765c\n"
        /* } scope */
        /* } scope */
        ".Lfa6d3c_000a76bd:\n"
        "movss 0x3c(%esi), %xmm3\n" /* line 1032 */
        "leal 0x18c(%esi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%esi), %edx\n" /* line 91 */
        "movl (%edx), %edi\n" /* keySize */
        "addl $1, %edi\n" /* keySize */
        "movl %edi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa6d3c_000a778d\n"
        ".Lfa6d3c_000a76ed:\n"
        "leal (, %edi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7745\n"
        /* } scope */
        ".Lfa6d3c_000a76fc:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x8c(%esi)\n"
        "jmp .Lfa6d3c_000a6eb2\n"
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a7745:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa6d3c_000a76fc\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa6d3c_000a7745\n"
        "jmp .Lfa6d3c_000a76fc\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a775d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        "jmp .Lfa6d3c_000a6f0d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a776c:\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x34(%ebp)\n" /* keySize */
        "jmp .Lfa6d3c_000a7487\n"
        /* } scope */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a777e:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %edi\n" /* line 97 | keySize */
        "jmp .Lfa6d3c_000a7408\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a778d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa6d3c_000a76ed\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a779c:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa6d3c_000a764d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa6d3c_000a77ab:\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %edi\n" /* line 97 | keySize */
        "movl %edi, -0x30(%ebp)\n" /* keySize */
        "jmp .Lfa6d3c_000a6f8c\n"
    );
}

/* line 1282 */
__attribute__((naked))
Bool OrientedParticle_Update(const OrientedParticle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1282 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%edi), %edx\n" /* line 232 */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lfa77be_000a7b6e\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%edi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%edi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa77be_000a780f\n"
        "movss %xmm1, 0x3c(%edi)\n" /* line 242 */
        ".Lfa77be_000a780f:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%edi), %xmm0\n"
        "ja .Lfa77be_000a7dfc\n"
        "movl 0xc0(%edi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa77be_000a7b20\n"
        ".Lfa77be_000a782b:\n"
        "movl $0, -0x34(%ebp)\n" /* or_ */
        "movl -0x34(%ebp), %eax\n" /* or_ */
        ".Lfa77be_000a7835:\n"
        "movl %eax, 4(%esp)\n" /* line 1294 */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je .Lfa77be_000a7b6e\n"
        "cmpw $0, 0xa8(%edi)\n" /* line 1018 */
        "js .Lfa77be_000a7b78\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1021 */
        "leal 0x174(%edi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a788d\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa77be_000a788d:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a78a7\n"
        ".Lfa77be_000a789c:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a789c\n"
        /* } scope */
        ".Lfa77be_000a78a7:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1021 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x88(%edi)\n"
        "cmpb $0, 0x104(%edi)\n" /* line 1027 */
        "jne .Lfa77be_000a7cc3\n"
        ".Lfa77be_000a78f8:\n"
        "movl 0x88(%edi), %eax\n" /* line 1036 */
        "movl %eax, 0x8c(%edi)\n"
        ".Lfa77be_000a7904:\n"
        "movl %edi, (%esp)\n" /* line 1300 | this */
        "calll Particle_UpdateRGB\n"
        "movl %edi, (%esp)\n" /* line 1301 | this */
        "calll Particle_UpdateAlpha\n"
        /* { scope 2: keySize, keySize */
        "testb $4, 0xaa(%edi)\n" /* line 1089 */
        "je .Lfa77be_000a7e58\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1090 */
        "movss 0x128(%edi), %xmm5\n" /* blendFactor */
        "leal 0x1b0(%edi), %ebx\n" /* source1 */
        "leal 0x1a4(%edi), %ecx\n" /* source0 */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, -0x28(%ebp)\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7968\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        ".Lfa77be_000a7968:\n"
        "movl -0x28(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7981\n"
        ".Lfa77be_000a7976:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7976\n"
        /* } scope */
        ".Lfa77be_000a7981:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %esi\n" /* keySize */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7f7d\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x1c(%ebp)\n" /* keySize */
        ".Lfa77be_000a79f8:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7a0e\n"
        ".Lfa77be_000a7a03:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7a03\n"
        /* } scope */
        ".Lfa77be_000a7a0e:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 55 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        /* } scope */
        ".Lfa77be_000a7a57:\n"
        "movl 0x195ed88, %ebx\n" /* line 1094 | source1 */
        "movl (%ebx), %eax\n" /* source1 */
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "mulss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "mulss %xmm0, %xmm3\n"
        "addss 0x44(%edi), %xmm3\n"
        "movss %xmm3, 0x44(%edi)\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        "movl 0x40(%edi), %eax\n" /* line 1110 */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* source1 */
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetMaterialSubimageCount\n"
        "movl %eax, %ecx\n"
        "cmpl $1, %eax\n" /* line 1112 */
        "je .Lfa77be_000a7f6e\n"
        "movl (%ebx), %eax\n" /* line 1118 | source1 */
        "movl 4(%eax), %eax\n"
        "subl 0xb8(%edi), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x10c(%edi), %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "addl 0x108(%edi), %edx\n"
        "movl %edx, 0x94(%edi)\n"
        "movl 0x110(%edi), %eax\n" /* line 1120 */
        "testl %eax, %eax\n"
        "jne .Lfa77be_000a7ee9\n"
        "cmpl %edx, %ecx\n" /* line 1122 */
        "jle .Lfa77be_000a7e48\n"
        /* } scope */
        ".Lfa77be_000a7ad3:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 1306 | or_ */
        "testl %ecx, %ecx\n"
        "je .Lfa77be_000a7f2e\n"
        "leal 0x7c(%edi), %eax\n" /* line 1308 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n" /* or_ */
        "movl %edx, (%esp)\n"
        "calll OrientationPosToWorldPos\n"
        "leal 0x48(%edi), %eax\n" /* line 1309 | this */
        "movl %eax, 8(%esp)\n"
        "leal 0x24c(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %esi\n" /* or_, keySize */
        "movl %esi, (%esp)\n" /* keySize */
        "calll OrientationDirToWorldDir\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa77be_000a7b20:\n"
        "movl 0xc0(%edi), %ebx\n" /* line 101 | key */
        /* { scope 2: keySize, keySize */
        "movl 0x3c(%ebx), %esi\n" /* line 90 | key, keySize */
        "testl %esi, %esi\n" /* keySize */
        "js .Lfa77be_000a7b6e\n"
        "movl 0x195ee78, %eax\n" /* line 94 */
        "movl (%eax), %eax\n"
        "movl 0x864c(%eax), %eax\n"
        "cmpl %eax, 4(%ebx)\n" /* key */
        "je .Lfa77be_000a7e33\n"
        "movl %eax, 4(%ebx)\n" /* line 96 | key */
        "leal 8(%ebx), %esi\n" /* line 102 | key, keySize */
        "movl %esi, 4(%esp)\n" /* keySize */
        "leal 0x3c(%ebx), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lfa77be_000a7e36\n"
        "movl $0xffffffff, 0x3c(%ebx)\n" /* line 105 | key */
        "movl $0xffffffff, 0x40(%ebx)\n" /* line 106 | key */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7b6e:\n"
        "xorl %eax, %eax\n" /* line 201 */
        /* } scope */
        /* } scope */
        ".Lfa77be_000a7b70:\n"
        "addl $0x4c, %esp\n" /* line 1318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa77be_000a7b78:\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1019 */
        "movss 0x120(%edi), %xmm5\n" /* blendFactor */
        "leal 0x180(%edi), %ebx\n" /* source1 */
        "leal 0x174(%edi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, -0x30(%ebp)\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7bbf\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        ".Lfa77be_000a7bbf:\n"
        "movl -0x30(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7bd8\n"
        ".Lfa77be_000a7bcd:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7bcd\n"
        /* } scope */
        ".Lfa77be_000a7bd8:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %esi\n" /* keySize */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a8025\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x24(%ebp)\n" /* keySize */
        ".Lfa77be_000a7c4f:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7c65\n"
        ".Lfa77be_000a7c5a:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7c5a\n"
        /* } scope */
        ".Lfa77be_000a7c65:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%edi)\n"
        "cmpb $0, 0x104(%edi)\n" /* line 1027 */
        "je .Lfa77be_000a78f8\n"
        ".Lfa77be_000a7cc3:\n"
        "testb $1, 0xaa(%edi)\n" /* line 1029 */
        "je .Lfa77be_000a7f85\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1030 */
        "movss 0x124(%edi), %xmm5\n" /* blendFactor */
        "leal 0x198(%edi), %ebx\n" /* source1 */
        "leal 0x18c(%edi), %ecx\n" /* source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, -0x2c(%ebp)\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa77be_000a802d\n"
        ".Lfa77be_000a7d11:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7e14\n"
        /* } scope */
        ".Lfa77be_000a7d23:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %eax\n" /* line 91 | key */
        "movl %eax, -0x40(%ebp)\n"
        "movl (%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "movl -0x40(%ebp), %esi\n" /* keySize */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa77be_000a804b\n"
        "movl -0x20(%ebp), %esi\n" /* keySize */
        ".Lfa77be_000a7d90:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7da6\n"
        ".Lfa77be_000a7d9b:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7d9b\n"
        /* } scope */
        ".Lfa77be_000a7da6:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1030 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x8c(%edi)\n"
        "jmp .Lfa77be_000a7904\n"
        ".Lfa77be_000a7dfc:\n"
        "movss %xmm0, 0x3c(%edi)\n" /* line 244 */
        "movl 0xc0(%edi), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "jne .Lfa77be_000a7b20\n"
        "jmp .Lfa77be_000a782b\n"
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a7e14:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7d23\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7e14\n"
        "jmp .Lfa77be_000a7d23\n"
        ".Lfa77be_000a7e33:\n"
        "leal 8(%ebx), %esi\n" /* key, keySize */
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7e36:\n"
        "movl %esi, -0x34(%ebp)\n" /* line 111 | keySize, or_ */
        /* } scope */
        "testl %esi, %esi\n" /* line 210 | keySize */
        "je .Lfa77be_000a7b6e\n"
        "movl %esi, %eax\n" /* keySize */
        "jmp .Lfa77be_000a7835\n"
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7e48:\n"
        "movl %edx, %eax\n" /* line 1138 */
        "cltd\n"
        "idivl %ecx\n"
        "movl %edx, 0x94(%edi)\n"
        "jmp .Lfa77be_000a7ad3\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7e58:\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1092 */
        "leal 0x1a4(%edi), %ecx\n" /* source */
        /* { scope 3: keySize */
        /* { scope 4 */
        "movl 0x1a4(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa77be_000a7e8e\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa77be_000a7e8e:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7ea8\n"
        ".Lfa77be_000a7e9d:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a7e9d\n"
        /* } scope */
        ".Lfa77be_000a7ea8:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 32 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss 8(%ecx), %xmm3\n"
        "jmp .Lfa77be_000a7a57\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7ee9:\n"
        "subl $1, %eax\n" /* line 1125 */
        "jne .Lfa77be_000a7ad3\n"
        "movl 0x114(%edi), %eax\n" /* line 1127 */
        "testl %eax, %eax\n"
        "jle .Lfa77be_000a805d\n"
        "cmpl %edx, %ecx\n" /* line 1129 */
        "jg .Lfa77be_000a7ad3\n"
        "addl $1, %eax\n" /* line 1131 */
        "imull %ecx, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lfa77be_000a7e48\n"
        "movl $0, 0x114(%edi)\n" /* line 1133 */
        "leal -1(%ecx), %eax\n" /* line 1134 */
        "movl %eax, 0x94(%edi)\n"
        "jmp .Lfa77be_000a7ad3\n"
        /* } scope */
        ".Lfa77be_000a7f2e:\n"
        "leal 0x7c(%edi), %ecx\n" /* line 1313 | this, to */
        "leal 4(%edi), %edx\n" /* this, from */
        /* { scope 2: keySize, keySize */
        "movl 4(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x7c(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x48(%edi), %ecx\n" /* line 1314 | this, to */
        "leal 0x24c(%edi), %edx\n" /* this, from */
        /* { scope 2: keySize, keySize */
        "movl 0x24c(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x48(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lfa77be_000a7b70\n"
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a7f6e:\n"
        "movl $0, 0x94(%edi)\n" /* line 1114 */
        "jmp .Lfa77be_000a7ad3\n"
        ".Lfa77be_000a7f7d:\n"
        "movl -0x1c(%ebp), %esi\n" /* keySize */
        "jmp .Lfa77be_000a79f8\n"
        /* } scope */
        ".Lfa77be_000a7f85:\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1032 */
        "leal 0x18c(%edi), %ecx\n" /* source */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%edi), %edx\n" /* line 91 */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lfa77be_000a803c\n"
        ".Lfa77be_000a7fb5:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a800d\n"
        /* } scope */
        ".Lfa77be_000a7fc4:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x8c(%edi)\n"
        "jmp .Lfa77be_000a7904\n"
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a800d:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa77be_000a7fc4\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa77be_000a800d\n"
        "jmp .Lfa77be_000a7fc4\n"
        ".Lfa77be_000a8025:\n"
        "movl -0x24(%ebp), %esi\n" /* keySize */
        "jmp .Lfa77be_000a7c4f\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a802d:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        "jmp .Lfa77be_000a7d11\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a803c:\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        "jmp .Lfa77be_000a7fb5\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        ".Lfa77be_000a804b:\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x20(%ebp)\n" /* keySize */
        "jmp .Lfa77be_000a7d90\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keySize, keySize */
        ".Lfa77be_000a805d:\n"
        "cmpl %edx, %ecx\n" /* line 1144 */
        "jg .Lfa77be_000a7ad3\n"
        "leal -1(%ecx), %eax\n" /* line 1145 */
        "movl %eax, 0x94(%edi)\n"
        "jmp .Lfa77be_000a7ad3\n"
    );
}

/* line 410 */
__attribute__((naked))
Bool Particle_Update(const Particle * _this, const Particle * _this_1, const Cloud * _this_2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 410 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        "movl 0xb8(%edi), %edx\n" /* line 232 | keySize */
        "movl 0x195ed88, %eax\n"
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg 0xa8369\n"
        "subl %edx, %eax\n" /* line 239 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0xbc(%edi), %eax\n" /* keySize */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x3c(%edi)\n" /* keySize */
        "movss 0x2ed5d0, %xmm1\n" /* line 241 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfa8074_000a80c5\n"
        "movss %xmm1, 0x3c(%edi)\n" /* line 242 | keySize */
        ".Lfa8074_000a80c5:\n"
        "pxor %xmm0, %xmm0\n" /* line 243 */
        "ucomiss 0x3c(%edi), %xmm0\n" /* keySize */
        "ja 0xa8373\n"
        "movl 0xc0(%edi), %eax\n" /* line 207 | keySize */
        "testl %eax, %eax\n"
        "jne 0xa8323\n"
        "xorl %ebx, %ebx\n" /* key */
        "movl %ebx, 4(%esp)\n" /* line 422 | or_ */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_UpdateOrigin\n"
        "testb %al, %al\n"
        "je 0xa8369\n"
        "testl %ebx, %ebx\n" /* line 425 | or_ */
        "je 0xa8387\n"
        "leal 0x7c(%edi), %eax\n" /* line 426 | this */
        "movl %eax, 8(%esp)\n"
        "leal 4(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* or_ */
        "calll OrientationPosToWorldPos\n"
        "cmpw $0, 0xa8(%edi)\n" /* line 1018 | this */
        "jns 0xa83c0\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1019 | this */
        "movss 0x120(%edi), %xmm5\n" /* this, blendFactor */
        "leal 0x180(%edi), %ebx\n" /* this, source1 */
        "leal 0x174(%edi), %ecx\n" /* this, source0 */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x174(%edi), %edx\n" /* line 91 | keySize */
        "movl (%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* keySize */
        "imull 4(%ecx), %eax\n" /* line 92 */
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %esi\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa8074_000a8168\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %esi\n" /* line 97 | keySize */
        ".Lfa8074_000a8168:\n"
        "movl -0x30(%ebp), %edx\n" /* line 100 | keySize */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa8074_000a8181\n"
        ".Lfa8074_000a8176:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa8074_000a8176\n"
        /* } scope */
        ".Lfa8074_000a8181:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 3: keySize */
        "movl (%ebx), %edx\n" /* line 91 | key */
        "movl %edx, -0x40(%ebp)\n"
        "movl %edx, %esi\n" /* keySize */
        "movl (%edx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull 4(%ebx), %eax\n" /* key */
        "leal (%esi, %eax, 4), %eax\n" /* keySize */
        "movl %eax, -0x3c(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe 0xa8521\n"
        "movl $0, 4(%ebx)\n" /* line 96 | key */
        "addl $8, %esi\n" /* line 97 | keySize */
        "movl %esi, -0x24(%ebp)\n" /* keySize */
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %esi), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa8074_000a820d\n"
        ".Lfa8074_000a8202:\n"
        "addl $1, 4(%ebx)\n" /* line 102 | key */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa8074_000a8202\n"
        /* } scope */
        ".Lfa8074_000a820d:\n"
        "movl 4(%ebx), %eax\n" /* line 126 | key */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1019 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "mulss %xmm1, %xmm5\n" /* blendFactor */
        "addss %xmm5, %xmm4\n" /* blendFactor */
        "mulss 8(%ecx), %xmm4\n"
        "movss %xmm4, 0x88(%edi)\n" /* this */
        "movaps %xmm4, %xmm0\n"
        "pxor %xmm6, %xmm6\n" /* line 433 */
        "ucomiss %xmm6, %xmm0\n"
        "jp .Lfa8074_000a8270\n"
        "je 0xa83a4\n"
        ".Lfa8074_000a8270:\n"
        "cmpb $0, 0x104(%edi)\n" /* line 1027 | this */
        "je 0xa845c\n"
        "testb $1, 0xaa(%edi)\n" /* line 1029 | this */
        "jne 0xa8529\n"
        "movss 0x3c(%edi), %xmm3\n" /* line 1032 | this */
        "leal 0x18c(%edi), %ecx\n" /* this, source */
        /* { scope 2: keySize, keySize */
        /* { scope 3: keySize */
        "movl 0x18c(%edi), %edx\n" /* line 91 | keySize */
        "movl (%edx), %esi\n" /* keySize */
        "addl $1, %esi\n" /* keySize */
        "movl %esi, %eax\n" /* line 92 | keySize */
        "imull 4(%ecx), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* key */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfa8074_000a82c0\n"
        "movl $0, 4(%ecx)\n" /* line 96 */
        "leal 8(%edx), %ebx\n" /* line 97 | key */
        ".Lfa8074_000a82c0:\n"
        "leal (, %esi, 4), %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lfa8074_000a82da\n"
        ".Lfa8074_000a82cf:\n"
        "addl $1, 4(%ecx)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lfa8074_000a82cf\n"
        /* } scope */
        ".Lfa8074_000a82da:\n"
        "movl 4(%ecx), %eax\n" /* line 126 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 3: keySize */
        /* { scope 4 */
        "movss 8(%eax), %xmm2\n" /* line 49 */
        "movss 4(%edx), %xmm1\n" /* line 51 */
        /* } scope */
        /* } scope */
        /* } scope */
        "subss %xmm2, %xmm3\n" /* line 1032 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
    );
}

/* line 285 */
__attribute__((naked))
void Effect_Archive(const Effect * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "leal 4(%edi), %esi\n" /* line 289 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa88b2_000a8a83\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8ae4\n"
        /* { scope 1: f */
        ".Lfa88b2_000a88ec:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0xb8(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8b0e\n"
        /* { scope 1: f */
        ".Lfa88b2_000a8916:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0xbc(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8b38\n"
        /* { scope 1: f */
        ".Lfa88b2_000a8940:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0xa8(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8b62\n"
        /* { scope 1: f */
        ".Lfa88b2_000a896a:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x10(%edi)\n"
        "leal 0x14(%edi), %esi\n" /* line 294 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa88b2_000a8b8c\n"
        ".Lfa88b2_000a8994:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x20(%edi), %esi\n" /* line 295 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa88b2_000a8bf0\n"
        ".Lfa88b2_000a89b5:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        ".Lfa88b2_000a89c9:\n"
        "leal 0x2c(%edi), %eax\n" /* line 296 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "leal 0x30(%edi), %eax\n" /* line 297 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "leal 0x40(%edi), %esi\n" /* line 300 | this, v */
        "movl %esi, 4(%esp)\n" /* v */
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveFxGfxEntity\n"
        "leal 0x34(%edi), %eax\n" /* line 305 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa88b2_000a8c4c\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x38(%edi)\n"
        ".Lfa88b2_000a8a2c:\n"
        "movl %esi, 4(%esp)\n" /* line 309 | v */
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveMaterial\n"
        "leal 0xb4(%edi), %eax\n" /* line 310 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveModel\n"
        "movl %ebx, 4(%esp)\n" /* line 312 | arch */
        "leal 0xc0(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxBoltFramePtr_Archive\n"
        "cmpb $0, 4(%ebx)\n" /* line 314 | arch */
        "je .Lfa88b2_000a8a7b\n"
        "leal 0x7c(%edi), %eax\n" /* line 316 | this */
        "movl %eax, (%esp)\n"
        "calll FX_GetCluster\n"
        "movl %eax, 0xac(%edi)\n" /* this */
        "movl %edi, (%esp)\n" /* line 317 | this */
        "calll FX_SetSortGroup\n"
        ".Lfa88b2_000a8a7b:\n"
        "addl $0x2c, %esp\n" /* line 319 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa88b2_000a8a83:\n"
        "movl 4(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a88ec\n"
        ".Lfa88b2_000a8ae4:\n"
        "movl 0xb8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a8916\n"
        ".Lfa88b2_000a8b0e:\n"
        "movl 0xbc(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a8940\n"
        ".Lfa88b2_000a8b38:\n"
        "movl 0xa8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa88b2_000a896a\n"
        ".Lfa88b2_000a8b62:\n"
        "movl 0x10(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "leal 0x14(%edi), %esi\n" /* line 294 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa88b2_000a8994\n"
        ".Lfa88b2_000a8b8c:\n"
        "movl 0x14(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x20(%edi), %esi\n" /* line 295 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa88b2_000a89b5\n"
        ".Lfa88b2_000a8bf0:\n"
        "movl 0x20(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa88b2_000a89c9\n"
        /* } scope */
        /* } scope */
        ".Lfa88b2_000a8c4c:\n"
        "movl 0x38(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa88b2_000a8a2c\n"
    );
}

/* line 2220 */
__attribute__((naked))
void Light_Archive(const Light * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "movl %ebx, 4(%esp)\n" /* line 2224 | arch */
        "movl %esi, (%esp)\n" /* this */
        "calll Effect_Archive\n"
        "leal 0xcc(%esi), %eax\n" /* line 2226 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0xd8(%esi), %eax\n" /* line 2227 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0xe4(%esi), %eax\n" /* line 2228 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0xf0(%esi), %eax\n" /* line 2229 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8c6e_000a8d22\n"
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %edi\n" /* f */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0xc4(%esi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8c6e_000a8d48\n"
        /* { scope 1 */
        ".Lfa8c6e_000a8cfd:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0xc8(%esi)\n"
        "addl $0x2c, %esp\n" /* line 2233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa8c6e_000a8d22:\n"
        "movl 0xc4(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %edi\n" /* f */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa8c6e_000a8cfd\n"
        ".Lfa8c6e_000a8d48:\n"
        "movl 0xc8(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2311 */

void Flash_Archive(const Flash * _this, FxArchive *arch)
{
    Light_Archive((const Light *)_this, arch);
}

/* line 1166 */
__attribute__((naked))
void Particle_Archive(const Particle * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1166 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "movl %ebx, 4(%esp)\n" /* line 1170 | arch */
        "movl %esi, (%esp)\n" /* this */
        "calll Effect_Archive\n"
        "leal 0xc4(%esi), %edi\n" /* line 1172 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a91ce\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0xd0(%esi), %edi\n" /* line 1174 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a9238\n"
        ".Lfa8d78_000a8dc7:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0xdc(%esi), %edi\n" /* line 1175 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a92a2\n"
        ".Lfa8d78_000a8deb:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0xe8(%esi), %edi\n" /* line 1176 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a930c\n"
        ".Lfa8d78_000a8e0f:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9370\n"
        /* { scope 1: f */
        ".Lfa8d78_000a8e2d:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x100(%esi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 164 */
        "je .Lfa8d78_000a939a\n"
        /* { scope 1: f */
        ".Lfa8d78_000a8e57:\n"
        "movl $1, 8(%esp)\n" /* line 84 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movzbl -0x1c(%ebp), %eax\n" /* line 165 | f */
        "movb %al, 0x104(%esi)\n"
        ".Lfa8d78_000a8e78:\n"
        "leal 0x144(%esi), %eax\n" /* line 1186 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x150(%esi), %eax\n" /* line 1187 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x15c(%esi), %eax\n" /* line 1188 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x168(%esi), %eax\n" /* line 1189 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x174(%esi), %eax\n" /* line 1190 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x180(%esi), %eax\n" /* line 1191 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x18c(%esi), %eax\n" /* line 1192 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x198(%esi), %eax\n" /* line 1193 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1a4(%esi), %eax\n" /* line 1194 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1b0(%esi), %eax\n" /* line 1195 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1bc(%esi), %eax\n" /* line 1197 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1c8(%esi), %eax\n" /* line 1198 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1d4(%esi), %eax\n" /* line 1199 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1e0(%esi), %eax\n" /* line 1200 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1ec(%esi), %eax\n" /* line 1201 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x1f8(%esi), %eax\n" /* line 1202 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x204(%esi), %eax\n" /* line 1204 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x210(%esi), %eax\n" /* line 1205 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x21c(%esi), %eax\n" /* line 1206 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x228(%esi), %eax\n" /* line 1207 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x234(%esi), %eax\n" /* line 1208 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x240(%esi), %eax\n" /* line 1209 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa8d78_000a95a9\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | f */
        "movl %eax, 0x108(%esi)\n"
        ".Lfa8d78_000a902e:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9584\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x10c(%esi)\n"
        ".Lfa8d78_000a9058:\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa8d78_000a955f\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | f */
        "movl %eax, 0x110(%esi)\n"
        ".Lfa8d78_000a9082:\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa8d78_000a953a\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | f */
        "movl %eax, 0x114(%esi)\n"
        ".Lfa8d78_000a90ac:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9515\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x118(%esi)\n"
        ".Lfa8d78_000a90d6:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a94f0\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x11c(%esi)\n"
        ".Lfa8d78_000a9100:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a94cb\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x120(%esi)\n"
        ".Lfa8d78_000a912a:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a94a6\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x124(%esi)\n"
        ".Lfa8d78_000a9154:\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa8d78_000a9481\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x128(%esi)\n"
        ".Lfa8d78_000a917e:\n"
        "leal 0x12c(%esi), %edi\n" /* line 1220 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a9422\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        ".Lfa8d78_000a91a2:\n"
        "leal 0x138(%esi), %edi\n" /* line 1221 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa8d78_000a93c0\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "addl $0x2c, %esp\n" /* line 1222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa8d78_000a91ce:\n"
        "movl 0xc4(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0xd0(%esi), %edi\n" /* line 1174 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa8d78_000a8dc7\n"
        ".Lfa8d78_000a9238:\n"
        "movl 0xd0(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0xdc(%esi), %edi\n" /* line 1175 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa8d78_000a8deb\n"
        ".Lfa8d78_000a92a2:\n"
        "movl 0xdc(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0xe8(%esi), %edi\n" /* line 1176 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa8d78_000a8e0f\n"
        ".Lfa8d78_000a930c:\n"
        "movl 0xe8(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa8d78_000a8e2d\n"
        ".Lfa8d78_000a9370:\n"
        "movl 0x100(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 164 */
        "jne .Lfa8d78_000a8e57\n"
        ".Lfa8d78_000a939a:\n"
        "movzbl 0x104(%esi), %eax\n" /* line 165 */
        "movb %al, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $1, 8(%esp)\n" /* line 123 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a8e78\n"
        /* } scope */
        ".Lfa8d78_000a93c0:\n"
        "movl 0x138(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa8d78_000a9422:\n"
        "movl 0x12c(%esi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a91a2\n"
        /* } scope */
        /* } scope */
        ".Lfa8d78_000a9481:\n"
        "movl 0x128(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a917e\n"
        /* } scope */
        ".Lfa8d78_000a94a6:\n"
        "movl 0x124(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9154\n"
        /* } scope */
        ".Lfa8d78_000a94cb:\n"
        "movl 0x120(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a912a\n"
        /* } scope */
        ".Lfa8d78_000a94f0:\n"
        "movl 0x11c(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9100\n"
        /* } scope */
        ".Lfa8d78_000a9515:\n"
        "movl 0x118(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a90d6\n"
        /* } scope */
        ".Lfa8d78_000a953a:\n"
        "movl 0x114(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a90ac\n"
        /* } scope */
        ".Lfa8d78_000a955f:\n"
        "movl 0x110(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9082\n"
        /* } scope */
        ".Lfa8d78_000a9584:\n"
        "movl 0x10c(%esi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a9058\n"
        /* } scope */
        ".Lfa8d78_000a95a9:\n"
        "movl 0x108(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa8d78_000a902e\n"
    );
}

/* line 1329 */
__attribute__((naked))
void OrientedParticle_Archive(const OrientedParticle * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1329 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* arch */
        "movl %edi, 4(%esp)\n" /* line 1333 | arch */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_Archive\n"
        "leal 0x24c(%ebx), %esi\n" /* line 1335 | this, v */
        "cmpb $0, 4(%edi)\n" /* line 227 */
        "je .Lfa95ce_000a9611\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "addl $0x2c, %esp\n" /* line 1336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa95ce_000a9611:\n"
        "movl 0x24c(%ebx), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %ebx\n" /* f */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1472 */
__attribute__((naked))
void Cloud_Archive(const Cloud * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1472 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* arch */
        "movl %esi, 4(%esp)\n" /* line 1476 | arch */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_Archive\n"
        "leal 0x24c(%edi), %ebx\n" /* line 1478 | this, v */
        "cmpb $0, 4(%esi)\n" /* line 227 */
        "je .Lfa966e_000a972e\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        ".Lfa966e_000a96ad:\n"
        "leal 0x264(%edi), %eax\n" /* line 1479 | this */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x270(%edi), %eax\n" /* line 1480 | this */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "cmpb $0, 4(%esi)\n" /* line 213 */
        "je .Lfa966e_000a97b6\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x260(%edi)\n"
        ".Lfa966e_000a96fb:\n"
        "cmpb $0, 4(%esi)\n" /* line 164 */
        "je .Lfa966e_000a978d\n"
        /* { scope 1: f */
        "movl $1, 8(%esp)\n" /* line 84 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movzbl -0x1c(%ebp), %eax\n" /* line 165 | f */
        "movb %al, 0x25c(%edi)\n"
        "addl $0x2c, %esp\n" /* line 1483 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa966e_000a972e:\n"
        "movl 0x24c(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa966e_000a96ad\n"
        /* } scope */
        /* } scope */
        ".Lfa966e_000a978d:\n"
        "movzbl 0x25c(%edi), %eax\n" /* line 165 */
        "movb %al, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $1, 8(%esp)\n" /* line 123 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1483 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa966e_000a97b6:\n"
        "movl 0x260(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa966e_000a96fb\n"
    );
}

/* line 1567 */
__attribute__((naked))
void Line_Archive(const Line * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1567 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* arch */
        "movl %edi, 4(%esp)\n" /* line 1571 | arch */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_Archive\n"
        "leal 0x24c(%ebx), %esi\n" /* line 1573 | this, v */
        "cmpb $0, 4(%edi)\n" /* line 227 */
        "je .Lfa97dc_000a981f\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "addl $0x2c, %esp\n" /* line 1574 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa97dc_000a981f:\n"
        "movl 0x24c(%ebx), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %ebx\n" /* f */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1574 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1699 */
__attribute__((naked))
void Tail_Archive(const Tail * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1699 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "movl %ebx, 4(%esp)\n" /* line 1703 | arch */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_Archive\n"
        "leal 0x24c(%edi), %esi\n" /* line 1705 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa987c_000a990d\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        ".Lfa987c_000a98b7:\n"
        "leal 0x260(%edi), %eax\n" /* line 1707 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "leal 0x26c(%edi), %eax\n" /* line 1708 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveChannelInstance\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa987c_000a996c\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | f */
        "movl %eax, 0x25c(%edi)\n"
        "addl $0x2c, %esp\n" /* line 1711 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa987c_000a990d:\n"
        "movl 0x24c(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "jmp .Lfa987c_000a98b7\n"
        /* } scope */
        /* } scope */
        ".Lfa987c_000a996c:\n"
        "movl 0x25c(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* f */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1711 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1794 */

void Cylinder_Archive(const Cylinder * _this, FxArchive *arch)
{
    Tail_Archive((const Tail *)_this, arch);
}

/* line 2104 */
__attribute__((naked))
void Emitter_Archive(const Emitter * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2104 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "movl %ebx, 4(%esp)\n" /* line 2108 | arch */
        "movl %edi, (%esp)\n" /* this */
        "calll Particle_Archive\n"
        "leal 0x24c(%edi), %esi\n" /* line 2110 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9b3d\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x258(%edi), %esi\n" /* line 2111 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9ba7\n"
        ".Lfa999e_000a99ed:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x264(%edi), %esi\n" /* line 2112 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9c11\n"
        ".Lfa999e_000a9a11:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lfa999e_000a9c75\n"
        /* { scope 1: f */
        ".Lfa999e_000a9a2f:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x270(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa999e_000a9c9f\n"
        /* { scope 1: f */
        ".Lfa999e_000a9a59:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | i */
        "movl %eax, 0x274(%edi)\n"
        "leal 0x278(%edi), %esi\n" /* line 2116 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9ccf\n"
        ".Lfa999e_000a9a89:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x284(%edi), %esi\n" /* line 2117 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lfa999e_000a9d39\n"
        ".Lfa999e_000a9aad:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x290(%edi), %eax\n" /* line 2119 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa999e_000a9daf\n"
        /* { scope 1: f */
        ".Lfa999e_000a9add:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | i */
        "movl %eax, 0x294(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "je .Lfa999e_000a9dd9\n"
        /* { scope 1: f */
        ".Lfa999e_000a9b07:\n"
        "movl $4, 8(%esp)\n" /* line 108 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 214 | i */
        "movl %eax, 0x298(%edi)\n"
        "movl 0xb4(%edi), %eax\n" /* line 2124 | this */
        "testl %eax, %eax\n"
        "je .Lfa999e_000a9e07\n"
        ".Lfa999e_000a9b35:\n"
        "addl $0x2c, %esp\n" /* line 2126 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa999e_000a9b3d:\n"
        "movl 0x24c(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x258(%edi), %esi\n" /* line 2111 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a99ed\n"
        ".Lfa999e_000a9ba7:\n"
        "movl 0x258(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x264(%edi), %esi\n" /* line 2112 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a9a11\n"
        ".Lfa999e_000a9c11:\n"
        "movl 0x264(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lfa999e_000a9a2f\n"
        ".Lfa999e_000a9c75:\n"
        "movl 0x270(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa999e_000a9a59\n"
        ".Lfa999e_000a9c9f:\n"
        "movl 0x274(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "leal 0x278(%edi), %esi\n" /* line 2116 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a9a89\n"
        ".Lfa999e_000a9ccf:\n"
        "movl 0x278(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x284(%edi), %esi\n" /* line 2117 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lfa999e_000a9aad\n"
        ".Lfa999e_000a9d39:\n"
        "movl 0x284(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x290(%edi), %eax\n" /* line 2119 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa999e_000a9add\n"
        ".Lfa999e_000a9daf:\n"
        "movl 0x294(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 213 */
        "jne .Lfa999e_000a9b07\n"
        ".Lfa999e_000a9dd9:\n"
        "movl 0x298(%edi), %eax\n" /* line 214 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "movl 0xb4(%edi), %eax\n" /* line 2124 | this */
        "testl %eax, %eax\n"
        "jne .Lfa999e_000a9b35\n"
        ".Lfa999e_000a9e07:\n"
        "andl $0xffffffef, 0xa8(%edi)\n" /* line 2125 | this */
        "addl $0x2c, %esp\n" /* line 2126 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1732 */
__attribute__((naked))
void ZN8CylinderD0Ev(void) /* Cylinder_~Cylinder */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1732 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa9e16_000a9e67\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa9e16_000a9e67\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa9e16_000a9e5b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa9e16_000a9e7e\n"
        ".Lfa9e16_000a9e48:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa9e16_000a9e5b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa9e16_000a9e48\n"
        ".Lfa9e16_000a9e56:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa9e16_000a9e5b:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa9e16_000a9e67\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa9e16_000a9e67:\n"
        "testl %ebx, %ebx\n"
        "je .Lfa9e16_000a9e78\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 1734 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfa9e16_000a9e78:\n"
        "addl $0x14, %esp\n" /* line 1734 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa9e16_000a9e7e:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa9e16_000a9e56\n"
    );
}

/* line 1732 */
__attribute__((naked))
void ZN8CylinderD1Ev(void) /* Cylinder_~Cylinder */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1732 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa9e86_000a9ed4\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa9e86_000a9ed4\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa9e86_000a9ec7\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa9e86_000a9ed6\n"
        ".Lfa9e86_000a9eb4:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa9e86_000a9ec7\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa9e86_000a9eb4\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa9e86_000a9ec7:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa9e86_000a9ed4\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 1734 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfa9e86_000a9ed4:\n"
        "popl %ebp\n" /* line 1734 */
        "retl\n"
        /* { scope 1 */
        ".Lfa9e86_000a9ed6:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa9e86_000a9ec7\n"
    );
}

/* line 1727 */
__attribute__((naked))
void Cylinder_Cylinder(const Cylinder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1727 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* line 1579 */
        "calll Particle_Particle\n"
        "movl $0x330108, (%ebx)\n" /* line 1727 | this */
        "addl $0x14, %esp\n" /* line 1729 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1260 */
__attribute__((naked))
void OrientedParticle_OrientedParticle(const OrientedParticle * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1260 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_Particle\n"
        "movl $0x330008, (%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 1262 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1265 */
__attribute__((naked))
void ZN16OrientedParticleD1Ev(void) /* OrientedParticle_~OrientedParticle */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1265 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa9f1e_000a9f6c\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa9f1e_000a9f6c\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa9f1e_000a9f5f\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa9f1e_000a9f6e\n"
        ".Lfa9f1e_000a9f4c:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa9f1e_000a9f5f\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa9f1e_000a9f4c\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa9f1e_000a9f5f:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa9f1e_000a9f6c\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 1267 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfa9f1e_000a9f6c:\n"
        "popl %ebp\n" /* line 1267 */
        "retl\n"
        /* { scope 1 */
        ".Lfa9f1e_000a9f6e:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfa9f1e_000a9f5f\n"
    );
}

/* line 1265 */
__attribute__((naked))
void ZN16OrientedParticleD0Ev(void) /* OrientedParticle_~OrientedParticle */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1265 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfa9f7a_000a9fcb\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfa9f7a_000a9fcb\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfa9f7a_000a9fbf\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfa9f7a_000a9fe2\n"
        ".Lfa9f7a_000a9fac:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfa9f7a_000a9fbf\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfa9f7a_000a9fac\n"
        ".Lfa9f7a_000a9fba:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfa9f7a_000a9fbf:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfa9f7a_000a9fcb\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfa9f7a_000a9fcb:\n"
        "testl %ebx, %ebx\n"
        "je .Lfa9f7a_000a9fdc\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 1267 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfa9f7a_000a9fdc:\n"
        "addl $0x14, %esp\n" /* line 1267 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa9f7a_000a9fe2:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfa9f7a_000a9fba\n"
    );
}

/* line 1341 */
__attribute__((naked))
void Cloud_Cloud(const Cloud * _this, const Cloud * _this_1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1341 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll Particle_Particle\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl $0x330048, (%edx)\n"
        "movl $4, -0x1c(%ebp)\n"
        "movl %edx, %edi\n"
        "addl $0x24c, %edi\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $3, %esi\n"
        /* { scope 1 */
        ".Lfa9fea_000aa01e:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1372 */
        "movl $0xbf800000, (%esp)\n"
        "calll flrand\n"
        "fstps 0x24c(%ebx)\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 1371 */
        "jne .Lfa9fea_000aa01e\n"
        "movl 8(%ebp), %eax\n" /* line 316 | this */
    );
}

/* line 1347 */
__attribute__((naked))
void ZN5CloudD1Ev(void) /* Cloud_~Cloud */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1347 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa112_000aa160\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa112_000aa160\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa112_000aa153\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa112_000aa162\n"
        ".Lfaa112_000aa140:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa112_000aa153\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa112_000aa140\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa112_000aa153:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa112_000aa160\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 1349 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfaa112_000aa160:\n"
        "popl %ebp\n" /* line 1349 */
        "retl\n"
        /* { scope 1 */
        ".Lfaa112_000aa162:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfaa112_000aa153\n"
    );
}

/* line 1347 */
__attribute__((naked))
void ZN5CloudD0Ev(void) /* Cloud_~Cloud */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1347 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa16e_000aa1bf\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa16e_000aa1bf\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa16e_000aa1b3\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa16e_000aa1d6\n"
        ".Lfaa16e_000aa1a0:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa16e_000aa1b3\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa16e_000aa1a0\n"
        ".Lfaa16e_000aa1ae:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa16e_000aa1b3:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa16e_000aa1bf\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfaa16e_000aa1bf:\n"
        "testl %ebx, %ebx\n"
        "je .Lfaa16e_000aa1d0\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 1349 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfaa16e_000aa1d0:\n"
        "addl $0x14, %esp\n" /* line 1349 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaa16e_000aa1d6:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfaa16e_000aa1ae\n"
    );
}

/* line 1499 */
__attribute__((naked))
void Line_Line(const Line * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1499 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_Particle\n"
        "movl $0x330088, (%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 1501 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1504 */
__attribute__((naked))
void ZN4LineD1Ev(void) /* Line_~Line */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1504 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa1fe_000aa24c\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa1fe_000aa24c\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa1fe_000aa23f\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa1fe_000aa24e\n"
        ".Lfaa1fe_000aa22c:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa1fe_000aa23f\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa1fe_000aa22c\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa1fe_000aa23f:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa1fe_000aa24c\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 1506 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfaa1fe_000aa24c:\n"
        "popl %ebp\n" /* line 1506 */
        "retl\n"
        /* { scope 1 */
        ".Lfaa1fe_000aa24e:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfaa1fe_000aa23f\n"
    );
}

/* line 1504 */
__attribute__((naked))
void ZN4LineD0Ev(void) /* Line_~Line */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1504 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa25a_000aa2ab\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa25a_000aa2ab\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa25a_000aa29f\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa25a_000aa2c2\n"
        ".Lfaa25a_000aa28c:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa25a_000aa29f\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa25a_000aa28c\n"
        ".Lfaa25a_000aa29a:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa25a_000aa29f:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa25a_000aa2ab\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfaa25a_000aa2ab:\n"
        "testl %ebx, %ebx\n"
        "je .Lfaa25a_000aa2bc\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 1506 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfaa25a_000aa2bc:\n"
        "addl $0x14, %esp\n" /* line 1506 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaa25a_000aa2c2:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfaa25a_000aa29a\n"
    );
}

/* line 1579 */
__attribute__((naked))
void Tail_Tail(const Tail * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1579 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_Particle\n"
        "movl $0x3300c8, (%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 1581 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1584 */
__attribute__((naked))
void ZN4TailD1Ev(void) /* Tail_~Tail */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1584 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa2ea_000aa338\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa2ea_000aa338\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa2ea_000aa32b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa2ea_000aa33a\n"
        ".Lfaa2ea_000aa318:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa2ea_000aa32b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa2ea_000aa318\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa2ea_000aa32b:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa2ea_000aa338\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 1586 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfaa2ea_000aa338:\n"
        "popl %ebp\n" /* line 1586 */
        "retl\n"
        /* { scope 1 */
        ".Lfaa2ea_000aa33a:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfaa2ea_000aa32b\n"
    );
}

/* line 1584 */
__attribute__((naked))
void ZN4TailD0Ev(void) /* Tail_~Tail */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1584 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa346_000aa397\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa346_000aa397\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa346_000aa38b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa346_000aa3ae\n"
        ".Lfaa346_000aa378:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa346_000aa38b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa346_000aa378\n"
        ".Lfaa346_000aa386:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa346_000aa38b:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa346_000aa397\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfaa346_000aa397:\n"
        "testl %ebx, %ebx\n"
        "je .Lfaa346_000aa3a8\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 1586 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfaa346_000aa3a8:\n"
        "addl $0x14, %esp\n" /* line 1586 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaa346_000aa3ae:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfaa346_000aa386\n"
    );
}

/* line 1804 */
__attribute__((naked))
void Emitter_Emitter(const Emitter * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1804 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll Particle_Particle\n"
        "movl $0x330148, (%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 1806 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1809 */
__attribute__((naked))
void ZN7EmitterD1Ev(void) /* Emitter_~Emitter */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1809 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa3d6_000aa424\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa3d6_000aa424\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa3d6_000aa417\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa3d6_000aa426\n"
        ".Lfaa3d6_000aa404:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa3d6_000aa417\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa3d6_000aa404\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa3d6_000aa417:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa3d6_000aa424\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 1811 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lfaa3d6_000aa424:\n"
        "popl %ebp\n" /* line 1811 */
        "retl\n"
        /* { scope 1 */
        ".Lfaa3d6_000aa426:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lfaa3d6_000aa417\n"
    );
}

/* line 1809 */
__attribute__((naked))
void ZN7EmitterD0Ev(void) /* Emitter_~Emitter */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1809 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lfaa432_000aa483\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lfaa432_000aa483\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lfaa432_000aa477\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lfaa432_000aa49a\n"
        ".Lfaa432_000aa464:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa432_000aa477\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lfaa432_000aa464\n"
        ".Lfaa432_000aa472:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lfaa432_000aa477:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lfaa432_000aa483\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfaa432_000aa483:\n"
        "testl %ebx, %ebx\n"
        "je .Lfaa432_000aa494\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 1811 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lfaa432_000aa494:\n"
        "addl $0x14, %esp\n" /* line 1811 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaa432_000aa49a:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lfaa432_000aa472\n"
    );
}

/* line 186 */
float Effect_GetVisibility(const Effect * _this, const vec_t *start, const vec_t *dir, float halfLen)
{
    return 1.0f;
}

/* line 189 */
void Effect_AddVisibility(const Effect * _this)
{
}

/* line 284 */
Bool Flash_Cull(const Flash * _this)
{
    return 0;
}

/* line 282 */
__attribute__((naked))
void ZN5FlashD0Ev(void) /* Flash_~Flash */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 282 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32ff88, (%ebx)\n" /* line 182 */
        "movl 0xc0(%ebx), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lf2bf27a_002bf2cb\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lf2bf27a_002bf2cb\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lf2bf27a_002bf2bf\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lf2bf27a_002bf2e2\n"
        ".Lf2bf27a_002bf2ac:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2bf27a_002bf2bf\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lf2bf27a_002bf2ac\n"
        ".Lf2bf27a_002bf2ba:\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lf2bf27a_002bf2bf:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lf2bf27a_002bf2cb\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lf2bf27a_002bf2cb:\n"
        "testl %ebx, %ebx\n"
        "je .Lf2bf27a_002bf2dc\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 282 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdaPv\n" /* line 35 */
        ".Lf2bf27a_002bf2dc:\n"
        "addl $0x14, %esp\n" /* line 282 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bf27a_002bf2e2:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "jmp .Lf2bf27a_002bf2ba\n"
    );
}

/* line 282 */
__attribute__((naked))
void ZN5FlashD1Ev(void) /* Flash_~Flash */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 282 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32ff88, (%eax)\n" /* line 182 */
        "movl 0xc0(%eax), %edx\n" /* line 60 */
        "testl %edx, %edx\n"
        "je .Lf2bf2ea_002bf338\n"
        "movl (%edx), %eax\n" /* line 71 */
        "subl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 72 */
        "jne .Lf2bf2ea_002bf338\n"
        /* { scope 1 */
        "movl __ZN11FxBoltFrame12g_mFrameListE, %eax\n" /* line 75 */
        "testl %eax, %eax\n"
        "je .Lf2bf2ea_002bf32b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "je .Lf2bf2ea_002bf33a\n"
        ".Lf2bf2ea_002bf318:\n"
        "leal 0x38(%eax), %ecx\n" /* line 75 */
        "movl 0x38(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2bf2ea_002bf32b\n"
        "cmpl %edx, %eax\n" /* line 77 */
        "jne .Lf2bf2ea_002bf318\n"
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        ".Lf2bf2ea_002bf32b:\n"
        "testl %edx, %edx\n" /* line 35 */
        "je .Lf2bf2ea_002bf338\n"
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 282 */
        /* { scope 1 */
        "jmp __ZdaPv\n" /* line 35 */
        /* } scope */
        ".Lf2bf2ea_002bf338:\n"
        "popl %ebp\n" /* line 282 */
        "retl\n"
        /* { scope 1 */
        ".Lf2bf2ea_002bf33a:\n"
        "movl $__ZN11FxBoltFrame12g_mFrameListE, %ecx\n" /* line 77 */
        "movl 0x38(%edx), %eax\n" /* line 79 */
        "movl %eax, (%ecx)\n"
        "jmp .Lf2bf2ea_002bf32b\n"
    );
}

