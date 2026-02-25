/* ASM dump from: q_shared.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/q_shared.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 */

extern vec4_t colorBlack; /* 0x0 */
extern vec4_t colorRed; /* 0x0 */
extern vec4_t colorGreen; /* 0x0 */
extern vec4_t colorBlue; /* 0x0 */
extern vec4_t colorYellow; /* 0x0 */
extern vec4_t colorLtYellow; /* 0x0 */
extern vec4_t colorMagenta; /* 0x0 */
extern vec4_t colorCyan; /* 0x0 */
extern vec4_t colorLtCyan; /* 0x0 */
extern vec4_t colorMdCyan; /* 0x0 */
extern vec4_t colorWhite; /* 0x0 */
extern vec4_t colorLtGrey; /* 0x0 */
extern TraceThreadInfo g_traceThreadInfo[1]; /* 0x0 */
static int valueindex; /* 0x3397f8 */
static va_info_t va_info[1]; /* 0x338fe0 */
static jmp_buf g_com_error[1]; /* 0x338f80 */
static char value1[2][8192]; /* 0x334f80 */
static short int (*LittleShort)(); /* 0x3397f4 */
static int (*LittleLong)(); /* 0x3397f0 */
static long long unsigned int (*LittleLong64)(); /* 0x3397ec */
static float (*LittleFloatRead)(); /* 0x3397e8 */
static int (*LittleFloatWrite)(); /* 0x3397e4 */

unsigned char ColorIndex(int c);
char * Com_SkipPath(char *pathname);
const char * Com_GetExtensionSubString(const char *filename);
short int ShortSwap(int l);
short int ShortNoSwap(int l);
int LongSwap(int l);
int LongNoSwap(int l);
long long unsigned int Long64Swap(long long unsigned int l);
long long unsigned int Long64NoSwap(long long unsigned int ll);
float FloatReadSwap(int n);
float FloatReadNoSwap(int n);
int FloatWriteSwap(float f);
int FloatWriteNoSwap(float f);
Bool I_islower(int c);
Bool I_isupper(int c);
Bool I_isdigit(int c);
JCOEF I_strncpyz(char *dest, const char *src, int destsize);
int I_strncmp(const char *s0, const char *s1, int n);
int I_DrawStrlen(const char *str);
char * I_CleanStr(char *string);
char I_CleanChar(int character);
int Com_sprintf(char *dest, int size, const char *fmt);
char * va(const char *format);
JCOEF Com_InitThreadData(int threadContext);
JCOEF Info_NextPair(const char * *head, char *key, char *value);
JCOEF Info_RemoveKey(char *s, const char *key);
JCOEF Info_RemoveKey_Big(char *s, const char *key);
qboolean Info_Validate(const char *s);
JCOEF Info_SetValueForKey(char *s, const char *key, const char *value);
JCOEF Info_SetValueForKey_Big(char *s, const char *key, const char *value);
float GetLeanFraction(const float fFrac);
float UnGetLeanFraction(const float fFrac);
JCOEF OrientationPosToWorldPos(const orientation_t *or_, const vec_t *pos, orientation_t (*out)[16]);
JCOEF OrientationDirToWorldDir(const orientation_t *or_, const vec_t *dir, orientation_t (*out)[16]);
JCOEF OrientationPosFromWorldPos(const orientation_t *or_, const vec_t *pos, orientation_t (*out)[16]);
JCOEF OrientationDirFromWorldDir(const orientation_t *or_, const vec_t *dir, orientation_t (*out)[16]);
int I_strnicmp(const char *s0, const char *s1, int n);
char * I_strupr(char *s);
char * I_strlwr(char *s);
JCOEF AddLeanToPosition(orientation_t (*position)[16], const float fViewYaw, const float fLeanFrac, const float fViewRoll, const float fLeanDist);
JCOEF Swap_Init(void);
int I_strcmp(const char *s0, const char *s1);
JCOEF Com_StripExtension(const char *in, char *out);
Bool I_isforfilename(int c);
char * Info_ValueForKey(const char *s, const char *key);
int I_stricmp(const char *s0, const char *s1);
JCOEF Com_DefaultExtension(char *path, int maxSize, const char *extension);
JCOEF I_strncat(char *dest, int size, const char *src);
qboolean ParseConfigStringToStruct(byte *pStruct, const cspField_t *pFieldList, const int iNumFields, const char *pszBuffer, const int iMaxFieldTypes, qboolean (*parseSpecialFieldType)(), JCOEF (*parseStrcpy)());

/* line 103 */
__attribute__((naked))
unsigned char ColorIndex(int c)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 103 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movzbl 8(%ebp), %eax\n" /* line 107 | c */
        "subb $0x30, %al\n"
        "cmpb $9, %al\n" /* line 108 */
        "ja .Lf28d68_00028d7a\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 109 */
        "retl\n"
        /* { scope 1 */
        ".Lf28d68_00028d7a:\n"
        "movl $7, %eax\n" /* line 108 */
        /* } scope */
        "popl %ebp\n" /* line 109 */
        "retl\n"
    );
}

/* line 117 */
__attribute__((naked))
char * Com_SkipPath(char *pathname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* pathname */
        /* { scope 1 */
        "movzbl (%eax), %edx\n" /* line 122 */
        "testb %dl, %dl\n"
        "je .Lf28d82_00028db2\n"
        "movl %eax, %ecx\n"
        "jmp .Lf28d82_00028d9d\n"
        ".Lf28d82_00028d93:\n"
        "addl $1, %eax\n" /* line 124 */
        "movzbl (%eax), %edx\n" /* line 122 */
        "testb %dl, %dl\n"
        "je .Lf28d82_00028dae\n"
        ".Lf28d82_00028d9d:\n"
        "cmpb $0x2f, %dl\n" /* line 124 */
        "jne .Lf28d82_00028d93\n"
        "leal 1(%eax), %ecx\n" /* line 125 */
        "movl %ecx, %eax\n"
        "movzbl (%eax), %edx\n" /* line 122 */
        "testb %dl, %dl\n"
        "jne .Lf28d82_00028d9d\n"
        /* } scope */
        ".Lf28d82_00028dae:\n"
        "movl %ecx, %eax\n" /* line 129 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf28d82_00028db2:\n"
        "movl %eax, %ecx\n" /* line 122 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 129 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 166 */
__attribute__((naked))
const char * Com_GetExtensionSubString(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* filename */
        /* { scope 1 */
        "movzbl (%eax), %edx\n" /* line 173 */
        "testb %dl, %dl\n"
        "je .Lf28db8_00028dfa\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf28db8_00028ddd\n"
        ".Lf28db8_00028dc9:\n"
        "cmpb $0x2f, %dl\n" /* line 177 */
        "je .Lf28db8_00028df6\n"
        "cmpb $0x5c, %dl\n"
        "je .Lf28db8_00028df6\n"
        ".Lf28db8_00028dd3:\n"
        "addl $1, %eax\n" /* line 179 */
        "movzbl (%eax), %edx\n" /* line 173 */
        "testb %dl, %dl\n"
        "je .Lf28db8_00028dee\n"
        ".Lf28db8_00028ddd:\n"
        "cmpb $0x2e, %dl\n" /* line 175 */
        "jne .Lf28db8_00028dc9\n"
        "movl %eax, %ecx\n"
        "addl $1, %eax\n" /* line 179 */
        "movzbl (%eax), %edx\n" /* line 173 */
        "testb %dl, %dl\n"
        "jne .Lf28db8_00028ddd\n"
        ".Lf28db8_00028dee:\n"
        "testl %ecx, %ecx\n" /* line 181 */
        "je .Lf28db8_00028dfa\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 184 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf28db8_00028df6:\n"
        "xorl %ecx, %ecx\n" /* line 177 */
        "jmp .Lf28db8_00028dd3\n"
        ".Lf28db8_00028dfa:\n"
        "movl %eax, %ecx\n" /* line 181 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 184 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 340 */
__attribute__((naked))
short int ShortSwap(int l)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 340 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* l */
        "rolw $8, %ax\n" /* l */
        "cwtl\n"
        "popl %ebp\n" /* line 348 */
        "retl\n"
    );
}

/* line 351 */
__attribute__((naked))
short int ShortNoSwap(int l)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 351 */
        "movl %esp, %ebp\n"
        "movswl 8(%ebp), %eax\n" /* l */
        "popl %ebp\n" /* line 354 */
        "retl\n"
    );
}

/* line 357 */
__attribute__((naked))
int LongSwap(int l)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 357 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* l */
        "movl %ecx, %eax\n" /* l */
        "shll $0x18, %eax\n"
        "movzbl %ch, %edx\n" /* l */
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "shrl $8, %ecx\n" /* l */
        "movl %ecx, %edx\n" /* l */
        "andl $0xff00, %edx\n"
        "addl %edx, %eax\n"
        "shrl $0x10, %ecx\n" /* l */
        "addl %ecx, %eax\n" /* l */
        "popl %ebp\n" /* line 367 */
        "retl\n"
    );
}

/* line 370 */
__attribute__((naked))
int LongNoSwap(int l)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 370 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* l */
        "popl %ebp\n" /* line 373 */
        "retl\n"
    );
}

