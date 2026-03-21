/* ASM dump from: g_weapon_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_weapon_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 */

static vec2_t traceOffsets[5]; /* traceOffsets */

/* Math functions */
extern float floorf(float x);
extern float ceilf(float x);

/* Extern functions */
extern char * va(const char *format, ...);
extern void SV_GameSendServerCommand(int clientNum, int svscmd_type, const char *text);
extern int BG_FindWeaponIndexForName(const char *name);
extern int BG_GetWeaponIndexForName(const char *name, void *weaponInfoMem);
extern qboolean OnSameTeam(gentity_t *ent1, gentity_t *ent2);

/* External globals */
extern struct level_locals_t level;
extern void *bg_weaponInfoMem; /* imp_G_RegisterWeapon - weapon info memory ptr */

/* Entity/client field access macros */
#define ENT_TAKEDAMAGE(e)    ((e)->takedamage)
#define ENT_CLIENT(e)        ((e)->client)
#define CLIENT_PS_PM_TYPE(c) ((c)->ps.pm_type)

void SnapVectorTowards(vec_t *v, vec_t *to);
qboolean LogAccuracyHit(gentity_t *target, gentity_t *attacker);
int G_GetWeaponIndexForName(const char *name);
void G_SetEquippedOffHand(int clientNum, int offHandIndex);
void G_SelectWeaponIndex(int clientNum, int iWeaponIndex);
void Weapon_RocketLauncher_Fire(gentity_s (*ent)[16], float spread, weaponParms *wp);
int weapon_grenadelauncher_fire(gentity_s (*ent)[16], int grenType, weaponParms *wp);
void G_UseOffHand(gentity_s (*ent)[16]);
static Bool Melee_Trace(gentity_s (*ent)[16], weaponParms *wp, int damage, float range, float width, float height, trace_t *trace, vec_t *endPos);
void Weapon_Melee(gentity_s (*ent)[16], weaponParms *wp, float range, float width, float height);
void FireWeaponMelee(gentity_s (*ent)[16]);
static void Bullet_Fire_Extended(const gentity_t *source, gentity_s (*attacker)[16], vec_t *end, float damageMultiplier, int recursion, const weaponParms *wp, const gentity_t *weaponEnt, const int gametime);
void G_SetupWeaponDef(void);
void Bullet_Endpos(float spread, vec_t *end, const weaponParms *wp, float maxRange);
void Bullet_Fire(gentity_s (*attacker)[16], float spread, weaponParms *wp, gentity_s (*weaponEnt)[16], int gametime);
void FireWeaponAntiLag(gentity_s (*ent)[16], int gametime);
qboolean G_GivePlayerWeapon(playerState_t *pPS, int iWeaponIndex);

/* line 172 */
void SnapVectorTowards(vec_t *v, vec_t *to)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (v[i] >= to[i])
            v[i] = floorf(v[i]);
        else
            v[i] = ceilf(v[i]);
    }
}

/* line 679 */
qboolean LogAccuracyHit(gentity_t *target, gentity_t *attacker)
{
    if (!ENT_TAKEDAMAGE(target))
        return 0;
    if (target == attacker)
        return 0;
    if (!ENT_CLIENT(target))
        return 0;
    if (!ENT_CLIENT(attacker))
        return 0;
    if (CLIENT_PS_PM_TYPE(ENT_CLIENT(target)) > 5)
        return 0;
    if (OnSameTeam(target, attacker))
        return 0;
    return 1;
}

/* line 963 */
int G_GetWeaponIndexForName(const char *name)
{
    if (!level.initializing)
        return BG_FindWeaponIndexForName(name);
    return BG_GetWeaponIndexForName(name, bg_weaponInfoMem);
}

/* line 985 */
void G_SetEquippedOffHand(int clientNum, int offHandIndex)
{
    SV_GameSendServerCommand(clientNum, 1, va("%c %i", 0x43, offHandIndex));
}

/* line 974 */
void G_SelectWeaponIndex(int clientNum, int iWeaponIndex)
{
    SV_GameSendServerCommand(clientNum, 1, va("%c %i", 0x61, iWeaponIndex));
}

/* line 644 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void Weapon_RocketLauncher_Fire(gentity_s (*ent)[16], float spread, weaponParms *wp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 644 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "movl 0x10(%ebp), %edi\n" /* wp */
        /* { scope 1: r */
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* line 652 | spread */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll tan\n"
        "fstpl -0x50(%ebp)\n"
        "cvtsd2ss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* fAimOffset */
        "movss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "mulss -0x44(%ebp), %xmm0\n" /* fAimOffset */
        "movss %xmm0, -0x44(%ebp)\n" /* fAimOffset */
        /* { scope 2 */
        "calll randomf\n" /* line 203 */
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n" /* line 204 */
        "calll randomf\n"
        "fstps -0x40(%ebp)\n" /* r */
        "movss -0x68(%ebp), %xmm0\n" /* line 205 */
        "mulss lit4_002ed638, %xmm0\n" /* 360.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        /* } scope */
        "movss %xmm0, (%esp)\n" /* line 486 */
        "calll cosf\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm1\n"
        "mulss -0x40(%ebp), %xmm1\n" /* r */
        "mulss -0x44(%ebp), %xmm1\n" /* fAimOffset */
        "movss -0x3c(%ebp), %xmm0\n" /* line 485 */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll sinf\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm2\n"
        "mulss -0x40(%ebp), %xmm2\n" /* r */
        "mulss -0x44(%ebp), %xmm2\n" /* fAimOffset */
        "movss (%edi), %xmm0\n" /* line 272 */
        "mulss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movss 4(%edi), %xmm0\n" /* line 273 */
        "mulss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss lit4_002ed6a8, %xmm0\n" /* line 274 | 16.0f */
        "mulss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0xc(%edi), %eax\n"
        /* { scope 2 */
        "movss -0x78(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0xc(%edi), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* dir */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "leal 0x18(%edi), %eax\n"
        /* } scope */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 288 */
        "mulss 0x18(%edi), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* dir */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm2\n" /* line 290 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x24(%ebp), %ebx\n" /* line 660 | dir */
        "movl %ebx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal 0x24(%edi), %edx\n" /* wp */
        /* { scope 2 */
        "movl 0x24(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* launchpos */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        /* } scope */
        "movl %ebx, 8(%esp)\n" /* line 664 */
        "leal -0x30(%ebp), %eax\n" /* launchpos */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll fire_rocket\n"
        "movl 0x158(%esi), %edx\n" /* line 667 | ent */
        "testl %edx, %edx\n"
        "je .Lf1c58e6_001c5acf\n"
        "leal 0x20(%edx), %eax\n" /* line 668 | result */
        /* { scope 2 */
        "movss lit4_002eda00, %xmm1\n" /* line 288 | -64.0f */
        "movss (%edi), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x20(%edx), %xmm0\n"
        "movss %xmm0, 0x20(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%edi), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lf1c58e6_001c5acf:\n"
        "addl $0x8c, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
