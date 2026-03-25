/* ASM dump from: g_items_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_items_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 */

extern qboolean itemRegistered[256]; /* 0x0 */
extern level_locals_t level;
extern int BG_GetNumWeapons(void);
extern WeaponDef *BG_GetWeaponDef(int weaponIndex);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern unsigned char G_SetConstString(scr_string_t *to, const char *from);
extern char *I_strncat(char *dest, int size, const char *src);
extern void SV_SetConfigstring(int index, const char *val);

/* Entity field access macros */
#define _ENT(e)           ((gentity_t *)(e))
#define ENT_CLIENTNUM(e)  (_ENT(e)->s.clientNum)
#define ENT_ACTIVE(e)     (_ENT(e)->active)

enum {
    GITEMS_ENTITYNUM_WORLD = 0x3fe,
    GITEMS_CS_WEAPONS = 7,
    GITEMS_CS_ITEMS = 8
};

void DroppedItemClearOwner(gentity_t *pSelf);
void G_GetItemClassname(const gitem_t *item, scr_string_t *out);
void ClearRegisteredItems(void);
void SaveRegisteredWeapons(void);
void SaveRegisteredItems(void);
void RegisterItem(int iItemIndex, qboolean bUpdateCS);
void G_RegisterWeapon(int weapIndex);
qboolean IsItemRegistered(int iItemIndex);
void FinishSpawningItem(gentity_t *ent);
void G_RunCorpseMove(gentity_t *ent);
void G_RunCorpse(gentity_t *ent);
void G_RunItem(gentity_t *ent);
int Add_Ammo(gentity_t *ent, int weapon, int count, qboolean fillClip);
gentity_t * Drop_Item(gentity_t *ent, const gitem_t *item, float angle, qboolean novelocity);
gentity_t * Drop_Weapon(gentity_t *pEnt, int iWeaponIndex, unsigned int tag);
void Touch_Item(gentity_t *ent, gentity_t *other, qboolean bTouched);
void Touch_Item_Auto(gentity_t *ent, gentity_t *other, qboolean bTouched);
void G_SpawnItem(gentity_t *ent, const gitem_t *item);

/* line 711 */
void DroppedItemClearOwner(gentity_t *pSelf)
{
    ENT_CLIENTNUM(pSelf) = GITEMS_ENTITYNUM_WORLD;
}

/* line 724 */
void G_GetItemClassname(const gitem_t *item, scr_string_t *out)
{
    char classname[256];
    int index;
    WeaponDef *weapDef;

    index = item - (gitem_t *)imp_bg_itemlist;

    if (index > BG_GetNumWeapons()) {
        G_SetConstString(out, item->classname);
        return;
    }

    weapDef = BG_GetWeaponDef(index);
    Com_sprintf(classname, sizeof(classname), "weapon_%s", weapDef->szInternalName);
    G_SetConstString(out, classname);
}

/* line 1109 */
void ClearRegisteredItems(void)
{
    memset(itemRegistered, 0, sizeof(itemRegistered));
    itemRegistered[0] = 1;
}

/* line 1124 */
void SaveRegisteredWeapons(void)
{
    char string[8192];
    WeaponDef *weapDef;
    int weapIndex;

    level.registerWeapons = 0;
    string[0] = '\0';
    weapDef = NULL;

    for (weapIndex = 1; weapIndex <= BG_GetNumWeapons(); ++weapIndex) {
        if (weapDef) {
            I_strncat(string, sizeof(string), " ");
        }

        weapDef = BG_GetWeaponDef(weapIndex);
        I_strncat(string, sizeof(string), weapDef->szInternalName);
    }

    SV_SetConfigstring(GITEMS_CS_WEAPONS, string);
}

/* line 1155 */
void SaveRegisteredItems(void)
{
    int bits;
    int digit;
    int itemIdx;
    int lastNonZeroChar;
    int n;
    char string[256];

    level.bRegisterItems = 0;
    bits = 0;
    digit = 0;
    n = 0;
    lastNonZeroChar = 0;

    for (itemIdx = 0; itemIdx < *(int *)imp_bg_numItems; ++itemIdx) {
        if (itemRegistered[itemIdx]) {
            digit += 1 << bits;
        }

        ++bits;

        if (bits == 4) {
            string[n] = digit + (digit < 10 ? '0' : 'W');
            ++n;
            lastNonZeroChar = n;
            digit = 0;
            bits = 0;
        }
    }

    if (bits) {
        string[n] = digit + (digit < 10 ? '0' : 'W');
        ++n;
        lastNonZeroChar = n;
    }

    string[lastNonZeroChar] = '\0';
    SV_SetConfigstring(GITEMS_CS_ITEMS, string);
}

/* line 1214 */
extern void Scr_Error(const char *msg);
extern const char *va(const char *fmt, ...);
extern int G_ModelIndex(const char *name);

void RegisterItem(int iItemIndex, qboolean bUpdateCS) {
    gitem_t *item;
    const char *name;

    /* Already registered? */
    if (itemRegistered[iItemIndex])
        return;

    /* If not initializing, check if the item has a valid classname */
    if (!level.initializing) {
        item = (gitem_t *)imp_bg_itemlist + iItemIndex;
        name = item->pickup_name;
        if (!name || *name == '\0') {
            name = "<<unknown>>"; /* "" or unknown */
        }
        Scr_Error(va("game tried to register the item '%s' after initialization finished\n", name));
    }

    /* Mark as registered */
    itemRegistered[iItemIndex] = 1;

    item = (gitem_t *)imp_bg_itemlist + iItemIndex;

    /* Register world model if present */
    if (item->world_model[0]) {
        G_ModelIndex(item->world_model[0]);
    }

    /* Register view model if present */
    if (item->world_model[1]) {
        G_ModelIndex(item->world_model[1]);
    }

    /* If bUpdateCS, set level flag */
    if (bUpdateCS) {
        level.bRegisterItems = 1;
    }
}

/* line 676: G_RegisterWeapon — register a weapon for use during map initialization.
   Called via BG_GetWeaponIndexForName callback during level.initializing. */
extern qboolean itemRegistered[];
extern int G_XModelBad(int modelIndex);
extern void G_OverrideModel(int modelIndex, const char *replacement);
extern int G_GetHintStringIndex(int *indexOut, const char *hintString);

void G_RegisterWeapon(int weapIndex)
{
    WeaponDef *weapDef;
    int modelIndex;

    itemRegistered[weapIndex] = 1;

    level.bRegisterItems = 1;
    level.registerWeapons = 1;

    weapDef = BG_GetWeaponDef(weapIndex);

    if (weapDef->szUseHintString && weapDef->szUseHintString[0] &&
        !G_GetHintStringIndex(&weapDef->iUseHintStringIndex, weapDef->szUseHintString))
    {
        Com_Error(1, "Too many different hintstring values on weapons. Max allowed is %i different strings", 12);
    }

    if (weapDef->dropHintString && weapDef->dropHintString[0] &&
        !G_GetHintStringIndex(&weapDef->dropHintStringIndex, weapDef->dropHintString))
    {
        Com_Error(1, "Too many different hintstring values on weapons. Max allowed is %i different strings", 12);
    }

    modelIndex = G_ModelIndex(weapDef->szWorldModel);
    if (modelIndex && G_XModelBad(modelIndex))
        G_OverrideModel(modelIndex, "xmodel/defaultweapon");

    G_ModelIndex(weapDef->szProjectileModel);
}
