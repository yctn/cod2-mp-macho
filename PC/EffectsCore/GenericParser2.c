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

static char token[1024]; /* token */

static char * GetToken(Bool readUntilEOL);
const char * GPValue_GetTopValue(const GPValue * _this);
Bool GPValue_IsList(const GPValue * _this);
void GPGroup_SortObject(const GPGroup * _this, GPObject *object, GPObject * *unsortedList, GPObject * *sortedList, GPObject * *lastObject);
void GPGroup_Clean(const GPGroup * _this);
void GenericParser2_GenericParser2(const GenericParser2 * _this);
char * TextPool_AllocText(const TextPool * _this, char *text, int addNULL, TextPool * *poolPtr);
GPGroup * GPGroup_AddGroup(const GPGroup * _this, const char *name, TextPool * *textPool);
void GPValue_AddValue(const GPValue * _this, const char *newValue, TextPool * *textPool);
GPValue * GPGroup_AddPair(const GPGroup * _this, const char *name, const char *value, TextPool * *textPool);
void ZN14GenericParser2D2Ev(void); /* GenericParser2_~GenericParser2 */
void ZN14GenericParser2D1Ev(void); /* GenericParser2_~GenericParser2 */
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

/* line 30 */
static __attribute__((naked))
char * GetToken(Bool readUntilEOL)
{
#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 30 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %edi\n" /* text */
        "movl %edx, %esi\n" /* allowLineBreaks */
        "movb %cl, -0x1d(%ebp)\n"
        /* { scope 1 */
        "movl (%eax), %ebx\n" /* line 32 | pointer */
        "movb $0, token\n" /* line 37 */
        "testl %ebx, %ebx\n" /* line 38 | pointer */
        "je .Lfabf10_000abf85\n"
        "movzbl (%ebx), %eax\n" /* pointer */
        ".Lfabf10_000abf30:\n"
        "movl %eax, %ecx\n" /* line 48 */
        "cmpb $0x20, %al\n" /* line 49 */
        "jle .Lfabf10_000abf5f\n"
        ".Lfabf10_000abf36:\n"
        "cmpb $0x2f, %cl\n" /* line 73 */
        "jne .Lfabf10_000abff5\n"
        "movzbl 1(%ebx), %eax\n" /* pointer */
        "cmpb $0x2f, %al\n"
        "je .Lfabf10_000abfad\n"
        "cmpb $0x2a, %al\n" /* line 82 */
        "jne .Lfabf10_000ac0f5\n"
        "addl $2, %ebx\n" /* line 84 | pointer */
        "movzbl (%ebx), %eax\n" /* line 85 | pointer */
        "testb %al, %al\n"
        "jne .Lfabf10_000abf9c\n"
        "movl %eax, %ecx\n" /* line 48 */
        "cmpb $0x20, %al\n" /* line 49 */
        "jg .Lfabf10_000abf36\n"
        ".Lfabf10_000abf5f:\n"
        "testb %al, %al\n" /* line 53 */
        "je .Lfabf10_000abf7f\n"
        "xorl %edx, %edx\n"
        ".Lfabf10_000abf65:\n"
        "cmpb $0xa, %cl\n" /* line 58 */
        "movl $1, %eax\n"
        "cmovel %eax, %edx\n"
        "addl $1, %ebx\n" /* line 62 | pointer */
        "movzbl (%ebx), %ecx\n" /* line 48 | pointer */
        "cmpb $0x20, %cl\n" /* line 49 */
        "jg .Lfabf10_000abfd4\n"
        "testb %cl, %cl\n" /* line 53 */
        "jne .Lfabf10_000abf65\n"
        ".Lfabf10_000abf7f:\n"
        "movl $0, (%edi)\n" /* line 55 | text */
        /* } scope */
        ".Lfabf10_000abf85:\n"
        "movl $token, %eax\n" /* line 175 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfabf10_000abf92:\n"
        "addl $1, %ebx\n" /* line 85 | pointer */
        ".Lfabf10_000abf95:\n"
        "movzbl (%ebx), %eax\n" /* pointer */
        "testb %al, %al\n"
        "je .Lfabf10_000abf30\n"
        ".Lfabf10_000abf9c:\n"
        "cmpb $0x2a, %al\n"
        "jne .Lfabf10_000abf92\n"
        "leal 1(%ebx), %eax\n" /* pointer */
        "cmpb $0x2f, 1(%ebx)\n" /* pointer */
        "je .Lfabf10_000abfea\n"
        "movl %eax, %ebx\n" /* pointer */
        "jmp .Lfabf10_000abf95\n"
        ".Lfabf10_000abfad:\n"
        "addl $2, %ebx\n" /* line 75 | pointer */
        "movzbl (%ebx), %eax\n" /* line 76 | pointer */
        "testb %al, %al\n"
        "je .Lfabf10_000abf30\n"
        "jmp .Lfabf10_000abfcb\n"
        ".Lfabf10_000abfbd:\n"
        "addl $1, %ebx\n" /* line 78 | pointer */
        "movzbl (%ebx), %eax\n" /* line 76 | pointer */
        "testb %al, %al\n"
        "je .Lfabf10_000abf30\n"
        ".Lfabf10_000abfcb:\n"
        "cmpb $0xa, %al\n"
        "jne .Lfabf10_000abfbd\n"
        "jmp .Lfabf10_000abf30\n"
        ".Lfabf10_000abfd4:\n"
        "testb %dl, %dl\n" /* line 64 */
        "je .Lfabf10_000abf36\n"
        "movl %esi, %eax\n" /* length */
        "testb %al, %al\n"
        "jne .Lfabf10_000abf36\n"
        "movl %ebx, (%edi)\n" /* line 172 | pointer, text */
        "jmp .Lfabf10_000abf85\n"
        ".Lfabf10_000abfea:\n"
        "addl $2, %ebx\n" /* line 91 | pointer */
        "movzbl (%ebx), %eax\n" /* pointer */
        "jmp .Lfabf10_000abf30\n"
        ".Lfabf10_000abff5:\n"
        "cmpb $0x22, %cl\n" /* line 100 */
        "je .Lfabf10_000ac0ff\n"
        ".Lfabf10_000abffe:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 120 */
        "jne .Lfabf10_000ac05a\n"
        "movl $0, -0x1c(%ebp)\n"
        ".Lfabf10_000ac00b:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 149 */
        "movb %cl, token(%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "cmpl $0x3ff, %edx\n"
        "jle .Lfabf10_000ac18b\n"
        ".Lfabf10_000ac026:\n"
        "addl $1, %ebx\n" /* line 151 | pointer */
        "cmpb $0x20, (%ebx)\n" /* line 145 | pointer */
        "jg .Lfabf10_000ac026\n"
        ".Lfabf10_000ac02e:\n"
        "cmpb $0x22, token\n" /* line 156 */
        "je .Lfabf10_000ac150\n"
        "movl -0x1c(%ebp), %esi\n" /* length */
        ".Lfabf10_000ac03e:\n"
        "cmpl $0x400, %esi\n" /* line 167 | length */
        "movl $0, %eax\n"
        "cmovgel %eax, %esi\n" /* length */
        "movb $0, token(%esi)\n" /* line 171 | length */
        "movl %ebx, (%edi)\n" /* line 172 | pointer, text */
        "jmp .Lfabf10_000abf85\n"
        ".Lfabf10_000ac05a:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 120 */
        "jmp .Lfabf10_000ac08b\n"
        ".Lfabf10_000ac063:\n"
        "addl $1, %ebx\n" /* line 125 | pointer */
        ".Lfabf10_000ac066:\n"
        "cmpl $0x3ff, -0x1c(%ebp)\n" /* line 130 */
        "jg .Lfabf10_000ac07e\n"
        "movl -0x1c(%ebp), %eax\n" /* line 132 */
        "movb %cl, token(%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lfabf10_000ac07e:\n"
        "movzbl (%ebx), %ecx\n" /* line 135 | pointer */
        "cmpb $0xa, %cl\n" /* line 123 */
        "je .Lfabf10_000ac0a3\n"
        "cmpb $0xd, %cl\n"
        "je .Lfabf10_000ac0a3\n"
        ".Lfabf10_000ac08b:\n"
        "cmpb $0x2f, %cl\n" /* line 125 */
        "jne .Lfabf10_000ac063\n"
        "leal 1(%ebx), %edx\n" /* pointer */
        "movzbl 1(%ebx), %eax\n" /* pointer */
        "cmpb $0x2f, %al\n"
        "je .Lfabf10_000ac0a3\n"
        "cmpb $0x2a, %al\n"
        "je .Lfabf10_000ac0a3\n"
        "movl %edx, %ebx\n" /* pointer */
        "jmp .Lfabf10_000ac066\n"
        ".Lfabf10_000ac0a3:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 138 */
        "testl %eax, %eax\n"
        "je .Lfabf10_000ac02e\n"
        "movl -0x1c(%ebp), %esi\n" /* length */
        "subl $1, %esi\n" /* length */
        "cmpb $0x1f, token(%esi)\n" /* length */
        "jg .Lfabf10_000ac02e\n"
        "leal token(%esi), %eax\n" /* length */
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lfabf10_000ac0ca:\n"
        "movl %esi, %eax\n" /* line 30 | allowLineBreaks */
        "subl %edx, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl %edx, %esi\n" /* line 138 | length */
        "je .Lfabf10_000ac02e\n"
        "leal mantle_check_radius+103(%esi), %eax\n" /* length */
        "subl -0x24(%ebp), %eax\n"
        "movzbl (%eax, %ecx), %eax\n"
        "addl $1, %edx\n"
        "subl $1, %ecx\n"
        "cmpb $0x1f, %al\n"
        "jle .Lfabf10_000ac0ca\n"
        "jmp .Lfabf10_000ac02e\n"
        ".Lfabf10_000ac0f5:\n"
        "movl $0x2f, %ecx\n" /* line 116 */
        "jmp .Lfabf10_000abffe\n"
        ".Lfabf10_000ac0ff:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 100 */
        "jne .Lfabf10_000ac05a\n"
        "addl $1, %ebx\n" /* line 102 | pointer */
        "movl $0, -0x1c(%ebp)\n"
        ".Lfabf10_000ac113:\n"
        "movzbl (%ebx), %eax\n" /* line 105 | pointer */
        "addl $1, %ebx\n" /* pointer */
        "cmpb $0x22, %al\n" /* line 106 */
        "je .Lfabf10_000ac02e\n"
        ".Lfabf10_000ac121:\n"
        "testb %al, %al\n" /* line 110 */
        "je .Lfabf10_000ac02e\n"
        "cmpl $0x3ff, -0x1c(%ebp)\n" /* line 114 */
        "jg .Lfabf10_000ac113\n"
        "movl -0x1c(%ebp), %edx\n" /* line 116 */
        "movb %al, token(%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movzbl (%ebx), %eax\n" /* line 105 | pointer */
        "addl $1, %ebx\n" /* pointer */
        "cmpb $0x22, %al\n" /* line 106 */
        "jne .Lfabf10_000ac121\n"
        "jmp .Lfabf10_000ac02e\n"
        ".Lfabf10_000ac150:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 158 | length */
        "subl $1, %esi\n" /* length */
        "movl %esi, 8(%esp)\n" /* line 159 | length */
        "movl $token+1, 4(%esp)\n"
        "movl $token, (%esp)\n"
        "calll memmove\n"
        "testl %esi, %esi\n" /* line 161 | length */
        "je .Lfabf10_000ac03e\n"
        "movl -0x1c(%ebp), %eax\n"
        "subl $2, %eax\n"
        "cmpb $0x22, token(%eax)\n"
        "cmovel %eax, %esi\n" /* length */
        "jmp .Lfabf10_000ac03e\n"
        ".Lfabf10_000ac18b:\n"
        "addl $1, %ebx\n" /* line 151 | pointer */
        "movzbl (%ebx), %ecx\n" /* line 152 | pointer */
        "cmpb $0x20, %cl\n" /* line 145 */
        "jg .Lfabf10_000ac00b\n"
        "jmp .Lfabf10_000ac02e\n"
    );
