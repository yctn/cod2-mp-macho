/* ASM dump from: g_spawn_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_spawn_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern qboolean G_SpawnStringInternal(SpawnVar *spawnVar, const char *key, const char *defaultString, const char **out);
extern void Scr_AddFields(const char *name, const void *fields);
extern void Scr_AddEntityNum(int entNum, int classnum);
extern int Scr_ExecEntThreadNum(int entNum, int classnum, scr_func_t handle, unsigned int paramcount);
extern void Scr_NotifyNum(int entNum, int classnum, int stringValue, unsigned int paramcount);
extern void Scr_Error(const char *msg);
extern void Com_Printf(const char *fmt, ...);
extern int atoi(const char *str);
extern double atof(const char *str);
extern unsigned int Scr_FindField(const char *name, int *type);
extern void Scr_AddInt(int value);
extern void Scr_AddString(const char *value);
extern void Scr_AddFloat(float value);
extern void Scr_AddVector(const float *value);
extern void Scr_AddObject(unsigned int id);
extern void Scr_AddConstString(unsigned int value);
extern void Scr_SetString(scr_string_t *to, unsigned int value);
extern const char *SL_ConvertToString(unsigned int stringValue);
extern int G_GetWeaponIndexForName(const char *name);
extern void *BG_GetWeaponDef(int weaponIndex);
extern const gitem_t *BG_FindItemForWeapon(int weaponIndex);
extern void G_SpawnItem(gentity_t *ent, const gitem_t *item);
extern JCOEF Scr_AddClassField(int classnum, const char *name, unsigned int offset);
extern void GScr_AddFieldsForClient(void);
extern void Scr_ParamError(unsigned int index, const char *error);
extern scr_entref_t Scr_GetEntityRef(unsigned int index);
extern void Scr_FreeHudElemConstStrings(game_hudelem_t *hud);
extern JCOEF Scr_FreeEntityNum(int entnum, int classnum);
extern void Scr_SetDynamicEntityField(int entnum, int classnum, unsigned int index);
extern unsigned int G_NewString(const char *string);
extern int I_stricmp(const char *s0, const char *s1);
extern unsigned char G_SetModel(gentity_t *ent, const char *modelName);
extern const char *G_ModelName(int index);
extern unsigned int Scr_GetConstString(unsigned int index);
extern const char *Scr_GetString(unsigned int index);
extern int Scr_GetOffset(int classnum, const char *name);
extern unsigned int Scr_GetNumParam(void);
extern void Scr_MakeArray(void);
extern void Scr_AddArray(void);

extern spawn_t spawns[22]; /* 0x0 */
static const ent_field_t fields[11]; /* fields */

qboolean G_SpawnString(const char *key, const char *defaultString, const char * *out);
static void Scr_ReadOnlyField(gentity_t *ent, int offset);
static unsigned int __attribute__((regparm(2))) G_SetEntityScriptVariableInternal(const char *key, const char *value);
void G_DuplicateEntityFields(gentity_t *dest, const gentity_t *source);
static const gitem_t * __attribute__((regparm(1))) G_GetItemForClassname(const char *classname);
qboolean G_CallSpawnEntity(gentity_t *ent);
void GScr_AddFieldsForEntity(void);
void GScr_AddFieldsForRadiant(void);
void Scr_AddEntity(gentity_t *ent);
gentity_t * Scr_GetEntity(unsigned int index);
void Scr_FreeHudElem(game_hudelem_t *hud);
void Scr_AddHudElem(game_hudelem_t *hud);
scr_thread_t Scr_ExecEntThread(gentity_t *ent, scr_func_t handle, unsigned int paramcount);
void Scr_Notify(gentity_t *ent, int stringValue, unsigned int paramcount);
static void __attribute__((regparm(3))) G_ParseEntityField(const char *key, const char *value, gentity_t *ent);
void Scr_GetGenericField(byte *b, fieldtype_t type, int ofs);
void Scr_GetEnt(void);
void Scr_GetEntArray(void);
qboolean G_SpawnFloat(const char *key, const char *defaultString, float *out);
qboolean G_SpawnInt(const char *key, const char *defaultString, int *out);
qboolean G_SpawnVector(const char *key, const char *defaultString, float *out);
void SP_worldspawn(void);
void G_LoadStructs(void);
void Scr_SetGenericField(byte *b, fieldtype_t type, int ofs);
qboolean Scr_SetObjectField(unsigned int classnum, int entnum, int offset);
void Scr_GetObjectField(unsigned int classnum, int entnum, int offset);
void Scr_FreeEntity(gentity_t *ent);
void G_CallSpawn(void);
void G_SpawnEntitiesFromString(void);

static level_locals_t *G_Level(void)
{
    return (level_locals_t *)imp_level;
}

static SpawnVar *G_LevelSpawnVar(void)
{
    return &G_Level()->spawnVar;
}

static gentity_t *G_Entities(void)
{
    return (gentity_t *)imp_g_entities;
}

