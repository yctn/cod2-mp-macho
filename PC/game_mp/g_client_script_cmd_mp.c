/* ASM dump from: g_client_script_cmd_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_client_script_cmd_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

/* player_methods[] defined at end of file */

void PlayerCmd_takeWeapon(struct scr_entref_t entref);
void PlayerCmd_takeAllWeapons(scr_entref_t entref);
static void PlayerCmd_setAngles(scr_entref_t entref);
static void PlayerCmd_getAngles(scr_entref_t entref);
void PlayerCmd_useButtonPressed(scr_entref_t entref);
void PlayerCmd_attackButtonPressed(scr_entref_t entref);
void PlayerCmd_meleeButtonPressed(scr_entref_t entref);
void PlayerCmd_playerADS(scr_entref_t entref);
void PlayerCmd_isOnGround(scr_entref_t entref);
void PlayerCmd_pingPlayer(scr_entref_t entref);
static void PlayerCmd_SetViewmodel(scr_entref_t entref);
static void PlayerCmd_GetViewmodel(scr_entref_t entref);
static void PlayerCmd_showScoreboard(scr_entref_t entref);
static void PlayerCmd_setSpawnWeapon(scr_entref_t entref);
static void PlayerCmd_dropItem(scr_entref_t entref);
static void PlayerCmd_Suicide(scr_entref_t entref);
static void PlayerCmd_OpenMenu(scr_entref_t entref);
static void PlayerCmd_OpenMenuNoMouse(scr_entref_t entref);
static void PlayerCmd_CloseMenu(scr_entref_t entref);
static void PlayerCmd_CloseInGameMenu(scr_entref_t entref);
static void PlayerCmd_SetWeaponSlotWeapon(scr_entref_t entref);
static void PlayerCmd_SetWeaponSlotAmmo(scr_entref_t entref);
static void PlayerCmd_GetWeaponSlotClipAmmo(scr_entref_t entref);
static void PlayerCmd_SetWeaponSlotClipAmmo(scr_entref_t entref);
static void PlayerCmd_SetWeaponClipAmmo(scr_entref_t entref);
static void iclientprintln(scr_entref_t entref);
static void iclientprintlnbold(scr_entref_t entref);
void PlayerCmd_spawn(scr_entref_t entref);
static void PlayerCmd_setEnterTime(scr_entref_t entref);
void BodyEnd(gentity_t *ent);
static void PlayerCmd_SetClientDvar(scr_entref_t entref);
static void PlayerCmd_IsTalking(scr_entref_t entref);
static void PlayerCmd_FreezeControls(scr_entref_t entref);
static void PlayerCmd_DisableWeapon(scr_entref_t entref);
static void PlayerCmd_EnableWeapon(scr_entref_t entref);
static void PlayerCmd_SetReverb(scr_entref_t entref);
static void PlayerCmd_DeactivateReverb(scr_entref_t entref);
static void PlayerCmd_SetChannelVolumes(scr_entref_t entref);
static void PlayerCmd_DeactivateChannelVolumes(scr_entref_t entref);
static void ScrCmd_IsLookingAt(scr_entref_t entref);
static void ScrCmd_PlayLocalSound(scr_entref_t entref);
static void PlayerCmd_SayAll(scr_entref_t entref);
static void PlayerCmd_SayTeam(scr_entref_t entref);
static void PlayerCmd_AllowSpectateTeam(scr_entref_t entref);
static void PlayerCmd_GetGuid(scr_entref_t entref);
BuiltinMethod Player_GetMethod(const char * *pName);
void PlayerCmd_giveWeapon(scr_entref_t entref);
void PlayerCmd_hasWeapon(scr_entref_t entref);
void PlayerCmd_switchToWeapon(scr_entref_t entref);
void PlayerCmd_switchToOffhand(scr_entref_t entref);
void PlayerCmd_giveStartAmmo(scr_entref_t entref);
void PlayerCmd_giveMaxAmmo(scr_entref_t entref);
void PlayerCmd_getFractionStartAmmo(scr_entref_t entref);
void PlayerCmd_getFractionMaxAmmo(scr_entref_t entref);
static void PlayerCmd_setOrigin(scr_entref_t entref);
static void PlayerCmd_finishPlayerDamage(scr_entref_t entref);
static void PlayerCmd_ClonePlayer(scr_entref_t entref);
void PlayerCmd_getCurrentWeapon(scr_entref_t entref);
void PlayerCmd_getCurrentOffhand(scr_entref_t entref);
static void PlayerCmd_GetWeaponSlotWeapon(scr_entref_t entref);
static void PlayerCmd_GetWeaponSlotAmmo(scr_entref_t entref);

