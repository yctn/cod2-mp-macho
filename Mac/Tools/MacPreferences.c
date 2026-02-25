/* ASM dump from: MacPreferences.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacPreferences.cp */

#include "common_types.h"
#include "imports.h"

bool MacPreferences_GetString(const char *inKey, char *outString, int inMaxString, const char *inDefault);
unsigned char MacPreferences_PutString(const char *inKey, const char *inString);
int MacPreferences_GetInteger(const char *inKey, int inDefault);
unsigned char MacPreferences_PutInteger(const char *inKey, int inNumber);
unsigned char MacPreferences_Synchronize(void);
unsigned char MacPreferences_PutRect(const char *inKey, const CGRect *inRect);
unsigned char MacPreferences_GetRect(const char *inKey, CGRect *outRect);
unsigned char MacPreferences_PutBoolean(const char *inKey, int inBoolean);
bool MacPreferences_GetBoolean(const char *inKey, int inDefault);

/* line 21 */
__attribute__((naked))
bool MacPreferences_GetString(const char *inKey, char *outString, int inMaxString, const char *inDefault)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 21 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* outString */
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 23 */
        "movl 8(%ebp), %eax\n" /* inKey */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithCString\n"
        "movl %eax, %ebx\n" /* keyRef */
        "movl kCFPreferencesCurrentApplication, %eax\n" /* line 25 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* keyRef */
        "calll CFPreferencesCopyAppValue\n"
        "movl %eax, %esi\n" /* stringRef */
        "movl %ebx, (%esp)\n" /* line 27 | keyRef */
        "calll CFRelease\n"
        "testl %esi, %esi\n" /* line 29 | stringRef */
        "je .Lf9964_000099c9\n"
        "movl %esi, (%esp)\n" /* line 31 | stringRef */
        "calll CFGetTypeID\n"
        "movl %eax, %ebx\n" /* keyRef */
        "calll CFStringGetTypeID\n"
        "cmpl %eax, %ebx\n" /* keyRef */
        "je .Lf9964_000099f6\n"
        ".Lf9964_000099c1:\n"
        "movl %esi, (%esp)\n" /* line 40 | stringRef */
        "calll CFRelease\n"
        ".Lf9964_000099c9:\n"
        "movl 0x14(%ebp), %eax\n" /* line 44 | inDefault */
        "testl %eax, %eax\n"
        "je .Lf9964_000099e9\n"
        "movl 0x14(%ebp), %eax\n" /* line 46 | inDefault */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outString */
        "calll strcpy\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf9964_000099e1:\n"
        "addl $0x1c, %esp\n" /* line 54 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9964_000099e9:\n"
        "movb $0, (%edi)\n" /* line 50 | outString */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 54 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9964_000099f6:\n"
        "movl $0, 0xc(%esp)\n" /* line 33 */
        "movl 0x10(%ebp), %eax\n" /* inMaxString */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* outString */
        "movl %esi, (%esp)\n" /* stringRef */
        "calll CFStringGetCString\n"
        "testb %al, %al\n"
        "je .Lf9964_000099c1\n"
        "movl %esi, (%esp)\n" /* line 35 | stringRef */
        "calll CFRelease\n"
        "movl $1, %eax\n"
        "jmp .Lf9964_000099e1\n"
    );
}

/* line 61 */
__attribute__((naked))
unsigned char MacPreferences_PutString(const char *inKey, const char *inString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 61 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* inString */
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 63 */
        "movl 8(%ebp), %eax\n" /* inKey */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithCString\n"
        "movl %eax, %esi\n" /* keyRef */
        "movl $0, 8(%esp)\n" /* line 64 */
        "movl %ebx, 4(%esp)\n" /* stringRef */
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithCString\n"
        "movl %eax, %ebx\n" /* stringRef */
        "movl kCFPreferencesCurrentApplication, %eax\n" /* line 66 */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* stringRef */
        "movl %esi, (%esp)\n" /* keyRef */
        "calll CFPreferencesSetAppValue\n"
        "movl %ebx, (%esp)\n" /* line 68 | stringRef */
        "calll CFRelease\n"
        "movl %esi, 8(%ebp)\n" /* line 69 | keyRef, inKey */
        /* } scope */
        "addl $0x10, %esp\n" /* line 70 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CFRelease\n" /* line 69 */
    );
}

/* line 77 */
__attribute__((naked))
int MacPreferences_GetInteger(const char *inKey, int inDefault)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x114, %esp\n"
        /* { scope 1 */
        "movl $0, 0xc(%esp)\n" /* line 80 */
        "movl $0x100, 8(%esp)\n"
        "leal -0x108(%ebp), %ebx\n" /* buffer */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inKey */
        "movl %eax, (%esp)\n"
        "calll MacPreferences_GetString\n"
        "cmpb $0, -0x108(%ebp)\n" /* line 83 | buffer */
        "jne .Lf9a94_00009ad8\n"
        "movl 0xc(%ebp), %eax\n" /* inDefault */
        /* } scope */
        "addl $0x114, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9a94_00009ad8:\n"
        "movl %ebx, (%esp)\n" /* line 85 */
        "calll atoi\n"
        /* } scope */
        "addl $0x114, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 100 */