#endif /* Original ASM */
    /* Register convention trampoline: eax=text(char**), edx=allowLineBreaks, ecx=readUntilEOL */
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll GetToken_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}

/* line 335 */
const char * GPValue_GetTopValue(const GPValue * _this)
{
    void *p = *(void **)((byte *)_this + 0x10);
    if (p)
        return *(const char **)p;
    return (const char *)p;
}

/* line 324 */
Bool GPValue_IsList(const GPValue * _this)
{
    byte *self = (byte *)_this;
    void *p = *(void **)(self + 0x10);
    if (p) {
        void *next = *(void **)((byte *)p + 4);
        if (next) {
            return 1;
        }
    }
    return 0;
#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 324 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 326 | this */
        "movl 0x10(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfac1b4_000ac1cf\n"
        "movl 4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfac1b4_000ac1cf\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 332 */
        "retl\n"
        ".Lfac1b4_000ac1cf:\n"
        "xorl %eax, %eax\n" /* line 326 */
        "popl %ebp\n" /* line 332 */
        "retl\n"
    );
#endif /* Original ASM */
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
    byte *obj = (byte *)object;
    byte *test;
    byte *last;

    /* If unsortedList is empty, this is the first+only object in both lists */
    if (*unsortedList == NULL) {
        *sortedList = object;
        *unsortedList = object;
        *lastObject = object;
        return;
    }

    /* Link: lastObject->next(sorted) = object  (offset 4 of the linked node at *lastObject) */
    /* Actually from the ASM: *((*lastObject) + 4) = object — that's the "next" field at offset 4 */
    *(GPObject **)((byte *)(*lastObject) + 4) = object;

    /* Walk the sorted list to find insertion point */
    test = (byte *)(*sortedList);
    if (!test) {
        /* Sorted list is empty, object becomes head */
        *sortedList = object;
        *lastObject = object;
        return;
    }

    last = NULL;
    while (1) {
        /* Compare object->name with test->name */
        const char *objName = *(const char **)obj;     /* offset 0x00 */
        const char *testName = *(const char **)test;   /* offset 0x00 */
        int cmp = strcmpi(objName, testName);
        if (cmp < 0) {
            /* Insert before test */
            *(GPObject **)((byte *)test + 0x0c) = object;  /* test->prev = object */
            *(GPObject **)(obj + 0x08) = (GPObject *)test;  /* object->next(sorted) = test */
            if (last) {
                /* Insert after last */
                *(GPObject **)(last + 0x08) = object;       /* last->next(sorted) = object */
                *(GPObject **)(obj + 0x0c) = (GPObject *)last;  /* object->prev = last */
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
            void *nextSorted = *(void **)((byte *)test + 8); /* offset 0x08 = next(sorted) */
            if (!nextSorted) {
                /* End of sorted list, insert after test */
                last = test;
                break;
            }
            last = test;
            test = (byte *)nextSorted;
        }
    }

    /* Insert after last (at end of sorted list) */
    *(GPObject **)(last + 0x08) = object;       /* last->next(sorted) = object */
    *(GPObject **)(obj + 0x0c) = (GPObject *)last; /* object->prev = last */
    *lastObject = object;

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 568 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* object */
        "movl 0x10(%ebp), %eax\n" /* unsortedList */
        /* { scope 1 */
        "movl (%eax), %ecx\n" /* line 572 */
        "testl %ecx, %ecx\n"
        "je .Lfac1d6_000ac245\n"
        "movl 0x18(%ebp), %edx\n" /* line 52 | lastObject */
        "movl (%edx), %eax\n"
        "movl %edi, 4(%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 580 | sortedList */
        "movl (%eax), %ebx\n" /* test */
        "testl %ebx, %ebx\n" /* line 582 | test */
        "je .Lfac1d6_000ac234\n"
        "xorl %esi, %esi\n" /* last */
        "jmp .Lfac1d6_000ac204\n"
        ".Lfac1d6_000ac200:\n"
        "movl %ebx, %esi\n" /* test, last */
        "movl %eax, %ebx\n" /* test */
        ".Lfac1d6_000ac204:\n"
        "movl (%ebx), %eax\n" /* line 584 | test */
        "movl %eax, 4(%esp)\n"
        "movl (%edi), %eax\n" /* object */
        "movl %eax, (%esp)\n"
        "calll strcmpi\n"
        "testl %eax, %eax\n"
        "js .Lfac1d6_000ac259\n"
        "movl 8(%ebx), %eax\n" /* line 53 */
        "testl %eax, %eax\n" /* line 582 */
        "jne .Lfac1d6_000ac200\n"
        "movl %ebx, %esi\n" /* test, last */
        ".Lfac1d6_000ac221:\n"
        "movl %edi, 8(%esi)\n" /* line 54 */
        "movl %esi, 0xc(%edi)\n" /* line 56 */
        "movl 0x18(%ebp), %eax\n" /* line 609 | lastObject */
        "movl %edi, (%eax)\n" /* object */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfac1d6_000ac234:\n"
        "movl %eax, %edx\n"
        /* { scope 1 */
        "movl %edi, (%edx)\n" /* line 605 | object */
        ".Lfac1d6_000ac238:\n"
        "movl 0x18(%ebp), %eax\n" /* line 609 | lastObject */
        "movl %edi, (%eax)\n" /* object */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfac1d6_000ac245:\n"
        "movl 0x14(%ebp), %edx\n" /* line 574 | sortedList */
        "movl %edi, (%edx)\n" /* object */
        "movl %edi, (%eax)\n" /* object */
        "movl 0x18(%ebp), %eax\n" /* line 609 | lastObject */
        "movl %edi, (%eax)\n" /* object */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfac1d6_000ac259:\n"
        "movl %edi, 0xc(%ebx)\n" /* line 56 */
        "movl %ebx, 8(%edi)\n" /* line 54 */
        "testl %esi, %esi\n" /* line 598 | last */
        "jne .Lfac1d6_000ac221\n"
        "movl 0x14(%ebp), %edx\n" /* sortedList */
        "movl %edi, (%edx)\n" /* line 605 | object */
        "jmp .Lfac1d6_000ac238\n"
    );
