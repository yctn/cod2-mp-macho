/* ASM dump from: zutil.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/zutil.c */

#include "common_types.h"
#include "imports.h"

voidpf zcalloc(voidpf opaque, unsigned int items, unsigned int size);
inflate_blocks_statef zcfree(voidpf opaque, voidpf ptr);

/* line 202 */
__attribute__((naked))
voidpf zcalloc(voidpf opaque, unsigned int items, unsigned int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 202 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* line 215 | size */
        "imull 0xc(%ebp), %eax\n" /* items */
        "movl %eax, 8(%ebp)\n" /* opaque */
        "popl %ebp\n" /* line 217 */
        "jmp Z_MallocInternal\n" /* line 215 */
    );
}

/* line 219 */
__attribute__((naked))
inflate_blocks_statef zcfree(voidpf opaque, voidpf ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 219 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* line 231 | ptr */
        "movl %eax, 8(%ebp)\n" /* opaque */
        "popl %ebp\n" /* line 233 */
        "jmp Z_FreeInternal\n" /* line 231 */
    );
}