__attribute__((naked))
unsigned char MacPreferences_PutInteger(const char *inKey, int inNumber)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 100 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x114, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 103 | inNumber */
        "movl %eax, 8(%esp)\n"
        "movl $0x215a64, 4(%esp)\n" /* "%d" */
        "leal -0x108(%ebp), %ebx\n" /* buffer */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl %ebx, 4(%esp)\n" /* line 105 */
        "movl 8(%ebp), %eax\n" /* inKey */
        "movl %eax, (%esp)\n"
        "calll MacPreferences_PutString\n"
        /* } scope */
        "addl $0x114, %esp\n" /* line 106 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 331 */
__attribute__((naked))
unsigned char MacPreferences_Synchronize(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 331 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl kCFPreferencesCurrentApplication, %eax\n" /* line 333 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CFPreferencesAppSynchronize\n"
        "leave\n" /* line 334 */
        "retl\n"
    );
}

/* line 244 */
__attribute__((naked))
unsigned char MacPreferences_PutRect(const char *inKey, const CGRect *inRect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 244 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x21c, %esp\n"
        /* { scope 1: buffer */
        "movl 8(%ebp), %eax\n" /* line 247 | inKey */
        "movl %eax, 4(%esp)\n"
        "leal -0x118(%ebp), %ebx\n" /* subKey */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 248 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x69726f2e, (%ecx)\n"
        "movl $0x2e6e6967, 4(%ecx)\n"
        "movw $0x78, 8(%ecx)\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 139 | inRect */
        "cvtss2sd (%eax), %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x215a68, 4(%esp)\n" /* "%f" */
        "leal -0x218(%ebp), %esi\n" /* buffer */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, 4(%esp)\n" /* line 141 */
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_PutString\n"
        /* } scope */
        "movl 8(%ebp), %edi\n" /* line 251 | inKey */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, %edi\n" /* line 252 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x69726f2e, (%ecx)\n"
        "movl $0x2e6e6967, 4(%ecx)\n"
        "movw $0x79, 8(%ecx)\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %edi\n" /* line 139 | inRect */
        "cvtss2sd 4(%edi), %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x215a68, 4(%esp)\n" /* "%f" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, 4(%esp)\n" /* line 141 */
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_PutString\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 255 | inKey */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 256 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x7a69732e, (%ecx)\n"
        "movl $0x69772e65, 4(%ecx)\n"
        "movl $0x687464, 8(%ecx)\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 139 | inRect */
        "cvtss2sd 8(%eax), %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x215a68, 4(%esp)\n" /* "%f" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, 4(%esp)\n" /* line 141 */
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_PutString\n"
        /* } scope */
        "movl 8(%ebp), %edi\n" /* line 259 | inKey */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 260 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x7a69732e, (%ecx)\n"
        "movl $0x65682e65, 4(%ecx)\n"
        "movl $0x74686769, 8(%ecx)\n"
        "movb $0, 0xc(%ecx)\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 139 | inRect */
        "cvtss2sd 0xc(%eax), %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x215a68, 4(%esp)\n" /* "%f" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, 4(%esp)\n" /* line 141 */
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_PutString\n"
        /* } scope */
        /* } scope */
        "addl $0x21c, %esp\n" /* line 262 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 219 */
__attribute__((naked))
unsigned char MacPreferences_GetRect(const char *inKey, CGRect *outRect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 219 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x23c, %esp\n"
        /* { scope 1: buffer */
        "movl 8(%ebp), %eax\n" /* line 222 | inKey */
        "movl %eax, 4(%esp)\n"
        "leal -0x118(%ebp), %ebx\n" /* subKey */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 223 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x69726f2e, (%ecx)\n"
        "movl $0x2e6e6967, 4(%ecx)\n"
        "movw $0x78, 8(%ecx)\n"
        /* { scope 2 */
        "movl $0, 0xc(%esp)\n" /* line 116 */
        "movl $0x100, 8(%esp)\n"
        "leal -0x218(%ebp), %esi\n" /* buffer */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_GetString\n"
        "pxor %xmm0, %xmm0\n" /* line 119 */
        "cmpb $0, -0x218(%ebp)\n" /* buffer */
        "jne .Lf9ce2_00009ef6\n"
        /* } scope */
        ".Lf9ce2_00009d5b:\n"
        "movl 0xc(%ebp), %eax\n" /* line 224 | outRect */
        "movss %xmm0, (%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 226 | inKey */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 227 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x69726f2e, (%ecx)\n"
        "movl $0x2e6e6967, 4(%ecx)\n"
        "movw $0x79, 8(%ecx)\n"
        /* { scope 2 */
        "movl $0, 0xc(%esp)\n" /* line 116 */
        "movl $0x100, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_GetString\n"
        "pxor %xmm0, %xmm0\n" /* line 119 */
        "cmpb $0, -0x218(%ebp)\n" /* buffer */
        "jne .Lf9ce2_00009edb\n"
        /* } scope */
        ".Lf9ce2_00009dc3:\n"
        "movl 0xc(%ebp), %eax\n" /* line 228 | outRect */
        "movss %xmm0, 4(%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 230 | inKey */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 231 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x7a69732e, (%ecx)\n"
        "movl $0x69772e65, 4(%ecx)\n"
        "movl $0x687464, 8(%ecx)\n"
        /* { scope 2 */
        "movl $0, 0xc(%esp)\n" /* line 116 */
        "movl $0x100, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_GetString\n"
        "pxor %xmm0, %xmm0\n" /* line 119 */
        "cmpb $0, -0x218(%ebp)\n" /* buffer */
        "jne .Lf9ce2_00009ec0\n"
        /* } scope */
        ".Lf9ce2_00009e2d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 232 | outRect */
        "movss %xmm0, 8(%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 234 | inKey */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 235 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x7a69732e, (%ecx)\n"
        "movl $0x65682e65, 4(%ecx)\n"
        "movl $0x74686769, 8(%ecx)\n"
        "movb $0, 0xc(%ecx)\n"
        /* { scope 2 */
        "movl $0, 0xc(%esp)\n" /* line 116 */
        "movl $0x100, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MacPreferences_GetString\n"
        "pxor %xmm0, %xmm0\n" /* line 119 */
        "cmpb $0, -0x218(%ebp)\n" /* buffer */
        "je .Lf9ce2_00009ead\n"
        "movl %esi, (%esp)\n" /* line 121 */
        "calll atof\n"
        "fstpl -0x220(%ebp)\n"
        "cvtsd2ss -0x220(%ebp), %xmm0\n"
        /* } scope */
        ".Lf9ce2_00009ead:\n"
        "movl 0xc(%ebp), %eax\n" /* line 236 | outRect */
        "movss %xmm0, 0xc(%eax)\n"
        /* } scope */
        "addl $0x23c, %esp\n" /* line 237 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        /* { scope 2 */
        ".Lf9ce2_00009ec0:\n"
        "movl %esi, (%esp)\n" /* line 121 */
        "calll atof\n"
        "fstpl -0x228(%ebp)\n"
        "cvtsd2ss -0x228(%ebp), %xmm0\n"
        "jmp .Lf9ce2_00009e2d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf9ce2_00009edb:\n"
        "movl %esi, (%esp)\n"
        "calll atof\n"
        "fstpl -0x230(%ebp)\n"
        "cvtsd2ss -0x230(%ebp), %xmm0\n"
        "jmp .Lf9ce2_00009dc3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf9ce2_00009ef6:\n"
        "movl %esi, (%esp)\n"
        "calll atof\n"
        "fstpl -0x238(%ebp)\n"
        "cvtsd2ss -0x238(%ebp), %xmm0\n"
        "jmp .Lf9ce2_00009d5b\n"
    );
}

