/* ASM dump from: com_shared.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_shared.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

int Com_HashKey(char *string, int maxlen);
int Com_RealTime(qtime_t *qtime);
long int Com_Memcpy(long int *dest, const long int *src, int count);
long int Com_Memset(long int *dest, const int val, int count);
Bool Com_Filter(const char *filter, const char *name, int casesensitive);
Bool Com_FilterPath(const char *filter, const char *name, int casesensitive);

/* line 184 */
__attribute__((naked))
int Com_HashKey(char *string, int maxlen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 184 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* string */
        "movl 0xc(%ebp), %esi\n" /* maxlen */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 189 | maxlen */
        "jle .Lf4880c_00048856\n"
        "movzbl (%edi), %eax\n" /* string */
        "testb %al, %al\n"
        "je .Lf4880c_00048856\n"
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n"
        ".Lf4880c_00048827:\n"
        "movsbl %al, %eax\n" /* line 191 */
        "leal 0x77(%ecx), %edx\n"
        "imull %edx, %eax\n"
        "addl %eax, %ebx\n"
        "addl $1, %ecx\n" /* line 189 */
        "cmpl %ecx, %esi\n" /* maxlen */
        "je .Lf4880c_00048841\n"
        "movzbl (%edi, %ecx), %eax\n" /* string */
        "testb %al, %al\n"
        "jne .Lf4880c_00048827\n"
        ".Lf4880c_00048841:\n"
        "movl %ebx, %edx\n"
        "sarl $0xa, %edx\n"
        "movl %ebx, %eax\n"
        "sarl $0x14, %eax\n"
        "xorl %edx, %ebx\n"
        "xorl %eax, %ebx\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 195 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4880c_00048856:\n"
        "xorl %ebx, %ebx\n" /* line 189 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "xorl %edx, %ebx\n"
        "xorl %eax, %ebx\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 195 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 203 */
__attribute__((naked))
int Com_RealTime(qtime_t *qtime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 203 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* qtime */
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 208 */
        "calll time\n"
        "movl %eax, -0xc(%ebp)\n" /* t */
        "testl %ebx, %ebx\n" /* line 209 | qtime */
        "je .Lf48868_000488cd\n"
        "leal -0xc(%ebp), %eax\n" /* line 211 | t */
        "movl %eax, (%esp)\n"
        "calll localtime\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 212 */
        "je .Lf48868_000488ca\n"
        "movl (%eax), %eax\n" /* line 214 */
        "movl %eax, (%ebx)\n" /* qtime */
        "movl 4(%edx), %eax\n" /* line 215 */
        "movl %eax, 4(%ebx)\n" /* qtime */
        "movl 8(%edx), %eax\n" /* line 216 */
        "movl %eax, 8(%ebx)\n" /* qtime */
        "movl 0xc(%edx), %eax\n" /* line 217 */
        "movl %eax, 0xc(%ebx)\n" /* qtime */
        "movl 0x10(%edx), %eax\n" /* line 218 */
        "movl %eax, 0x10(%ebx)\n" /* qtime */
        "movl 0x14(%edx), %eax\n" /* line 219 */
        "movl %eax, 0x14(%ebx)\n" /* qtime */
        "movl 0x18(%edx), %eax\n" /* line 220 */
        "movl %eax, 0x18(%ebx)\n" /* qtime */
        "movl 0x1c(%edx), %eax\n" /* line 221 */
        "movl %eax, 0x1c(%ebx)\n" /* qtime */
        "movl 0x20(%edx), %eax\n" /* line 222 */
        "movl %eax, 0x20(%ebx)\n" /* qtime */
        ".Lf48868_000488ca:\n"
        "movl -0xc(%ebp), %eax\n" /* line 224 | t */
        /* } scope */
        ".Lf48868_000488cd:\n"
        "addl $0x24, %esp\n" /* line 225 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 635 */
__attribute__((naked))
long int Com_Memcpy(long int *dest, const long int *src, int count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 635 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 637 | count */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* src */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dest */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leave\n" /* line 638 */
        "retl\n"
    );
}

/* line 642 */
__attribute__((naked))
long int Com_Memset(long int *dest, const int val, int count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 642 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 644 | count */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* val */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dest */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leave\n" /* line 645 */
        "retl\n"
    );
}