#include <math.h>
extern float randomf(void);
extern float Vec3Normalize(vec3_t v);
extern void *fire_rocket(gentity_t *ent, vec_t *start, vec_t *dir);
extern void *fire_grenade(gentity_t *ent, vec_t *start, vec_t *vel, int grenType, int fuseTime);
extern void AngleVectors(vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern void G_GetPlayerViewOrigin(gentity_t *ent, vec_t *origin);
extern void G_LocationalTrace(void *results, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask, unsigned char *priorityMap);
extern void G_CheckHitTriggerDamage(gentity_t *attacker, vec_t *start, vec_t *end, int damage, int mod);
extern void *G_TempEntity(vec_t *origin, int event);
extern int DirToByte(vec_t *dir);
extern void G_Damage(gentity_t *target, gentity_t *inflictor, gentity_t *attacker, void *dir, vec_t *point, int damage, int dflags, int mod, int hitLoc, int timeOffset);
extern void G_GetPlayerViewDirection(gentity_t *ent, vec_t *forward, vec_t *right, vec_t *up);
extern void *BG_GetWeaponDef(int weaponIndex);
extern int rand(void);

void Weapon_RocketLauncher_Fire(gentity_s (*ent)[16], float spread, weaponParms *wp) {
    float fAimOffset;
    float r1, r2;
    float angle;
    float cosVal, sinVal;
    float rightScale, upScale;
    vec3_t dir;
    vec3_t launchpos;
    gentity_t *missile;
    gclient_t *client;
    double angRad;

    /* Convert spread to aim offset */
    angRad = (double)spread * 0.017453292519943295;
    fAimOffset = (float)tan(angRad);
    fAimOffset *= 16.0f;

    /* Random angle and radius */
    r1 = (float)randomf(); /* random [0,1] */
    r2 = (float)randomf(); /* random [0,1] */
    angle = r1 * 360.0f;
    angle = (float)((double)angle * 0.017453292519943295);

    cosVal = cosf(angle);
    rightScale = r2 * cosVal * fAimOffset;
    sinVal = sinf(angle);
    upScale = r2 * sinVal * fAimOffset;

    /* dir = forward * 16 */
    dir[0] = wp->forward[0] * 16.0f;
    dir[1] = wp->forward[1] * 16.0f;
    dir[2] = wp->forward[2] * 16.0f;

    /* dir += right * rightScale */
    dir[0] += rightScale * wp->right[0];
    dir[1] += rightScale * wp->right[1];
    dir[2] += rightScale * wp->right[2];

    /* dir += up * upScale */
    dir[0] += upScale * wp->up[0];
    dir[1] += upScale * wp->up[1];
    dir[2] += upScale * wp->up[2];

    Vec3Normalize(dir);

    /* Copy launch position */
    launchpos[0] = wp->muzzleTrace[0];
    launchpos[1] = wp->muzzleTrace[1];
    launchpos[2] = wp->muzzleTrace[2];

    missile = (gentity_t *)fire_rocket((gentity_t *)ent, launchpos, dir);

    /* Kick back */
    client = ((gentity_t *)ent)->client;
    if (client) {
        client->ps.velocity[0] += wp->forward[0] * -64.0f;
        client->ps.velocity[1] += wp->forward[1] * -64.0f;
        client->ps.velocity[2] += wp->forward[2] * -64.0f;
    }
}
#endif

/* line 615 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int weapon_grenadelauncher_fire(gentity_s (*ent)[16], int grenType, weaponParms *wp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 615 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        "movl 0x10(%ebp), %edx\n" /* wp */
        /* { scope 1 */
        "movl 0x3c(%edx), %eax\n" /* line 621 */
        "cvtsi2ssl 0x384(%eax), %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%edx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* vTossVel */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss 8(%edx), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "cvtsi2ssl 0x388(%eax), %xmm0\n" /* line 622 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0x248(%eax), %eax\n" /* line 624 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* grenType */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %esi\n" /* vTossVel */
        "movl %esi, 8(%esp)\n"
        "addl $0x24, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll fire_grenade\n"
        "movl %eax, %ebx\n" /* m */
        "movl %esi, (%esp)\n" /* line 627 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl 0x158(%edi), %eax\n" /* ent */
        "leal 0x20(%eax), %edx\n"
        /* { scope 2 */
        "movss -0x24(%ebp), %xmm2\n" /* line 304 | vTossVel */
        "movaps %xmm2, %xmm1\n"
        "mulss 0x20(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "leal 0x24(%ebx), %eax\n" /* line 629 | m, result */
        /* { scope 2 */
        "mulss %xmm1, %xmm2\n" /* line 288 */
        "addss 0x24(%ebx), %xmm2\n"
        "movss %xmm2, 0x24(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 633 | m */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
int weapon_grenadelauncher_fire(gentity_s (*ent)[16], int grenType, weaponParms *wp) {
    vec3_t vTossVel;
    float scale;
    int fuseTime;
    gentity_t *m;
    gclient_t *client;
    float dot;
    float *forward;
    void *weapDef;

    /* Get weapon def for projectile speed/up-velocity */
    weapDef = (void *)wp->weapDef;
    scale = (float)((WeaponDef *)weapDef)->iProjectileSpeed;
    /* vTossVel = forward * scale */
    vTossVel[0] = wp->forward[0] * scale;
    vTossVel[1] = wp->forward[1] * scale;
    vTossVel[2] = wp->forward[2] * scale;

    /* Add upward velocity component */
    vTossVel[2] += (float)((WeaponDef *)weapDef)->iProjectileSpeedUp;

    /* Get fuse time */
    fuseTime = ((WeaponDef *)weapDef)->iFuseTime;

    /* Fire the grenade */
    m = (gentity_t *)fire_grenade((gentity_t *)ent, wp->muzzleTrace, vTossVel, grenType, fuseTime);

    /* Normalize toss velocity */
    Vec3Normalize(vTossVel);

    /* Add velocity dot product to missile origin */
    client = ((gentity_t *)ent)->client;
    forward = client->ps.velocity;
    dot = vTossVel[0] * forward[0] + vTossVel[1] * forward[1] + vTossVel[2] * forward[2];

    m->s.pos.trDelta[0] += vTossVel[0] * dot;
    m->s.pos.trDelta[1] += vTossVel[1] * dot;
    m->s.pos.trDelta[2] += vTossVel[2] * dot;

    return (int)m;
}
#endif

/* line 797 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void G_UseOffHand(gentity_s (*ent)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 797 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1: viewang */
        "movl 0x158(%ebx), %eax\n" /* line 804 | ent */
        "movl 0xd0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl 0x158(%ebx), %edx\n" /* ent */
        "leal 0xe8(%edx), %ecx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xe8(%edx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* viewang */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        /* } scope */
        "movl 0x27d8(%edx), %eax\n" /* line 725 */
        "movl %eax, -0x14(%ebp)\n" /* viewang */
        "movl 0x27dc(%edx), %eax\n" /* line 726 */
        "movl %eax, -0x10(%ebp)\n"
        "leal -0x54(%ebp), %esi\n" /* line 729 | wp */
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* viewang */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal -0x30(%ebp), %eax\n" /* line 731 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_GetPlayerViewOrigin\n"
        /* } scope */
        "movl %esi, 8(%esp)\n" /* line 810 */
        "movl 0x158(%ebx), %eax\n" /* ent */
        "movl 0xd0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll weapon_grenadelauncher_fire\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 811 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void G_UseOffHand(gentity_s (*ent)[16]) {
    vec3_t viewang;
    vec3_t forward, right, up;
    vec3_t muzzlePoint;
    weaponParms wp;
    gclient_t *client;
    int weaponIndex;
    void *weapDef;

    client = ((gentity_t *)ent)->client;

    /* Get current off-hand weapon index */
    weaponIndex = client->ps.offHandIndex;
    weapDef = BG_GetWeaponDef(weaponIndex);

    /* Get view angles from client */
    viewang[0] = client->ps.viewangles[0];
    viewang[1] = client->ps.viewangles[1];
    viewang[2] = client->ps.viewangles[2];

    /* Override pitch/yaw with view command angles */
    viewang[0] = *(float *)((byte *)client + 0x27d8); /* unknown: cmd viewangles override pitch */
    viewang[1] = *(float *)((byte *)client + 0x27dc); /* unknown: cmd viewangles override yaw */

    /* Build direction vectors */
    AngleVectors(viewang, (float *)&wp, right, up);

    /* Get muzzle origin */
    G_GetPlayerViewOrigin((gentity_t *)ent, muzzlePoint);

    /* Fire grenade launcher with off-hand weapon */
    weapon_grenadelauncher_fire(ent, client->ps.offHandIndex, &wp);
}
#endif

