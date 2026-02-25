/* ASM dump from: jmemmgr.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jmemmgr.c */

#include "common_types.h"
#include "imports.h"

static const size_t first_pool_slop[2]; /* 0x306f28 */
static const size_t extra_pool_slop[2]; /* 0x306f20 */

static void free_pool(j_common_ptr cinfo, int pool_id);
static void self_destruct(j_common_ptr cinfo);
void jinit_memory_mgr(j_common_ptr cinfo);
static void * alloc_small(j_common_ptr cinfo, int pool_id, size_t sizeofobject);
static jvirt_barray_ptr request_virt_barray(j_common_ptr cinfo, int pool_id, int pre_zero, JDIMENSION blocksperrow, JDIMENSION numrows, JDIMENSION maxaccess);
static jvirt_sarray_ptr request_virt_sarray(j_common_ptr cinfo, int pool_id, int pre_zero, JDIMENSION samplesperrow, JDIMENSION numrows, JDIMENSION maxaccess);
static void * alloc_large(j_common_ptr cinfo, int pool_id, size_t sizeofobject);
static JBLOCKARRAY alloc_barray(j_common_ptr cinfo, int pool_id, JDIMENSION blocksperrow, JDIMENSION numrows);
static JSAMPARRAY alloc_sarray(j_common_ptr cinfo, int pool_id, JDIMENSION samplesperrow, JDIMENSION numrows);
static JSAMPARRAY access_virt_sarray(j_common_ptr cinfo, jvirt_sarray_ptr ptr, JDIMENSION start_row, JDIMENSION num_rows, int writable);
static JBLOCKARRAY access_virt_barray(j_common_ptr cinfo, jvirt_barray_ptr ptr, JDIMENSION start_row, JDIMENSION num_rows, int writable);
static void realize_virt_arrays(j_common_ptr cinfo);

/* line 933 */
static __attribute__((naked))
void free_pool(j_common_ptr cinfo, int pool_id)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 933 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 934 | cinfo */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0xc(%ebp)\n" /* mem */
        "cmpl $1, 0xc(%ebp)\n" /* line 939 | pool_id */
        "jbe .Lf1fc230_001fc262\n"
        "movl 8(%ebp), %edx\n" /* line 940 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0xe, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* pool_id */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fc230_001fc262:\n"
        "cmpl $1, 0xc(%ebp)\n" /* line 948 | pool_id */
        "je .Lf1fc230_001fc2f7\n"
        ".Lf1fc230_001fc26c:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 969 | pool_id */
        "movl -0xc(%ebp), %edx\n" /* mem */
        "movl 0x3c(%edx, %ecx, 4), %eax\n"
        "movl $0, 0x3c(%edx, %ecx, 4)\n" /* line 970 */
        "testl %eax, %eax\n" /* line 972 */
        "jne .Lf1fc230_001fc286\n"
        "jmp .Lf1fc230_001fc2ae\n"
        ".Lf1fc230_001fc284:\n"
        "movl %edi, %eax\n"
        /* { scope 2 */
        ".Lf1fc230_001fc286:\n"
        "movl (%eax), %edi\n" /* line 973 | next_lhdr_ptr */
        "movl 4(%eax), %esi\n" /* line 974 | bptr */
        "addl 8(%eax), %esi\n" /* bptr */
        "addl $0xc, %esi\n" /* bptr */
        "movl %esi, 8(%esp)\n" /* line 977 | bptr */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_free_large\n"
        "movl -0xc(%ebp), %eax\n" /* line 978 | mem */
        "subl %esi, 0x4c(%eax)\n" /* bptr */
        /* } scope */
        "testl %edi, %edi\n" /* line 972 */
        "jne .Lf1fc230_001fc284\n"
        ".Lf1fc230_001fc2ae:\n"
        "movl 0xc(%ebp), %edx\n" /* line 983 | pool_id */
        "movl -0xc(%ebp), %ecx\n" /* mem */
        "movl 0x34(%ecx, %edx, 4), %eax\n"
        "movl $0, 0x34(%ecx, %edx, 4)\n" /* line 984 */
        "testl %eax, %eax\n" /* line 986 */
        "jne .Lf1fc230_001fc2c8\n"
        "jmp .Lf1fc230_001fc2f0\n"
        ".Lf1fc230_001fc2c6:\n"
        "movl %edi, %eax\n" /* next_lhdr_ptr */
        /* { scope 2 */
        ".Lf1fc230_001fc2c8:\n"
        "movl (%eax), %edi\n" /* line 987 | next_shdr_ptr */
        "movl 4(%eax), %esi\n" /* line 988 | bptr */
        "addl 8(%eax), %esi\n" /* bptr */
        "addl $0xc, %esi\n" /* bptr */
        "movl %esi, 8(%esp)\n" /* line 991 | bptr */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_free_small\n"
        "movl -0xc(%ebp), %edx\n" /* line 992 | mem */
        "subl %esi, 0x4c(%edx)\n" /* bptr */
        /* } scope */
        "testl %edi, %edi\n" /* line 986 | next_lhdr_ptr */
        "jne .Lf1fc230_001fc2c6\n"
        ".Lf1fc230_001fc2f0:\n"
        "addl $0x20, %esp\n" /* line 995 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf1fc230_001fc2f7:\n"
        "movl -0xc(%ebp), %eax\n" /* line 952 | mem */
        "movl 0x44(%eax), %esi\n" /* bptr */
        "testl %esi, %esi\n" /* bptr */
        "jne .Lf1fc230_001fc30a\n"
        "jmp .Lf1fc230_001fc375\n"
        ".Lf1fc230_001fc303:\n"
        "movl 0x24(%esi), %esi\n" /* bptr */
        "testl %esi, %esi\n" /* bptr */
        "je .Lf1fc230_001fc32b\n"
        ".Lf1fc230_001fc30a:\n"
        "cmpb $0, 0x22(%esi)\n" /* line 953 | bptr */
        "je .Lf1fc230_001fc303\n"
        "movb $0, 0x22(%esi)\n" /* line 954 | bptr */
        "leal 0x28(%esi), %eax\n" /* line 955 | bptr */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll *0x30(%esi)\n" /* bptr */
        "movl 0x24(%esi), %esi\n" /* line 952 | bptr */
        "testl %esi, %esi\n" /* bptr */
        "jne .Lf1fc230_001fc30a\n"
        ".Lf1fc230_001fc32b:\n"
        "movl -0xc(%ebp), %ecx\n" /* mem */
        ".Lf1fc230_001fc32e:\n"
        "movl $0, 0x44(%ecx)\n" /* line 958 */
        "movl 0x48(%ecx), %esi\n" /* line 959 | bptr */
        "testl %esi, %esi\n" /* bptr */
        "jne .Lf1fc230_001fc345\n"
        "jmp .Lf1fc230_001fc366\n"
        ".Lf1fc230_001fc33e:\n"
        "movl 0x24(%esi), %esi\n" /* bptr */
        "testl %esi, %esi\n" /* bptr */
        "je .Lf1fc230_001fc366\n"
        ".Lf1fc230_001fc345:\n"
        "cmpb $0, 0x22(%esi)\n" /* line 960 | bptr */
        "je .Lf1fc230_001fc33e\n"
        "movb $0, 0x22(%esi)\n" /* line 961 | bptr */
        "leal 0x28(%esi), %eax\n" /* line 962 | bptr */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x30(%esi)\n" /* bptr */
        "movl 0x24(%esi), %esi\n" /* line 959 | bptr */
        "testl %esi, %esi\n" /* bptr */
        "jne .Lf1fc230_001fc345\n"
        ".Lf1fc230_001fc366:\n"
        "movl -0xc(%ebp), %edx\n" /* line 965 | mem */
        "movl $0, 0x48(%edx)\n"
        "jmp .Lf1fc230_001fc26c\n"
        ".Lf1fc230_001fc375:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1fc230_001fc32e\n"
    );
}

/* line 1005 */
static __attribute__((naked))
void self_destruct(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 1005 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl $1, %esi\n"
        ".Lf1fc379_001fc389:\n"
        "movl %esi, 4(%esp)\n" /* line 1013 | pool */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll free_pool\n"
        "subl $1, %esi\n" /* line 1012 | pool */
        "cmpl $-1, %esi\n" /* pool */
        "jne .Lf1fc379_001fc389\n"
        "movl $0x54, 8(%esp)\n" /* line 1017 */
        "movl 4(%edi), %eax\n" /* cinfo */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll jpeg_free_small\n"
        "movl $0, 4(%edi)\n" /* line 1018 | cinfo */
        "movl %edi, 8(%ebp)\n" /* line 1020 | cinfo */
        "addl $0x10, %esp\n" /* line 1021 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp jpeg_mem_term\n" /* line 1020 */
    );
}