/* line 69 */
extern void Scr_ObjectError(const char *msg);
extern const char *va(const char *fmt, ...);
extern const char *Scr_GetString(unsigned int index);
extern int G_GetWeaponIndexForName(const char *name);
extern int BG_AmmoForWeapon(int weaponIndex);
extern int BG_ClipForWeapon(int weaponIndex);
extern qboolean BG_TakePlayerWeapon(playerState_t *ps, int weaponIndex);

void PlayerCmd_takeWeapon(struct scr_entref_t entref) {
    unsigned short entnum;
    unsigned short classnum;
    gentity_t *pSelf;
    const char *weaponName;
    int iWeaponIndex;
    gclient_t *client;
    int ammoIndex;
    int clipIndex;

    entnum = entref.entnum;
    classnum = entref.classnum;

    if (classnum != 0) {
        Scr_ObjectError("not an entity");
        pSelf = NULL;
    } else {
        pSelf = &((gentity_t *)imp_g_entities)[entnum];
        if (pSelf->client == NULL) {
            Scr_ObjectError(va("entity %i is not a player", (int)entnum));
        }
    }

    weaponName = (const char *)Scr_GetString(0);
    iWeaponIndex = G_GetWeaponIndexForName(weaponName);

    client = pSelf->client;
    ammoIndex = BG_AmmoForWeapon(iWeaponIndex);
    client->ps.ammo[ammoIndex] = 0;

    client = pSelf->client;
    clipIndex = BG_ClipForWeapon(iWeaponIndex);
    client->ps.ammoclip[clipIndex] = 0;

    BG_TakePlayerWeapon(&pSelf->client->ps, iWeaponIndex);
}

