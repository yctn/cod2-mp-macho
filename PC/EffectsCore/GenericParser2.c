/* ASM dump from: GenericParser2.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/GenericParser2.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/GenericParser2.h"
 */

extern void Z_FreeInternal(void *ptr);
extern void *Z_MallocInternal(int size);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int strcmpi(const char *str1, const char *str2);

/*
 * Reconstructed struct layouts from offset analysis:
 *
 * GPObject (base for GPValue/GPGroup linked list nodes):
 *   0x00: const char *name
 *   0x04: GPObject *next         (unsorted list link)
 *   0x08: GPObject *sortedNext   (sorted list link)
 *   0x0c: GPObject *sortedPrev   (sorted list back-link)
 *
 * GPValue (0x14 bytes, extends GPObject):
 *   0x00-0x0c: GPObject fields
 *   0x10: GPValue *valueList     (head of value node list)
 *
 * GPGroup (0x30 bytes):
 *   0x00: const char *name
 *   0x04: GPObject *nextUnsorted
 *   0x08: GPObject *sortedNext
 *   0x0c: GPObject *sortedPrev
 *   0x10: GPValue *pairList      (head of unsorted pair list)
 *   0x14: GPValue *pairSorted    (head of sorted pair list)
 *   0x18: GPValue *pairLast      (tail of sorted pair list)
 *   0x1c: GPGroup *subGroupList  (head of unsorted sub-group list)
 *   0x20: GPGroup *subGroupSorted (head of sorted sub-group list)
 *   0x24: GPGroup *subGroupLast  (tail of sorted sub-group list)
 *   0x28: void *parent
 *   0x2c: byte cleanFlag         (writeable flag)
 *
 * TextPool_ (0x10 bytes):
 *   0x00: char *data
 *   0x04: TextPool_ *next
 *   0x08: int capacity
 *   0x0c: int used
 *
 * GenericParser2_ (extends GPGroup):
 *   0x00-0x2c: GPGroup fields
 *   0x30: TextPool_ *textPoolList
 *   0x34: byte writeable
 */

static char token[1024]; /* token */

const char * GPValue_GetTopValue(const GPValue * _this);
Bool GPValue_IsList(const GPValue * _this);
void GPGroup_SortObject(const GPGroup * _this, GPObject *object, GPObject * *unsortedList, GPObject * *sortedList, GPObject * *lastObject);
void GPGroup_Clean(const GPGroup * _this);
void GenericParser2_GenericParser2(const GenericParser2 * _this);
char * TextPool_AllocText(const TextPool * _this, char *text, int addNULL, TextPool * *poolPtr);
GPGroup * GPGroup_AddGroup(const GPGroup * _this, const char *name, TextPool * *textPool);
void GPValue_AddValue(const GPValue * _this, const char *newValue, TextPool * *textPool);
GPValue * GPGroup_AddPair(const GPGroup * _this, const char *name, const char *value, TextPool * *textPool);
void ZN14GenericParser2D2Ev(GenericParser2 *_this); /* GenericParser2_~GenericParser2 */
void ZN14GenericParser2D1Ev(GenericParser2 *_this); /* GenericParser2_~GenericParser2 */
Bool GPGroup_Parse(const GPGroup * _this, char * *dataPtr, TextPool * *textPool);
Bool GenericParser2_Parse(const GenericParser2 * _this, char * *dataPtr, int cleanFirst, int writeable);

/* ================================================================
 * GetToken — register convention: eax=text(char**), edx=allowLineBreaks, ecx=readUntilEOL
 * Returns pointer to static token buffer.
 * ================================================================ */