static int G_HudElemIndex(const game_hudelem_t *hud)
{
    return (int)(hud - (const game_hudelem_t *)imp_g_hudelems);
}

/* line 7 */
qboolean G_SpawnString(const char *key, const char *defaultString, const char * *out)
{
    return G_SpawnStringInternal(G_LevelSpawnVar(), key, defaultString, out);
}

/* line 47 */
static void Scr_ReadOnlyField(gentity_t *ent, int offset)
{
    Scr_Error((const char *)str_002b33d0);
}

/* line 160 */
static unsigned int __attribute__((regparm(2))) G_SetEntityScriptVariableInternal(const char *key, const char *value)
{
    int type;
    unsigned int index;

    index = Scr_FindField(key, &type);
    if (!index) {
        return 0;
    }

    switch (type) {
    case 2:
        Scr_AddString(value);
        break;
    case 4:
    {
        vec3_t vec = {0.0f, 0.0f, 0.0f};
        sscanf(value, "%f %f %f", &vec[0], &vec[1], &vec[2]);
        Scr_AddVector(vec);
        break;
    }
    case 5:
        Scr_AddFloat((float)atof(value));
        break;
    case 6:
        Scr_AddInt(atoi(value));
        break;
    default:
        break;
    }

    return index;
}

/* line 337 */
void G_DuplicateEntityFields(gentity_t *dest, const gentity_t *source)
{
    const ent_field_t *field;

    for (field = fields; field->name; ++field) {
        switch (field->type) {
        case F_INT:
        case F_FLOAT:
            *(int *)((byte *)dest + field->ofs) = *(const int *)((const byte *)source + field->ofs);
            break;
        case F_STRING:
            Scr_SetString((scr_string_t *)((byte *)dest + field->ofs), *(const scr_string_t *)((const byte *)source + field->ofs));
            break;
        case F_VECTOR:
        {
            vec3_t *destVec = (vec3_t *)((byte *)dest + field->ofs);
            const vec3_t *sourceVec = (const vec3_t *)((const byte *)source + field->ofs);

            (*destVec)[0] = (*sourceVec)[0];
            (*destVec)[1] = (*sourceVec)[1];
            (*destVec)[2] = (*sourceVec)[2];
            break;
        }
        case F_MODEL:
            *(byte *)((byte *)dest + field->ofs) = *(const byte *)((const byte *)source + field->ofs);
            break;
        default:
            break;
        }
    }
}

/* line 392 */
static const gitem_t * __attribute__((regparm(1))) G_GetItemForClassname(const char *classname)
{
    int weaponIndex;
    int itemIndex;
    int bgNumItems;
    gitem_t *bgItemList;

    if (!strncmp(classname, "weapon_", 7)) {
        weaponIndex = G_GetWeaponIndexForName(classname + 7);
        if (weaponIndex) {
            BG_GetWeaponDef(weaponIndex);
            return BG_FindItemForWeapon(weaponIndex);
        }
    }

    bgNumItems = *(int *)imp_bg_numItems;
    if (bgNumItems <= 0x81) {
        return NULL;
    }

    bgItemList = (gitem_t *)imp_bg_itemlist;
    for (itemIndex = 0x81; itemIndex < bgNumItems; ++itemIndex) {
        if (!strcmp(bgItemList[itemIndex].classname, classname)) {
            return &bgItemList[itemIndex];
        }
    }

    return NULL;
}

/* line 481 */
qboolean G_CallSpawnEntity(gentity_t *ent)
{
    const char *classname;
    const gitem_t *item;
    int i;

    if (!ent->classname) {
        Com_Printf((const char *)str_002b3400);
        return 0;
    }

    classname = SL_ConvertToString(ent->classname);
    item = G_GetItemForClassname(classname);
    if (item) {
        G_SpawnItem(ent, item);
        return 1;
    }

    for (i = 0; spawns[i].name; ++i) {
        if (!strcmp(spawns[i].name, classname)) {
            ((void (*)(gentity_t *))spawns[i].spawn)(ent);
            return 1;
        }
    }

    Com_Printf("%s doesn't have a spawn function\n", SL_ConvertToString(ent->classname));
    return 0;
}

/* line 523 */
void GScr_AddFieldsForEntity(void)
{
    int i;

    for (i = 0; fields[i].name; ++i) {
        Scr_AddClassField(0, fields[i].name, (unsigned int)i);
    }

    GScr_AddFieldsForClient();
}

/* line 543 */
void GScr_AddFieldsForRadiant(void)
{
    Scr_AddFields("radiant", (const void *)str_002b3448);
}

/* line 814 */
void Scr_AddEntity(gentity_t *ent)
{
    Scr_AddEntityNum(*(int *)ent, 0);
}

/* line 829 */
gentity_t * Scr_GetEntity(unsigned int index)
{
    scr_entref_t ref;

    ref = Scr_GetEntityRef(index);
    if (ref.classnum) {
        Scr_ParamError(index, (const char *)str_002b21c8);
        return NULL;
    }

    return &G_Entities()[ref.entnum];
}