/* line 41 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
Bool Melee_Trace(gentity_s (*ent)[16], weaponParms *wp, int damage, float range, float width, float height, trace_t *trace, vec_t *endPos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* wp */
        /* { scope 1 */
        "movss 0x18(%ebp), %xmm0\n" /* line 51 | width */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "ja .Lf1c5c72_001c5c9c\n"
        "jp .Lf1c5c72_001c5c9c\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss 0x1c(%ebp), %xmm0\n" /* height */
        "jae .Lf1c5c72_001c5e8f\n"
        ".Lf1c5c72_001c5c9c:\n"
        "movl $5, -0x38(%ebp)\n" /* numTraces */
        ".Lf1c5c72_001c5ca3:\n"
        "movl imp_bulletPriorityMap, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x24(%ebp), %edx\n" /* endPos */
        "addl $4, %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl 0x24(%ebp), %eax\n" /* endPos */
        "addl $8, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "xorl %edi, %edi\n" /* traceIndex */
        "movl $traceOffsets, %esi\n"
        "leal 0x24(%ebx), %edx\n" /* wp */
        "movl %edx, -0x40(%ebp)\n"
        "leal 0xc(%ebx), %eax\n" /* wp */
        "movl %eax, -0x44(%ebp)\n"
        "leal 0x18(%ebx), %edx\n" /* wp */
        "movl %edx, -0x3c(%ebp)\n"
        "jmp .Lf1c5c72_001c5d0d\n"
        ".Lf1c5c72_001c5cd8:\n"
        "movl 0x20(%ebp), %edx\n" /* line 83 | trace */
        "testb $0x10, 0x10(%edx)\n"
        "jne .Lf1c5c72_001c5cf8\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 87 | 1.0f */
        "ucomiss (%edx), %xmm0\n"
        "jne .Lf1c5c72_001c5e9b\n"
        "jp .Lf1c5c72_001c5e9b\n"
        ".Lf1c5c72_001c5cf8:\n"
        "addl $1, %edi\n" /* line 58 | traceIndex */
        "addl $8, %esi\n"
        "cmpl %edi, -0x38(%ebp)\n" /* traceIndex, numTraces */
        "je .Lf1c5c72_001c5e85\n"
        "movl -0x44(%ebp), %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        ".Lf1c5c72_001c5d0d:\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 288 | range */
        "mulss (%ebx), %xmm0\n" /* wp */
        "addss 0x24(%ebx), %xmm0\n" /* wp */
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movss 0x14(%ebp), %xmm0\n" /* line 289 | range */
        "mulss 4(%ebx), %xmm0\n" /* wp */
        "addss 0x28(%ebx), %xmm0\n" /* wp */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 290 | range */
        "mulss 8(%ebx), %xmm0\n" /* wp */
        "addss 0x2c(%ebx), %xmm0\n" /* wp */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss 0x18(%ebp), %xmm1\n" /* line 62 | width, scale */
        "mulss (%esi), %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0xc(%ebx), %xmm0\n" /* wp */
        "addss -0x24(%ebp), %xmm0\n" /* end */
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movss 0x1c(%ebp), %xmm1\n" /* line 63 | height, scale */
        "mulss 4(%esi), %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x18(%ebx), %xmm0\n" /* wp */
        "addss -0x24(%ebp), %xmm0\n" /* end */
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%edx), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movl -0x34(%ebp), %eax\n" /* line 74 */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x2802831, 0x10(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "movl 0x20(%ebp), %edx\n" /* line 75 | trace */
        "movss (%edx), %xmm2\n" /* fraction */
        /* { scope 2 */
        "movss 0x24(%ebx), %xmm1\n" /* line 1203 | wp */
        "movss -0x24(%ebp), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl 0x24(%ebp), %eax\n" /* endPos */
        "movss %xmm1, (%eax)\n"
        "movss 0x28(%ebx), %xmm1\n" /* line 1204 | wp */
        "movss -0x20(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x30(%ebp), %edx\n"
        "movss %xmm1, (%edx)\n"
        "movss 0x2c(%ebx), %xmm1\n" /* line 1205 | wp */
        "movss -0x1c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movl -0x2c(%ebp), %eax\n"
        "movss %xmm1, (%eax)\n"
        /* } scope */
        "testl %edi, %edi\n" /* line 77 | traceIndex */
        "jne .Lf1c5c72_001c5cd8\n"
        "movl $7, 0x10(%esp)\n" /* line 80 */
        "movl 0x10(%ebp), %edx\n" /* damage */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* endPos */
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll G_CheckHitTriggerDamage\n"
        "jmp .Lf1c5c72_001c5cd8\n"
        ".Lf1c5c72_001c5e85:\n"
        "xorl %eax, %eax\n" /* line 58 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 94 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c5c72_001c5e8f:\n"
        "movl $1, -0x38(%ebp)\n" /* line 51 | numTraces */
        "jmp .Lf1c5c72_001c5ca3\n"
        ".Lf1c5c72_001c5e9b:\n"
        "movl $1, %eax\n" /* line 88 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 94 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
static Bool Melee_Trace(gentity_s (*ent)[16], weaponParms *wp, int damage, float range, float width, float height, trace_t *trace, vec_t *endPos) {
    int numTraces;
    int traceIndex;
    vec3_t end;
    float widthScale, heightScale;
    float fraction;
    float *origin;
    float *forward;
    float *right;
    float *up;

    if (width > 0.0f || height > 0.0f) {
        numTraces = 5;
    } else {
        numTraces = 1;
    }

    origin = wp->muzzleTrace;
    forward = wp->forward;
    right = wp->right;
    up = wp->up;

    for (traceIndex = 0; traceIndex < numTraces; traceIndex++) {
        /* end = origin + forward * range */
        end[0] = forward[0] * range + origin[0];
        end[1] = forward[1] * range + origin[1];
        end[2] = forward[2] * range + origin[2];

        /* Add right offset */
        widthScale = width * ((float *)&traceOffsets)[traceIndex * 2];
        end[0] += right[0] * widthScale;
        end[1] += right[1] * widthScale;
        end[2] += right[2] * widthScale;

        /* Add up offset */
        heightScale = height * ((float *)&traceOffsets)[traceIndex * 2 + 1];
        end[0] += up[0] * heightScale;
        end[1] += up[1] * heightScale;
        end[2] += up[2] * heightScale;

        /* Do the trace */
        G_LocationalTrace(trace, origin, end, ((gentity_t *)ent)->s.number, 0x2802831, (unsigned char *)imp_bulletPriorityMap);

        /* Compute hit position via interpolation */
        fraction = trace->fraction;
        endPos[0] = origin[0] + (end[0] - origin[0]) * fraction;
        endPos[1] = origin[1] + (end[1] - origin[1]) * fraction;
        endPos[2] = origin[2] + (end[2] - origin[2]) * fraction;

        /* First trace also checks trigger damage */
        if (traceIndex == 0) {
            G_CheckHitTriggerDamage((gentity_t *)ent, origin, endPos, damage, 7);
        }

        /* Check for entity hit (not pass-through and fraction < 1.0) */
        if (trace->surfaceFlags & 0x10) {
            /* startsolid - skip */
        } else if (trace->fraction == 1.0f) {
            /* Complete miss - skip */
        } else {
            return 1;
        }
    }

    return 0;
}
#endif

/* line 102 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void Weapon_Melee(gentity_s (*ent)[16], weaponParms *wp, float range, float width, float height)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1 */
        "movl 0xc8(%edi), %eax\n" /* line 112 | ent */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x1f4(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* damage */
        "leal -0x24(%ebp), %eax\n" /* line 114 | endpos */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* tr */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* height */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* width */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* range */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* damage */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* wp */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll Melee_Trace\n"
        "testb %al, %al\n"
        "je .Lf1c5ea8_001c5f7f\n"
        "movzwl -0x2c(%ebp), %eax\n" /* line 117 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* traceEnt */
        "subl %eax, %esi\n" /* traceEnt */
        "shll $4, %esi\n" /* traceEnt */
        "addl imp_g_entities, %esi\n" /* traceEnt */
        "movl 0x158(%esi), %edx\n" /* line 129 | traceEnt */
        "testl %edx, %edx\n"
        "je .Lf1c5ea8_001c5ffc\n"
        "movl $0xad, 4(%esp)\n" /* line 130 */
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, (%esp)\n"
        "calll G_TempEntity\n"
        "movl %eax, %ebx\n" /* tent */
        ".Lf1c5ea8_001c5f47:\n"
        "movzwl -0x2c(%ebp), %eax\n" /* line 134 */
        "movl %eax, 0x74(%ebx)\n" /* tent */
        "leal -0x44(%ebp), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xa0(%ebx)\n" /* tent */
        "movl 0xc8(%edi), %eax\n" /* line 136 | ent */
        "movl %eax, 0xc8(%ebx)\n" /* tent */
        "cmpw $0x3fe, -0x2c(%ebp)\n" /* line 138 */
        "je .Lf1c5ea8_001c5f7f\n"
        "cmpb $0, 0x161(%esi)\n" /* line 141 | traceEnt */
        "jne .Lf1c5ea8_001c5f8a\n"
        /* } scope */
        ".Lf1c5ea8_001c5f7f:\n"
        "addl $0x8c, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c5ea8_001c5f8a:\n"
        "movzwl -0x28(%ebp), %ebx\n" /* line 144 | tent */
        "calll rand\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl $0, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n" /* tent */
        "movl $7, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0x66666667, %edx\n"
        "imull %edx\n"
        "sarl $1, %edx\n"
        "movl -0x5c(%ebp), %ecx\n"
        "sarl $0x1f, %ecx\n"
        "subl %ecx, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "subl %edx, -0x5c(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "addl -0x4c(%ebp), %eax\n" /* damage */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* wp */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* ent */
        "movl %edi, 4(%esp)\n" /* ent */
        "movl %esi, (%esp)\n" /* traceEnt */
        "calll G_Damage\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c5ea8_001c5ffc:\n"
        "movl $0xae, 4(%esp)\n" /* line 132 */
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, (%esp)\n"
        "calll G_TempEntity\n"
        "movl %eax, %ebx\n" /* tent */
        "jmp .Lf1c5ea8_001c5f47\n"
    );
}

