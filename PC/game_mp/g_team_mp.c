/* Converted to C from ASM: g_team_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_team_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern void G_GetPlayerViewOrigin(gentity_t *ent, vec3_t origin);
extern void G_GetPlayerViewDirection(gentity_t *ent, vec3_t forward, vec3_t right, vec3_t up);
extern void G_TraceCapsule(trace_t *trace, vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, int passEntityNum, int contentMask);
extern int G_IsPlaying(gentity_t *ent);

extern byte *g_entities_ptr; /* 0x195f688 */
extern byte *level_ptr;      /* 0x195f6a0 */
extern byte *sv_maxclients;  /* 0x195f6c0 */
extern vec3_t *trace_mins;   /* 0x195ed4c */

qboolean OnSameTeam(gentity_t *ent1, gentity_t *ent2);
short int TeamplayInfoMessage(gentity_t *ent);
short int CheckTeamStatus(void);

/* line 11 */
qboolean OnSameTeam(gentity_t *ent1, gentity_t *ent2)
{
    gclient_t *cl1;
    gclient_t *cl2;
    int team1;

    cl1 = ent1->client;
    if (!cl1)
        return 0;

    cl2 = ent2->client;
    if (!cl2)
        return 0;

    team1 = *(int *)((byte *)cl1 + 0x274c);
    if (team1 == 0)
        return 0;

    if (team1 == *(int *)((byte *)cl2 + 0x274c))
        return 1;

    return 0;
}

/* line 37 */
short int TeamplayInfoMessage(gentity_t *ent)
{
    gclient_t *client;
    vec3_t vStart;
    vec3_t vForward;
    vec3_t vEnd;
    trace_t trace;
    int identEnt;
    int compassTime;
    byte *identGentBase;
    gclient_t *identClient;

    client = ent->client;

    if (*(int *)((byte *)client + 0x26a8) != 0) {
        /* Binocular/spectator path */
        G_GetPlayerViewOrigin(ent, vStart);
        G_GetPlayerViewDirection(ent, vForward, NULL, NULL);

        /* Adjust vStart.z if viewHeightCurrent < 8.0 */
        if (client->ps.viewHeightCurrent < 8.0f) {
            vStart[2] += 8.0f - client->ps.viewHeightCurrent;
        }
    } else if (*(int *)((byte *)client + 0x274c) != 0) {
        /* Team path */
        G_GetPlayerViewOrigin(ent, vStart);
        G_GetPlayerViewDirection(ent, vForward, NULL, NULL);
    } else {
        /* No team */
        *(int *)((byte *)client + 0x138) = -1;
        *(int *)((byte *)client + 0x13c) = 0;
        return 0;
    }

    /* Compute vEnd = vStart + vForward * 8192.0 */
    vEnd[0] = vStart[0] + vForward[0] * 8192.0f;
    vEnd[1] = vStart[1] + vForward[1] * 8192.0f;
    vEnd[2] = vStart[2] + vForward[2] * 8192.0f;

    /* Trace forward */
    G_TraceCapsule(&trace, vStart, (vec_t *)trace_mins, (vec_t *)trace_mins, vEnd, client->ps.clientNum, 0x2000001);

    identEnt = trace.entityNum;

    if (identEnt <= 63) {
        identGentBase = g_entities_ptr + identEnt * 0x230;
        identClient = *(gclient_t **)(identGentBase + 0x158);

        if (identClient != NULL) {
            if (!G_IsPlaying(ent)) {
                /* Not playing (spectating) - show health regardless of team */
                compassTime = *(int *)(identGentBase + 0x194);
                goto store;
            }

            /* Check if same team */
            if (*(int *)((byte *)identClient + 0x274c) == *(int *)((byte *)client + 0x274c)) {
                compassTime = *(int *)(identGentBase + 0x194);
                goto store;
            }
        }
    }

    identEnt = -1;
    compassTime = 0;

store:
    client = ent->client;
    *(int *)((byte *)client + 0x138) = identEnt;
    client = ent->client;
    *(int *)((byte *)client + 0x13c) = compassTime;
    return 0;
}

/* line 90 */
short int CheckTeamStatus(void)
{
    byte *level;
    int time;
    int lastTime;
    int maxClients;
    int i;
    byte *entBase;
    byte *sessCheck;
    gclient_t *cl;

    level = *(byte **)&level_ptr;
    time = *(int *)(level + 0x1ec);
    lastTime = *(int *)(level + 0x20c);

    if (time - lastTime <= 0)
        return 0;

    *(int *)(level + 0x20c) = time;

    maxClients = *(int *)(*(int *)sv_maxclients + 8);
    if (maxClients <= 0)
        return 0;

    for (i = 0; i < maxClients; i++) {
        entBase = g_entities_ptr + i * 0x230;
        sessCheck = entBase + 0xfc;

        /* Check if connected */
        if (*sessCheck == 0)
            continue;

        /* Check pm_flags for spectator/limbo */
        cl = *(gclient_t **)(entBase + 0x158);
        if (*(byte *)((byte *)cl + 0xe) & 0x40)
            continue;

        TeamplayInfoMessage((gentity_t *)entBase);
    }

    return 0;
}
