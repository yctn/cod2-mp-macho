/* ASM dump from: scr_stringlist.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_stringlist.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

static struct scrStringGlob_t scrStringGlob; /* scrStringGlob */

unsigned int SL_ConvertFromString(const char *str);
unsigned int SL_Shutdown(void);
const char * SL_ConvertToString(unsigned int stringValue);
unsigned int SL_TransferRefToUser(unsigned int stringValue, unsigned int user);
unsigned int SL_AddRefToString(unsigned int stringValue);
unsigned int SL_RemoveRefToStringOfLen(unsigned int stringValue, unsigned int len);
int SL_GetStringLen(unsigned int stringValue);
unsigned int SL_FindStringOfLen(const char *str, unsigned int len);
unsigned int SL_FindLowercaseString(const char *str);
unsigned int SL_FindString(const char *str);
unsigned int SL_GetStringOfLen(const char *str, unsigned int user, unsigned int len, int type);
unsigned int SL_GetLowercaseString_(const char *str, unsigned int user, int type);
unsigned int SL_GetString_(const char *str, unsigned int user, int type);
unsigned int SL_RemoveRefToString(unsigned int stringValue);
unsigned int SL_ShutdownSystem(unsigned int user);
unsigned int Scr_SetString(scr_string_t *to, unsigned int from);
unsigned int SL_ConvertToLowercase(unsigned int stringValue, unsigned int user, int type);
unsigned int Scr_ShutdownGameStrings(void);
unsigned int SL_Init(void);
unsigned int Scr_AllocString(const char *s, int sys);
unsigned int SL_GetString(const char *str, unsigned int user);
unsigned int SL_GetStringForFloat(float f);
unsigned int SL_GetStringForInt(int i);
unsigned int SL_GetStringForVector(const float *v);
unsigned int Scr_CreateCanonicalFilename(const char *filename);

/* line 206 */
unsigned int SL_ConvertFromString(const char *str)
{
    return (int)((byte *)str - 4 - *(byte **)*(void **)imp_scrMemTreePub) >> 3;
}

/* line 299 */
unsigned int SL_Shutdown(void)
{
    *(byte *)((char *)&scrStringGlob + 65536) = 0;
}

/* line 151 */
const char * SL_ConvertToString(unsigned int stringValue)
{
    if (!stringValue)
        return 0;
    return (const char *)(*(byte **)*(void **)imp_scrMemTreePub + stringValue * 8 + 4);
}

/* line 759 */
unsigned int SL_TransferRefToUser(unsigned int stringValue, unsigned int user)
{
    byte *entry = *(byte **)*(void **)imp_scrMemTreePub + stringValue * 8;
    if (entry[1] & user)
    {
        *(unsigned short *)(entry + 2) -= 1;
    }
    else
    {
        entry[1] |= (byte)user;
    }
    return 0;
}

/* line 810 */
unsigned int SL_AddRefToString(unsigned int stringValue)
{
    byte *base = *(byte **)*(void **)imp_scrMemTreePub;
    *(unsigned short *)(base + stringValue * 8 + 2) += 1;
}

/* line 986 */
__attribute__((naked))
unsigned int SL_RemoveRefToStringOfLen(unsigned int stringValue, unsigned int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 986 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "movl 8(%ebp), %ecx\n" /* stringValue */
        "leal (%eax, %ecx, 8), %edx\n"
        "movzwl 2(%edx), %eax\n" /* line 1007 */
        "subl $1, %eax\n"
        "movw %ax, 2(%edx)\n"
        "testw %ax, %ax\n" /* line 1008 */
        "jne .Lf43568_0004367c\n"
        /* { scope 2 */
        "leal 4(%edx), %eax\n" /* line 855 */
        /* { scope 3 */
        "cmpl $0xff, 0xc(%ebp)\n" /* line 222 | len */
        "jbe .Lf43568_00043684\n"
        "movl 0xc(%ebp), %ecx\n" /* line 238 | len */
        "shrl $2, %ecx\n"
        "movl $0x40011, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "subl %eax, %ecx\n"
        "leal 1(%ecx), %esi\n"
        /* } scope */
        ".Lf43568_000435c8:\n"
        "leal (, %esi, 4), %edx\n" /* line 859 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, %edi\n" /* newEntry */
        "addl $scrStringGlob, %edi\n" /* newEntry */
        "movl 0xc(%ebp), %eax\n" /* line 877 | len */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* stringValue */
        "movl %ecx, (%esp)\n"
        "calll MT_FreeIndex\n"
        "movl -0x1c(%ebp), %eax\n" /* line 881 */
        "movzwl scrStringGlob(%eax), %ecx\n"
        "andl $0x3fff, %ecx\n"
        "leal (, %ecx, 4), %edx\n" /* line 882 */
        "leal scrStringGlob(%edx), %ebx\n" /* hash */
        "movzwl 2(%edi), %eax\n" /* line 884 | newEntry */
        "cmpl %eax, 8(%ebp)\n" /* stringValue */
        "je .Lf43568_000436da\n"
        "movzwl 2(%ebx), %eax\n" /* line 905 | hash */
        "cmpl %eax, 8(%ebp)\n" /* stringValue */
        "je .Lf43568_0004363d\n"
        ".Lf43568_00043622:\n"
        "movl %ecx, %esi\n" /* line 908 */
        "movzwl (%ebx), %ecx\n" /* line 912 | hash */
        "andl $0x3fff, %ecx\n"
        "leal scrStringGlob(, %ecx, 4), %ebx\n" /* line 913 | hash */
        "movzwl 2(%ebx), %eax\n" /* line 905 | hash */
        "cmpl %eax, 8(%ebp)\n" /* stringValue */
        "jne .Lf43568_00043622\n"
        ".Lf43568_0004363d:\n"
        "movzwl scrStringGlob(, %esi, 4), %eax\n" /* line 907 */
        "andw $0xc000, %ax\n"
        "movzwl (%ebx), %edx\n" /* hash */
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movw %ax, scrStringGlob(, %esi, 4)\n"
        "movl %ebx, %edi\n" /* hash, newEntry */
        ".Lf43568_0004365d:\n"
        "movzwl scrStringGlob, %eax\n" /* line 919 */
        "movw %ax, (%edi)\n" /* line 921 | newEntry */
        "movw $0, 2(%edi)\n" /* line 922 | newEntry */
        "movw %cx, scrStringGlob+2(, %eax, 4)\n" /* line 924 */
        "movw %cx, scrStringGlob\n" /* line 925 */
        /* } scope */
        /* } scope */
        ".Lf43568_0004367c:\n"
        "addl $0x2c, %esp\n" /* line 1037 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf43568_00043684:\n"
        "movl 0xc(%ebp), %edx\n" /* line 226 | len */
        "testl %edx, %edx\n"
        "je .Lf43568_000436d0\n"
        "movl %eax, %ecx\n" /* line 222 */
        "xorl %ebx, %ebx\n" /* hash */
        "movl 0xc(%ebp), %eax\n" /* len */
        "leal (%ecx, %eax), %esi\n"
        ".Lf43568_00043695:\n"
        "movl %ebx, %eax\n" /* line 229 | hash */
        "shll $5, %eax\n"
        "subl %ebx, %eax\n" /* hash */
        "movsbl (%ecx), %edx\n" /* line 230 */
        "leal (%edx, %eax), %ebx\n" /* hash */
        "addl $1, %ecx\n" /* line 231 */
        "cmpl %ecx, %esi\n" /* line 226 */
        "jne .Lf43568_00043695\n"
        "movl $0x40011, %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "mull %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "movl %ebx, %edx\n" /* hash */
        "subl %eax, %edx\n"
        "leal 1(%edx), %esi\n" /* line 235 */
        "jmp .Lf43568_000435c8\n"
        ".Lf43568_000436d0:\n"
        "xorl %edx, %edx\n" /* line 226 */
        "leal 1(%edx), %esi\n" /* line 235 */
        "jmp .Lf43568_000435c8\n"
        /* } scope */
        ".Lf43568_000436da:\n"
        "cmpl %ebx, %edi\n" /* line 886 | hash, newEntry */
        "je .Lf43568_0004370c\n"
        "movzwl scrStringGlob(%edx), %eax\n" /* line 888 */
        "andw $0x3fff, %ax\n"
        "orw $0x8000, %ax\n"
        "movl -0x1c(%ebp), %edx\n"
        "movw %ax, scrStringGlob(%edx)\n"
        "movzwl 2(%ebx), %eax\n" /* line 889 | hash */
        "movw %ax, 2(%edi)\n" /* newEntry */
        "movl %edi, scrStringGlob+65540\n" /* line 890 | newEntry */
        "movl %ebx, %edi\n" /* hash, newEntry */
        "jmp .Lf43568_0004365d\n"
        ".Lf43568_0004370c:\n"
        "movl %esi, %ecx\n" /* line 905 */
        "jmp .Lf43568_0004365d\n"
    );
}