/* line 1031 */
__attribute__((naked))
void jinit_memory_mgr(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 1031 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl $0, 4(%edi)\n" /* line 1037 | cinfo */
        "movl %edi, (%esp)\n" /* line 1058 | cinfo */
        "calll jpeg_mem_init\n"
        "movl %eax, -0x1c(%ebp)\n" /* max_to_use */
        "movl $0x54, 4(%esp)\n" /* line 1061 */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll jpeg_get_small\n"
        "movl %eax, %esi\n" /* mem */
        "testl %eax, %eax\n" /* line 1063 */
        "je .Lf1fc3c9_001fc4b2\n"
        ".Lf1fc3c9_001fc406:\n"
        "leal 0x101(%ebx), %eax\n" /* line 1069 */
        "movl %eax, (%esi)\n" /* mem */
        "leal 0x3d4(%ebx), %eax\n" /* line 1070 */
        "movl %eax, 4(%esi)\n" /* mem */
        "leal 0x57a(%ebx), %eax\n" /* line 1071 */
        "movl %eax, 8(%esi)\n" /* mem */
        "leal 0x4a3(%ebx), %eax\n" /* line 1072 */
        "movl %eax, 0xc(%esi)\n" /* mem */
        "leal 0x356(%ebx), %eax\n" /* line 1073 */
        "movl %eax, 0x10(%esi)\n" /* mem */
        "leal 0x2d8(%ebx), %eax\n" /* line 1074 */
        "movl %eax, 0x14(%esi)\n" /* mem */
        "leal 0xddc(%ebx), %eax\n" /* line 1075 */
        "movl %eax, 0x18(%esi)\n" /* mem */
        "leal 0x640(%ebx), %eax\n" /* line 1076 */
        "movl %eax, 0x1c(%esi)\n" /* mem */
        "leal 0xa05(%ebx), %eax\n" /* line 1077 */
        "movl %eax, 0x20(%esi)\n" /* mem */
        "leal -0x1a7(%ebx), %eax\n" /* line 1078 */
        "movl %eax, 0x24(%esi)\n" /* mem */
        "leal -0x5e(%ebx), %eax\n" /* line 1079 */
        "movl %eax, 0x28(%esi)\n" /* mem */
        "movl $0x3b9aca00, 0x30(%esi)\n" /* line 1082 | mem */
        "movl -0x1c(%ebp), %eax\n" /* line 1085 | max_to_use */
        "movl %eax, 0x2c(%esi)\n" /* mem */
        "movl %esi, %eax\n" /* mem */
        "movl $2, %edx\n"
        ".Lf1fc3c9_001fc47c:\n"
        "movl $0, 0x38(%eax)\n" /* line 1088 */
        "movl $0, 0x40(%eax)\n" /* line 1089 */
        "subl $4, %eax\n"
        "subl $1, %edx\n" /* line 1087 */
        "jne .Lf1fc3c9_001fc47c\n"
        "movl $0, 0x44(%esi)\n" /* line 1091 | mem */
        "movl $0, 0x48(%esi)\n" /* line 1092 | mem */
        "movl $0x54, 0x4c(%esi)\n" /* line 1094 | mem */
        "movl %esi, 4(%edi)\n" /* line 1097 | mem, cinfo */
        "addl $0x2c, %esp\n" /* line 1120 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc3c9_001fc4b2:\n"
        "movl %edi, (%esp)\n" /* line 1064 | cinfo */
        "calll jpeg_mem_term\n"
        "movl (%edi), %eax\n" /* line 1065 | cinfo */
        "movl $0x36, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl $0, 0x18(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1fc3c9_001fc406\n"
    );
}

/* line 261 */
static __attribute__((naked))
void * alloc_small(j_common_ptr cinfo, int pool_id, size_t sizeofobject)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 261 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 262 | cinfo */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* mem */
        "cmpl $0x3b9ac9f4, 0x10(%ebp)\n" /* line 268 | sizeofobject */
        "ja .Lf1fc4d8_001fc597\n"
        ".Lf1fc4d8_001fc4fc:\n"
        "movl 0x10(%ebp), %eax\n" /* line 273 | sizeofobject */
        "andl $7, %eax\n"
        "je .Lf1fc4d8_001fc511\n"
        "movl 0x10(%ebp), %ecx\n" /* line 274 | sizeofobject */
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 0x10(%ebp)\n" /* sizeofobject */
        ".Lf1fc4d8_001fc511:\n"
        "cmpl $1, 0xc(%ebp)\n" /* line 277 | pool_id */
        "jbe .Lf1fc4d8_001fc532\n"
        "movl 8(%ebp), %edx\n" /* line 278 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0xe, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* pool_id */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fc4d8_001fc532:\n"
        "movl 0xc(%ebp), %edx\n" /* line 280 | pool_id */
        "movl -0x24(%ebp), %ecx\n" /* mem */
        "movl 0x34(%ecx, %edx, 4), %eax\n"
        "testl %eax, %eax\n" /* line 281 */
        "je .Lf1fc4d8_001fc5b8\n"
        "movl 0x10(%ebp), %ecx\n" /* line 282 | sizeofobject */
        "cmpl 8(%eax), %ecx\n"
        "ja .Lf1fc4d8_001fc569\n"
        "movl %eax, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* sizeofobject */
        ".Lf1fc4d8_001fc54d:\n"
        "movl 4(%ecx), %eax\n" /* line 321 */
        "addl %eax, %edx\n" /* line 322 */
        "movl %edx, 4(%ecx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 323 | sizeofobject */
        "subl %edx, 8(%ecx)\n"
        "leal 0xc(%ecx, %eax), %eax\n"
        "addl $0x2c, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc4d8_001fc567:\n"
        "movl %ecx, %eax\n" /* line 283 */
        ".Lf1fc4d8_001fc569:\n"
        "movl (%eax), %ecx\n" /* line 285 */
        "testl %ecx, %ecx\n" /* line 281 */
        "je .Lf1fc4d8_001fc686\n"
        "movl 0x10(%ebp), %eax\n" /* line 282 | sizeofobject */
        "cmpl 8(%ecx), %eax\n"
        "ja .Lf1fc4d8_001fc567\n"
        "movl %eax, %edx\n"
        "movl 4(%ecx), %eax\n" /* line 321 */
        "addl %eax, %edx\n" /* line 322 */
        "movl %edx, 4(%ecx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 323 | sizeofobject */
        "subl %edx, 8(%ecx)\n"
        "leal 0xc(%ecx, %eax), %eax\n"
        "addl $0x2c, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc4d8_001fc597:\n"
        "movl 8(%ebp), %edx\n" /* line 226 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x36, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc4d8_001fc4fc\n"
        ".Lf1fc4d8_001fc5b8:\n"
        "movl $0, -0x20(%ebp)\n" /* line 281 | prev_hdr_ptr */
        ".Lf1fc4d8_001fc5bf:\n"
        "movl 0x10(%ebp), %edx\n" /* line 291 | sizeofobject */
        "addl $0xc, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* min_request */
        "movl -0x20(%ebp), %edx\n" /* line 292 | prev_hdr_ptr */
        "testl %edx, %edx\n"
        "je .Lf1fc4d8_001fc68e\n"
        "movl 0xc(%ebp), %edx\n" /* line 295 | pool_id */
        "movl 0x10aa3a(%ebx, %edx, 4), %eax\n"
        ".Lf1fc4d8_001fc5dd:\n"
        "movl $0x3b9aca00, %edi\n" /* line 297 */
        "subl -0x1c(%ebp), %edi\n" /* min_request */
        "cmpl %edi, %eax\n"
        "ja .Lf1fc4d8_001fc5eb\n"
        "movl %eax, %edi\n"
        ".Lf1fc4d8_001fc5eb:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 301 | min_request */
        "addl %edi, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_get_small\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 302 */
        "jne .Lf1fc4d8_001fc642\n"
        ".Lf1fc4d8_001fc605:\n"
        "shrl $1, %edi\n" /* line 304 */
        "cmpl $0x31, %edi\n" /* line 305 */
        "ja .Lf1fc4d8_001fc5eb\n"
        "movl 8(%ebp), %edx\n" /* line 226 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x36, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $2, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x1c(%ebp), %esi\n" /* line 301 | min_request */
        "addl %edi, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_get_small\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 302 */
        "je .Lf1fc4d8_001fc605\n"
        ".Lf1fc4d8_001fc642:\n"
        "movl -0x24(%ebp), %eax\n" /* line 308 | mem */
        "addl %esi, 0x4c(%eax)\n"
        "movl $0, (%ecx)\n" /* line 310 */
        "movl $0, 4(%ecx)\n" /* line 311 */
        "movl 0x10(%ebp), %eax\n" /* line 312 | sizeofobject */
        "addl %edi, %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 313 | prev_hdr_ptr */
        "testl %eax, %eax\n"
        "je .Lf1fc4d8_001fc69d\n"
        "movl -0x20(%ebp), %edx\n" /* line 316 | prev_hdr_ptr */
        "movl %ecx, (%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* sizeofobject */
        "movl 4(%ecx), %eax\n" /* line 321 */
        "addl %eax, %edx\n" /* line 322 */
        "movl %edx, 4(%ecx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 323 | sizeofobject */
        "subl %edx, 8(%ecx)\n"
        "leal 0xc(%ecx, %eax), %eax\n"
        "addl $0x2c, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc4d8_001fc686:\n"
        "movl %eax, -0x20(%ebp)\n" /* line 281 | prev_hdr_ptr */
        "jmp .Lf1fc4d8_001fc5bf\n"
        ".Lf1fc4d8_001fc68e:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 293 | pool_id */
        "movl 0x10aa42(%ebx, %ecx, 4), %eax\n"
        "jmp .Lf1fc4d8_001fc5dd\n"
        ".Lf1fc4d8_001fc69d:\n"
        "movl 0xc(%ebp), %edx\n" /* line 314 | pool_id */
        "movl -0x24(%ebp), %eax\n" /* mem */
        "movl %ecx, 0x34(%eax, %edx, 4)\n"
        "movl 0x10(%ebp), %edx\n" /* sizeofobject */
        "jmp .Lf1fc4d8_001fc54d\n"
    );
}