#endif /* Original ASM */
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
    byte *self = (byte *)_this;
    byte *pair;
    byte *nextPair;
    byte *subGroup;
    byte *nextSubGroup;

    /* Free all pairs (GPValues) at offset 0x10 */
    pair = *(byte **)(self + 0x10);
    while (pair) {
        /* Save the next pointer (offset 4 of pair = next unsorted) */
        nextPair = *(byte **)(pair + 4);
        *(byte **)(self + 0x18) = nextPair;

        /* Free all value nodes in this pair's value list (offset 0x10 of GPValue) */
        {
            byte *valNode = *(byte **)(pair + 0x10);
            while (valNode) {
                byte *nextVal = *(byte **)(valNode + 4);
                Z_FreeInternal(valNode);
                *(byte **)(pair + 0x10) = nextVal;
                valNode = nextVal;
            }
        }

        /* Free the pair itself */
        Z_FreeInternal(pair);

        /* Move to next pair */
        pair = *(byte **)(self + 0x18);
        *(byte **)(self + 0x10) = pair;
    }

    /* Free all sub-groups (GPGroups) at offset 0x1c */
    subGroup = *(byte **)(self + 0x1c);
    while (subGroup) {
        /* Save next pointer (offset 4 of subgroup = next unsorted) */
        nextSubGroup = *(byte **)(subGroup + 4);
        *(byte **)(self + 0x24) = nextSubGroup;

        /* Recursively clean the sub-group */
        GPGroup_Clean((const GPGroup *)subGroup);

        /* Free the sub-group itself */
        Z_FreeInternal(subGroup);

        /* Move to next sub-group */
        subGroup = *(byte **)(self + 0x24);
        *(byte **)(self + 0x1c) = subGroup;
    }

    /* Zero out all internal pointers */
    *(void **)(self + 0x18) = 0;
    *(void **)(self + 0x14) = 0;
    *(void **)(self + 0x10) = 0;
    *(void **)(self + 0x24) = 0;
    *(void **)(self + 0x20) = 0;
    *(void **)(self + 0x1c) = 0;
    *(void **)(self + 0x28) = 0;
    *(byte *)(self + 0x2c) = 0;

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        ".Lfac26a_000ac26a:\n"
        "pushl %ebp\n" /* line 505 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0x10(%edi), %esi\n" /* line 507 | this */
        "movl %esi, %eax\n"
        "testl %esi, %esi\n"
        "je .Lfac26a_000ac2be\n"
        ".Lfac26a_000ac27f:\n"
        "movl 4(%eax), %eax\n" /* line 509 */
        "movl %eax, 0x18(%edi)\n" /* this */
        "testl %esi, %esi\n" /* line 510 */
        "je .Lfac26a_000ac337\n"
        /* { scope 1 */
        "movl 0x10(%esi), %eax\n" /* line 280 */
        "testl %eax, %eax\n"
        "jne .Lfac26a_000ac298\n"
        "jmp .Lfac26a_000ac2aa\n"
        /* } scope */
        ".Lfac26a_000ac296:\n"
        "movl %ebx, %eax\n" /* line 510 */
        /* { scope 1 */
        ".Lfac26a_000ac298:\n"
        "movl 4(%eax), %ebx\n" /* line 51 */
        "movl %eax, (%esp)\n" /* line 63 */
        "calll Z_FreeInternal\n"
        "movl %ebx, 0x10(%esi)\n" /* line 284 */
        "testl %ebx, %ebx\n" /* line 280 */
        "jne .Lfac26a_000ac296\n"
        /* } scope */
        ".Lfac26a_000ac2aa:\n"
        "movl %esi, (%esp)\n" /* line 63 */
        "calll Z_FreeInternal\n"
        "movl 0x18(%edi), %esi\n"
        ".Lfac26a_000ac2b5:\n"
        "movl %esi, %eax\n" /* line 511 */
        "movl %esi, 0x10(%edi)\n" /* this */
        "testl %esi, %esi\n" /* line 507 */
        "jne .Lfac26a_000ac27f\n"
        ".Lfac26a_000ac2be:\n"
        "movl 0x1c(%edi), %ebx\n" /* line 514 | this */
        "movl %ebx, %eax\n"
        "testl %ebx, %ebx\n"
        "jne .Lfac26a_000ac2e5\n"
        "jmp .Lfac26a_000ac2fa\n"
        ".Lfac26a_000ac2c9:\n"
        "movl %ebx, (%esp)\n" /* line 465 */
        "calll GPGroup_Clean\n"
        "movl %ebx, (%esp)\n" /* line 63 */
        "calll Z_FreeInternal\n"
        "movl 0x24(%edi), %ebx\n"
        "movl %ebx, %eax\n" /* line 518 */
        "movl %ebx, 0x1c(%edi)\n" /* this */
        "testl %ebx, %ebx\n" /* line 514 */
        "je .Lfac26a_000ac2fa\n"
        ".Lfac26a_000ac2e5:\n"
        "movl 4(%eax), %eax\n" /* line 516 */
        "movl %eax, 0x24(%edi)\n" /* this */
        "testl %ebx, %ebx\n" /* line 517 */
        "jne .Lfac26a_000ac2c9\n"
        "movl %eax, %ebx\n"
        "movl %ebx, %eax\n" /* line 518 */
        "movl %ebx, 0x1c(%edi)\n" /* this */
        "testl %ebx, %ebx\n" /* line 514 */
        "jne .Lfac26a_000ac2e5\n"
        ".Lfac26a_000ac2fa:\n"
        "movl $0, 0x18(%edi)\n" /* line 521 | this */
        "movl $0, 0x14(%edi)\n" /* this */
        "movl $0, 0x10(%edi)\n" /* this */
        "movl $0, 0x24(%edi)\n" /* line 522 | this */
        "movl $0, 0x20(%edi)\n" /* this */
        "movl $0, 0x1c(%edi)\n" /* this */
        "movl $0, 0x28(%edi)\n" /* line 523 | this */
        "movb $0, 0x2c(%edi)\n" /* line 524 | this */
        "addl $0x1c, %esp\n" /* line 525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfac26a_000ac337:\n"
        "movl %eax, %esi\n"
        "jmp .Lfac26a_000ac2b5\n"
    );
#endif /* Original ASM */
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
    byte *self = (byte *)_this;
    *(const char **)(self + 0x00) = str_0021e4f8; /* "Top Level" */
    *(int *)(self + 0x04) = 0;
    *(int *)(self + 0x08) = 0;
    *(int *)(self + 0x0c) = 0;
    *(int *)(self + 0x10) = 0;
    *(int *)(self + 0x14) = 0;
    *(int *)(self + 0x18) = 0;
    *(int *)(self + 0x1c) = 0;
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = 0;
    *(int *)(self + 0x28) = 0;
    *(byte *)(self + 0x2c) = 0;
    *(int *)(self + 0x30) = 0;
    *(byte *)(self + 0x34) = 0;

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 818 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $str_0021e4f8, (%eax)\n" /* line 243 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n" /* line 458 */
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl $0, 0x1c(%eax)\n"
        "movl $0, 0x20(%eax)\n"
        "movl $0, 0x24(%eax)\n"
        "movl $0, 0x28(%eax)\n"
        "movb $0, 0x2c(%eax)\n"
        "movl $0, 0x30(%eax)\n" /* line 820 */
        "movb $0, 0x34(%eax)\n"
        "popl %ebp\n" /* line 822 */
        "retl\n"
    );
