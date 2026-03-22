/* Converted to C from ASM: g_client_fields_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_client_fields_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern const char * va(const char *fmt, ...);
extern void Scr_Error(const char *msg);
extern unsigned short Scr_GetConstString(int index);
extern const char * SL_ConvertToString(int stringId);
extern void Scr_AddConstString(int stringId);
extern int Scr_GetInt(int index);
extern const char * Scr_GetString(int index);
extern float Scr_GetFloat(int index);
extern void Scr_AddFloat(float value);
extern void Scr_AddInt(int value);
extern void Scr_AddString(const char *str);
extern void Scr_AddClassField(int classnum, const char *name, int offset);
extern void Scr_SetGenericField(gclient_t *client, int offset, int type);
extern void Scr_GetGenericField(gclient_t *client, int offset, int type);
extern void ClientUserinfoChanged(int clientNum);
extern void CalculateRanks(void);
extern int GScr_GetStatusIconIndex(const char *name);
extern int GScr_GetHeadIconIndex(const char *name);
extern void SV_GetConfigstring(int index, char *buf, int bufSize);

/* imp_scr_const declared in generated_syms.h as void* */
extern byte level_ptr[];      /* imp_level - points to level struct */
extern byte g_entities_ptr[]; /* imp_g_entities - points to entity array */

#define SCR_CONST() ((const scr_const_t *)imp_scr_const)

static client_fields_t fields[14]; /* initialized at runtime in GScr_AddFieldsForClient */
static int fields_inited = 0;
#define CF(i,n,o,t,s,g) do{fields[i].name=n;fields[i].ofs=o;fields[i].type=t;fields[i].setter=(ScriptCallbackClient)(s);fields[i].getter=(ScriptCallbackClient)(g);}while(0)