/* line 159 */
__attribute__((naked))
unsigned char MacPreferences_PutBoolean(const char *inKey, int inBoolean)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x114, %esp\n"
        /* { scope 1 */
        "movzbl 0xc(%ebp), %eax\n" /* line 103 | inBoolean */
        "movl %eax, 8(%esp)\n"
        "movl $0x215a64, 4(%esp)\n" /* "%d" */
        "leal -0x108(%ebp), %ebx\n" /* buffer */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl %ebx, 4(%esp)\n" /* line 105 */
        "movl 8(%ebp), %eax\n" /* inKey */
        "movl %eax, (%esp)\n"
        "calll MacPreferences_PutString\n"
        /* } scope */
        "addl $0x114, %esp\n" /* line 162 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 149 */
__attribute__((naked))
bool MacPreferences_GetBoolean(const char *inKey, int inDefault)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 149 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x110, %esp\n"
        "movzbl 0xc(%ebp), %ebx\n" /* inDefault, result */
        /* { scope 1 */
        "movl $0, 0xc(%esp)\n" /* line 80 */
        "movl $0x100, 8(%esp)\n"
        "leal -0x108(%ebp), %esi\n" /* buffer */
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inKey */
        "movl %eax, (%esp)\n"
        "calll MacPreferences_GetString\n"
        "cmpb $0, -0x108(%ebp)\n" /* line 83 | buffer */
        "je .Lf9f54_00009f9b\n"
        "movl %esi, (%esp)\n" /* line 85 */
        "calll atoi\n"
        "movl %eax, %ebx\n" /* result */
        ".Lf9f54_00009f9b:\n"
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* result */
        "setne %al\n"
        /* } scope */
        "addl $0x110, %esp\n" /* line 152 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