/* line 36 */
__attribute__((naked))
Bool Com_Filter(const char *filter, const char *name, int casesensitive)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 36 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %esi\n" /* filter */
        /* { scope 1: strcmpCallback */
        ".Lf48918_00048927:\n"
        "movzbl (%esi), %eax\n" /* line 42 | filter */
        "testb %al, %al\n"
        "je .Lf48918_00048c14\n"
        "cmpb $0x2a, %al\n" /* line 44 */
        "je .Lf48918_000489ee\n"
        "cmpb $0x3f, %al\n" /* line 63 */
        "je .Lf48918_0004895c\n"
        "cmpb $0x5b, %al\n" /* line 68 */
        "je .Lf48918_00048a37\n"
        "movl 0x10(%ebp), %edx\n" /* line 122 | casesensitive */
        "testl %edx, %edx\n"
        "je .Lf48918_00048b31\n"
        "movl 0xc(%ebp), %ecx\n" /* line 124 | name */
        "cmpb (%ecx), %al\n"
        "jne .Lf48918_000489e1\n"
        ".Lf48918_0004895c:\n"
        "addl $1, %esi\n" /* line 132 | filter */
        ".Lf48918_0004895f:\n"
        "addl $1, 0xc(%ebp)\n" /* line 133 | name */
        "jmp .Lf48918_00048927\n"
        ".Lf48918_00048965:\n"
        "xorl %edx, %edx\n" /* line 47 */
        ".Lf48918_00048967:\n"
        "movb $0, -0x418(%ebp, %edx)\n" /* line 54 */
        "cmpb $0, -0x418(%ebp)\n" /* line 55 | buf */
        "je .Lf48918_00048927\n"
        "movl 0x10(%ebp), %eax\n" /* line 57 | casesensitive */
        "testl %eax, %eax\n"
        "je .Lf48918_00048b5c\n"
        "movl 0x195ed0c, %eax\n"
        "movl %eax, -0x420(%ebp)\n" /* strcmpCallback */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf48918_0004898e:\n"
        "xorl %edx, %edx\n" /* line 896 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl 0xc(%ebp), %edi\n" /* name, len */
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* len */
        "movl %ecx, %ebx\n" /* i */
        "notl %ebx\n" /* i */
        "movl $0xffffffff, %ecx\n"
        "leal -0x418(%ebp), %edi\n" /* buf, len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "movl %ebx, %edi\n" /* line 22 | i, len */
        "subl %ecx, %edi\n" /* len */
        "js .Lf48918_000489e1\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf48918_000489b8:\n"
        "leal -0x418(%ebp), %eax\n" /* line 24 | buf */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll *-0x420(%ebp)\n" /* strcmpCallback */
        "testl %eax, %eax\n"
        "je .Lf48918_00048be8\n"
        "addl $1, %ebx\n" /* line 22 | i */
        "addl $1, 0xc(%ebp)\n" /* name */
        "cmpl %ebx, %edi\n" /* i, len */
        "jge .Lf48918_000489b8\n"
        /* } scope */
        /* } scope */
        ".Lf48918_000489e1:\n"
        "xorl %eax, %eax\n" /* line 42 */
        /* } scope */
        ".Lf48918_000489e3:\n"
        "addl $0x42c, %esp\n" /* line 137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: strcmpCallback */
        ".Lf48918_000489ee:\n"
        "addl $1, %esi\n" /* line 46 | filter */
        "movzbl (%esi), %eax\n" /* line 47 | filter */
        "testb %al, %al\n"
        "je .Lf48918_00048965\n"
        "cmpb $0x2a, %al\n" /* line 49 */
        "je .Lf48918_00048965\n"
        "cmpb $0x3f, %al\n"
        "je .Lf48918_00048965\n"
        "xorl %edx, %edx\n"
        ".Lf48918_00048a0e:\n"
        "movb %al, -0x418(%edx, %ebp)\n" /* line 51 */
        "addl $1, %esi\n" /* line 52 | filter */
        "addl $1, %edx\n" /* line 47 */
        "movzbl (%esi), %eax\n" /* filter */
        "testb %al, %al\n"
        "je .Lf48918_00048967\n"
        "cmpb $0x2a, %al\n" /* line 49 */
        "je .Lf48918_00048967\n"
        "cmpb $0x3f, %al\n"
        "jne .Lf48918_00048a0e\n"
        "jmp .Lf48918_00048967\n"
        ".Lf48918_00048a37:\n"
        "addl $1, %esi\n" /* line 68 | filter */
        "cmpb $0x5b, (%esi)\n" /* filter */
        "je .Lf48918_00048927\n"
        "xorl %edx, %edx\n"
        "movzbl (%esi), %eax\n" /* line 76 | filter */
        "testb %al, %al\n"
        "je .Lf48918_00048a7d\n"
        ".Lf48918_00048a4c:\n"
        "testl %edx, %edx\n"
        "jne .Lf48918_00048a9b\n"
        "cmpb $0x5d, %al\n" /* line 78 */
        "je .Lf48918_00048ad8\n"
        "leal 1(%esi), %edi\n" /* filter, len */
        "cmpb $0x2d, (%edi)\n" /* line 80 | len */
        "je .Lf48918_00048aee\n"
        ".Lf48918_00048a64:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 96 | casesensitive */
        "testl %ecx, %ecx\n"
        "je .Lf48918_00048ab0\n"
        "movl 0xc(%ebp), %ecx\n" /* line 98 | name */
        "cmpb (%ecx), %al\n"
        "je .Lf48918_00048acf\n"
        ".Lf48918_00048a72:\n"
        "xorl %edx, %edx\n" /* line 103 */
        "movl %edi, %esi\n" /* len, filter */
        ".Lf48918_00048a76:\n"
        "movzbl (%esi), %eax\n" /* line 76 | filter */
        "testb %al, %al\n"
        "jne .Lf48918_00048a4c\n"
        ".Lf48918_00048a7d:\n"
        "testl %edx, %edx\n" /* line 109 */
        "je .Lf48918_000489e1\n"
        "addl $1, %esi\n" /* line 132 | filter */
        "jmp .Lf48918_0004895f\n"
        ".Lf48918_00048a8d:\n"
        "addl $1, %esi\n" /* line 113 | filter */
        ".Lf48918_00048a90:\n"
        "movzbl (%esi), %eax\n" /* line 111 | filter */
        "testb %al, %al\n"
        "je .Lf48918_0004895c\n"
        ".Lf48918_00048a9b:\n"
        "cmpb $0x5d, %al\n" /* line 113 */
        "jne .Lf48918_00048a8d\n"
        "addl $1, %esi\n" /* filter */
        "cmpb $0x5d, (%esi)\n" /* filter */
        "je .Lf48918_00048a90\n"
        "addl $1, 0xc(%ebp)\n" /* line 133 | name */
        "jmp .Lf48918_00048927\n"
        ".Lf48918_00048ab0:\n"
        "movsbl %al, %eax\n" /* line 103 */
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "movl %eax, %ebx\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* name */
        "movsbl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "cmpl %eax, %ebx\n" /* i */
        "jne .Lf48918_00048a72\n"
        ".Lf48918_00048acf:\n"
        "movl $1, %edx\n"
        "movl %edi, %esi\n" /* len, filter */
        "jmp .Lf48918_00048a76\n"
        ".Lf48918_00048ad8:\n"
        "leal 1(%esi), %edi\n" /* line 78 | filter, len */
        "cmpb $0x5d, 1(%esi)\n" /* filter */
        "jne .Lf48918_000489e1\n"
        "cmpb $0x2d, (%edi)\n" /* line 80 | len */
        "jne .Lf48918_00048a64\n"
        ".Lf48918_00048aee:\n"
        "leal 2(%esi), %edx\n" /* filter */
        "movl %edx, -0x424(%ebp)\n"
        "movzbl 2(%esi), %edx\n" /* filter */
        "testb %dl, %dl\n"
        "je .Lf48918_00048a64\n"
        "cmpb $0x5d, %dl\n"
        "je .Lf48918_00048b78\n"
        "leal 3(%esi), %ecx\n" /* filter */
        "movl %ecx, -0x41c(%ebp)\n"
        "movl 0x10(%ebp), %ebx\n" /* line 82 | casesensitive, i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf48918_00048b92\n"
        ".Lf48918_00048b18:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 84 | name, i */
        "movzbl (%ebx), %ecx\n" /* i */
        "cmpb %cl, %al\n"
        "jle .Lf48918_00048b6d\n"
        ".Lf48918_00048b22:\n"
        "xorl %edx, %edx\n" /* line 89 */
        ".Lf48918_00048b24:\n"
        "movl -0x41c(%ebp), %edi\n" /* len */
        "movl %edi, %esi\n" /* line 103 | len, filter */
        "jmp .Lf48918_00048a76\n"
        ".Lf48918_00048b31:\n"
        "movsbl %al, %eax\n" /* line 129 */
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "movl %eax, %ebx\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* name */
        "movsbl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "cmpl %eax, %ebx\n" /* i */
        "jne .Lf48918_000489e1\n"
        "addl $1, %esi\n" /* line 132 | filter */
        "jmp .Lf48918_0004895f\n"
        ".Lf48918_00048b5c:\n"
        "movl 0x195ed10, %edx\n" /* line 57 */
        "movl %edx, -0x420(%ebp)\n" /* strcmpCallback */
        "jmp .Lf48918_0004898e\n"
        ".Lf48918_00048b6d:\n"
        "cmpb %cl, %dl\n" /* line 84 */
        "jl .Lf48918_00048b22\n"
        "movl $1, %edx\n" /* line 89 */
        "jmp .Lf48918_00048b24\n"
        ".Lf48918_00048b78:\n"
        "leal 3(%esi), %ebx\n" /* line 80 | filter, i */
        "movl %ebx, -0x41c(%ebp)\n" /* i */
        "cmpb $0x5d, 3(%esi)\n" /* filter */
        "jne .Lf48918_00048a64\n"
        "movl 0x10(%ebp), %ebx\n" /* line 82 | casesensitive, i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf48918_00048b18\n"
        ".Lf48918_00048b92:\n"
        "movl 0xc(%ebp), %edx\n" /* line 89 | name */
        "movsbl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "movl %eax, %ebx\n" /* i */
        "movsbl (%esi), %eax\n" /* filter */
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "cmpl %eax, %ebx\n" /* i */
        "jl .Lf48918_00048b22\n"
        "movl 0xc(%ebp), %ecx\n" /* name */
        "movsbl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "movl %eax, %ebx\n" /* i */
        "movl -0x424(%ebp), %edx\n"
        "movsbl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "cmpl %eax, %ebx\n" /* i */
        "jg .Lf48918_00048b22\n"
        "movl $1, %edx\n"
        "jmp .Lf48918_00048b24\n"
        ".Lf48918_00048be8:\n"
        "movl 0xc(%ebp), %edi\n" /* line 58 | name, len */
        "testl %edi, %edi\n" /* len */
        "je .Lf48918_000489e1\n"
        "cld\n" /* line 60 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x418(%ebp), %edi\n" /* buf, len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "movl 0xc(%ebp), %ebx\n" /* name, i */
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl %ecx, 0xc(%ebp)\n" /* name */
        "jmp .Lf48918_00048927\n"
        ".Lf48918_00048c14:\n"
        "movl $1, %eax\n" /* line 42 */
        "jmp .Lf48918_000489e3\n"
    );
}