static char * GetToken_impl(char **text, int allowLineBreaks, int readUntilEOL)
{
    char *pointer;
    int length;
    int foundNewline;

    pointer = *text;
    token[0] = '\0';

    if (!pointer) {
        return token;
    }

    /* Skip whitespace, comments */
    while (1) {
        unsigned char ch = (unsigned char)*pointer;

        /* Skip whitespace */
        while (ch && ch <= 0x20) {
            if (ch == '\n') {
                foundNewline = 1;
            }
            pointer++;
            ch = (unsigned char)*pointer;
            if (ch > 0x20) {
                /* Non-whitespace found; check if we hit a newline and shouldn't cross lines */
                if (foundNewline && !allowLineBreaks) {
                    *text = pointer;
                    return token;
                }
                goto check_comment;
            }
            if (!ch) {
                break;
            }
        }

        if (!ch) {
            *text = 0;
            return token;
        }

check_comment:
        foundNewline = 0;
        if (ch == '/') {
            unsigned char next = (unsigned char)pointer[1];
            if (next == '/') {
                /* Single-line comment: skip to end of line */
                pointer += 2;
                while (1) {
                    ch = (unsigned char)*pointer;
                    if (!ch) break;
                    if (ch == '\n') break;
                    pointer++;
                }
                continue;
            } else if (next == '*') {
                /* Multi-line comment: skip to */
                pointer += 2;
                while (1) {
                    ch = (unsigned char)*pointer;
                    if (!ch) break;
                    if (ch == '*' && pointer[1] == '/') {
                        pointer += 2;
                        break;
                    }
                    pointer++;
                }
                continue;
            }
            /* Not a comment — '/' is a regular character, fall through */
        }

        break; /* Not whitespace or comment, proceed to tokenize */
    }

    /* At this point, *pointer is the first non-whitespace, non-comment char */
    {
        unsigned char ch = (unsigned char)*pointer;

        if (ch == '"' && !readUntilEOL) {
            /* Quoted string */
            pointer++; /* skip opening quote */
            length = 0;
            while (1) {
                ch = (unsigned char)*pointer;
                pointer++;
                if (ch == '"') break;
                if (!ch) break;
                if (length <= 0x3ff) {
                    token[length] = (char)ch;
                    length++;
                }
            }
            /* Check if token starts with '"', strip surrounding quotes via memmove */
            if (token[0] == '"') {
                int newLen = length - 1;
                memmove(token, token + 1, newLen);
                length = newLen;
                if (newLen > 0 && token[length - 2] == '"') {
                    length = length - 2;
                }
            }
        } else if (readUntilEOL) {
            /* Read until end-of-line mode */
            length = 0;
            while (1) {
                /* Check for comment start */
                if (ch == '/') {
                    unsigned char next = (unsigned char)pointer[1];
                    if (next == '/' || next == '*') {
                        break; /* Stop at comment */
                    }
                    pointer++;
                } else {
                    pointer++;
                }
                if (length <= 0x3ff) {
                    token[length] = (char)ch;
                    length++;
                }
                ch = (unsigned char)*pointer;
                if (ch == '\n' || ch == '\r') break;
            }
            /* Strip trailing whitespace */
            if (length > 0) {
                int trimLen = length - 1;
                if ((unsigned char)token[trimLen] <= 0x1f) {
                    /* Walk backwards stripping control chars */
                    int count = 0;
                    while (trimLen > count) {
                        if ((unsigned char)token[trimLen - count - 1] > 0x1f) {
                            break;
                        }
                        count++;
                    }
                    length = trimLen - count;
                }
            }
        } else {
            /* Regular (unquoted, non-EOL) token */
            if (ch == '/') {
                ch = '/'; /* not a comment, treat '/' as start of token */
            }
            length = 0;
            /* Read token char */
            token[length] = (char)ch;
            length++;
            if (length > 0x3ff) {
                /* Token too long, skip remaining non-whitespace */
                pointer++;
                while ((unsigned char)*pointer > 0x20) {
                    pointer++;
                }
            } else {
                /* Read next chars */
                pointer++;
                ch = (unsigned char)*pointer;
                while (ch > 0x20) {
                    token[length] = (char)ch;
                    length++;
                    if (length > 0x3ff) {
                        pointer++;
                        while ((unsigned char)*pointer > 0x20) {
                            pointer++;
                        }
                        goto finish_token;
                    }
                    pointer++;
                    ch = (unsigned char)*pointer;
                }
            }
        }

finish_token:
        /* Check if token starts with '"' and strip quotes */
        if (token[0] == '"') {
            int newLen = length - 1;
            memmove(token, token + 1, newLen);
            length = newLen;
            if (newLen > 0 && token[length - 2] == '"') {
                length = length - 2;
            }
        }

        /* Null-terminate */
        if (length >= 0x400) {
            length = 0;
        }
        token[length] = '\0';
        *text = pointer;
    }

    return token;
}