/* line 376 */
__attribute__((naked))
long long unsigned int Long64Swap(long long unsigned int l)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 376 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* l */
        "movl 0xc(%ebp), %edi\n"
        "movl %esi, %ecx\n" /* l */
        "movzbl %cl, %eax\n"
        "movl %eax, %edx\n"
        "movl $0, %eax\n"
        "shll $0x18, %edx\n"
        "movl %esi, %ecx\n" /* l */
        "movl %edi, %ebx\n"
        "shrdl $8, %ebx, %ecx\n"
        "shrl $8, %ebx\n"
        "movl %ecx, -0x14(%ebp)\n"
        "movl %ebx, -0x10(%ebp)\n"
        "movzbl -0x14(%ebp), %ecx\n"
        "movl %ecx, %ebx\n"
        "movl $0, %ecx\n"
        "shll $0x10, %ebx\n"
        "addl %ecx, %eax\n"
        "adcl %ebx, %edx\n"
        "movl %esi, %ecx\n" /* l */
        "movl %edi, %ebx\n"
        "shrdl $0x10, %ebx, %ecx\n"
        "shrl $0x10, %ebx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ebx, -0x18(%ebp)\n"
        "movzbl -0x1c(%ebp), %ecx\n"
        "movl %ecx, %ebx\n"
        "movl $0, %ecx\n"
        "shll $8, %ebx\n"
        "addl %ecx, %eax\n"
        "adcl %ebx, %edx\n"
        "movl %esi, %ecx\n" /* l */
        "movl %edi, %ebx\n"
        "shrdl $0x18, %edi, %ecx\n"
        "shrl $0x18, %ebx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl %ebx, -0x20(%ebp)\n"
        "movzbl -0x24(%ebp), %ecx\n"
        "movl %ecx, %ebx\n"
        "movl $0, %ecx\n"
        "addl %ecx, %eax\n"
        "adcl %ebx, %edx\n"
        "movl %edi, %ebx\n"
        "movzbl %bl, %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl -0x28(%ebp), %ebx\n"
        "shldl $0x18, %ecx, %ebx\n"
        "shll $0x18, %ecx\n"
        "addl %ecx, %eax\n"
        "adcl %ebx, %edx\n"
        "movl %edi, %esi\n" /* l */
        "xorl %edi, %edi\n"
        "shrl $8, %esi\n" /* l */
        "movl %esi, %ebx\n" /* l */
        "movzbl %bl, %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl -0x28(%ebp), %ebx\n"
        "shldl $0x10, %ecx, %ebx\n"
        "shll $0x10, %ecx\n"
        "addl %ecx, %eax\n"
        "adcl %ebx, %edx\n"
        "shrdl $8, %edi, %esi\n" /* l */
        "shrl $8, %edi\n"
        "movl %esi, %ebx\n" /* l */
        "movzbl %bl, %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl -0x28(%ebp), %ebx\n"
        "shldl $8, %ecx, %ebx\n"
        "shll $8, %ecx\n"
        "addl %ecx, %eax\n"
        "adcl %ebx, %edx\n"
        "shrdl $8, %edi, %esi\n" /* l */
        "movl %esi, %ebx\n" /* l */
        "movzbl %bl, %esi\n" /* l */
        "movl %esi, -0x2c(%ebp)\n" /* l */
        "movl $0, -0x28(%ebp)\n"
        "addl -0x2c(%ebp), %eax\n"
        "adcl -0x28(%ebp), %edx\n"
        "addl $0x20, %esp\n" /* line 390 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 393 */
__attribute__((naked))
long long unsigned int Long64NoSwap(long long unsigned int ll)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 393 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* ll */
        "movl 0xc(%ebp), %edx\n"
        "popl %ebp\n" /* line 396 */
        "retl\n"
    );
}

/* line 399 */
__attribute__((naked))
float FloatReadSwap(int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 399 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %ecx\n" /* n */
        /* { scope 1 */
        "movl %ecx, %edx\n" /* line 409 */
        "shrl $0x18, %edx\n"
        "movb %dl, %al\n"
        "movl %ecx, %edx\n" /* line 410 */
        "shrl $0x10, %edx\n"
        "movb %dl, %ah\n"
        "movzbl %ch, %edx\n" /* line 411 */
        "shll $0x10, %edx\n"
        "andl $0xff00ffff, %eax\n"
        "orl %edx, %eax\n"
        "shll $0x18, %ecx\n" /* line 412 */
        "andl $0xffffff, %eax\n"
        "orl %ecx, %eax\n"
        "movl %eax, -4(%ebp)\n"
        "flds -4(%ebp)\n"
        /* } scope */
        "leave\n" /* line 414 */
        "retl\n"
    );
}

/* line 417 */
__attribute__((naked))
float FloatReadNoSwap(int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 417 */
        "movl %esp, %ebp\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* n */
        "movl %eax, -4(%ebp)\n" /* n, i */
        /* { scope 1 */
        "flds -4(%ebp)\n" /* line 341 | i */
        /* } scope */
        "leave\n" /* line 420 */
        "retl\n"
    );
}

/* line 423 */
__attribute__((naked))
int FloatWriteSwap(float f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 423 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        /* { scope 1 */
        "movl 8(%ebp), %ecx\n" /* line 432 | f */
        "movl %ecx, %edx\n" /* line 433 */
        "shrl $0x18, %edx\n"
        "movb %dl, %al\n"
        "movl %ecx, %edx\n" /* line 434 */
        "shrl $0x10, %edx\n"
        "movb %dl, %ah\n"
        "movzbl %ch, %edx\n" /* line 435 */
        "shll $0x10, %edx\n"
        "andl $0xff00ffff, %eax\n"
        "orl %edx, %eax\n"
        "shll $0x18, %ecx\n" /* line 436 */
        "andl $0xffffff, %eax\n"
        "orl %ecx, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 438 */
        "retl\n"
    );
}

/* line 441 */
__attribute__((naked))
int FloatWriteNoSwap(float f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 441 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 336 | f */
        "popl %ebp\n" /* line 444 */
        "retl\n"
    );
}

/* line 502 */
__attribute__((naked))
Bool I_islower(int c)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 502 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* c */
        "subl $0x61, %eax\n"
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "popl %ebp\n" /* line 505 */
        "retl\n"
    );
}

/* line 508 */
__attribute__((naked))
Bool I_isupper(int c)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 508 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* c */
        "subl $0x41, %eax\n"
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "popl %ebp\n" /* line 511 */
        "retl\n"
    );
}

/* line 520 */
__attribute__((naked))
Bool I_isdigit(int c)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 520 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* c */
        "subl $0x30, %eax\n"
        "cmpl $9, %eax\n"
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "popl %ebp\n" /* line 523 */
        "retl\n"
    );
}

/* line 548 */
__attribute__((naked))
JCOEF I_strncpyz(char *dest, const char *src, int destsize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 548 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* dest */
        "movl 0x10(%ebp), %ebx\n" /* destsize */
        "leal -1(%ebx), %eax\n" /* line 554 | destsize */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* src */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* dest */
        "calll strncpy\n"
        "movb $0, -1(%esi, %ebx)\n" /* line 555 | dest */
        "addl $0x10, %esp\n" /* line 556 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 587 */
__attribute__((naked))
int I_strncmp(const char *s0, const char *s1, int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 587 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* s0 */
        "movl 0xc(%ebp), %eax\n" /* s1 */
        "xorl %edi, %edi\n"
        /* { scope 1 */
        ".Lf2905a_00029068:\n"
        "movzbl (%edx), %ebx\n" /* line 593 */
        "movsbl %bl, %esi\n" /* c0 */
        "addl $1, %edx\n"
        "movsbl (%eax), %ecx\n" /* line 594 */
        "addl $1, %eax\n"
        "cmpl 0x10(%ebp), %edi\n" /* line 596 | n */
        "je .Lf2905a_00029087\n"
        "cmpl %ecx, %esi\n" /* line 599 | c0 */
        "jne .Lf2905a_0002908e\n"
        "addl $1, %edi\n" /* line 600 */
        "testb %bl, %bl\n" /* line 591 */
        "jne .Lf2905a_00029068\n"
        ".Lf2905a_00029087:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 604 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2905a_0002908e:\n"
        "xorl %eax, %eax\n" /* line 600 */
        "cmpl %esi, %ecx\n" /* c0 */
        "setle %al\n"
        "leal -1(%eax, %eax), %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 604 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 707 */
__attribute__((naked))
int I_DrawStrlen(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 707 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* str */
        "xorl %ebx, %ebx\n"
        /* { scope 1 */
        ".Lf2909e_000290a7:\n"
        "movzbl (%ecx), %edx\n" /* line 712 */
        "testb %dl, %dl\n"
        "je .Lf2909e_000290c2\n"
        ".Lf2909e_000290ae:\n"
        "cmpb $0x5e, %dl\n" /* line 714 */
        "je .Lf2909e_000290c7\n"
        "leal 1(%ecx), %eax\n"
        ".Lf2909e_000290b6:\n"
        "addl $1, %ebx\n" /* line 720 | count */
        "movl %eax, %ecx\n"
        "movzbl (%ecx), %edx\n" /* line 712 */
        "testb %dl, %dl\n"
        "jne .Lf2909e_000290ae\n"
        /* } scope */
        ".Lf2909e_000290c2:\n"
        "movl %ebx, %eax\n" /* line 726 | count */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2909e_000290c7:\n"
        "leal 1(%ecx), %eax\n" /* line 714 */
        "movzbl 1(%ecx), %edx\n"
        "testb %dl, %dl\n"
        "je .Lf2909e_000290b6\n"
        "cmpb $0x5e, %dl\n"
        "je .Lf2909e_000290b6\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf2909e_000290b6\n"
        "cmpb $0x39, %dl\n"
        "jg .Lf2909e_000290b6\n"
        "addl $2, %ecx\n" /* line 716 */
        "jmp .Lf2909e_000290a7\n"
    );
}

/* line 730 */
__attribute__((naked))
char * I_CleanStr(char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 730 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* string */
        /* { scope 1 */
        "movzbl (%edi), %edx\n" /* line 738 | string */
        "testb %dl, %dl\n"
        "je .Lf290e6_00029147\n"
        "movl %edi, %eax\n" /* string */
        "movl %edi, %esi\n" /* string, d */
        "jmp .Lf290e6_00029114\n"
        ".Lf290e6_000290fc:\n"
        "leal 1(%eax), %ecx\n" /* line 740 */
        ".Lf290e6_000290ff:\n"
        "leal -0x20(%edx), %eax\n" /* line 744 */
        "cmpb $0x5e, %al\n"
        "ja .Lf290e6_0002910b\n"
        "movb %dl, (%esi)\n" /* line 746 | d */
        "addl $1, %esi\n" /* d */
        ".Lf290e6_0002910b:\n"
        "movzbl (%ecx), %edx\n" /* line 738 */
        "testb %dl, %dl\n"
        "je .Lf290e6_0002913d\n"
        ".Lf290e6_00029112:\n"
        "movl %ecx, %eax\n"
        ".Lf290e6_00029114:\n"
        "cmpb $0x5e, %dl\n" /* line 740 */
        "jne .Lf290e6_000290fc\n"
        "leal 1(%eax), %ecx\n"
        "movzbl 1(%eax), %ebx\n"
        "testb %bl, %bl\n"
        "je .Lf290e6_000290ff\n"
        "cmpb $0x5e, %bl\n"
        "je .Lf290e6_000290ff\n"
        "cmpb $0x2f, %bl\n"
        "jle .Lf290e6_000290ff\n"
        "cmpb $0x39, %bl\n"
        "jg .Lf290e6_000290ff\n"
        "leal 2(%eax), %ecx\n"
        "movzbl (%ecx), %edx\n" /* line 738 */
        "testb %dl, %dl\n"
        "jne .Lf290e6_00029112\n"
        ".Lf290e6_0002913d:\n"
        "movb $0, (%esi)\n" /* line 750 | d */
        /* } scope */
        "movl %edi, %eax\n" /* line 753 | string */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf290e6_00029147:\n"
        "movl %edi, %esi\n" /* line 738 | string, d */
        "movb $0, (%esi)\n" /* line 750 | d */
        /* } scope */
        "movl %edi, %eax\n" /* line 753 | string */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 757 */
__attribute__((naked))
char I_CleanChar(int character)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 757 */
        "movl %esp, %ebp\n"
        "movzbl 8(%ebp), %eax\n" /* character */
        "cmpb $0x92, %al\n" /* line 761 */
        "je .Lf29154_00029164\n"
        "movsbl %al, %eax\n" /* line 764 */
        "popl %ebp\n" /* line 765 */
        "retl\n"
        ".Lf29154_00029164:\n"
        "movl $0x27, %eax\n" /* line 761 */
        "popl %ebp\n" /* line 765 */
        "retl\n"
    );
}