/* line 559 */
static __attribute__((naked))
jvirt_barray_ptr request_virt_barray(j_common_ptr cinfo, int pool_id, int pre_zero, JDIMENSION blocksperrow, JDIMENSION numrows, JDIMENSION maxaccess)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 559 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0xc(%ebp), %edi\n" /* pool_id */
        "movl 0x10(%ebp), %eax\n" /* pre_zero */
        "movl %eax, -0x10(%ebp)\n"
        "movl 4(%esi), %edx\n" /* line 560 | cinfo */
        "movl %edx, -0xc(%ebp)\n" /* mem */
        "cmpl $1, %edi\n" /* line 564 | pool_id */
        "je .Lf1fc6af_001fc6e3\n"
        "movl (%esi), %eax\n" /* line 565 | cinfo */
        "movl $0xe, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %edi, 0x18(%eax)\n" /* pool_id */
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1fc6af_001fc6e3:\n"
        "movl $0x78, 8(%esp)\n" /* line 568 */
        "movl %edi, 4(%esp)\n" /* pool_id */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll alloc_small\n"
        "movl $0, (%eax)\n" /* line 571 */
        "movl 0x18(%ebp), %edx\n" /* line 572 | numrows */
        "movl %edx, 4(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 573 | blocksperrow */
        "movl %edx, 8(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 574 | maxaccess */
        "movl %edx, 0xc(%eax)\n"
        "movzbl -0x10(%ebp), %ecx\n" /* line 575 */
        "movb %cl, 0x20(%eax)\n"
        "movb $0, 0x22(%eax)\n" /* line 576 */
        "movl -0xc(%ebp), %ecx\n" /* line 577 | mem */
        "movl 0x48(%ecx), %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "movl %eax, 0x48(%ecx)\n" /* line 578 */
        "addl $0x20, %esp\n" /* line 581 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 529 */
static __attribute__((naked))
jvirt_sarray_ptr request_virt_sarray(j_common_ptr cinfo, int pool_id, int pre_zero, JDIMENSION samplesperrow, JDIMENSION numrows, JDIMENSION maxaccess)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 529 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0xc(%ebp), %edi\n" /* pool_id */
        "movl 0x10(%ebp), %eax\n" /* pre_zero */
        "movl %eax, -0x10(%ebp)\n"
        "movl 4(%esi), %edx\n" /* line 530 | cinfo */
        "movl %edx, -0xc(%ebp)\n" /* mem */
        "cmpl $1, %edi\n" /* line 534 | pool_id */
        "je .Lf1fc72d_001fc761\n"
        "movl (%esi), %eax\n" /* line 535 | cinfo */
        "movl $0xe, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %edi, 0x18(%eax)\n" /* pool_id */
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1fc72d_001fc761:\n"
        "movl $0x78, 8(%esp)\n" /* line 538 */
        "movl %edi, 4(%esp)\n" /* pool_id */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll alloc_small\n"
        "movl $0, (%eax)\n" /* line 541 */
        "movl 0x18(%ebp), %edx\n" /* line 542 | numrows */
        "movl %edx, 4(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 543 | samplesperrow */
        "movl %edx, 8(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 544 | maxaccess */
        "movl %edx, 0xc(%eax)\n"
        "movzbl -0x10(%ebp), %ecx\n" /* line 545 */
        "movb %cl, 0x20(%eax)\n"
        "movb $0, 0x22(%eax)\n" /* line 546 */
        "movl -0xc(%ebp), %ecx\n" /* line 547 | mem */
        "movl 0x44(%ecx), %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "movl %eax, 0x44(%ecx)\n" /* line 548 */
        "addl $0x20, %esp\n" /* line 551 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 346 */