/* line 849 */
void Scr_FreeHudElem(game_hudelem_t *hud)
{
    Scr_FreeHudElemConstStrings(hud);
    Scr_FreeEntityNum(G_HudElemIndex(hud), 1);
}

/* line 865 */
void Scr_AddHudElem(game_hudelem_t *hud)
{
    Scr_AddEntityNum(G_HudElemIndex(hud), 1);
}

/* line 900 */
scr_thread_t Scr_ExecEntThread(gentity_t *ent, scr_func_t handle, unsigned int paramcount)
{
    return (unsigned short)Scr_ExecEntThreadNum(*(int *)ent, 0, handle, paramcount);
}

/* line 930 */
void Scr_Notify(gentity_t *ent, int stringValue, unsigned int paramcount)
{
    Scr_NotifyNum(*(int *)ent, 0, (unsigned short)stringValue, paramcount);
}

/* line 225 */
static void __attribute__((regparm(3))) G_ParseEntityField(const char *key, const char *value, gentity_t *ent)
{
    const ent_field_t *field;
    unsigned int index;

    for (field = fields; field->name; ++field) {
        if (!I_stricmp(field->name, key)) {
            byte *fieldData = (byte *)ent + field->ofs;

            switch (field->type) {
            case F_INT:
                *(int *)fieldData = atoi(value);
                break;
            case F_FLOAT:
                *(float *)fieldData = (float)atof(value);
                break;
            case F_STRING:
                Scr_SetString((scr_string_t *)fieldData, 0);
                *(scr_string_t *)fieldData = (scr_string_t)G_NewString(value);
                break;
            case F_VECTOR:
            {
                vec3_t vec = {0.0f, 0.0f, 0.0f};
                sscanf(value, "%f %f %f", &vec[0], &vec[1], &vec[2]);
                ((vec3_t *)fieldData)[0][0] = vec[0];
                ((vec3_t *)fieldData)[0][1] = vec[1];
                ((vec3_t *)fieldData)[0][2] = vec[2];
                break;
            }
            case F_MODEL:
                if (*value == '*') {
                    ent->model = (byte)(unsigned short)atoi(value + 1);
                } else {
                    G_SetModel(ent, value);
                }
                break;
            default:
                break;
            }

            return;
        }
    }

    index = G_SetEntityScriptVariableInternal(key, value);
    if (index) {
        Scr_SetDynamicEntityField(ent->s.number, 0, index);
    }
}

/* line 689 */
void Scr_GetGenericField(byte *b, fieldtype_t type, int ofs)
{
    switch (type) {
    case F_INT:
        Scr_AddInt(*(int *)(b + ofs));
        break;
    case F_FLOAT:
        Scr_AddFloat(*(float *)(b + ofs));
        break;
    case F_LSTRING:
        Scr_AddString((const char *)(b + ofs));
        break;
    case F_STRING:
    {
        scr_string_t stringValue = *(scr_string_t *)(b + ofs);
        if (stringValue) {
            Scr_AddConstString(stringValue);
        }
        break;
    }
    case F_VECTOR:
        Scr_AddVector((float *)(b + ofs));
        break;
    case F_ENTITY:
    {
        gentity_t *ent = *(gentity_t **)(b + ofs);
        if (ent) {
            Scr_AddEntityNum(ent->s.number, 0);
        }
        break;
    }
    case F_VECTORHACK:
    {
        vec3_t vec = {0.0f, *(float *)(b + ofs), 0.0f};
        Scr_AddVector(vec);
        break;
    }
    case F_OBJECT:
    {
        unsigned int objectId = *(scr_string_t *)(b + ofs);
        if (objectId) {
            Scr_AddObject(objectId);
        }
        break;
    }
    case F_MODEL:
        Scr_AddString(G_ModelName(*(byte *)(b + ofs)));
        break;
    default:
        break;
    }
}

/* line 945 */
void Scr_GetEnt(void)
{
    scr_string_t name;
    int offset;
    const ent_field_t *field;
    gentity_t *found;
    int i;
    level_locals_t *level;
    gentity_t *gentities;

    name = (scr_string_t)Scr_GetConstString(0);
    offset = Scr_GetOffset(0, Scr_GetString(1));
    if (offset < 0) {
        return;
    }

    field = &fields[offset];
    if (field->type != F_STRING) {
        return;
    }

    level = G_Level();
    gentities = G_Entities();
    found = NULL;

    for (i = 0; i < level->num_entities; ++i) {
        gentity_t *ent = &gentities[i];
        scr_string_t fieldValue;

        if (!ent->r.inuse) {
            continue;
        }

        fieldValue = *(scr_string_t *)((byte *)ent + field->ofs);
        if (!fieldValue || fieldValue != name) {
            continue;
        }

        if (found) {
            Scr_Error((const char *)str_002b3454);
        }
        found = ent;
    }

    if (found) {
        Scr_AddEntityNum(found->s.number, 0);
    }
}