/* line 769 */
__attribute__((naked))
int Com_sprintf(char *dest, int size, const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 769 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* dest */
        "movl 0xc(%ebp), %ebx\n" /* size */
        /* { scope 1 */
        "leal 0x14(%ebp), %eax\n" /* line 774 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 775 */
        "movl 0x10(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* size */
        "movl %esi, (%esp)\n" /* dest */
        "calll vsnprintf\n"
        "movb $0, -1(%esi, %ebx)\n" /* line 777 | dest */
        /* } scope */
        "addl $0x20, %esp\n" /* line 781 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 819 */
__attribute__((naked))
char * va(const char *format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 819 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "leal 0xc(%ebp), %eax\n" /* line 826 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl $1, (%esp)\n" /* line 827 */
        "calll Sys_GetValue\n"
        "movl %eax, %ecx\n"
        "movl 0x800(%eax), %eax\n" /* line 828 */
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal (%ecx, %edx), %ebx\n" /* buf */
        "addl $1, %eax\n" /* line 829 */
        "andl $0x80000001, %eax\n"
        "js .Lf291a4_00029225\n"
        ".Lf291a4_000291d7:\n"
        "movl %eax, 0x800(%ecx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 830 | argptr */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* format */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* buf */
        "calll vsnprintf\n"
        "movb $0, 0x3ff(%ebx)\n" /* line 831 | buf */
        "cmpl $0x3ff, %eax\n" /* line 834 */
        "jbe .Lf291a4_0002921d\n"
        "movl $0x215d4c, 4(%esp)\n" /* line 835 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf291a4_0002921d:\n"
        "movl %ebx, %eax\n" /* line 838 | buf */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf291a4_00029225:\n"
        "subl $1, %eax\n" /* line 829 */
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf291a4_000291d7\n"
    );
}

/* line 848 */
__attribute__((naked))
JCOEF Com_InitThreadData(int threadContext)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 848 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* threadContext */
        "movl %ebx, %eax\n" /* line 850 | threadContext */
        "shll $0xb, %eax\n"
        "leal va_info(%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Sys_SetValue\n"
        "leal (%ebx, %ebx, 8), %eax\n" /* line 851 | threadContext */
        "leal g_com_error(, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Sys_SetValue\n"
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 852 | threadContext */
        "leal g_traceThreadInfo(, %ebx, 8), %ebx\n" /* threadContext */
        "movl %ebx, 4(%esp)\n" /* threadContext */
        "movl $3, (%esp)\n"
        "calll Sys_SetValue\n"
        "addl $0x14, %esp\n" /* line 853 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1005 */
__attribute__((naked))
JCOEF Info_NextPair(const char * *head, char *key, char *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1005 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* head */
        "movl 0xc(%ebp), %edx\n" /* key */
        "movl 0x10(%ebp), %esi\n" /* value */
        /* { scope 1 */
        "movl (%edi), %ecx\n" /* line 1010 | head */
        "leal 1(%ecx), %eax\n" /* line 1014 */
        "cmpb $0x5c, (%ecx)\n"
        "cmovel %eax, %ecx\n"
        "movb $0, (%edx)\n" /* line 1016 */
        "movb $0, (%esi)\n" /* line 1017 | value */
        "movzbl (%ecx), %eax\n" /* line 1020 */
        "cmpb $0x5c, %al\n"
        "je .Lf29290_000292ca\n"
        ".Lf29290_000292b7:\n"
        "testb %al, %al\n" /* line 1022 */
        "je .Lf29290_000292fb\n"
        "movb %al, (%edx)\n" /* line 1028 */
        "addl $1, %edx\n"
        "addl $1, %ecx\n"
        "movzbl (%ecx), %eax\n" /* line 1020 */
        "cmpb $0x5c, %al\n"
        "jne .Lf29290_000292b7\n"
        ".Lf29290_000292ca:\n"
        "movb $0, (%edx)\n" /* line 1030 */
        "leal 1(%ecx), %ebx\n" /* line 1031 | s */
        "movzbl 1(%ecx), %eax\n" /* line 1034 */
        "cmpb $0x5c, %al\n"
        "je .Lf29290_00029305\n"
        "testb %al, %al\n"
        "je .Lf29290_00029305\n"
        "movl %esi, %edx\n" /* value */
        ".Lf29290_000292de:\n"
        "movb %al, (%edx)\n" /* line 1036 */
        "addl $1, %edx\n"
        "addl $1, %ebx\n" /* s */
        "movzbl (%ebx), %eax\n" /* line 1034 | s */
        "cmpb $0x5c, %al\n"
        "je .Lf29290_000292f1\n"
        "testb %al, %al\n"
        "jne .Lf29290_000292de\n"
        ".Lf29290_000292f1:\n"
        "movb $0, (%edx)\n" /* line 1038 */
        "movl %ebx, (%edi)\n" /* line 1040 | s, head */
        /* } scope */
        ".Lf29290_000292f6:\n"
        "popl %ebx\n" /* line 1041 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29290_000292fb:\n"
        "movb $0, (%edx)\n" /* line 1024 */
        "movl %ecx, (%edi)\n" /* line 1025 | head */
        /* } scope */
        "popl %ebx\n" /* line 1041 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29290_00029305:\n"
        "movl %esi, %edx\n" /* line 1034 | value */
        "movb $0, (%edx)\n" /* line 1038 */
        "movl %ebx, (%edi)\n" /* line 1040 | s, head */
        "jmp .Lf29290_000292f6\n"
    );
}

/* line 1049 */
__attribute__((naked))
JCOEF Info_RemoveKey(char *s, const char *key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1049 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x81c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        /* { scope 1 */
        "cld\n" /* line 1056 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3ff, %ecx\n"
        "ja .Lf2930e_000293d1\n"
        ".Lf2930e_0002933a:\n"
        "movl $0x5c, 4(%esp)\n" /* line 1061 */
        "movl 0xc(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2930e_000293a4\n"
        /* } scope */
        ".Lf2930e_00029351:\n"
        "addl $0x81c, %esp\n" /* line 1099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2930e_0002935c:\n"
        "leal 1(%ebx), %edx\n" /* line 1070 | s */
        "movzbl 1(%ebx), %eax\n" /* line 1072 | s */
        "cmpb $0x5c, %al\n"
        "jne .Lf2930e_000293ae\n"
        "leal -0x418(%ebp), %esi\n" /* pkey */
        "movl %esi, %ecx\n"
        ".Lf2930e_0002936f:\n"
        "movb $0, (%ecx)\n" /* line 1078 */
        "leal 1(%edx), %edi\n" /* line 1079 */
        "movzbl 1(%edx), %eax\n" /* line 1082 */
        "cmpb $0x5c, %al\n"
        "je .Lf2930e_00029381\n"
        "testb %al, %al\n"
        "jne .Lf2930e_000293ea\n"
        ".Lf2930e_00029381:\n"
        "leal -0x818(%ebp), %edx\n" /* value */
        ".Lf2930e_00029387:\n"
        "movb $0, (%edx)\n" /* line 1088 */
        "movl %esi, 4(%esp)\n" /* line 1090 */
        "movl 0xc(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf2930e_00029405\n"
        "cmpb $0, (%edi)\n" /* line 1096 */
        "je .Lf2930e_00029351\n"
        "movl %edi, %ebx\n" /* line 1097 | s */
        ".Lf2930e_000293a4:\n"
        "cmpb $0x5c, (%ebx)\n" /* line 1069 | s */
        "je .Lf2930e_0002935c\n"
        "movzbl (%ebx), %eax\n" /* line 1072 | s */
        "movl %ebx, %edx\n" /* s */
        ".Lf2930e_000293ae:\n"
        "testb %al, %al\n" /* line 1074 */
        "je .Lf2930e_00029351\n"
        "leal -0x418(%ebp), %esi\n" /* line 1075 | pkey */
        "movl %esi, %ecx\n"
        "jmp .Lf2930e_000293c0\n"
        ".Lf2930e_000293bc:\n"
        "testb %al, %al\n" /* line 1074 */
        "je .Lf2930e_00029351\n"
        ".Lf2930e_000293c0:\n"
        "movb %al, (%ecx)\n" /* line 1076 */
        "addl $1, %ecx\n"
        "addl $1, %edx\n"
        "movzbl (%edx), %eax\n" /* line 1072 */
        "cmpb $0x5c, %al\n"
        "jne .Lf2930e_000293bc\n"
        "jmp .Lf2930e_0002936f\n"
        ".Lf2930e_000293d1:\n"
        "movl $0x215d7c, 4(%esp)\n" /* line 1058 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2930e_0002933a\n"
        ".Lf2930e_000293ea:\n"
        "leal -0x818(%ebp), %edx\n" /* line 1082 | value */
        ".Lf2930e_000293f0:\n"
        "movb %al, (%edx)\n" /* line 1086 */
        "addl $1, %edx\n"
        "addl $1, %edi\n"
        "movzbl (%edi), %eax\n" /* line 1082 */
        "cmpb $0x5c, %al\n"
        "je .Lf2930e_00029387\n"
        "testb %al, %al\n"
        "jne .Lf2930e_000293f0\n"
        "jmp .Lf2930e_00029387\n"
        ".Lf2930e_00029405:\n"
        "movl %edi, 4(%esp)\n" /* line 1092 */
        "movl %ebx, (%esp)\n" /* s */
        "calll strcpy\n"
        "jmp .Lf2930e_00029351\n"
    );
}