static __attribute__((naked))
void * alloc_large(j_common_ptr cinfo, int pool_id, size_t sizeofobject)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* sizeofobject */
        "movl 8(%ebp), %eax\n" /* line 347 | cinfo */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0xc(%ebp)\n" /* mem */
        "cmpl $0x3b9ac9f4, %edi\n" /* line 352 | sizeofobject */
        "ja .Lf1fc7ab_001fc83b\n"
        ".Lf1fc7ab_001fc7c7:\n"
        "movl %edi, %eax\n" /* line 357 | sizeofobject */
        "andl $7, %eax\n"
        "je .Lf1fc7ab_001fc7d3\n"
        "subl %eax, %edi\n" /* line 358 | sizeofobject */
        "leal 8(%edi), %edi\n" /* sizeofobject */
        ".Lf1fc7ab_001fc7d3:\n"
        "cmpl $1, 0xc(%ebp)\n" /* line 361 | pool_id */
        "jbe .Lf1fc7ab_001fc7f4\n"
        "movl 8(%ebp), %ecx\n" /* line 362 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0xe, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* pool_id */
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fc7ab_001fc7f4:\n"
        "leal 0xc(%edi), %eax\n" /* line 364 | sizeofobject */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_get_large\n"
        "movl %eax, %esi\n" /* hdr_ptr */
        "testl %eax, %eax\n" /* line 366 */
        "je .Lf1fc7ab_001fc85c\n"
        ".Lf1fc7ab_001fc80c:\n"
        "movl %edi, %eax\n" /* line 368 | sizeofobject */
        "movl -0xc(%ebp), %ecx\n" /* mem */
        "addl 0x4c(%ecx), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, 0x4c(%ecx)\n"
        "movl 0xc(%ebp), %edx\n" /* line 371 | pool_id */
        "movl 0x3c(%ecx, %edx, 4), %eax\n"
        "movl %eax, (%esi)\n" /* hdr_ptr */
        "movl %edi, 4(%esi)\n" /* line 375 | sizeofobject, hdr_ptr */
        "movl $0, 8(%esi)\n" /* line 376 | hdr_ptr */
        "movl %esi, 0x3c(%ecx, %edx, 4)\n" /* line 377 | hdr_ptr */
        "leal 0xc(%esi), %eax\n" /* hdr_ptr */
        "addl $0x20, %esp\n" /* line 380 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc7ab_001fc83b:\n"
        "movl 8(%ebp), %edx\n" /* line 226 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x36, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $3, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc7ab_001fc7c7\n"
        ".Lf1fc7ab_001fc85c:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl (%edx), %eax\n"
        "movl $0x36, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $4, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc7ab_001fc80c\n"
    );
}

/* line 448 */
static __attribute__((naked))
JBLOCKARRAY alloc_barray(j_common_ptr cinfo, int pool_id, JDIMENSION blocksperrow, JDIMENSION numrows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 448 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 449 | cinfo */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* mem */
        "movl 0x10(%ebp), %edi\n" /* line 456 | blocksperrow, currow */
        "shll $7, %edi\n" /* currow */
        "movl $0x3b9ac9f4, %eax\n"
        "xorl %edx, %edx\n"
        "divl %edi\n" /* currow */
        "movl %eax, %esi\n" /* rowsperchunk */
        "testl %eax, %eax\n" /* line 458 */
        "jle .Lf1fc87a_001fc939\n"
        ".Lf1fc87a_001fc8a4:\n"
        "cmpl 0x14(%ebp), %esi\n" /* line 460 | numrows, rowsperchunk */
        "cmovgel 0x14(%ebp), %esi\n" /* numrows, rowsperchunk */
        "movl -0x14(%ebp), %ecx\n" /* line 464 | mem */
        "movl %esi, 0x50(%ecx)\n" /* rowsperchunk */
        "movl 0x14(%ebp), %eax\n" /* line 467 | numrows */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pool_id */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll alloc_small\n"
        "movl %eax, -0x10(%ebp)\n" /* result */
        "movl 0x14(%ebp), %ecx\n" /* line 472 | numrows */
        "testl %ecx, %ecx\n"
        "jne .Lf1fc87a_001fc8de\n"
        "addl $0x20, %esp\n" /* line 484 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc87a_001fc8de:\n"
        "movl %edi, -0xc(%ebp)\n" /* line 472 | currow */
        "xorl %edi, %edi\n" /* currow */
        ".Lf1fc87a_001fc8e3:\n"
        "movl 0x14(%ebp), %eax\n" /* line 473 | numrows */
        "subl %edi, %eax\n" /* currow */
        "cmpl %eax, %esi\n" /* rowsperchunk */
        "cmoval %eax, %esi\n" /* rowsperchunk */
        "movl 0x10(%ebp), %eax\n" /* line 474 | blocksperrow */
        "imull %esi, %eax\n" /* rowsperchunk */
        "shll $7, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* pool_id */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll alloc_large\n"
        "testl %esi, %esi\n" /* line 477 | rowsperchunk */
        "je .Lf1fc87a_001fc92a\n"
        "movl -0x10(%ebp), %ecx\n" /* result */
        "leal (%ecx, %edi, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1fc87a_001fc918:\n"
        "movl %eax, (%edx)\n" /* line 478 */
        "addl $1, %edi\n" /* currow */
        "addl -0xc(%ebp), %eax\n" /* line 479 */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ecx, %esi\n" /* line 477 | rowsperchunk */
        "jne .Lf1fc87a_001fc918\n"
        ".Lf1fc87a_001fc92a:\n"
        "cmpl %edi, 0x14(%ebp)\n" /* line 472 | currow, numrows */
        "ja .Lf1fc87a_001fc8e3\n"
        "movl -0x10(%ebp), %eax\n" /* result */
        "addl $0x20, %esp\n" /* line 484 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc87a_001fc939:\n"
        "movl 8(%ebp), %edx\n" /* line 459 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x46, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc87a_001fc8a4\n"
    );
}

/* line 400 */
static __attribute__((naked))
JSAMPARRAY alloc_sarray(j_common_ptr cinfo, int pool_id, JDIMENSION samplesperrow, JDIMENSION numrows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 400 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 401 | cinfo */
        "movl 4(%eax), %edi\n" /* mem */
        "movl $0x3b9ac9f4, %eax\n" /* line 408 */
        "xorl %edx, %edx\n"
        "divl 0x10(%ebp)\n" /* samplesperrow */
        "movl %eax, %esi\n" /* rowsperchunk */
        "testl %eax, %eax\n" /* line 410 */
        "jle .Lf1fc951_001fc9ff\n"
        ".Lf1fc951_001fc973:\n"
        "cmpl 0x14(%ebp), %esi\n" /* line 412 | numrows, rowsperchunk */
        "cmovgel 0x14(%ebp), %esi\n" /* numrows, rowsperchunk */
        "movl %esi, 0x50(%edi)\n" /* line 416 | rowsperchunk, currow */
        "movl 0x14(%ebp), %eax\n" /* line 419 | numrows */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* pool_id */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll alloc_small\n"
        "movl %eax, -0xc(%ebp)\n" /* result */
        "movl 0x14(%ebp), %edi\n" /* line 424 | numrows, currow */
        "testl %edi, %edi\n" /* currow */
        "jne .Lf1fc951_001fc9aa\n"
        "addl $0x20, %esp\n" /* line 436 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc951_001fc9aa:\n"
        "xorl %edi, %edi\n" /* line 424 | currow */
        ".Lf1fc951_001fc9ac:\n"
        "movl 0x14(%ebp), %eax\n" /* line 425 | numrows */
        "subl %edi, %eax\n" /* currow */
        "cmpl %eax, %esi\n" /* rowsperchunk */
        "cmoval %eax, %esi\n" /* rowsperchunk */
        "movl 0x10(%ebp), %eax\n" /* line 426 | samplesperrow */
        "imull %esi, %eax\n" /* rowsperchunk */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* pool_id */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll alloc_large\n"
        "testl %esi, %esi\n" /* line 429 | rowsperchunk */
        "je .Lf1fc951_001fc9f0\n"
        "movl -0xc(%ebp), %ecx\n" /* result */
        "leal (%ecx, %edi, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1fc951_001fc9de:\n"
        "movl %eax, (%edx)\n" /* line 430 */
        "addl $1, %edi\n" /* currow */
        "addl 0x10(%ebp), %eax\n" /* line 431 | samplesperrow */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ecx, %esi\n" /* line 429 | rowsperchunk */
        "jne .Lf1fc951_001fc9de\n"
        ".Lf1fc951_001fc9f0:\n"
        "cmpl %edi, 0x14(%ebp)\n" /* line 424 | currow, numrows */
        "ja .Lf1fc951_001fc9ac\n"
        "movl -0xc(%ebp), %eax\n" /* result */
        "addl $0x20, %esp\n" /* line 436 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fc951_001fc9ff:\n"
        "movl 8(%ebp), %edx\n" /* line 411 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x46, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc951_001fc973\n"
    );
}

/* line 764 */
static __attribute__((naked))
JSAMPARRAY access_virt_sarray(j_common_ptr cinfo, jvirt_sarray_ptr ptr, JDIMENSION start_row, JDIMENSION num_rows, int writable)
{
    __asm__ __volatile__ (
        /* { scope 1: file_offset, thisrow, file_offset, i, ... */
        "pushl %ebp\n" /* line 764 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x60, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* num_rows */
        "movzbl 0x18(%ebp), %edx\n" /* writable */
        "movb %dl, -0x1d(%ebp)\n" /* writable */
        "movl 0x10(%ebp), %ecx\n" /* line 765 | start_row */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* end_row */
        "movl 0xc(%ebp), %edi\n" /* line 769 | ptr, i */
        "cmpl 4(%edi), %ecx\n" /* i */
        "ja .Lf1fca17_001fca42\n"
        "cmpl 0xc(%edi), %eax\n" /* i */
        "jbe .Lf1fca17_001fccc1\n"
        ".Lf1fca17_001fca42:\n"
        "movl 8(%ebp), %edx\n" /* line 771 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x16, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fca17_001fca55:\n"
        "movl 0xc(%ebp), %edi\n" /* line 774 | ptr, i */
        "movl 0x18(%edi), %ecx\n" /* i */
        "cmpl %ecx, 0x10(%ebp)\n" /* start_row */
        "jb .Lf1fca17_001fcacb\n"
        "addl 0x10(%edi), %ecx\n" /* i */
        "cmpl %ecx, -0x1c(%ebp)\n" /* end_row */
        "ja .Lf1fca17_001fccd0\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movl 0x1c(%edi), %esi\n" /* i, byte_count */
        ".Lf1fca17_001fca72:\n"
        "movl %esi, %eax\n" /* line 811 | byte_count */
        "cmpl %esi, -0x1c(%ebp)\n" /* byte_count, end_row */
        "jbe .Lf1fca17_001fcbc0\n"
        ".Lf1fca17_001fca7d:\n"
        "cmpl %esi, 0x10(%ebp)\n" /* line 812 | byte_count, start_row */
        "jbe .Lf1fca17_001fcd0d\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 813 | writable */
        "jne .Lf1fca17_001fcdae\n"
        "movl 0x10(%ebp), %eax\n" /* start_row */
        "movl 0xc(%ebp), %edx\n" /* line 821 | ptr */
        "cmpb $0, 0x20(%edx)\n"
        "jne .Lf1fca17_001fcd29\n"
        ".Lf1fca17_001fcaa0:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 830 | writable */
        "je .Lf1fca17_001fcd8e\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl 0x18(%edx), %ecx\n"
        "movl %edx, %edi\n" /* i */
        "movb $1, 0x21(%edi)\n" /* line 836 | i */
        ".Lf1fca17_001fcab6:\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        ".Lf1fca17_001fcab9:\n"
        "subl %ecx, 0x10(%ebp)\n" /* start_row */
        "movl (%edx), %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* start_row */
        "leal (%eax, %ecx, 4), %eax\n"
        "addl $0x60, %esp\n" /* line 839 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fca17_001fcacb:\n"
        "movl %edi, %eax\n" /* i */
        "cmpb $0, 0x22(%eax)\n" /* line 776 */
        "je .Lf1fca17_001fccdd\n"
        ".Lf1fca17_001fcad7:\n"
        "movl %eax, %ecx\n"
        ".Lf1fca17_001fcad9:\n"
        "cmpb $0, 0x21(%ecx)\n" /* line 779 */
        "jne .Lf1fca17_001fcbdc\n"
        "movl %ecx, %eax\n"
        "movl 0x10(%ecx), %edi\n" /* i */
        "movl 8(%ecx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x1c(%ecx), %esi\n" /* byte_count */
        ".Lf1fca17_001fcaf1:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 790 | start_row */
        "cmpl 0x18(%eax), %ecx\n"
        "jbe .Lf1fca17_001fccf8\n"
        "movl %ecx, 0x18(%eax)\n" /* line 791 */
        /* { scope 2 */
        ".Lf1fca17_001fcb00:\n"
        "movl 0xc(%ebp), %eax\n" /* line 698 | ptr */
        "movl 0x18(%eax), %ecx\n"
        "movl -0x2c(%ebp), %edx\n"
        "imull %ecx, %edx\n"
        "movl %edx, -0x10(%ebp)\n" /* file_offset */
        "testl %edi, %edi\n" /* line 700 | i */
        "jle .Lf1fca17_001fca72\n"
        "movl 0x14(%eax), %eax\n" /* line 702 */
        "cmpl %eax, %edi\n" /* i */
        "cmovlel %edi, %eax\n" /* i */
        "movl %esi, %edx\n" /* line 705 | byte_count */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n"
        "cmovlel %eax, %edx\n"
        "movl 0xc(%ebp), %edi\n" /* line 707 | ptr, i */
        "movl 4(%edi), %eax\n" /* i */
        "subl %ecx, %eax\n"
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 708 */
        "jle .Lf1fca17_001fca72\n"
        "movl %edi, %eax\n" /* i */
        "xorl %edi, %edi\n" /* line 709 | i */
        "addl $0x28, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        ".Lf1fca17_001fcb47:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 710 | byte_count */
        "imull %edx, %esi\n" /* byte_count */
        "movl %esi, 0x10(%esp)\n" /* line 716 | byte_count */
        "movl -0x10(%ebp), %ecx\n" /* file_offset */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl (%edx), %eax\n"
        "movl (%eax, %edi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x28(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x28(%edx)\n"
        "addl %esi, -0x10(%ebp)\n" /* line 719 | byte_count, file_offset */
        "movl 0xc(%ebp), %ecx\n" /* line 700 | ptr */
        "movl 0x14(%ecx), %edx\n"
        "addl %edx, %edi\n" /* i */
        "movl 0x10(%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* i */
        "jge .Lf1fca17_001fcdc9\n"
        "subl %edi, %eax\n" /* line 702 | i */
        "cmpl %edx, %eax\n"
        "cmovgl %edx, %eax\n"
        "movl 0x18(%ecx), %edx\n" /* line 704 */
        "addl %edi, %edx\n" /* i */
        "movl %edx, -0x40(%ebp)\n" /* thisrow */
        "movl 0x1c(%ecx), %esi\n" /* line 705 | byte_count */
        "movl %esi, %edx\n" /* byte_count */
        "subl -0x40(%ebp), %edx\n" /* thisrow */
        "cmpl %edx, %eax\n"
        "cmovlel %eax, %edx\n"
        "movl 4(%ecx), %eax\n" /* line 707 */
        "subl -0x40(%ebp), %eax\n" /* thisrow */
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 708 */
        "jg .Lf1fca17_001fcb47\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 811 | byte_count */
        "cmpl %esi, -0x1c(%ebp)\n" /* byte_count, end_row */
        "ja .Lf1fca17_001fca7d\n"
        ".Lf1fca17_001fcbc0:\n"
        "movl 0xc(%ebp), %eax\n" /* ptr */
        "movl 0x18(%eax), %ecx\n"
        ".Lf1fca17_001fcbc6:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 835 | writable */
        "je .Lf1fca17_001fcab6\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movb $1, 0x21(%edi)\n" /* line 836 | i */
        "jmp .Lf1fca17_001fcab6\n"
        /* { scope 2 */
        ".Lf1fca17_001fcbdc:\n"
        "movl 8(%ecx), %edi\n" /* line 697 | i */
        "movl %edi, -0x2c(%ebp)\n" /* i */
        "movl %ecx, %eax\n" /* line 698 */
        "movl 0x18(%ecx), %ecx\n"
        "imull %ecx, %edi\n" /* i */
        "movl %edi, -0x18(%ebp)\n" /* i, file_offset */
        "movl 0x10(%eax), %edi\n" /* line 700 | i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf1fca17_001fcd7c\n"
        "movl 0xc(%ebp), %edx\n" /* line 702 | ptr */
        "movl 0x14(%edx), %eax\n"
        "cmpl %edi, %eax\n" /* i */
        "cmovgl %edi, %eax\n" /* i */
        "movl 0x1c(%edx), %esi\n" /* line 705 | byte_count */
        "movl %esi, %edx\n" /* byte_count */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n"
        "cmovgl %edx, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 707 | ptr */
        "movl 4(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 708 */
        "jle .Lf1fca17_001fcd7f\n"
        "movl $0, -0x14(%ebp)\n" /* line 709 | i */
        "movl 0xc(%ebp), %ecx\n" /* ptr */
        "addl $0x28, %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        ".Lf1fca17_001fcc3a:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 710 | byte_count */
        "imull %edx, %esi\n" /* byte_count */
        "movl %esi, 0x10(%esp)\n" /* line 712 | byte_count */
        "movl -0x18(%ebp), %edi\n" /* file_offset, i */
        "movl %edi, 0xc(%esp)\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl (%edx), %eax\n"
        "movl -0x14(%ebp), %ecx\n" /* i */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x28(%ebp), %edi\n" /* i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x2c(%edx)\n"
        "addl %esi, -0x18(%ebp)\n" /* line 719 | byte_count, file_offset */
        "movl 0xc(%ebp), %ecx\n" /* line 700 | ptr */
        "movl 0x14(%ecx), %edx\n"
        "addl %edx, -0x14(%ebp)\n" /* i */
        "movl 0x10(%ecx), %edi\n" /* i */
        "cmpl -0x14(%ebp), %edi\n" /* i */
        "jle .Lf1fca17_001fcdd1\n"
        "movl %edi, %eax\n" /* line 702 | i */
        "subl -0x14(%ebp), %eax\n" /* i */
        "cmpl %eax, %edx\n"
        "cmovlel %edx, %eax\n"
        "movl -0x14(%ebp), %ecx\n" /* line 704 | i */
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "addl 0x18(%edx), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* thisrow */
        "movl 0x1c(%edx), %esi\n" /* line 705 | byte_count */
        "movl %esi, %edx\n" /* byte_count */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n"
        "cmovlel %eax, %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* line 707 | ptr */
        "movl 4(%ecx), %eax\n"
        "subl -0x40(%ebp), %eax\n" /* thisrow */
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 708 */
        "jg .Lf1fca17_001fcc3a\n"
        "movl 8(%ecx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf1fca17_001fcd7f\n"
        /* } scope */
        ".Lf1fca17_001fccc1:\n"
        "movl (%edi), %eax\n" /* line 769 | i */
        "testl %eax, %eax\n"
        "jne .Lf1fca17_001fca55\n"
        "jmp .Lf1fca17_001fca42\n"
        ".Lf1fca17_001fccd0:\n"
        "movl 0xc(%ebp), %eax\n" /* ptr */
        "cmpb $0, 0x22(%eax)\n" /* line 776 */
        "jne .Lf1fca17_001fcad7\n"
        ".Lf1fca17_001fccdd:\n"
        "movl 8(%ebp), %edx\n" /* line 777 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x45, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0xc(%ebp), %ecx\n" /* ptr */
        "jmp .Lf1fca17_001fcad9\n"
        /* { scope 2 */
        ".Lf1fca17_001fccf8:\n"
        "xorl %eax, %eax\n" /* line 797 */
        "movl -0x1c(%ebp), %edx\n" /* end_row */
        "subl %edi, %edx\n" /* i */
        "cmovnsl %edx, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* line 799 | ptr */
        "movl %eax, 0x18(%edx)\n"
        "jmp .Lf1fca17_001fcb00\n"
        /* } scope */
        ".Lf1fca17_001fcd0d:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 819 | writable */
        "je .Lf1fca17_001fcd1c\n"
        ".Lf1fca17_001fcd13:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 820 | end_row, i */
        "movl 0xc(%ebp), %ecx\n" /* ptr */
        "movl %edi, 0x1c(%ecx)\n" /* i */
        ".Lf1fca17_001fcd1c:\n"
        "movl 0xc(%ebp), %edx\n" /* line 821 | ptr */
        "cmpb $0, 0x20(%edx)\n"
        "je .Lf1fca17_001fcaa0\n"
        /* { scope 2 */
        ".Lf1fca17_001fcd29:\n"
        "movl 8(%edx), %ecx\n" /* line 822 */
        "movl %ecx, -0xc(%ebp)\n" /* bytesperrow */
        "movl 0x18(%edx), %ecx\n" /* line 823 */
        "subl %ecx, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 824 | end_row */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n" /* line 825 */
        "jae .Lf1fca17_001fcbc6\n"
        "leal (, %eax, 4), %esi\n" /* byte_count */
        "xorl %edi, %edi\n" /* i */
        "subl %eax, %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        ".Lf1fca17_001fcd4f:\n"
        "movl -0xc(%ebp), %eax\n" /* line 826 | bytesperrow */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl (%edx), %eax\n"
        "movl (%eax, %esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "addl $1, %edi\n" /* i */
        "addl $4, %esi\n" /* byte_count */
        "cmpl %edi, -0x24(%ebp)\n" /* line 825 | i */
        "jne .Lf1fca17_001fcd4f\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movl 0x18(%edi), %ecx\n" /* i */
        "jmp .Lf1fca17_001fcbc6\n"
        ".Lf1fca17_001fcd7c:\n"
        "movl 0x1c(%eax), %esi\n" /* byte_count */
        /* } scope */
        ".Lf1fca17_001fcd7f:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 781 | ptr */
        "movb $0, 0x21(%ecx)\n"
        "movl 0xc(%ebp), %eax\n" /* ptr */
        "jmp .Lf1fca17_001fcaf1\n"
        ".Lf1fca17_001fcd8e:\n"
        "movl 8(%ebp), %edx\n" /* line 831 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x16, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movl 0x18(%edi), %ecx\n" /* i */
        "movl %edi, %edx\n" /* i */
        "jmp .Lf1fca17_001fcab9\n"
        ".Lf1fca17_001fcdae:\n"
        "movl 8(%ebp), %edx\n" /* line 814 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x16, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* start_row */
        "jmp .Lf1fca17_001fcd13\n"
        ".Lf1fca17_001fcdc9:\n"
        "movl 0x1c(%ecx), %esi\n" /* byte_count */
        "jmp .Lf1fca17_001fca72\n"
        ".Lf1fca17_001fcdd1:\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x1c(%ecx), %esi\n" /* byte_count */
        "jmp .Lf1fca17_001fcd7f\n"
    );
}

/* line 849 */
static __attribute__((naked))
JBLOCKARRAY access_virt_barray(j_common_ptr cinfo, jvirt_barray_ptr ptr, JDIMENSION start_row, JDIMENSION num_rows, int writable)
{
    __asm__ __volatile__ (
        /* { scope 1: bytesperrow, file_offset, thisrow, bytesperrow, ... */
        "pushl %ebp\n" /* line 849 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x60, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* num_rows */
        "movzbl 0x18(%ebp), %edx\n" /* writable */
        "movb %dl, -0x25(%ebp)\n" /* writable */
        "movl 0x10(%ebp), %ecx\n" /* line 850 | start_row */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* end_row */
        "movl 0xc(%ebp), %edi\n" /* line 854 | ptr, i */
        "cmpl 4(%edi), %ecx\n" /* i */
        "ja .Lf1fcddc_001fce07\n"
        "cmpl 0xc(%edi), %eax\n" /* i */
        "jbe .Lf1fcddc_001fd095\n"
        ".Lf1fcddc_001fce07:\n"
        "movl 8(%ebp), %edx\n" /* line 856 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x16, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fcddc_001fce1a:\n"
        "movl 0xc(%ebp), %edi\n" /* line 859 | ptr, i */
        "movl 0x18(%edi), %ecx\n" /* i */
        "cmpl %ecx, 0x10(%ebp)\n" /* start_row */
        "jb .Lf1fcddc_001fce90\n"
        "addl 0x10(%edi), %ecx\n" /* i */
        "cmpl %ecx, -0x24(%ebp)\n" /* end_row */
        "ja .Lf1fcddc_001fd0a4\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movl 0x1c(%edi), %esi\n" /* i, byte_count */
        ".Lf1fcddc_001fce37:\n"
        "movl %esi, %eax\n" /* line 896 | byte_count */
        "cmpl %esi, -0x24(%ebp)\n" /* byte_count, end_row */
        "jbe .Lf1fcddc_001fcf8e\n"
        ".Lf1fcddc_001fce42:\n"
        "cmpl %esi, 0x10(%ebp)\n" /* line 897 | byte_count, start_row */
        "jbe .Lf1fcddc_001fd0e1\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 898 | writable */
        "jne .Lf1fcddc_001fd185\n"
        "movl 0x10(%ebp), %eax\n" /* start_row */
        "movl 0xc(%ebp), %edx\n" /* line 906 | ptr */
        "cmpb $0, 0x20(%edx)\n"
        "jne .Lf1fcddc_001fd0fd\n"
        ".Lf1fcddc_001fce65:\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 915 | writable */
        "je .Lf1fcddc_001fd165\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl 0x18(%edx), %ecx\n"
        "movl %edx, %edi\n" /* i */
        "movb $1, 0x21(%edi)\n" /* line 921 | i */
        ".Lf1fcddc_001fce7b:\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        ".Lf1fcddc_001fce7e:\n"
        "subl %ecx, 0x10(%ebp)\n" /* start_row */
        "movl (%edx), %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* start_row */
        "leal (%eax, %ecx, 4), %eax\n"
        "addl $0x60, %esp\n" /* line 924 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fcddc_001fce90:\n"
        "movl %edi, %eax\n" /* i */
        "cmpb $0, 0x22(%eax)\n" /* line 861 */
        "je .Lf1fcddc_001fd0b1\n"
        ".Lf1fcddc_001fce9c:\n"
        "movl %eax, %ecx\n"
        ".Lf1fcddc_001fce9e:\n"
        "cmpb $0, 0x21(%ecx)\n" /* line 864 */
        "jne .Lf1fcddc_001fcfaa\n"
        "movl %ecx, %eax\n"
        "movl 0x10(%ecx), %edi\n" /* i */
        "movl 8(%ecx), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x1c(%ecx), %esi\n" /* byte_count */
        ".Lf1fcddc_001fceb6:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 875 | start_row */
        "cmpl 0x18(%eax), %ecx\n"
        "jbe .Lf1fcddc_001fd0cc\n"
        "movl %ecx, 0x18(%eax)\n" /* line 876 */
        /* { scope 2 */
        ".Lf1fcddc_001fcec5:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 730 */
        "shll $7, %ecx\n"
        "movl %ecx, -0x14(%ebp)\n" /* bytesperrow */
        "movl 0xc(%ebp), %eax\n" /* line 731 | ptr */
        "movl 0x18(%eax), %ecx\n"
        "movl -0x14(%ebp), %edx\n" /* bytesperrow */
        "imull %ecx, %edx\n"
        "movl %edx, -0x10(%ebp)\n" /* file_offset */
        "testl %edi, %edi\n" /* line 733 | i */
        "jle .Lf1fcddc_001fce37\n"
        "movl 0x14(%eax), %eax\n" /* line 735 */
        "cmpl %eax, %edi\n" /* i */
        "cmovlel %edi, %eax\n" /* i */
        "movl %esi, %edx\n" /* line 738 | byte_count */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n"
        "cmovlel %eax, %edx\n"
        "movl 0xc(%ebp), %edi\n" /* line 740 | ptr, i */
        "movl 4(%edi), %eax\n" /* i */
        "subl %ecx, %eax\n"
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 741 */
        "jle .Lf1fcddc_001fce37\n"
        "movl %edi, %eax\n" /* i */
        "xorl %edi, %edi\n" /* line 742 | i */
        "addl $0x28, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        ".Lf1fcddc_001fcf15:\n"
        "movl -0x14(%ebp), %esi\n" /* line 743 | bytesperrow, byte_count */
        "imull %edx, %esi\n" /* byte_count */
        "movl %esi, 0x10(%esp)\n" /* line 749 | byte_count */
        "movl -0x10(%ebp), %ecx\n" /* file_offset */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl (%edx), %eax\n"
        "movl (%eax, %edi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x28(%edx)\n"
        "addl %esi, -0x10(%ebp)\n" /* line 752 | byte_count, file_offset */
        "movl 0xc(%ebp), %ecx\n" /* line 733 | ptr */
        "movl 0x14(%ecx), %edx\n"
        "addl %edx, %edi\n" /* i */
        "movl 0x10(%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* i */
        "jge .Lf1fcddc_001fd1a0\n"
        "subl %edi, %eax\n" /* line 735 | i */
        "cmpl %edx, %eax\n"
        "cmovgl %edx, %eax\n"
        "movl 0x18(%ecx), %edx\n" /* line 737 */
        "addl %edi, %edx\n" /* i */
        "movl %edx, -0x40(%ebp)\n" /* thisrow */
        "movl 0x1c(%ecx), %esi\n" /* line 738 | byte_count */
        "movl %esi, %edx\n" /* byte_count */
        "subl -0x40(%ebp), %edx\n" /* thisrow */
        "cmpl %edx, %eax\n"
        "cmovlel %eax, %edx\n"
        "movl 4(%ecx), %eax\n" /* line 740 */
        "subl -0x40(%ebp), %eax\n" /* thisrow */
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 741 */
        "jg .Lf1fcddc_001fcf15\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 896 | byte_count */
        "cmpl %esi, -0x24(%ebp)\n" /* byte_count, end_row */
        "ja .Lf1fcddc_001fce42\n"
        ".Lf1fcddc_001fcf8e:\n"
        "movl 0xc(%ebp), %eax\n" /* ptr */
        "movl 0x18(%eax), %ecx\n"
        ".Lf1fcddc_001fcf94:\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 920 | writable */
        "je .Lf1fcddc_001fce7b\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movb $1, 0x21(%edi)\n" /* line 921 | i */
        "jmp .Lf1fcddc_001fce7b\n"
        /* { scope 2 */
        ".Lf1fcddc_001fcfaa:\n"
        "movl 8(%ecx), %edi\n" /* line 730 | i */
        "movl %edi, -0x34(%ebp)\n" /* i */
        "shll $7, %edi\n" /* i */
        "movl %edi, -0x20(%ebp)\n" /* i, bytesperrow */
        "movl %ecx, %eax\n" /* line 731 */
        "movl 0x18(%ecx), %ecx\n"
        "imull %ecx, %edi\n" /* i */
        "movl %edi, -0x1c(%ebp)\n" /* i, file_offset */
        "movl 0x10(%eax), %edi\n" /* line 733 | i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf1fcddc_001fd153\n"
        "movl 0xc(%ebp), %edx\n" /* line 735 | ptr */
        "movl 0x14(%edx), %eax\n"
        "cmpl %edi, %eax\n" /* i */
        "cmovgl %edi, %eax\n" /* i */
        "movl 0x1c(%edx), %esi\n" /* line 738 | byte_count */
        "movl %esi, %edx\n" /* byte_count */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n"
        "cmovgl %edx, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 740 | ptr */
        "movl 4(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 741 */
        "jle .Lf1fcddc_001fd156\n"
        "movl $0, -0x18(%ebp)\n" /* line 742 | i */
        "movl 0xc(%ebp), %ecx\n" /* ptr */
        "addl $0x28, %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        ".Lf1fcddc_001fd00e:\n"
        "movl -0x20(%ebp), %esi\n" /* line 743 | bytesperrow, byte_count */
        "imull %edx, %esi\n" /* byte_count */
        "movl %esi, 0x10(%esp)\n" /* line 745 | byte_count */
        "movl -0x1c(%ebp), %edi\n" /* file_offset, i */
        "movl %edi, 0xc(%esp)\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl (%edx), %eax\n"
        "movl -0x18(%ebp), %ecx\n" /* i */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %edi\n" /* i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x2c(%edx)\n"
        "addl %esi, -0x1c(%ebp)\n" /* line 752 | byte_count, file_offset */
        "movl 0xc(%ebp), %ecx\n" /* line 733 | ptr */
        "movl 0x14(%ecx), %edx\n"
        "addl %edx, -0x18(%ebp)\n" /* i */
        "movl 0x10(%ecx), %edi\n" /* i */
        "cmpl -0x18(%ebp), %edi\n" /* i */
        "jle .Lf1fcddc_001fd1a8\n"
        "movl %edi, %eax\n" /* line 735 | i */
        "subl -0x18(%ebp), %eax\n" /* i */
        "cmpl %eax, %edx\n"
        "cmovlel %edx, %eax\n"
        "movl -0x18(%ebp), %ecx\n" /* line 737 | i */
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "addl 0x18(%edx), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* thisrow */
        "movl 0x1c(%edx), %esi\n" /* line 738 | byte_count */
        "movl %esi, %edx\n" /* byte_count */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n"
        "cmovlel %eax, %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* line 740 | ptr */
        "movl 4(%ecx), %eax\n"
        "subl -0x40(%ebp), %eax\n" /* thisrow */
        "cmpl %eax, %edx\n"
        "cmovgl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 741 */
        "jg .Lf1fcddc_001fd00e\n"
        "movl 8(%ecx), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "jmp .Lf1fcddc_001fd156\n"
        /* } scope */
        ".Lf1fcddc_001fd095:\n"
        "movl (%edi), %eax\n" /* line 854 | i */
        "testl %eax, %eax\n"
        "jne .Lf1fcddc_001fce1a\n"
        "jmp .Lf1fcddc_001fce07\n"
        ".Lf1fcddc_001fd0a4:\n"
        "movl 0xc(%ebp), %eax\n" /* ptr */
        "cmpb $0, 0x22(%eax)\n" /* line 861 */
        "jne .Lf1fcddc_001fce9c\n"
        ".Lf1fcddc_001fd0b1:\n"
        "movl 8(%ebp), %edx\n" /* line 862 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x45, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0xc(%ebp), %ecx\n" /* ptr */
        "jmp .Lf1fcddc_001fce9e\n"
        /* { scope 2 */
        ".Lf1fcddc_001fd0cc:\n"
        "xorl %eax, %eax\n" /* line 882 */
        "movl -0x24(%ebp), %edx\n" /* end_row */
        "subl %edi, %edx\n" /* i */
        "cmovnsl %edx, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* line 884 | ptr */
        "movl %eax, 0x18(%edx)\n"
        "jmp .Lf1fcddc_001fcec5\n"
        /* } scope */
        ".Lf1fcddc_001fd0e1:\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 904 | writable */
        "je .Lf1fcddc_001fd0f0\n"
        ".Lf1fcddc_001fd0e7:\n"
        "movl -0x24(%ebp), %edi\n" /* line 905 | end_row, i */
        "movl 0xc(%ebp), %ecx\n" /* ptr */
        "movl %edi, 0x1c(%ecx)\n" /* i */
        ".Lf1fcddc_001fd0f0:\n"
        "movl 0xc(%ebp), %edx\n" /* line 906 | ptr */
        "cmpb $0, 0x20(%edx)\n"
        "je .Lf1fcddc_001fce65\n"
        /* { scope 2 */
        ".Lf1fcddc_001fd0fd:\n"
        "movl 8(%edx), %ecx\n" /* line 907 */
        "shll $7, %ecx\n"
        "movl %ecx, -0xc(%ebp)\n" /* bytesperrow */
        "movl 0x18(%edx), %ecx\n" /* line 908 */
        "subl %ecx, %eax\n"
        "movl -0x24(%ebp), %edx\n" /* line 909 | end_row */
        "subl %ecx, %edx\n"
        "cmpl %edx, %eax\n" /* line 910 */
        "jae .Lf1fcddc_001fcf94\n"
        "leal (, %eax, 4), %esi\n" /* byte_count */
        "xorl %edi, %edi\n" /* i */
        "subl %eax, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        ".Lf1fcddc_001fd126:\n"
        "movl -0xc(%ebp), %eax\n" /* line 911 | bytesperrow */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* ptr */
        "movl (%edx), %eax\n"
        "movl (%eax, %esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "addl $1, %edi\n" /* i */
        "addl $4, %esi\n" /* byte_count */
        "cmpl %edi, -0x2c(%ebp)\n" /* line 910 | i */
        "jne .Lf1fcddc_001fd126\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movl 0x18(%edi), %ecx\n" /* i */
        "jmp .Lf1fcddc_001fcf94\n"
        ".Lf1fcddc_001fd153:\n"
        "movl 0x1c(%eax), %esi\n" /* byte_count */
        /* } scope */
        ".Lf1fcddc_001fd156:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 866 | ptr */
        "movb $0, 0x21(%ecx)\n"
        "movl 0xc(%ebp), %eax\n" /* ptr */
        "jmp .Lf1fcddc_001fceb6\n"
        ".Lf1fcddc_001fd165:\n"
        "movl 8(%ebp), %edx\n" /* line 916 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x16, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0xc(%ebp), %edi\n" /* ptr, i */
        "movl 0x18(%edi), %ecx\n" /* i */
        "movl %edi, %edx\n" /* i */
        "jmp .Lf1fcddc_001fce7e\n"
        ".Lf1fcddc_001fd185:\n"
        "movl 8(%ebp), %edx\n" /* line 899 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x16, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* start_row */
        "jmp .Lf1fcddc_001fd0e7\n"
        ".Lf1fcddc_001fd1a0:\n"
        "movl 0x1c(%ecx), %esi\n" /* byte_count */
        "jmp .Lf1fcddc_001fce37\n"
        ".Lf1fcddc_001fd1a8:\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x1c(%ecx), %esi\n" /* byte_count */
        "jmp .Lf1fcddc_001fd156\n"
    );
}

/* line 587 */
static __attribute__((naked))
void realize_virt_arrays(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: samplesperrow */
        "pushl %ebp\n" /* line 587 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 588 | cinfo */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* mem */
        "movl 0x44(%eax), %ecx\n" /* line 600 */
        "testl %ecx, %ecx\n"
        "je .Lf1fd1b3_001fd4d4\n"
        "xorl %edi, %edi\n" /* maximum_space */
        "xorl %esi, %esi\n" /* space_per_minheight */
        "jmp .Lf1fd1b3_001fd1dc\n"
        ".Lf1fd1b3_001fd1d5:\n"
        "movl 0x24(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1fd1b3_001fd1fa\n"
        ".Lf1fd1b3_001fd1dc:\n"
        "movl (%ecx), %eax\n" /* line 601 */
        "testl %eax, %eax\n"
        "jne .Lf1fd1b3_001fd1d5\n"
        "movl 8(%ecx), %eax\n" /* line 602 */
        "movl %eax, %edx\n"
        "imull 0xc(%ecx), %edx\n"
        "addl %edx, %esi\n" /* space_per_minheight */
        "imull 4(%ecx), %eax\n" /* line 604 */
        "addl %eax, %edi\n" /* maximum_space */
        "movl 0x24(%ecx), %ecx\n" /* line 600 */
        "testl %ecx, %ecx\n"
        "jne .Lf1fd1b3_001fd1dc\n"
        ".Lf1fd1b3_001fd1fa:\n"
        "movl -0x24(%ebp), %edx\n" /* line 608 | mem */
        "movl 0x48(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1fd1b3_001fd20d\n"
        "jmp .Lf1fd1b3_001fd231\n"
        ".Lf1fd1b3_001fd206:\n"
        "movl 0x24(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1fd1b3_001fd231\n"
        ".Lf1fd1b3_001fd20d:\n"
        "movl (%ecx), %eax\n" /* line 609 */
        "testl %eax, %eax\n"
        "jne .Lf1fd1b3_001fd206\n"
        "movl 8(%ecx), %edx\n" /* line 610 */
        "movl %edx, %eax\n"
        "imull 0xc(%ecx), %eax\n"
        "shll $7, %eax\n"
        "addl %eax, %esi\n" /* space_per_minheight */
        "imull 4(%ecx), %edx\n" /* line 612 */
        "shll $7, %edx\n"
        "addl %edx, %edi\n" /* maximum_space */
        "movl 0x24(%ecx), %ecx\n" /* line 608 */
        "testl %ecx, %ecx\n"
        "jne .Lf1fd1b3_001fd20d\n"
        ".Lf1fd1b3_001fd231:\n"
        "testl %esi, %esi\n" /* line 617 | space_per_minheight */
        "jle .Lf1fd1b3_001fd39f\n"
        "movl -0x24(%ebp), %ecx\n" /* line 621 | mem */
        "movl 0x4c(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* maximum_space */
        "movl %esi, 4(%esp)\n" /* space_per_minheight */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_mem_available\n"
        "cmpl %edi, %eax\n" /* line 628 | maximum_space */
        "jl .Lf1fd1b3_001fd3a6\n"
        "movl $0x3b9aca00, -0x20(%ebp)\n" /* max_minheights */
        "movl -0x24(%ebp), %edx\n" /* line 641 | mem */
        "movl 0x44(%edx), %edi\n" /* maximum_space */
        "testl %edi, %edi\n" /* maximum_space */
        "jne .Lf1fd1b3_001fd27f\n"
        "jmp .Lf1fd1b3_001fd3c8\n"
        ".Lf1fd1b3_001fd274:\n"
        "movl 0x24(%edi), %edi\n" /* maximum_space */
        "testl %edi, %edi\n" /* maximum_space */
        "je .Lf1fd1b3_001fd32a\n"
        ".Lf1fd1b3_001fd27f:\n"
        "movl (%edi), %esi\n" /* line 642 | maximum_space, space_per_minheight */
        "testl %esi, %esi\n" /* space_per_minheight */
        "jne .Lf1fd1b3_001fd274\n"
        "movl 4(%edi), %esi\n" /* line 643 | maximum_space, space_per_minheight */
        "movl 0xc(%edi), %ecx\n" /* maximum_space */
        "leal -1(%esi), %eax\n" /* line 644 | space_per_minheight */
        "xorl %edx, %edx\n"
        "divl %ecx\n"
        "addl $1, %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* max_minheights */
        "jl .Lf1fd1b3_001fd466\n"
        "movl %esi, 0x10(%edi)\n" /* line 646 | space_per_minheight, maximum_space */
        "movl %esi, -0xc(%ebp)\n" /* line 656 | space_per_minheight */
        "movl 8(%edi), %eax\n" /* maximum_space */
        "movl %eax, -0x1c(%ebp)\n" /* samplesperrow */
        /* { scope 2: mem, result, rowsperchunk, currow */
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 401 | cinfo */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x18(%ebp)\n" /* mem */
        "movl $0x3b9ac9f4, %eax\n" /* line 408 */
        "xorl %edx, %edx\n"
        "divl -0x1c(%ebp)\n" /* samplesperrow */
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 410 */
        "jle .Lf1fd1b3_001fd4b4\n"
        ".Lf1fd1b3_001fd2c7:\n"
        "cmpl -0xc(%ebp), %esi\n" /* line 412 */
        "cmovgel -0xc(%ebp), %esi\n"
        "movl %esi, -0x2c(%ebp)\n" /* rowsperchunk */
        "movl -0x18(%ebp), %eax\n" /* line 416 | mem */
        "movl %esi, 0x50(%eax)\n"
        "movl -0xc(%ebp), %eax\n" /* line 419 */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll alloc_small\n"
        "movl %eax, -0x14(%ebp)\n" /* result */
        "movl -0xc(%ebp), %ecx\n" /* line 424 */
        "testl %ecx, %ecx\n"
        "jne .Lf1fd1b3_001fd3ff\n"
        /* } scope */
        /* } scope */
        ".Lf1fd1b3_001fd302:\n"
        "movl %eax, (%edi)\n" /* line 656 | maximum_space */
        "movl -0x24(%ebp), %edx\n" /* line 658 | mem */
        "movl 0x50(%edx), %eax\n"
        "movl %eax, 0x14(%edi)\n" /* maximum_space */
        "movl $0, 0x18(%edi)\n" /* line 659 | maximum_space */
        "movl $0, 0x1c(%edi)\n" /* line 660 | maximum_space */
        "movb $0, 0x21(%edi)\n" /* line 661 | maximum_space */
        "movl 0x24(%edi), %edi\n" /* line 641 | maximum_space */
        "testl %edi, %edi\n" /* maximum_space */
        "jne .Lf1fd1b3_001fd27f\n"
        ".Lf1fd1b3_001fd32a:\n"
        "movl -0x24(%ebp), %ecx\n" /* mem */
        ".Lf1fd1b3_001fd32d:\n"
        "movl 0x48(%ecx), %esi\n" /* line 665 | space_per_minheight */
        "testl %esi, %esi\n" /* space_per_minheight */
        "jne .Lf1fd1b3_001fd33d\n"
        "jmp .Lf1fd1b3_001fd39f\n"
        ".Lf1fd1b3_001fd336:\n"
        "movl 0x24(%esi), %esi\n" /* space_per_minheight */
        "testl %esi, %esi\n" /* space_per_minheight */
        "je .Lf1fd1b3_001fd39f\n"
        ".Lf1fd1b3_001fd33d:\n"
        "movl (%esi), %eax\n" /* line 666 | space_per_minheight */
        "testl %eax, %eax\n"
        "jne .Lf1fd1b3_001fd336\n"
        "movl 4(%esi), %edi\n" /* line 667 | space_per_minheight, maximum_space */
        "movl 0xc(%esi), %ecx\n" /* space_per_minheight */
        "leal -1(%edi), %eax\n" /* line 668 | maximum_space */
        "xorl %edx, %edx\n"
        "divl %ecx\n"
        "addl $1, %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* max_minheights */
        "jl .Lf1fd1b3_001fd3cf\n"
        "movl %edi, 0x10(%esi)\n" /* line 670 | maximum_space, space_per_minheight */
        "movl %edi, %eax\n" /* maximum_space */
        ".Lf1fd1b3_001fd35d:\n"
        "movl %eax, 0xc(%esp)\n" /* line 680 */
        "movl 8(%esi), %eax\n" /* space_per_minheight */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll alloc_barray\n"
        "movl %eax, (%esi)\n" /* space_per_minheight */
        "movl -0x24(%ebp), %ecx\n" /* line 682 | mem */
        "movl 0x50(%ecx), %eax\n"
        "movl %eax, 0x14(%esi)\n" /* space_per_minheight */
        "movl $0, 0x18(%esi)\n" /* line 683 | space_per_minheight */
        "movl $0, 0x1c(%esi)\n" /* line 684 | space_per_minheight */
        "movb $0, 0x21(%esi)\n" /* line 685 | space_per_minheight */
        "movl 0x24(%esi), %esi\n" /* line 665 | space_per_minheight */
        "testl %esi, %esi\n" /* space_per_minheight */
        "jne .Lf1fd1b3_001fd33d\n"
        ".Lf1fd1b3_001fd39f:\n"
        "addl $0x40, %esp\n" /* line 688 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fd1b3_001fd3a6:\n"
        "cltd\n" /* line 631 */
        "idivl %esi\n" /* space_per_minheight */
        "movl %eax, -0x20(%ebp)\n" /* max_minheights */
        "testl %eax, %eax\n" /* line 635 */
        "movl $1, %eax\n"
        "cmovgl -0x20(%ebp), %eax\n" /* max_minheights */
        "movl %eax, -0x20(%ebp)\n" /* max_minheights */
        "movl -0x24(%ebp), %edx\n" /* line 641 | mem */
        "movl 0x44(%edx), %edi\n" /* maximum_space */
        "testl %edi, %edi\n" /* maximum_space */
        "jne .Lf1fd1b3_001fd27f\n"
        ".Lf1fd1b3_001fd3c8:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1fd1b3_001fd32d\n"
        ".Lf1fd1b3_001fd3cf:\n"
        "imull -0x20(%ebp), %ecx\n" /* line 673 | max_minheights */
        "movl %ecx, 0x10(%esi)\n" /* space_per_minheight */
        "imull 8(%esi), %edi\n" /* line 674 | space_per_minheight, maximum_space */
        "shll $7, %edi\n" /* maximum_space */
        "movl %edi, 8(%esp)\n" /* maximum_space */
        "leal 0x28(%esi), %eax\n" /* space_per_minheight */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_open_backing_store\n"
        "movb $1, 0x22(%esi)\n" /* line 678 | space_per_minheight */
        "movl 0x10(%esi), %eax\n" /* space_per_minheight */
        "jmp .Lf1fd1b3_001fd35d\n"
        /* { scope 2: mem, result, rowsperchunk, currow */
        /* { scope 3 */
        ".Lf1fd1b3_001fd3ff:\n"
        "movl $0, -0x10(%ebp)\n" /* line 424 | currow */
        "movl -0xc(%ebp), %eax\n"
        ".Lf1fd1b3_001fd409:\n"
        "subl -0x10(%ebp), %eax\n" /* line 425 | currow */
        "cmpl %eax, -0x2c(%ebp)\n" /* rowsperchunk */
        "cmovbel -0x2c(%ebp), %eax\n" /* rowsperchunk */
        "movl %eax, -0x2c(%ebp)\n" /* rowsperchunk */
        "movl -0x1c(%ebp), %eax\n" /* line 426 | samplesperrow */
        "imull -0x2c(%ebp), %eax\n" /* rowsperchunk */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll alloc_large\n"
        "movl -0x2c(%ebp), %edx\n" /* line 429 | rowsperchunk */
        "testl %edx, %edx\n"
        "je .Lf1fd1b3_001fd45a\n"
        "movl -0x10(%ebp), %esi\n" /* currow */
        "movl -0x14(%ebp), %ecx\n" /* result */
        "leal (%ecx, %esi, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1fd1b3_001fd446:\n"
        "movl %eax, (%edx)\n" /* line 430 */
        "addl $1, -0x10(%ebp)\n" /* currow */
        "addl -0x1c(%ebp), %eax\n" /* line 431 | samplesperrow */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ecx, -0x2c(%ebp)\n" /* line 429 | rowsperchunk */
        "jne .Lf1fd1b3_001fd446\n"
        ".Lf1fd1b3_001fd45a:\n"
        "movl -0xc(%ebp), %esi\n" /* line 424 */
        "cmpl %esi, -0x10(%ebp)\n" /* currow */
        "jae .Lf1fd1b3_001fd4cc\n"
        "movl %esi, %eax\n"
        "jmp .Lf1fd1b3_001fd409\n"
        /* } scope */
        /* } scope */
        ".Lf1fd1b3_001fd466:\n"
        "imull -0x20(%ebp), %ecx\n" /* line 649 | max_minheights */
        "movl %ecx, 0x10(%edi)\n" /* maximum_space */
        "imull 8(%edi), %esi\n" /* line 650 | maximum_space, space_per_minheight */
        "movl %esi, 8(%esp)\n" /* space_per_minheight */
        "leal 0x28(%edi), %eax\n" /* maximum_space */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_open_backing_store\n"
        "movb $1, 0x22(%edi)\n" /* line 654 | maximum_space */
        "movl 0x10(%edi), %esi\n" /* maximum_space, space_per_minheight */
        "movl %esi, -0xc(%ebp)\n" /* line 656 | space_per_minheight */
        "movl 8(%edi), %eax\n" /* maximum_space */
        "movl %eax, -0x1c(%ebp)\n" /* samplesperrow */
        /* { scope 2: mem, result, rowsperchunk, currow */
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 401 | cinfo */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x18(%ebp)\n" /* mem */
        "movl $0x3b9ac9f4, %eax\n" /* line 408 */
        "xorl %edx, %edx\n"
        "divl -0x1c(%ebp)\n" /* samplesperrow */
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 410 */
        "jg .Lf1fd1b3_001fd2c7\n"
        ".Lf1fd1b3_001fd4b4:\n"
        "movl 8(%ebp), %ecx\n" /* line 411 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x46, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fd1b3_001fd2c7\n"
        ".Lf1fd1b3_001fd4cc:\n"
        "movl -0x14(%ebp), %eax\n" /* result */
        "jmp .Lf1fd1b3_001fd302\n"
        /* } scope */
        /* } scope */
        ".Lf1fd1b3_001fd4d4:\n"
        "xorl %esi, %esi\n" /* line 600 | space_per_minheight */
        "xorl %edi, %edi\n" /* maximum_space */
        "jmp .Lf1fd1b3_001fd1fa\n"
    );
}