/* line 998 */
void Scr_GetEntArray(void)
{
    level_locals_t *level;
    gentity_t *gentities;
    int i;

    level = G_Level();
    gentities = G_Entities();

    if (!Scr_GetNumParam()) {
        Scr_MakeArray();
        for (i = 0; i < level->num_entities; ++i) {
            if (!gentities[i].r.inuse) {
                continue;
            }
            Scr_AddEntityNum(gentities[i].s.number, 0);
            Scr_AddArray();
        }
        return;
    }

    {
        scr_string_t name = (scr_string_t)Scr_GetConstString(0);
        int offset = Scr_GetOffset(0, Scr_GetString(1));
        const ent_field_t *field;

        if (offset < 0) {
            return;
        }

        field = &fields[offset];
        if (field->type != F_STRING) {
            return;
        }

        Scr_MakeArray();
        for (i = 0; i < level->num_entities; ++i) {
            scr_string_t fieldValue;

            if (!gentities[i].r.inuse) {
                continue;
            }

            fieldValue = *(scr_string_t *)((byte *)&gentities[i] + field->ofs);
            if (!fieldValue || fieldValue != name) {
                continue;
            }

            Scr_AddEntityNum(gentities[i].s.number, 0);
            Scr_AddArray();
        }
    }
}

/* line 13 */
qboolean G_SpawnFloat(const char *key, const char *defaultString, float *out)
{
    const char *s;
    qboolean present;

    present = G_SpawnStringInternal(G_LevelSpawnVar(), key, defaultString, &s);
    *out = (float)atof(s);
    return present;
}

/* line 24 */
qboolean G_SpawnInt(const char *key, const char *defaultString, int *out)
{
    const char *s;
    qboolean present;

    present = G_SpawnStringInternal(G_LevelSpawnVar(), key, defaultString, &s);
    *out = atoi(s);
    return present;
}

/* line 35 */
qboolean G_SpawnVector(const char *key, const char *defaultString, float *out)
{
    const char *s;
    qboolean present;

    present = G_SpawnStringInternal(G_LevelSpawnVar(), key, defaultString, &s);
    out[0] = 0.0f;
    out[1] = 0.0f;
    out[2] = 0.0f;
    sscanf(s, "%f %f %f", &out[0], &out[1], &out[2]);
    return present;
}