#endif /* Original ASM */
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
    byte *pool = (byte *)_this;
    int length;
    int extra;
    int used;
    char *dest;

    extra = addNULL ? 1 : 0;
    length = strlen(text) + extra;

    used = *(int *)(pool + 0x0c);
    if (used + length + 1 <= *(int *)(pool + 0x08)) {
        /* Fits in current pool */
        dest = *(char **)pool + used;
        strcpy(dest, text);
        used += length;
        *(int *)(pool + 0x0c) = used;
        /* Null terminate at end */
        (*(char **)pool)[used] = '\0';
        /* Return pointer to start of allocated text */
        return *(char **)pool + used - length;
    }

    /* Doesn't fit — need a new pool */
    if (!poolPtr) {
        return NULL;
    }

    {
        byte *newPool;
        int initSize;
        TextPool *prev;
        TextPool *newNode;

        initSize = *(int *)(pool + 0x08);

        /* Allocate new TextPool node (0x10 bytes) */
        newPool = (byte *)Z_MallocInternal(0x10);

        /* Initialize new pool */
        *(void **)(newPool + 0x04) = NULL;
        *(int *)(newPool + 0x08) = initSize;
        *(int *)(newPool + 0x0c) = 0;
        *(void **)newPool = Z_MallocInternal(initSize);

        /* Link: current pool's next = newPool */
        prev = (TextPool *)(*poolPtr);
        *(void **)((byte *)prev + 0x04) = (void *)newPool;

        /* Update poolPtr to point to new pool */
        newNode = (TextPool *)(*(void **)((byte *)(*poolPtr) + 0x04));
        *poolPtr = newNode;

        /* Recurse into new pool with no poolPtr (NULL) to avoid infinite recursion */
        return TextPool_AllocText(newNode, text, addNULL ? 1 : 0, NULL);
    }

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        ".Lfac3a2_000ac3a2:\n"
        "pushl %ebp\n" /* line 201 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* text */
        "movl 0x14(%ebp), %eax\n" /* poolPtr */
        "movl %eax, -0x20(%ebp)\n" /* poolPtr */
        "movzbl 0x10(%ebp), %edx\n" /* addNULL */
        "movb %dl, -0x19(%ebp)\n" /* addNULL */
        /* { scope 1 */
        "testb %dl, %dl\n" /* line 203 */
        "setne %dl\n"
        "movzbl %dl, %edx\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* text, length */
        "repne scasb %es:(%edi), %al\n" /* length */
        "notl %ecx\n"
        "leal -1(%ecx, %edx), %edi\n" /* length */
        "movl 0xc(%ebx), %edx\n" /* line 205 | this */
        "leal 1(%edi, %edx), %eax\n" /* length */
        "cmpl 8(%ebx), %eax\n" /* this */
        "jg .Lfac3a2_000ac40f\n"
        "movl %esi, 4(%esp)\n" /* line 218 | text */
        "addl (%ebx), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movl %edi, %edx\n" /* line 219 | which */
        "addl 0xc(%ebx), %edx\n" /* this */
        "movl %edx, 0xc(%ebx)\n" /* this */
        "movl (%ebx), %eax\n" /* line 220 | this */
        "movb $0, (%eax, %edx)\n"
        "movl (%ebx), %eax\n" /* line 222 | this */
        "addl 0xc(%ebx), %eax\n" /* this */
        "subl %edi, %eax\n" /* which */
        /* } scope */
        ".Lfac3a2_000ac407:\n"
        "addl $0x2c, %esp\n" /* line 223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfac3a2_000ac40f:\n"
        "movl -0x20(%ebp), %edi\n" /* line 207 | poolPtr, length */
        "testl %edi, %edi\n" /* length */
        "je .Lfac3a2_000ac474\n"
        "movl $0x10, (%esp)\n" /* line 31 */
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n"
        "movl 8(%ebx), %eax\n" /* line 209 | this, initSize */
        /* { scope 2 */
        "movl $0, 4(%edi)\n" /* line 181 */
        "movl %eax, 8(%edi)\n"
        "movl $0, 0xc(%edi)\n"
        "movl %eax, (%esp)\n" /* line 184 */
        "calll Z_MallocInternal\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x20(%ebp), %edx\n" /* line 23 | poolPtr */
        "movl (%edx), %eax\n"
        "movl %edi, 4(%eax)\n"
        /* } scope */
        "movl (%edx), %eax\n" /* line 22 */
        "movl 4(%eax), %edx\n"
        "movl -0x20(%ebp), %eax\n" /* line 210 | poolPtr */
        "movl %edx, (%eax)\n"
        "movl $0, 0x14(%ebp)\n" /* line 212 | poolPtr */
        "movzbl -0x19(%ebp), %eax\n" /* addNULL */
        "movl %eax, 0x10(%ebp)\n" /* addNULL */
        "movl %esi, 0xc(%ebp)\n" /* text */
        "movl %edx, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp TextPool_AllocText\n" /* line 212 */
        ".Lfac3a2_000ac474:\n"
        "xorl %eax, %eax\n" /* line 207 */
        "jmp .Lfac3a2_000ac407\n"
        "movl %eax, %ebx\n" /* this */
        "movl %edi, (%esp)\n" /* line 32 */
        "calll Z_FreeInternal\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
