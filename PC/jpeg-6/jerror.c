/* ASM dump from: jerror.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jerror.c */

#include "common_types.h"
#include "imports.h"

extern const const char * jpeg_std_message_table[125]; /* 0x0 */

static void error_exit(j_common_ptr cinfo);
static void output_message(j_common_ptr cinfo);
static void emit_message(j_common_ptr cinfo, int msg_level);
static void format_message(j_common_ptr cinfo, char *buffer);
static void reset_error_mgr(j_common_ptr cinfo);
jpeg_error_mgr * jpeg_std_error(jpeg_error_mgr *err, void (*exit)(), void (*printf)());

/* line 71 */
static __attribute__((naked))
void error_exit(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl (%esi), %eax\n" /* line 73 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *8(%eax)\n"
        "movl %esi, (%esp)\n" /* line 76 | cinfo */
        "calll jpeg_destroy\n"
        "movl (%esi), %eax\n" /* line 78 | cinfo */
        "movl 0x84(%eax), %ecx\n"
        "addl $0x14, %esp\n" /* line 79 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 78 */
    );
}

/* line 99 */
static __attribute__((naked))
void output_message(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0xe0, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl (%esi), %eax\n" /* line 103 | cinfo */
        "leal -0xd0(%ebp), %edi\n" /* buffer */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *0xc(%eax)\n"
        "movl (%esi), %eax\n" /* line 110 | cinfo */
        "movl %edi, (%esp)\n"
        "calll *0x88(%eax)\n"
        "addl $0xe0, %esp\n" /* line 112 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 128 */
static __attribute__((naked))
void emit_message(j_common_ptr cinfo, int msg_level)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0xc(%ebp), %eax\n" /* msg_level */
        "movl (%edx), %esi\n" /* line 129 | err */
        "testl %eax, %eax\n" /* line 131 */
        "js .Lf1f8f0a_001f8f35\n"
        "cmpl 0x68(%esi), %eax\n" /* line 142 | err */
        "jle .Lf1f8f0a_001f8f28\n"
        "addl $0x14, %esp\n" /* line 145 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f8f0a_001f8f28:\n"
        "movl %edx, 8(%ebp)\n" /* line 143 | cinfo */
        "movl 8(%esi), %ecx\n" /* err */
        "addl $0x14, %esp\n" /* line 145 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 143 */
        ".Lf1f8f0a_001f8f35:\n"
        "movl 0x6c(%esi), %eax\n" /* line 136 | err */
        "testl %eax, %eax\n"
        "je .Lf1f8f0a_001f8f42\n"
        "cmpl $2, 0x68(%esi)\n" /* err */
        "jle .Lf1f8f0a_001f8f48\n"
        ".Lf1f8f0a_001f8f42:\n"
        "movl %edx, (%esp)\n" /* line 137 */
        "calll *8(%esi)\n" /* err */
        ".Lf1f8f0a_001f8f48:\n"
        "addl $1, 0x6c(%esi)\n" /* line 139 | err */
        "addl $0x14, %esp\n" /* line 145 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 157 */
static __attribute__((naked))
void format_message(j_common_ptr cinfo, char *buffer)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 157 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 158 | cinfo */
        "movl (%eax), %ecx\n" /* err */
        "movl 0x14(%ecx), %edx\n" /* line 159 | msg_code */
        "testl %edx, %edx\n" /* line 166 */
        "jle .Lf1f8f52_001f8fd9\n"
        "cmpl 0x74(%ecx), %edx\n"
        "jg .Lf1f8f52_001f8fd9\n"
        "movl 0x70(%ecx), %eax\n" /* line 167 */
        "movl (%eax, %edx, 4), %esi\n" /* msgtext */
        ".Lf1f8f52_001f8f71:\n"
        "testl %esi, %esi\n" /* line 175 | msgtext */
        "je .Lf1f8f52_001f8fef\n"
        ".Lf1f8f52_001f8f75:\n"
        "movl %esi, %eax\n" /* line 177 | msgtext */
        ".Lf1f8f52_001f8f77:\n"
        "movzbl (%eax), %edx\n" /* line 183 */
        "addl $1, %eax\n"
        "testb %dl, %dl\n"
        "je .Lf1f8f52_001f8f8b\n"
        "cmpb $0x25, %dl\n" /* line 184 */
        "jne .Lf1f8f52_001f8f77\n"
        "cmpb $0x73, (%eax)\n" /* line 185 */
        "je .Lf1f8f52_001f9008\n"
        ".Lf1f8f52_001f8f8b:\n"
        "movl 0x34(%ecx), %eax\n" /* line 194 */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x30(%ecx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x2c(%ecx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x24(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x20(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* msgtext */
        "movl 0xc(%ebp), %edi\n" /* buffer */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        "addl $0x30, %esp\n" /* line 199 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f8f52_001f8fd9:\n"
        "movl 0x78(%ecx), %esi\n" /* line 168 | msgtext */
        "testl %esi, %esi\n" /* msgtext */
        "je .Lf1f8f52_001f8fef\n"
        "movl 0x7c(%ecx), %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf1f8f52_001f8fef\n"
        "cmpl 0x80(%ecx), %edx\n"
        "jle .Lf1f8f52_001f8ffc\n"
        ".Lf1f8f52_001f8fef:\n"
        "movl %edx, 0x18(%ecx)\n" /* line 176 */
        "movl 0x70(%ecx), %eax\n" /* line 177 */
        "movl (%eax), %esi\n" /* msgtext */
        "jmp .Lf1f8f52_001f8f75\n"
        ".Lf1f8f52_001f8ffc:\n"
        "movl %edx, %edi\n" /* line 171 */
        "subl %eax, %edi\n"
        "movl (%esi, %edi, 4), %esi\n" /* msgtext */
        "jmp .Lf1f8f52_001f8f71\n"
        ".Lf1f8f52_001f9008:\n"
        "leal 0x18(%ecx), %eax\n" /* line 192 */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* msgtext */
        "movl 0xc(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "addl $0x30, %esp\n" /* line 199 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 212 */
static __attribute__((naked))
void reset_error_mgr(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 212 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl (%eax), %edx\n" /* line 213 */
        "movl $0, 0x6c(%edx)\n"
        "movl (%eax), %eax\n" /* line 215 */
        "movl $0, 0x14(%eax)\n"
        "popl %ebp\n" /* line 216 */
        "retl\n"
    );
}

/* line 231 */
__attribute__((naked))
jpeg_error_mgr * jpeg_std_error(jpeg_error_mgr *err, void (*exit)(), void (*printf)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 231 */
        "movl %esp, %ebp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* err */
        "leal -0x19b(%ecx), %edx\n" /* line 232 */
        "movl %edx, (%eax)\n"
        "leal -0x13d(%ecx), %edx\n" /* line 233 */
        "movl %edx, 4(%eax)\n"
        "leal -0x172(%ecx), %edx\n" /* line 234 */
        "movl %edx, 8(%eax)\n"
        "leal -0xf5(%ecx), %edx\n" /* line 235 */
        "movl %edx, 0xc(%eax)\n"
        "leal -0x22(%ecx), %edx\n" /* line 236 */
        "movl %edx, 0x10(%eax)\n"
        "movl $0, 0x68(%eax)\n" /* line 238 */
        "movl $0, 0x6c(%eax)\n" /* line 239 */
        "movl $0, 0x14(%eax)\n" /* line 240 */
        "leal 0x13b459(%ecx), %edx\n" /* line 243 */
        "movl %edx, 0x70(%eax)\n"
        "movl $0x7b, 0x74(%eax)\n" /* line 244 */
        "movl $0, 0x78(%eax)\n" /* line 246 */
        "movl $0, 0x7c(%eax)\n" /* line 247 */
        "movl $0, 0x80(%eax)\n" /* line 248 */
        "movl 0xc(%ebp), %edx\n" /* line 250 | exit */
        "movl %edx, 0x84(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 251 | printf */
        "movl %edx, 0x88(%eax)\n"
        "popl %ebp\n" /* line 254 */
        "retl\n"
    );
}