/* line 30 — GetToken: originally register convention (eax=text, edx=allowLineBreaks, ecx=readUntilEOL).
 * All active callers now use GetToken_impl directly; this wrapper is kept for completeness.
 */

/* line 335 */
const char * GPValue_GetTopValue(const GPValue * _this)
{
    GPValue *list = ((GPValue *)_this)->valueList; /* offset 0x10 */
    if (list)
        return list->name;
    return NULL;
}

/* line 324 */
Bool GPValue_IsList(const GPValue * _this)
{
    GPValue *list = ((GPValue *)_this)->valueList; /* offset 0x10 */
    if (list) {
        if (list->next) { /* offset 0x04 */
            return 1;
        }
    }
    return 0;
}

/* line 568 */
/*
 * GPGroup_SortObject — inserts 'object' into a sorted linked list.
 * Objects at offsets: 0x00=name, 0x04=next(unsorted), 0x08=next(sorted), 0x0c=prev(sorted)
 *
 * unsortedList: the head of the unsorted chain (object is removed from here)
 * sortedList: the head of the sorted chain (object is inserted here in order)
 * lastObject: the tail of the sorted chain
 */
void GPGroup_SortObject(const GPGroup * _this, GPObject *object, GPObject * *unsortedList, GPObject * *sortedList, GPObject * *lastObject)
{
    GPObject *test;
    GPObject *last;

    /* If unsortedList is empty, this is the first+only object in both lists */
    if (*unsortedList == NULL) {
        *sortedList = object;
        *unsortedList = object;
        *lastObject = object;
        return;
    }

    /* Link: lastObject->next = object */
    (*lastObject)->next = object;

    /* Walk the sorted list to find insertion point */
    test = *sortedList;
    if (!test) {
        /* Sorted list is empty, object becomes head */
        *sortedList = object;
        *lastObject = object;
        return;
    }

    last = NULL;
    while (1) {
        /* Compare object->name with test->name */
        int cmp = strcmpi(object->name, test->name);
        if (cmp < 0) {
            /* Insert before test */
            test->sortedPrev = object;
            object->sortedNext = test;
            if (last) {
                /* Insert after last */
                last->sortedNext = object;
                object->sortedPrev = last;
                *lastObject = object;
            } else {
                /* Object becomes new head of sorted list */
                *sortedList = object;
                *lastObject = object;
            }
            return;
        }
        /* Move to next in sorted list */
        {
            GPObject *nextSorted = test->sortedNext;
            if (!nextSorted) {
                /* End of sorted list, insert after test */
                last = test;
                break;
            }
            last = test;
            test = nextSorted;
        }
    }

    /* Insert after last (at end of sorted list) */
    last->sortedNext = object;
    object->sortedPrev = last;
    *lastObject = object;

}

/* line 505 */
/*
 * GPGroup_Clean — frees all GPValues (at offset 0x10) and GPGroups (at offset 0x1c)
 * owned by this group, then zeroes all internal pointers.
 *
 * GPGroup layout (offsets used):
 *   0x10: pairList (first GPValue*)
 *   0x14: pairSortedList
 *   0x18: nextPair / temp
 *   0x1c: subGroupList (first GPGroup*)
 *   0x20: subGroupSortedList
 *   0x24: nextSubGroup / temp
 *   0x28: field28
 *   0x2c: writeable (byte)
 */