/* line 190 */
__attribute__((naked))
int SL_GetStringLen(unsigned int stringValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 190 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* stringValue */
        "leal (%edx, %eax, 8), %edx\n"
        /* { scope 2 */
        "movzbl (%edx), %eax\n" /* line 182 */
        "subb $1, %al\n"
        "movzbl %al, %ecx\n"
        "cmpb $0, 4(%edx, %ecx)\n" /* line 184 */
        "je .Lf43714_0004374e\n"
        "leal 4(%edx, %ecx), %edx\n"
        ".Lf43714_00043737:\n"
        "addl $0x100, %ecx\n" /* line 182 */
        "movzbl 0x100(%edx), %eax\n" /* line 184 */
        "addl $0x100, %edx\n"
        "testb %al, %al\n"
        "jne .Lf43714_00043737\n"
        /* } scope */
        /* } scope */
        ".Lf43714_0004374e:\n"
        "movl %ecx, %eax\n" /* line 197 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 311 */
__attribute__((naked))
unsigned int SL_FindStringOfLen(const char *str, unsigned int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 311 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        /* { scope 2 */
        "cmpl $0xff, 0xc(%ebp)\n" /* line 222 | len */
        "ja .Lf43752_000437af\n"
        "movl 0xc(%ebp), %ecx\n" /* line 226 | len */
        "testl %ecx, %ecx\n"
        "je .Lf43752_0004380d\n"
        "movl 8(%ebp), %ecx\n" /* line 222 | str */
        "xorl %ebx, %ebx\n" /* hash */
        "movl 0xc(%ebp), %edx\n" /* len */
        "leal (%ecx, %edx), %esi\n"
        ".Lf43752_0004377a:\n"
        "movl %ebx, %eax\n" /* line 229 | hash */
        "shll $5, %eax\n"
        "subl %ebx, %eax\n" /* hash */
        "movsbl (%ecx), %edx\n" /* line 230 */
        "leal (%edx, %eax), %ebx\n" /* hash */
        "addl $1, %ecx\n" /* line 231 */
        "cmpl %ecx, %esi\n" /* line 226 */
        "jne .Lf43752_0004377a\n"
        "movl $0x40011, %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "mull %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "movl %ebx, %edx\n" /* hash */
        "subl %eax, %edx\n"
        "jmp .Lf43752_0004380f\n"
        ".Lf43752_000437af:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 238 | len */
        "shrl $2, %ecx\n"
        "movl $0x40011, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* hash */
        "movl %ecx, %eax\n"
        /* } scope */
        "shll $2, %eax\n" /* line 328 */
        "leal scrStringGlob(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* entry */
        "movzwl scrStringGlob(%eax), %ebx\n" /* line 334 | newEntry */
        "movl %ebx, %eax\n" /* newEntry */
        "andl $0xc000, %eax\n"
        "cmpl $0x8000, %eax\n"
        "je .Lf43752_00043838\n"
        ".Lf43752_000437fb:\n"
        "movl $0, -0x14(%ebp)\n" /* line 356 | stringValue */
        /* } scope */
        ".Lf43752_00043802:\n"
        "movl -0x14(%ebp), %eax\n" /* line 395 | stringValue */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf43752_0004380d:\n"
        "xorl %edx, %edx\n" /* line 226 */
        ".Lf43752_0004380f:\n"
        "addl $1, %edx\n" /* line 235 */
        "movl %edx, -0x20(%ebp)\n" /* hash */
        "movl %edx, %eax\n"
        /* } scope */
        "shll $2, %eax\n" /* line 328 */
        "leal scrStringGlob(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* entry */
        "movzwl scrStringGlob(%eax), %ebx\n" /* line 334 | newEntry */
        "movl %ebx, %eax\n" /* newEntry */
        "andl $0xc000, %eax\n"
        "cmpl $0x8000, %eax\n"
        "jne .Lf43752_000437fb\n"
        ".Lf43752_00043838:\n"
        "movzwl 2(%edx), %ecx\n" /* line 338 */
        "movl %ecx, -0x14(%ebp)\n" /* stringValue */
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "movzbl 0xc(%ebp), %edx\n" /* line 339 | len */
        "movl %edx, -0x18(%ebp)\n" /* byteLen */
        "movzbl 0xc(%ebp), %ecx\n" /* len */
        "cmpb %cl, (%eax)\n"
        "je .Lf43752_00043936\n"
        ".Lf43752_0004385f:\n"
        "andl $0x3fff, %ebx\n" /* line 354 | newEntry */
        "movl %ebx, -0x1c(%ebp)\n" /* newEntry, newIndex */
        "leal scrStringGlob(, %ebx, 4), %ebx\n" /* line 355 | newEntry */
        "cmpl %ebx, -0x28(%ebp)\n" /* line 356 | newEntry, entry */
        "je .Lf43752_000437fb\n"
        "movl -0x20(%ebp), %esi\n" /* hash */
        "movl %esi, -0x24(%ebp)\n" /* prev */
        "jmp .Lf43752_0004389d\n"
        ".Lf43752_0004387c:\n"
        "movzwl (%ebx), %eax\n" /* line 384 | newEntry */
        "andl $0x3fff, %eax\n"
        "leal scrStringGlob(, %eax, 4), %ebx\n" /* line 385 | newEntry */
        "cmpl %ebx, -0x28(%ebp)\n" /* line 356 | newEntry, entry */
        "je .Lf43752_000437fb\n"
        "movl -0x1c(%ebp), %ecx\n" /* newIndex */
        "movl %ecx, -0x24(%ebp)\n" /* prev */
        "movl %eax, -0x1c(%ebp)\n" /* newIndex */
        ".Lf43752_0004389d:\n"
        "movzwl 2(%ebx), %eax\n" /* line 139 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x10(%ebp), %ecx\n"
        "leal (%ecx, %eax, 8), %edx\n"
        "movzbl (%edx), %eax\n" /* line 361 */
        "cmpl %eax, -0x18(%ebp)\n" /* byteLen */
        "jne .Lf43752_0004387c\n"
        "addl $4, %edx\n"
        "cld\n"
        "movl 0xc(%ebp), %esi\n" /* len */
        "cmpl %esi, %esi\n"
        "movl %edx, %esi\n"
        "movl 8(%ebp), %edi\n" /* str */
        "movl 0xc(%ebp), %ecx\n" /* len */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf43752_000438d6\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf43752_000438d6:\n"
        "testl %eax, %eax\n"
        "jne .Lf43752_0004387c\n"
        "movl -0x24(%ebp), %esi\n" /* line 364 | prev */
        "movzwl scrStringGlob(, %esi, 4), %eax\n"
        "andw $0xc000, %ax\n"
        "movzwl (%ebx), %edx\n" /* newEntry */
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movw %ax, scrStringGlob(, %esi, 4)\n"
        "movzwl (%ebx), %eax\n" /* line 365 | newEntry */
        "andw $0xc000, %ax\n"
        "movl -0x28(%ebp), %ecx\n" /* entry */
        "movzwl (%ecx), %edx\n"
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movw %ax, (%ebx)\n" /* newEntry */
        "movzwl (%ecx), %eax\n" /* line 366 */
        "andw $0xc000, %ax\n"
        "orl -0x1c(%ebp), %eax\n" /* newIndex */
        "movw %ax, (%ecx)\n"
        "movl -0x2c(%ebp), %esi\n" /* line 367 */
        "movl %esi, -0x14(%ebp)\n" /* stringValue */
        "movzwl 2(%ecx), %eax\n" /* line 368 */
        "movw %ax, 2(%ebx)\n" /* newEntry */
        "movw %si, 2(%ecx)\n" /* line 369 */
        "jmp .Lf43752_00043802\n"
        ".Lf43752_00043936:\n"
        "addl $4, %eax\n" /* line 339 */
        "cld\n"
        "movl 0xc(%ebp), %esi\n" /* len */
        "cmpl %esi, %esi\n"
        "movl %eax, %esi\n"
        "movl 8(%ebp), %edi\n" /* str */
        "movl 0xc(%ebp), %ecx\n" /* len */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf43752_0004395a\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf43752_0004395a:\n"
        "testl %eax, %eax\n"
        "jne .Lf43752_0004385f\n"
        "jmp .Lf43752_00043802\n"
    );
}

