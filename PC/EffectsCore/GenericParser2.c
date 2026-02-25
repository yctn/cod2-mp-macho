/* ASM dump from: GenericParser2.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/GenericParser2.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/GenericParser2.h"
 */

static char token[1024]; /* 0x4ed380 */

static char * GetToken(Bool readUntilEOL);
const char * GPValue_GetTopValue(const GPValue * _this);
Bool GPValue_IsList(const GPValue * _this);
my_upsampler GPGroup_SortObject(const GPGroup * _this, GPObject *object, GPObject * *unsortedList, GPObject * *sortedList, GPObject * *lastObject);
my_upsampler GPGroup_Clean(const GPGroup * _this);
my_upsampler GenericParser2_GenericParser2(const GenericParser2 * _this);
char * TextPool_AllocText(const TextPool * _this, char *text, int addNULL, TextPool * *poolPtr);
GPGroup * GPGroup_AddGroup(const GPGroup * _this, const char *name, TextPool * *textPool);
my_upsampler GPValue_AddValue(const GPValue * _this, const char *newValue, TextPool * *textPool);
GPValue * GPGroup_AddPair(const GPGroup * _this, const char *name, const char *value, TextPool * *textPool);
void ZN14GenericParser2D2Ev(void); /* GenericParser2_~GenericParser2 */
void ZN14GenericParser2D1Ev(void); /* GenericParser2_~GenericParser2 */
Bool GPGroup_Parse(const GPGroup * _this, char * *dataPtr, TextPool * *textPool);
Bool GenericParser2_Parse(const GenericParser2 * _this, char * *dataPtr, int cleanFirst, int writeable);

/* line 30 */
static __attribute__((naked))
char * GetToken(Bool readUntilEOL)
{
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
        "leal 0x4ed37f(%esi), %eax\n" /* length */
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
        "movl $0x4ed381, 4(%esp)\n"
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
}

/* line 335 */
__attribute__((naked))
const char * GPValue_GetTopValue(const GPValue * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 335 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 337 | this */
        "movl 0x10(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfac1a2_000ac1b1\n"
        "movl (%eax), %eax\n" /* line 49 */
        ".Lfac1a2_000ac1b1:\n"
        "popl %ebp\n" /* line 343 */
        "retl\n"
    );
}

/* line 324 */
__attribute__((naked))
Bool GPValue_IsList(const GPValue * _this)
{
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
}

/* line 568 */
__attribute__((naked))
my_upsampler GPGroup_SortObject(const GPGroup * _this, GPObject *object, GPObject * *unsortedList, GPObject * *sortedList, GPObject * *lastObject)
{
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
}

/* line 505 */
__attribute__((naked))
my_upsampler GPGroup_Clean(const GPGroup * _this)
{
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
}

/* line 818 */
__attribute__((naked))
my_upsampler GenericParser2_GenericParser2(const GenericParser2 * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 818 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x21e4f8, (%eax)\n" /* line 243 */
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
}

/* line 201 */
__attribute__((naked))
char * TextPool_AllocText(const TextPool * _this, char *text, int addNULL, TextPool * *poolPtr)
{
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
}

/* line 641 */
__attribute__((naked))
GPGroup * GPGroup_AddGroup(const GPGroup * _this, const char *name, TextPool * *textPool)
{
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
}

/* line 346 */
__attribute__((naked))
my_upsampler GPValue_AddValue(const GPValue * _this, const char *newValue, TextPool * *textPool)
{
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
}

/* line 613 */
__attribute__((naked))
GPValue * GPGroup_AddPair(const GPGroup * _this, const char *name, const char *value, TextPool * *textPool)
{
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
}

/* line 825 */
__attribute__((naked))
void ZN14GenericParser2D2Ev(void) /* GenericParser2_~GenericParser2 */
{
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
}

/* line 825 */
__attribute__((naked))
void ZN14GenericParser2D1Ev(void) /* GenericParser2_~GenericParser2 */
{
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
}

/* line 682 */
__attribute__((naked))
Bool GPGroup_Parse(const GPGroup * _this, char * *dataPtr, TextPool * *textPool)
{
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
        "movl $0x21e508, 4(%esp)\n" /* line 704 */
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
        "movl $0x21e50c, 4(%esp)\n" /* line 713 */
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
        "movl $0x21e510, 4(%esp)\n" /* line 722 */
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
        "movl $0x21e504, 4(%esp)\n" /* line 379 */
        "movl %eax, (%esp)\n"
        "calll strcmpi\n"
        "testl %eax, %eax\n"
        "je .Lfac784_000ac793\n"
        "movl %edi, 0xc(%esp)\n" /* line 384 */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* token */
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
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
}

/* line 831 */
__attribute__((naked))
Bool GenericParser2_Parse(const GenericParser2 * _this, char * *dataPtr, int cleanFirst, int writeable)
{
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
}