/* line 1107 */
__attribute__((naked))
JCOEF Info_RemoveKey_Big(char *s, const char *key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1107 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x401c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        /* { scope 1 */
        "cld\n" /* line 1114 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x1fff, %ecx\n"
        "ja .Lf29416_000294d9\n"
        ".Lf29416_00029442:\n"
        "movl $0x5c, 4(%esp)\n" /* line 1119 */
        "movl 0xc(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf29416_000294ac\n"
        /* } scope */
        ".Lf29416_00029459:\n"
        "addl $0x401c, %esp\n" /* line 1157 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29416_00029464:\n"
        "leal 1(%ebx), %edx\n" /* line 1128 | s */
        "movzbl 1(%ebx), %eax\n" /* line 1130 | s */
        "cmpb $0x5c, %al\n"
        "jne .Lf29416_000294b6\n"
        "leal -0x2018(%ebp), %esi\n" /* pkey */
        "movl %esi, %ecx\n"
        ".Lf29416_00029477:\n"
        "movb $0, (%ecx)\n" /* line 1136 */
        "leal 1(%edx), %edi\n" /* line 1137 */
        "movzbl 1(%edx), %eax\n" /* line 1140 */
        "cmpb $0x5c, %al\n"
        "je .Lf29416_00029489\n"
        "testb %al, %al\n"
        "jne .Lf29416_000294f2\n"
        ".Lf29416_00029489:\n"
        "leal -0x4018(%ebp), %edx\n" /* value */
        ".Lf29416_0002948f:\n"
        "movb $0, (%edx)\n" /* line 1146 */
        "movl %esi, 4(%esp)\n" /* line 1148 */
        "movl 0xc(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf29416_0002950d\n"
        "cmpb $0, (%edi)\n" /* line 1154 */
        "je .Lf29416_00029459\n"
        "movl %edi, %ebx\n" /* line 1155 | s */
        ".Lf29416_000294ac:\n"
        "cmpb $0x5c, (%ebx)\n" /* line 1127 | s */
        "je .Lf29416_00029464\n"
        "movzbl (%ebx), %eax\n" /* line 1130 | s */
        "movl %ebx, %edx\n" /* s */
        ".Lf29416_000294b6:\n"
        "testb %al, %al\n" /* line 1132 */
        "je .Lf29416_00029459\n"
        "leal -0x2018(%ebp), %esi\n" /* line 1133 | pkey */
        "movl %esi, %ecx\n"
        "jmp .Lf29416_000294c8\n"
        ".Lf29416_000294c4:\n"
        "testb %al, %al\n" /* line 1132 */
        "je .Lf29416_00029459\n"
        ".Lf29416_000294c8:\n"
        "movb %al, (%ecx)\n" /* line 1134 */
        "addl $1, %ecx\n"
        "addl $1, %edx\n"
        "movzbl (%edx), %eax\n" /* line 1130 */
        "cmpb $0x5c, %al\n"
        "jne .Lf29416_000294c4\n"
        "jmp .Lf29416_00029477\n"
        ".Lf29416_000294d9:\n"
        "movl $0x215da4, 4(%esp)\n" /* line 1116 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf29416_00029442\n"
        ".Lf29416_000294f2:\n"
        "leal -0x4018(%ebp), %edx\n" /* line 1140 | value */
        ".Lf29416_000294f8:\n"
        "movb %al, (%edx)\n" /* line 1144 */
        "addl $1, %edx\n"
        "addl $1, %edi\n"
        "movzbl (%edi), %eax\n" /* line 1140 */
        "cmpb $0x5c, %al\n"
        "je .Lf29416_0002948f\n"
        "testb %al, %al\n"
        "jne .Lf29416_000294f8\n"
        "jmp .Lf29416_0002948f\n"
        ".Lf29416_0002950d:\n"
        "movl %edi, 4(%esp)\n" /* line 1150 */
        "movl %ebx, (%esp)\n" /* s */
        "calll strcpy\n"
        "jmp .Lf29416_00029459\n"
    );
}

/* line 1168 */
__attribute__((naked))
qboolean Info_Validate(const char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1168 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        "movl $0x22, 4(%esp)\n" /* line 1170 */
        "movl %ebx, (%esp)\n" /* s */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2951e_00029544\n"
        ".Lf2951e_0002953c:\n"
        "xorl %eax, %eax\n" /* line 1174 */
        ".Lf2951e_0002953e:\n"
        "addl $0x14, %esp\n" /* line 1179 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2951e_00029544:\n"
        "movl $0x3b, 4(%esp)\n" /* line 1174 */
        "movl %ebx, (%esp)\n" /* s */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lf2951e_0002953c\n"
        "movb $1, %al\n"
        "jmp .Lf2951e_0002953e\n"
    );
}

/* line 1189 */
__attribute__((naked))
JCOEF Info_SetValueForKey(char *s, const char *key, const char *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* key */
        "movl 0x10(%ebp), %ebx\n" /* value */
        /* { scope 1 */
        "cld\n" /* line 1200 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3ff, %ecx\n"
        "ja .Lf2955c_000295f6\n"
        "xorl %ecx, %ecx\n" /* line 1203 */
        "movl $1, %edx\n"
        "jmp .Lf2955c_000295b2\n"
        ".Lf2955c_00029591:\n"
        "cmpb $0x5c, %al\n" /* line 1212 */
        "je .Lf2955c_000295a7\n"
        "cmpb $0x3b, %al\n"
        "je .Lf2955c_000295a7\n"
        "cmpb $0x22, %al\n"
        "je .Lf2955c_000295a7\n"
        "movb %al, -0x818(%ebp, %ecx)\n" /* line 1215 */
        "addl $1, %ecx\n" /* line 1216 */
        ".Lf2955c_000295a7:\n"
        "addl $1, %edx\n"
        "cmpl $0x400, %edx\n" /* line 1207 */
        "je .Lf2955c_000295bb\n"
        ".Lf2955c_000295b2:\n"
        "movzbl -1(%ebx, %edx), %eax\n" /* line 1209 | value */
        "testb %al, %al\n" /* line 1210 */
        "jne .Lf2955c_00029591\n"
        ".Lf2955c_000295bb:\n"
        "movb $0, -0x818(%ebp, %ecx)\n" /* line 1220 */
        "movl $0x5c, 4(%esp)\n" /* line 1222 */
        "movl %esi, (%esp)\n" /* key */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2955c_0002960d\n"
        "movl %ebx, 8(%esp)\n" /* line 1224 | value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215dfc, (%esp)\n" /* "Can't use keys with a \
key: '%s'
value: '%s'" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf2955c_000295eb:\n"
        "addl $0x83c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2955c_000295f6:\n"
        "movl $0x215dd0, (%esp)\n" /* line 1202 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2955c_0002960d:\n"
        "movl $0x3b, 4(%esp)\n" /* line 1228 */
        "movl %esi, (%esp)\n" /* key */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2955c_00029640\n"
        "movl %ebx, 8(%esp)\n" /* line 1230 | value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215e2c, (%esp)\n" /* "Can't use keys with a semicolon
key: '%s'
value: '%s'" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x83c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2955c_00029640:\n"
        "movl $0x22, 4(%esp)\n" /* line 1234 */
        "movl %esi, (%esp)\n" /* key */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2955c_0002966a\n"
        "movl %ebx, 8(%esp)\n" /* line 1236 | value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215e64, (%esp)\n" /* "Can't use keys with a "
key: '%s'
value: '%s'" */
        "calll Com_Printf\n"
        "jmp .Lf2955c_000295eb\n"
        ".Lf2955c_0002966a:\n"
        "movl %esi, 4(%esp)\n" /* line 1240 | key */
        "movl 8(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll Info_RemoveKey\n"
        "cmpb $0, -0x818(%ebp)\n" /* line 1241 | cleanValue */
        "je .Lf2955c_000295eb\n"
        "leal -0x818(%ebp), %eax\n" /* line 1244 | cleanValue */
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* key */
        "movl $0x215e94, 8(%esp)\n" /* "\%s\%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %ecx\n" /* newi */
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "testl %eax, %eax\n" /* line 1246 */
        "jle .Lf2955c_00029728\n"
        "xorl %edx, %edx\n" /* line 1252 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "leal -0x418(%ebp), %edi\n" /* newi */
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, -0x81c(%ebp)\n"
        "movl $0xffffffff, %ecx\n"
        "movl 8(%ebp), %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x81c(%ebp), %eax\n"
        "leal -2(%ecx, %eax), %ecx\n"
        "cmpl $0x400, %ecx\n"
        "jbe .Lf2955c_0002970e\n"
        "movl 8(%ebp), %ecx\n" /* line 1254 | s */
        "movl %ecx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215ee4, (%esp)\n" /* "Info string length exceeded
key: '%s'
value: '%s'
Info stri" */
        "calll Com_Printf\n"
        "jmp .Lf2955c_000295eb\n"
        ".Lf2955c_0002970e:\n"
        "leal -0x418(%ebp), %eax\n" /* line 1258 | newi */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %ecx, (%esp)\n"
        "calll strcat\n"
        "jmp .Lf2955c_000295eb\n"
        ".Lf2955c_00029728:\n"
        "movl $0x215e9c, (%esp)\n" /* line 1248 */
        "calll Com_Printf\n"
        "jmp .Lf2955c_000295eb\n"
    );
}

