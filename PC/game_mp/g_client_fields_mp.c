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

extern byte *g_scr_data_ptr; /* 0x195f5bc - direct pointer to scr data */
extern byte *level_ptr;      /* 0x195f6a0 - points to level struct */
extern byte *g_entities_ptr; /* 0x195f688 - points to entity array */

#define CLIENT_STRIDE sizeof(gclient_s)
#define ENTITY_STRIDE sizeof(gentity_s)

static const client_fields_t fields[14]; /* 0x333760 */

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
static int ClientNum(byte *pSelf)
{
    byte *level = *(byte **)level_ptr;
    byte *clients = *(byte **)level;
    return ((int)((byte *)pSelf - clients)) / CLIENT_STRIDE;
}

/* Helper: get entity pointer for a client */
static byte *ClientEntity(byte *pSelf)
{
    int num = ClientNum(pSelf);
    byte *entities = *(byte **)g_entities_ptr;
    return entities + num * ENTITY_STRIDE;
}

/* line 20 */
static void ClientScr_ReadOnly(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *fb = (byte *)pField;
    Scr_Error(va("player field %s is read-only", *(const char **)fb));
}

/* line 33 */
static void ClientScr_SetSessionTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *scr = *(byte **)&g_scr_data_ptr;
    unsigned short str;
    int clientNum;

    str = Scr_GetConstString(0);

    if (str == *(unsigned short *)(scr + 4)) {
        /* allies */
        *(int *)(pb + 0x274c) = 1;
    } else if (str == *(unsigned short *)(scr + 2)) {
        /* axis */
        *(int *)(pb + 0x274c) = 2;
    } else if (str == *(unsigned short *)(scr + 0x48)) {
        /* spectator */
        *(int *)(pb + 0x274c) = 3;
    } else if (str == *(unsigned short *)(scr + 0x74)) {
        /* none */
        *(int *)(pb + 0x274c) = 0;
    } else {
        Scr_Error(va("'%s' is an illegal sessionteam string. Must be allies, axis, none, or spectator.", SL_ConvertToString((unsigned short)str)));
    }

    clientNum = ClientNum(pb);
    ClientUserinfoChanged(clientNum);
    CalculateRanks();
}

/* line 62 */
static void ClientScr_GetSessionTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *scr = *(byte **)&g_scr_data_ptr;
    int team = *(int *)(pb + 0x274c);

    switch (team) {
    case 1:
        Scr_AddConstString(*(unsigned short *)(scr + 4));
        break;
    case 2:
        Scr_AddConstString(*(unsigned short *)(scr + 2));
        break;
    case 3:
        Scr_AddConstString(*(unsigned short *)(scr + 0x48));
        break;
    case 0:
        Scr_AddConstString(*(unsigned short *)(scr + 0x74));
        break;
    default:
        break;
    }
}

/* line 89 */
static void ClientScr_SetSessionState(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *scr = *(byte **)&g_scr_data_ptr;
    unsigned short str;

    str = Scr_GetConstString(0);

    if (str == *(unsigned short *)(scr + 0x72)) {
        /* playing */
        *(int *)(pb + 0x26a8) = 0;
    } else if (str == *(unsigned short *)(scr + 0x76)) {
        /* dead */
        *(int *)(pb + 0x26a8) = 1;
    } else if (str == *(unsigned short *)(scr + 0x48)) {
        /* spectator */
        *(int *)(pb + 0x26a8) = 2;
    } else if (str == *(unsigned short *)(scr + 0x6e)) {
        /* intermission */
        *(int *)(pb + 0xa0) ^= 2;
        *(int *)(pb + 0x26a8) = 3;
    } else {
        Scr_Error(va("'%s' is an illegal sessionstate string. Must be playing, dead, spectator, or intermission.", SL_ConvertToString((unsigned short)str)));
    }
}

/* line 125 */
static void ClientScr_GetSessionState(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *scr = *(byte **)&g_scr_data_ptr;
    int state = *(int *)(pb + 0x26a8);

    switch (state) {
    case 0:
        Scr_AddConstString(*(unsigned short *)(scr + 0x72));
        break;
    case 1:
        Scr_AddConstString(*(unsigned short *)(scr + 0x76));
        break;
    case 2:
        Scr_AddConstString(*(unsigned short *)(scr + 0x48));
        break;
    case 3:
        Scr_AddConstString(*(unsigned short *)(scr + 0x6e));
        break;
    default:
        break;
    }
}

/* line 153 */
static void ClientScr_SetMaxHealth(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    int val;
    int health;
    byte *ent;

    val = Scr_GetInt(0);
    if (val <= 0)
        val = 1;

    *(int *)(pb + 0x2728) = val;

    /* Cap current health to max */
    health = *(int *)(pb + 0x12c);
    if (health > val)
        health = val;

    /* Update entity health */
    ent = ClientEntity(pb);
    *(int *)(ent + 0x194) = health;

    /* Update maxHealth in playerState */
    *(int *)(pb + 0x134) = *(int *)(pb + 0x2728);
}

/* line 179 */
static void ClientScr_SetScore(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;

    *(int *)(pb + 0x26b8) = Scr_GetInt(0);
    CalculateRanks();
}

/* line 194 */
static void ClientScr_SetSpectatorClient(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    int iNewSpectatorClient;

    iNewSpectatorClient = Scr_GetInt(0);
    if ((unsigned int)(iNewSpectatorClient + 1) > 0x40) {
        Scr_Error("spectatorclient can only be set to -1, or a valid client number");
    }

    *(int *)(pb + 0x26ac) = iNewSpectatorClient;
}