/* line 1063 */
__attribute__((naked))
void SP_worldspawn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1063 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "leal -0x1c(%ebp), %edi\n" /* line 9 | s */
        "movl %edi, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl $str_0021c208, 4(%esp)\n" /* "classname" */
        "movl imp_level, %esi\n"
        "leal 0x1348(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl $str_002b347c, 4(%esp)\n" /* line 1068 */
        "movl -0x1c(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf19ecb4_0019eef9\n"
        ".Lf19ecb4_0019ed03:\n"
        "movl $str_002a89ec, 4(%esp)\n" /* line 1074 */
        "movl $2, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0x1f8(%esi), %eax\n" /* line 1076 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xd, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $str_002157b8, 8(%esp)\n"
        "movl $str_002b34bc, 4(%esp)\n" /* "ambienttrack" */
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1079 | s */
        "cmpb $0, (%eax)\n"
        "je .Lf19ecb4_0019eec7\n"
        "movl %eax, 4(%esp)\n" /* line 1080 */
        "movl $str_002b34cc, (%esp)\n" /* "n\%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SV_SetConfigstring\n"
        ".Lf19ecb4_0019ed85:\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $str_002157b8, 8(%esp)\n"
        "movl $str_002b34d4, 4(%esp)\n" /* "message" */
        "movl imp_level, %ebx\n"
        "addl $0x1348, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1085 | s */
        "movl %eax, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl imp_g_motd, %eax\n" /* line 1087 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xe, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $str_002b34dc, 8(%esp)\n" /* "800" */
        "movl $str_0021a8b4, 4(%esp)\n" /* "gravity" */
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1091 | s */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x30(%ebp)\n"
        "cvtsd2ss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl imp_g_gravity, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFloat\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $str_002157b8, 8(%esp)\n"
        "movl $str_002b34e0, 4(%esp)\n" /* "northyaw" */
        "movl %ebx, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1094 | s */
        "cmpb $0, (%eax)\n"
        "je .Lf19ecb4_0019eee0\n"
        "movl %eax, 4(%esp)\n" /* line 1095 */
        "movl $0xb, (%esp)\n"
        "calll SV_SetConfigstring\n"
        ".Lf19ecb4_0019ee56:\n"
        "movl %edi, 0xc(%esp)\n" /* line 9 */
        "movl $str_0021952c, 8(%esp)\n" /* "0" */
        "movl $str_002b33a4, 4(%esp)\n" /* "spawnflags" */
        "movl imp_level, %eax\n"
        "addl $0x1348, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1100 | s */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl imp_g_entities, %ebx\n"
        "movl %eax, 0x8bd10(%ebx)\n"
        "movl $0x3fe, 0x8bba0(%ebx)\n" /* line 1102 */
        "movl imp_scr_const, %eax\n" /* line 1103 */
        "movzwl 0x60(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x8bd08(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movb $1, 0x8bc9c(%ebx)\n" /* line 1104 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1105 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19ecb4_0019eec7:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 1082 */
        "movl $3, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf19ecb4_0019ed85\n"
        ".Lf19ecb4_0019eee0:\n"
        "movl $str_0021952c, 4(%esp)\n" /* line 1097 */
        "movl $0xb, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf19ecb4_0019ee56\n"
        ".Lf19ecb4_0019eef9:\n"
        "movl $str_002b3488, 4(%esp)\n" /* line 1070 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19ecb4_0019ed03\n"
    );
}

/* line 1137 */
__attribute__((naked))
void G_LoadStructs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1137 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl $0, 4(%esp)\n" /* line 1143 */
        "movl imp_g_scr_data, %eax\n"
        "movl 0x10b0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_ExecThread\n"
        "movzwl %ax, %eax\n" /* line 1144 */
        "movl %eax, (%esp)\n"
        "calll Scr_FreeThread\n"
        "movl imp_level, %ebx\n"
        "movl %ebx, -0x30(%ebp)\n"
        "jmp .Lf19ef12_0019ef52\n"
        ".Lf19ef12_0019ef4c:\n"
        "movl imp_level, %ebx\n"
        ".Lf19ef12_0019ef52:\n"
        "leal 0x1348(%ebx), %esi\n" /* line 1146 */
        "movl %esi, (%esp)\n"
        "calll G_ParseSpawnVars\n"
        "testl %eax, %eax\n"
        "je .Lf19ef12_0019f027\n"
        "leal -0x1c(%ebp), %eax\n" /* line 9 | classname */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl $str_0021c208, 4(%esp)\n" /* "classname" */
        "movl %esi, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1149 | classname */
        "movl $str_002b3394, %esi\n" /* "script_struct" */
        "movl $0xe, %ecx\n"
        "cld\n"
        "movl %eax, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf19ef12_0019efaa\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf19ef12_0019efaa:\n"
        "testl %eax, %eax\n"
        "jne .Lf19ef12_0019ef4c\n"
        "movl $0, 4(%esp)\n" /* line 318 */
        "movl imp_g_scr_data, %eax\n"
        "movl 0x10b4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddExecThread\n"
        "movl $0, (%esp)\n" /* line 319 */
        "calll Scr_GetObject\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x134c(%ebx), %eax\n" /* line 321 */
        "testl %eax, %eax\n"
        "jle .Lf19ef12_0019ef4c\n"
        "xorl %edi, %edi\n"
        "movl %ebx, %esi\n"
        "jmp .Lf19ef12_0019f001\n"
        ".Lf19ef12_0019efec:\n"
        "addl $1, %edi\n"
        "addl $8, %esi\n"
        "movl -0x30(%ebp), %ebx\n"
        "cmpl 0x134c(%ebx), %edi\n"
        "jge .Lf19ef12_0019ef52\n"
        ".Lf19ef12_0019f001:\n"
        "movl 0x1354(%esi), %edx\n" /* line 323 */
        "movl 0x1350(%esi), %eax\n"
        "calll G_SetEntityScriptVariableInternal\n"
        "testl %eax, %eax\n" /* line 324 */
        "je .Lf19ef12_0019efec\n"
        "movl %eax, 4(%esp)\n" /* line 327 */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetStructField\n"
        "jmp .Lf19ef12_0019efec\n"
        ".Lf19ef12_0019f027:\n"
        "calll SV_ResetEntityParsePoint\n" /* line 1153 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 594 */