/* line 1269 */
__attribute__((naked))
JCOEF Info_SetValueForKey_Big(char *s, const char *key, const char *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1269 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x403c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* key */
        "movl 0x10(%ebp), %ebx\n" /* value */
        /* { scope 1 */
        "cld\n" /* line 1280 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x1fff, %ecx\n"
        "ja .Lf2973a_000297d4\n"
        "xorl %ecx, %ecx\n" /* line 1283 */
        "movl $1, %edx\n"
        "jmp .Lf2973a_00029790\n"
        ".Lf2973a_0002976f:\n"
        "cmpb $0x5c, %al\n" /* line 1292 */
        "je .Lf2973a_00029785\n"
        "cmpb $0x3b, %al\n"
        "je .Lf2973a_00029785\n"
        "cmpb $0x22, %al\n"
        "je .Lf2973a_00029785\n"
        "movb %al, -0x4018(%ebp, %ecx)\n" /* line 1295 */
        "addl $1, %ecx\n" /* line 1296 */
        ".Lf2973a_00029785:\n"
        "addl $1, %edx\n"
        "cmpl $0x2000, %edx\n" /* line 1287 */
        "je .Lf2973a_00029799\n"
        ".Lf2973a_00029790:\n"
        "movzbl -1(%ebx, %edx), %eax\n" /* line 1289 | value */
        "testb %al, %al\n" /* line 1290 */
        "jne .Lf2973a_0002976f\n"
        ".Lf2973a_00029799:\n"
        "movb $0, -0x4018(%ebp, %ecx)\n" /* line 1300 */
        "movl $0x5c, 4(%esp)\n" /* line 1302 */
        "movl %esi, (%esp)\n" /* key */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2973a_000297eb\n"
        "movl %ebx, 8(%esp)\n" /* line 1304 | value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215dfc, (%esp)\n" /* "Can't use keys with a \
key: '%s'
value: '%s'" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf2973a_000297c9:\n"
        "addl $0x403c, %esp\n" /* line 1339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2973a_000297d4:\n"
        "movl $0x215dd0, (%esp)\n" /* line 1282 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x403c, %esp\n" /* line 1339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2973a_000297eb:\n"
        "movl $0x3b, 4(%esp)\n" /* line 1308 */
        "movl %esi, (%esp)\n" /* key */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2973a_0002981e\n"
        "movl %ebx, 8(%esp)\n" /* line 1310 | value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215e2c, (%esp)\n" /* "Can't use keys with a semicolon
key: '%s'
value: '%s'" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x403c, %esp\n" /* line 1339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2973a_0002981e:\n"
        "movl $0x22, 4(%esp)\n" /* line 1314 */
        "movl %esi, (%esp)\n" /* key */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf2973a_00029848\n"
        "movl %ebx, 8(%esp)\n" /* line 1316 | value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215e64, (%esp)\n" /* "Can't use keys with a "
key: '%s'
value: '%s'" */
        "calll Com_Printf\n"
        "jmp .Lf2973a_000297c9\n"
        ".Lf2973a_00029848:\n"
        "movl %esi, 4(%esp)\n" /* line 1320 | key */
        "movl 8(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll Info_RemoveKey_Big\n"
        "cmpb $0, -0x4018(%ebp)\n" /* line 1321 | cleanValue */
        "je .Lf2973a_000297c9\n"
        "leal -0x4018(%ebp), %eax\n" /* line 1324 | cleanValue */
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* key */
        "movl $0x215e94, 8(%esp)\n" /* "\%s\%s" */
        "movl $0x2000, 4(%esp)\n"
        "leal -0x2018(%ebp), %ecx\n" /* newi */
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "testl %eax, %eax\n" /* line 1326 */
        "jle .Lf2973a_00029906\n"
        "xorl %edx, %edx\n" /* line 1332 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "leal -0x2018(%ebp), %edi\n" /* newi */
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, -0x401c(%ebp)\n"
        "movl $0xffffffff, %ecx\n"
        "movl 8(%ebp), %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x401c(%ebp), %eax\n"
        "leal -2(%ecx, %eax), %ecx\n"
        "cmpl $0x400, %ecx\n"
        "jbe .Lf2973a_000298ec\n"
        "movl 8(%ebp), %ecx\n" /* line 1334 | s */
        "movl %ecx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* value */
        "movl %esi, 4(%esp)\n" /* key */
        "movl $0x215ee4, (%esp)\n" /* "Info string length exceeded
key: '%s'
value: '%s'
Info stri" */
        "calll Com_Printf\n"
        "jmp .Lf2973a_000297c9\n"
        ".Lf2973a_000298ec:\n"
        "leal -0x2018(%ebp), %eax\n" /* line 1338 | newi */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %ecx, (%esp)\n"
        "calll strcat\n"
        "jmp .Lf2973a_000297c9\n"
        ".Lf2973a_00029906:\n"
        "movl $0x215e9c, (%esp)\n" /* line 1328 */
        "calll Com_Printf\n"
        "jmp .Lf2973a_000297c9\n"
    );
}

/* line 1436 */
__attribute__((naked))
float GetLeanFraction(const float fFrac)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1436 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* fFrac */
        "movaps %xmm0, %xmm2\n" /* fFrac */
        "andps 0x2efae0, %xmm2\n"
        "movss 0x2ed62c, %xmm1\n" /* 2.0f */
        "subss %xmm2, %xmm1\n"
        "mulss %xmm1, %xmm0\n" /* fFrac */
        "movss %xmm0, -4(%ebp)\n" /* line 1439 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 1449 */
__attribute__((naked))
float UnGetLeanFraction(const float fFrac)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1449 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 81 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 8(%ebp), %xmm1\n" /* fFrac */
        "sqrtss %xmm1, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%ebp)\n" /* line 1455 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 1495 */
__attribute__((naked))
JCOEF OrientationPosToWorldPos(const orientation_t *or_, const vec_t *pos, orientation_t (*out)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1495 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* or_ */
        "movl 0xc(%ebp), %edx\n" /* pos */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "movss (%edx), %xmm1\n" /* line 1498 */
        "mulss 0xc(%eax), %xmm1\n"
        "addss (%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x24(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss (%edx), %xmm1\n" /* line 1499 */
        "mulss 0x10(%eax), %xmm1\n"
        "addss 4(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x1c(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x28(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%edx), %xmm1\n" /* line 1500 */
        "mulss 0x14(%eax), %xmm1\n"
        "addss 8(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x20(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x2c(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "popl %ebp\n" /* line 1501 */
        "retl\n"
    );
}

/* line 1504 */
__attribute__((naked))
JCOEF OrientationDirToWorldDir(const orientation_t *or_, const vec_t *dir, orientation_t (*out)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1504 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* or_ */
        "movl 0xc(%ebp), %eax\n" /* dir */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "movss (%eax), %xmm1\n" /* line 1507 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1508 */
        "mulss 0x10(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x1c(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1509 */
        "mulss 0x14(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2c(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "popl %ebp\n" /* line 1510 */
        "retl\n"
    );
}

/* line 1522 */
__attribute__((naked))
JCOEF OrientationPosFromWorldPos(const orientation_t *or_, const vec_t *pos, orientation_t (*out)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1522 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* or_ */
        "movl 0xc(%ebp), %edx\n" /* pos */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "movss (%edx), %xmm2\n" /* line 1528 */
        "subss (%eax), %xmm2\n"
        "movss 4(%edx), %xmm3\n" /* line 1529 */
        "subss 4(%eax), %xmm3\n"
        "movss 8(%edx), %xmm4\n" /* line 1530 */
        "subss 8(%eax), %xmm4\n"
        "movaps %xmm2, %xmm0\n" /* line 1532 */
        "mulss 0xc(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x10(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x14(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movaps %xmm2, %xmm0\n" /* line 1533 */
        "mulss 0x18(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x1c(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x20(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "mulss 0x24(%eax), %xmm2\n" /* line 1534 */
        "mulss 0x28(%eax), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss 0x2c(%eax), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, 8(%ecx)\n"
        "popl %ebp\n" /* line 1535 */
        "retl\n"
    );
}

/* line 1538 */
__attribute__((naked))
JCOEF OrientationDirFromWorldDir(const orientation_t *or_, const vec_t *dir, orientation_t (*out)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1538 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* or_ */
        "movl 0xc(%ebp), %eax\n" /* dir */
        "movl 0x10(%ebp), %ecx\n" /* out */
        "movss (%eax), %xmm1\n" /* line 1541 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1542 */
        "mulss 0x18(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x1c(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss (%eax), %xmm1\n" /* line 1543 */
        "mulss 0x24(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2c(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "popl %ebp\n" /* line 1544 */
        "retl\n"
    );
}

