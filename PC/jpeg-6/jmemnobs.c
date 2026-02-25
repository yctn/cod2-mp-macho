/* ASM dump from: jmemnobs.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jmemnobs.c */

#include "common_types.h"
#include "imports.h"

long int * jpeg_get_small(j_common_ptr cinfo, size_t sizeofobject);
long int jpeg_free_small(j_common_ptr cinfo, long int *object, size_t sizeofobject);
long int * jpeg_get_large(j_common_ptr cinfo, size_t sizeofobject);
long int jpeg_free_large(j_common_ptr cinfo, long int *object, size_t sizeofobject);
long int jpeg_mem_available(j_common_ptr cinfo, long int min_bytes_needed, long int max_bytes_needed, long int already_allocated);
long int jpeg_open_backing_store(j_common_ptr cinfo, backing_store_ptr info, long int total_bytes_needed);
long int jpeg_mem_init(j_common_ptr cinfo);
long int jpeg_mem_term(j_common_ptr cinfo);

/* line 36 */
__attribute__((naked))
long int * jpeg_get_small(j_common_ptr cinfo, size_t sizeofobject)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 36 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0xc(%ebp), %edx\n" /* line 37 | sizeofobject */
        "movl %edx, 8(%ebp)\n" /* cinfo */
        "movl 0x18(%eax), %ecx\n"
        "popl %ebp\n" /* line 38 */
        "jmpl *%ecx\n" /* line 37 */
    );
}

/* line 42 */
__attribute__((naked))
long int jpeg_free_small(j_common_ptr cinfo, long int *object, size_t sizeofobject)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xc(%ebp), %edx\n" /* object */
        "movl 0x10(%ebp), %eax\n" /* line 43 | sizeofobject */
        "movl %eax, 0xc(%ebp)\n" /* object */
        "movl %edx, 8(%ebp)\n" /* cinfo */
        "movl 0x1c(%ecx), %ecx\n"
        "popl %ebp\n" /* line 44 */
        "jmpl *%ecx\n" /* line 43 */
    );
}

/* line 56 */
__attribute__((naked))
long int * jpeg_get_large(j_common_ptr cinfo, size_t sizeofobject)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0xc(%ebp), %edx\n" /* line 57 | sizeofobject */
        "movl %edx, 8(%ebp)\n" /* cinfo */
        "movl 0x18(%eax), %ecx\n"
        "popl %ebp\n" /* line 58 */
        "jmpl *%ecx\n" /* line 57 */
    );
}

/* line 62 */
__attribute__((naked))
long int jpeg_free_large(j_common_ptr cinfo, long int *object, size_t sizeofobject)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xc(%ebp), %edx\n" /* object */
        "movl 0x10(%ebp), %eax\n" /* line 63 | sizeofobject */
        "movl %eax, 0xc(%ebp)\n" /* object */
        "movl %edx, 8(%ebp)\n" /* cinfo */
        "movl 0x1c(%ecx), %ecx\n"
        "popl %ebp\n" /* line 64 */
        "jmpl *%ecx\n" /* line 63 */
    );
}

/* line 75 */
__attribute__((naked))
long int jpeg_mem_available(j_common_ptr cinfo, long int min_bytes_needed, long int max_bytes_needed, long int already_allocated)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* max_bytes_needed */
        "popl %ebp\n" /* line 77 */
        "retl\n"
    );
}

/* line 89 */
__attribute__((naked))
long int jpeg_open_backing_store(j_common_ptr cinfo, backing_store_ptr info, long int total_bytes_needed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl (%eax), %edx\n" /* line 90 */
        "movl $0x31, 0x14(%edx)\n"
        "movl (%eax), %edx\n"
        "movl %eax, 8(%ebp)\n" /* cinfo */
        "movl (%edx), %ecx\n"
        "popl %ebp\n" /* line 91 */
        "jmpl *%ecx\n" /* line 90 */
    );
}

/* line 101 */
__attribute__((naked))
long int jpeg_mem_init(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 103 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 107 */
__attribute__((naked))
long int jpeg_mem_term(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 107 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 109 */
        "retl\n"
    );
}