#endif /* Original ASM */
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
    byte *self = (byte *)_this;
    const char *allocName = name;
    byte *newGroup;

    /* Allocate the name in the text pool if textPool is provided */
    if (textPool) {
        allocName = TextPool_AllocText(*textPool, (char *)name, 1, textPool);
    }

    /* Allocate a new GPGroup (0x30 bytes) */
    newGroup = (byte *)Z_MallocInternal(0x30);

    /* Initialize: name at offset 0, rest zeroed */
    *(const char **)(newGroup + 0x00) = allocName;
    *(int *)(newGroup + 0x04) = 0;
    *(int *)(newGroup + 0x08) = 0;
    *(int *)(newGroup + 0x0c) = 0;
    *(int *)(newGroup + 0x10) = 0;
    *(int *)(newGroup + 0x14) = 0;
    *(int *)(newGroup + 0x18) = 0;
    *(int *)(newGroup + 0x1c) = 0;
    *(int *)(newGroup + 0x20) = 0;
    *(int *)(newGroup + 0x24) = 0;
    *(int *)(newGroup + 0x28) = 0;
    *(byte *)(newGroup + 0x2c) = 0;

    /* Insert into sorted sub-group list */
    GPGroup_SortObject(_this, (GPObject *)newGroup,
                       (GPObject **)(self + 0x1c),
                       (GPObject **)(self + 0x20),
                       (GPObject **)(self + 0x24));

    return (GPGroup *)newGroup;

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 641 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* name */
        "movl 0x10(%ebp), %eax\n" /* textPool */
        "testl %eax, %eax\n" /* line 645 */
        "je .Lfac48a_000ac4bc\n"
        "movl %eax, 0xc(%esp)\n" /* line 647 */
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* name */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll TextPool_AllocText\n"
        "movl %eax, %esi\n" /* name */
        ".Lfac48a_000ac4bc:\n"
        "movl $0x30, (%esp)\n" /* line 62 */
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%eax)\n" /* line 243 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n" /* line 458 */
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl $0, 0x1c(%eax)\n"
        "movl $0, 0x20(%eax)\n"
        "movl $0, 0x24(%eax)\n"
        "movl $0, 0x28(%eax)\n"
        "movb $0, 0x2c(%eax)\n"
        "leal 0x24(%edi), %eax\n" /* line 661 | this */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x20(%edi), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x1c(%edi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* this */
        "calll GPGroup_SortObject\n"
        "movl %ebx, %eax\n" /* line 655 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
#endif /* Original ASM */
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
    byte *self = (byte *)_this;
    const char *allocValue = newValue;
    byte *head;
    byte *newNode;

    /* Allocate value string in text pool if provided */
    if (textPool) {
        allocValue = TextPool_AllocText(*textPool, (char *)newValue, 1, textPool);
    }

    head = *(byte **)(self + 0x10);
    if (head) {
        /* Value list already exists — append new node */
        newNode = (byte *)Z_MallocInternal(0x10);
        *(const char **)(newNode + 0x00) = allocValue;
        *(void **)(newNode + 0x04) = NULL;
        *(void **)(newNode + 0x08) = NULL;
        *(void **)(newNode + 0x0c) = NULL;

        /* Link: last->next = newNode */
        {
            byte *lastNode = *(byte **)(head + 0x08); /* head's "last" pointer */
            *(void **)(lastNode + 0x04) = newNode;
        }

        /* Update head's "last" pointer to point to newNode */
        {
            byte *lastNode = *(byte **)(head + 0x08);
            byte *nextOfLast = *(byte **)(lastNode + 0x04);
            *(byte **)(head + 0x08) = nextOfLast;
        }
    } else {
        /* First value — create head node */
        newNode = (byte *)Z_MallocInternal(0x10);
        *(const char **)(newNode + 0x00) = allocValue;
        *(void **)(newNode + 0x04) = NULL;
        *(void **)(newNode + 0x0c) = NULL;
        *(byte **)(self + 0x10) = newNode;
        /* Head's "last" pointer points to itself */
        *(byte **)(newNode + 0x08) = newNode;
    }

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* newValue */
        "movl 0x10(%ebp), %eax\n" /* textPool */
        "testl %eax, %eax\n" /* line 348 */
        "je .Lfac542_000ac573\n"
        "movl %eax, 0xc(%esp)\n" /* line 350 */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* newValue */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll TextPool_AllocText\n"
        "movl %eax, %ebx\n" /* newValue */
        ".Lfac542_000ac573:\n"
        "movl 0x10(%esi), %eax\n" /* line 353 | this */
        "testl %eax, %eax\n"
        "je .Lfac542_000ac5b9\n"
        "movl $0x10, (%esp)\n" /* line 62 */
        "calll Z_MallocInternal\n"
        "movl %ebx, (%eax)\n" /* line 243 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl 0x10(%esi), %edx\n" /* line 52 */
        "movl 8(%edx), %edx\n"
        "movl %eax, 4(%edx)\n"
        "movl 0x10(%esi), %edx\n" /* line 361 | this */
        "movl 8(%edx), %eax\n" /* line 54 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 8(%edx)\n"
        "addl $0x10, %esp\n" /* line 363 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfac542_000ac5b9:\n"
        "movl $0x10, (%esp)\n" /* line 62 */
        "calll Z_MallocInternal\n"
        "movl %ebx, (%eax)\n" /* line 243 */
        "movl $0, 4(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl %eax, 0x10(%esi)\n" /* line 355 | this */
        "movl %eax, 8(%eax)\n" /* line 54 */
        "addl $0x10, %esp\n" /* line 363 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
#endif /* Original ASM */
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
    byte *self = (byte *)_this;
    const char *allocName = name;
    const char *allocValue = value;
    byte *newPair;

    /* Allocate name and value in text pool if textPool is provided */
    if (textPool) {
        allocName = TextPool_AllocText(*textPool, (char *)name, 1, textPool);
        if (value) {
            allocValue = TextPool_AllocText(*textPool, (char *)value, 1, textPool);
        }
    }

    /* Allocate new GPValue (0x14 bytes) */
    newPair = (byte *)Z_MallocInternal(0x14);
    *(const char **)(newPair + 0x00) = allocName;
    *(int *)(newPair + 0x04) = 0;
    *(int *)(newPair + 0x08) = 0;
    *(int *)(newPair + 0x0c) = 0;
    *(int *)(newPair + 0x10) = 0;

    /* Add the value if present */
    if (allocValue) {
        GPValue_AddValue((const GPValue *)newPair, allocValue, NULL);
    }

    /* Insert into sorted pair list */
    GPGroup_SortObject(_this, (GPObject *)newPair,
                       (GPObject **)(self + 0x10),
                       (GPObject **)(self + 0x14),
                       (GPObject **)(self + 0x18));

    return (GPValue *)newPair;

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 613 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* name */
        "movl 0x10(%ebp), %ebx\n" /* value */
        "movl 0x14(%ebp), %esi\n" /* textPool */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 617 | newPair */
        "je .Lfac5e4_000ac636\n"
        "movl %esi, 0xc(%esp)\n" /* line 619 | newPair */
        "movl $1, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* name */
        "movl (%esi), %eax\n" /* newPair */
        "movl %eax, (%esp)\n"
        "calll TextPool_AllocText\n"
        "movl %eax, %edi\n" /* name */
        "testl %ebx, %ebx\n" /* line 620 | value */
        "je .Lfac5e4_000ac636\n"
        "movl %esi, 0xc(%esp)\n" /* line 622 | newPair */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* value */
        "movl (%esi), %eax\n" /* newPair */
        "movl %eax, (%esp)\n"
        "calll TextPool_AllocText\n"
        "movl %eax, %ebx\n" /* value */
        ".Lfac5e4_000ac636:\n"
        "movl $0x14, (%esp)\n" /* line 62 */
        "calll Z_MallocInternal\n"
        "movl %eax, %esi\n"
        "movl %edi, (%eax)\n" /* line 243 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n" /* line 267 */
        "testl %ebx, %ebx\n" /* line 269 */
        "je .Lfac5e4_000ac67a\n"
        "movl $0, 8(%esp)\n" /* line 271 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GPValue_AddValue\n"
        ".Lfac5e4_000ac67a:\n"
        "movl 8(%ebp), %eax\n" /* line 637 | this */
        "addl $0x18, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x10, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* newPair */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll GPGroup_SortObject\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 631 | newPair */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* value */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 63 */
        "calll Z_FreeInternal\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
#endif /* Original ASM */
}