/* line 560 */
__attribute__((naked))
int I_strnicmp(const char *s0, const char *s1, int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 560 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edi\n" /* s0 */
        "movl 0xc(%ebp), %esi\n" /* s1 */
        "movl $0, -0x10(%ebp)\n"
        /* { scope 1 */
        ".Lf29bb4_00029bca:\n"
        "movsbl (%edi), %ebx\n" /* line 566 | s0, c0 */
        "addl $1, %edi\n" /* s0 */
        "movsbl (%esi), %ecx\n" /* line 567 | s1 */
        "addl $1, %esi\n" /* s1 */
        "movl 0x10(%ebp), %eax\n" /* line 569 | n */
        "cmpl %eax, -0x10(%ebp)\n"
        "je .Lf29bb4_00029c10\n"
        "cmpl %ecx, %ebx\n" /* line 572 | c0 */
        "je .Lf29bb4_00029c08\n"
        "leal -0x61(%ebx), %eax\n" /* line 574 | c0 */
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "leal -0x20(%ebx), %edx\n" /* line 575 | c0 */
        "testb %al, %al\n"
        "cmovnel %edx, %ebx\n" /* c0 */
        "leal -0x61(%ecx), %eax\n" /* line 576 */
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "leal -0x20(%ecx), %edx\n" /* line 577 */
        "testb %al, %al\n"
        "cmovnel %edx, %ecx\n"
        "cmpl %ecx, %ebx\n" /* line 578 | c0 */
        "jne .Lf29bb4_00029c1a\n"
        ".Lf29bb4_00029c08:\n"
        "addl $1, -0x10(%ebp)\n" /* line 579 */
        "testl %ebx, %ebx\n" /* line 564 | c0 */
        "jne .Lf29bb4_00029bca\n"
        ".Lf29bb4_00029c10:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $4, %esp\n" /* line 584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29bb4_00029c1a:\n"
        "xorl %eax, %eax\n" /* line 579 */
        "cmpl %ebx, %ecx\n" /* c0 */
        "setle %al\n"
        "leal -1(%eax, %eax), %eax\n"
        /* } scope */
        "addl $4, %esp\n" /* line 584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 677 */
__attribute__((naked))
char * I_strupr(char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 677 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* s */
        "movzbl (%ebx), %edx\n" /* line 682 | s */
        "testb %dl, %dl\n"
        "je .Lf29c2e_00029c59\n"
        "movl %ebx, %ecx\n" /* s */
        ".Lf29c2e_00029c3e:\n"
        "movsbl %dl, %eax\n" /* line 684 */
        "subl $0x61, %eax\n"
        "cmpl $0x19, %eax\n"
        "ja .Lf29c2e_00029c4e\n"
        "leal -0x20(%edx), %eax\n" /* line 685 */
        "movb %al, (%ecx)\n"
        ".Lf29c2e_00029c4e:\n"
        "movzbl 1(%ecx), %edx\n" /* line 682 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf29c2e_00029c3e\n"
        ".Lf29c2e_00029c59:\n"
        "movl %ebx, %eax\n" /* line 689 | s */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 662 */
__attribute__((naked))
char * I_strlwr(char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 662 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* s */
        "movzbl (%ebx), %edx\n" /* line 667 | s */
        "testb %dl, %dl\n"
        "je .Lf29c60_00029c8b\n"
        "movl %ebx, %ecx\n" /* s */
        ".Lf29c60_00029c70:\n"
        "movsbl %dl, %eax\n" /* line 669 */
        "subl $0x41, %eax\n"
        "cmpl $0x19, %eax\n"
        "ja .Lf29c60_00029c80\n"
        "leal 0x20(%edx), %eax\n" /* line 670 */
        "movb %al, (%ecx)\n"
        ".Lf29c60_00029c80:\n"
        "movzbl 1(%ecx), %edx\n" /* line 667 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf29c60_00029c70\n"
        ".Lf29c60_00029c8b:\n"
        "movl %ebx, %eax\n" /* line 674 | s */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1465 */
__attribute__((naked))
JCOEF AddLeanToPosition(orientation_t (*position)[16], const float fViewYaw, const float fLeanFrac, const float fViewRoll, const float fLeanDist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1465 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %ebx\n" /* position */
        "movss 0x10(%ebp), %xmm3\n" /* fLeanFrac */
        "movss 0x14(%ebp), %xmm2\n" /* fViewRoll */
        "pxor %xmm4, %xmm4\n" /* line 1467 */
        "ucomiss %xmm4, %xmm3\n"
        "jp .Lf29c90_00029cb5\n"
        "jne .Lf29c90_00029cb5\n"
        "addl $0x44, %esp\n" /* line 1480 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29c90_00029cb5:\n"
        "movaps %xmm3, %xmm0\n" /* line 1438 */
        "andps 0x2efaf0, %xmm0\n"
        "movss 0x2ed62c, %xmm1\n" /* 2.0f */
        "subss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm4, -0x20(%ebp)\n" /* line 191 | vAng */
        "movss 0xc(%ebp), %xmm0\n" /* line 192 | fViewYaw */
        "movss %xmm0, -0x1c(%ebp)\n"
        "mulss %xmm1, %xmm2\n" /* line 193 */
        "movss %xmm2, -0x18(%ebp)\n"
        "movl $0, 0xc(%esp)\n" /* line 1476 */
        "leal -0x14(%ebp), %eax\n" /* vRight */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* vAng */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "calll AngleVectors\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 1477 */
        "mulss 0x18(%ebp), %xmm1\n" /* fLeanDist */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x14(%ebp), %xmm0\n" /* vRight */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x10(%ebp), %xmm0\n"
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "mulss -0xc(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%ebx), %xmm1\n"
        "movss %xmm1, 8(%ebx)\n"
        /* } scope */
        "addl $0x44, %esp\n" /* line 1480 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 476 */
__attribute__((naked))
JCOEF Swap_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 476 */
        "movl %esp, %ebp\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movb $1, -2(%ebp)\n" /* line 478 | swaptest */
        "movb $0, -1(%ebp)\n"
        "cmpw $1, -2(%ebp)\n" /* line 481 | swaptest */
        "je .Lf29d52_00029d9b\n"
        "movl $0x28e02, LittleShort\n" /* line 462 */
        "movl $0x28e1a, LittleLong\n" /* line 464 */
        "movl $0x28e4a, LittleLong64\n" /* line 465 */
        "movl $0x28f6a, LittleFloatRead\n" /* line 466 */
        "movl $0x28fb4, LittleFloatWrite\n" /* line 467 */
        /* } scope */
        "leave\n" /* line 485 */
        "retl\n"
        /* { scope 1 */
        ".Lf29d52_00029d9b:\n"
        "movl $0x28e10, LittleShort\n" /* line 450 */
        "movl $0x28e42, LittleLong\n" /* line 452 */
        "movl $0x28f5e, LittleLong64\n" /* line 453 */
        "movl $0x28fa2, LittleFloatRead\n" /* line 454 */
        "movl $0x28fe4, LittleFloatWrite\n" /* line 455 */
        /* } scope */
        "leave\n" /* line 485 */
        "retl\n"
    );
}

/* line 616 */
__attribute__((naked))
int I_strcmp(const char *s0, const char *s1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 616 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* s0 */
        "movl 0xc(%ebp), %eax\n" /* s1 */
        "movl $0x7fffffff, %esi\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf29dd0_00029de1:\n"
        "movzbl (%edx), %ecx\n" /* line 593 */
        "movsbl %cl, %edi\n" /* c0 */
        "addl $1, %edx\n"
        "movsbl (%eax), %ebx\n" /* line 594 | c1 */
        "addl $1, %eax\n"
        "subl $1, %esi\n" /* line 596 */
        "cmpl $-1, %esi\n"
        "je .Lf29dd0_00029e00\n"
        "cmpl %ebx, %edi\n" /* line 599 | c1, c0 */
        "jne .Lf29dd0_00029e07\n"
        "testb %cl, %cl\n" /* line 591 */
        "jne .Lf29dd0_00029de1\n"
        ".Lf29dd0_00029e00:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 621 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf29dd0_00029e07:\n"
        "xorl %eax, %eax\n" /* line 600 */
        "cmpl %edi, %ebx\n" /* c0, c1 */
        "setle %al\n"
        "leal -1(%eax, %eax), %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 621 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 192 */
__attribute__((naked))
JCOEF Com_StripExtension(const char *in, char *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 192 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* in */
        "movl 0xc(%ebp), %ebx\n" /* out */
        /* { scope 1 */
        "movzbl (%esi), %edx\n" /* line 173 */
        "testb %dl, %dl\n"
        "jne .Lf29e18_00029e48\n"
        "movl %esi, %ecx\n"
        ".Lf29e18_00029e2c:\n"
        "cmpl %esi, %ecx\n" /* line 197 | in */
        "je .Lf29e18_00029e41\n"
        "movl %esi, %edx\n" /* in */
        ".Lf29e18_00029e32:\n"
        "movzbl (%edx), %eax\n" /* line 198 */
        "movb %al, (%ebx)\n" /* out */
        "addl $1, %ebx\n" /* out */
        "addl $1, %edx\n"
        "cmpl %ecx, %edx\n" /* line 197 */
        "jne .Lf29e18_00029e32\n"
        ".Lf29e18_00029e41:\n"
        "movb $0, (%ebx)\n" /* line 199 | out */
        /* } scope */
        "popl %ebx\n" /* line 200 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29e18_00029e48:\n"
        "movl %esi, %ecx\n" /* line 173 */
        "xorl %eax, %eax\n"
        "jmp .Lf29e18_00029e62\n"
        ".Lf29e18_00029e4e:\n"
        "cmpb $0x2f, %dl\n" /* line 177 */
        "je .Lf29e18_00029e7b\n"
        "cmpb $0x5c, %dl\n"
        "je .Lf29e18_00029e7b\n"
        ".Lf29e18_00029e58:\n"
        "addl $1, %ecx\n" /* line 179 */
        "movzbl (%ecx), %edx\n" /* line 173 */
        "testb %dl, %dl\n"
        "je .Lf29e18_00029e73\n"
        ".Lf29e18_00029e62:\n"
        "cmpb $0x2e, %dl\n" /* line 175 */
        "jne .Lf29e18_00029e4e\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n" /* line 179 */
        "movzbl (%ecx), %edx\n" /* line 173 */
        "testb %dl, %dl\n"
        "jne .Lf29e18_00029e62\n"
        ".Lf29e18_00029e73:\n"
        "testl %eax, %eax\n" /* line 181 */
        "je .Lf29e18_00029e2c\n"
        "movl %eax, %ecx\n"
        "jmp .Lf29e18_00029e2c\n"
        ".Lf29e18_00029e7b:\n"
        "xorl %eax, %eax\n" /* line 177 */
        "jmp .Lf29e18_00029e58\n"
    );
}

/* line 532 */
__attribute__((naked))
Bool I_isforfilename(int c)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 532 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* c */
        "leal -0x61(%edx), %eax\n" /* line 516 */
        "cmpl $0x19, %eax\n"
        "jbe .Lf29e80_00029e96\n"
        "leal -0x41(%edx), %eax\n"
        "cmpl $0x19, %eax\n"
        "ja .Lf29e80_00029ec7\n"
        ".Lf29e80_00029e96:\n"
        "movl $1, %eax\n"
        ".Lf29e80_00029e9b:\n"
        "testl %eax, %eax\n" /* line 528 */
        "jne .Lf29e80_00029ea7\n"
        "leal -0x30(%edx), %eax\n"
        "cmpl $9, %eax\n"
        "ja .Lf29e80_00029ec3\n"
        ".Lf29e80_00029ea7:\n"
        "movl $1, %eax\n"
        ".Lf29e80_00029eac:\n"
        "testl %eax, %eax\n" /* line 535 */
        "jne .Lf29e80_00029ebc\n"
        "cmpl $0x5f, %edx\n"
        "je .Lf29e80_00029ebc\n"
        "cmpl $0x2d, %edx\n"
        "je .Lf29e80_00029ebc\n"
        "popl %ebp\n" /* line 536 */
        "retl\n"
        ".Lf29e80_00029ebc:\n"
        "movl $1, %eax\n" /* line 535 */
        "popl %ebp\n" /* line 536 */
        "retl\n"
        ".Lf29e80_00029ec3:\n"
        "xorl %eax, %eax\n" /* line 528 */
        "jmp .Lf29e80_00029eac\n"
        ".Lf29e80_00029ec7:\n"
        "xorl %eax, %eax\n" /* line 516 */
        "jmp .Lf29e80_00029e9b\n"
    );
}