/* line 214 */
static void ClientScr_SetStatusIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;

    *(int *)(pb + 0x26b0) = GScr_GetStatusIconIndex(Scr_GetString(0));
}

/* line 230 */
static void ClientScr_GetStatusIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    char szConfigString[1024];
    int icon = *(int *)(pb + 0x26b0);

    if (icon == 0) {
        Scr_AddString("");
        return;
    }

    SV_GetConfigstring(icon + 0x16, szConfigString, 1024);
    Scr_AddString(szConfigString);
}

/* line 254 */
static void ClientScr_SetHeadIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *pEnt;

    pEnt = ClientEntity(pb);
    *(int *)(pEnt + 0x94) = GScr_GetHeadIconIndex(Scr_GetString(0));
}

/* line 273 */
static void ClientScr_GetHeadIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *entities = *(byte **)g_entities_ptr;
    int clientNum = ClientNum(pb);
    char szConfigString[1024];
    int icon;

    icon = *(int *)(entities + clientNum * ENTITY_STRIDE + 0x94);

    if (icon == 0) {
        Scr_AddString("");
        return;
    }
    if (icon > 0xf) {
        return;
    }

    SV_GetConfigstring(icon + 0x1e, szConfigString, 1024);
    Scr_AddString(szConfigString);
}

/* line 298 */
static void ClientScr_SetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *scr = *(byte **)&g_scr_data_ptr;
    byte *pEnt;
    unsigned short str;

    pEnt = ClientEntity(pb);
    str = Scr_GetConstString(0);

    if (str == *(unsigned short *)(scr + 0x74)) {
        /* none */
        *(int *)(pEnt + 0x98) = 0;
    } else if (str == *(unsigned short *)(scr + 2)) {
        /* axis */
        *(int *)(pEnt + 0x98) = 2;
    } else if (str == *(unsigned short *)(scr + 4)) {
        /* allies */
        *(int *)(pEnt + 0x98) = 1;
    } else if (str == *(unsigned short *)(scr + 0x48)) {
        /* spectator */
        Scr_Error(va("'%s' is an illegal head icon team string. Must be none, allies, axis, or spectator.", SL_ConvertToString((unsigned short)str)));
    } else {
        *(int *)(pEnt + 0x98) = 3;
    }
}

/* line 326 */
static void ClientScr_GetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    byte *scr = *(byte **)&g_scr_data_ptr;
    byte *entities = *(byte **)g_entities_ptr;
    int clientNum = ClientNum(pb);
    int team;

    team = *(int *)(entities + clientNum * ENTITY_STRIDE + 0x98);

    switch (team) {
    case 1:
        Scr_AddConstString(*(unsigned short *)(scr + 4));
        break;
    case 2:
        Scr_AddConstString(*(unsigned short *)(scr + 2));
        break;
    case 3:
        Scr_AddConstString(*(unsigned short *)(scr + 0x48));
        break;
    default:
        Scr_AddConstString(*(unsigned short *)(scr + 0x74));
        break;
    }
}

/* line 357 */
static void ClientScr_SetArchiveTime(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    float val;

    val = Scr_GetFloat(0);
    *(int *)(pb + 0x26b4) = (int)(val * 1000.0f);
}

/* line 370 */
static void ClientScr_GetArchiveTime(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;

    Scr_AddFloat((float)*(int *)(pb + 0x26b4) * 0.001f);
}

/* line 380 */
static void ClientScr_SetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    *(int *)(pb + 0x27a4) = Scr_GetInt(0);
}

/* line 393 */
static void ClientScr_GetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField)
{
    byte *pb = (byte *)pSelf;
    Scr_AddInt(*(int *)(pb + 0x26b4));
}

/* line 428 */
void GScr_AddFieldsForClient(void)
{
    byte *fb = (byte *)fields;
    int i;
    const char *name;

    name = *(const char **)fb;
    i = 0;
    while (name != NULL) {
        /* Compute encoded offset from field index */
        int idx = i / 4;
        int mult = idx * 3;
        mult = mult + (mult << 4);
        mult = mult + (mult << 8);
        mult = mult + (mult << 16);
        int encoded = (idx + mult * 4) | 0xc000;
        encoded &= 0xffff;

        Scr_AddClassField(0, name, encoded);

        i += 0x14;
        fb += 0x14;
        name = *(const char **)fb;
    }
}

/* line 446 */
void Scr_SetClientField(gclient_t *client, int offset)
{
    byte *entry;
    void (*setter)(gclient_t *, const client_fields_s *);

    entry = (byte *)fields + offset * 20;
    setter = *(void (**)(gclient_t *, const client_fields_s *))(entry + 0xc);

    if (setter != NULL) {
        setter(client, (const client_fields_s *)entry);
    } else {
        Scr_SetGenericField(client, *(int *)(entry + 4), *(int *)(entry + 8));
    }
}

/* line 471 */
void Scr_GetClientField(gclient_t *client, int offset)
{
    byte *entry;
    void (*getter)(gclient_t *, const client_fields_s *);

    entry = (byte *)fields + offset * 20;
    getter = *(void (**)(gclient_t *, const client_fields_s *))(entry + 0x10);

    if (getter != NULL) {
        getter(client, (const client_fields_s *)entry);
    } else {
        Scr_GetGenericField(client, *(int *)(entry + 4), *(int *)(entry + 8));
    }
}