/* Helper: shared destructor logic for GenericParser2 */
static void GenericParser2_Destroy(byte *self)
{
    byte *pool;
    byte *next;

    /* Clean the group */
    GPGroup_Clean((const GPGroup *)self);

    /* Free all text pools */
    pool = *(byte **)(self + 0x30);
    while (pool) {
        next = *(byte **)(pool + 0x04); /* pool->next */
        /* Free pool data buffer */
        Z_FreeInternal(*(void **)pool);
        /* Free pool node */
        Z_FreeInternal(pool);
        pool = next;
    }

    *(void **)(self + 0x30) = NULL;

    /* Clean again (tail call in original) */
    GPGroup_Clean((const GPGroup *)self);
}

/* line 825 */
void ZN14GenericParser2D2Ev(void) /* GenericParser2_~GenericParser2 */
{
    /* cdecl: this at 8(%ebp) */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"
        "calll GenericParser2_Destroy\n"
        "addl $4, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 825 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl %edi, (%esp)\n" /* line 854 */
        "calll GPGroup_Clean\n"
        "movl 0x30(%edi), %ebx\n" /* line 856 | this */
        "testl %ebx, %ebx\n" /* line 230 */
        "jne .Lfac6c4_000ac6e3\n"
        "jmp .Lfac6c4_000ac6fc\n"
        ".Lfac6c4_000ac6e1:\n"
        "movl %esi, %ebx\n"
        ".Lfac6c4_000ac6e3:\n"
        "movl 4(%ebx), %esi\n" /* line 22 */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 194 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 32 */
        "calll Z_FreeInternal\n"
        "testl %esi, %esi\n" /* line 230 */
        "jne .Lfac6c4_000ac6e1\n"
        ".Lfac6c4_000ac6fc:\n"
        "movl $0, 0x30(%edi)\n" /* line 857 */
        "movl %edi, 8(%ebp)\n" /* line 465 | this */
        "addl $0x1c, %esp\n" /* line 828 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp GPGroup_Clean\n" /* line 465 */
        "movl %eax, %ebx\n" /* this */
        "movl %edi, (%esp)\n"
        "calll GPGroup_Clean\n"
        "movl %ebx, (%esp)\n" /* line 466 | this */
        "calll __Unwind_Resume\n"
    );
