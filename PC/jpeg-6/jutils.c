/* Converted to C from ASM: jutils.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jutils.c */

#include "common_types.h"
#include "imports.h"

extern const int jpeg_natural_order[80]; /* 0x0 */

long int jdiv_round_up(long int a, long int b)
{
    return (a + b - 1) / b;
}

long int jround_up(long int a, long int b)
{
    long int tmp = a + b - 1;
    return tmp - (tmp % b);
}

void jcopy_sample_rows(JSAMPARRAY input_array, int source_row, JSAMPARRAY output_array, int dest_row, int num_rows, JDIMENSION num_cols)
{
    unsigned char **inptr = (unsigned char **)(void *)input_array + source_row;
    unsigned char **outptr = (unsigned char **)(void *)output_array + dest_row;
    int row;

    for (row = 0; row < num_rows; row++) {
        memcpy(*outptr, *inptr, num_cols);
        inptr++;
        outptr++;
    }
}

void jcopy_block_row(JBLOCKROW input_row, JBLOCKROW output_row, JDIMENSION num_blocks)
{
    memcpy((void *)output_row, (void *)input_row, (size_t)num_blocks * 128);
}

void jzero_far(int *target, size_t bytestozero)
{
    memset(target, 0, bytestozero);
}

