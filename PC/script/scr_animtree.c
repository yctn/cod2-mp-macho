/* ASM dump from: scr_animtree.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_animtree.cpp */

#include "common_types.h"
#include "imports.h"

extern void Com_Printf(const char *fmt, ...);
extern int MT_SearchTreeAny(int nodeNum);

enum {
    SCR_ANIMTREE_NAMES = 0,
    SCR_ANIMTREE_XANIM = 1,
    SCR_VAR_POINTER = 1,
    SCR_VAR_INTEGER = 6,
    SCR_VAR_CODEPOS = 7,
    SCR_SL_MAX_STRING_INDEX = 0x10000,
    SCR_MAX_XANIMTREE_NUM = 128,
    SCR_ANIM_FLAG_LOOPSYNC = 1,
    SCR_ANIM_FLAG_NONLOOPSYNC = 2,
    SCR_ANIM_FLAG_COMPLETE = 8,
};

extern struct scrAnimPub_t scrAnimPub; /* 0x0 */
extern struct scrVarPub_t scrVarPub; /* 0x0 */
extern struct scrParserPub_t scrParserPub; /* 0x0 */
extern struct scrAnimGlob_t scrAnimGlob; /* scrAnimGlob - BSS */
extern const char str_0021dd64[];
extern const char str_0021dd70[];
extern const char str_0021dd7c[];

__attribute__((used, packed, aligned(4)))
UInt32 propertyNames_storage[8] = {
    (UInt32)str_0021dd64,
    (UInt32)str_0021dd70,
    (UInt32)str_0021dd7c,
    0,
    0,
    0,
    0,
    0,
}; /* 0x30aa80 */

#define propertyNames ((const char * const *)propertyNames_storage)

extern void * Hunk_AllocAlignInternal(int size, int align);

void SetAnimCheck(int bAnimCheck);
static void * Hunk_AllocXAnimTreePrecache(int size);
static void Scr_EmitAnimationInternal(char *pos, unsigned int animName, unsigned int names);
static int Scr_GetAnimTreeSize(unsigned int parentNode);
static void ConnectScriptToAnim(unsigned int names, int index, unsigned int filename, unsigned int name, int treeIndex);
struct XAnim_s * Scr_GetAnims(int index);
static int Scr_CreateAnimationTree(unsigned int parentNode, unsigned int names, struct XAnim_s *anims, unsigned int childIndex, const char *parentName, unsigned int parentIndex, unsigned int filename, int treeIndex);
static void Scr_CheckAnimsDefined(unsigned int names, unsigned int filename);
static void Scr_PrecacheAnimationTree(unsigned int parentNode);
static unsigned int Scr_UsingTreeInternal(const char *filename, int *index, int user);
static void AnimTreeCompileError(const char *msg);
static int GetAnimTreeParseProperties(void);
void Scr_UsingTree(const char *filename, unsigned int sourcePos);
struct scr_animtree_t Scr_FindAnimTree(const char *filename);
void Scr_FindAnim(const char *filename, const char *animName, scr_anim_t *anim, int user);
void Scr_EmitAnimation(char *pos, unsigned int animName, unsigned int sourcePos);
static Bool AnimTreeParseInternal(unsigned int parentNode, unsigned int names, Bool bIncludeParent, int bLoop, int bComplete);
static Bool Scr_LoadAnimTreeInternal(const char *filename, unsigned int parentNode, unsigned int names);
void Scr_LoadAnimTreeAtIndex(int index, Alloc_t Alloc, int user);