__attribute__((naked))
void Scr_SetGenericField(byte *b, fieldtype_t type, int ofs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 594 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* type */
        /* { scope 1 */
        "cmpl $6, %eax\n" /* line 598 */
        "ja .Lf19f034_0019f084\n"
        "jmpl *.Ljt_19f034_0(, %eax, 4)\n"
        ".Lf19f034_0019f04a:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 620 | ofs */
        "addl 8(%ebp), %ebx\n" /* b */
        "movl $0, (%esp)\n" /* line 833 */
        "calll Scr_GetEntityRef\n"
        "movl %eax, %edx\n"
        "shrl $0x10, %eax\n" /* line 834 */
        "testw %ax, %ax\n"
        "jne .Lf19f034_0019f12b\n"
        "movzwl %dx, %eax\n" /* line 837 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "movl %edx, (%ebx)\n" /* line 620 */
        /* } scope */
        ".Lf19f034_0019f084:\n"
        "addl $0x24, %esp\n" /* line 626 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f034_0019f08a:\n"
        "movl $0, (%esp)\n" /* line 610 */
        "calll Scr_GetInt\n"
        "movl 8(%ebp), %edx\n" /* b */
        "movl 0x10(%ebp), %ecx\n" /* ofs */
        "movl %eax, (%edx, %ecx)\n"
        "jmp .Lf19f034_0019f084\n"
        ".Lf19f034_0019f0a1:\n"
        "leal -0x14(%ebp), %eax\n" /* line 616 | vec */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl -0x10(%ebp), %eax\n" /* line 617 */
        "movl 8(%ebp), %ecx\n" /* b */
        "movl 0x10(%ebp), %edx\n" /* ofs */
        "movl %eax, (%ecx, %edx)\n"
        "jmp .Lf19f034_0019f084\n"
        ".Lf19f034_0019f0c2:\n"
        "leal -0x14(%ebp), %eax\n" /* line 604 | vec */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movl 8(%ebp), %edx\n" /* line 605 | b */
        "addl 0x10(%ebp), %edx\n" /* ofs */
        "movl -0x14(%ebp), %eax\n" /* vec */
        "movl %eax, (%edx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 606 */
        "movl %eax, 4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 607 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf19f034_0019f084\n"
        ".Lf19f034_0019f0ee:\n"
        "movl $0, (%esp)\n" /* line 601 */
        "calll Scr_GetConstStringIncludeNull\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* b */
        "addl 0x10(%ebp), %eax\n" /* ofs */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "jmp .Lf19f034_0019f084\n"
        ".Lf19f034_0019f111:\n"
        "movl $0, (%esp)\n" /* line 613 */
        "calll Scr_GetFloat\n"
        "movl 8(%ebp), %eax\n" /* b */
        "movl 0x10(%ebp), %edx\n" /* ofs */
        "fstps (%eax, %edx)\n"
        "jmp .Lf19f034_0019f084\n"
        ".Lf19f034_0019f12b:\n"
        "movl $str_002b21c8, 4(%esp)\n" /* line 839 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "xorl %edx, %edx\n"
        "movl %edx, (%ebx)\n" /* line 620 */
        "jmp .Lf19f034_0019f084\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_19f034_0:\n"
        ".long .Lf19f034_0019f08a\n"
        ".long .Lf19f034_0019f111\n"
        ".long .Lf19f034_0019f084\n"
        ".long .Lf19f034_0019f0ee\n"
        ".long .Lf19f034_0019f0c2\n"
        ".long .Lf19f034_0019f04a\n"
        ".long .Lf19f034_0019f0a1\n"
        ".text\n"
    );
}

/* line 634 */
__attribute__((naked))
qboolean Scr_SetObjectField(unsigned int classnum, int entnum, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 634 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* classnum */
        "movl 0xc(%ebp), %eax\n" /* entnum */
        "movl 0x10(%ebp), %ecx\n" /* offset */
        "testl %edx, %edx\n" /* line 636 */
        "je .Lf19f148_0019f16c\n"
        "subl $1, %edx\n"
        "je .Lf19f148_0019f1b5\n"
        ".Lf19f148_0019f161:\n"
        "movl $1, %eax\n" /* line 641 */
        ".Lf19f148_0019f166:\n"
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f148_0019f16c:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 561 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl imp_g_entities, %edx\n"
        "movl %ecx, %eax\n" /* line 564 */
        "andl $0xc000, %eax\n"
        "cmpl $0xc000, %eax\n"
        "je .Lf19f148_0019f1c3\n"
        "movl %ecx, %eax\n" /* line 576 */
        "shll $4, %eax\n"
        "leal fields(%eax), %ebx\n" /* f */
        "movl 0xc(%ebx), %eax\n" /* line 578 | f */
        "testl %eax, %eax\n"
        "je .Lf19f148_0019f1e7\n"
        "movl %ecx, 4(%esp)\n" /* line 580 */
        "movl %edx, (%esp)\n"
        "calll *%eax\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19f148_0019f1b5:\n"
        "movl %ecx, 4(%esp)\n" /* line 641 */
        "movl %eax, (%esp)\n"
        "calll Scr_SetHudElemField\n"
        "jmp .Lf19f148_0019f161\n"
        /* { scope 1 */
        ".Lf19f148_0019f1c3:\n"
        "movl 0x158(%edx), %eax\n" /* line 566 */
        "testl %eax, %eax\n"
        "je .Lf19f148_0019f166\n"
        "andb $0x3f, %ch\n" /* line 569 */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetClientField\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f148_0019f1e7:\n"
        "movl 4(%ebx), %eax\n" /* line 584 | f */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebx), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Scr_SetGenericField\n"
        "movl $1, %eax\n"
        "jmp .Lf19f148_0019f166\n"
    );
}

