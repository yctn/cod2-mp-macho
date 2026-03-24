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