#endif /* Original ASM */
}

/* line 825 */
void ZN14GenericParser2D1Ev(void) /* GenericParser2_~GenericParser2 */
{
    /* cdecl: this at 8(%ebp) — identical to D2 */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"
        "calll GenericParser2_Destroy\n"
        "addl $4, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 825 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl %edi, (%esp)\n" /* line 854 */
        "calll GPGroup_Clean\n"
        "movl 0x30(%edi), %ebx\n" /* line 856 | this */
        "testl %ebx, %ebx\n" /* line 230 */
        "jne .Lfac724_000ac743\n"
        "jmp .Lfac724_000ac75c\n"
        ".Lfac724_000ac741:\n"
        "movl %esi, %ebx\n"
        ".Lfac724_000ac743:\n"
        "movl 4(%ebx), %esi\n" /* line 22 */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 194 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 32 */
        "calll Z_FreeInternal\n"
        "testl %esi, %esi\n" /* line 230 */
        "jne .Lfac724_000ac741\n"
        ".Lfac724_000ac75c:\n"
        "movl $0, 0x30(%edi)\n" /* line 857 */
        "movl %edi, 8(%ebp)\n" /* line 465 | this */
        "addl $0x1c, %esp\n" /* line 828 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp GPGroup_Clean\n" /* line 465 */
        "movl %eax, %ebx\n" /* this */
        "movl %edi, (%esp)\n"
        "calll GPGroup_Clean\n"
        "movl %ebx, (%esp)\n" /* line 466 | this */
        "calll __Unwind_Resume\n"
    );