void GPGroup_Clean(const GPGroup * _this)
{
    GPGroup *grp = (GPGroup *)_this;
    GPValue *pair;
    GPObject *nextPair;
    GPGroup *subGroup;
    GPObject *nextSubGroup;

    /* Free all pairs (GPValues) */
    pair = grp->pairList;
    while (pair) {
        nextPair = ((GPObject *)pair)->next;
        grp->pairLast = (GPValue *)nextPair;

        /* Free all value nodes in this pair's value list */
        {
            GPValue *valNode = pair->valueList;
            while (valNode) {
                GPObject *nextVal = ((GPObject *)valNode)->next;
                Z_FreeInternal(valNode);
                pair->valueList = (GPValue *)nextVal;
                valNode = (GPValue *)nextVal;
            }
        }

        /* Free the pair itself */
        Z_FreeInternal(pair);

        /* Move to next pair */
        pair = grp->pairLast;
        grp->pairList = pair;
    }

    /* Free all sub-groups (GPGroups) */
    subGroup = grp->subGroupList;
    while (subGroup) {
        nextSubGroup = ((GPObject *)subGroup)->next;
        grp->subGroupLast = (GPGroup *)nextSubGroup;

        /* Recursively clean the sub-group */
        GPGroup_Clean((const GPGroup *)subGroup);

        /* Free the sub-group itself */
        Z_FreeInternal(subGroup);

        /* Move to next sub-group */
        subGroup = grp->subGroupLast;
        grp->subGroupList = subGroup;
    }

    /* Zero out all internal pointers */
    grp->pairLast = NULL;
    grp->pairSorted = NULL;
    grp->pairList = NULL;
    grp->subGroupLast = NULL;
    grp->subGroupSorted = NULL;
    grp->subGroupList = NULL;
    grp->parent = NULL;
    grp->cleanFlag = 0;

}

/* line 818 */
/*
 * GenericParser2 constructor.
 *
 * GenericParser2 layout:
 *   0x00: name (set to "Top Level")
 *   0x04-0x0c: zeros (GPObject base fields)
 *   0x10-0x2c: GPGroup fields (all zeroed)
 *   0x30: textPoolList (NULL)
 *   0x34: writeable flag (0)
 */
void GenericParser2_GenericParser2(const GenericParser2 * _this)
{
    /* GenericParser2 extends GPGroup with textPoolList and writeable */
    GPGroup *grp = (GPGroup *)_this;
    grp->name = "Top Level"; /* "Top Level" */
    grp->nextUnsorted = NULL;
    grp->sortedNext = NULL;
    grp->sortedPrev = NULL;
    grp->pairList = NULL;
    grp->pairSorted = NULL;
    grp->pairLast = NULL;
    grp->subGroupList = NULL;
    grp->subGroupSorted = NULL;
    grp->subGroupLast = NULL;
    grp->parent = NULL;
    grp->cleanFlag = 0;
    /* GenericParser2-specific fields (beyond GPGroup) */
    GenericParser2 *gp = (GenericParser2 *)_this;
    gp->textPoolList = NULL;
    gp->writeable = 0;

}

/* line 201 */
/*
 * TextPool_AllocText — allocates text from a pool, creating a new pool node if needed.
 *
 * TextPool layout (0x10 bytes):
 *   0x00: data (char*)
 *   0x04: next (TextPool*)
 *   0x08: capacity (int)
 *   0x0c: used (int)
 */