/* line 819 */
__attribute__((naked))
void FireWeaponMelee(gentity_s (*ent)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 819 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "movl 0x158(%esi), %eax\n" /* line 823 | ent */
        "testl $0x300, 0xa0(%eax)\n"
        "je .Lf1c6016_001c603c\n"
        "cmpb $0, 0x162(%esi)\n" /* ent */
        "jne .Lf1c6016_001c60af\n"
        ".Lf1c6016_001c603c:\n"
        "movl 0xc8(%esi), %eax\n" /* line 827 | ent */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0xc(%ebp)\n"
        "leal -0x48(%ebp), %ebx\n" /* line 830 | wp */
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewOrigin\n"
        "leal -0x30(%ebp), %eax\n" /* line 831 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewDirection\n"
        "movl imp_player_meleeHeight, %eax\n" /* line 833 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl imp_player_meleeWidth, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_player_meleeRange, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll Weapon_Melee\n"
        /* } scope */
        ".Lf1c6016_001c60af:\n"
        "addl $0x60, %esp\n" /* line 834 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 385 */
static __attribute__((naked))
void Bullet_Fire_Extended(const gentity_t *source, gentity_s (*attacker)[16], vec_t *end, float damageMultiplier, int recursion, const weaponParms *wp, const gentity_t *weaponEnt, const int gametime)
{
    __asm__ __volatile__ (
        ".Lf1c60b6_001c60b6:\n"
        "pushl %ebp\n" /* line 385 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl %ecx, %ebx\n" /* start */
        "movl 8(%ebp), %edi\n" /* end */
        "movss %xmm0, -0x80(%ebp)\n"
        /* { scope 1: reflect */
        "cmpl $0xc, 0xc(%ebp)\n" /* line 406 | recursion */
        "jg .Lf1c60b6_001c642e\n"
        "movl 0x10(%ebp), %eax\n" /* line 412 | wp */
        "movl 0x3c(%eax), %edx\n"
        "movl 0x31c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1c60b6_001c63f9\n"
        "movl $0x20, -0x70(%ebp)\n" /* dflags */
        "movl $2, -0x6c(%ebp)\n" /* iMOD */
        "movl -0x70(%ebp), %eax\n" /* line 423 | dflags */
        "orl $2, %eax\n"
        "movl 0x320(%edx), %edx\n"
        "testl %edx, %edx\n"
        "cmovel -0x70(%ebp), %eax\n" /* dflags */
        "movl %eax, -0x70(%ebp)\n" /* dflags */
        "testl %ecx, %ecx\n" /* line 425 */
        "je .Lf1c60b6_001c6424\n"
        ".Lf1c60b6_001c611b:\n"
        "movl imp_riflePriorityMap, %eax\n"
        ".Lf1c60b6_001c6120:\n"
        "movl %eax, 0x14(%esp)\n"
        "movl $0x2802831, 0x10(%esp)\n"
        "movl -0x78(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* end */
        "movl %ebx, 4(%esp)\n" /* start */
        "leal -0x54(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "movss -0x54(%ebp), %xmm2\n" /* line 426 | tr, fraction */
        /* { scope 2 */
        "movss (%ebx), %xmm1\n" /* line 1203 | start */
        "movss (%edi), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* endpos */
        "leal 4(%edi), %eax\n" /* line 1204 | end */
        "movl %eax, -0x64(%ebp)\n"
        "leal 4(%ebx), %edx\n" /* start */
        "movl %edx, -0x68(%ebp)\n"
        "movss 4(%ebx), %xmm1\n" /* start */
        "movss 4(%edi), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "leal 8(%edi), %eax\n" /* line 1205 | end */
        "movl %eax, -0x5c(%ebp)\n"
        "leal 8(%ebx), %edx\n" /* start */
        "movl %edx, -0x60(%ebp)\n"
        "movss 8(%ebx), %xmm1\n" /* start */
        "movss 8(%edi), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movl -0x6c(%ebp), %eax\n" /* line 439 | iMOD */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* wp */
        "movl 0x3c(%edx), %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* start */
        "movl -0x7c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll G_CheckHitTriggerDamage\n"
        "movzwl -0x38(%ebp), %eax\n" /* line 441 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* traceEnt */
        "subl %eax, %esi\n" /* traceEnt */
        "shll $4, %esi\n" /* traceEnt */
        "addl imp_g_entities, %esi\n" /* traceEnt */
        /* { scope 2 */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* reflect */
        "movss 4(%edi), %xmm0\n" /* line 249 */
        "subss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 */
        "subss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 469 | reflect */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x30(%ebp), %xmm5\n" /* line 304 | reflect */
        "movss -0x50(%ebp), %xmm3\n"
        "movss -0x4c(%ebp), %xmm2\n"
        "movss -0x48(%ebp), %xmm4\n"
        "movaps %xmm5, %xmm0\n" /* line 470 */
        "mulss %xmm3, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss -0x2c(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x28(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss lit4_002ed628, %xmm0\n" /* -2.0f */
        "mulss %xmm0, %xmm3\n" /* line 288 */
        "addss %xmm3, %xmm5\n"
        "movss %xmm5, -0x30(%ebp)\n" /* reflect */
        "mulss %xmm0, %xmm2\n" /* line 289 */
        "addss -0x2c(%ebp), %xmm2\n"
        "movss %xmm2, -0x2c(%ebp)\n"
        "mulss %xmm0, %xmm4\n" /* line 290 */
        "addss -0x28(%ebp), %xmm4\n"
        "movss %xmm4, -0x28(%ebp)\n"
        "testb $4, -0x44(%ebp)\n" /* line 473 */
        "jne .Lf1c60b6_001c62aa\n"
        "movl 0x158(%esi), %eax\n" /* traceEnt */
        "testl %eax, %eax\n"
        "je .Lf1c60b6_001c65a1\n"
        /* } scope */
        ".Lf1c60b6_001c62aa:\n"
        "testb $0x10, -0x40(%ebp)\n" /* line 493 */
        "jne .Lf1c60b6_001c6445\n"
        "cmpb $0, 0x161(%esi)\n" /* line 522 | traceEnt */
        "je .Lf1c60b6_001c63ee\n"
        "cmpl %esi, -0x7c(%ebp)\n" /* traceEnt */
        "je .Lf1c60b6_001c63ee\n"
        "movss (%ebx), %xmm0\n" /* line 248 */
        "subss -0x24(%ebp), %xmm0\n" /* endpos */
        "movl -0x68(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm1\n"
        "subss -0x20(%ebp), %xmm1\n"
        "movl -0x60(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm2\n"
        "subss -0x1c(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %edx\n" /* line 263 | wp */
        "movl 0x3c(%edx), %eax\n"
        "movss 0x598(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1c60b6_001c6533\n"
        ".Lf1c60b6_001c631a:\n"
        "movl 0x1ec(%eax), %edx\n" /* line 274 */
        /* } scope */
        ".Lf1c60b6_001c6320:\n"
        "movl imp_level, %eax\n" /* line 529 */
        "movl 0x1ec(%eax), %eax\n"
        "subl 0x18(%ebp), %eax\n" /* gametime */
        "movl %eax, 0x24(%esp)\n"
        "movzwl -0x34(%ebp), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl -0x6c(%ebp), %eax\n" /* iMOD */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x70(%ebp), %eax\n" /* dflags */
        "movl %eax, 0x18(%esp)\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss -0x80(%ebp), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* endpos */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* wp */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* traceEnt */
        "calll G_Damage\n"
        "movl 0x158(%esi), %ecx\n" /* line 533 | traceEnt */
        "testl %ecx, %ecx\n"
        "je .Lf1c60b6_001c63ee\n"
        "testb $0x20, -0x70(%ebp)\n" /* line 535 | dflags */
        "je .Lf1c60b6_001c63ee\n"
        "movl $str_002ab4f0, (%esp)\n" /* line 537 */
        "calll Dvar_GetInt\n"
        "testl %eax, %eax\n"
        "jne .Lf1c60b6_001c63ad\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* traceEnt */
        "calll OnSameTeam\n"
        "testl %eax, %eax\n"
        "jne .Lf1c60b6_001c63ee\n"
        ".Lf1c60b6_001c63ad:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 540 */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, -0x80(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* gametime */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* weaponEnt */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* wp */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* recursion */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* end */
        "leal -0x24(%ebp), %ecx\n" /* endpos */
        "movl -0x7c(%ebp), %edx\n"
        "movl %esi, %eax\n" /* traceEnt */
        "calll Bullet_Fire_Extended\n"
        /* } scope */
        ".Lf1c60b6_001c63ee:\n"
        "addl $0xac, %esp\n" /* line 545 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: reflect */
        ".Lf1c60b6_001c63f9:\n"
        "movl $0, -0x70(%ebp)\n" /* line 412 | dflags */
        "movl $1, -0x6c(%ebp)\n" /* iMOD */
        "movl -0x70(%ebp), %eax\n" /* line 423 | dflags */
        "orl $2, %eax\n"
        "movl 0x320(%edx), %edx\n"
        "testl %edx, %edx\n"
        "cmovel -0x70(%ebp), %eax\n" /* dflags */
        "movl %eax, -0x70(%ebp)\n" /* dflags */
        "testl %ecx, %ecx\n" /* line 425 */
        "jne .Lf1c60b6_001c611b\n"
        ".Lf1c60b6_001c6424:\n"
        "movl imp_bulletPriorityMap, %eax\n"
        "jmp .Lf1c60b6_001c6120\n"
        ".Lf1c60b6_001c642e:\n"
        "movl $str_002b6990, (%esp)\n" /* line 408 */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 545 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: reflect */
        /* { scope 2 */
        ".Lf1c60b6_001c6445:\n"
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* reflect */
        "movl -0x64(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm0\n"
        "movl -0x68(%ebp), %edx\n"
        "subss (%edx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n" /* line 250 */
        "movss (%eax), %xmm0\n"
        "movl -0x60(%ebp), %edx\n"
        "subss (%edx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 500 | reflect */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x30(%ebp), %xmm3\n" /* line 304 | reflect */
        "movaps %xmm3, %xmm1\n" /* line 501 */
        "mulss -0x50(%ebp), %xmm1\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x48(%ebp), %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "xorps traceOffsets+48, %xmm1\n"
        "pxor %xmm2, %xmm2\n" /* line 502 */
        "ucomiss lit4_002ed610, %xmm1\n" /* 0.125f */
        "jae .Lf1c60b6_001c6590\n"
        ".Lf1c60b6_001c64c6:\n"
        "mulss %xmm2, %xmm3\n" /* line 288 */
        "addss -0x24(%ebp), %xmm3\n" /* endpos */
        "movss %xmm3, (%ebx)\n"
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "mulss -0x28(%ebp), %xmm2\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm2\n"
        "movss %xmm2, 8(%ebx)\n"
        "movl 0x18(%ebp), %edx\n" /* line 505 | gametime */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* weaponEnt */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* wp */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* recursion */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* end */
        "movss -0x80(%ebp), %xmm0\n"
        "movl %ebx, %ecx\n" /* start */
        "movl -0x7c(%ebp), %edx\n"
        "movl -0x78(%ebp), %eax\n"
        "calll Bullet_Fire_Extended\n"
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 545 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: reflect */
        /* { scope 2 */
        ".Lf1c60b6_001c6533:\n"
        "movss 0x59c(%eax), %xmm2\n" /* line 268 */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf1c60b6_001c6631\n"
        "subss %xmm0, %xmm2\n" /* line 271 */
        "ucomiss lit4_002ed5e8, %xmm2\n" /* line 272 | 0.0f */
        "jne .Lf1c60b6_001c6557\n"
        "jnp .Lf1c60b6_001c631a\n"
        ".Lf1c60b6_001c6557:\n"
        "subss %xmm0, %xmm1\n" /* line 278 */
        "divss %xmm2, %xmm1\n"
        "cvtsi2ssl 0x1ec(%eax), %xmm2\n" /* line 283 */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "cvtsi2ssl 0x590(%eax), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "cvttss2si %xmm2, %edx\n"
        "jmp .Lf1c60b6_001c6320\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1c60b6_001c6590:\n"
        "movss lit4_002ed604, %xmm2\n" /* line 502 | 0.25f */
        "divss %xmm1, %xmm2\n"
        "jmp .Lf1c60b6_001c64c6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1c60b6_001c65a1:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 473 | 1.0f */
        "ucomiss -0x54(%ebp), %xmm0\n" /* tr */
        "jbe .Lf1c60b6_001c62aa\n"
        "movl 0x10(%ebp), %edx\n" /* line 482 | wp */
        "movl 0x3c(%edx), %eax\n"
        "cmpl $1, 0x31c(%eax)\n"
        "sbbl %eax, %eax\n"
        "addl $0xb7, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* endpos */
        "movl %eax, (%esp)\n"
        "calll G_TempEntity\n"
        "movl %eax, -0x74(%ebp)\n" /* tent */
        "leal -0x50(%ebp), %eax\n" /* line 483 */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl -0x74(%ebp), %edx\n" /* tent */
        "movl %eax, 0xa0(%edx)\n"
        "leal -0x30(%ebp), %eax\n" /* line 484 | reflect */
        "movl %eax, (%esp)\n"
        "calll DirToByte\n"
        "movzbl %al, %eax\n"
        "movl -0x74(%ebp), %edx\n" /* tent */
        "movl %eax, 0xd8(%edx)\n"
        "cmpl $2, 4(%esi)\n" /* line 485 | traceEnt */
        "je .Lf1c60b6_001c663c\n"
        "movl -0x44(%ebp), %eax\n"
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        ".Lf1c60b6_001c6618:\n"
        "movl -0x74(%ebp), %edx\n" /* tent */
        "movl %eax, 0x88(%edx)\n"
        "movl 0x14(%ebp), %edx\n" /* line 486 | weaponEnt */
        "movl (%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n" /* tent */
        "movl %eax, 0x74(%edx)\n"
        "jmp .Lf1c60b6_001c62aa\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1c60b6_001c6631:\n"
        "movl 0x590(%eax), %edx\n" /* line 289 */
        "jmp .Lf1c60b6_001c6320\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1c60b6_001c663c:\n"
        "movl $7, %eax\n" /* line 485 */
        "jmp .Lf1c60b6_001c6618\n"
    );
}

/* line 939 */
__attribute__((naked))
void G_SetupWeaponDef(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 939 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $str_0021742c, (%esp)\n" /* line 941 */
        "calll Com_DPrintf\n"
        "movl $str_002b69cc, (%esp)\n" /* line 942 */
        "calll Com_DPrintf\n"
        "movl imp_bg_iNumWeapons, %eax\n" /* line 944 */
        "movl (%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf1c6644_001c6680\n"
        "movl $str_0021742c, (%esp)\n" /* line 954 */
        "calll Com_DPrintf\n"
        "addl $0x14, %esp\n" /* line 955 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1c6644_001c6680:\n"
        "calll SV_SetWeaponInfoMemory\n" /* line 946 */
        "calll ClearRegisteredItems\n" /* line 947 */
        "calll BG_ClearWeaponDef\n" /* line 948 */
        "movl imp_G_RegisterWeapon, %ebx\n" /* line 950 */
        "movl %ebx, (%esp)\n"
        "calll BG_FillInAmmoItems\n"
        "movl imp_level, %eax\n" /* line 965 */
        "movl 0x1c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1c6644_001c66cb\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_0021ca4c, (%esp)\n" /* "defaultweapon_mp" */
        "calll BG_GetWeaponIndexForName\n"
        "movl $str_0021742c, (%esp)\n" /* line 954 */
        "calll Com_DPrintf\n"
        "addl $0x14, %esp\n" /* line 955 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1c6644_001c66cb:\n"
        "movl $str_0021ca4c, (%esp)\n" /* line 965 */
        "calll BG_FindWeaponIndexForName\n"
        "movl $str_0021742c, (%esp)\n" /* line 954 */
        "calll Com_DPrintf\n"
        "addl $0x14, %esp\n" /* line 955 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 219 */
__attribute__((naked))
void Bullet_Endpos(float spread, vec_t *end, const weaponParms *wp, float maxRange)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 219 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* end */
        "movl 0x10(%ebp), %esi\n" /* wp */
        /* { scope 1: r */
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 228 | spread */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll tan\n"
        "fstpl -0x20(%ebp)\n"
        "cvtsd2ss -0x20(%ebp), %xmm0\n"
        "mulss 0x14(%ebp), %xmm0\n" /* maxRange */
        "movss %xmm0, -0x14(%ebp)\n" /* aimOffset */
        /* { scope 2 */
        "calll randomf\n" /* line 203 */
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n" /* line 204 */
        "calll randomf\n"
        "fstps -0x10(%ebp)\n" /* r */
        "movss -0x38(%ebp), %xmm0\n" /* line 205 */
        "mulss lit4_002ed638, %xmm0\n" /* 360.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "movss %xmm0, (%esp)\n" /* line 486 */
        "calll cosf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "mulss -0x10(%ebp), %xmm1\n" /* r */
        "mulss -0x14(%ebp), %xmm1\n" /* aimOffset */
        "movss -0xc(%ebp), %xmm0\n" /* line 485 */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll sinf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm2\n"
        "mulss -0x10(%ebp), %xmm2\n" /* r */
        "mulss -0x14(%ebp), %xmm2\n" /* aimOffset */
        "leal 0x24(%esi), %eax\n" /* line 243 | wp, start */
        /* { scope 2 */
        "movss 0x14(%ebp), %xmm0\n" /* line 288 | maxRange */
        "mulss (%esi), %xmm0\n" /* wp */
        "addss 0x24(%esi), %xmm0\n" /* wp */
        "movss %xmm0, (%ebx)\n" /* end */
        "movss 0x14(%ebp), %xmm0\n" /* line 289 | maxRange */
        "mulss 4(%esi), %xmm0\n" /* wp */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* end */
        "movss 0x14(%ebp), %xmm0\n" /* line 290 | maxRange */
        "mulss 8(%esi), %xmm0\n" /* wp */
        "movss %xmm0, 0x14(%ebp)\n" /* maxRange */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n" /* end */
        /* } scope */
        "leal 0xc(%esi), %eax\n" /* line 247 | wp, dir */
        /* { scope 2 */
        "movss -0x48(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0xc(%esi), %xmm0\n" /* wp */
        "addss (%ebx), %xmm0\n" /* end */
        "movss %xmm0, (%ebx)\n" /* end */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ebx), %xmm0\n" /* end */
        "movss %xmm0, 4(%ebx)\n" /* end */
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%ebx), %xmm1\n" /* end */
        "movss %xmm1, 8(%ebx)\n" /* end */
        /* } scope */
        "leal 0x18(%esi), %eax\n" /* line 248 | wp, dir */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 288 */
        "mulss 0x18(%esi), %xmm0\n" /* wp */
        "addss (%ebx), %xmm0\n" /* end */
        "movss %xmm0, (%ebx)\n" /* end */
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ebx), %xmm0\n" /* end */
        "movss %xmm0, 4(%ebx)\n" /* end */
        "mulss 8(%eax), %xmm2\n" /* line 290 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, 8(%ebx)\n" /* end */
        /* } scope */
        /* } scope */
        "addl $0x60, %esp\n" /* line 251 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 579 */