/* line 746 */
__attribute__((naked))
void Scr_GetObjectField(unsigned int classnum, int entnum, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 746 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* classnum */
        "movl 0xc(%ebp), %eax\n" /* entnum */
        "movl 0x10(%ebp), %ebx\n" /* offset */
        "testl %edx, %edx\n" /* line 748 */
        "je .Lf19f208_0019f221\n"
        "subl $1, %edx\n"
        "je .Lf19f208_0019f27d\n"
        ".Lf19f208_0019f21e:\n"
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f208_0019f221:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 664 */
        "leal (, %eax, 8), %ecx\n"
        "subl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "addl imp_g_entities, %ecx\n"
        "movl %ebx, %eax\n" /* line 667 */
        "andl $0xc000, %eax\n"
        "cmpl $0xc000, %eax\n"
        "je .Lf19f208_0019f263\n"
        "shll $4, %ebx\n" /* line 679 */
        "leal fields(%ebx), %eax\n"
        "movl 4(%eax), %edx\n" /* line 680 */
        "movl %edx, 0x10(%ebp)\n" /* offset */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* entnum */
        "movl %ecx, 8(%ebp)\n" /* classnum */
        /* } scope */
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_GetGenericField\n" /* line 680 */
        ".Lf19f208_0019f263:\n"
        "movl 0x158(%ecx), %eax\n" /* line 669 */
        "testl %eax, %eax\n"
        "je .Lf19f208_0019f21e\n"
        "andb $0x3f, %bh\n" /* line 672 */
        "movl %ebx, 0xc(%ebp)\n" /* entnum */
        "movl %eax, 8(%ebp)\n" /* classnum */
        /* } scope */
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_GetClientField\n" /* line 672 */
        /* } scope */
        ".Lf19f208_0019f27d:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 754 | offset, entnum */
        "movl %eax, 8(%ebp)\n" /* classnum */
        "popl %ebx\n" /* line 760 */
        "popl %ebp\n"
        "jmp Scr_GetHudElemField\n" /* line 754 */
    );
}