/* line 925 */
__attribute__((naked))
char * Info_ValueForKey(const char *s, const char *key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 925 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 934 | s */
        "je .Lf29ecc_00029f41\n"
        "movl 0xc(%ebp), %esi\n" /* key, s1 */
        "testl %esi, %esi\n" /* s1 */
        "je .Lf29ecc_00029f41\n"
        "cld\n" /* line 939 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* s, c1 */
        "repne scasb %es:(%edi), %al\n" /* c1 */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x1fff, %ecx\n"
        "ja .Lf29ecc_00029f5c\n"
        ".Lf29ecc_00029eff:\n"
        "movl valueindex, %eax\n" /* line 944 */
        "xorl $1, %eax\n"
        "movl %eax, -0x2024(%ebp)\n"
        "movl %eax, valueindex\n"
        "leal 1(%ebx), %eax\n" /* line 946 | s */
        "cmpb $0x5c, (%ebx)\n" /* s */
        "cmovel %eax, %ebx\n" /* s */
        ".Lf29ecc_00029f1b:\n"
        "movzbl (%ebx), %eax\n" /* line 950 | s */
        "cmpb $0x5c, %al\n"
        "je .Lf29ecc_00029f72\n"
        "testb %al, %al\n" /* line 952 */
        "je .Lf29ecc_00029f41\n"
        "leal -0x2018(%ebp), %ecx\n" /* pkey */
        "movl %ecx, %edx\n"
        ".Lf29ecc_00029f2e:\n"
        "movb %al, (%edx)\n" /* line 954 */
        "addl $1, %edx\n"
        "addl $1, %ebx\n" /* s */
        "movzbl (%ebx), %eax\n" /* line 950 | s */
        "cmpb $0x5c, %al\n"
        "je .Lf29ecc_00029f7a\n"
        "testb %al, %al\n" /* line 952 */
        "jne .Lf29ecc_00029f2e\n"
        ".Lf29ecc_00029f41:\n"
        "movl $0x2157b8, -0x2020(%ebp)\n" /* line 989 | result */
        /* } scope */
        ".Lf29ecc_00029f4b:\n"
        "movl -0x2020(%ebp), %eax\n" /* line 995 | result */
        "addl $0x202c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29ecc_00029f5c:\n"
        "movl $0x215f28, 4(%esp)\n" /* line 941 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf29ecc_00029eff\n"
        ".Lf29ecc_00029f72:\n"
        "leal -0x2018(%ebp), %ecx\n" /* line 950 | pkey */
        "movl %ecx, %edx\n"
        ".Lf29ecc_00029f7a:\n"
        "movb $0, (%edx)\n" /* line 956 */
        "leal 1(%ebx), %eax\n" /* line 957 | s */
        "movl %eax, -0x201c(%ebp)\n"
        "movl -0x2024(%ebp), %eax\n" /* line 975 */
        "shll $0xd, %eax\n"
        "addl $value1, %eax\n"
        "movl %eax, -0x2020(%ebp)\n" /* result */
        "movzbl 1(%ebx), %eax\n" /* line 980 | s */
        "cmpb $0x5c, %al\n"
        "je .Lf29ecc_00029fa6\n"
        "testb %al, %al\n"
        "jne .Lf29ecc_0002a015\n"
        ".Lf29ecc_00029fa6:\n"
        "movl -0x2020(%ebp), %edx\n" /* result */
        ".Lf29ecc_00029fac:\n"
        "movb $0, (%edx)\n" /* line 984 */
        "movl 0xc(%ebp), %ebx\n" /* key, s */
        "movl %ecx, %esi\n" /* s1 */
        "jmp .Lf29ecc_00029fba\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf29ecc_00029fb6:\n"
        "testl %ecx, %ecx\n" /* line 564 */
        "je .Lf29ecc_00029f4b\n"
        ".Lf29ecc_00029fba:\n"
        "movsbl (%ebx), %ecx\n" /* line 566 */
        "addl $1, %ebx\n"
        "movsbl (%esi), %edi\n" /* line 567 | c1 */
        "addl $1, %esi\n"
        "leal 0x7fffdfe8(%ebp), %eax\n" /* line 569 */
        "cmpl %eax, %esi\n"
        "je .Lf29ecc_00029f4b\n"
        "cmpl %edi, %ecx\n" /* line 572 | c1 */
        "je .Lf29ecc_00029fb6\n"
        "leal -0x61(%ecx), %eax\n" /* line 574 */
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "leal -0x20(%ecx), %edx\n" /* line 575 */
        "testb %al, %al\n"
        "cmovnel %edx, %ecx\n"
        "leal -0x61(%edi), %eax\n" /* line 576 | c1 */
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "leal -0x20(%edi), %edx\n" /* line 577 | c1 */
        "testb %al, %al\n"
        "cmovnel %edx, %edi\n" /* c1 */
        "cmpl %ecx, %edi\n" /* line 578 | c1 */
        "je .Lf29ecc_00029fb6\n"
        /* } scope */
        /* } scope */
        "movl -0x201c(%ebp), %ebx\n" /* line 989 | s */
        "cmpb $0, (%ebx)\n" /* s */
        "je .Lf29ecc_00029f41\n"
        "addl $1, %ebx\n" /* line 991 | s */
        "jmp .Lf29ecc_00029f1b\n"
        ".Lf29ecc_0002a015:\n"
        "movl -0x2020(%ebp), %edx\n" /* line 980 | result */
        ".Lf29ecc_0002a01b:\n"
        "movb %al, (%edx)\n" /* line 982 */
        "addl $1, %edx\n"
        "addl $1, -0x201c(%ebp)\n"
        "movl -0x201c(%ebp), %ebx\n" /* line 980 | s */
        "movzbl (%ebx), %eax\n" /* s */
        "cmpb $0x5c, %al\n"
        "je .Lf29ecc_00029fac\n"
        "testb %al, %al\n"
        "jne .Lf29ecc_0002a01b\n"
        "jmp .Lf29ecc_00029fac\n"
    );
}