static void ClientScr_ReadOnly(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetSessionTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetSessionTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetSessionState(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetSessionState(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetMaxHealth(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetScore(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetSpectatorClient(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetStatusIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetStatusIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetHeadIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetHeadIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetArchiveTime(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetArchiveTime(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField);
void GScr_AddFieldsForClient(void);
void Scr_SetClientField(gclient_t *client, int offset);
void Scr_GetClientField(gclient_t *client, int offset);

/* Helper: compute client number from gclient_t pointer */
static level_locals_t *G_Level(void)
{
    return (level_locals_t *)level_ptr;
}

static gentity_t *G_Entities(void)
{
    return (gentity_t *)g_entities_ptr;
}

/* Helper: compute client number from gclient_t pointer */
static int ClientNum(const gclient_t *client)
{
    return (int)(client - G_Level()->clients);
}

/* Helper: get entity pointer for a client */
static gentity_t *ClientEntity(const gclient_t *client)
{
    return &G_Entities()[ClientNum(client)];
}

/* line 20 */
static void ClientScr_ReadOnly(gclient_t *pSelf, const client_fields_s *pField)
{
    Scr_Error(va("player field %s is read-only", pField->name));
}

/* line 33 */
static void ClientScr_SetSessionTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    const scr_const_t *sc = SCR_CONST();
    unsigned short str;

    str = Scr_GetConstString(0);

    if (str == sc->allies) {
        client->sess.cs.team = 1;
    } else if (str == sc->axis) {
        client->sess.cs.team = 2;
    } else if (str == sc->spectator) {
        client->sess.cs.team = 3;
    } else if (str == sc->none) {
        client->sess.cs.team = 0;
    } else {
        Scr_Error(va("'%s' is an illegal sessionteam string. Must be allies, axis, none, or spectator.", SL_ConvertToString((unsigned short)str)));
    }

    ClientUserinfoChanged(ClientNum(client));
    CalculateRanks();
}

/* line 62 */
static void ClientScr_GetSessionTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    const scr_const_t *sc = SCR_CONST();

    switch (client->sess.cs.team) {
    case 1: Scr_AddConstString(sc->allies); break;
    case 2: Scr_AddConstString(sc->axis); break;
    case 3: Scr_AddConstString(sc->spectator); break;
    case 0: Scr_AddConstString(sc->none); break;
    default: break;
    }
}

/* line 89 */
static void ClientScr_SetSessionState(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    const scr_const_t *sc = SCR_CONST();
    unsigned short str;

    str = Scr_GetConstString(0);

    if (str == sc->playing) {
        client->sess.sessionState = 0; /* SESS_STATE_PLAYING */
    } else if (str == sc->dead) {
        client->sess.sessionState = 1; /* SESS_STATE_DEAD */
    } else if (str == sc->spectator) {
        client->sess.sessionState = 2; /* SESS_STATE_SPECTATOR */
    } else if (str == sc->intermission) {
        ((gclient_t *)client)->ps.eFlags ^= 2; /* ps.pm_flags toggle */
        client->sess.sessionState = 3; /* SESS_STATE_INTERMISSION */
    } else {
        Scr_Error(va("'%s' is an illegal sessionstate string. Must be playing, dead, spectator, or intermission.", SL_ConvertToString((unsigned short)str)));
    }
}

/* line 125 */
static void ClientScr_GetSessionState(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    const scr_const_t *sc = SCR_CONST();

    switch (client->sess.sessionState) {
    case 0: Scr_AddConstString(sc->playing); break;
    case 1: Scr_AddConstString(sc->dead); break;
    case 2: Scr_AddConstString(sc->spectator); break;
    case 3: Scr_AddConstString(sc->intermission); break;
    default: break;
    }
}

/* line 153 */
static void ClientScr_SetMaxHealth(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    int val;
    int health;

    val = Scr_GetInt(0);
    if (val <= 0)
        val = 1;

    client->sess.maxHealth = val;

    /* Cap current health to max */
    health = client->ps.stats[0];
    if (health > val)
        health = val;

    /* Update entity health */
    {
        gentity_s *ent = ClientEntity(client);
        ent->health = health;

    /* Update maxHealth in playerState */
        client->ps.stats[2] = client->sess.maxHealth;
    }
}

/* line 179 */
static void ClientScr_SetScore(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    client->sess.score = Scr_GetInt(0);
    CalculateRanks();
}

/* line 194 */
static void ClientScr_SetSpectatorClient(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    int iNewSpectatorClient = Scr_GetInt(0);

    if ((unsigned int)(iNewSpectatorClient + 1) > 0x40) {
        Scr_Error("spectatorclient can only be set to -1, or a valid client number");
    }

    client->sess.forceSpectatorClient = iNewSpectatorClient;
}

/* line 214 */
static void ClientScr_SetStatusIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    client->sess.status_icon = GScr_GetStatusIconIndex(Scr_GetString(0));
}

/* line 230 */
static void ClientScr_GetStatusIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    char szConfigString[1024];

    if (client->sess.status_icon == 0) {
        Scr_AddString("");
        return;
    }

    SV_GetConfigstring(client->sess.status_icon + 0x16, szConfigString, 1024);
    Scr_AddString(szConfigString);
}

/* line 254 */
static void ClientScr_SetHeadIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    /* headicon is stored on the entity, not the client */
    gentity_s *ent = ClientEntity(pSelf);
    ((ent)->s.iHeadIcon) = GScr_GetHeadIconIndex(Scr_GetString(0)); /* ent.headicon */
}

/* line 273 */
static void ClientScr_GetHeadIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    int clientNum = ClientNum(pSelf);
    gentity_s *ent = &G_Entities()[clientNum];
    char szConfigString[1024];
    int icon = ((ent)->s.iHeadIcon); /* ent.headicon */

    if (icon == 0) { Scr_AddString(""); return; }
    if (icon > 0xf) { return; }

    SV_GetConfigstring(icon + 0x1e, szConfigString, 1024);
    Scr_AddString(szConfigString);
}

/* line 298 */
static void ClientScr_SetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    const scr_const_t *sc = SCR_CONST();
    gentity_s *ent = ClientEntity(pSelf);
    unsigned short str = Scr_GetConstString(0);

    if (str == sc->none) {
        ((ent)->s.iHeadIconTeam) = 0; /* ent.headiconteam = TEAM_NONE */
    } else if (str == sc->axis) {
        ((ent)->s.iHeadIconTeam) = 2;
    } else if (str == sc->allies) {
        ((ent)->s.iHeadIconTeam) = 1;
    } else if (str == sc->spectator) {
        Scr_Error(va("'%s' is an illegal head icon team string.", SL_ConvertToString((unsigned short)str)));
    } else {
        ((ent)->s.iHeadIconTeam) = 3;
    }
}

/* line 326 */
static void ClientScr_GetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    const scr_const_t *sc = SCR_CONST();
    int clientNum = ClientNum(pSelf);
    gentity_s *ent = &G_Entities()[clientNum];
    int team = ((ent)->s.iHeadIconTeam); /* ent.headiconteam */

    switch (team) {
    case 1: Scr_AddConstString(sc->allies); break;
    case 2: Scr_AddConstString(sc->axis); break;
    case 3: Scr_AddConstString(sc->spectator); break;
    default:
        Scr_AddConstString(sc->none);
        break;
    }
}