/* line 798 */
__attribute__((naked))
void Scr_FreeEntity(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 798 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl fields, %eax\n" /* line 776 */
        "testl %eax, %eax\n"
        "je .Lf19f28a_0019f2d2\n"
        "movl $fields+8, %ebx\n"
        "jmp .Lf19f28a_0019f2ad\n"
        ".Lf19f28a_0019f2a3:\n"
        "movl 8(%ebx), %eax\n"
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lf19f28a_0019f2d2\n"
        ".Lf19f28a_0019f2ad:\n"
        "cmpl $3, (%ebx)\n" /* line 778 */
        "jne .Lf19f28a_0019f2a3\n"
        "movl $0, 4(%esp)\n" /* line 781 */
        "movl 8(%ebp), %eax\n" /* ent */
        "addl -4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 8(%ebx), %eax\n" /* line 776 */
        "addl $0x10, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf19f28a_0019f2ad\n"
        ".Lf19f28a_0019f2d2:\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "xorl %edi, %edi\n" /* i */
        "movl %esi, %ebx\n"
        "addl $0x218, %ebx\n"
        ".Lf19f28a_0019f2df:\n"
        "movb $0, 0x210(%esi)\n" /* line 787 */
        "movl $0, 4(%esp)\n" /* line 788 */
        "movl %ebx, (%esp)\n"
        "calll Scr_SetString\n"
        "addl $1, %edi\n" /* line 785 | i */
        "addl $2, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $7, %edi\n" /* i */
        "jne .Lf19f28a_0019f2df\n"
        /* } scope */
        "movl $0, 4(%esp)\n" /* line 805 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_FreeEntityNum\n"
        "addl $0x1c, %esp\n" /* line 806 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 429 */
__attribute__((naked))
void G_CallSpawn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 429 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: i */
        "leal -0x1c(%ebp), %eax\n" /* line 9 | classname */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl $str_0021c208, 4(%esp)\n" /* "classname" */
        "movl imp_level, %ebx\n"
        "leal 0x1348(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnStringInternal\n"
        "movl -0x1c(%ebp), %eax\n" /* line 438 | classname */
        "testl %eax, %eax\n"
        "je .Lf19f322_0019f48b\n"
        "calll G_GetItemForClassname\n" /* line 444 */
        "movl %eax, -0x30(%ebp)\n" /* item */
        "testl %eax, %eax\n" /* line 445 */
        "je .Lf19f322_0019f3bd\n"
        "calll G_Spawn\n" /* line 447 */
        "movl %eax, %esi\n" /* ent */
        /* { scope 2 */
        "movl 0x134c(%ebx), %edi\n" /* line 295 | i */
        "testl %edi, %edi\n" /* i */
        "jg .Lf19f322_0019f42d\n"
        ".Lf19f322_0019f382:\n"
        "leal 0x138(%esi), %eax\n" /* line 298 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetOrigin\n"
        "leal 0x144(%esi), %eax\n" /* line 299 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetAngle\n"
        /* } scope */
        "movl -0x30(%ebp), %edx\n" /* line 449 | item */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll G_SpawnItem\n"
        /* } scope */
        ".Lf19f322_0019f3b5:\n"
        "addl $0x4c, %esp\n" /* line 470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf19f322_0019f3bd:\n"
        "movl spawns, %eax\n" /* line 454 */
        "testl %eax, %eax\n"
        "je .Lf19f322_0019f3eb\n"
        "movl -0x1c(%ebp), %esi\n" /* line 456 | classname, ent */
        "movl $spawns, %ebx\n" /* s */
        ".Lf19f322_0019f3ce:\n"
        "movl %esi, 4(%esp)\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf19f322_0019f49f\n"
        "addl $8, %ebx\n" /* line 454 | s */
        "movl (%ebx), %eax\n" /* s */
        "testl %eax, %eax\n"
        "jne .Lf19f322_0019f3ce\n"
        ".Lf19f322_0019f3eb:\n"
        "calll G_Spawn\n" /* line 468 */
        "movl %eax, %esi\n" /* ent */
        /* { scope 2 */
        "movl imp_level, %eax\n" /* line 295 */
        "movl 0x134c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf19f322_0019f45b\n"
        ".Lf19f322_0019f401:\n"
        "leal 0x138(%esi), %eax\n" /* line 298 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetOrigin\n"
        "leal 0x144(%esi), %eax\n" /* line 299 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetAngle\n"
        /* } scope */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2 */
        ".Lf19f322_0019f42d:\n"
        "xorl %edi, %edi\n" /* line 295 | i */
        "movl %ebx, -0x34(%ebp)\n"
        ".Lf19f322_0019f432:\n"
        "movl 0x1354(%ebx), %edx\n" /* line 296 */
        "movl 0x1350(%ebx), %eax\n"
        "movl %esi, %ecx\n"
        "calll G_ParseEntityField\n"
        "addl $1, %edi\n" /* line 295 | i */
        "addl $8, %ebx\n"
        "movl -0x34(%ebp), %eax\n"
        "cmpl 0x134c(%eax), %edi\n" /* i */
        "jl .Lf19f322_0019f432\n"
        "jmp .Lf19f322_0019f382\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19f322_0019f45b:\n"
        "xorl %edi, %edi\n" /* i */
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, %ebx\n"
        ".Lf19f322_0019f462:\n"
        "movl 0x1354(%ebx), %edx\n" /* line 296 */
        "movl 0x1350(%ebx), %eax\n"
        "movl %esi, %ecx\n"
        "calll G_ParseEntityField\n"
        "addl $1, %edi\n" /* line 295 | i */
        "addl $8, %ebx\n"
        "movl -0x3c(%ebp), %eax\n"
        "cmpl 0x134c(%eax), %edi\n" /* i */
        "jl .Lf19f322_0019f462\n"
        "jmp .Lf19f322_0019f401\n"
        /* } scope */
        ".Lf19f322_0019f48b:\n"
        "movl $str_002b34ec, (%esp)\n" /* line 440 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf19f322_0019f49f:\n"
        "movl imp_G_FreeEntity, %eax\n" /* line 458 */
        "cmpl %eax, 4(%ebx)\n" /* s */
        "je .Lf19f322_0019f3b5\n"
        "calll G_Spawn\n" /* line 460 */
        "movl %eax, %edi\n" /* i */
        /* { scope 2 */
        "movl imp_level, %eax\n" /* line 295 */
        "movl 0x134c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf19f322_0019f4f2\n"
        ".Lf19f322_0019f4c3:\n"
        "leal 0x138(%edi), %eax\n" /* line 298 | i */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* i */
        "calll G_SetOrigin\n"
        "leal 0x144(%edi), %eax\n" /* line 299 | i */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* i */
        "calll G_SetAngle\n"
        /* } scope */
        "movl %edi, (%esp)\n" /* line 462 | i */
        "calll *4(%ebx)\n" /* s */
        "jmp .Lf19f322_0019f3b5\n"
        /* { scope 2 */
        ".Lf19f322_0019f4f2:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 295 | i */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %esi\n"
        ".Lf19f322_0019f4fe:\n"
        "movl 0x1354(%esi), %edx\n" /* line 296 */
        "movl 0x1350(%esi), %eax\n"
        "movl %edi, %ecx\n" /* i */
        "calll G_ParseEntityField\n"
        "addl $1, -0x2c(%ebp)\n" /* line 295 | i */
        "addl $8, %esi\n"
        "movl -0x2c(%ebp), %edx\n" /* i */
        "movl -0x38(%ebp), %eax\n"
        "cmpl 0x134c(%eax), %edx\n"
        "jl .Lf19f322_0019f4fe\n"
        "jmp .Lf19f322_0019f4c3\n"
    );
}

/* line 1115 */
__attribute__((naked))
void G_SpawnEntitiesFromString(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1115 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_level, %eax\n" /* line 1120 */
        "addl $0x1348, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ParseSpawnVars\n"
        "testl %eax, %eax\n"
        "je .Lf19f528_0019f56f\n"
        ".Lf19f528_0019f545:\n"
        "calll SP_worldspawn\n" /* line 1123 */
        "movl imp_level, %ebx\n"
        "addl $0x1348, %ebx\n"
        "jmp .Lf19f528_0019f55d\n"
        ".Lf19f528_0019f558:\n"
        "calll G_CallSpawn\n" /* line 1127 */
        ".Lf19f528_0019f55d:\n"
        "movl %ebx, (%esp)\n" /* line 1126 */
        "calll G_ParseSpawnVars\n"
        "testl %eax, %eax\n"
        "jne .Lf19f528_0019f558\n"
        "addl $0x14, %esp\n" /* line 1128 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19f528_0019f56f:\n"
        "movl $str_002b350c, 4(%esp)\n" /* line 1121 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf19f528_0019f545\n"
    );
}
