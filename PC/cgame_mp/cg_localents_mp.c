/* Decompiled from: cg_localents_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_localents_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern void BG_EvaluateTrajectory(void *traj, int time, float *result);
extern const vec_t Vec3NormalizeTo(const vec_t *v, vec_t *out);
extern void CG_DrawTracer(vec_t *start, vec_t *finish);
extern void Com_Error(int code, const char *fmt, ...);

extern localEntity_t cg_eachClientActiveLocalEntities[1]; /* 0x0 */
extern localEntity_t * cg_eachClientFreeLocalEntities[1]; /* 0x0 */
extern localEntity_t *cg_localEntities; /* 0x0 */
extern localEntity_t *cg_activeLocalEntities; /* 0x0 */
extern localEntity_t *cg_freeLocalEntities; /* 0x0 */
static cg_eachClientLocalEntities_t cg_eachClientLocalEntities; /* cg_eachClientLocalEntities */

void CG_InitLocalEntities(void);
void CG_AddMovingTracer(localEntity_t *le);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__I_cg_eachClientActiveLocalEntities(void); /* global constructors keyed to cg_eachClientActiveLocalEntities */
localEntity_t * CG_AllocLocalEntity(void);
void CG_AddLocalEntities(void);

/*
 * CG_FreeLocalEntity - Unlink a local entity from the active list and
 * return it to the free list.
 * Inlined helper used by CG_AllocLocalEntity and CG_AddLocalEntities.
 */
static void CG_FreeLocalEntity(localEntity_t *le)
{
    localEntity_t *prev_ent = (localEntity_t *)(le->prev);
    localEntity_t *next_ent = (localEntity_t *)(le->next);

    if (!prev_ent) {
        Com_Error(1, "CG_FreeLocalEntity: not active");
    }

    /* Unlink from active list */
    next_ent->prev = (int)prev_ent;
    prev_ent->next = (int)next_ent;

    /* Add to free list */
    le->next = (int)cg_freeLocalEntities;
    cg_freeLocalEntities = le;
}

/* line 50 */
void CG_InitLocalEntities(void)
{
    int i;

    memset(cg_localEntities, 0, 0x5e00);

    /* Make the active list a circular sentinel */
    cg_activeLocalEntities->next = (int)cg_activeLocalEntities;
    cg_activeLocalEntities->prev = (int)cg_activeLocalEntities;

    /* Build the free list */
    cg_freeLocalEntities = cg_localEntities;
    for (i = 0; i < 127; i++) {
        cg_localEntities[i].next = (int)&cg_localEntities[i + 1];
    }
}

/* line 103 */
void CG_AddMovingTracer(localEntity_t *le)
{
    vec3_t start;
    vec3_t end;
    vec3_t dir;
    int time;
    float dot;
    float dist;

    /* Evaluate the trajectory to get current position */
    time = *(int *)((char *)(*(int *)imp_cg) + 0x25bb0);
    BG_EvaluateTrajectory(&le->pos, time, start);

    /* Get normalized direction from trDelta */
    Vec3NormalizeTo(le->pos.trDelta, dir);

    /* dot = (start - trBase) . dir */
    dot = (start[0] - le->pos.trBase[0]) * dir[0]
        + (start[1] - le->pos.trBase[1]) * dir[1]
        + (start[2] - le->pos.trBase[2]) * dir[2];

    /* dist = min(tracerClipDist - dot, cg_tracerSpeed) */
    dist = le->tracerClipDist - dot;
    {
        float tracerLen = *(float *)((char *)(*(int *)imp_cg_tracerLength) + 8);
        if (dist > tracerLen) {
            dist = tracerLen;
        }
    }

    /* end = start + dist * dir */
    end[0] = start[0] + dist * dir[0];
    end[1] = start[1] + dist * dir[1];
    end[2] = start[2] + dist * dir[2];

    CG_DrawTracer(start, end);
}

/* line 157 */
static void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "cmpl $0xffff, %edx\n"
        "je .Lf1dd90a_001dd917\n"
        ".Lf1dd90a_001dd915:\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dd90a_001dd917:\n"
        "subl $1, %eax\n"
        "jne .Lf1dd90a_001dd915\n"
        "movl cg_eachClientFreeLocalEntities, %eax\n"
        "movl %eax, cg_freeLocalEntities\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 158 */
static void GLOBAL__I_cg_eachClientActiveLocalEntities(void) /* global constructors keyed to cg_eachClientActiveLocalEntities */
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 78 */
localEntity_t * CG_AllocLocalEntity(void)
{
    localEntity_t *le;

    if (!cg_freeLocalEntities) {
        /* No free entities, steal oldest active one */
        le = (localEntity_t *)(cg_activeLocalEntities->prev);
        CG_FreeLocalEntity(le);
    }

    le = cg_freeLocalEntities;

    /* Unlink from free list */
    cg_freeLocalEntities = (localEntity_t *)(le->next);

    /* Clear the entity */
    memset(le, 0, 0xbc);

    /* Insert into active list (at head, after sentinel) */
    le->next = cg_activeLocalEntities->next;
    le->prev = (int)cg_activeLocalEntities;
    ((localEntity_t *)(cg_activeLocalEntities->next))->prev = (int)le;
    cg_activeLocalEntities->next = (int)le;

    return le;
}

/* line 129 */
void CG_AddLocalEntities(void)
{
    localEntity_t *le;
    localEntity_t *next;
    int time;

    le = (localEntity_t *)(cg_activeLocalEntities->prev);

    while (le != cg_activeLocalEntities) {
        next = (localEntity_t *)(le->prev);

        time = *(int *)((char *)(*(int *)imp_cg) + 0x25bb0);

        if (time >= le->endTime || time < le->pos.trTime) {
            /* Entity has expired or time is before trajectory start - free it */
            CG_FreeLocalEntity(le);
        } else {
            CG_AddMovingTracer(le);
        }

        le = next;
    }
}