__attribute__((naked))
void Bullet_Fire(gentity_s (*attacker)[16], float spread, weaponParms *wp, gentity_s (*weaponEnt)[16], int gametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 579 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3ac, %esp\n"
        /* { scope 1: client, clientPosition, start */
        /* { scope 2 */
        "movl imp_g_antilag, %eax\n" /* line 305 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1c6854_001c6a2a\n"
        /* } scope */
        ".Lf1c6854_001c6871:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 587 | wp, shotIndex */
        "movl 0x3c(%ebx), %ecx\n" /* shotIndex */
        "cmpl $3, 0x7c(%ecx)\n"
        "je .Lf1c6854_001c698c\n"
        "movl $0x46000000, 0xc(%esp)\n" /* line 594 */
        "movl %ebx, 8(%esp)\n" /* shotIndex */
        "leal -0x24(%ebp), %ebx\n" /* end, shotIndex */
        "movl %ebx, 4(%esp)\n" /* shotIndex */
        "movss 0xc(%ebp), %xmm0\n" /* spread */
        "movss %xmm0, (%esp)\n"
        "calll Bullet_Endpos\n"
        "movl 0x10(%ebp), %ecx\n" /* line 595 | wp */
        "addl $0x24, %ecx\n"
        "movl 0x18(%ebp), %eax\n" /* gametime */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* weaponEnt */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edi\n" /* wp, client */
        "movl %edi, 8(%esp)\n" /* client */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* shotIndex */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movl 8(%ebp), %edx\n" /* attacker */
        "movl 0x14(%ebp), %eax\n" /* weaponEnt */
        "calll Bullet_Fire_Extended\n"
        /* { scope 2 */
        ".Lf1c6854_001c68dc:\n"
        "movl imp_g_antilag, %eax\n" /* line 355 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1c6854_001c6981\n"
        "movl imp_level, %ebx\n" /* line 358 */
        "movl 0x1e4(%ebx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf1c6854_001c6981\n"
        "xorl %edi, %edi\n" /* client */
        "jmp .Lf1c6854_001c6910\n"
        ".Lf1c6854_001c6905:\n"
        "addl $1, %edi\n" /* client */
        "cmpl 0x1e4(%ebx), %edi\n" /* client */
        "jge .Lf1c6854_001c6981\n"
        ".Lf1c6854_001c6910:\n"
        "cmpb $0, -0x7c(%ebp, %edi)\n" /* line 360 */
        "je .Lf1c6854_001c6905\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 362 | client */
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "movl imp_g_entities, %esi\n"
        "leal (%ebx, %esi), %eax\n"
        "movl %eax, -0x390(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll SV_UnlinkEntity\n"
        "leal 0x130(%ebx, %esi), %ebx\n" /* line 366 */
        "leal 8(%ebx), %ecx\n"
        "leal (%edi, %edi, 2), %eax\n" /* client */
        "leal -0x37c(%ebp, %eax, 4), %eax\n"
        "movl (%eax), %edx\n"
        "movl %edx, 8(%ebx)\n"
        "movl 4(%eax), %edx\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl -0x390(%ebp), %edx\n" /* line 368 */
        "movl %edx, (%esp)\n"
        "calll SV_LinkEntity\n"
        "movl imp_level, %ebx\n"
        "addl $1, %edi\n" /* line 358 | client */
        "cmpl 0x1e4(%ebx), %edi\n" /* client */
        "jl .Lf1c6854_001c6910\n"
        /* } scope */
        /* } scope */
        ".Lf1c6854_001c6981:\n"
        "addl $0x3ac, %esp\n" /* line 599 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: client, clientPosition, start */
        /* { scope 2 */
        ".Lf1c6854_001c698c:\n"
        "movl %ebx, %edx\n" /* line 562 | shotIndex, from */
        "addl $0x24, %edx\n" /* from */
        /* { scope 3 */
        "movl 0x24(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x3c(%ebp)\n" /* start */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 564 */
        "movl 0x1dc(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1c6854_001c68dc\n"
        "xorl %ebx, %ebx\n" /* shotIndex */
        "leal -0x30(%ebp), %esi\n" /* clientPosition */
        "leal -0x3c(%ebp), %edi\n" /* start, client */
        ".Lf1c6854_001c69bb:\n"
        "movl 0x59c(%eax), %eax\n" /* line 566 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* wp */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* spread */
        "movss %xmm0, (%esp)\n"
        "calll Bullet_Endpos\n"
        "movl 0x18(%ebp), %eax\n" /* line 567 | gametime */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* weaponEnt */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* wp */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movl %edi, %ecx\n" /* client */
        "movl 8(%ebp), %edx\n" /* attacker */
        "movl 0x14(%ebp), %eax\n" /* weaponEnt */
        "calll Bullet_Fire_Extended\n"
        "addl $1, %ebx\n" /* line 564 | shotIndex */
        "movl 0x10(%ebp), %edx\n" /* wp */
        "movl 0x3c(%edx), %eax\n"
        "cmpl 0x1dc(%eax), %ebx\n" /* shotIndex */
        "jl .Lf1c6854_001c69bb\n"
        "jmp .Lf1c6854_001c68dc\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1c6854_001c6a2a:\n"
        "movl $0x340, 8(%esp)\n" /* line 308 */
        "movl $0, 4(%esp)\n"
        "leal -0x37c(%ebp), %eax\n" /* antilagClients */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl imp_level, %ebx\n" /* line 311 */
        "movl 0x1ec(%ebx), %ecx\n"
        "subl 0x18(%ebp), %ecx\n" /* gametime */
        "movl imp_sv_fps, %eax\n"
        "movl (%eax), %esi\n"
        "movl $0x3e8, %eax\n"
        "cltd\n"
        "idivl 8(%esi)\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf1c6854_001c6871\n"
        "movl 0x1e4(%ebx), %edi\n" /* line 314 */
        "testl %edi, %edi\n"
        "jle .Lf1c6854_001c6871\n"
        "movl $0, -0x394(%ebp)\n" /* client */
        "movl $0, -0x38c(%ebp)\n"
        "jmp .Lf1c6854_001c6ab6\n"
        ".Lf1c6854_001c6a93:\n"
        "addl $1, -0x394(%ebp)\n" /* client */
        "addl $0x28a4, -0x38c(%ebp)\n"
        "movl -0x394(%ebp), %edx\n" /* client */
        "cmpl 0x1e4(%ebx), %edx\n"
        "jge .Lf1c6854_001c6871\n"
        ".Lf1c6854_001c6ab6:\n"
        "movl -0x38c(%ebp), %eax\n" /* line 316 */
        "addl (%ebx), %eax\n"
        "cmpl $2, 0x26c4(%eax)\n"
        "jne .Lf1c6854_001c6a93\n"
        "movl 0x26a8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1c6854_001c6a93\n"
        "leal -0x30(%ebp), %esi\n" /* line 319 | clientPosition */
        "movl %esi, 8(%esp)\n"
        "movl 0x18(%ebp), %ebx\n" /* gametime */
        "movl %ebx, 4(%esp)\n"
        "movl -0x394(%ebp), %edi\n" /* client */
        "movl %edi, (%esp)\n"
        "calll SV_GetClientPositionAtTime\n"
        "testb %al, %al\n"
        "jne .Lf1c6854_001c6af9\n"
        "movl imp_level, %ebx\n"
        "jmp .Lf1c6854_001c6a93\n"
        ".Lf1c6854_001c6af9:\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 326 */
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "movl imp_g_entities, %ecx\n"
        "leal 0x130(%ebx, %ecx), %esi\n"
        "leal 8(%esi), %eax\n"
        "movl %eax, -0x398(%ebp)\n"
        "leal (%edi, %edi, 2), %edx\n"
        "leal -0x37c(%ebp, %edx, 4), %edx\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, (%edx)\n"
        "movl -0x398(%ebp), %edi\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, 8(%edx)\n"
        "addl %ecx, %ebx\n" /* line 331 */
        "movl %ebx, (%esp)\n"
        "calll SV_UnlinkEntity\n"
        "movl -0x30(%ebp), %eax\n" /* line 334 | clientPosition */
        "movl %eax, 8(%esi)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl %ebx, (%esp)\n" /* line 337 */
        "calll SV_LinkEntity\n"
        "movl -0x394(%ebp), %eax\n" /* line 340 | client */
        "movb $1, -0x7c(%ebp, %eax)\n"
        "movl imp_level, %ebx\n"
        "jmp .Lf1c6854_001c6a93\n"
    );
}

