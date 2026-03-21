/* Converted to C from ASM: g_team_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_team_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern void G_GetPlayerViewOrigin(gentity_t *ent, vec3_t origin);
extern void G_GetPlayerViewDirection(gentity_t *ent, vec3_t forward, vec3_t right, vec3_t up);
extern void G_TraceCapsule(trace_t *trace, vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, int passEntityNum, int contentMask);
extern int G_IsPlaying(gentity_t *ent);

extern byte g_entities_ptr[]; /* imp_g_entities */
extern byte level_ptr[];      /* imp_level */
extern byte *sv_maxclients;  /* imp_g_maxclients */
extern vec3_t *trace_mins;   /* imp_vec3_origin */

#define STAT_IDENT_CLIENT_NUM    3
#define STAT_IDENT_CLIENT_HEALTH 4
#define PMF_FOLLOW               0x400000

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

    team1 = cl1->sess.cs.team;
    if (team1 == 0)
        return 0;

    if (team1 == cl2->sess.cs.team)
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
    gentity_t *identGent;
    gclient_t *identClient;

    client = ent->client;

    if (client->sess.sessionState != SESS_STATE_PLAYING) {
        /* Binocular/spectator path */
        G_GetPlayerViewOrigin(ent, vStart);
        G_GetPlayerViewDirection(ent, vForward, NULL, NULL);

        /* Adjust vStart.z if viewHeightCurrent < 8.0 */
        if (client->ps.viewHeightCurrent < 8.0f) {
            vStart[2] += 8.0f - client->ps.viewHeightCurrent;
        }
    } else if (client->sess.cs.team != 0) {
        /* Team path */
        G_GetPlayerViewOrigin(ent, vStart);
        G_GetPlayerViewDirection(ent, vForward, NULL, NULL);
    } else {
        /* No team */
        client->ps.stats[STAT_IDENT_CLIENT_NUM] = -1;
        client->ps.stats[STAT_IDENT_CLIENT_HEALTH] = 0;
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
        identGent = &((gentity_t *)g_entities_ptr)[identEnt];
        identClient = identGent->client;

        if (identClient != NULL) {
            if (!G_IsPlaying(ent)) {
                /* Not playing (spectating) - show health regardless of team */
                compassTime = identGent->health;
                goto store;
            }

            /* Check if same team */
            if (identClient->sess.cs.team == client->sess.cs.team) {
                compassTime = identGent->health;
                goto store;
            }
        }
    }

    identEnt = -1;
    compassTime = 0;

store:
    client = ent->client;
    client->ps.stats[STAT_IDENT_CLIENT_NUM] = identEnt;
    client = ent->client;
    client->ps.stats[STAT_IDENT_CLIENT_HEALTH] = compassTime;
    return 0;
}

/* line 90 */
short int CheckTeamStatus(void)
{
    level_locals_t *level;
    int time;
    int lastTime;
    int maxClients;
    int i;
    gentity_t *ent;
    gclient_t *cl;

    level = (level_locals_t *)level_ptr;
    time = level->time;
    lastTime = level->lastTeammateHealthTime;

    if (time - lastTime <= 0)
        return 0;

    level->lastTeammateHealthTime = time;

    maxClients = ((dvar_t *)sv_maxclients)->current.integer;
    if (maxClients <= 0)
        return 0;

    for (i = 0; i < maxClients; i++) {
        ent = &((gentity_t *)g_entities_ptr)[i];

        /* Check if in use */
        if (!ent->r.inuse)
            continue;

        /* Check pm_flags for follow mode */
        cl = ent->client;
        if (cl == NULL)
            continue;
        if (cl->ps.pm_flags & PMF_FOLLOW)
            continue;

        TeamplayInfoMessage(ent);
    }

    return 0;
}