#endif /* Original ASM */
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
            if (*(void **)(self + 0x28) != NULL) {
                return 0;
            }
            return 1;
        }

        /* Check for "}" — end of group */
        if (strcmpi(tok, str_0021e508) == 0) {
            return 1;
        }

        /* Save current token as name */
        I_strncpyz(lastToken, tok, 0x400);

        /* Get next token to determine what follows the name */
        tok = GetToken_impl(dataPtr, 1, 1);

        if (strcmpi(tok, str_0021e50c) == 0) {
            /* "{" — sub-group */
            GPGroup *newGroup;
            newGroup = GPGroup_AddGroup(_this, lastToken, textPool);
            /* Copy writeable flag from parent */
            *(byte *)((byte *)newGroup + 0x2c) = *(byte *)(self + 0x2c);
            /* Recursively parse sub-group */
            if (!GPGroup_Parse((const GPGroup *)newGroup, dataPtr, textPool)) {
                return 0;
            }
            continue;
        }

        if (strcmpi(tok, str_0021e510) == 0) {
            /* "[" — list of values */
            GPValue *newPair;
            newPair = GPGroup_AddPair(_this, lastToken, NULL, textPool);

            /* Read values until "]" */
            while (1) {
                tok = GetToken_impl(dataPtr, 1, 1);
                if (tok[0] == '\0') {
                    return 0;
                }
                if (strcmpi(tok, str_0021e504) == 0) {
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

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        ".Lfac784_000ac784:\n"
        "pushl %ebp\n" /* line 682 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* textPool */
        /* { scope 1 */
        ".Lfac784_000ac793:\n"
        "xorl %ecx, %ecx\n" /* line 691 */
        "movl $1, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* dataPtr */
        "calll GetToken\n"
        "movl %eax, %ebx\n" /* token */
        "cmpb $0, (%eax)\n" /* line 693 */
        "je .Lfac784_000ac92a\n"
        ".Lfac784_000ac7ad:\n"
        "movl $str_0021e508, 4(%esp)\n" /* line 704 */
        "movl %eax, (%esp)\n"
        "calll strcmpi\n"
        "testl %eax, %eax\n"
        "je .Lfac784_000ac938\n"
        "movl $0x400, 8(%esp)\n" /* line 709 */
        "movl %ebx, 4(%esp)\n" /* token */
        "leal -0x418(%ebp), %edx\n" /* lastToken */
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $1, %ecx\n" /* line 712 */
        "movl $1, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* dataPtr */
        "calll GetToken\n"
        "movl %eax, %ebx\n" /* token */
        "movl $str_0021e50c, 4(%esp)\n" /* line 713 */
        "movl %eax, (%esp)\n"
        "calll strcmpi\n"
        "testl %eax, %eax\n"
        "jne .Lfac784_000ac852\n"
        "movl %edi, 8(%esp)\n" /* line 715 | textPool */
        "leal -0x418(%ebp), %ecx\n" /* lastToken */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll GPGroup_AddGroup\n"
        "movl 8(%ebp), %ecx\n" /* line 120 | this */
        "movzbl 0x2c(%ecx), %edx\n"
        "movb %dl, 0x2c(%eax)\n"
        "movl %edi, 8(%esp)\n" /* line 717 | textPool */
        "movl 0xc(%ebp), %edx\n" /* dataPtr */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GPGroup_Parse\n"
        "testb %al, %al\n"
        "jne .Lfac784_000ac793\n"
        ".Lfac784_000ac845:\n"
        "xorl %eax, %eax\n" /* line 732 */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 737 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfac784_000ac852:\n"
        "movl $str_0021e510, 4(%esp)\n" /* line 722 */
        "movl %ebx, (%esp)\n" /* token */
        "calll strcmpi\n"
        "testl %eax, %eax\n"
        "jne .Lfac784_000ac8f3\n"
        "movl %edi, 0xc(%esp)\n" /* line 724 | textPool */
        "movl $0, 8(%esp)\n"
        "leal -0x418(%ebp), %ecx\n" /* lastToken */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll GPGroup_AddPair\n"
        "movl %eax, %esi\n" /* newPair */
        "jmp .Lfac784_000ac8d5\n"
        /* { scope 2 */
        ".Lfac784_000ac88f:\n"
        "movl $str_0021e504, 4(%esp)\n" /* line 379 */
        "movl %eax, (%esp)\n"
        "calll strcmpi\n"
        "testl %eax, %eax\n"
        "je .Lfac784_000ac793\n"
        "movl %edi, 0xc(%esp)\n" /* line 384 */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* token */
        "movl (%edi), %eax\n"
        "calll TextPool_AllocText\n"
        "movl $0, 8(%esp)\n" /* line 385 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll GPValue_AddValue\n"
        ".Lfac784_000ac8d5:\n"
        "movl $1, %ecx\n" /* line 373 */
        "movl $1, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* dataPtr */
        "calll GetToken\n"
        "movl %eax, %ebx\n" /* token */
        "cmpb $0, (%eax)\n" /* line 375 */
        "jne .Lfac784_000ac88f\n"
        "jmp .Lfac784_000ac845\n"
        /* } scope */
        ".Lfac784_000ac8f3:\n"
        "movl %edi, 0xc(%esp)\n" /* line 732 | textPool */
        "movl %ebx, 8(%esp)\n" /* token */
        "leal -0x418(%ebp), %edx\n" /* lastToken */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll GPGroup_AddPair\n"
        "xorl %ecx, %ecx\n" /* line 691 */
        "movl $1, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* dataPtr */
        "calll GetToken\n"
        "movl %eax, %ebx\n" /* token */
        "cmpb $0, (%eax)\n" /* line 693 */
        "jne .Lfac784_000ac7ad\n"
        ".Lfac784_000ac92a:\n"
        "movl 8(%ebp), %eax\n" /* line 695 | this */
        "movl 0x28(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfac784_000ac845\n"
        ".Lfac784_000ac938:\n"
        "movl $1, %eax\n" /* line 732 */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 737 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
#endif /* Original ASM */
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
    byte *self = (byte *)_this;
    TextPool *topPool;

    if (cleanFirst) {
        /* Clean the group */
        GPGroup_Clean((const GPGroup *)self);

        /* Free all text pools */
        {
            byte *pool = *(byte **)(self + 0x30);
            while (pool) {
                byte *next = *(byte **)(pool + 0x04);
                Z_FreeInternal(*(void **)pool);
                Z_FreeInternal(pool);
                pool = next;
            }
            *(void **)(self + 0x30) = NULL;
        }
    }

    /* Ensure a text pool exists */
    if (*(void **)(self + 0x30) == NULL) {
        byte *newPool = (byte *)Z_MallocInternal(0x10);
        *(void **)(newPool + 0x04) = NULL;
        *(int *)(newPool + 0x08) = 0x2800;
        *(int *)(newPool + 0x0c) = 0;
        *(void **)newPool = Z_MallocInternal(0x2800);
        *(void **)(self + 0x30) = newPool;
    }

    /* Set writeable flags */
    *(byte *)(self + 0x34) = (byte)writeable;
    *(byte *)(self + 0x2c) = (byte)writeable;

    /* Parse using the top pool */
    topPool = *(TextPool **)(self + 0x30);
    return (Bool)GPGroup_Parse((const GPGroup *)self, dataPtr, &topPool);

#if 0 /* Original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 831 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movzbl 0x14(%ebp), %eax\n" /* writeable, dataPtr */
        "movb %al, -0x29(%ebp)\n" /* dataPtr, writeable */
        /* { scope 1 */
        "cmpb $0, 0x10(%ebp)\n" /* line 835 | cleanFirst */
        "jne .Lfac948_000ac9cf\n"
        ".Lfac948_000ac961:\n"
        "movl 0x30(%edi), %eax\n" /* line 840 | this */
        "testl %eax, %eax\n"
        "je .Lfac948_000ac999\n"
        ".Lfac948_000ac968:\n"
        "movzbl -0x29(%ebp), %eax\n" /* line 32 | writeable */
        "movb %al, 0x34(%edi)\n" /* line 149 */
        "movb %al, 0x2c(%edi)\n" /* line 120 */
        "movl 0x30(%edi), %eax\n" /* line 847 | this */
        "movl %eax, -0x1c(%ebp)\n" /* topPool */
        "leal -0x1c(%ebp), %eax\n" /* line 848 | topPool */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* dataPtr */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* this */
        "calll GPGroup_Parse\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 849 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfac948_000ac999:\n"
        "movl $0x10, (%esp)\n" /* line 31 */
        "calll Z_MallocInternal\n"
        "movl %eax, %esi\n"
        /* { scope 2 */
        "movl $0, 4(%eax)\n" /* line 181 */
        "movl $0x2800, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0x2800, (%esp)\n" /* line 184 */
        "calll Z_MallocInternal\n"
        "movl %eax, (%esi)\n"
        /* } scope */
        "movl %esi, 0x30(%edi)\n" /* line 842 | this */
        "jmp .Lfac948_000ac968\n"
        ".Lfac948_000ac9cf:\n"
        "movl %edi, (%esp)\n" /* line 854 | this */
        "calll GPGroup_Clean\n"
        "movl 0x30(%edi), %ebx\n" /* line 856 | this */
        "testl %ebx, %ebx\n" /* line 230 */
        "jne .Lfac948_000ac9ec\n"
        "movl $0, 0x30(%edi)\n" /* line 857 | this */
        "jmp .Lfac948_000ac961\n"
        ".Lfac948_000ac9ea:\n"
        "movl %esi, %ebx\n" /* line 230 */
        ".Lfac948_000ac9ec:\n"
        "movl 4(%ebx), %esi\n" /* line 22 */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 194 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 32 */
        "calll Z_FreeInternal\n"
        "testl %esi, %esi\n" /* line 230 */
        "jne .Lfac948_000ac9ea\n"
        "movl $0, 0x30(%edi)\n" /* line 857 | this */
        "jmp .Lfac948_000ac961\n"
        "movl %eax, %ebx\n" /* this */
        "movl %esi, (%esp)\n" /* line 32 */
        "calll Z_FreeInternal\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
#endif /* Original ASM */
}