/* line 357 */
static void ClientScr_SetArchiveTime(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    client->sess.archiveTime = (int)(Scr_GetFloat(0) * 1000.0f);
}

/* line 370 */
static void ClientScr_GetArchiveTime(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    Scr_AddFloat((float)client->sess.archiveTime * 0.001f);
}

/* line 380 */
static void ClientScr_SetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    client->sess.psOffsetTime = Scr_GetInt(0);
}

/* line 393 */
static void ClientScr_GetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField)
{
    gclient_s *client = (gclient_s *)pSelf;
    Scr_AddInt(client->sess.archiveTime);
}

/* line 428 */
void GScr_AddFieldsForClient(void)
{
    /* Populate client fields from Mac binary data (utils/binary.x86 @ 0x332760) */
    if (!fields_inited) {
        fields_inited = 1;
        CF(0,  "name",            0x2784, F_LSTRING, ClientScr_ReadOnly,        NULL);
        CF(1,  "sessionteam",     0,      F_STRING,  ClientScr_SetSessionTeam,  ClientScr_GetSessionTeam);
        CF(2,  "sessionstate",    0,      F_STRING,  ClientScr_SetSessionState, ClientScr_GetSessionState);
        CF(3,  "maxhealth",       0x2728, F_INT,     ClientScr_SetMaxHealth,    NULL);
        CF(4,  "score",           0x26b8, F_INT,     ClientScr_SetScore,        NULL);
        CF(5,  "deaths",          0x26bc, F_INT,     NULL,                      NULL);
        CF(6,  "statusicon",      0,      F_STRING,  ClientScr_SetStatusIcon,   ClientScr_GetStatusIcon);
        CF(7,  "headicon",        0,      F_STRING,  ClientScr_SetHeadIcon,     ClientScr_GetHeadIcon);
        CF(8,  "headiconteam",    0,      F_STRING,  ClientScr_SetHeadIconTeam, ClientScr_GetHeadIconTeam);
        CF(9,  "spectatorclient", 0x26ac, F_INT,     ClientScr_ReadOnly,        NULL);
        CF(10, "archivetime",     0x26b4, F_FLOAT,   ClientScr_SetArchiveTime,  ClientScr_GetArchiveTime);
        CF(11, "psoffsettime",    0x27a4, F_INT,     ClientScr_SetPSOffsetTime, ClientScr_GetPSOffsetTime);
        CF(12, "pers",            0x26c0, F_OBJECT,  ClientScr_ReadOnly,        NULL);
    }
    for (int fieldIndex = 0; fieldIndex < (int)(sizeof(fields) / sizeof(fields[0])); ++fieldIndex) {
        const client_fields_t *field = &fields[fieldIndex];
        int fieldWordOffset;
        int idx;
        int mult;
        int encoded;

        if (!field->name) {
            break;
        }

        /* Original encoding uses the field's word offset in the table. */
        fieldWordOffset = fieldIndex * (sizeof(client_fields_t) / sizeof(int));
        idx = fieldWordOffset;
        mult = idx * 3;
        mult = mult + (mult << 4);
        mult = mult + (mult << 8);
        mult = mult + (mult << 16);
        encoded = (idx + mult * 4) | 0xc000;
        encoded &= 0xffff;

        Scr_AddClassField(0, field->name, encoded);
    }
}

/* line 446 */
void Scr_SetClientField(gclient_t *client, int offset)
{
    const client_fields_t *field;
    void (*setter)(gclient_t *, const client_fields_s *);

    if (!client || offset < 0 || offset >= 13 || !fields[offset].name)
        return;

    field = &fields[offset];
    setter = (void (*)(gclient_t *, const client_fields_s *))field->setter;

    if (setter != NULL) {
        setter(client, field);
    } else {
        Scr_SetGenericField(client, field->ofs, field->type);
    }
}

/* line 471 */
void Scr_GetClientField(gclient_t *client, int offset)
{
    const client_fields_t *field;
    void (*getter)(gclient_t *, const client_fields_s *);

    if (!client || offset < 0 || offset >= 13 || !fields[offset].name) {
        Scr_AddUndefined();
        return;
    }

    field = &fields[offset];
    getter = (void (*)(gclient_t *, const client_fields_s *))field->getter;

    if (getter != NULL) {
        getter(client, field);
    } else {
        Scr_GetGenericField(client, field->ofs, field->type);
    }
}