char * TextPool_AllocText(const TextPool * _this, char *text, int addNULL, TextPool * *poolPtr)
{
    TextPool *pool = (TextPool *)_this;
    int length;
    int extra;
    int used;
    char *dest;

    extra = addNULL ? 1 : 0;
    length = strlen(text) + extra;

    used = pool->used;
    if (used + length + 1 <= pool->capacity) {
        /* Fits in current pool */
        dest = pool->data + used;
        strcpy(dest, text);
        used += length;
        pool->used = used;
        /* Null terminate at end */
        pool->data[used] = '\0';
        /* Return pointer to start of allocated text */
        return pool->data + used - length;
    }

    /* Doesn't fit -- need a new pool */
    if (!poolPtr) {
        return NULL;
    }

    {
        TextPool *newPool;
        int initSize;
        TextPool *prev;
        TextPool *newNode;

        initSize = pool->capacity;

        /* Allocate new TextPool node (0x10 bytes) */
        newPool = (TextPool *)Z_MallocInternal(0x10);

        /* Initialize new pool */
        newPool->next = NULL;
        newPool->capacity = initSize;
        newPool->used = 0;
        newPool->data = (char *)Z_MallocInternal(initSize);

        /* Link: current pool's next = newPool */
        prev = *poolPtr;
        prev->next = newPool;

        /* Update poolPtr to point to new pool */
        newNode = (*poolPtr)->next;
        *poolPtr = newNode;

        /* Recurse into new pool with no poolPtr (NULL) to avoid infinite recursion */
        return TextPool_AllocText((const TextPool *)newNode, text, addNULL ? 1 : 0, NULL);
    }

}

/* line 641 */
/*
 * GPGroup_AddGroup — creates a new sub-group with the given name, inserts into sorted list.
 *
 * GPGroup offsets for sub-group tracking:
 *   0x1c: subGroupUnsortedList
 *   0x20: subGroupSortedList
 *   0x24: subGroupLastObject
 */
GPGroup * GPGroup_AddGroup(const GPGroup * _this, const char *name, TextPool * *textPool)
{
    const char *allocName = name;
    GPGroup *newGroup;

    /* Allocate the name in the text pool if textPool is provided */
    if (textPool) {
        allocName = TextPool_AllocText(*textPool, (char *)name, 1, textPool);
    }

    /* Allocate a new GPGroup (0x30 bytes) */
    newGroup = (GPGroup *)Z_MallocInternal(0x30);

    /* Initialize: name at offset 0, rest zeroed */
    newGroup->name = allocName;
    newGroup->nextUnsorted = NULL;
    newGroup->sortedNext = NULL;
    newGroup->sortedPrev = NULL;
    newGroup->pairList = NULL;
    newGroup->pairSorted = NULL;
    newGroup->pairLast = NULL;
    newGroup->subGroupList = NULL;
    newGroup->subGroupSorted = NULL;
    newGroup->subGroupLast = NULL;
    newGroup->parent = NULL;
    newGroup->cleanFlag = 0;

    /* Insert into sorted sub-group list */
    {
        GPGroup *grp = (GPGroup *)_this;
        GPGroup_SortObject(_this, (GPObject *)newGroup,
                           (GPObject **)&grp->subGroupList,
                           (GPObject **)&grp->subGroupSorted,
                           (GPObject **)&grp->subGroupLast);
    }

    return newGroup;

}

/* line 346 */
/*
 * GPValue_AddValue — adds a new value to a GPValue's value list.
 *
 * GPValue layout:
 *   0x00: name
 *   0x04: next (unsorted)
 *   0x08: next (sorted) / also used as "last" pointer in value list
 *   0x0c: prev (sorted)
 *   0x10: valueListHead (first value node)
 *
 * Value node layout (0x10 bytes):
 *   0x00: string value
 *   0x04: next node
 *   0x08: last node pointer (only on head)
 *   0x0c: unused
 */
void GPValue_AddValue(const GPValue * _this, const char *newValue, TextPool * *textPool)
{
    const char *allocValue = newValue;
    GPValue *gpv = (GPValue *)_this;
    GPObject *head;
    GPValue *newNode;

    /* Allocate value string in text pool if provided */
    if (textPool) {
        allocValue = TextPool_AllocText(*textPool, (char *)newValue, 1, textPool);
    }

    head = (GPObject *)gpv->valueList;
    if (head) {
        /* Value list already exists -- append new node */
        newNode = (GPValue *)Z_MallocInternal(0x10);
        newNode->name = allocValue;
        ((GPObject *)newNode)->next = NULL;
        ((GPObject *)newNode)->sortedNext = NULL;
        ((GPObject *)newNode)->sortedPrev = NULL;

        /* Link: last->next = newNode */
        {
            GPObject *lastNode = head->sortedNext; /* head's "last" pointer */
            lastNode->next = (GPObject *)newNode;
        }

        /* Update head's "last" pointer to point to newNode */
        {
            GPObject *lastNode = head->sortedNext;
            GPObject *nextOfLast = lastNode->next;
            head->sortedNext = nextOfLast;
        }
    } else {
        /* First value -- create head node */
        newNode = (GPValue *)Z_MallocInternal(0x10);
        newNode->name = allocValue;
        ((GPObject *)newNode)->next = NULL;
        ((GPObject *)newNode)->sortedPrev = NULL;
        gpv->valueList = newNode;
        /* Head's "last" pointer points to itself */
        ((GPObject *)newNode)->sortedNext = (GPObject *)newNode;
    }

}