/* line 739 */
__attribute__((naked))
void FireWeaponAntiLag(gentity_s (*ent)[16], int gametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 739 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x90, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1: viewang */
        "movl 0x158(%ebx), %eax\n" /* line 748 | ent */
        "testl $0x300, 0xa0(%eax)\n"
        "je .Lf1c6b7a_001c6ba7\n"
        "cmpb $0, 0x162(%ebx)\n" /* ent */
        "jne .Lf1c6b7a_001c6cb6\n"
        ".Lf1c6b7a_001c6ba7:\n"
        "movl 0xc8(%ebx), %eax\n" /* line 752 | ent */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x158(%ebx), %edx\n" /* ent */
        "leal 0xe8(%edx), %ecx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xe8(%edx), %eax\n" /* line 199 */
        "movl %eax, -0x1c(%ebp)\n" /* viewang */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x18(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x14(%ebp)\n"
        /* } scope */
        "movl 0x27d8(%edx), %eax\n" /* line 725 */
        "movl %eax, -0x1c(%ebp)\n" /* viewang */
        "movl 0x27dc(%edx), %eax\n" /* line 726 */
        "movl %eax, -0x18(%ebp)\n"
        "leal -0x5c(%ebp), %esi\n" /* line 729 | wp */
        "leal -0x44(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x50(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* viewang */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal -0x38(%ebp), %eax\n" /* line 731 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_GetPlayerViewOrigin\n"
        /* } scope */
        "movl 0x158(%ebx), %edx\n" /* line 757 | ent */
        "movss 0x2810(%edx), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n" /* aimSpreadScale */
        "leal -0x10(%ebp), %eax\n" /* line 759 | maxSpread */
        "movl %eax, 0xc(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* minSpread */
        "movl %eax, 8(%esp)\n"
        "movl 0xc8(%ebx), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll BG_GetSpreadForWeapon\n"
        "movl 0x158(%ebx), %eax\n" /* line 762 | ent */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss 0xdc(%eax), %xmm0\n"
        "jne .Lf1c6b7a_001c6cc0\n"
        "jp .Lf1c6b7a_001c6cc0\n"
        "movl -0x20(%ebp), %eax\n" /* line 763 */
        "movss 0x4bc(%eax), %xmm0\n"
        "movss -0x10(%ebp), %xmm1\n" /* maxSpread */
        "subss %xmm0, %xmm1\n"
        "mulss -0x6c(%ebp), %xmm1\n" /* aimSpreadScale */
        "addss %xmm0, %xmm1\n"
        "movl 0x78(%eax), %edx\n" /* line 768 */
        "testl %edx, %edx\n"
        "je .Lf1c6b7a_001c6ce1\n"
        ".Lf1c6b7a_001c6c8a:\n"
        "cmpl $1, %edx\n" /* line 772 */
        "je .Lf1c6b7a_001c6d24\n"
        "cmpl $2, %edx\n" /* line 776 */
        "je .Lf1c6b7a_001c6d08\n"
        "movl (%eax), %eax\n" /* line 782 */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $str_002b69e4, 4(%esp)\n" /* "Unknown weapon type %i for %s
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf1c6b7a_001c6cb6:\n"
        "addl $0x90, %esp\n" /* line 784 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: viewang */
        ".Lf1c6b7a_001c6cc0:\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 765 | minSpread */
        "movss -0x10(%ebp), %xmm1\n" /* maxSpread */
        "subss %xmm0, %xmm1\n"
        "mulss -0x6c(%ebp), %xmm1\n" /* aimSpreadScale */
        "addss %xmm0, %xmm1\n"
        "movl -0x20(%ebp), %eax\n"
        "movl 0x78(%eax), %edx\n" /* line 768 */
        "testl %edx, %edx\n"
        "jne .Lf1c6b7a_001c6c8a\n"
        ".Lf1c6b7a_001c6ce1:\n"
        "movl 0xc(%ebp), %eax\n" /* line 770 | gametime */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* ent */
        "movl %esi, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll Bullet_Fire\n"
        /* } scope */
        "addl $0x90, %esp\n" /* line 784 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: viewang */
        ".Lf1c6b7a_001c6d08:\n"
        "movl %esi, 8(%esp)\n" /* line 778 */
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll Weapon_RocketLauncher_Fire\n"
        /* } scope */
        "addl $0x90, %esp\n" /* line 784 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: viewang */
        ".Lf1c6b7a_001c6d24:\n"
        "movl %esi, 8(%esp)\n" /* line 774 */
        "movl 0xc8(%ebx), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll weapon_grenadelauncher_fire\n"
        "jmp .Lf1c6b7a_001c6cb6\n"
    );
}