/* line 608 */
__attribute__((naked))
int I_stricmp(const char *s0, const char *s1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 608 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edi\n" /* s0 */
        "movl 0xc(%ebp), %esi\n" /* s1 */
        "movl $0x7fffffff, -0x10(%ebp)\n" /* n */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2a042_0002a058:\n"
        "movsbl (%edi), %ecx\n" /* line 566 */
        "addl $1, %edi\n"
        "movsbl (%esi), %ebx\n" /* line 567 | c1 */
        "addl $1, %esi\n"
        "subl $1, -0x10(%ebp)\n" /* line 569 | n */
        "cmpl $-1, -0x10(%ebp)\n" /* n */
        "je .Lf2a042_0002a09c\n"
        "cmpl %ebx, %ecx\n" /* line 572 | c1 */
        "je .Lf2a042_0002a098\n"
        "leal -0x61(%ecx), %eax\n" /* line 574 */
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "leal -0x20(%ecx), %edx\n" /* line 575 */
        "testb %al, %al\n"
        "cmovnel %edx, %ecx\n"
        "leal -0x61(%ebx), %eax\n" /* line 576 | c1 */
        "cmpl $0x19, %eax\n"
        "setbe %al\n"
        "leal -0x20(%ebx), %edx\n" /* line 577 | c1 */
        "testb %al, %al\n"
        "cmovnel %edx, %ebx\n" /* c1 */
        "cmpl %ebx, %ecx\n" /* line 578 | c1 */
        "jne .Lf2a042_0002a0a6\n"
        ".Lf2a042_0002a098:\n"
        "testl %ecx, %ecx\n" /* line 564 */
        "jne .Lf2a042_0002a058\n"
        ".Lf2a042_0002a09c:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $4, %esp\n" /* line 613 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2a042_0002a0a6:\n"
        "xorl %eax, %eax\n" /* line 579 */
        "cmpl %ecx, %ebx\n" /* c1 */
        "setle %al\n"
        "leal -1(%eax, %eax), %eax\n"
        /* } scope */
        /* } scope */
        "addl $4, %esp\n" /* line 613 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 225 */
__attribute__((naked))
JCOEF Com_DefaultExtension(char *path, int maxSize, const char *extension)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 225 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %esi\n" /* path */
        /* { scope 1 */
        "cld\n" /* line 234 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* path */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %esi), %ecx\n"
        "leal -1(%ecx), %ebx\n" /* src */
        "movzbl -1(%ecx), %eax\n" /* line 236 */
        "cmpb $0x2f, %al\n"
        "je .Lf2a0ba_0002a10d\n"
        "cmpl %ebx, %esi\n" /* src, path */
        "je .Lf2a0ba_0002a10d\n"
        "cmpb $0x2e, %al\n" /* line 238 */
        "je .Lf2a0ba_0002a105\n"
        "movl %ebx, %edx\n" /* line 240 | src */
        ".Lf2a0ba_0002a0ed:\n"
        "movzbl -1(%edx), %ecx\n" /* line 236 */
        "cmpb $0x2f, %cl\n"
        "je .Lf2a0ba_0002a10d\n"
        "leal 1(%esi), %eax\n" /* path */
        "cmpl %eax, %edx\n"
        "je .Lf2a0ba_0002a10d\n"
        "subl $1, %edx\n"
        "cmpb $0x2e, %cl\n" /* line 238 */
        "jne .Lf2a0ba_0002a0ed\n"
        /* } scope */
        ".Lf2a0ba_0002a105:\n"
        "addl $0x6c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a0ba_0002a10d:\n"
        "movl $0x3f, 8(%esp)\n" /* line 554 */
        "movl %esi, 4(%esp)\n" /* path */
        "leal -0x58(%ebp), %ebx\n" /* oldPath, src */
        "movl %ebx, (%esp)\n" /* src */
        "calll strncpy\n"
        "movb $0, -0x19(%ebp)\n" /* line 555 */
        "movl 0x10(%ebp), %eax\n" /* line 246 | extension */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* src */
        "movl $0x215f50, 8(%esp)\n" /* "%s%s" */
        "movl 0xc(%ebp), %eax\n" /* maxSize */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* path */
        "calll Com_sprintf\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 693 */
__attribute__((naked))
JCOEF I_strncat(char *dest, int size, const char *src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 693 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* size */
        /* { scope 1 */
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* dest */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n" /* dest */
        "cmpl %esi, %ebx\n" /* line 700 | size, destLen */
        "jl .Lf2a152_0002a188\n"
        "movl $0x215f58, 4(%esp)\n" /* line 701 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf2a152_0002a188:\n"
        "subl %ebx, %esi\n" /* line 703 | dest, destsize */
        "addl 8(%ebp), %ebx\n" /* dest */
        /* { scope 2 */
        "leal -1(%esi), %eax\n" /* line 554 */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* src */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strncpy\n"
        "movb $0, -1(%ebx, %esi)\n" /* line 555 */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 704 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1351 */
__attribute__((naked))
qboolean ParseConfigStringToStruct(byte *pStruct, const cspField_t *pFieldList, const int iNumFields, const char *pszBuffer, const int iMaxFieldTypes, qboolean (*parseSpecialFieldType)(), JCOEF (*parseStrcpy)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1351 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "cmpl $0, 0x10(%ebp)\n" /* line 1357 | iNumFields */
        "jg .Lf2a1b0_0002a207\n"
        "je .Lf2a1b0_0002a1fa\n" /* line 1412 */
        ".Lf2a1b0_0002a1c1:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1416 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a1b0_0002a1cb:\n"
        "movl 0x18(%ebp), %ecx\n" /* line 1398 | iMaxFieldTypes */
        "testl %ecx, %ecx\n"
        "jle .Lf2a1b0_0002a1d7\n"
        "cmpl 0x18(%ebp), %edx\n" /* iMaxFieldTypes */
        "jl .Lf2a1b0_0002a233\n"
        ".Lf2a1b0_0002a1d7:\n"
        "movl %edx, 8(%esp)\n" /* line 1407 */
        "movl $0x215f78, 4(%esp)\n" /* "Bad field type %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf2a1b0_0002a1ef:\n"
        "addl $1, %edi\n" /* line 1357 | iField */
        "addl $0xc, %esi\n" /* pField */
        "cmpl %edi, 0x10(%ebp)\n" /* iField, iNumFields */
        "jne .Lf2a1b0_0002a20c\n"
        ".Lf2a1b0_0002a1fa:\n"
        "movl $1, %eax\n" /* line 1412 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1416 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2a1b0_0002a207:\n"
        "movl 0xc(%ebp), %esi\n" /* line 1357 | pFieldList, pField */
        "xorl %edi, %edi\n" /* iField */
        ".Lf2a1b0_0002a20c:\n"
        "movl (%esi), %eax\n" /* line 1359 | pField */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* pszBuffer */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "cmpb $0, (%eax)\n" /* line 1360 */
        "je .Lf2a1b0_0002a1ef\n"
        "movl 8(%esi), %edx\n" /* line 1363 | pField */
        "cmpl $7, %edx\n"
        "jg .Lf2a1b0_0002a1cb\n"
        "ja .Lf2a1b0_0002a1ef\n" /* line 1365 */
        "jmpl *0x2efb00(, %edx, 4)\n"
        ".Lf2a1b0_0002a233:\n"
        "movl %edx, 8(%esp)\n" /* line 1401 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pStruct */
        "movl %eax, (%esp)\n"
        "calll *0x1c(%ebp)\n" /* parseSpecialFieldType */
        "testl %eax, %eax\n"
        "je .Lf2a1b0_0002a1c1\n"
        "addl $1, %edi\n" /* line 1357 | iField */
        "addl $0xc, %esi\n" /* pField */
        "cmpl %edi, 0x10(%ebp)\n" /* iField, iNumFields */
        "jne .Lf2a1b0_0002a20c\n"
        "jmp .Lf2a1b0_0002a1fa\n"
        "movl %eax, 4(%esp)\n" /* line 1368 */
        "movl 8(%ebp), %eax\n" /* pStruct */
        "addl 4(%esi), %eax\n" /* pField */
        "movl %eax, (%esp)\n"
        "calll *0x20(%ebp)\n" /* parseStrcpy */
        "jmp .Lf2a1b0_0002a1ef\n"
        "movl 8(%ebp), %ebx\n" /* line 1389 | pStruct, dest */
        "addl 4(%esi), %ebx\n" /* pField, dest */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x20(%ebp)\n"
        "cvtsd2ss -0x20(%ebp), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, (%ebx)\n" /* dest */
        "jmp .Lf2a1b0_0002a1ef\n"
        "movl 8(%ebp), %ebx\n" /* line 1386 | pStruct, dest */
        "addl 4(%esi), %ebx\n" /* pField, dest */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x28(%ebp)\n"
        "cvtsd2ss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* dest */
        "jmp .Lf2a1b0_0002a1ef\n"
        "movl 8(%ebp), %ebx\n" /* line 1383 | pStruct, dest */
        "addl 4(%esi), %ebx\n" /* pField, dest */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* dest */
        "jmp .Lf2a1b0_0002a1ef\n"
        "movl 8(%ebp), %ebx\n" /* line 1380 | pStruct, dest */
        "addl 4(%esi), %ebx\n" /* pField, dest */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%ebx)\n" /* dest */
        "jmp .Lf2a1b0_0002a1ef\n"
        "movl 8(%ebp), %ebx\n" /* line 1377 | pStruct, dest */
        "addl 4(%esi), %ebx\n" /* pField, dest */
        /* { scope 2 */
        "movl $0xff, 8(%esp)\n" /* line 554 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strncpy\n"
        "movb $0, 0xff(%ebx)\n" /* line 555 */
        "jmp .Lf2a1b0_0002a1ef\n"
        /* } scope */
        "movl 8(%ebp), %ebx\n" /* line 1374 | pStruct, dest */
        "addl 4(%esi), %ebx\n" /* pField, dest */
        /* { scope 2 */
        "movl $0x3f, 8(%esp)\n" /* line 554 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strncpy\n"
        "movb $0, 0x3f(%ebx)\n" /* line 555 */
        "jmp .Lf2a1b0_0002a1ef\n"
        /* } scope */
        "movl 8(%ebp), %ebx\n" /* line 1371 | pStruct, dest */
        "addl 4(%esi), %ebx\n" /* pField, dest */
        /* { scope 2 */
        "movl $0x3ff, 8(%esp)\n" /* line 554 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strncpy\n"
        "movb $0, 0x3ff(%ebx)\n" /* line 555 */
        "jmp .Lf2a1b0_0002a1ef\n"
    );
}