/* line 613 */
/*
 * GPGroup_AddPair — creates a new GPValue pair with name and optional value,
 * inserts into sorted pair list.
 *
 * GPGroup offsets for pair tracking:
 *   0x10: pairUnsortedList
 *   0x14: pairSortedList
 *   0x18: pairLastObject
 *
 * GPValue is 0x14 bytes (name + GPObject fields + value list head).
 */
GPValue * GPGroup_AddPair(const GPGroup * _this, const char *name, const char *value, TextPool * *textPool)
{
    const char *allocName = name;
    const char *allocValue = value;
    GPValue *newPair;

    /* Allocate name and value in text pool if textPool is provided */
    if (textPool) {
        allocName = TextPool_AllocText(*textPool, (char *)name, 1, textPool);
        if (value) {
            allocValue = TextPool_AllocText(*textPool, (char *)value, 1, textPool);
        }
    }

    /* Allocate new GPValue (0x14 bytes) */
    newPair = (GPValue *)Z_MallocInternal(0x14);
    newPair->name = allocName;
    ((GPObject *)newPair)->next = NULL;
    ((GPObject *)newPair)->sortedNext = NULL;
    ((GPObject *)newPair)->sortedPrev = NULL;
    newPair->valueList = NULL;

    /* Add the value if present */
    if (allocValue) {
        GPValue_AddValue((const GPValue *)newPair, allocValue, NULL);
    }

    /* Insert into sorted pair list */
    {
        GPGroup *grp = (GPGroup *)_this;
        GPGroup_SortObject(_this, (GPObject *)newPair,
                           (GPObject **)&grp->pairList,
                           (GPObject **)&grp->pairSorted,
                           (GPObject **)&grp->pairLast);
    }

    return newPair;

}

/* Helper: shared destructor logic for GenericParser2 */
static void GenericParser2_Destroy(byte *self)
{
    GenericParser2 *gp = (GenericParser2 *)self;
    TextPool *pool;
    TextPool *next;

    /* Clean the group */
    GPGroup_Clean((const GPGroup *)self);

    /* Free all text pools */
    pool = gp->textPoolList;
    while (pool) {
        next = pool->next;
        /* Free pool data buffer */
        Z_FreeInternal(pool->data);
        /* Free pool node */
        Z_FreeInternal(pool);
        pool = next;
    }

    gp->textPoolList = NULL;

    /* Clean again (tail call in original) */
    GPGroup_Clean((const GPGroup *)self);
}

/* line 825 */
void ZN14GenericParser2D2Ev(GenericParser2 *_this) /* GenericParser2_~GenericParser2 */
{
    GenericParser2_Destroy((byte *)_this);
}

/* line 825 */
void ZN14GenericParser2D1Ev(GenericParser2 *_this) /* GenericParser2_~GenericParser2 */
{
    GenericParser2_Destroy((byte *)_this);
}

/* line 682 */
/*
 * GPGroup_Parse — recursively parses a group from text data.
 *
 * Grammar:
 *   group = (pair | subgroup)*
 *   pair = name value | name "[" value* "]"
 *   subgroup = name "{" group "}"
 *   token "}" ends the current group
 *
 * GetToken is called with register convention: eax=dataPtr, edx=allowLineBreaks, ecx=readUntilEOL
 */