/* line 845 */
__attribute__((naked))
qboolean G_GivePlayerWeapon(playerState_t *pPS, int iWeaponIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 845 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* pPS */
        /* { scope 1 */
        "leal 0x544(%edi), %eax\n" /* line 856 | pPS */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* line 807 | iWeaponIndex */
        "sarl $5, %eax\n"
        "leal (, %eax, 4), %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* iWeaponIndex */
        "andl $0x1f, %esi\n"
        "movl 0x544(%edi, %ebx), %eax\n" /* line 856 | pPS */
        "movl %esi, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1c6d42_001c6d83\n"
        ".Lf1c6d42_001c6d79:\n"
        "xorl %eax, %eax\n" /* line 919 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 927 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c6d42_001c6d83:\n"
        "movl 0xc(%ebp), %eax\n" /* line 859 | iWeaponIndex */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edx\n"
        "movl 0x7c(%eax), %eax\n" /* line 860 */
        "cmpl $7, %eax\n"
        "je .Lf1c6d42_001c6d79\n"
        "cmpl $8, %eax\n" /* line 863 */
        "je .Lf1c6d42_001c6d79\n"
        "movl $1, %eax\n" /* line 812 */
        "movl %esi, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x20(%ebp), %ecx\n"
        "orl %eax, (%ecx, %ebx)\n"
        "leal 0x55c(%edi, %ebx), %ebx\n" /* line 817 */
        "movl %ebx, -0x1c(%ebp)\n"
        "movl %eax, %esi\n"
        "notl %esi\n"
        "andl %esi, (%ebx)\n"
        "cmpl $9, 0x7c(%edx)\n" /* line 871 */
        "je .Lf1c6d42_001c6e18\n"
        "movl 0x84(%edx), %ebx\n" /* line 875 */
        "testl %ebx, %ebx\n"
        "je .Lf1c6d42_001c6e25\n"
        "movl 0xd0(%edi), %eax\n" /* line 877 | pPS */
        "testl %eax, %eax\n"
        "jne .Lf1c6d42_001c6ed0\n"
        "movl 0xc(%ebp), %ebx\n" /* line 879 | iWeaponIndex */
        "movl %ebx, 0xd0(%edi)\n" /* pPS */
        "movl 0xcc(%edi), %ebx\n" /* line 880 | pPS, clientNum */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 987 | iWeaponIndex */
        /* } scope */
        /* { scope 2 */
        ".Lf1c6d42_001c6dec:\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x43, 4(%esp)\n"
        "movl $str_002b1d38, (%esp)\n" /* "%c %i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* clientNum */
        "calll SV_GameSendServerCommand\n"
        ".Lf1c6d42_001c6e18:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf1c6d42_001c6e1d:\n"
        "addl $0x3c, %esp\n" /* line 927 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c6d42_001c6e25:\n"
        "movl 0x80(%edx), %eax\n" /* line 902 */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf1c6d42_001c6e53\n"
        "cmpb $0, 0x555(%edi)\n" /* line 907 | pPS */
        "je .Lf1c6d42_001c6f1b\n"
        "cmpb $0, 0x556(%edi)\n" /* line 909 | pPS */
        "jne .Lf1c6d42_001c6e53\n"
        "movzbl 0xc(%ebp), %ebx\n" /* line 910 | iWeaponIndex, clientNum */
        "movb %bl, 0x556(%edi)\n" /* clientNum, pPS */
        ".Lf1c6d42_001c6e53:\n"
        "movl 0x36c(%edx), %edx\n" /* line 918 */
        "testl %edx, %edx\n" /* line 919 */
        "je .Lf1c6d42_001c6e18\n"
        "movl %edx, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, %ebx\n"
        "andl $0x1f, %ebx\n"
        "movl -0x20(%ebp), %ecx\n" /* line 919 */
        "movl (%ecx, %eax), %eax\n"
        "movl %ebx, %ecx\n" /* clientNum */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1c6d42_001c6e18\n"
        ".Lf1c6d42_001c6e7b:\n"
        "movl $1, %eax\n" /* line 812 */
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x20(%ebp), %ebx\n"
        "movl -0x2c(%ebp), %edi\n"
        "orl %eax, (%ebx, %edi)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 817 */
        "andl %esi, (%eax)\n"
        "movl %edx, (%esp)\n" /* line 923 */
        "calll BG_GetWeaponDef\n"
        "movl 0x36c(%eax), %edx\n"
        "testl %edx, %edx\n" /* line 919 */
        "je .Lf1c6d42_001c6e18\n"
        "movl %edx, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, %ebx\n"
        "andl $0x1f, %ebx\n"
        "movl -0x20(%ebp), %edi\n" /* line 919 | pPS */
        "movl (%edi, %eax), %eax\n" /* pPS */
        "movl %ebx, %ecx\n" /* clientNum */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1c6d42_001c6e7b\n"
        /* { scope 2 */
        "movl $1, %eax\n" /* line 987 */
        "jmp .Lf1c6d42_001c6e1d\n"
        /* } scope */
        ".Lf1c6d42_001c6ed0:\n"
        "movl %eax, 4(%esp)\n" /* line 882 */
        "movl %edi, (%esp)\n" /* pPS */
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "jg .Lf1c6d42_001c6e18\n"
        "movl 0xd0(%edi), %eax\n" /* line 884 | pPS */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x84(%eax), %eax\n" /* line 887 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pPS */
        "calll BG_GetFirstAvailableOffhand\n"
        "testl %eax, %eax\n" /* line 890 */
        "cmovel 0xc(%ebp), %eax\n" /* iWeaponIndex */
        "movl %eax, 0xd0(%edi)\n" /* pPS */
        "movl 0xcc(%edi), %ebx\n" /* line 894 | pPS, clientNum */
        "jmp .Lf1c6d42_001c6dec\n"
        ".Lf1c6d42_001c6f1b:\n"
        "movzbl 0xc(%ebp), %ecx\n" /* line 908 | iWeaponIndex */
        "movb %cl, 0x555(%edi)\n" /* pPS */
        "jmp .Lf1c6d42_001c6e53\n"
    );
}