/* external function declarations */
extern unsigned int FindNextSibling(unsigned int id);
extern unsigned int GetVariableName(unsigned int id);
extern int GetVarType(unsigned int id);
extern unsigned int FindObject(unsigned int varId);
extern unsigned int FindVariable(unsigned int parent, unsigned int name);
extern unsigned int GetNewVariable(unsigned int parent, unsigned int name);
extern unsigned int GetVariable(unsigned int parent, unsigned int name);
extern unsigned int GetObjectA(unsigned int varId);
extern unsigned int GetArray(unsigned int id);
extern unsigned int GetArraySize(unsigned int id);
extern unsigned int GetArrayVariable(unsigned int parentId, unsigned int unsignedValue);
extern unsigned int FindArrayVariable(unsigned int parentId, int intValue);
extern void RemoveVariable(unsigned int parentId, unsigned int unsignedValue);
extern void RemoveRefToObject(unsigned int objId);
extern void * GetVariableValueAddress(unsigned int id);
extern void SetVariableValue(unsigned int id, void *value);
extern void SL_RemoveRefToString(unsigned int stringValue);
extern const char *SL_ConvertToString(unsigned int stringValue);
extern unsigned int SL_GetLowercaseString_(const char *str, unsigned int user, int type);
extern unsigned int SL_GetString_(const char *str, unsigned int user, int type);
extern unsigned int Scr_CreateCanonicalFilename(const char *filename);
extern int Scr_EvalVariable(unsigned int varId);
extern int Scr_IsInOpcodeMemory(const char *pos);
extern Bool Scr_IsIdentifier(const char *token);
extern int Scr_AllocArray(void);
extern void *XAnimCreateAnims(const char *debugName, int size, Alloc_t Alloc);
extern void XAnimBlend(void *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags);
extern void XAnimPrecache(const char *name, Alloc_t Alloc);
extern void XAnimCreate(void *anims, unsigned int animIndex, const char *name);
extern void XAnimSetupSyncNodes(void *anims);
extern byte *Scr_AddSourceBuffer(const char *filename, const char *extFilename, byte *oldFilename, int flag);
extern void Com_BeginParseSession(const char *name);
extern void Com_EndParseSession(void);
extern const char *Com_Parse(const char **buf);
extern const char *Com_ParseOnLine(const char **buf);
extern const char *Com_GetLastTokenPos(void);
extern void Hunk_ClearTempMemoryHigh(void);
extern int I_stricmp(const char *s1, const char *s2);
extern char *va(const char *format, ...);
extern void CompileError(unsigned int sourcePos, const char *fmt, ...);
extern void CompileError2(const char *codePos, const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern int sprintf(char *buf, const char *fmt, ...);

/* string literals referenced from asm */
extern const char str_0021dd88[];  /* "duplicate animation '%s' in 'animtrees/%s.atr'" */
extern const char str_0021ddb8[];
extern const char str_0021d930[];
extern const char str_00216058[];  /* "%s" */
extern const char str_0021de10[];
extern const char str_0021ddcc[];
extern const char str_0021dde0[];
extern const char str_0021de04[];
extern const char str_0021de28[];
extern const char str_0021de60[];
extern const char str_0021de7c[];
extern const char str_0021de04[];
extern const char str_0021dea4[];
extern const char str_0021debc[];
extern const char str_0021ded8[]; /* "animtrees/%s.atr" */
extern const char str_0021deec[];
extern const char str_0021df00[]; /* "unknown anim tree '%s'" */
extern const char str_0021df18[]; /* "root" */
extern const char str_0021df20[]; /* "animation '%s' not defined in anim tree '%s'" */
extern const char str_00217870[];
extern const char str_00217a74[]; /* "void_loop" */
extern const char str_0021cdd0[];

/* line 60 */
void SetAnimCheck(int bAnimCheck)
{
    scrAnimGlob.bAnimCheck = bAnimCheck;
}

/* line 315 */
static void * Hunk_AllocXAnimTreePrecache(int size)
{
    return Hunk_AllocAlignInternal(size, 4);
}

static void Scr_EmitAnimationInternal(char *pos, unsigned int animName, unsigned int names)
{
    VariableUnion *value;
    unsigned int animId;
    VariableValue tempValue;

    animId = FindVariable(names, animName);
    if (animId) {
        value = (VariableUnion *)GetVariableValueAddress(animId);
        *(const char **)pos = value->codePosValue;
        value->codePosValue = pos;
        return;
    }

    animId = GetNewVariable(names, animName);
    *(const char **)pos = 0;
    tempValue.u.codePosValue = pos;
    tempValue.type = SCR_VAR_CODEPOS;
    SetVariableValue(animId, &tempValue);
}

/* line 322 */
static int Scr_GetAnimTreeSize(unsigned int parentNode)
{
    unsigned int node;
    int size;

    size = 0;
    for (node = FindNextSibling(parentNode); node; node = FindNextSibling(node)) {
        if (GetVariableName(node) >= SCR_SL_MAX_STRING_INDEX) {
            continue;
        }
        if (GetVarType(node) == SCR_VAR_POINTER) {
            size += Scr_GetAnimTreeSize(FindObject(node));
            continue;
        }
        size++;
    }

    if (size) {
        size++;
    }
    return size;
}

/* line 352 */
static void ConnectScriptToAnim(unsigned int names, int index, unsigned int filename, unsigned int name, int treeIndex)
{
    union {
        scr_anim_t anim;
        const char *linkPointer;
    } link;
    VariableUnion *value;
    unsigned int animId;
    const char *codePos;
    const char *nextCodePos;

    animId = FindVariable(names, name);
    if (!animId) {
        return;
    }

    value = (VariableUnion *)GetVariableValueAddress(animId);
    if (!value->codePosValue) {
        Com_Error(1, "duplicate animation '%s' in 'animtrees/%s.atr'",
                  SL_ConvertToString(name), SL_ConvertToString(filename));
    }

    link.anim.index = (unsigned short)index;
    link.anim.tree = (unsigned short)treeIndex;

    for (codePos = value->codePosValue; codePos; codePos = nextCodePos) {
        nextCodePos = *(const char * const *)codePos;
        *(const void **)codePos = link.linkPointer;
    }

    value->codePosValue = 0;
}

/* line 396 */
struct XAnim_s * Scr_GetAnims(int index)
{
    return *(struct XAnim_s **)(0x114e22c + index * 4);
}

/* line 407 */
static int Scr_CreateAnimationTree(unsigned int parentNode, unsigned int names, struct XAnim_s *anims, unsigned int childIndex, const char *parentName, unsigned int parentIndex, unsigned int filename, int treeIndex)
{
    unsigned int flagsId;
    unsigned int nodeRef;
    unsigned int name;
    unsigned int size;
    unsigned short flags;

    size = 0;
    for (nodeRef = FindNextSibling(parentNode); nodeRef; nodeRef = FindNextSibling(nodeRef)) {
        if (GetVariableName(nodeRef) < SCR_SL_MAX_STRING_INDEX) {
            size++;
        }
    }

    flags = 0;
    flagsId = FindArrayVariable(parentNode, 0);
    if (flagsId) {
        flags = (unsigned short)((VariableUnion *)GetVariableValueAddress(flagsId))->intValue;
    }

    scrVarPub.checksum *= 31;
    scrVarPub.checksum += parentIndex;
    scrVarPub.checksum *= 31;
    scrVarPub.checksum += childIndex;
    scrVarPub.checksum *= 31;
    scrVarPub.checksum += size;
    scrVarPub.checksum *= 31;
    scrVarPub.checksum += flags;

    XAnimBlend(anims, parentIndex, parentName, childIndex, size, flags);

    parentIndex = childIndex;
    childIndex += size;

    for (nodeRef = FindNextSibling(parentNode); nodeRef; nodeRef = FindNextSibling(nodeRef)) {
        name = GetVariableName(nodeRef);
        if (name >= SCR_SL_MAX_STRING_INDEX) {
            continue;
        }

        ConnectScriptToAnim(names, parentIndex, filename, name, treeIndex);

        if (GetVarType(nodeRef) == SCR_VAR_POINTER) {
            childIndex = Scr_CreateAnimationTree(
                FindObject(nodeRef), names, anims, childIndex,
                SL_ConvertToString(name), parentIndex, filename, treeIndex);
        } else {
            scrVarPub.checksum *= 31;
            scrVarPub.checksum += parentIndex;
            XAnimCreate(anims, parentIndex, SL_ConvertToString(name));
        }

        parentIndex++;
    }

    return (int)childIndex;
}

static void Scr_CheckAnimsDefined(unsigned int names, unsigned int filename)
{
    VariableUnion *value;
    unsigned int animId;
    unsigned int name;
    char *msg;

    for (animId = FindNextSibling(names); animId; animId = FindNextSibling(animId)) {
        name = GetVariableName(animId);
        value = (VariableUnion *)GetVariableValueAddress(animId);
        if (!value->codePosValue) {
            continue;
        }

        msg = va("animation '%s' not defined in anim tree '%s'",
                 SL_ConvertToString(name), SL_ConvertToString(filename));
        if (Scr_IsInOpcodeMemory(value->codePosValue)) {
            CompileError2(value->codePosValue, "%s", msg);
            continue;
        }
        Com_Error(1, "%s", msg);
    }
}

/* line 498 */
static void Scr_PrecacheAnimationTree(unsigned int parentNode)
{
    unsigned int node;
    unsigned int name;

    for (node = FindNextSibling(parentNode); node; node = FindNextSibling(node)) {
        name = GetVariableName(node);
        if (name >= SCR_SL_MAX_STRING_INDEX) {
            continue;
        }
        if (GetVarType(node) == SCR_VAR_POINTER) {
            Scr_PrecacheAnimationTree(FindObject(node));
            continue;
        }
        XAnimPrecache(SL_ConvertToString(name), Hunk_AllocXAnimTreePrecache);
    }
}

/* line 521 */
static unsigned int Scr_UsingTreeInternal(const char *filename, int *index, int user)
{
    unsigned int id;
    unsigned int fileId;
    unsigned int names;
    unsigned int name;
    int i;

    /* DBG: check sv=374 state before CreateCanonicalFilename */
    {
        byte *base374 = *(byte **)imp_scrMemTreePub;
        unsigned short ref374 = *(unsigned short *)(base374 + 374 * 8 + 2);
        static unsigned short prev_ref374 = 0xFFFF;
        if (ref374 != prev_ref374) {
            Com_Printf("DBG sv374 CHECK: refcount changed %u -> %u str=\"%.12s\" before UsingTreeInternal('%s')\n",
                       prev_ref374, ref374, (const char *)(base374 + 374*8+4), filename);
            prev_ref374 = ref374;
        }
    }

    name = Scr_CreateCanonicalFilename(filename);
    id = FindVariable(scrAnimPub.animtrees, name);

    if (id) {
        fileId = FindObject(id);
        *index = 0;

        for (i = 1; i <= scrAnimPub.xanim_num[user]; i++) {
            if (scrAnimGlob.using_xanim_lookup[user][i] == id) {
                *index = i;
                break;
            }
        }
        Com_Printf("DBG Scr_UsingTreeInternal: FOUND '%s' user=%d id=%u index=%d nameId=%u\n",
                   filename, user, id, *index, name);
    } else {
        id = GetNewVariable(scrAnimPub.animtrees, name);
        fileId = GetObjectA(id);

        scrAnimPub.xanim_num[user]++;
        if (scrAnimPub.xanim_num[user] >= SCR_MAX_XANIMTREE_NUM) {
            Com_Error(1, "too many xanim trees");
            scrAnimPub.xanim_num[user] = SCR_MAX_XANIMTREE_NUM - 1;
        }

        scrAnimGlob.using_xanim_lookup[user][scrAnimPub.xanim_num[user]] =
            (unsigned short)id;
        *index = scrAnimPub.xanim_num[user];
        Com_Printf("DBG Scr_UsingTreeInternal: NEW '%s' user=%d id=%u index=%d nameId=%u\n",
                   filename, user, id, *index, name);
    }

    names = GetArray(GetVariable(fileId, SCR_ANIMTREE_NAMES));
    SL_RemoveRefToString(name);
    return names;
}

static void AnimTreeCompileError(const char *msg)
{
    const char *pos;

    pos = Com_GetLastTokenPos();
    Com_EndParseSession();
    CompileError((unsigned int)(pos - scrAnimGlob.start), "%s", msg);
}

static int GetAnimTreeParseProperties(void)
{
    const char *token;
    int flags;
    int i;

    flags = 0;
    while (1) {
        token = Com_ParseOnLine(&scrAnimGlob.pos);
        if (!token[0]) {
            return flags;
        }

        for (i = 0; i < 3; i++) {
            if (!I_stricmp(token, propertyNames[i])) {
                break;
            }
        }

        switch (i) {
        case 0:
            flags |= SCR_ANIM_FLAG_LOOPSYNC;
            break;
        case 1:
            flags |= SCR_ANIM_FLAG_NONLOOPSYNC;
            break;
        case 2:
            flags |= SCR_ANIM_FLAG_COMPLETE;
            break;
        default:
            AnimTreeCompileError("unknown anim property");
            break;
        }
    }
}

/* line 573 */
void Scr_UsingTree(const char *filename, unsigned int sourcePos)
{
    if (!Scr_IsIdentifier(filename)) {
        CompileError(sourcePos, "bad anim tree name");
        return;
    }

    scrAnimPub.animTreeNames =
        Scr_UsingTreeInternal(filename, &scrAnimPub.animTreeIndex, 1);
}

/* line 698 */
struct scr_animtree_t Scr_FindAnimTree(const char *filename)
{
    struct scr_animtree_t result;
    unsigned int filenameId;
    unsigned int fileId;

    filenameId = Scr_CreateCanonicalFilename(filename);
    fileId = FindVariable(scrAnimPub.animtrees, filenameId);
    SL_RemoveRefToString(filenameId);

    result.anims = 0;
    if (!fileId)
        return result;

    GetVariableName(fileId);
    fileId = FindObject(fileId);
    if (!FindVariable(fileId, 1))
        return result;

    result.anims = (struct XAnim_s *)(uintptr_t)Scr_EvalVariable(FindVariable(fileId, 1));
    return result;
}

/* Wrapper for ASM callers that expect result in eax (no hidden pointer) */
void *Scr_FindAnimTree_asm(const char *filename)
{
    struct scr_animtree_t result = Scr_FindAnimTree(filename);
    return (void *)result.anims;
}

/* line 738 */
void Scr_FindAnim(const char *filename, const char *animName, scr_anim_t *anim, int user)
{
    int index;
    unsigned int name;

    {
        static unsigned short fa_prev374 = 0xFFFF;
        byte *b374 = *(byte **)imp_scrMemTreePub;
        unsigned short r_entry = *(unsigned short *)(b374 + 374*8+2);
        if (r_entry != fa_prev374) {
            Com_Printf("DBG FindAnim ENTRY sv374: %u -> %u str='%.12s' anim='%s'\n",
                       fa_prev374, r_entry, (const char *)(b374+374*8+4), animName);
            fa_prev374 = r_entry;
        }
        /* Check if sv=374 is in free tree while it should be allocated */
        if (r_entry == 1) {
            extern void MT_VerifyNotInTree(int nodeNum);
            MT_VerifyNotInTree(374);
            MT_VerifyNotInTree(373);
            MT_VerifyNotInTree(372);
        }
    }
    name = SL_GetLowercaseString_(animName, 4, 0);
    Scr_EmitAnimationInternal(
        (char *)anim, name, Scr_UsingTreeInternal(filename, &index, user));
    SL_RemoveRefToString(name);
    /* Check: after freeing this anim name, did node 374's refcount get corrupted? */
    {
        byte *b374 = *(byte **)imp_scrMemTreePub;
        unsigned short r = *(unsigned short *)(b374 + 374*8+2);
        static int fa_caught = 0;
        if (!fa_caught && r != 1 && r != 0 && r != 2) {
            /* refcount is bogus — the free corrupted node 374 */
            Com_Printf("TREE CORRUPT after RemoveRef: sv374 ref=%u str='%.12s' anim='%s' freed_sv=%u\n",
                       r, (const char *)(b374+374*8+4), animName, name);
            fa_caught = 1;
        }
    }
}

/* line 164 */
void Scr_EmitAnimation(char *pos, unsigned int animName, unsigned int sourcePos)
{
    if (!scrAnimPub.animTreeNames) {
        CompileError(sourcePos, "#using_animtree was not specified");
        return;
    }

    Scr_EmitAnimationInternal(pos, animName, scrAnimPub.animTreeNames);
}

/* line 179 */
static Bool AnimTreeParseInternal(unsigned int parentNode, unsigned int names, Bool bIncludeParent, int bLoop, int bComplete)
{
    VariableValue tempValue;
    unsigned int index;
    unsigned int currentAnim;
    unsigned int node;
    const char *token;
    int flags;
    Bool bIgnore;

    tempValue.type = SCR_VAR_INTEGER;
    index = 0;
    currentAnim = 0;
    flags = 0;
    bIgnore = 0;

    while (1) {
        token = Com_Parse(&scrAnimGlob.pos);

        if (!scrAnimGlob.pos) {
            if (bIgnore) {
                RemoveVariable(parentNode, index);
            }

            if (bIncludeParent && !GetArraySize(parentNode)) {
                index = SL_GetString_(bLoop ? "void_loop" : "void", 0, 4);
                GetVariable(parentNode, index);
                SL_RemoveRefToString(index);
            }

            return 1;
        }

        if (Scr_IsIdentifier(token)) {
            if (bIgnore) {
                RemoveVariable(parentNode, index);
            }

            index = SL_GetLowercaseString_(token, 2, 4);
            if (FindVariable(parentNode, index)) {
                AnimTreeCompileError("duplicate animation");
            }

            currentAnim = GetVariable(parentNode, index);
            bIgnore = 0;

            if (!bComplete && !FindVariable(names, index)) {
                bIgnore = (scrAnimGlob.bAnimCheck == 0);
            }

            flags = 0;
            token = Com_ParseOnLine(&scrAnimGlob.pos);
            if (!token[0]) {
                continue;
            }

            if (Scr_IsIdentifier(token)) {
                AnimTreeCompileError("FIXME: aliases not yet implemented");
            }
            if (token[0] != ':' || token[1]) {
                AnimTreeCompileError("bad token");
            }

            flags = GetAnimTreeParseProperties();
            token = Com_Parse(&scrAnimGlob.pos);
            if (token[0] != '{' || token[1]) {
                AnimTreeCompileError("properties cannot be applied to primitive animations");
            }
        }

        if (token[0] == '{') {
            if (token[1]) {
                AnimTreeCompileError("bad token");
            }
            if (*Com_ParseOnLine(&scrAnimGlob.pos)) {
                AnimTreeCompileError("token not allowed after '{'");
            }
            if (!currentAnim) {
                AnimTreeCompileError("no animation specified for this block");
            }

            node = GetArray(currentAnim);
            if (bComplete || ((flags & SCR_ANIM_FLAG_COMPLETE) && !bIgnore)) {
                if (AnimTreeParseInternal(node, names, (Bool)!bIgnore,
                                          flags & SCR_ANIM_FLAG_LOOPSYNC, 1)) {
                    AnimTreeCompileError("unexpected end of file");
                }
            } else {
                if (AnimTreeParseInternal(node, names, (Bool)!bIgnore,
                                          flags & SCR_ANIM_FLAG_LOOPSYNC, 0)) {
                    AnimTreeCompileError("unexpected end of file");
                }
            }

            if (GetArraySize(node)) {
                tempValue.u.intValue = flags;
                SetVariableValue(GetArrayVariable(node, 0), &tempValue);
            } else {
                RemoveVariable(parentNode, index);
            }

            currentAnim = 0;
            bIgnore = 0;
            continue;
        }

        if (token[0] != '}') {
            AnimTreeCompileError("bad token");
            continue;
        }

        if (token[1]) {
            AnimTreeCompileError("bad token");
        }
        if (*Com_ParseOnLine(&scrAnimGlob.pos)) {
            AnimTreeCompileError("token not allowed after '}'");
        }

        if (bIgnore) {
            RemoveVariable(parentNode, index);
        }

        if (bIncludeParent && !GetArraySize(parentNode)) {
            index = SL_GetString_(bLoop ? "void_loop" : "void", 0, 4);
            GetVariable(parentNode, index);
            SL_RemoveRefToString(index);
        }

        return 0;
    }
}

static Bool Scr_LoadAnimTreeInternal(const char *filename, unsigned int parentNode, unsigned int names)
{
    const char *oldSourceBuf;
    const char *oldFilename;
    const char *sourceBuffer;
    const char *errorPos;
    char extFilename[96];

    sprintf(extFilename, "animtrees/%s.atr", filename);
    oldSourceBuf = scrParserPub.sourceBuf;
    oldFilename = scrParserPub.scriptfilename;

    sourceBuffer = (const char *)Scr_AddSourceBuffer(0, extFilename, 0, 1);
    if (!sourceBuffer) {
        return 0;
    }

    scrParserPub.scriptfilename = extFilename;
    Com_BeginParseSession("Scr_AnimTreeParse");
    scrAnimGlob.start = sourceBuffer;
    scrAnimGlob.pos = sourceBuffer;

    if (!AnimTreeParseInternal(parentNode, names, 1, 0, 0)) {
        errorPos = Com_GetLastTokenPos();
        Com_EndParseSession();
        CompileError((unsigned int)(errorPos - scrAnimGlob.start), "%s", "bad token");
    } else {
        Com_EndParseSession();
    }

    scrParserPub.scriptfilename = oldFilename;
    scrParserPub.sourceBuf = oldSourceBuf;
    Hunk_ClearTempMemoryHigh();

    return (Bool)(GetArraySize(parentNode) != 0);
}

/* line 618 */
void Scr_LoadAnimTreeAtIndex(int index, Alloc_t Alloc, int user)
{
    unsigned int id;
    unsigned int fileId;
    unsigned int filenameId;
    unsigned int namesVar;
    unsigned int names;
    unsigned int name;
    int size;
    int size2;
    scr_animtree_t animtree;
    VariableValue tempValue;

    id = scrAnimGlob.using_xanim_lookup[user][index];
    filenameId = GetVariableName(id) & 0xffff;
    fileId = FindObject(id);

    Com_Printf("DBG Scr_LoadAnimTreeAtIndex: index=%d user=%d id=%u filenameId=%u str='%s'\n",
               index, user, id, filenameId, SL_ConvertToString(filenameId));

    if (FindVariable(fileId, SCR_ANIMTREE_XANIM)) {
        return;
    }

    namesVar = FindVariable(fileId, SCR_ANIMTREE_NAMES);
    if (!namesVar) {
        scrAnimPub.xanim_lookup[user][index].anims = 0;
        return;
    }

    animtree.anims = 0;
    names = FindObject(namesVar);
    scrAnimPub.animtree_node = Scr_AllocArray();

    if (!Scr_LoadAnimTreeInternal(SL_ConvertToString(filenameId),
                                  scrAnimPub.animtree_node, names)) {
        Com_Error(1, "unknown anim tree '%s'", SL_ConvertToString(filenameId));
    }

    size = Scr_GetAnimTreeSize(scrAnimPub.animtree_node);
    animtree.anims =
        (struct XAnim_s *)XAnimCreateAnims(SL_ConvertToString(filenameId), size, Alloc);

    name = SL_GetString_("root", 0, 4);
    ConnectScriptToAnim(names, 0, filenameId, name, index);
    SL_RemoveRefToString(name);

    Scr_PrecacheAnimationTree(scrAnimPub.animtree_node);
    size2 = Scr_CreateAnimationTree(scrAnimPub.animtree_node, names, animtree.anims,
                                    1, "root", 0, filenameId, index);
    (void)size2;

    Scr_CheckAnimsDefined(names, filenameId);

    RemoveVariable(fileId, SCR_ANIMTREE_NAMES);
    RemoveRefToObject(scrAnimPub.animtree_node);
    scrAnimPub.animtree_node = 0;

    tempValue.u.codePosValue = (const char *)animtree.anims;
    tempValue.type = SCR_VAR_CODEPOS;
    SetVariableValue(GetVariable(fileId, SCR_ANIMTREE_XANIM), &tempValue);

    XAnimSetupSyncNodes(animtree.anims);
    scrAnimPub.xanim_lookup[user][index] = animtree;
}