Bool GPGroup_Parse(const GPGroup * _this, char * *dataPtr, TextPool * *textPool)
{
    byte *self = (byte *)_this;
    char *tok;
    char lastToken[0x400];

    while (1) {
        /* Get next token (allowLineBreaks=1, readUntilEOL=0) */
        tok = GetToken_impl(dataPtr, 1, 0);

        if (tok[0] == '\0') {
            /* End of data */
            /* If this->field_0x28 (parent) is non-null, we hit EOF inside a group = error */
            if (((GPGroup *)_this)->parent != NULL) {
                return 0;
            }
            return 1;
        }

        /* Check for "}" — end of group */
        if (strcmpi(tok, "}") == 0) {
            return 1;
        }

        /* Save current token as name */
        I_strncpyz(lastToken, tok, 0x400);

        /* Get next token to determine what follows the name */
        tok = GetToken_impl(dataPtr, 1, 1);

        if (strcmpi(tok, "{") == 0) {
            /* "{" — sub-group */
            GPGroup *newGroup;
            newGroup = GPGroup_AddGroup(_this, lastToken, textPool);
            /* Copy writeable flag from parent */
            ((GPGroup *)newGroup)->cleanFlag = ((GPGroup *)_this)->cleanFlag;
            /* Recursively parse sub-group */
            if (!GPGroup_Parse((const GPGroup *)newGroup, dataPtr, textPool)) {
                return 0;
            }
            continue;
        }

        if (strcmpi(tok, "[") == 0) {
            /* "[" — list of values */
            GPValue *newPair;
            newPair = GPGroup_AddPair(_this, lastToken, NULL, textPool);

            /* Read values until "]" */
            while (1) {
                tok = GetToken_impl(dataPtr, 1, 1);
                if (tok[0] == '\0') {
                    return 0;
                }
                if (strcmpi(tok, "]") == 0) {
                    /* "]" — end of list */
                    break;
                }
                /* Allocate value text and add to the pair */
                {
                    char *allocValue = TextPool_AllocText(*textPool, tok, 1, textPool);
                    GPValue_AddValue(newPair, allocValue, NULL);
                }
            }
            continue;
        }

        /* Otherwise, tok is the value for a simple name-value pair */
        GPGroup_AddPair(_this, lastToken, tok, textPool);
    }

}

/* line 831 */
/*
 * GenericParser2_Parse — entry point: optionally cleans, sets up text pool, parses.
 *
 * GenericParser2 layout (beyond GPGroup):
 *   0x30: textPoolList (TextPool*)
 *   0x34: writeable (byte)
 *   0x2c: writeable flag (in GPGroup portion)
 */
Bool GenericParser2_Parse(const GenericParser2 * _this, char * *dataPtr, int cleanFirst, int writeable)
{
    GenericParser2 *gp = (GenericParser2 *)_this;
    TextPool *topPool;

    if (cleanFirst) {
        /* Clean the group */
        GPGroup_Clean((const GPGroup *)_this);

        /* Free all text pools */
        {
            TextPool *pool = gp->textPoolList;
            while (pool) {
                TextPool *next = pool->next;
                Z_FreeInternal(pool->data);
                Z_FreeInternal(pool);
                pool = next;
            }
            gp->textPoolList = NULL;
        }
    }

    /* Ensure a text pool exists */
    if (gp->textPoolList == NULL) {
        TextPool *newPool = (TextPool *)Z_MallocInternal(0x10);
        newPool->next = NULL;
        newPool->capacity = 0x2800;
        newPool->used = 0;
        newPool->data = (char *)Z_MallocInternal(0x2800);
        gp->textPoolList = newPool;
    }

    /* Set writeable flags */
    gp->writeable = (byte)writeable;
    ((GPGroup *)_this)->cleanFlag = (byte)writeable;

    /* Parse using the top pool */
    topPool = gp->textPoolList;
    return (Bool)GPGroup_Parse((const GPGroup *)_this, dataPtr, &topPool);

}