#else
void Weapon_Melee(gentity_s (*ent)[16], weaponParms *wp, float range, float width, float height) {
    int damage;
    trace_t tr;
    vec3_t endpos;
    gentity_t *traceEnt;
    gentity_t *tent;
    int traceEntNum;
    int weaponIndex;

    /* Get melee damage from weapon def */
    weaponIndex = ((gentity_t *)ent)->s.weapon;
    damage = ((WeaponDef *)BG_GetWeaponDef(weaponIndex))->iMeleeDamage;

    if (!Melee_Trace(ent, wp, damage, range, width, height, &tr, endpos))
        return;

    /* Get trace entity */
    traceEntNum = tr.entityNum;
    traceEnt = (gentity_t *)((byte *)imp_g_entities + traceEntNum * 0x230);

    /* Create temp entity for melee effect */
    if (traceEnt->client != NULL) {
        /* Hit a player - blood effect */
        tent = (gentity_t *)G_TempEntity(endpos, 0xad);
    } else {
        /* Hit world/object - impact effect */
        tent = (gentity_t *)G_TempEntity(endpos, 0xae);
    }

    /* Set tent fields */
    tent->s.otherEntityNum = traceEntNum;

    /* DirToByte from trace normal */
    {
        int dirByte = DirToByte(tr.normal);
        tent->s.eventParm = (unsigned char)dirByte;
    }

    /* Copy weapon index */
    tent->s.weapon = ((gentity_t *)ent)->s.weapon;

    /* Check if hit world entity */
    if (traceEntNum == 0x3fe)
        return;

    /* Check if trace entity takes damage */
    if (!traceEnt->takedamage)
        return;

    /* Apply damage */
    {
        int locBits = tr.partGroup;
        int randVal = rand();
        int dmg = damage + (randVal % 5);
        G_Damage(traceEnt, (gentity_t *)ent, (gentity_t *)ent, wp, endpos, dmg, 7, 0, locBits, 0);
    }
}
#endif