static const BuiltinMethodDef player_methods[] = {
    {"giveweapon", (BuiltinMethod)PlayerCmd_giveWeapon, 0},
    {"takeweapon", (BuiltinMethod)PlayerCmd_takeWeapon, 0},
    {"takeallweapons", (BuiltinMethod)PlayerCmd_takeAllWeapons, 0},
    {"getcurrentweapon", (BuiltinMethod)PlayerCmd_getCurrentWeapon, 0},
    {"getcurrentoffhand", (BuiltinMethod)PlayerCmd_getCurrentOffhand, 0},
    {"hasweapon", (BuiltinMethod)PlayerCmd_hasWeapon, 0},
    {"switchtoweapon", (BuiltinMethod)PlayerCmd_switchToWeapon, 0},
    {"switchtooffhand", (BuiltinMethod)PlayerCmd_switchToOffhand, 0},
    {"givestartammo", (BuiltinMethod)PlayerCmd_giveStartAmmo, 0},
    {"givemaxammo", (BuiltinMethod)PlayerCmd_giveMaxAmmo, 0},
    {"getfractionstartammo", (BuiltinMethod)PlayerCmd_getFractionStartAmmo, 0},
    {"getfractionmaxammo", (BuiltinMethod)PlayerCmd_getFractionMaxAmmo, 0},
    {"setorigin", (BuiltinMethod)PlayerCmd_setOrigin, 0},
    {"setplayerangles", (BuiltinMethod)PlayerCmd_setAngles, 0},
    {"getplayerangles", (BuiltinMethod)PlayerCmd_getAngles, 0},
    {"usebuttonpressed", (BuiltinMethod)PlayerCmd_useButtonPressed, 0},
    {"attackbuttonpressed", (BuiltinMethod)PlayerCmd_attackButtonPressed, 0},
    {"meleebuttonpressed", (BuiltinMethod)PlayerCmd_meleeButtonPressed, 0},
    {"playerads", (BuiltinMethod)PlayerCmd_playerADS, 0},
    {"isonground", (BuiltinMethod)PlayerCmd_isOnGround, 0},
    {"pingplayer", (BuiltinMethod)PlayerCmd_pingPlayer, 0},
    {"setviewmodel", (BuiltinMethod)PlayerCmd_SetViewmodel, 0},
    {"getviewmodel", (BuiltinMethod)PlayerCmd_GetViewmodel, 0},
    {"sayall", (BuiltinMethod)PlayerCmd_SayAll, 0},
    {"sayteam", (BuiltinMethod)PlayerCmd_SayTeam, 0},
    {"showscoreboard", (BuiltinMethod)PlayerCmd_showScoreboard, 0},
    {"setspawnweapon", (BuiltinMethod)PlayerCmd_setSpawnWeapon, 0},
    {"dropitem", (BuiltinMethod)PlayerCmd_dropItem, 0},
    {"finishplayerdamage", (BuiltinMethod)PlayerCmd_finishPlayerDamage, 0},
    {"suicide", (BuiltinMethod)PlayerCmd_Suicide, 0},
    {"openmenu", (BuiltinMethod)PlayerCmd_OpenMenu, 0},
    {"openmenunomouse", (BuiltinMethod)PlayerCmd_OpenMenuNoMouse, 0},
    {"closemenu", (BuiltinMethod)PlayerCmd_CloseMenu, 0},
    {"closeingamemenu", (BuiltinMethod)PlayerCmd_CloseInGameMenu, 0},
    {"freezecontrols", (BuiltinMethod)PlayerCmd_FreezeControls, 0},
    {"disableweapon", (BuiltinMethod)PlayerCmd_DisableWeapon, 0},
    {"enableweapon", (BuiltinMethod)PlayerCmd_EnableWeapon, 0},
    {"setreverb", (BuiltinMethod)PlayerCmd_SetReverb, 0},
    {"deactivatereverb", (BuiltinMethod)PlayerCmd_DeactivateReverb, 0},
    {"setchannelvolumes", (BuiltinMethod)PlayerCmd_SetChannelVolumes, 0},
    {"deactivatechannelvolumes", (BuiltinMethod)PlayerCmd_DeactivateChannelVolumes, 0},
    {"getweaponslotweapon", (BuiltinMethod)PlayerCmd_GetWeaponSlotWeapon, 0},
    {"setweaponslotweapon", (BuiltinMethod)PlayerCmd_SetWeaponSlotWeapon, 0},
    {"getweaponslotammo", (BuiltinMethod)PlayerCmd_GetWeaponSlotAmmo, 0},
    {"setweaponslotammo", (BuiltinMethod)PlayerCmd_SetWeaponSlotAmmo, 0},
    {"getweaponslotclipammo", (BuiltinMethod)PlayerCmd_GetWeaponSlotClipAmmo, 0},
    {"setweaponslotclipammo", (BuiltinMethod)PlayerCmd_SetWeaponSlotClipAmmo, 0},
    {"setweaponclipammo", (BuiltinMethod)PlayerCmd_SetWeaponClipAmmo, 0},
    {"iprintln", (BuiltinMethod)iclientprintln, 0},
    {"iprintlnbold", (BuiltinMethod)iclientprintlnbold, 0},
    {"spawn", (BuiltinMethod)PlayerCmd_spawn, 0},
    {"setentertime", (BuiltinMethod)PlayerCmd_setEnterTime, 0},
    {"cloneplayer", (BuiltinMethod)PlayerCmd_ClonePlayer, 0},
    {"setclientcvar", (BuiltinMethod)PlayerCmd_SetClientDvar, 0},
    {"islookingat", (BuiltinMethod)ScrCmd_IsLookingAt, 0},
    {"playlocalsound", (BuiltinMethod)ScrCmd_PlayLocalSound, 0},
    {"istalking", (BuiltinMethod)PlayerCmd_IsTalking, 0},
    {"allowspectateteam", (BuiltinMethod)PlayerCmd_AllowSpectateTeam, 0},
    {"getguid", (BuiltinMethod)PlayerCmd_GetGuid, 0},
};

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))

BuiltinMethod Player_GetMethod(const char **pName)
{
    int i;
    for (i = 0; i < (int)ARRAY_COUNT(player_methods); i++)
    {
        if (I_stricmp(*pName, player_methods[i].actionString) == 0)
        {
            *pName = player_methods[i].actionString;
            return player_methods[i].actionFunc;
        }
    }
    return (BuiltinMethod)0;
}