/* line 145 */
__attribute__((naked))
Bool Com_FilterPath(const char *filter, const char *name, int casesensitive)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 145 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x90, %esp\n"
        "movl 8(%ebp), %ecx\n" /* filter */
        "movl 0xc(%ebp), %esi\n" /* name */
        "xorl %edx, %edx\n"
        "leal -0x48(%ebp), %ebx\n" /* new_filter */
        "jmp .Lf48c1e_00048c45\n"
        /* { scope 1 */
        ".Lf48c1e_00048c36:\n"
        "cmpb $0x3a, %al\n" /* line 153 */
        "je .Lf48c1e_00048c51\n"
        "movb %al, (%edx, %ebx)\n" /* line 159 */
        "addl $1, %edx\n" /* line 151 */
        "cmpl $0x3f, %edx\n"
        "je .Lf48c1e_00048c5d\n"
        ".Lf48c1e_00048c45:\n"
        "movzbl (%ecx, %edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf48c1e_00048c5d\n"
        "cmpb $0x5c, %al\n" /* line 153 */
        "jne .Lf48c1e_00048c36\n"
        ".Lf48c1e_00048c51:\n"
        "movb $0x2f, (%edx, %ebx)\n" /* line 155 */
        "addl $1, %edx\n" /* line 151 */
        "cmpl $0x3f, %edx\n"
        "jne .Lf48c1e_00048c45\n"
        ".Lf48c1e_00048c5d:\n"
        "movb $0, -0x48(%ebp, %edx)\n" /* line 162 */
        "xorl %edx, %edx\n"
        "leal -0x88(%ebp), %ecx\n" /* new_name */
        "jmp .Lf48c1e_00048c7b\n"
        ".Lf48c1e_00048c6c:\n"
        "cmpb $0x3a, %al\n" /* line 165 */
        "je .Lf48c1e_00048c87\n"
        "movb %al, (%edx, %ecx)\n" /* line 171 */
        "addl $1, %edx\n" /* line 163 */
        "cmpl $0x3f, %edx\n"
        "je .Lf48c1e_00048c93\n"
        ".Lf48c1e_00048c7b:\n"
        "movzbl (%esi, %edx), %eax\n" /* name */
        "testb %al, %al\n"
        "je .Lf48c1e_00048c93\n"
        "cmpb $0x5c, %al\n" /* line 165 */
        "jne .Lf48c1e_00048c6c\n"
        ".Lf48c1e_00048c87:\n"
        "movb $0x2f, (%edx, %ecx)\n" /* line 167 */
        "addl $1, %edx\n" /* line 163 */
        "cmpl $0x3f, %edx\n"
        "jne .Lf48c1e_00048c7b\n"
        ".Lf48c1e_00048c93:\n"
        "movb $0, -0x88(%ebp, %edx)\n" /* line 174 */
        "movl 0x10(%ebp), %eax\n" /* line 175 | casesensitive */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_Filter\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x90, %esp\n" /* line 176 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