/* line 407 */
__attribute__((naked))
unsigned int SL_FindLowercaseString(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 407 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x201c, %esp\n"
        "movl 8(%ebp), %esi\n" /* str */
        /* { scope 1 */
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* str, i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "cmpl $0x2000, %ebx\n" /* line 416 */
        "jg .Lf43968_000439ce\n"
        "testl %ebx, %ebx\n" /* line 421 */
        "jg .Lf43968_000439b0\n"
        ".Lf43968_00043993:\n"
        "movl %ebx, 4(%esp)\n" /* line 425 */
        "leal -0x2018(%ebp), %eax\n" /* newStr */
        "movl %eax, (%esp)\n"
        "calll SL_FindStringOfLen\n"
        /* } scope */
        "addl $0x201c, %esp\n" /* line 426 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf43968_000439b0:\n"
        "xorl %edi, %edi\n" /* line 416 | i */
        ".Lf43968_000439b2:\n"
        "movsbl (%esi, %edi), %eax\n" /* line 422 | str */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, -0x2018(%edi, %ebp)\n" /* i */
        "addl $1, %edi\n" /* line 421 | i */
        "cmpl %edi, %ebx\n" /* i */
        "jne .Lf43968_000439b2\n"
        "jmp .Lf43968_00043993\n"
        ".Lf43968_000439ce:\n"
        "xorl %eax, %eax\n" /* line 416 */
        /* } scope */
        "addl $0x201c, %esp\n" /* line 426 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 398 */
__attribute__((naked))
unsigned int SL_FindString(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 398 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* str */
        "movl %edx, %edi\n" /* line 400 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SL_FindStringOfLen\n"
        "addl $0x14, %esp\n" /* line 401 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 491 */
__attribute__((naked))
unsigned int SL_GetStringOfLen(const char *str, unsigned int user, unsigned int len, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 491 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        /* { scope 2 */
        "cmpl $0xff, 0x10(%ebp)\n" /* line 222 | len */
        "ja .Lf43a06_00043a66\n"
        "movl 0x10(%ebp), %ebx\n" /* line 226 | len, hash */
        "testl %ebx, %ebx\n" /* hash */
        "je .Lf43a06_00043bc0\n"
        "movl 8(%ebp), %ecx\n" /* line 222 | str */
        "xorl %ebx, %ebx\n" /* hash */
        "movl 0x10(%ebp), %edx\n" /* len */
        "leal (%ecx, %edx), %esi\n"
        ".Lf43a06_00043a2e:\n"
        "movl %ebx, %eax\n" /* line 229 | hash */
        "shll $5, %eax\n"
        "subl %ebx, %eax\n" /* hash */
        "movsbl (%ecx), %edx\n" /* line 230 */
        "leal (%edx, %eax), %ebx\n" /* hash */
        "addl $1, %ecx\n" /* line 231 */
        "cmpl %ecx, %esi\n" /* line 226 */
        "jne .Lf43a06_00043a2e\n"
        "movl $0x40011, %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "mull %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "movl %ebx, %edx\n" /* hash */
        "subl %eax, %edx\n"
        "jmp .Lf43a06_00043bc2\n"
        ".Lf43a06_00043a66:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 238 | len */
        "shrl $2, %ecx\n"
        "movl $0x40011, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x30(%ebp)\n" /* hash */
        "movl %ecx, %ebx\n" /* hash */
        /* } scope */
        ".Lf43a06_00043a91:\n"
        "shll $2, %ebx\n" /* line 510 | refStr */
        "leal scrStringGlob(%ebx), %edx\n" /* refStr */
        "movl %edx, -0x38(%ebp)\n" /* entry */
        "movzbl 0x10(%ebp), %ecx\n" /* line 512 | len */
        "movl %ecx, -0x2c(%ebp)\n" /* byteLen */
        "movzwl scrStringGlob(%ebx), %esi\n" /* line 518 | refStr, stringValue */
        "movl %esi, -0x40(%ebp)\n" /* stringValue */
        "movl %esi, %eax\n" /* stringValue */
        "andl $0xc000, %eax\n"
        "cmpl $0x8000, %eax\n"
        "je .Lf43a06_00043c21\n"
        "testl %eax, %eax\n" /* line 601 */
        "je .Lf43a06_00043bcf\n"
        "movl -0x40(%ebp), %edx\n" /* line 615 */
        "andl $0x3fff, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* next */
        "movl %edx, %ebx\n" /* refStr */
        "jmp .Lf43a06_00043ada\n"
        ".Lf43a06_00043ad8:\n"
        "movl %eax, %ebx\n" /* line 617 | refStr */
        ".Lf43a06_00043ada:\n"
        "movzwl scrStringGlob(, %ebx, 4), %eax\n"
        "andl $0x3fff, %eax\n"
        "cmpl %eax, -0x30(%ebp)\n" /* hash */
        "jne .Lf43a06_00043ad8\n"
        "movzwl scrStringGlob, %eax\n" /* line 622 */
        "movzwl %ax, %edi\n" /* newIndex */
        "testw %ax, %ax\n" /* line 623 */
        "je .Lf43a06_00043dee\n"
        ".Lf43a06_00043aff:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 632 | type */
        "movl %ecx, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* len */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MT_AllocIndex\n"
        "movzwl %ax, %esi\n" /* stringValue */
        "leal (, %edi, 4), %ecx\n" /* line 634 */
        "movzwl scrStringGlob(%ecx), %eax\n" /* line 637 */
        "andl $0x3fff, %eax\n"
        "movw %ax, scrStringGlob\n" /* line 638 */
        "movl $scrStringGlob, %edx\n" /* line 639 */
        "movw $0, 2(%edx, %eax, 4)\n"
        "movzwl scrStringGlob(, %ebx, 4), %eax\n" /* line 641 */
        "andw $0xc000, %ax\n"
        "orl %edi, %eax\n" /* newIndex */
        "movw %ax, scrStringGlob(, %ebx, 4)\n"
        "movl -0x34(%ebp), %eax\n" /* line 643 | next */
        "orb $0x40, %ah\n"
        "movw %ax, scrStringGlob(%ecx)\n"
        "movl -0x38(%ebp), %edx\n" /* line 644 | entry */
        "movzwl 2(%edx), %eax\n"
        "movw %ax, scrStringGlob+2(%ecx)\n"
        "movl %edx, %ecx\n"
        ".Lf43a06_00043b6f:\n"
        "movl -0x30(%ebp), %eax\n" /* line 648 | hash */
        "orw $0x8000, %ax\n"
        "movw %ax, (%ecx)\n"
        ".Lf43a06_00043b79:\n"
        "movl -0x38(%ebp), %eax\n" /* line 652 | entry */
        "movw %si, 2(%eax)\n" /* stringValue */
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "leal (%eax, %esi, 8), %ebx\n"
        "leal 4(%ebx), %eax\n" /* line 655 | refStr */
        "movl 0x10(%ebp), %edx\n" /* len */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* str */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movzbl 0xc(%ebp), %eax\n" /* line 657 | user */
        "movb %al, 1(%ebx)\n" /* refStr */
        "movw $1, 2(%ebx)\n" /* line 659 | refStr */
        "movzbl -0x2c(%ebp), %edx\n" /* line 660 | byteLen */
        "movb %dl, (%ebx)\n" /* refStr */
        /* } scope */
        ".Lf43a06_00043bb6:\n"
        "movl %esi, %eax\n" /* line 682 | stringValue */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf43a06_00043bc0:\n"
        "xorl %edx, %edx\n" /* line 226 */
        ".Lf43a06_00043bc2:\n"
        "addl $1, %edx\n" /* line 235 */
        "movl %edx, -0x30(%ebp)\n" /* hash */
        "movl %edx, %ebx\n" /* hash */
        "jmp .Lf43a06_00043a91\n"
        /* } scope */
        ".Lf43a06_00043bcf:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 603 | type */
        "movl %ecx, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* len */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MT_AllocIndex\n"
        "movzwl %ax, %esi\n" /* stringValue */
        "movl -0x38(%ebp), %eax\n" /* line 605 | entry */
        "movzwl 2(%eax), %ecx\n"
        "movzwl scrStringGlob(%ebx), %edx\n" /* line 606 | refStr */
        "andl $0x3fff, %edx\n"
        "movzwl scrStringGlob(, %ecx, 4), %eax\n" /* line 608 */
        "andw $0xc000, %ax\n"
        "orl %edx, %eax\n"
        "movw %ax, scrStringGlob(, %ecx, 4)\n"
        "movw %cx, scrStringGlob+2(, %edx, 4)\n" /* line 609 */
        "movl -0x38(%ebp), %ecx\n" /* entry */
        "jmp .Lf43a06_00043b6f\n"
        ".Lf43a06_00043c21:\n"
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movzwl 2(%edx), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x28(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n"
        "movzbl (%ebx), %eax\n" /* line 521 | refStr */
        "cmpl %eax, %ecx\n"
        "je .Lf43a06_00043e11\n"
        ".Lf43a06_00043c43:\n"
        "movl -0x40(%ebp), %esi\n" /* line 538 | stringValue */
        "andl $0x3fff, %esi\n" /* stringValue */
        "movl %esi, -0x24(%ebp)\n" /* stringValue */
        "leal scrStringGlob(, %esi, 4), %ebx\n" /* line 539 | refStr */
        "cmpl %ebx, -0x38(%ebp)\n" /* line 540 | refStr, entry */
        "je .Lf43a06_00043d45\n"
        "movl -0x30(%ebp), %eax\n" /* hash */
        "movl %eax, -0x20(%ebp)\n"
        "jmp .Lf43a06_00043c88\n"
        ".Lf43a06_00043c67:\n"
        "movzwl (%ebx), %eax\n" /* line 570 | refStr */
        "andl $0x3fff, %eax\n"
        "leal scrStringGlob(, %eax, 4), %ebx\n" /* line 571 | refStr */
        "cmpl %ebx, -0x38(%ebp)\n" /* line 540 | refStr, entry */
        "je .Lf43a06_00043d45\n"
        "movl -0x24(%ebp), %esi\n" /* stringValue */
        "movl %esi, -0x20(%ebp)\n" /* stringValue */
        "movl %eax, -0x24(%ebp)\n"
        ".Lf43a06_00043c88:\n"
        "movzwl 2(%ebx), %edx\n" /* line 139 */
        "movl %edx, -0x3c(%ebp)\n"
        "movl -0x28(%ebp), %ecx\n"
        "leal (%ecx, %edx, 8), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movzbl (%ecx), %eax\n" /* line 545 */
        "cmpl %eax, -0x2c(%ebp)\n" /* byteLen */
        "jne .Lf43a06_00043c67\n"
        "addl $4, %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "cld\n"
        "movl 0x10(%ebp), %esi\n" /* len, stringValue */
        "cmpl %esi, %esi\n" /* stringValue */
        "movl %ecx, %esi\n" /* stringValue */
        "movl 8(%ebp), %edi\n" /* str, newIndex */
        "movl 0x10(%ebp), %ecx\n" /* len */
        "repe cmpsb %es:(%edi), (%esi)\n" /* newIndex, stringValue */
        "movl $0, %eax\n"
        "je .Lf43a06_00043cc7\n"
        "movzbl -1(%esi), %eax\n" /* stringValue */
        "movzbl -1(%edi), %ecx\n" /* newIndex */
        "subl %ecx, %eax\n"
        ".Lf43a06_00043cc7:\n"
        "testl %eax, %eax\n"
        "jne .Lf43a06_00043c67\n"
        "movl -0x20(%ebp), %ecx\n" /* line 548 */
        "movzwl scrStringGlob(, %ecx, 4), %eax\n"
        "andw $0xc000, %ax\n"
        "movzwl (%ebx), %edx\n" /* refStr */
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movw %ax, scrStringGlob(, %ecx, 4)\n"
        "movzwl (%ebx), %eax\n" /* line 549 | refStr */
        "andw $0xc000, %ax\n"
        "movl -0x38(%ebp), %esi\n" /* entry, stringValue */
        "movzwl (%esi), %edx\n" /* stringValue */
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movw %ax, (%ebx)\n" /* refStr */
        "movzwl (%esi), %eax\n" /* line 550 | stringValue */
        "andw $0xc000, %ax\n"
        "orl -0x24(%ebp), %eax\n"
        "movw %ax, (%esi)\n" /* stringValue */
        "movl -0x3c(%ebp), %esi\n" /* line 551 | stringValue */
        "movl -0x38(%ebp), %edx\n" /* line 552 | entry */
        "movzwl 2(%edx), %eax\n"
        "movw %ax, 2(%ebx)\n" /* refStr */
        "movw %si, 2(%edx)\n" /* line 553 | stringValue */
        "movl -0x1c(%ebp), %ecx\n" /* line 455 */
        "movzbl 1(%ecx), %edx\n"
        "movzbl %dl, %eax\n"
        "testl %eax, 0xc(%ebp)\n" /* user */
        "jne .Lf43a06_00043bb6\n"
        "orb 0xc(%ebp), %dl\n" /* line 476 | user */
        "movb %dl, 1(%ecx)\n"
        "addw $1, 2(%ecx)\n" /* line 477 */
        "jmp .Lf43a06_00043bb6\n"
        ".Lf43a06_00043d45:\n"
        "movzwl scrStringGlob, %eax\n" /* line 574 */
        "movzwl %ax, %ebx\n" /* refStr */
        "testw %ax, %ax\n" /* line 575 */
        "je .Lf43a06_00043dcb\n"
        ".Lf43a06_00043d54:\n"
        "movl 0x14(%ebp), %eax\n" /* line 584 | type */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* len */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MT_AllocIndex\n"
        "movzwl %ax, %esi\n" /* stringValue */
        "leal (, %ebx, 4), %ecx\n" /* line 586 */
        "movzwl scrStringGlob(%ecx), %eax\n" /* line 589 */
        "andl $0x3fff, %eax\n"
        "movw %ax, scrStringGlob\n" /* line 590 */
        "movl $scrStringGlob, %edx\n" /* line 591 */
        "movw $0, 2(%edx, %eax, 4)\n"
        "movl -0x38(%ebp), %edx\n" /* line 593 | entry */
        "movzwl (%edx), %eax\n"
        "andw $0x3fff, %ax\n"
        "orb $0x40, %ah\n"
        "movw %ax, scrStringGlob(%ecx)\n"
        "movzwl (%edx), %eax\n" /* line 594 */
        "andw $0xc000, %ax\n"
        "movl %ebx, %edx\n" /* refStr */
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movl -0x38(%ebp), %edx\n" /* entry */
        "movw %ax, (%edx)\n"
        "movzwl 2(%edx), %eax\n" /* line 597 */
        "movw %ax, scrStringGlob+2(%ecx)\n"
        "jmp .Lf43a06_00043b79\n"
        ".Lf43a06_00043dcb:\n"
        "calll Scr_DumpScriptThreads\n" /* line 578 */
        "calll Scr_DumpScriptVariables\n" /* line 579 */
        "movl $str_00217bd0, 4(%esp)\n" /* line 581 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf43a06_00043d54\n"
        ".Lf43a06_00043dee:\n"
        "calll Scr_DumpScriptThreads\n" /* line 626 */
        "calll Scr_DumpScriptVariables\n" /* line 627 */
        "movl $str_00217bd0, 4(%esp)\n" /* line 629 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf43a06_00043aff\n"
        ".Lf43a06_00043e11:\n"
        "leal 4(%ebx), %ecx\n" /* line 521 | refStr */
        "movl %ecx, -0x4c(%ebp)\n"
        "cld\n"
        "movl 0x10(%ebp), %esi\n" /* len, stringValue */
        "cmpl %esi, %esi\n" /* stringValue */
        "movl %ecx, %esi\n" /* stringValue */
        "movl 8(%ebp), %edi\n" /* str, newIndex */
        "movl 0x10(%ebp), %ecx\n" /* len */
        "repe cmpsb %es:(%edi), (%esi)\n" /* newIndex, stringValue */
        "movl $0, %eax\n"
        "je .Lf43a06_00043e38\n"
        "movzbl -1(%esi), %eax\n" /* stringValue */
        "movzbl -1(%edi), %ecx\n" /* newIndex */
        "subl %ecx, %eax\n"
        ".Lf43a06_00043e38:\n"
        "testl %eax, %eax\n"
        "jne .Lf43a06_00043c43\n"
        "movzbl 1(%ebx), %edx\n" /* line 455 | hash */
        "movzbl %dl, %eax\n"
        "testl %eax, 0xc(%ebp)\n" /* user */
        "jne .Lf43a06_00043e68\n"
        "orb 0xc(%ebp), %dl\n" /* line 476 | user */
        "movb %dl, 1(%ebx)\n" /* hash */
        "addw $1, 2(%ebx)\n" /* line 477 | hash */
        "movl -0x38(%ebp), %ecx\n" /* entry */
        "movzwl 2(%ecx), %ecx\n"
        "movl %ecx, -0x44(%ebp)\n"
        "movl %ecx, %esi\n"
        "jmp .Lf43a06_00043bb6\n"
        ".Lf43a06_00043e68:\n"
        "movl -0x44(%ebp), %esi\n"
        "jmp .Lf43a06_00043bb6\n"
    );
}

/* line 719 */
__attribute__((naked))
unsigned int SL_GetLowercaseString_(const char *str, unsigned int user, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 719 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x201c, %esp\n"
        "movl 8(%ebp), %esi\n" /* str */
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* str, i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        /* { scope 1 */
        "cmpl $0x2000, %ebx\n" /* line 704 */
        "ja .Lf43e70_00043ee8\n"
        "testl %ebx, %ebx\n" /* line 710 */
        "jne .Lf43e70_00043ec6\n"
        ".Lf43e70_00043e9b:\n"
        "movl 0x10(%ebp), %eax\n" /* line 715 | type */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* user */
        "movl %eax, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* newStr */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        /* } scope */
        "addl $0x201c, %esp\n" /* line 722 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf43e70_00043ec6:\n"
        "xorl %edi, %edi\n" /* line 707 | i */
        "xorl %eax, %eax\n"
        ".Lf43e70_00043eca:\n"
        "movsbl (%esi, %eax), %eax\n" /* line 711 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, -0x2018(%edi, %ebp)\n" /* i */
        "addl $1, %edi\n" /* line 710 | i */
        "movl %edi, %eax\n" /* i */
        "cmpl %edi, %ebx\n" /* i */
        "ja .Lf43e70_00043eca\n"
        "jmp .Lf43e70_00043e9b\n"
        ".Lf43e70_00043ee8:\n"
        "movl %esi, 8(%esp)\n" /* line 707 */
        "movl $str_00217bfc, 4(%esp)\n" /* "max string length exceeded: "%s"" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x201c, %esp\n" /* line 722 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 685 */
__attribute__((naked))
unsigned int SL_GetString_(const char *str, unsigned int user, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 685 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* str */
        "movl 0x10(%ebp), %eax\n" /* line 687 | type */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, %edi\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* user */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        "addl $0x14, %esp\n" /* line 688 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 935 */
__attribute__((naked))
unsigned int SL_RemoveRefToString(unsigned int stringValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 935 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "movl 8(%ebp), %edx\n" /* stringValue */
        "leal (%eax, %edx, 8), %ebx\n"
        /* { scope 2 */
        "movzbl (%ebx), %eax\n" /* line 182 */
        "subb $1, %al\n"
        "movzbl %al, %ecx\n"
        "cmpb $0, 4(%ebx, %ecx)\n" /* line 184 */
        "jne .Lf43f48_00044082\n"
        /* } scope */
        ".Lf43f48_00043f71:\n"
        "addl $1, %ecx\n" /* line 943 */
        "movl %ecx, -0x1c(%ebp)\n"
        "movzwl 2(%ebx), %eax\n" /* line 1007 | refStr */
        "subl $1, %eax\n"
        "movw %ax, 2(%ebx)\n" /* refStr */
        "testw %ax, %ax\n" /* line 1008 */
        "jne .Lf43f48_0004407a\n"
        /* { scope 2 */
        "leal 4(%ebx), %eax\n" /* line 855 | newIndex */
        /* { scope 3 */
        "cmpl $0xff, -0x1c(%ebp)\n" /* line 222 */
        "jbe .Lf43f48_000440a2\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 238 */
        "shrl $2, %ecx\n"
        "movl $0x40011, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "subl %eax, %ecx\n"
        "leal 1(%ecx), %ebx\n" /* hash */
        /* } scope */
        ".Lf43f48_00043fc1:\n"
        "leal (, %ebx, 4), %edx\n" /* line 859 */
        "movl %edx, -0x20(%ebp)\n"
        "movl %edx, %edi\n" /* newEntry */
        "addl $scrStringGlob, %edi\n" /* newEntry */
        "movl -0x1c(%ebp), %eax\n" /* line 877 */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* stringValue */
        "movl %eax, (%esp)\n"
        "calll MT_FreeIndex\n"
        "movl -0x20(%ebp), %edx\n" /* line 881 */
        "movzwl scrStringGlob(%edx), %esi\n"
        "andl $0x3fff, %esi\n"
        "leal (, %esi, 4), %edx\n" /* line 882 */
        "leal scrStringGlob(%edx), %ecx\n"
        "movzwl 2(%edi), %eax\n" /* line 884 | newEntry */
        "cmpl %eax, 8(%ebp)\n" /* stringValue */
        "je .Lf43f48_000440f8\n"
        "movzwl 2(%ecx), %eax\n" /* line 905 */
        "cmpl %eax, 8(%ebp)\n" /* stringValue */
        "jne .Lf43f48_00044022\n"
        "jmp .Lf43f48_00044130\n"
        ".Lf43f48_00044020:\n"
        "movl %ebx, %esi\n" /* line 908 | newIndex */
        ".Lf43f48_00044022:\n"
        "movzwl (%ecx), %ebx\n" /* line 912 | newIndex */
        "andl $0x3fff, %ebx\n" /* newIndex */
        "leal scrStringGlob(, %ebx, 4), %ecx\n" /* line 913 */
        "movzwl 2(%ecx), %eax\n" /* line 905 */
        "cmpl %eax, 8(%ebp)\n" /* stringValue */
        "jne .Lf43f48_00044020\n"
        ".Lf43f48_0004403b:\n"
        "movzwl scrStringGlob(, %esi, 4), %eax\n" /* line 907 */
        "andw $0xc000, %ax\n"
        "movzwl (%ecx), %edx\n"
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movw %ax, scrStringGlob(, %esi, 4)\n"
        "movl %ecx, %edi\n" /* newEntry */
        ".Lf43f48_0004405b:\n"
        "movzwl scrStringGlob, %eax\n" /* line 919 */
        "movw %ax, (%edi)\n" /* line 921 | newEntry */
        "movw $0, 2(%edi)\n" /* line 922 | newEntry */
        "movw %bx, scrStringGlob+2(, %eax, 4)\n" /* line 924 | newIndex */
        "movw %bx, scrStringGlob\n" /* line 925 | newIndex */
        /* } scope */
        /* } scope */
        ".Lf43f48_0004407a:\n"
        "addl $0x2c, %esp\n" /* line 948 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf43f48_00044082:\n"
        "leal 4(%ebx, %ecx), %edx\n" /* line 1008 | refStr */
        /* { scope 2 */
        ".Lf43f48_00044086:\n"
        "addl $0x100, %ecx\n" /* line 182 */
        "movzbl 0x100(%edx), %eax\n" /* line 184 */
        "addl $0x100, %edx\n"
        "testb %al, %al\n"
        "jne .Lf43f48_00044086\n"
        "jmp .Lf43f48_00043f71\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf43f48_000440a2:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 226 */
        "testl %esi, %esi\n"
        "je .Lf43f48_000440ee\n"
        "movl %eax, %ecx\n" /* line 222 */
        "xorl %ebx, %ebx\n" /* hash */
        "movl -0x1c(%ebp), %eax\n"
        "leal (%ecx, %eax), %esi\n"
        ".Lf43f48_000440b3:\n"
        "movl %ebx, %eax\n" /* line 229 | hash */
        "shll $5, %eax\n"
        "subl %ebx, %eax\n" /* hash */
        "movsbl (%ecx), %edx\n" /* line 230 */
        "leal (%edx, %eax), %ebx\n" /* hash */
        "addl $1, %ecx\n" /* line 231 */
        "cmpl %ecx, %esi\n" /* line 226 */
        "jne .Lf43f48_000440b3\n"
        "movl $0x40011, %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "mull %edx\n"
        "movl %ebx, %eax\n" /* hash */
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "movl %ebx, %edx\n" /* hash */
        "subl %eax, %edx\n"
        "leal 1(%edx), %ebx\n" /* line 235 | hash */
        "jmp .Lf43f48_00043fc1\n"
        ".Lf43f48_000440ee:\n"
        "xorl %edx, %edx\n" /* line 226 */
        "leal 1(%edx), %ebx\n" /* line 235 | hash */
        "jmp .Lf43f48_00043fc1\n"
        /* } scope */
        ".Lf43f48_000440f8:\n"
        "cmpl %ecx, %edi\n" /* line 886 | newEntry */
        "je .Lf43f48_0004405b\n"
        "movzwl scrStringGlob(%edx), %eax\n" /* line 888 */
        "andw $0x3fff, %ax\n"
        "orw $0x8000, %ax\n"
        "movl -0x20(%ebp), %edx\n"
        "movw %ax, scrStringGlob(%edx)\n"
        "movzwl 2(%ecx), %eax\n" /* line 889 */
        "movw %ax, 2(%edi)\n" /* newEntry */
        "movl %edi, scrStringGlob+65540\n" /* line 890 | newEntry */
        "movl %esi, %ebx\n" /* newIndex */
        "movl %ecx, %edi\n" /* newEntry */
        "jmp .Lf43f48_0004405b\n"
        ".Lf43f48_00044130:\n"
        "movl %esi, %eax\n" /* line 891 */
        "movl %ebx, %esi\n" /* newIndex */
        "movl %eax, %ebx\n" /* newIndex */
        "jmp .Lf43f48_0004403b\n"
    );
}

/* line 1094 */
__attribute__((naked))
unsigned int SL_ShutdownSystem(unsigned int user)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1094 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl $1, %esi\n"
        "movzbl 8(%ebp), %eax\n" /* user */
        "notb %al\n"
        "movl %eax, %edi\n"
        /* { scope 1 */
        ".Lf4413c_00044152:\n"
        "leal (, %esi, 4), %eax\n" /* line 1110 */
        "leal scrStringGlob(%eax), %ebx\n" /* entry */
        "testw $0xc000, scrStringGlob(%eax)\n" /* line 1111 */
        "je .Lf4413c_000441a9\n"
        "movzwl 2(%ebx), %eax\n" /* line 139 */
        "movl imp_scrMemTreePub, %ecx\n"
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 8), %ecx\n"
        "movzbl 1(%ecx), %edx\n" /* line 1115 */
        "movzbl %dl, %eax\n"
        "testl %eax, 8(%ebp)\n" /* user */
        "je .Lf4413c_000441a9\n"
        "andl %edi, %edx\n" /* line 1118 */
        "movb %dl, 1(%ecx)\n"
        "movl $0, scrStringGlob+65540\n" /* line 1119 */
        "movzwl 2(%ebx), %eax\n" /* line 1120 | entry */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl scrStringGlob+65540, %eax\n" /* line 1108 */
        "testl %eax, %eax\n"
        "jne .Lf4413c_00044152\n"
        ".Lf4413c_000441a9:\n"
        "addl $1, %esi\n" /* line 1106 | hash */
        "cmpl $0x4000, %esi\n" /* hash */
        "jne .Lf4413c_00044152\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1127 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1040 */
__attribute__((naked))
unsigned int Scr_SetString(scr_string_t *to, unsigned int from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1040 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* to */
        "movl 0xc(%ebp), %ebx\n" /* from */
        "testl %ebx, %ebx\n" /* line 1042 | from */
        "je .Lf441bc_000441db\n"
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "addw $1, 2(%eax, %ebx, 8)\n" /* line 832 */
        ".Lf441bc_000441db:\n"
        "movzwl (%esi), %eax\n" /* line 1044 | to */
        "testw %ax, %ax\n"
        "je .Lf441bc_000441ee\n"
        "movzwl %ax, %eax\n" /* line 1045 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        ".Lf441bc_000441ee:\n"
        "movw %bx, (%esi)\n" /* line 1046 | from, to */
        "addl $0x10, %esp\n" /* line 1047 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 731 */
__attribute__((naked))
unsigned int SL_ConvertToLowercase(unsigned int stringValue, unsigned int user, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 731 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        "movl 8(%ebp), %edi\n" /* stringValue */
        /* { scope 1 */
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "leal (%eax, %edi, 8), %ebx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movzbl (%ebx), %eax\n" /* line 182 */
        "subb $1, %al\n"
        "movzbl %al, %ecx\n"
        "cmpb $0, 4(%ebx, %ecx)\n" /* line 184 */
        "jne .Lf441f8_00044276\n"
        /* } scope */
        /* } scope */
        ".Lf441f8_00044220:\n"
        "leal 1(%ecx), %esi\n" /* line 741 */
        "cmpl $0x2000, %esi\n" /* line 742 */
        "ja .Lf441f8_00044269\n"
        "testl %edi, %edi\n" /* line 156 */
        "jne .Lf441f8_00044293\n"
        "movl $0, -0x201c(%ebp)\n" /* str */
        "testl %esi, %esi\n" /* line 747 */
        "jne .Lf441f8_000442a0\n"
        ".Lf441f8_0004423d:\n"
        "movl 0x10(%ebp), %eax\n" /* line 750 | type */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* user */
        "movl %edx, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* newStr */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        "movl %eax, %ebx\n" /* newStringValue */
        "movl %edi, (%esp)\n" /* line 751 | stringValue */
        "calll SL_RemoveRefToString\n"
        "movl %ebx, %edi\n" /* newStringValue, stringValue */
        /* } scope */
        ".Lf441f8_00044269:\n"
        "movl %edi, %eax\n" /* line 756 | stringValue */
        "addl $0x202c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf441f8_00044276:\n"
        "leal 4(%ebx, %ecx), %edx\n" /* line 742 | newStringValue */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf441f8_0004427a:\n"
        "addl $0x100, %ecx\n" /* line 182 */
        "movzbl 0x100(%edx), %eax\n" /* line 184 */
        "addl $0x100, %edx\n"
        "testb %al, %al\n"
        "jne .Lf441f8_0004427a\n"
        "jmp .Lf441f8_00044220\n"
        /* } scope */
        /* } scope */
        ".Lf441f8_00044293:\n"
        "addl $4, %ebx\n" /* line 156 */
        "movl %ebx, -0x201c(%ebp)\n" /* str */
        "testl %esi, %esi\n" /* line 747 */
        "je .Lf441f8_0004423d\n"
        ".Lf441f8_000442a0:\n"
        "xorl %ebx, %ebx\n" /* newStringValue */
        "xorl %eax, %eax\n"
        ".Lf441f8_000442a4:\n"
        "movl -0x201c(%ebp), %edx\n" /* line 748 | str */
        "movsbl (%edx, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, -0x2018(%ebx, %ebp)\n" /* newStringValue */
        "addl $1, %ebx\n" /* line 747 | newStringValue */
        "movl %ebx, %eax\n" /* newStringValue */
        "cmpl %ebx, %esi\n" /* newStringValue */
        "ja .Lf441f8_000442a4\n"
        "jmp .Lf441f8_0004423d\n"
    );
}

/* line 1130 */
__attribute__((naked))
unsigned int Scr_ShutdownGameStrings(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1130 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl $1, %ebx\n" /* hash */
        "movl imp_scrMemTreePub, %esi\n"
        /* { scope 1 */
        ".Lf442cc_000442df:\n"
        "leal (, %ebx, 4), %eax\n" /* line 1110 */
        "leal scrStringGlob(%eax), %ecx\n"
        "testw $0xc000, scrStringGlob(%eax)\n" /* line 1111 */
        "je .Lf442cc_0004432c\n"
        "movzwl 2(%ecx), %edx\n" /* line 139 */
        "movl (%esi), %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movzbl 1(%edx), %eax\n" /* line 1115 */
        "testb $1, %al\n"
        "je .Lf442cc_0004432c\n"
        "andb $0xfe, %al\n" /* line 1118 */
        "movb %al, 1(%edx)\n"
        "movl $0, scrStringGlob+65540\n" /* line 1119 */
        "movzwl 2(%ecx), %eax\n" /* line 1120 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl scrStringGlob+65540, %eax\n" /* line 1108 */
        "testl %eax, %eax\n"
        "jne .Lf442cc_000442df\n"
        ".Lf442cc_0004432c:\n"
        "addl $1, %ebx\n" /* line 1106 | hash */
        "cmpl $0x4000, %ebx\n" /* hash */
        "jne .Lf442cc_000442df\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 287 */
__attribute__((naked))
unsigned int SL_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 287 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "cmpb $0, scrStringGlob+65536\n" /* line 289 */
        "je .Lf4433e_0004461b\n"
        "movl $1, -0x1c(%ebp)\n"
        "jmp .Lf4433e_00044375\n"
        ".Lf4433e_0004435d:\n"
        "movw $1, 2(%edi)\n" /* line 962 */
        "movb $4, 1(%edi)\n" /* line 963 */
        "movl scrStringGlob+65540, %ecx\n" /* line 1189 */
        "testl %ecx, %ecx\n"
        "je .Lf4433e_000444b3\n"
        ".Lf4433e_00044375:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1191 */
        "shll $2, %eax\n"
        "leal scrStringGlob(%eax), %edx\n"
        "testw $0xc000, scrStringGlob(%eax)\n" /* line 1192 */
        "je .Lf4433e_000444b3\n"
        "movl $0, scrStringGlob+65540\n" /* line 1195 */
        "movzwl 2(%edx), %edx\n" /* line 1196 */
        "movl %edx, -0x28(%ebp)\n"
        "movl imp_scrMemTreePub, %eax\n" /* line 139 */
        "movl (%eax), %eax\n"
        "leal (%eax, %edx, 8), %edi\n"
        "testb $4, 1(%edi)\n" /* line 960 */
        "jne .Lf4433e_0004435d\n"
        "movw $0, 2(%edi)\n" /* line 977 */
        "movb $0, 1(%edi)\n" /* line 978 */
        "movzbl (%edi), %eax\n" /* line 182 */
        "subb $1, %al\n"
        "movzbl %al, %ecx\n"
        "cmpb $0, 4(%edi, %ecx)\n" /* line 184 */
        "jne .Lf4433e_00044574\n"
        ".Lf4433e_000443ce:\n"
        "addl $1, %ecx\n" /* line 982 */
        "movl %ecx, -0x2c(%ebp)\n"
        "leal 4(%edi), %eax\n" /* line 855 */
        "cmpl $0xff, %ecx\n" /* line 222 */
        "ja .Lf4433e_00044549\n"
        "movl -0x2c(%ebp), %edx\n" /* line 226 */
        "testl %edx, %edx\n"
        "jne .Lf4433e_000445ca\n"
        "xorl %edx, %edx\n"
        ".Lf4433e_000443f0:\n"
        "leal 1(%edx), %ebx\n" /* line 235 */
        ".Lf4433e_000443f3:\n"
        "leal (, %ebx, 4), %esi\n" /* line 859 */
        "leal scrStringGlob(%esi), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 877 */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll MT_FreeIndex\n"
        "movzwl scrStringGlob(%esi), %ecx\n" /* line 881 */
        "andl $0x3fff, %ecx\n"
        "leal (, %ecx, 4), %edx\n" /* line 882 */
        "leal scrStringGlob(%edx), %edi\n"
        "movl -0x20(%ebp), %eax\n" /* line 884 */
        "movzwl 2(%eax), %eax\n"
        "cmpl %eax, -0x28(%ebp)\n"
        "je .Lf4433e_00044594\n"
        "movzwl 2(%edi), %eax\n" /* line 905 */
        "cmpl -0x28(%ebp), %eax\n"
        "je .Lf4433e_00044466\n"
        ".Lf4433e_0004444b:\n"
        "movl %ecx, %ebx\n" /* line 908 */
        "movzwl (%edi), %ecx\n" /* line 912 */
        "andl $0x3fff, %ecx\n"
        "leal scrStringGlob(, %ecx, 4), %edi\n" /* line 913 */
        "movzwl 2(%edi), %eax\n" /* line 905 */
        "cmpl -0x28(%ebp), %eax\n"
        "jne .Lf4433e_0004444b\n"
        ".Lf4433e_00044466:\n"
        "movl $scrStringGlob, %esi\n" /* line 907 */
        "movzwl scrStringGlob(, %ebx, 4), %eax\n"
        "andw $0xc000, %ax\n"
        "movzwl (%edi), %edx\n"
        "andw $0x3fff, %dx\n"
        "orl %edx, %eax\n"
        "movw %ax, scrStringGlob(, %ebx, 4)\n"
        ".Lf4433e_00044489:\n"
        "movzwl scrStringGlob, %eax\n" /* line 919 */
        "movw %ax, (%edi)\n" /* line 921 */
        "movw $0, 2(%edi)\n" /* line 922 */
        "movw %cx, 2(%esi, %eax, 4)\n" /* line 924 */
        "movw %cx, scrStringGlob\n" /* line 925 */
        "movl scrStringGlob+65540, %ecx\n" /* line 1189 */
        "testl %ecx, %ecx\n"
        "jne .Lf4433e_00044375\n"
        ".Lf4433e_000444b3:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 1187 */
        "cmpl $0x4000, -0x1c(%ebp)\n"
        "jne .Lf4433e_00044375\n"
        "calll MT_InitForceAlloc\n" /* line 1200 */
        "movl %eax, -0x30(%ebp)\n"
        "movl $1, %esi\n"
        "movl $4, %ebx\n"
        "jmp .Lf4433e_00044513\n"
        ".Lf4433e_000444d8:\n"
        "xorl %edx, %edx\n" /* line 156 */
        ".Lf4433e_000444da:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl $4, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x30(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll MT_ForceAllocIndex\n"
        ".Lf4433e_00044501:\n"
        "addl $1, %esi\n" /* line 1203 */
        "addl $4, %ebx\n"
        "cmpl $0x4000, %esi\n"
        "je .Lf4433e_00044676\n"
        ".Lf4433e_00044513:\n"
        "testw $0xc000, scrStringGlob(%ebx)\n" /* line 1206 */
        "je .Lf4433e_00044501\n"
        "movzwl scrStringGlob+2(%ebx), %edx\n" /* line 1209 */
        "movzwl %dx, %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl imp_scrMemTreePub, %ecx\n" /* line 139 */
        "movl (%ecx), %eax\n"
        "movl -0x24(%ebp), %ecx\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "testb $4, 1(%eax)\n" /* line 1210 */
        "je .Lf4433e_00044501\n"
        "testw %dx, %dx\n" /* line 156 */
        "je .Lf4433e_000444d8\n"
        "leal 4(%eax), %edx\n"
        "jmp .Lf4433e_000444da\n"
        ".Lf4433e_00044549:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 238 */
        "shrl $2, %ecx\n"
        "movl $0x40011, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "subl %eax, %ecx\n"
        "leal 1(%ecx), %ebx\n"
        "jmp .Lf4433e_000443f3\n"
        ".Lf4433e_00044574:\n"
        "leal 4(%edi, %ecx), %edx\n" /* line 222 */
        ".Lf4433e_00044578:\n"
        "addl $0x100, %ecx\n" /* line 182 */
        "movzbl 0x100(%edx), %eax\n" /* line 184 */
        "addl $0x100, %edx\n"
        "testb %al, %al\n"
        "jne .Lf4433e_00044578\n"
        "jmp .Lf4433e_000443ce\n"
        ".Lf4433e_00044594:\n"
        "cmpl %edi, -0x20(%ebp)\n" /* line 886 */
        "je .Lf4433e_0004460c\n"
        "movzwl scrStringGlob(%edx), %eax\n" /* line 888 */
        "andw $0x3fff, %ax\n"
        "orw $0x8000, %ax\n"
        "movw %ax, scrStringGlob(%esi)\n"
        "movzwl 2(%edi), %eax\n" /* line 889 */
        "movl -0x20(%ebp), %edx\n"
        "movw %ax, 2(%edx)\n"
        "movl %edx, scrStringGlob+65540\n" /* line 890 */
        "movl $scrStringGlob, %esi\n"
        "jmp .Lf4433e_00044489\n"
        ".Lf4433e_000445ca:\n"
        "movl %eax, %ecx\n" /* line 184 */
        "xorl %ebx, %ebx\n"
        "movl -0x2c(%ebp), %eax\n"
        "leal (%eax, %ecx), %esi\n"
        ".Lf4433e_000445d4:\n"
        "movl %ebx, %eax\n" /* line 229 */
        "shll $5, %eax\n"
        "subl %ebx, %eax\n"
        "movsbl (%ecx), %edx\n" /* line 230 */
        "leal (%edx, %eax), %ebx\n"
        "addl $1, %ecx\n" /* line 231 */
        "cmpl %ecx, %esi\n" /* line 226 */
        "jne .Lf4433e_000445d4\n"
        "movl $0x40011, %edx\n"
        "movl %ebx, %eax\n"
        "mull %edx\n"
        "movl %ebx, %eax\n"
        "subl %edx, %eax\n"
        "shrl $1, %eax\n"
        "addl %eax, %edx\n"
        "shrl $0xd, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "jmp .Lf4433e_000443f0\n"
        ".Lf4433e_0004460c:\n"
        "movl %ebx, %ecx\n" /* line 905 */
        "movl -0x20(%ebp), %edi\n"
        "movl $scrStringGlob, %esi\n"
        "jmp .Lf4433e_00044489\n"
        ".Lf4433e_0004461b:\n"
        "calll MT_Init\n" /* line 252 */
        "movw $0, scrStringGlob\n" /* line 260 */
        "xorl %edx, %edx\n"
        "movl $1, %ecx\n"
        "movl $4, %ebx\n"
        "jmp .Lf4433e_0004463e\n"
        ".Lf4433e_00044637:\n"
        "movl %ecx, %edx\n" /* line 262 */
        "movl %eax, %ecx\n"
        "addl $4, %ebx\n"
        ".Lf4433e_0004463e:\n"
        "movw $0, scrStringGlob(%ebx)\n" /* line 266 */
        "orw %cx, scrStringGlob(, %edx, 4)\n" /* line 267 */
        "movw %dx, scrStringGlob+2(%ebx)\n" /* line 268 */
        "leal 1(%ecx), %eax\n" /* line 262 */
        "cmpl $0x4000, %eax\n"
        "jne .Lf4433e_00044637\n"
        "movw %cx, scrStringGlob+2\n" /* line 273 */
        "movb $1, scrStringGlob+65536\n" /* line 279 */
        ".Lf4433e_0004466e:\n"
        "addl $0x4c, %esp\n" /* line 296 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4433e_00044676:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1218 */
        "movl %eax, (%esp)\n"
        "calll MT_FinishForceAlloc\n"
        "jmp .Lf4433e_0004466e\n"
    );
}

/* line 1059 */
__attribute__((naked))
unsigned int Scr_AllocString(const char *s, int sys)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1059 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl $6, 0xc(%esp)\n" /* line 687 */
        "movl %edx, %edi\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        "addl $0x14, %esp\n" /* line 1064 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 691 */
__attribute__((naked))
unsigned int SL_GetString(const char *str, unsigned int user)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 691 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* str */
        "movl $6, 0xc(%esp)\n" /* line 687 */
        "movl %edx, %edi\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* user */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        "addl $0x14, %esp\n" /* line 694 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1067 */
__attribute__((naked))
unsigned int SL_GetStringForFloat(float f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1067 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x90, %esp\n"
        /* { scope 1 */
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 1071 | f */
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00217c20, 4(%esp)\n" /* "%g" */
        "leal -0x88(%ebp), %ebx\n" /* tempString */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl $0xe, 0xc(%esp)\n" /* line 687 */
        "movl %ebx, %edi\n" /* line 896 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        /* } scope */
        "addl $0x90, %esp\n" /* line 1073 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1076 */
__attribute__((naked))
unsigned int SL_GetStringForInt(int i)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1076 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x90, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1080 | i */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021785c, 4(%esp)\n" /* "%i" */
        "leal -0x88(%ebp), %ebx\n" /* tempString */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl $0xe, 0xc(%esp)\n" /* line 687 */
        "movl %ebx, %edi\n" /* line 896 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        /* } scope */
        "addl $0x90, %esp\n" /* line 1082 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1085 */
__attribute__((naked))
unsigned int SL_GetStringForVector(const float *v)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1085 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0xa0, %esp\n"
        "movl 8(%ebp), %eax\n" /* v */
        /* { scope 1 */
        "cvtss2sd 8(%eax), %xmm0\n" /* line 1089 */
        "movsd %xmm0, 0x18(%esp)\n"
        "cvtss2sd 4(%eax), %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "cvtss2sd (%eax), %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00217c24, 4(%esp)\n" /* "(%g, %g, %g)" */
        "leal -0x88(%ebp), %ebx\n" /* tempString */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl $0xe, 0xc(%esp)\n" /* line 687 */
        "movl %ebx, %edi\n" /* line 896 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        /* } scope */
        "addl $0xa0, %esp\n" /* line 1091 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1267 */
__attribute__((naked))
unsigned int Scr_CreateCanonicalFilename(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1267 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* filename */
        "leal -0x418(%ebp), %eax\n" /* newFilename */
        "movl %eax, -0x41c(%ebp)\n" /* newFilename */
        "movl $0x400, %esi\n"
        /* { scope 1: newFilename */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4482c_0004484c:\n"
        "movzbl (%ebx), %eax\n" /* line 1234 */
        "movsbl %al, %edi\n" /* c */
        "addl $1, %ebx\n" /* line 1235 */
        "cmpb $0x5c, %al\n" /* line 1237 */
        "je .Lf4482c_0004484c\n"
        "cmpb $0x2f, %al\n"
        "je .Lf4482c_0004484c\n"
        ".Lf4482c_0004485d:\n"
        "cmpl $0x1f, %edi\n" /* line 1240 | c */
        "ja .Lf4482c_000448b3\n"
        "testl %edi, %edi\n" /* line 1258 | c */
        "jne .Lf4482c_0004484c\n"
        "movl -0x41c(%ebp), %eax\n" /* line 1260 | newFilename */
        "movb $0, (%eax)\n"
        /* } scope */
        /* } scope */
        "movl $7, 0xc(%esp)\n" /* line 687 */
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x418(%ebp), %edi\n" /* newFilename */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* newFilename */
        "movl %edx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1273 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: newFilename */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4482c_000448ae:\n"
        "movl $0x2f, %edi\n" /* line 1237 | c */
        ".Lf4482c_000448b3:\n"
        "movl %edi, (%esp)\n" /* line 1242 | c */
        "calll ___tolower\n"
        "movl -0x41c(%ebp), %edx\n" /* newFilename */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n" /* line 1243 */
        "movl %edx, -0x41c(%ebp)\n" /* newFilename */
        "subl $1, %esi\n" /* line 1245 */
        "je .Lf4482c_000448ed\n"
        ".Lf4482c_000448d1:\n"
        "cmpl $0x2f, %edi\n" /* line 1248 | c */
        "je .Lf4482c_0004484c\n"
        "movzbl (%ebx), %eax\n" /* line 1251 */
        "movsbl %al, %edi\n" /* c */
        "addl $1, %ebx\n" /* line 1252 */
        "cmpb $0x5c, %al\n" /* line 1254 */
        "jne .Lf4482c_0004485d\n"
        "jmp .Lf4482c_000448ae\n"
        ".Lf4482c_000448ed:\n"
        "movl $0, 0xc(%esp)\n" /* line 1246 */
        "movl %ebx, 8(%esp)\n"
        "movl $str_00217c34, 4(%esp)\n" /* "Filename '%s' exceeds maximum length of %d" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf4482c_000448d1\n"
    );
}

