/* ASM dump from: sv_snapshot_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_snapshot_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static int startOffset; /* 0x3131e4 */
static int endOffset; /* 0x3131e0 */

void SV_UpdateServerCommandsToClient(client_t *client, msg_t *msg);
static cachedSnapshot_t * SV_GetCachedSnapshotInternal(void);
void SV_ArchiveSnapshot(void);
void SV_SendMessageToClient(msg_t *msg, client_t *client);
qboolean SV_GetArchivedClientInfo(int clientNum, int *pArchiveTime, int (*ps)[4], void (*cs)());
Bool SV_GetClientPositionAtTime(int client, int gametime, vec_t *pos);
void SV_SendClientSnapshot(client_t *client);
void SV_SendClientMessages(void);

/* line 483 */
__attribute__((naked))
void SV_UpdateServerCommandsToClient(client_t *client, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 483 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* client */
        /* { scope 1 */
        "movl 0x20810(%edi), %edx\n" /* line 490 | client */
        "leal 1(%edx), %eax\n"
        "cmpl GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(%edi), %eax\n" /* client */
        "jge .Lf191f90_00191fbe\n"
        "movl 0x195f278, %eax\n" /* line 492 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf191f90_0019205e\n"
        ".Lf191f90_00191fbe:\n"
        "leal 1(%edx), %ebx\n" /* line 501 | i */
        "movl GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(%edi), %eax\n" /* client */
        "cmpl %eax, %ebx\n" /* i */
        "jle .Lf191f90_00192005\n"
        ".Lf191f90_00191fcb:\n"
        "movl %eax, 0x20814(%edi)\n" /* line 515 | client */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 516 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191f90_00191fd9:\n"
        "movl %esi, 8(%esp)\n" /* line 508 */
        "movl %ebx, %eax\n" /* i */
        "subl 0x20810(%edi), %eax\n" /* client */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b03cc, (%esp)\n" /* "%i: %s
" */
        "calll Com_Printf\n"
        ".Lf191f90_00191ff8:\n"
        "addl $1, %ebx\n" /* line 501 | i */
        "movl GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(%edi), %eax\n" /* client */
        "cmpl %ebx, %eax\n" /* i */
        "jl .Lf191f90_00191fcb\n"
        ".Lf191f90_00192005:\n"
        "movl $4, 4(%esp)\n" /* line 503 */
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl %ebx, 4(%esp)\n" /* line 504 | i */
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %ebx, %eax\n" /* line 505 | i */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal 0x400(%edx, %eax, 8), %eax\n"
        "leal 0xc(%edi, %eax), %esi\n" /* client */
        "movl %esi, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteString\n"
        "movl 0x195f278, %edx\n" /* line 507 */
        "movl (%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf191f90_00191ff8\n"
        "jmp .Lf191f90_00191fd9\n"
        ".Lf191f90_0019205e:\n"
        "leal 0x20c48(%edi), %eax\n" /* line 493 | client */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b0390, (%esp)\n" /* "Client %s has the following un-ack'd reliable commands:
" */
        "calll Com_Printf\n"
        "movl 0x20810(%edi), %edx\n" /* client */
        "jmp .Lf191f90_00191fbe\n"
    );
}

/* line 836 */
static __attribute__((naked))
cachedSnapshot_t * SV_GetCachedSnapshotInternal(void)
{
    __asm__ __volatile__ (
        ".Lf192080_00192080:\n"
        "pushl %ebp\n" /* line 836 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* archivedFrame */
        /* { scope 1 */
        "movl $0x20000, 4(%esp)\n" /* line 853 */
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* msg_buf_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x44(%ebp)\n" /* msg_buf */
        "movl $0x1b4e81b5, %edx\n" /* line 855 */
        "movl %edi, %eax\n" /* oldnum */
        "imull %edx\n"
        "sarl $7, %edx\n"
        "movl %edi, %eax\n" /* oldnum */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edi, %edx\n" /* oldnum */
        "subl %eax, %edx\n"
        "movl 0x195f284, %ecx\n"
        "movl 0x30(%ecx), %eax\n"
        "leal (%eax, %edx, 8), %esi\n" /* partSize */
        "movl 0x38(%ecx), %eax\n" /* line 856 */
        "subl $0x2000000, %eax\n"
        "cmpl %eax, (%esi)\n" /* partSize */
        "jl .Lf192080_001921e2\n"
        "movl 0x44(%ecx), %eax\n" /* line 860 */
        "movl %eax, %ebx\n" /* line 861 | oldArchivedFrame */
        "subl $0x200, %ebx\n" /* oldArchivedFrame */
        "movl $0, %edx\n"
        "cmovsl %edx, %ebx\n" /* oldArchivedFrame */
        "leal -1(%eax), %ecx\n" /* line 864 */
        "cmpl %ecx, %ebx\n" /* oldArchivedFrame */
        "jg .Lf192080_00192154\n"
        "movl 0x195f284, %edx\n" /* line 866 */
        "movl 0x50(%edx), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %ecx, %edx\n"
        "andl $0x800001ff, %edx\n"
        "js .Lf192080_00192537\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "addl -0x40(%ebp), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* cachedFrame */
        "cmpl (%edx), %edi\n" /* line 867 | oldnum */
        "jne .Lf192080_00192221\n"
        ".Lf192080_0019213a:\n"
        "movl -0x54(%ebp), %ecx\n" /* cachedFrame */
        "movl 0x195f284, %edx\n" /* line 869 */
        "movl 0x3c(%edx), %eax\n"
        "subl $0x4000, %eax\n"
        "cmpl %eax, 0xc(%ecx)\n"
        "jge .Lf192080_00192265\n"
        ".Lf192080_00192154:\n"
        "movl $0x20000, 8(%esp)\n" /* line 876 */
        "movl -0x44(%ebp), %eax\n" /* msg_buf */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 4(%esi), %ecx\n" /* line 877 | partSize */
        "movl %ecx, -0x28(%ebp)\n"
        "movl (%esi), %edx\n" /* line 879 | partSize */
        "andl $0x81ffffff, %edx\n"
        "js .Lf192080_00192562\n"
        ".Lf192080_00192182:\n"
        "movl $0x2000000, %esi\n" /* line 881 | partSize */
        "subl %edx, %esi\n" /* partSize */
        "cmpl %esi, %ecx\n" /* line 882 | partSize */
        "jg .Lf192080_0019227b\n"
        "movl 0x195f284, %eax\n" /* line 884 */
        "addl 0x34(%eax), %edx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        ".Lf192080_001921ac:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 892 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadBit\n"
        "testl %eax, %eax\n"
        "jne .Lf192080_001922b9\n"
        "leal -0x34(%ebp), %eax\n" /* line 894 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, %ebx\n" /* oldArchivedFrame */
        "movl 0x195f284, %esi\n" /* line 896 | partSize */
        "movl 0x2c(%esi), %eax\n" /* partSize */
        "subl $0x4b0, %eax\n"
        "cmpl %eax, %ebx\n" /* oldArchivedFrame */
        "jge .Lf192080_00192584\n"
        ".Lf192080_001921e2:\n"
        "movl $0, -0x54(%ebp)\n" /* line 1097 | cachedFrame */
        ".Lf192080_001921e9:\n"
        "leal -0x1c(%ebp), %ecx\n" /* msg_buf_large_local */
        "movl %ecx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "movl -0x54(%ebp), %eax\n" /* line 1098 | cachedFrame */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf192080_001921ff:\n"
        "subl $1, %edx\n" /* line 866 */
        "orl $0xfffffe00, %edx\n"
        "addl $1, %edx\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "addl -0x40(%ebp), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* cachedFrame */
        "cmpl (%edx), %edi\n" /* line 867 | oldnum */
        "je .Lf192080_0019224c\n"
        ".Lf192080_00192221:\n"
        "subl $1, %ecx\n" /* line 864 */
        "cmpl %ecx, %ebx\n" /* oldArchivedFrame */
        "jg .Lf192080_00192154\n"
        "movl %ecx, %edx\n" /* line 866 */
        "andl $0x800001ff, %edx\n"
        "js .Lf192080_001921ff\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "addl -0x40(%ebp), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* cachedFrame */
        "cmpl (%edx), %edi\n" /* line 867 | oldnum */
        "jne .Lf192080_00192221\n"
        ".Lf192080_0019224c:\n"
        "movl %edx, %ecx\n"
        "movl 0x195f284, %edx\n" /* line 869 */
        "movl 0x3c(%edx), %eax\n"
        "subl $0x4000, %eax\n"
        "cmpl %eax, 0xc(%ecx)\n"
        "jl .Lf192080_00192154\n"
        ".Lf192080_00192265:\n"
        "movl 0x40(%edx), %eax\n" /* line 871 */
        "subl $__mh_execute_header, %eax\n"
        "cmpl %eax, 0x14(%ecx)\n"
        "jl .Lf192080_00192154\n"
        "jmp .Lf192080_001921e9\n"
        ".Lf192080_0019227b:\n"
        "movl 0x195f284, %ebx\n" /* line 888 | oldArchivedFrame */
        "addl 0x34(%ebx), %edx\n" /* oldArchivedFrame */
        "movl %esi, 8(%esp)\n" /* partSize */
        "movl %edx, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl %esi, %ecx\n" /* line 889 | partSize */
        "addl -0x30(%ebp), %ecx\n"
        "movl -0x28(%ebp), %eax\n"
        "subl %esi, %eax\n" /* partSize */
        "movl 0x34(%ebx), %edx\n" /* oldArchivedFrame */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf192080_001921ac\n"
        ".Lf192080_001922b9:\n"
        "movl 0x195f284, %ebx\n" /* line 1031 | oldArchivedFrame */
        "movl 0x44(%ebx), %edx\n" /* oldArchivedFrame */
        "andl $0x800001ff, %edx\n"
        "js .Lf192080_00192573\n"
        ".Lf192080_001922ce:\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x50(%ebx), %eax\n" /* oldArchivedFrame */
        "addl %eax, %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* cachedFrame */
        "movl %edi, (%edx)\n" /* line 1033 | oldnum */
        "movl $0, 8(%edx)\n" /* line 1034 */
        "movl 0x3c(%ebx), %eax\n" /* line 1035 | oldArchivedFrame */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 0x10(%edx)\n" /* line 1036 */
        "movl 0x40(%ebx), %eax\n" /* line 1037 | oldArchivedFrame */
        "movl %eax, 0x14(%edx)\n"
        "movl $0, 0x18(%edx)\n" /* line 1038 */
        "leal -0x34(%ebp), %edx\n" /* line 1039 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl -0x54(%ebp), %ecx\n" /* cachedFrame */
        "movl %eax, 4(%ecx)\n"
        "movl %ebx, %esi\n" /* oldArchivedFrame, partSize */
        "jmp .Lf192080_00192335\n"
        ".Lf192080_0019231a:\n"
        "movl 0x40(%esi), %eax\n" /* line 1058 | partSize */
        "addl $1, %eax\n"
        "movl %eax, 0x40(%esi)\n" /* partSize */
        "cmpl $0x7ffffffd, %eax\n" /* line 1060 */
        "jg .Lf192080_001923fc\n"
        ".Lf192080_0019232e:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1062 | cachedFrame */
        "addl $1, 0x10(%ecx)\n"
        ".Lf192080_00192335:\n"
        "leal -0x34(%ebp), %eax\n" /* line 1043 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadBit\n"
        "testl %eax, %eax\n"
        "je .Lf192080_00192430\n"
        "movl $6, 4(%esp)\n" /* line 1047 */
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %edi\n" /* oldnum */
        "movl -0x24(%ebp), %eax\n" /* line 1049 */
        "cmpl -0x28(%ebp), %eax\n"
        "jle .Lf192080_00192379\n"
        "movl $0x2b0418, 4(%esp)\n" /* line 1050 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf192080_00192379:\n"
        "movl 0x40(%esi), %edx\n" /* line 1052 | partSize */
        "andl $0x80000fff, %edx\n"
        "js .Lf192080_001924d4\n"
        ".Lf192080_00192388:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x4c(%esi), %edx\n" /* partSize */
        "leal (%edx, %eax, 8), %ebx\n" /* oldArchivedFrame */
        "movl %edi, 0xc(%esp)\n" /* line 1053 | oldnum */
        "leal 4(%ebx), %eax\n" /* oldArchivedFrame */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadDeltaClient\n"
        "leal -0x34(%ebp), %eax\n" /* line 1054 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadBit\n"
        "movl %eax, (%ebx)\n" /* oldArchivedFrame */
        "testl %eax, %eax\n" /* line 1055 */
        "je .Lf192080_0019231a\n"
        "leal 0x60(%ebx), %eax\n" /* line 1056 | oldArchivedFrame */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadDeltaPlayerstate\n"
        "movl 0x40(%esi), %eax\n" /* line 1058 | partSize */
        "addl $1, %eax\n"
        "movl %eax, 0x40(%esi)\n" /* partSize */
        "cmpl $0x7ffffffd, %eax\n" /* line 1060 */
        "jle .Lf192080_0019232e\n"
        ".Lf192080_001923fc:\n"
        "movl $0x2b0440, 4(%esp)\n" /* line 1061 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192080_0019232e\n"
        ".Lf192080_00192415:\n"
        "movl $0x2b0468, 4(%esp)\n" /* line 1082 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf192080_00192429:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1083 | cachedFrame */
        "addl $1, 8(%ecx)\n"
        ".Lf192080_00192430:\n"
        "movl $0xa, 4(%esp)\n" /* line 1068 */
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %ebx\n" /* oldArchivedFrame */
        "cmpl $0x3ff, %eax\n" /* line 1070 */
        "je .Lf192080_001924f3\n"
        "movl -0x24(%ebp), %eax\n" /* line 1073 */
        "cmpl -0x28(%ebp), %eax\n"
        "jle .Lf192080_0019246c\n"
        "movl $0x2b0418, 4(%esp)\n" /* line 1074 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf192080_0019246c:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1077 | oldArchivedFrame */
        "movl 0x195f284, %esi\n" /* partSize */
        "movl 0x3c(%esi), %edx\n" /* partSize */
        "andl $0x80003fff, %edx\n"
        "js .Lf192080_001924e5\n"
        ".Lf192080_00192481:\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x48(%esi), %edx\n" /* partSize */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal (%ebx, %ebx, 2), %edx\n" /* oldArchivedFrame */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x195ee80, %edx\n"
        "leal 0x241c(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadDeltaArchivedEntity\n"
        "movl 0x3c(%esi), %eax\n" /* line 1079 | partSize */
        "addl $1, %eax\n"
        "movl %eax, 0x3c(%esi)\n" /* partSize */
        "cmpl $0x7ffffffd, %eax\n" /* line 1081 */
        "jle .Lf192080_00192429\n"
        "jmp .Lf192080_00192415\n"
        ".Lf192080_001924d4:\n"
        "subl $1, %edx\n" /* line 1052 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_00192388\n"
        ".Lf192080_001924e5:\n"
        "subl $1, %edx\n" /* line 1077 */
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_00192481\n"
        ".Lf192080_001924f3:\n"
        "movl 0x195f284, %eax\n" /* line 1086 */
        "movl 0x44(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x44(%eax)\n"
        "cmpl $0x7ffffffd, %edx\n" /* line 1088 */
        "jle .Lf192080_001921e9\n"
        "movl $0x2b0490, 4(%esp)\n" /* line 1089 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 1097 | msg_buf_large_local */
        "movl %ecx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "movl -0x54(%ebp), %eax\n" /* line 1098 | cachedFrame */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf192080_00192537:\n"
        "subl $1, %edx\n" /* line 866 */
        "orl $0xfffffe00, %edx\n"
        "addl $1, %edx\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "addl -0x40(%ebp), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* cachedFrame */
        "cmpl (%edx), %edi\n" /* line 867 | oldnum */
        "jne .Lf192080_00192221\n"
        "jmp .Lf192080_0019213a\n"
        ".Lf192080_00192562:\n"
        "subl $1, %edx\n" /* line 879 */
        "orl $0xfe000000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_00192182\n"
        ".Lf192080_00192573:\n"
        "subl $1, %edx\n" /* line 1031 */
        "orl $0xfffffe00, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_001922ce\n"
        ".Lf192080_00192584:\n"
        "movl $0x1b4e81b5, %edx\n" /* line 900 */
        "movl %ebx, %eax\n" /* oldArchivedFrame */
        "imull %edx\n"
        "sarl $7, %edx\n"
        "movl %ebx, %eax\n" /* oldArchivedFrame */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %ebx, %ecx\n" /* oldArchivedFrame */
        "subl %eax, %ecx\n"
        "movl 0x30(%esi), %edx\n" /* partSize */
        "movl 0x38(%esi), %eax\n" /* partSize */
        "subl $0x2000000, %eax\n"
        "cmpl %eax, (%edx, %ecx, 8)\n"
        "jl .Lf192080_001921e2\n"
        "movl %ebx, %eax\n" /* line 903 | oldArchivedFrame */
        "calll SV_GetCachedSnapshotInternal\n"
        "movl %eax, -0x50(%ebp)\n" /* oldCachedFrame */
        "testl %eax, %eax\n" /* line 904 */
        "je .Lf192080_001921e2\n"
        "movl 0x44(%esi), %edx\n" /* line 908 | partSize */
        "andl $0x800001ff, %edx\n"
        "js .Lf192080_00192a26\n"
        ".Lf192080_001925dd:\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x50(%esi), %ecx\n" /* partSize */
        "addl %ecx, %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* cachedFrame */
        "movl %edi, (%edx)\n" /* line 910 | oldnum */
        "movl $0, 8(%edx)\n" /* line 911 */
        "movl 0x3c(%esi), %eax\n" /* line 912 | partSize */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 0x10(%edx)\n" /* line 913 */
        "movl 0x40(%esi), %eax\n" /* line 914 | partSize */
        "movl %eax, 0x14(%edx)\n"
        "movl $1, 0x18(%edx)\n" /* line 915 */
        "leal -0x34(%ebp), %eax\n" /* line 916 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl -0x54(%ebp), %edx\n" /* cachedFrame */
        "movl %eax, 4(%edx)\n"
        "movl -0x50(%ebp), %ecx\n" /* line 922 | oldCachedFrame */
        "movl 0x10(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf192080_00192a15\n"
        "movl -0x50(%ebp), %eax\n" /* line 928 | oldCachedFrame */
        "movl 0x14(%eax), %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192080_00192a04\n"
        ".Lf192080_00192645:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x4c(%esi), %edx\n" /* partSize */
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* oldCachedClient */
        "movl 4(%eax), %edi\n" /* line 929 | oldnum */
        ".Lf192080_0019265e:\n"
        "movl $0, -0x48(%ebp)\n" /* oldindex */
        ".Lf192080_00192665:\n"
        "leal -0x34(%ebp), %edx\n" /* line 934 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadBit\n"
        "testl %eax, %eax\n"
        "je .Lf192080_0019279c\n"
        "movl $6, 4(%esp)\n" /* line 938 */
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %esi\n" /* partSize */
        "movl -0x24(%ebp), %eax\n" /* line 940 */
        "cmpl -0x28(%ebp), %eax\n"
        "jg .Lf192080_00192855\n"
        ".Lf192080_00192699:\n"
        "cmpl %esi, %edi\n" /* line 943 | partSize, oldnum */
        "jge .Lf192080_001926f7\n"
        "movl -0x50(%ebp), %eax\n" /* line 948 | oldCachedFrame */
        "movl 0x10(%eax), %ebx\n" /* oldArchivedFrame */
        "movl 0x195f284, %edx\n" /* line 954 */
        "movl 0x4c(%edx), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl -0x48(%ebp), %ecx\n" /* oldindex */
        "addl 0x14(%eax), %ecx\n"
        "jmp .Lf192080_001926c0\n"
        ".Lf192080_001926b7:\n"
        "movl $0x1869f, %edi\n" /* line 948 | oldnum */
        "cmpl %edi, %esi\n" /* line 943 | oldnum, partSize */
        "jle .Lf192080_001926f7\n"
        ".Lf192080_001926c0:\n"
        "addl $1, -0x48(%ebp)\n" /* line 946 | oldindex */
        "addl $1, %ecx\n"
        "cmpl -0x48(%ebp), %ebx\n" /* line 948 | oldindex, oldArchivedFrame */
        "jle .Lf192080_001926b7\n"
        "movl %ecx, %edx\n" /* line 954 */
        "andl $0x80000fff, %edx\n"
        "js .Lf192080_00192844\n"
        ".Lf192080_001926da:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* oldCachedClient */
        "movl 4(%eax), %edi\n" /* line 955 | oldnum */
        "cmpl %edi, %esi\n" /* line 943 | oldnum, partSize */
        "jg .Lf192080_001926c0\n"
        ".Lf192080_001926f7:\n"
        "cmpl %esi, %edi\n" /* line 959 | partSize, oldnum */
        "je .Lf192080_0019286e\n"
        "movl 0x195f284, %eax\n" /* line 990 */
        "movl 0x40(%eax), %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192080_00192970\n"
        "movl %eax, %ecx\n"
        ".Lf192080_00192715:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x4c(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n" /* oldArchivedFrame */
        "movl %esi, 0xc(%esp)\n" /* line 991 | partSize */
        "leal 4(%ebx), %eax\n" /* oldArchivedFrame */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadDeltaClient\n"
        "leal -0x34(%ebp), %edx\n" /* line 992 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadBit\n"
        "movl %eax, (%ebx)\n" /* oldArchivedFrame */
        "testl %eax, %eax\n" /* line 993 */
        "jne .Lf192080_00192951\n"
        ".Lf192080_0019275b:\n"
        "movl 0x195f284, %edx\n" /* line 996 */
        "movl 0x40(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x40(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 998 */
        "jg .Lf192080_00192938\n"
        ".Lf192080_00192775:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1000 | cachedFrame */
        "addl $1, 0x10(%ecx)\n"
        "jmp .Lf192080_00192665\n"
        ".Lf192080_00192781:\n"
        "movl $0x2b0468, 4(%esp)\n" /* line 1020 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf192080_00192795:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1021 | cachedFrame */
        "addl $1, 8(%ecx)\n"
        ".Lf192080_0019279c:\n"
        "movl $0xa, 4(%esp)\n" /* line 1006 */
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %ebx\n" /* oldArchivedFrame */
        "cmpl $0x3ff, %eax\n" /* line 1008 */
        "je .Lf192080_001924f3\n"
        "movl -0x24(%ebp), %eax\n" /* line 1011 */
        "cmpl -0x28(%ebp), %eax\n"
        "jle .Lf192080_001927d8\n"
        "movl $0x2b0418, 4(%esp)\n" /* line 1012 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf192080_001927d8:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1015 | oldArchivedFrame */
        "movl 0x195f284, %esi\n" /* partSize */
        "movl 0x3c(%esi), %edx\n" /* partSize */
        "andl $0x80003fff, %edx\n"
        "js .Lf192080_001929cb\n"
        ".Lf192080_001927f1:\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x48(%esi), %edx\n" /* partSize */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal (%ebx, %ebx, 2), %edx\n" /* oldArchivedFrame */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x195ee80, %edx\n"
        "leal 0x241c(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadDeltaArchivedEntity\n"
        "movl 0x3c(%esi), %eax\n" /* line 1017 | partSize */
        "addl $1, %eax\n"
        "movl %eax, 0x3c(%esi)\n" /* partSize */
        "cmpl $0x7ffffffd, %eax\n" /* line 1019 */
        "jle .Lf192080_00192795\n"
        "jmp .Lf192080_00192781\n"
        ".Lf192080_00192844:\n"
        "subl $1, %edx\n" /* line 954 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_001926da\n"
        ".Lf192080_00192855:\n"
        "movl $0x2b0418, 4(%esp)\n" /* line 941 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192080_00192699\n"
        ".Lf192080_0019286e:\n"
        "movl 0x195f284, %ecx\n" /* line 961 */
        "movl 0x40(%ecx), %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192080_001929dc\n"
        ".Lf192080_00192883:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x4c(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n" /* oldArchivedFrame */
        "movl %esi, 0xc(%esp)\n" /* line 962 | partSize */
        "leal 4(%ebx), %eax\n" /* oldArchivedFrame */
        "movl %eax, 8(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* oldCachedClient */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadDeltaClient\n"
        "leal -0x34(%ebp), %edx\n" /* line 963 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadBit\n"
        "movl %eax, (%ebx)\n" /* oldArchivedFrame */
        "testl %eax, %eax\n" /* line 964 */
        "jne .Lf192080_001929aa\n"
        ".Lf192080_001928cb:\n"
        "movl 0x195f284, %edx\n" /* line 967 */
        "movl 0x40(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x40(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 969 */
        "jg .Lf192080_00192991\n"
        ".Lf192080_001928e5:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 971 | cachedFrame */
        "addl $1, 0x10(%ecx)\n"
        "addl $1, -0x48(%ebp)\n" /* line 973 | oldindex */
        "movl -0x48(%ebp), %edx\n" /* line 975 | oldindex */
        "movl -0x50(%ebp), %eax\n" /* oldCachedFrame */
        "cmpl 0x10(%eax), %edx\n"
        "jge .Lf192080_00192987\n"
        "movl %eax, %ecx\n"
        "movl %edx, %eax\n" /* line 981 */
        "addl 0x14(%ecx), %eax\n"
        "movl %eax, %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192080_001929f3\n"
        ".Lf192080_00192914:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x195f284, %ecx\n"
        "movl 0x4c(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* oldCachedClient */
        "movl 4(%eax), %edi\n" /* line 982 | oldnum */
        "jmp .Lf192080_00192665\n"
        ".Lf192080_00192938:\n"
        "movl $0x2b0440, 4(%esp)\n" /* line 999 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192080_00192775\n"
        ".Lf192080_00192951:\n"
        "leal 0x60(%ebx), %eax\n" /* line 994 | oldArchivedFrame */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadDeltaPlayerstate\n"
        "jmp .Lf192080_0019275b\n"
        ".Lf192080_00192970:\n"
        "subl $1, %edx\n" /* line 990 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "movl 0x195f284, %ecx\n"
        "jmp .Lf192080_00192715\n"
        ".Lf192080_00192987:\n"
        "movl $0x1869f, %edi\n" /* line 929 | oldnum */
        "jmp .Lf192080_00192665\n"
        ".Lf192080_00192991:\n"
        "movl $0x2b0440, 4(%esp)\n" /* line 970 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192080_001928e5\n"
        ".Lf192080_001929aa:\n"
        "leal 0x60(%ebx), %eax\n" /* line 965 | oldArchivedFrame */
        "movl %eax, 8(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* oldCachedClient */
        "addl $0x60, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadDeltaPlayerstate\n"
        "jmp .Lf192080_001928cb\n"
        ".Lf192080_001929cb:\n"
        "subl $1, %edx\n" /* line 1015 */
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_001927f1\n"
        ".Lf192080_001929dc:\n"
        "subl $1, %edx\n" /* line 961 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "movl 0x195f284, %ecx\n"
        "jmp .Lf192080_00192883\n"
        ".Lf192080_001929f3:\n"
        "subl $1, %edx\n" /* line 981 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_00192914\n"
        ".Lf192080_00192a04:\n"
        "subl $1, %edx\n" /* line 928 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_00192645\n"
        ".Lf192080_00192a15:\n"
        "movl $0, -0x4c(%ebp)\n" /* line 922 | oldCachedClient */
        "movl $0x1869f, %edi\n" /* oldnum */
        "jmp .Lf192080_0019265e\n"
        ".Lf192080_00192a26:\n"
        "subl $1, %edx\n" /* line 908 */
        "orl $0xfffffe00, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192080_001925dd\n"
        "movl %eax, %ebx\n" /* oldArchivedFrame */
        "leal -0x1c(%ebp), %eax\n" /* line 1097 | msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* oldArchivedFrame */
        "calll __Unwind_Resume\n"
    );
}

/* line 1772 */
__attribute__((naked))
void SV_ArchiveSnapshot(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1772 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x282c, %esp\n"
        /* { scope 1 */
        "movl $0x20000, 4(%esp)\n" /* line 1795 */
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* msg_buf_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %edx\n"
        "movl 0x195ee80, %eax\n" /* line 1800 */
        "cmpl $2, (%eax)\n"
        "je .Lf192a4c_00192a98\n"
        ".Lf192a4c_00192a82:\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 2067 | msg_buf_large_local */
        "movl %ecx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x282c, %esp\n" /* line 2068 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf192a4c_00192a98:\n"
        "movl 0x195f284, %edi\n" /* line 1803 | c */
        "movl 0x28(%edi), %eax\n" /* c */
        "testl %eax, %eax\n"
        "je .Lf192a4c_00192a82\n"
        "movl $0x20000, 8(%esp)\n" /* line 1814 */
        "movl %edx, 4(%esp)\n"
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 0x44(%edi), %edx\n" /* line 1816 | c */
        "movl %edx, %esi\n" /* line 1817 | oldindex */
        "subl $0x200, %esi\n" /* oldindex */
        "movl $0, %eax\n"
        "cmovsl %eax, %esi\n" /* oldindex */
        "movl 0x195f2f8, %eax\n" /* line 1820 */
        "movl (%eax), %eax\n"
        "movl 0x2c(%edi), %ebx\n" /* c, newnum */
        "subl 8(%eax), %ebx\n" /* newnum */
        "subl $1, %edx\n" /* line 1822 */
        "cmpl %edx, %esi\n" /* oldindex */
        "jg .Lf192a4c_00192b30\n"
        "movl 0x50(%edi), %edi\n" /* line 1824 | c */
        "movl %edi, -0x2800(%ebp)\n" /* c */
        "jmp .Lf192a4c_00192b18\n"
        ".Lf192a4c_00192aee:\n"
        "leal (, %ecx, 4), %eax\n"
        "shll $5, %ecx\n"
        "subl %eax, %ecx\n"
        "movl -0x2800(%ebp), %edi\n" /* c */
        "addl %ecx, %edi\n" /* c */
        "cmpl (%edi), %ebx\n" /* line 1825 | c, newnum */
        "jg .Lf192a4c_00192b11\n"
        "movl 0x18(%edi), %eax\n" /* line 1827 | c */
        "testl %eax, %eax\n"
        "je .Lf192a4c_00193093\n"
        ".Lf192a4c_00192b11:\n"
        "subl $1, %edx\n" /* line 1822 */
        "cmpl %edx, %esi\n" /* oldindex */
        "jg .Lf192a4c_00192b30\n"
        ".Lf192a4c_00192b18:\n"
        "movl %edx, %ecx\n" /* line 1824 */
        "andl $0x800001ff, %ecx\n"
        "jns .Lf192a4c_00192aee\n"
        "subl $1, %ecx\n"
        "orl $0xfffffe00, %ecx\n"
        "addl $1, %ecx\n"
        "jmp .Lf192a4c_00192aee\n"
        ".Lf192a4c_00192b30:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1944 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "movl 0x195f284, %ebx\n" /* line 1945 | newnum */
        "movl 4(%ebx), %eax\n" /* newnum */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl 0x44(%ebx), %edx\n" /* line 1948 | newnum */
        "andl $0x800001ff, %edx\n"
        "js .Lf192a4c_0019302e\n"
        ".Lf192a4c_00192b62:\n"
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x50(%ebx), %ecx\n" /* newnum */
        "addl %ecx, %edx\n"
        "movl %edx, -0x2810(%ebp)\n" /* cachedFrame */
        "movl 0x2c(%ebx), %eax\n" /* line 1950 | newnum */
        "movl %eax, (%edx)\n"
        "movl $0, 8(%edx)\n" /* line 1951 */
        "movl 0x3c(%ebx), %eax\n" /* line 1952 | newnum */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 0x10(%edx)\n" /* line 1953 */
        "movl 0x40(%ebx), %eax\n" /* line 1954 | newnum */
        "movl %eax, 0x14(%edx)\n"
        "movl $0, 0x18(%edx)\n" /* line 1955 */
        "movl 4(%ebx), %eax\n" /* line 1956 | newnum */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebx), %edi\n" /* line 1958 | newnum, c */
        "movl 0x195f290, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf192a4c_00192d11\n"
        "movl $0, -0x27fc(%ebp)\n"
        "movl %ebx, -0x2814(%ebp)\n" /* newnum */
        "movl %ebx, -0x2818(%ebp)\n" /* newnum */
        "movl %edx, -0x281c(%ebp)\n"
        "jmp .Lf192a4c_00192c43\n"
        ".Lf192a4c_00192bd9:\n"
        "leal -0x34(%ebp), %eax\n" /* line 1970 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "movl %ebx, 8(%esp)\n" /* line 1971 | newnum */
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "movl -0x2814(%ebp), %edx\n" /* line 1978 */
        "movl 0x40(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x40(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 1980 */
        "jg .Lf192a4c_00192cf8\n"
        ".Lf192a4c_00192c15:\n"
        "movl -0x2810(%ebp), %ecx\n" /* line 1982 | cachedFrame */
        "addl $1, 0x10(%ecx)\n"
        "movl -0x281c(%ebp), %edx\n"
        ".Lf192a4c_00192c25:\n"
        "addl $1, -0x27fc(%ebp)\n" /* line 1958 */
        "addl $0x78f0c, %edi\n" /* c */
        "movl (%edx), %eax\n"
        "movl -0x27fc(%ebp), %ecx\n"
        "cmpl 8(%eax), %ecx\n"
        "jge .Lf192a4c_00192d11\n"
        ".Lf192a4c_00192c43:\n"
        "cmpl $1, (%edi)\n" /* line 1960 | c */
        "jle .Lf192a4c_00192c25\n"
        "movl -0x2818(%ebp), %ecx\n" /* line 1963 */
        "movl 0x40(%ecx), %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192a4c_00192e30\n"
        ".Lf192a4c_00192c5d:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x4c(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %esi\n" /* oldindex */
        "movl -0x27fc(%ebp), %eax\n" /* line 1965 */
        "movl %eax, (%esp)\n"
        "calll G_GetClientState\n"
        "leal 4(%esi), %ebx\n" /* oldindex, newnum */
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll memcpy\n"
        "movl $1, 0xc(%esp)\n" /* line 1966 */
        "movl %ebx, 8(%esp)\n" /* newnum */
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "leal 0x60(%esi), %ebx\n" /* line 1967 | oldindex, newnum */
        "movl %ebx, 4(%esp)\n" /* newnum */
        "movl -0x27fc(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll GetFollowPlayerState\n"
        "movl %eax, (%esi)\n" /* oldindex */
        "testl %eax, %eax\n" /* line 1968 */
        "jne .Lf192a4c_00192bd9\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1975 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl -0x2814(%ebp), %edx\n" /* line 1978 */
        "movl 0x40(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x40(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 1980 */
        "jle .Lf192a4c_00192c15\n"
        ".Lf192a4c_00192cf8:\n"
        "movl $0x2b0440, 4(%esp)\n" /* line 1981 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192a4c_00192c15\n"
        ".Lf192a4c_00192d11:\n"
        "leal -0x34(%ebp), %eax\n" /* line 1985 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl 0x195ee80, %eax\n" /* line 1987 */
        "movl 0x5f424(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf192a4c_00192ea9\n"
        ".Lf192a4c_00192d2f:\n"
        "movl 0x195f284, %eax\n" /* line 2026 */
        "movl 0x44(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x44(%eax)\n"
        "cmpl $0x7ffffffd, %edx\n" /* line 2028 */
        "jg .Lf192a4c_00192e90\n"
        ".Lf192a4c_00192d49:\n"
        "movl $0xa, 8(%esp)\n" /* line 2032 */
        "movl $0x3ff, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBits\n"
        "movl -0x34(%ebp), %ebx\n" /* line 2034 | msg, newnum */
        "testl %ebx, %ebx\n" /* newnum */
        "jne .Lf192a4c_00192e7f\n"
        "movl 0x195f284, %edi\n" /* line 2041 | c */
        "movl 0x2c(%edi), %ecx\n" /* c */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $7, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %eax, %ecx\n"
        "movl 0x30(%edi), %eax\n" /* c */
        "leal (%eax, %ecx, 8), %ecx\n"
        "movl 0x38(%edi), %eax\n" /* line 2042 | c */
        "movl %eax, (%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2043 */
        "movl %eax, 4(%ecx)\n"
        "movl 0x38(%edi), %eax\n" /* line 2044 | c */
        "movl %eax, %ebx\n" /* newnum */
        "andl $0x81ffffff, %ebx\n" /* newnum */
        "js .Lf192a4c_00193082\n"
        ".Lf192a4c_00192dbc:\n"
        "movl -0x28(%ebp), %edx\n" /* line 2046 */
        "addl %edx, %eax\n"
        "movl %eax, 0x38(%edi)\n" /* c */
        "cmpl $0x7ffffffd, %eax\n" /* line 2048 */
        "jg .Lf192a4c_00193012\n"
        ".Lf192a4c_00192dcf:\n"
        "movl $0x2000000, %esi\n" /* line 2051 | oldindex */
        "subl %ebx, %esi\n" /* newnum, oldindex */
        "cmpl %edx, %esi\n" /* line 2052 | oldindex */
        "jl .Lf192a4c_00192e47\n"
        "addl 0x34(%edi), %ebx\n" /* line 2054 | c, newnum */
        "movl %edx, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll memcpy\n"
        ".Lf192a4c_00192df0:\n"
        "movl 0x195f284, %eax\n" /* line 2062 */
        "movl 0x2c(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x2c(%eax)\n"
        "cmpl $0x7ffffffd, %edx\n" /* line 2064 */
        "jle .Lf192a4c_00192e1a\n"
        "movl $0x2b0520, 4(%esp)\n" /* line 2065 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf192a4c_00192e1a:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2067 | msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x282c, %esp\n" /* line 2068 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf192a4c_00192e30:\n"
        "subl $1, %edx\n" /* line 1963 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "movl -0x2818(%ebp), %ecx\n"
        "jmp .Lf192a4c_00192c5d\n"
        ".Lf192a4c_00192e47:\n"
        "addl 0x34(%edi), %ebx\n" /* line 2058 | c, newnum */
        "movl %esi, 8(%esp)\n" /* oldindex */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll memcpy\n"
        "movl 0x34(%edi), %ecx\n" /* line 2059 | c */
        "movl -0x28(%ebp), %edx\n"
        "subl %esi, %edx\n" /* oldindex */
        "movl %esi, %eax\n" /* oldindex */
        "addl -0x30(%ebp), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf192a4c_00192df0\n"
        ".Lf192a4c_00192e7f:\n"
        "movl $0x2b04b8, (%esp)\n" /* line 2037 */
        "calll Com_DPrintf\n"
        "jmp .Lf192a4c_00192a82\n"
        ".Lf192a4c_00192e90:\n"
        "movl $0x2b0490, 4(%esp)\n" /* line 2029 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192a4c_00192d49\n"
        ".Lf192a4c_00192ea9:\n"
        "xorl %edi, %edi\n" /* line 1987 | c */
        "jmp .Lf192a4c_00192ece\n"
        ".Lf192a4c_00192ead:\n"
        "testb $1, 0xf2(%eax)\n" /* line 1997 */
        "je .Lf192a4c_0019303f\n"
        ".Lf192a4c_00192eba:\n"
        "addl $1, %edi\n" /* line 1987 | c */
        "movl 0x195ee80, %eax\n"
        "cmpl 0x5f424(%eax), %edi\n" /* c */
        "jge .Lf192a4c_00192d2f\n"
        ".Lf192a4c_00192ece:\n"
        "movl %edi, (%esp)\n" /* line 1989 | c */
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* newnum */
        "cmpb $0, 0xf0(%eax)\n" /* line 1990 */
        "je .Lf192a4c_00192eba\n"
        "movl 0x100(%eax), %esi\n" /* line 1995 | oldindex */
        "testl %esi, %esi\n" /* oldindex */
        "je .Lf192a4c_00192ead\n"
        ".Lf192a4c_00192eeb:\n"
        "movl 0x195f284, %ecx\n" /* line 2005 */
        "movl 0x3c(%ecx), %edx\n"
        "andl $0x80003fff, %edx\n"
        "js .Lf192a4c_0019306b\n"
        ".Lf192a4c_00192f00:\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x48(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %esi\n" /* oldindex */
        "movl $0xf0, 8(%esp)\n" /* line 2007 */
        "movl %ebx, 4(%esp)\n" /* newnum */
        "movl %esi, (%esp)\n" /* oldindex */
        "calll memcpy\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 2008 | newnum */
        "movl %eax, 0xf0(%esi)\n" /* oldindex */
        "movl 0x100(%ebx), %edx\n" /* line 2009 | newnum */
        "testl %edx, %edx\n"
        "je .Lf192a4c_00192f44\n"
        "orl $8, %eax\n" /* line 2010 */
        "movl %eax, 0xf0(%esi)\n" /* oldindex */
        ".Lf192a4c_00192f44:\n"
        "movl 0xf4(%ebx), %eax\n" /* line 2011 | newnum */
        "movl %eax, 0xf4(%esi)\n" /* oldindex */
        "movl 0xf8(%ebx), %eax\n" /* line 2012 | newnum */
        "movl %eax, 0xf8(%esi)\n" /* oldindex */
        "leal 0xfc(%esi), %ecx\n" /* line 2013 | oldindex, to */
        "leal 0x120(%ebx), %edx\n" /* newnum, from */
        /* { scope 2 */
        "movl 0x120(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xfc(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x108(%esi), %ecx\n" /* line 2014 | oldindex, to */
        "leal 0x12c(%ebx), %edx\n" /* newnum, from */
        /* { scope 2 */
        "movl 0x12c(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x108(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $1, 0xc(%esp)\n" /* line 2016 */
        "movl %esi, 8(%esp)\n" /* oldindex */
        "movl (%ebx), %eax\n" /* newnum */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195ee80, %eax\n"
        "leal 0x241c(%eax, %edx, 4), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaArchivedEntity\n"
        "movl 0x195f284, %edx\n" /* line 2018 */
        "movl 0x3c(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x3c(%edx)\n"
        "cmpl $0x7ffffffd, %eax\n" /* line 2021 */
        "jg .Lf192a4c_00192ffc\n"
        ".Lf192a4c_00192fed:\n"
        "movl -0x2810(%ebp), %ecx\n" /* line 2023 | cachedFrame */
        "addl $1, 8(%ecx)\n"
        "jmp .Lf192a4c_00192eba\n"
        ".Lf192a4c_00192ffc:\n"
        "movl $0x2b0468, 4(%esp)\n" /* line 2022 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf192a4c_00192fed\n"
        ".Lf192a4c_00193012:\n"
        "movl $0x2b04f8, 4(%esp)\n" /* line 2049 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf192a4c_00192dcf\n"
        ".Lf192a4c_0019302e:\n"
        "subl $1, %edx\n" /* line 1948 */
        "orl $0xfffffe00, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192a4c_00192b62\n"
        ".Lf192a4c_0019303f:\n"
        "movl %eax, (%esp)\n" /* line 2000 */
        "calll SV_SvEntityForGentity\n"
        "movl %eax, %edx\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 2001 | newnum */
        "testb $0x18, %al\n"
        "jne .Lf192a4c_00192eeb\n"
        "movl 0x118(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf192a4c_00192eba\n"
        "jmp .Lf192a4c_00192eeb\n"
        ".Lf192a4c_0019306b:\n"
        "subl $1, %edx\n" /* line 2005 */
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "movl 0x195f284, %ecx\n"
        "jmp .Lf192a4c_00192f00\n"
        ".Lf192a4c_00193082:\n"
        "subl $1, %ebx\n" /* line 2044 | newnum */
        "orl $0xfe000000, %ebx\n" /* newnum */
        "addl $1, %ebx\n" /* newnum */
        "jmp .Lf192a4c_00192dbc\n"
        ".Lf192a4c_00193093:\n"
        "movl 0x195f284, %ebx\n" /* line 1829 | newnum */
        "movl 0x3c(%ebx), %eax\n" /* newnum */
        "subl $0x4000, %eax\n"
        "cmpl %eax, 0xc(%edi)\n" /* c */
        "jl .Lf192a4c_00192b30\n"
        "movl 0x40(%ebx), %eax\n" /* line 1831 | newnum */
        "subl $__mh_execute_header, %eax\n"
        "cmpl %eax, 0x14(%edi)\n" /* c */
        "jl .Lf192a4c_00192b30\n"
        "leal -0x34(%ebp), %eax\n" /* line 1834 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl (%edi), %eax\n" /* line 1835 | c */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl 4(%ebx), %eax\n" /* line 1836 | newnum */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl 0x195f290, %eax\n" /* line 1838 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x2808(%ebp)\n" /* to_num_clients */
        "movl 0x10(%edi), %eax\n" /* line 1839 | c */
        "movl %eax, -0x2804(%ebp)\n" /* from_num_clients */
        "movl $0, -0x280c(%ebp)\n" /* cachedClient */
        "xorl %ebx, %ebx\n" /* newnum */
        "xorl %esi, %esi\n" /* oldindex */
        ".Lf192a4c_00193110:\n"
        "cmpl -0x2808(%ebp), %ebx\n" /* line 1843 | to_num_clients, newnum */
        "jl .Lf192a4c_00193173\n"
        ".Lf192a4c_00193118:\n"
        "cmpl -0x2804(%ebp), %esi\n" /* from_num_clients, oldindex */
        "jge .Lf192a4c_001932d5\n"
        ".Lf192a4c_00193124:\n"
        "movl %esi, %eax\n" /* line 1860 | oldindex */
        "addl 0x14(%edi), %eax\n" /* c */
        "movl %eax, %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf192a4c_0019329e\n"
        ".Lf192a4c_00193137:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x195f284, %ecx\n"
        "movl 0x4c(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, -0x280c(%ebp)\n" /* cachedClient */
        "movl 4(%eax), %edx\n" /* line 1861 */
        "cmpl %edx, %ebx\n" /* line 1864 | newnum */
        "je .Lf192a4c_001931b3\n"
        ".Lf192a4c_0019315d:\n"
        "jl .Lf192a4c_00193231\n" /* line 1884 */
        "leal 1(%esi), %eax\n" /* line 1904 | oldindex */
        "cmpl %edx, %ebx\n" /* newnum */
        "cmovgl %eax, %esi\n" /* oldindex */
        "cmpl -0x2808(%ebp), %ebx\n" /* line 1843 | to_num_clients, newnum */
        "jge .Lf192a4c_00193118\n"
        ".Lf192a4c_00193173:\n"
        "movl 0x195f284, %edx\n" /* line 1847 */
        "movl 0xc(%edx), %ecx\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* newnum */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n" /* newnum */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "cmpl $1, (%ecx, %edx, 4)\n"
        "jle .Lf192a4c_00193229\n"
        "cmpl -0x2804(%ebp), %esi\n" /* line 1854 | from_num_clients, oldindex */
        "jl .Lf192a4c_00193124\n"
        "movl $0x270f, %edx\n"
        "cmpl %edx, %ebx\n" /* line 1864 | newnum */
        "jne .Lf192a4c_0019315d\n"
        ".Lf192a4c_001931b3:\n"
        "movl %ebx, (%esp)\n" /* line 1869 | newnum */
        "calll G_GetClientState\n"
        "movl $1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x280c(%ebp), %eax\n" /* cachedClient */
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "leal -0x27f0(%ebp), %edx\n" /* line 1870 | ps */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll GetFollowPlayerState\n"
        "testl %eax, %eax\n"
        "je .Lf192a4c_001932c2\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1872 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "leal -0x27f0(%ebp), %eax\n" /* line 1873 | ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x280c(%ebp), %eax\n" /* cachedClient */
        "addl $0x60, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "addl $1, %esi\n" /* line 1879 | oldindex */
        ".Lf192a4c_00193229:\n"
        "addl $1, %ebx\n" /* line 1880 | newnum */
        "jmp .Lf192a4c_00193110\n"
        ".Lf192a4c_00193231:\n"
        "movl %ebx, (%esp)\n" /* line 1887 | newnum */
        "calll G_GetClientState\n"
        "movl $1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "leal -0x27f0(%ebp), %edx\n" /* line 1888 | ps */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll GetFollowPlayerState\n"
        "testl %eax, %eax\n"
        "je .Lf192a4c_001932af\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1890 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit1\n"
        "leal -0x27f0(%ebp), %eax\n" /* line 1891 | ps */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "addl $1, %ebx\n" /* line 1880 | newnum */
        "jmp .Lf192a4c_00193110\n"
        ".Lf192a4c_0019329e:\n"
        "subl $1, %edx\n" /* line 1860 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf192a4c_00193137\n"
        ".Lf192a4c_001932af:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1895 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "addl $1, %ebx\n" /* line 1880 | newnum */
        "jmp .Lf192a4c_00193110\n"
        ".Lf192a4c_001932c2:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1877 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "addl $1, %esi\n" /* line 1879 | oldindex */
        "jmp .Lf192a4c_00193229\n"
        ".Lf192a4c_001932d5:\n"
        "leal -0x34(%ebp), %eax\n" /* line 1909 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBit0\n"
        "movl 0x195ee80, %eax\n" /* line 1911 */
        "movl 0x5f424(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf192a4c_00192d49\n"
        "xorl %esi, %esi\n" /* oldindex */
        "jmp .Lf192a4c_00193318\n"
        ".Lf192a4c_001932f7:\n"
        "testb $1, 0xf2(%eax)\n" /* line 1921 */
        "je .Lf192a4c_001933e9\n"
        ".Lf192a4c_00193304:\n"
        "addl $1, %esi\n" /* line 1911 | oldindex */
        "movl 0x195ee80, %eax\n"
        "cmpl %esi, 0x5f424(%eax)\n" /* oldindex */
        "jle .Lf192a4c_00192d49\n"
        ".Lf192a4c_00193318:\n"
        "movl %esi, (%esp)\n" /* line 1913 | oldindex */
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* newnum */
        "cmpb $0, 0xf0(%eax)\n" /* line 1914 */
        "je .Lf192a4c_00193304\n"
        "movl 0x100(%eax), %edi\n" /* line 1919 | c */
        "testl %edi, %edi\n" /* c */
        "je .Lf192a4c_001932f7\n"
        ".Lf192a4c_00193335:\n"
        "leal -0x148(%ebp), %edi\n" /* line 1929 | archivedEnt, c */
        "movl $0xf0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* newnum */
        "movl %edi, (%esp)\n" /* c */
        "calll memcpy\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 1930 | newnum */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x100(%ebx), %edx\n" /* line 1931 | newnum */
        "testl %edx, %edx\n"
        "je .Lf192a4c_00193369\n"
        "orl $8, %eax\n" /* line 1932 */
        "movl %eax, -0x58(%ebp)\n"
        ".Lf192a4c_00193369:\n"
        "movl 0xf4(%ebx), %eax\n" /* line 1933 | newnum */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0xf8(%ebx), %eax\n" /* line 1934 | newnum */
        "movl %eax, -0x50(%ebp)\n"
        "leal 0x120(%ebx), %edx\n" /* newnum */
        /* { scope 2 */
        "movl 0x120(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x44(%ebp)\n"
        "leal 0x12c(%ebx), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x12c(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x38(%ebp)\n"
        /* } scope */
        "movl $1, 0xc(%esp)\n" /* line 1938 */
        "movl %edi, 8(%esp)\n" /* c */
        "movl (%ebx), %eax\n" /* newnum */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195ee80, %eax\n"
        "leal 0x241c(%eax, %edx, 4), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaArchivedEntity\n"
        "jmp .Lf192a4c_00193304\n"
        ".Lf192a4c_001933e9:\n"
        "movl %eax, (%esp)\n" /* line 1924 */
        "calll SV_SvEntityForGentity\n"
        "movl %eax, %edx\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 1925 | newnum */
        "testb $0x18, %al\n"
        "jne .Lf192a4c_00193335\n"
        "movl 0x118(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf192a4c_00193304\n"
        "jmp .Lf192a4c_00193335\n"
        "movl %eax, %ebx\n" /* newnum */
        "leal -0x1c(%ebp), %edx\n" /* line 2067 | msg_buf_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* newnum */
        "calll __Unwind_Resume\n"
    );
}

/* line 1619 */
__attribute__((naked))
void SV_SendMessageToClient(msg_t *msg, client_t *client)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1619 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* msg */
        "movl 0xc(%ebp), %ebx\n" /* client */
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 1623 */
        "leal -0x1c(%ebp), %eax\n" /* compressedBuf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* compressedBuf_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %edi\n" /* compressedSize */
        "movl 4(%esi), %eax\n" /* line 1626 | rateMsec */
        "movl (%eax), %eax\n"
        "movl %eax, (%edi)\n" /* compressedSize */
        "movl 0xc(%esi), %eax\n" /* line 1627 | rateMsec */
        "subl $4, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 4(%edi), %eax\n" /* compressedSize */
        "movl %eax, 4(%esp)\n"
        "movl 4(%esi), %eax\n" /* rateMsec */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MSG_WriteBitsCompress\n"
        "addl $4, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 1629 | client */
        "testl %eax, %eax\n"
        "je .Lf19342a_00193498\n"
        "movl %eax, 4(%esp)\n" /* line 1631 */
        "movl %ebx, (%esp)\n" /* client */
        "calll SV_DropClient\n"
        ".Lf19342a_00193498:\n"
        "movl 0x6e5b4(%ebx), %edx\n" /* line 1637 | client */
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, 0x233e4(%ebx, %eax, 4)\n" /* client */
        "movl 0x6e5b4(%ebx), %edx\n" /* line 1638 | client */
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl 0x195f284, %esi\n" /* rateMsec */
        "movl 4(%esi), %edx\n" /* rateMsec */
        "movl %edx, 0x233dc(%ebx, %eax, 4)\n" /* client */
        "movl 0x6e5b4(%ebx), %edx\n" /* line 1639 | client */
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl $0xffffffff, 0x233e0(%ebx, %eax, 4)\n" /* client */
        "movl -0x2c(%ebp), %eax\n" /* line 1642 */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* compressedSize */
        "movl %ebx, (%esp)\n" /* client */
        "calll SV_Netchan_Transmit\n"
        "cmpl $2, 0x6e5c4(%ebx)\n" /* line 1653 | client */
        "je .Lf19342a_00193550\n"
        "movl 0x6e5c4(%ebx), %ecx\n" /* client */
        "movl %ecx, -0x28(%ebp)\n"
        "movl 0x6e5c8(%ebx), %edx\n" /* client */
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* client */
        "movl %eax, -0x20(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "je .Lf19342a_0019356f\n"
        ".Lf19342a_00193550:\n"
        "movl 4(%esi), %eax\n" /* line 1655 | rateMsec */
        "subl $1, %eax\n"
        "movl %eax, 0x20d18(%ebx)\n" /* client */
        "leal -0x1c(%ebp), %edx\n" /* line 1687 | compressedBuf_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1688 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf19342a_0019356f:\n"
        "cmpl $0x5dc, -0x2c(%ebp)\n" /* line 1587 */
        "jg .Lf19342a_00193633\n"
        "movl -0x2c(%ebp), %edi\n"
        ".Lf19342a_0019357f:\n"
        "movl 0x6e5a8(%ebx), %esi\n" /* line 1591 | rate */
        "movl 0x195f268, %eax\n" /* line 1592 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf19342a_001935a6\n"
        "cmpl $0x3e7, %eax\n" /* line 1594 */
        "jle .Lf19342a_00193676\n"
        ".Lf19342a_0019359e:\n"
        "movl 8(%edx), %eax\n" /* line 1598 */
        "cmpl %eax, %esi\n" /* rate */
        "cmovgl %eax, %esi\n" /* rate */
        ".Lf19342a_001935a6:\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 1603 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal 0xbb80(, %eax, 8), %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl %esi\n" /* rate */
        "movl %eax, %esi\n" /* rate */
        "movl 0x195f2bc, %eax\n" /* line 1605 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf19342a_00193649\n"
        /* } scope */
        ".Lf19342a_001935ca:\n"
        "movl 0x6e5ac(%ebx), %eax\n" /* line 1662 | client */
        "cmpl %eax, %esi\n" /* rateMsec */
        "jge .Lf19342a_0019363d\n"
        "movl $0, 0x20d1c(%ebx)\n" /* line 1666 | client */
        "movl %eax, %esi\n" /* rateMsec */
        ".Lf19342a_001935e0:\n"
        "movl 0x195f284, %edx\n" /* line 1673 */
        "movl %esi, %eax\n" /* rateMsec */
        "addl 4(%edx), %eax\n"
        "movl %eax, 0x20d18(%ebx)\n" /* client */
        "cmpl $4, (%ebx)\n" /* line 1676 | client */
        "je .Lf19342a_00193612\n"
        "cmpb $0, 0x20c68(%ebx)\n" /* line 1681 | client */
        "jne .Lf19342a_00193612\n"
        "movl 4(%edx), %edx\n"
        "addl $0x3e8, %edx\n"
        "cmpl %edx, %eax\n"
        "jge .Lf19342a_00193612\n"
        "movl %edx, 0x20d18(%ebx)\n" /* line 1683 | client */
        ".Lf19342a_00193612:\n"
        "movl 0x195ee80, %eax\n" /* line 1687 */
        "movl -0x2c(%ebp), %edx\n"
        "addl %edx, 0x5f48c(%eax)\n"
        "leal -0x1c(%ebp), %eax\n" /* compressedBuf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1688 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19342a_00193633:\n"
        "movl $0x5dc, %edi\n" /* line 1656 | compressedSize */
        "jmp .Lf19342a_0019357f\n"
        ".Lf19342a_0019363d:\n"
        "movl $1, 0x20d1c(%ebx)\n" /* line 1670 | client */
        "jmp .Lf19342a_001935e0\n"
        /* { scope 2 */
        ".Lf19342a_00193649:\n"
        "movl 0x6e5a8(%ebx), %eax\n" /* line 1606 */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x20c48(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* rate */
        "movl $0x2b0548, (%esp)\n" /* "It would take %ims to send %i bytes to client %s (rate %i)
" */
        "calll Com_Printf\n"
        "jmp .Lf19342a_001935ca\n"
        ".Lf19342a_00193676:\n"
        "movl $0x3e8, 4(%esp)\n" /* line 1596 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl 0x195f268, %eax\n"
        "movl (%eax), %edx\n"
        "jmp .Lf19342a_0019359e\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "leal -0x1c(%ebp), %edx\n" /* line 1687 | compressedBuf_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll __Unwind_Resume\n"
    );
}

/* line 1302 */
__attribute__((naked))
qboolean SV_GetArchivedClientInfo(int clientNum, int *pArchiveTime, int (*ps)[4], void (*cs)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1302 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x195f284, %esi\n" /* line 1116 */
        "movl 0x28(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1936a8_0019372e\n"
        "movl 0xc(%ebp), %eax\n" /* line 1125 | pArchiveTime */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n" /* line 1126 */
        "jle .Lf1936a8_0019371e\n"
        "movl 0x2c(%esi), %ecx\n" /* line 1129 */
        "movl 0x195f2f8, %ebx\n" /* archivedFrame */
        "movl (%ebx), %eax\n" /* archivedFrame */
        "movl 8(%eax), %edi\n"
        "movl %edx, %ebx\n" /* archivedFrame */
        "imull %edi, %ebx\n" /* archivedFrame */
        "movl $0x10624dd3, %edx\n"
        "movl %ebx, %eax\n" /* archivedFrame */
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ebx, %eax\n" /* archivedFrame */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "leal -0x4b0(%ecx), %ebx\n" /* line 1130 | archivedFrame */
        "cmpl %ebx, %eax\n" /* archivedFrame */
        "jl .Lf1936a8_00193798\n"
        "movl %eax, %ebx\n" /* archivedFrame */
        ".Lf1936a8_00193701:\n"
        "testl %ebx, %ebx\n" /* line 1135 | archivedFrame */
        "js .Lf1936a8_00193866\n"
        ".Lf1936a8_00193709:\n"
        "cmpl %ebx, 0x2c(%esi)\n" /* line 1141 | archivedFrame */
        "jg .Lf1936a8_001937b3\n"
        ".Lf1936a8_00193712:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1149 | pArchiveTime, archivedFrame */
        "movl $0, (%ebx)\n" /* archivedFrame */
        "movl 0xc(%ebp), %eax\n" /* pArchiveTime */
        /* } scope */
        ".Lf1936a8_0019371e:\n"
        "movl (%eax), %eax\n" /* line 1315 */
        "testl %eax, %eax\n"
        "jle .Lf1936a8_00193737\n"
        ".Lf1936a8_00193724:\n"
        "xorl %eax, %eax\n" /* line 1378 */
        /* } scope */
        ".Lf1936a8_00193726:\n"
        "addl $0x2c, %esp\n" /* line 1379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1936a8_0019372e:\n"
        "movl 0xc(%ebp), %eax\n" /* pArchiveTime */
        /* { scope 1 */
        "movl (%eax), %eax\n" /* line 1315 */
        "testl %eax, %eax\n"
        "jg .Lf1936a8_00193724\n"
        ".Lf1936a8_00193737:\n"
        "movl 0xc(%esi), %ecx\n" /* line 1165 */
        "movl 8(%ebp), %edx\n" /* clientNum */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl 8(%ebp), %eax\n" /* clientNum */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "cmpl $4, (%ecx, %edx, 4)\n"
        "jne .Lf1936a8_00193724\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1167 | ps */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %ebx\n" /* clientNum, archivedFrame */
        "movl %ebx, (%esp)\n" /* archivedFrame */
        "calll GetFollowPlayerState\n"
        "testl %eax, %eax\n"
        "je .Lf1936a8_00193724\n"
        "movl %ebx, (%esp)\n" /* line 1169 | archivedFrame */
        "calll G_GetClientState\n"
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* cs */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $1, %eax\n"
        "jmp .Lf1936a8_00193726\n"
        /* { scope 2 */
        ".Lf1936a8_00193798:\n"
        "subl %ebx, %ecx\n" /* line 1133 | archivedFrame */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "cltd\n"
        "idivl %edi\n"
        "movl 0xc(%ebp), %edx\n" /* pArchiveTime */
        "movl %eax, (%edx)\n"
        "jmp .Lf1936a8_00193701\n"
        ".Lf1936a8_001937b3:\n"
        "movl 0x195f284, %edi\n"
        "jmp .Lf1936a8_001937c9\n"
        ".Lf1936a8_001937bb:\n"
        "addl $1, %ebx\n" /* line 1146 | archivedFrame */
        "movl %edi, %esi\n" /* line 1141 */
        "cmpl 0x2c(%edi), %ebx\n" /* archivedFrame */
        "jge .Lf1936a8_00193712\n"
        ".Lf1936a8_001937c9:\n"
        "movl %ebx, %eax\n" /* line 1143 | archivedFrame */
        "calll SV_GetCachedSnapshotInternal\n"
        "testl %eax, %eax\n" /* line 1144 */
        "je .Lf1936a8_001937bb\n"
        /* } scope */
        "movl 0x195f284, %edx\n" /* line 1320 */
        "movl 4(%edx), %esi\n" /* deltaTime */
        "subl 4(%eax), %esi\n" /* deltaTime */
        "movl 0x10(%eax), %ecx\n" /* line 1323 */
        "movl %ecx, -0x20(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jle .Lf1936a8_00193724\n"
        "movl 0x4c(%edx), %edx\n" /* line 1325 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x14(%eax), %edi\n"
        "movl %edi, %edx\n"
        "andl $0x80000fff, %edx\n"
        "js .Lf1936a8_001939f9\n"
        ".Lf1936a8_00193805:\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n" /* cachedClient */
        "movl 8(%ebp), %ecx\n" /* line 1326 | clientNum */
        "cmpl 4(%ebx), %ecx\n" /* cachedClient */
        "je .Lf1936a8_0019388d\n"
        "xorl %ecx, %ecx\n" /* line 1328 */
        "jmp .Lf1936a8_0019383f\n"
        ".Lf1936a8_00193824:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 1325 */
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %edx, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n" /* cachedClient */
        "movl 8(%ebp), %eax\n" /* line 1326 | clientNum */
        "cmpl 4(%ebx), %eax\n" /* cachedClient */
        "je .Lf1936a8_0019388d\n"
        ".Lf1936a8_0019383f:\n"
        "addl $1, %ecx\n" /* line 1323 */
        "cmpl %ecx, -0x20(%ebp)\n"
        "je .Lf1936a8_00193724\n"
        "leal (%edi, %ecx), %eax\n" /* line 1325 */
        "movl %eax, %edx\n"
        "andl $0x80000fff, %edx\n"
        "jns .Lf1936a8_00193824\n"
        "subl $1, %edx\n"
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf1936a8_00193824\n"
        /* { scope 2 */
        ".Lf1936a8_00193866:\n"
        "movl 0x2c(%esi), %eax\n" /* line 1138 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl 0x195f2f8, %ecx\n"
        "movl (%ecx), %ebx\n" /* archivedFrame */
        "cltd\n"
        "idivl 8(%ebx)\n" /* archivedFrame */
        "movl 0xc(%ebp), %ecx\n" /* pArchiveTime */
        "movl %eax, (%ecx)\n"
        "xorl %ebx, %ebx\n" /* archivedFrame */
        "jmp .Lf1936a8_00193709\n"
        /* } scope */
        ".Lf1936a8_0019388d:\n"
        "movl (%ebx), %eax\n" /* line 1328 | cachedClient */
        "testl %eax, %eax\n"
        "je .Lf1936a8_00193724\n"
        "leal 0x60(%ebx), %eax\n" /* line 1340 | cachedClient */
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* ps */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal 4(%ebx), %eax\n" /* line 1341 | cachedClient */
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* cs */
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1344 | ps, cachedClient */
        "movl (%ebx), %eax\n" /* cachedClient */
        "testl %eax, %eax\n"
        "je .Lf1936a8_001939f2\n"
        "leal (%esi, %eax), %eax\n" /* line 1345 | deltaTime */
        "movl %eax, (%ebx)\n" /* cachedClient */
        "movl 0x10(%ebp), %edx\n" /* ps */
        ".Lf1936a8_001938e0:\n"
        "movl 0x10(%edx), %eax\n" /* line 1346 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_001939eb\n"
        "leal (%esi, %eax), %eax\n" /* line 1347 | deltaTime */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x10(%ebp), %ecx\n" /* ps */
        ".Lf1936a8_001938f4:\n"
        "movl 0x44(%ecx), %eax\n" /* line 1348 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_001939e4\n"
        "leal (%esi, %eax), %eax\n" /* line 1349 | deltaTime */
        "movl %eax, 0x44(%ecx)\n"
        "movl 0x10(%ebp), %ebx\n" /* ps, cachedClient */
        ".Lf1936a8_00193908:\n"
        "movl 0x70(%ebx), %eax\n" /* line 1350 | cachedClient */
        "testl %eax, %eax\n"
        "je .Lf1936a8_001939dd\n"
        "leal (%esi, %eax), %eax\n" /* line 1351 | deltaTime */
        "movl %eax, 0x70(%ebx)\n" /* cachedClient */
        "movl 0x10(%ebp), %edx\n" /* ps */
        ".Lf1936a8_0019391c:\n"
        "movl 0xfc(%edx), %eax\n" /* line 1352 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_001939d6\n"
        "leal (%esi, %eax), %eax\n" /* line 1353 | deltaTime */
        "movl %eax, 0xfc(%edx)\n"
        "movl 0x10(%ebp), %ecx\n" /* ps */
        ".Lf1936a8_00193936:\n"
        "movl 0x5dc(%ecx), %eax\n" /* line 1354 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_001939cf\n"
        "leal (%esi, %eax), %eax\n" /* line 1355 | deltaTime */
        "movl %eax, 0x5dc(%ecx)\n"
        "movl 0x10(%ebp), %edx\n" /* ps */
        ".Lf1936a8_00193950:\n"
        "xorl %ebx, %ebx\n" /* cachedClient */
        "movl 0x195f284, %edi\n"
        ".Lf1936a8_00193958:\n"
        "movl 0x1790(%edx), %eax\n" /* line 1358 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_0019396b\n"
        "leal (%esi, %eax), %eax\n" /* line 1359 | deltaTime */
        "movl %eax, 0x1790(%edx)\n"
        ".Lf1936a8_0019396b:\n"
        "movl 0x1750(%edx), %eax\n" /* line 1360 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_0019398b\n"
        "leal (%esi, %eax), %eax\n" /* line 1362 | deltaTime */
        "movl %eax, 0x1750(%edx)\n"
        "movl 4(%edi), %ecx\n" /* line 1364 */
        "cmpl %ecx, %eax\n"
        "jle .Lf1936a8_0019398b\n"
        "movl %ecx, 0x1750(%edx)\n" /* line 1365 */
        ".Lf1936a8_0019398b:\n"
        "movl 0x1770(%edx), %eax\n" /* line 1370 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_0019399e\n"
        "leal (%esi, %eax), %eax\n" /* line 1371 | deltaTime */
        "movl %eax, 0x1770(%edx)\n"
        ".Lf1936a8_0019399e:\n"
        "movl 0x1788(%edx), %eax\n" /* line 1372 */
        "testl %eax, %eax\n"
        "je .Lf1936a8_001939b1\n"
        "leal (%esi, %eax), %eax\n" /* line 1373 | deltaTime */
        "movl %eax, 0x1788(%edx)\n"
        ".Lf1936a8_001939b1:\n"
        "addl $1, %ebx\n" /* line 1356 | cachedClient */
        "subl $-0x80, %edx\n"
        "cmpl $0x1f, %ebx\n" /* cachedClient */
        "jne .Lf1936a8_00193958\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1375 | ps, cachedClient */
        "addl %esi, 0x7a4(%ebx)\n" /* deltaTime, cachedClient */
        "movl $1, %eax\n"
        "jmp .Lf1936a8_00193726\n"
        ".Lf1936a8_001939cf:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf1936a8_00193950\n"
        ".Lf1936a8_001939d6:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1936a8_00193936\n"
        ".Lf1936a8_001939dd:\n"
        "movl %ebx, %edx\n" /* cachedClient */
        "jmp .Lf1936a8_0019391c\n"
        ".Lf1936a8_001939e4:\n"
        "movl %ecx, %ebx\n" /* cachedClient */
        "jmp .Lf1936a8_00193908\n"
        ".Lf1936a8_001939eb:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1936a8_001938f4\n"
        ".Lf1936a8_001939f2:\n"
        "movl %ebx, %edx\n" /* cachedClient */
        "jmp .Lf1936a8_001938e0\n"
        ".Lf1936a8_001939f9:\n"
        "subl $1, %edx\n" /* line 1325 */
        "orl $0xfffff000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf1936a8_00193805\n"
    );
}

/* line 1179 */
__attribute__((naked))
Bool SV_GetClientPositionAtTime(int client, int gametime, vec_t *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1179 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x275c, %esp\n"
        /* { scope 1 */
        "movl 0x195f2f8, %eax\n" /* line 1195 */
        "movl (%eax), %ecx\n"
        "movl $0x3e8, %ebx\n"
        "movl %ebx, %eax\n"
        "cltd\n"
        "idivl 8(%ecx)\n"
        "movl %eax, %esi\n"
        "movl 0x195f284, %eax\n" /* line 1202 */
        "movl 4(%eax), %eax\n"
        "cltd\n"
        "idivl %esi\n"
        "imull %esi, %eax\n"
        "subl 0xc(%ebp), %eax\n" /* gametime */
        "cltd\n"
        "idivl %esi\n"
        "movl %eax, %edx\n"
        "addl startOffset, %edx\n"
        "imull %esi, %edx\n"
        "movl %edx, -0x2744(%ebp)\n" /* startTime */
        "addl endOffset, %eax\n" /* line 1203 */
        "imull %esi, %eax\n"
        "movl %eax, -0x2740(%ebp)\n" /* endTime */
        "movl %edx, -0x1c(%ebp)\n" /* line 1209 | timeRequest */
        "movw $0xa, %bx\n"
        "leal -0x1c(%ebp), %edi\n" /* timeRequest */
        ".Lf193a0a_00193a68:\n"
        "leal -0x90(%ebp), %eax\n" /* line 1215 | cs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x2738(%ebp), %edx\n" /* ps */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* client */
        "movl %eax, (%esp)\n"
        "calll SV_GetArchivedClientInfo\n"
        "testl %eax, %eax\n"
        "jne .Lf193a0a_00193be7\n"
        "addl %esi, -0x1c(%ebp)\n" /* line 1225 | timeRequest */
        "subl $1, %ebx\n" /* line 1211 */
        "jne .Lf193a0a_00193a68\n"
        "movb $0, -0x2739(%ebp)\n" /* foundStart */
        ".Lf193a0a_00193aa2:\n"
        "movl -0x2740(%ebp), %edx\n" /* line 1230 | endTime */
        "movl %edx, -0x1c(%ebp)\n" /* timeRequest */
        "movl $0xa, %ebx\n"
        ".Lf193a0a_00193ab0:\n"
        "leal -0x90(%ebp), %eax\n" /* line 1236 | cs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x2738(%ebp), %edx\n" /* ps */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* client */
        "movl %eax, (%esp)\n"
        "calll SV_GetArchivedClientInfo\n"
        "testl %eax, %eax\n"
        "jne .Lf193a0a_00193bb9\n"
        "subl %esi, -0x1c(%ebp)\n" /* line 1246 | timeRequest */
        "subl $1, %ebx\n" /* line 1232 */
        "jne .Lf193a0a_00193ab0\n"
        ".Lf193a0a_00193ae3:\n"
        "cmpb $0, -0x2739(%ebp)\n" /* line 1250 | foundStart */
        "je .Lf193a0a_00193b17\n"
        "testb %al, %al\n"
        "jne .Lf193a0a_00193b89\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x34(%ebp)\n" /* endPos */
        "movl %eax, -0x30(%ebp)\n" /* line 184 */
        "movl %eax, -0x2c(%ebp)\n" /* line 185 */
        "movl %eax, -0x274c(%ebp)\n"
        "movss -0x274c(%ebp), %xmm2\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "jmp .Lf193a0a_00193b40\n"
        ".Lf193a0a_00193b17:\n"
        "testb %al, %al\n" /* line 1264 */
        "je .Lf193a0a_00193c17\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x28(%ebp)\n" /* startPos */
        "movl %eax, -0x24(%ebp)\n" /* line 184 */
        "movl %eax, -0x20(%ebp)\n" /* line 185 */
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movl %eax, -0x274c(%ebp)\n"
        "movss -0x274c(%ebp), %xmm3\n"
        ".Lf193a0a_00193b40:\n"
        "movl $1, %edx\n"
        "leal -0x28(%ebp), %ebx\n" /* startPos */
        "leal -0x34(%ebp), %ecx\n" /* endPos */
        ".Lf193a0a_00193b4b:\n"
        "leal (, %edx, 4), %eax\n" /* line 1288 */
        "movaps %xmm3, %xmm0\n"
        "mulss -4(%ebx, %eax), %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss -4(%ecx, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movl 0x10(%ebp), %eax\n" /* pos */
        "movss %xmm0, -4(%eax, %edx, 4)\n"
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 1283 */
        "jne .Lf193a0a_00193b4b\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x275c, %esp\n" /* line 1294 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf193a0a_00193b89:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1254 | gametime */
        "cltd\n"
        "idivl %esi\n"
        "cvtsi2ssl %edx, %xmm2\n"
        "movl -0x2740(%ebp), %edx\n" /* endTime */
        "subl %edx, -0x2744(%ebp)\n" /* startTime */
        "cvtsi2ssl -0x2744(%ebp), %xmm0\n" /* startTime */
        "divss %xmm0, %xmm2\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "subss %xmm2, %xmm3\n"
        "jmp .Lf193a0a_00193b40\n"
        ".Lf193a0a_00193bb9:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1239 | timeRequest */
        "movl %eax, -0x2740(%ebp)\n" /* endTime */
        "movl -0x2724(%ebp), %eax\n" /* line 1240 */
        "movl %eax, -0x34(%ebp)\n" /* endPos */
        "movl -0x2720(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x271c(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl $1, %eax\n"
        "jmp .Lf193a0a_00193ae3\n"
        ".Lf193a0a_00193be7:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1218 | timeRequest */
        "movl %edx, -0x2744(%ebp)\n" /* startTime */
        "movl -0x2724(%ebp), %eax\n" /* line 1219 */
        "movl %eax, -0x28(%ebp)\n" /* startPos */
        "movl -0x2720(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x271c(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movb $1, -0x2739(%ebp)\n" /* foundStart */
        "jmp .Lf193a0a_00193aa2\n"
        ".Lf193a0a_00193c17:\n"
        "xorl %eax, %eax\n" /* line 1264 */
        /* } scope */
        "addl $0x275c, %esp\n" /* line 1294 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1699 */
__attribute__((naked))
void SV_SendClientSnapshot(client_t *client)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1699 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x132c, %esp\n"
        /* { scope 1: frame, client */
        "movl $0x20000, 4(%esp)\n" /* line 1702 */
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* msg_buf_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x12f8(%ebp)\n" /* msg_buf */
        "movl 8(%ebp), %ecx\n" /* line 1704 | client */
        "movl (%ecx), %eax\n"
        "cmpl $4, %eax\n"
        "je .Lf193c24_0019419e\n"
        "subl $1, %eax\n"
        "je .Lf193c24_0019453b\n"
        ".Lf193c24_00193c6b:\n"
        "movl $0x20000, 8(%esp)\n" /* line 1710 */
        "movl -0x12f8(%ebp), %edx\n" /* msg_buf */
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 8(%ebp), %ebx\n" /* line 1714 | client, state */
        "movl 0x20840(%ebx), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl (%ebx), %eax\n" /* line 1716 | state */
        "cmpl $4, %eax\n"
        "je .Lf193c24_00193d49\n"
        "subl $1, %eax\n"
        "je .Lf193c24_00193d49\n"
        "movl 8(%ebp), %ebx\n" /* client, state */
        ".Lf193c24_00193cb7:\n"
        "leal -0x50(%ebp), %ecx\n" /* line 1730 | msg */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll SV_WriteDownloadToClient\n"
        ".Lf193c24_00193cc6:\n"
        "movl $7, 4(%esp)\n" /* line 1734 */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl -0x50(%ebp), %ecx\n" /* line 1737 | msg */
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00193d21\n"
        "movl 8(%ebp), %edx\n" /* line 1739 | client */
        "addl $0x20c48, %edx\n"
        "movl %edx, -0x12fc(%ebp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x2b064c, (%esp)\n" /* "WARNING: msg overflowed for %s, trying to recover
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %ecx\n" /* line 1741 | client */
        "movl (%ecx), %eax\n"
        "cmpl $4, %eax\n"
        "je .Lf193c24_0019460e\n"
        "subl $1, %eax\n"
        "je .Lf193c24_0019479e\n"
        ".Lf193c24_00193d16:\n"
        "movl -0x50(%ebp), %edx\n" /* line 1754 | msg */
        "testl %edx, %edx\n"
        "jne .Lf193c24_00194543\n"
        ".Lf193c24_00193d21:\n"
        "movl 8(%ebp), %eax\n" /* line 1762 | client */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll SV_SendMessageToClient\n"
        "leal -0x1c(%ebp), %ebx\n" /* msg_buf_large_local, state */
        "movl %ebx, (%esp)\n" /* state */
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x132c, %esp\n" /* line 1763 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: frame, client */
        ".Lf193c24_00193d49:\n"
        "leal -0x50(%ebp), %edx\n" /* line 1719 | msg */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl %ecx, (%esp)\n"
        "calll SV_UpdateServerCommandsToClient\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        "movl 8(%ebp), %eax\n" /* line 374 | client */
        "movl 0x6e5b4(%eax), %ebx\n" /* i */
        "movl %ebx, %eax\n" /* i */
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "leal 0x20d24(%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x12a4(%ebp)\n" /* frame */
        "movl 0x20d08(%ecx), %eax\n" /* line 377 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00193d9b\n"
        "cmpl $4, (%ecx)\n"
        "je .Lf193c24_001945ae\n"
        ".Lf193c24_00193d9b:\n"
        "xorl %ebx, %ebx\n" /* line 399 | i */
        "xorl %esi, %esi\n" /* lastframe */
        ".Lf193c24_00193d9f:\n"
        "movl $6, 4(%esp)\n" /* line 405 */
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x195f284, %edi\n" /* line 409 | newindex */
        "movl 4(%edi), %eax\n" /* newindex */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %esi, 4(%esp)\n" /* line 412 | lastframe */
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 8(%edi), %edx\n" /* line 414 | newindex */
        "movl %edx, %eax\n" /* line 416 */
        "orl $1, %eax\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl 0x20d1c(%ecx), %edi\n" /* newindex */
        "testl %edi, %edi\n" /* newindex */
        "cmovnel %eax, %edx\n"
        "movl (%ecx), %eax\n" /* line 417 */
        "cmpl $4, %eax\n"
        "je .Lf193c24_001947cf\n"
        "subl $1, %eax\n" /* line 419 */
        "je .Lf193c24_00193e09\n"
        "movl 8(%ebp), %eax\n" /* line 420 | client */
        "movl $0, 4(%eax)\n"
        ".Lf193c24_00193e09:\n"
        "movl %edx, %eax\n" /* line 422 */
        "orl $2, %eax\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl 4(%ecx), %esi\n" /* lastframe */
        "testl %esi, %esi\n" /* lastframe */
        "cmovel %eax, %edx\n"
        "movl %edx, 4(%esp)\n" /* line 424 */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "testl %ebx, %ebx\n" /* line 431 | i */
        "je .Lf193c24_001947db\n"
        "movl -0x12a4(%ebp), %edx\n" /* line 433 | frame */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "movl 0x26a8(%ebx), %eax\n" /* line 439 | i */
        "movl %eax, -0x1294(%ebp)\n" /* from_num_entities */
        "movl 0x26b0(%ebx), %edx\n" /* line 440 | i */
        "movl %edx, -0x1298(%ebp)\n" /* from_first_entity */
        "movl 0x26ac(%ebx), %ecx\n" /* line 441 | i */
        "movl %ecx, -0x127c(%ebp)\n" /* from_num_clients */
        "movl 0x26b4(%ebx), %ebx\n" /* line 442 | i */
        "movl %ebx, -0x1280(%ebp)\n" /* i, from_first_client */
        ".Lf193c24_00193e79:\n"
        "movl -0x12a4(%ebp), %edx\n" /* line 461 | frame */
        "movl 0x26b0(%edx), %edx\n"
        "movl %edx, -0x12a0(%ebp)\n" /* to_first_entity */
        "movl -0x12a4(%ebp), %ecx\n" /* frame */
        "movl 0x26a8(%ecx), %ecx\n"
        "movl %ecx, -0x129c(%ebp)\n" /* to_num_entities */
        "xorl %edi, %edi\n" /* newindex */
        "xorl %ebx, %ebx\n" /* i */
        "movl $0, -0x128c(%ebp)\n" /* newindex */
        "movl $0, -0x1290(%ebp)\n" /* oldindex */
        "movl %ecx, %edx\n"
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00193eb7:\n"
        "cmpl %edx, -0x128c(%ebp)\n" /* line 173 | newindex */
        "jge .Lf193c24_00193f17\n"
        ".Lf193c24_00193ebf:\n"
        "movl 0x195f284, %esi\n" /* line 181 */
        "movl -0x128c(%ebp), %eax\n" /* newindex */
        "addl -0x12a0(%ebp), %eax\n" /* to_first_entity */
        "cltd\n"
        "idivl 0x10(%esi)\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %edi\n" /* newent */
        "shll $8, %edi\n" /* newent */
        "subl %eax, %edi\n" /* newent */
        "addl 0x20(%esi), %edi\n" /* newent */
        "movl (%edi), %ecx\n" /* line 182 | newent */
        "movl -0x1290(%ebp), %eax\n" /* line 185 | oldindex */
        "cmpl %eax, -0x1294(%ebp)\n" /* from_num_entities */
        "jg .Lf193c24_00193f34\n"
        "movl $0x270f, %eax\n"
        "cmpl %ecx, %eax\n" /* line 205 */
        "je .Lf193c24_00193f59\n"
        ".Lf193c24_00193efd:\n"
        "jg .Lf193c24_00193f8d\n" /* line 221 */
        "jl .Lf193c24_00193fd0\n" /* line 234 */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "cmpl %edx, -0x128c(%ebp)\n" /* line 173 | newindex */
        "jl .Lf193c24_00193ebf\n"
        ".Lf193c24_00193f17:\n"
        "movl -0x1290(%ebp), %ecx\n" /* oldindex */
        "cmpl %ecx, -0x1294(%ebp)\n" /* from_num_entities */
        "jle .Lf193c24_00194001\n"
        "movl $0x270f, %ecx\n"
        "movl 0x195f284, %esi\n"
        ".Lf193c24_00193f34:\n"
        "movl -0x1298(%ebp), %eax\n" /* line 191 | from_first_entity */
        "addl -0x1290(%ebp), %eax\n" /* oldindex */
        "cltd\n"
        "idivl 0x10(%esi)\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ebx\n" /* oldent */
        "shll $8, %ebx\n" /* oldent */
        "subl %eax, %ebx\n" /* oldent */
        "addl 0x20(%esi), %ebx\n" /* oldent */
        "movl (%ebx), %eax\n" /* line 192 | oldent */
        "cmpl %ecx, %eax\n" /* line 205 */
        "jne .Lf193c24_00193efd\n"
        ".Lf193c24_00193f59:\n"
        "movl $0, 0xc(%esp)\n" /* line 210 */
        "movl %edi, 8(%esp)\n" /* newent */
        "movl %ebx, 4(%esp)\n" /* oldent */
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "addl $1, -0x1290(%ebp)\n" /* line 216 | oldindex */
        "addl $1, -0x128c(%ebp)\n" /* line 217 | newindex */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "jmp .Lf193c24_00193eb7\n"
        ".Lf193c24_00193f8d:\n"
        "movl $1, 0xc(%esp)\n" /* line 224 */
        "movl %edi, 8(%esp)\n" /* newent */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195ee80, %eax\n"
        "leal 0x241c(%eax, %edx, 4), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "addl $1, -0x128c(%ebp)\n" /* line 230 | newindex */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "jmp .Lf193c24_00193eb7\n"
        ".Lf193c24_00193fd0:\n"
        "movl $1, 0xc(%esp)\n" /* line 237 */
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* oldent */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "addl $1, -0x1290(%ebp)\n" /* line 243 | oldindex */
        "movl -0x129c(%ebp), %edx\n" /* to_num_entities */
        "jmp .Lf193c24_00193eb7\n"
        ".Lf193c24_00194001:\n"
        "movl $0xa, 8(%esp)\n" /* line 249 */
        "movl $0x3ff, 4(%esp)\n"
        "leal -0x50(%ebp), %ebx\n" /* msg, oldent */
        "movl %ebx, (%esp)\n" /* oldent */
        "calll MSG_WriteBits\n"
        /* } scope */
        /* } scope */
        "movl -0x12a4(%ebp), %eax\n" /* line 464 | frame */
        "movl 0x26b4(%eax), %eax\n"
        "movl %eax, -0x1288(%ebp)\n" /* to_first_client */
        "movl -0x12a4(%ebp), %edx\n" /* frame */
        "movl 0x26ac(%edx), %edx\n"
        "movl %edx, -0x1284(%ebp)\n" /* to_num_clients */
        "movl $0, -0x1274(%ebp)\n" /* newclient */
        "movl $0, -0x1278(%ebp)\n" /* oldclient */
        "xorl %edi, %edi\n" /* newindex */
        "xorl %ebx, %ebx\n" /* i */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194058:\n"
        "cmpl -0x1284(%ebp), %edi\n" /* line 281 | to_num_clients, newindex */
        "jge .Lf193c24_001940d2\n"
        ".Lf193c24_00194060:\n"
        "movl 0x195f284, %esi\n" /* line 289 */
        "movl -0x1288(%ebp), %ecx\n" /* to_first_client */
        "leal (%edi, %ecx), %eax\n" /* newindex */
        "cltd\n"
        "idivl 0x14(%esi)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x24(%esi), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1274(%ebp)\n" /* newclient */
        "movl (%eax), %ecx\n" /* line 290 */
        "cmpl %ebx, -0x127c(%ebp)\n" /* line 293 | oldindex, from_num_clients */
        "jg .Lf193c24_001940e9\n"
        "movl $0x270f, %eax\n"
        "cmpl %ecx, %eax\n" /* line 303 */
        "je .Lf193c24_0019410f\n"
        ".Lf193c24_0019409a:\n"
        "jg .Lf193c24_00194141\n" /* line 319 */
        "jge .Lf193c24_00194058\n" /* line 332 */
        "movl $1, 0xc(%esp)\n" /* line 335 */
        "movl $0, 8(%esp)\n"
        "movl -0x1278(%ebp), %edx\n" /* oldclient */
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "addl $1, %ebx\n" /* line 341 | oldindex */
        "cmpl -0x1284(%ebp), %edi\n" /* line 281 | to_num_clients, newindex */
        "jl .Lf193c24_00194060\n"
        ".Lf193c24_001940d2:\n"
        "cmpl %ebx, -0x127c(%ebp)\n" /* oldindex, from_num_clients */
        "jle .Lf193c24_0019416e\n"
        "movl $0x270f, %ecx\n"
        "movl 0x195f284, %esi\n"
        ".Lf193c24_001940e9:\n"
        "movl -0x1280(%ebp), %eax\n" /* line 299 | from_first_client */
        "addl %ebx, %eax\n" /* oldindex */
        "cltd\n"
        "idivl 0x14(%esi)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x24(%esi), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1278(%ebp)\n" /* oldclient */
        "movl (%eax), %eax\n" /* line 300 */
        "cmpl %ecx, %eax\n" /* line 303 */
        "jne .Lf193c24_0019409a\n"
        ".Lf193c24_0019410f:\n"
        "movl $0, 0xc(%esp)\n" /* line 308 */
        "movl -0x1274(%ebp), %ecx\n" /* newclient */
        "movl %ecx, 8(%esp)\n"
        "movl -0x1278(%ebp), %eax\n" /* oldclient */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "addl $1, %ebx\n" /* line 314 | oldindex */
        "addl $1, %edi\n" /* line 315 | newindex */
        "jmp .Lf193c24_00194058\n"
        ".Lf193c24_00194141:\n"
        "movl $1, 0xc(%esp)\n" /* line 322 */
        "movl -0x1274(%ebp), %ecx\n" /* newclient */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaClient\n"
        "addl $1, %edi\n" /* line 328 | newindex */
        "jmp .Lf193c24_00194058\n"
        ".Lf193c24_0019416e:\n"
        "leal -0x50(%ebp), %ebx\n" /* line 346 | msg, oldindex */
        "movl %ebx, (%esp)\n" /* oldindex */
        "calll MSG_WriteBit0\n"
        /* } scope */
        /* } scope */
        "movl 0x195f2b0, %eax\n" /* line 467 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf193c24_001947a6\n"
        /* } scope */
        ".Lf193c24_0019418b:\n"
        "movl 8(%ebp), %edx\n" /* line 1727 | client */
        "cmpl $1, (%edx)\n"
        "je .Lf193c24_00193cc6\n"
        "movl %edx, %ebx\n" /* state */
        "jmp .Lf193c24_00193cb7\n"
        ".Lf193c24_0019419e:\n"
        "movl %ecx, %ebx\n" /* state */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        ".Lf193c24_001941a0:\n"
        "movl 0x6e5b4(%ebx), %eax\n" /* line 1417 | state */
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "leal 0x20d24(%ebx, %edx, 4), %esi\n" /* state, frame */
        "movl $0, 0x26a8(%esi)\n" /* line 1418 | frame */
        "movl $0, 0x26ac(%esi)\n" /* line 1419 | frame */
        "movl 0x20c44(%ebx), %ecx\n" /* line 1423 | state */
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00193c6b\n"
        "cmpl $1, (%ebx)\n" /* state */
        "je .Lf193c24_00193c6b\n"
        "movl 0x195f284, %edi\n" /* line 1429 | i */
        "movl 0x18(%edi), %eax\n" /* i */
        "movl %eax, 0x26b0(%esi)\n" /* frame */
        "movl 0x1c(%edi), %eax\n" /* line 1430 | i */
        "movl %eax, 0x26b4(%esi)\n" /* frame */
        "movl 0x195ee80, %eax\n" /* line 1435 */
        "cmpl $2, (%eax)\n"
        "jne .Lf193c24_00193c6b\n"
        "movl %ebx, %eax\n" /* line 1441 | state */
        "subl 0xc(%edi), %eax\n" /* i */
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, -0x1300(%ebp)\n"
        "movl %eax, (%esp)\n" /* line 1443 */
        "calll G_GetClientArchiveTime\n"
        "movl %eax, -0x12e8(%ebp)\n" /* archiveTime */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        "movl 0x28(%edi), %edx\n" /* line 1116 | i */
        "testl %edx, %edx\n"
        "je .Lf193c24_00194938\n"
        "testl %eax, %eax\n" /* line 1126 */
        "jle .Lf193c24_00194938\n"
        "movl 0x2c(%edi), %eax\n" /* line 1129 | i */
        "movl %eax, -0x12e4(%ebp)\n"
        "movl 0x195f2f8, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x12e0(%ebp)\n"
        "movl -0x12e8(%ebp), %ecx\n" /* archiveTime */
        "imull %eax, %ecx\n"
        "movl $0x10624dd3, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl -0x12e4(%ebp), %ebx\n" /* archivedFrame */
        "subl %edx, %ebx\n" /* archivedFrame */
        "movl -0x12e4(%ebp), %ecx\n" /* line 1130 */
        "subl $0x4b0, %ecx\n"
        "cmpl %ecx, %ebx\n" /* archivedFrame */
        "jge .Lf193c24_001942bb\n"
        "movl -0x12e4(%ebp), %eax\n" /* line 1133 */
        "subl %ecx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl -0x12e0(%ebp)\n"
        "movl %eax, -0x12e8(%ebp)\n" /* archiveTime */
        "movl %ecx, %ebx\n" /* archivedFrame */
        ".Lf193c24_001942bb:\n"
        "testl %ebx, %ebx\n" /* line 1135 | archivedFrame */
        "js .Lf193c24_00194c41\n"
        ".Lf193c24_001942c3:\n"
        "cmpl -0x12e4(%ebp), %ebx\n" /* line 1141 | archivedFrame */
        "jl .Lf193c24_00194825\n"
        ".Lf193c24_001942cf:\n"
        "movl $0, -0x12f0(%ebp)\n" /* cachedFrame */
        "movl $0, -0x12e8(%ebp)\n" /* archiveTime */
        /* } scope */
        ".Lf193c24_001942e3:\n"
        "movl -0x12e8(%ebp), %edx\n" /* line 1445 | archiveTime */
        "movl %edx, 4(%esp)\n"
        "movl -0x1300(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll G_SetClientArchiveTime\n"
        "movl -0x12f0(%ebp), %ebx\n" /* line 1446 | cachedFrame, state */
        "testl %ebx, %ebx\n" /* state */
        "je .Lf193c24_00194c2a\n"
        "movl 0x195f284, %eax\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x12ec(%ebp)\n" /* deltaTime */
        "movl -0x12f0(%ebp), %ebx\n" /* cachedFrame, state */
        "movl 4(%ebx), %ebx\n" /* state */
        "subl %ebx, %eax\n" /* state */
        "movl %eax, -0x12ec(%ebp)\n" /* deltaTime */
        ".Lf193c24_00194328:\n"
        "movl -0x1300(%ebp), %eax\n" /* line 1449 */
        "movl %eax, (%esp)\n"
        "calll SV_GameClientNum\n"
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* frame */
        "calll memcpy\n"
        "movl 0xcc(%esi), %edx\n" /* line 1451 | frame */
        "movl %edx, -0x12c4(%ebp)\n" /* clientNum */
        "cmpl $0x3ff, %edx\n" /* line 1452 */
        "jbe .Lf193c24_00194372\n"
        "movl $0x2b0584, 4(%esp)\n" /* line 1454 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf193c24_00194372:\n"
        "leal 0x14(%esi), %edx\n" /* frame */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        "movl 0x14(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x2c(%ebp)\n" /* org */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x24(%ebp)\n"
        /* } scope */
        "addss 0xf8(%esi), %xmm0\n" /* line 1459 | frame */
        "movss %xmm0, -0x24(%ebp)\n"
        "movl $0x41a00000, 0x10(%esp)\n" /* line 1462 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl 0x4c(%esi), %eax\n" /* frame */
        "movl %eax, 8(%esp)\n"
        "movl 0xec(%esi), %eax\n" /* frame */
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %ecx\n" /* org */
        "movl %ecx, (%esp)\n"
        "calll AddLeanToPosition\n"
        "movl -0x12f0(%ebp), %ecx\n" /* line 1468 | cachedFrame */
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00194947\n"
        "movl -0x12f0(%ebp), %eax\n" /* line 1517 | cachedFrame */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x12c0(%ebp)\n" /* from_first_entity */
        "movl -0x12f0(%ebp), %edx\n" /* cachedFrame */
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x12bc(%ebp)\n" /* from_num_entities */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        /* { scope 5: e */
        "leal -0x2c(%ebp), %ecx\n" /* line 756 | org */
        "movl %ecx, (%esp)\n"
        "calll CM_PointLeafnum\n"
        "movl %eax, (%esp)\n" /* line 758 */
        "calll CM_LeafCluster\n"
        "testl %eax, %eax\n" /* line 759 */
        "js .Lf193c24_00194847\n"
        "movl %eax, (%esp)\n" /* line 762 */
        "calll CM_ClusterPVS\n"
        "movl %eax, -0x12b0(%ebp)\n" /* clientpvs */
        "calll G_GetFogOpaqueDistSqrd\n" /* line 764 */
        "fstps -0x12ac(%ebp)\n" /* fogOpaqueDistSqrd */
        "movss -0x12ac(%ebp), %xmm0\n" /* line 765 | fogOpaqueDistSqrd */
        "movaps %xmm0, %xmm1\n"
        "cmpneqss 0x2ed684, %xmm0\n" /* 3.4028234663852886e+38f */
        "andps %xmm1, %xmm0\n"
        "movss %xmm0, -0x12ac(%ebp)\n" /* fogOpaqueDistSqrd */
        "movl -0x12bc(%ebp), %eax\n" /* line 772 | from_num_entities */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00194847\n"
        "movl -0x12c4(%ebp), %eax\n" /* clientNum */
        "sarl $5, %eax\n"
        "movl %eax, -0x126c(%ebp)\n"
        "movl -0x12c4(%ebp), %edx\n" /* clientNum */
        "andl $0x1f, %edx\n"
        "movl %edx, -0x1268(%ebp)\n"
        "movl $0, -0x12a8(%ebp)\n" /* e */
        "movl $0, -0x1264(%ebp)\n"
        "jmp .Lf193c24_00194510\n"
        ".Lf193c24_00194488:\n"
        "movl %edx, %eax\n" /* line 774 */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x195f284, %ecx\n"
        "movl 0x48(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl -0x126c(%ebp), %ebx\n" /* line 782 | num_leafs */
        "movl 0xf4(%edx, %ebx, 4), %eax\n"
        "movzbl -0x1268(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_001944f7\n"
        "movl -0x12c4(%ebp), %ebx\n" /* line 785 | clientNum, num_leafs */
        "cmpl (%edx), %ebx\n" /* num_leafs */
        "je .Lf193c24_001944f7\n"
        "testb $0x18, 0xf0(%edx)\n" /* line 798 */
        "je .Lf193c24_00194b8f\n"
        "cmpl $0x400, -0x1264(%ebp)\n" /* line 608 */
        "je .Lf193c24_001944f7\n"
        "movl -0x12a8(%ebp), %edx\n" /* line 613 | e */
        "movl -0x1264(%ebp), %eax\n"
        "movl %edx, -0x1250(%ebp, %eax, 4)\n"
        "addl $1, %eax\n" /* line 614 */
        "movl %eax, -0x1264(%ebp)\n"
        ".Lf193c24_001944f7:\n"
        "addl $1, -0x12a8(%ebp)\n" /* line 772 | e */
        "movl -0x12a8(%ebp), %edx\n" /* e */
        "cmpl %edx, -0x12bc(%ebp)\n" /* from_num_entities */
        "je .Lf193c24_00194a73\n"
        ".Lf193c24_00194510:\n"
        "movl -0x12c0(%ebp), %eax\n" /* line 774 | from_first_entity */
        "addl -0x12a8(%ebp), %eax\n" /* e */
        "movl %eax, %edx\n"
        "andl $0x80003fff, %edx\n"
        "jns .Lf193c24_00194488\n"
        "subl $1, %edx\n"
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf193c24_00194488\n"
        ".Lf193c24_0019453b:\n"
        "movl 8(%ebp), %ebx\n" /* client, num_leafs */
        "jmp .Lf193c24_001941a0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf193c24_00194543:\n"
        "movl -0x12fc(%ebp), %eax\n" /* line 1756 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b0680, (%esp)\n" /* "WARNING: client disconnected for msg overflow: %s
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %edx\n" /* line 1757 | client */
        "movl 0x6e5c4(%edx), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl %edx, %ebx\n" /* state */
        "movl 0x6e5c8(%edx), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* state */
        "movl %eax, -0x30(%ebp)\n"
        "movl $0x228e90, 0x10(%esp)\n" /* "disconnect" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl $0x2b06b4, 4(%esp)\n" /* line 1758 */
        "movl %ebx, (%esp)\n" /* state */
        "calll SV_DropClient\n"
        "jmp .Lf193c24_00193d21\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_001945ae:\n"
        "movl %ebx, %esi\n" /* line 383 | i, lastframe */
        "subl %eax, %esi\n" /* lastframe */
        "cmpl $0x1c, %esi\n" /* lastframe */
        "jg .Lf193c24_0019491c\n"
        "movl %eax, %edx\n" /* line 393 */
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* client */
        "leal 0x20d24(%edx, %eax, 4), %ebx\n" /* i */
        "movl 0x195f284, %edx\n" /* line 397 */
        "movl 0x18(%edx), %eax\n"
        "subl 0x10(%edx), %eax\n"
        "cmpl %eax, 0x26b0(%ebx)\n" /* i */
        "jge .Lf193c24_00193d9f\n"
        "movl 8(%ebp), %eax\n" /* line 399 | client */
        "addl $0x20c48, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b061c, (%esp)\n" /* "%s: Delta request from out of date entities.
" */
        "calll Com_DPrintf\n"
        "jmp .Lf193c24_00193d9b\n"
        ".Lf193c24_0019460e:\n"
        "movl %ecx, %edx\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_00194610:\n"
        "movl -0x12fc(%ebp), %ebx\n" /* line 557 | i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl 0x195f284, %eax\n"
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b03d4, (%esp)\n" /* "-- Unacknowledged Server Commands for client %i:%s --
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %ecx\n" /* line 559 | client */
        "movl 0x20810(%ecx), %ebx\n" /* i */
        "addl $1, %ebx\n" /* i */
        "cmpl GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(%ecx), %ebx\n" /* i */
        "jle .Lf193c24_001946d7\n"
        ".Lf193c24_00194655:\n"
        "movl $0x2b040c, (%esp)\n" /* line 562 */
        "calll Com_Printf\n"
        /* } scope */
        "movl $0x20000, 8(%esp)\n" /* line 1746 */
        "movl -0x12f8(%ebp), %edx\n" /* msg_buf */
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_Init\n"
        "movl 8(%ebp), %ebx\n" /* line 1747 | client, state */
        "movl 0x20840(%ebx), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        "movl 8(%ebp), %edx\n" /* line 531 | client */
        "movl 0x20810(%edx), %ebx\n" /* i */
        "addl $1, %ebx\n" /* i */
        "cmpl GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(%edx), %ebx\n" /* i */
        "jle .Lf193c24_0019471d\n"
        ".Lf193c24_001946aa:\n"
        "movl %edx, %ecx\n"
        ".Lf193c24_001946ac:\n"
        "leal -1(%ebx), %eax\n" /* line 542 | i */
        "cmpl 0x20814(%ecx), %eax\n" /* line 543 */
        "jle .Lf193c24_001946bd\n"
        "movl %eax, 0x20814(%ecx)\n" /* line 544 */
        /* } scope */
        ".Lf193c24_001946bd:\n"
        "movl $7, 4(%esp)\n" /* line 1750 */
        "leal -0x50(%ebp), %ebx\n" /* msg, state */
        "movl %ebx, (%esp)\n" /* state */
        "calll MSG_WriteByte\n"
        "jmp .Lf193c24_00193d16\n"
        ".Lf193c24_001946d5:\n"
        "movl %eax, %ecx\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_001946d7:\n"
        "movl %ebx, %eax\n" /* line 560 | i */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0x40c(%eax, %ecx), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x80c(%eax, %ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $0x2ab3fc, (%esp)\n" /* "cmd %5d: %8d: %s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 559 | i */
        "movl 8(%ebp), %eax\n" /* client */
        "cmpl GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(%eax), %ebx\n" /* i */
        "jle .Lf193c24_001946d5\n"
        "jmp .Lf193c24_00194655\n"
        ".Lf193c24_0019471d:\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "jmp .Lf193c24_00194724\n"
        ".Lf193c24_00194722:\n"
        "movl %edx, %ecx\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_00194724:\n"
        "movl %ebx, %eax\n" /* line 533 | i */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal 0x400(%edx, %eax, 8), %eax\n"
        "leal 0xc(%ecx, %eax), %esi\n" /* lastframe */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* lastframe, newindex */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* newindex */
        "notl %ecx\n"
        "movl -0x44(%ebp), %eax\n"
        "leal 5(%ecx, %eax), %ecx\n"
        "cmpl $0x1ffff, %ecx\n"
        "jg .Lf193c24_00194c39\n"
        "movl $4, 4(%esp)\n" /* line 537 */
        "leal -0x50(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl %ebx, 4(%esp)\n" /* line 538 | i */
        "leal -0x50(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %esi, 4(%esp)\n" /* line 539 | lastframe */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteString\n"
        "addl $1, %ebx\n" /* line 531 | i */
        "movl 8(%ebp), %edx\n" /* client */
        "cmpl GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(%edx), %ebx\n" /* i */
        "jle .Lf193c24_00194722\n"
        "jmp .Lf193c24_001946aa\n"
        ".Lf193c24_0019479e:\n"
        "movl 8(%ebp), %edx\n" /* client */
        "jmp .Lf193c24_00194610\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_001947a6:\n"
        "xorl %ebx, %ebx\n" /* line 467 | i */
        ".Lf193c24_001947a8:\n"
        "movl $0, 4(%esp)\n" /* line 468 */
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "addl $1, %ebx\n" /* line 467 | i */
        "movl 0x195f2b0, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n" /* i */
        "jl .Lf193c24_001947a8\n"
        "jmp .Lf193c24_0019418b\n"
        ".Lf193c24_001947cf:\n"
        "movl $1, 4(%ecx)\n" /* line 418 */
        "jmp .Lf193c24_00193e09\n"
        ".Lf193c24_001947db:\n"
        "movl -0x12a4(%ebp), %ebx\n" /* line 448 | frame, i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaPlayerstate\n"
        "movl $0, -0x1294(%ebp)\n" /* from_num_entities */
        "movl $0, -0x1298(%ebp)\n" /* from_first_entity */
        "movl $0, -0x127c(%ebp)\n" /* from_num_clients */
        "movl $0, -0x1280(%ebp)\n" /* from_first_client */
        "jmp .Lf193c24_00193e79\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194825:\n"
        "movl %ebx, %eax\n" /* line 1143 | archivedFrame */
        "calll SV_GetCachedSnapshotInternal\n"
        "movl %eax, -0x12f0(%ebp)\n" /* cachedFrame */
        "testl %eax, %eax\n" /* line 1144 */
        "jne .Lf193c24_001942e3\n"
        "addl $1, %ebx\n" /* line 1146 | archivedFrame */
        "cmpl 0x2c(%edi), %ebx\n" /* line 1141 | i, archivedFrame */
        "jl .Lf193c24_00194825\n"
        "jmp .Lf193c24_001942cf\n"
        /* } scope */
        ".Lf193c24_00194847:\n"
        "movl -0x12f0(%ebp), %ebx\n" /* line 1546 | cachedFrame, state */
        "movl 0x10(%ebx), %eax\n" /* state */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00193c6b\n"
        "xorl %edi, %edi\n" /* i */
        "movl 0x195f284, %ebx\n" /* state */
        "movl -0x12f0(%ebp), %ecx\n" /* cachedFrame */
        "jmp .Lf193c24_00194883\n"
        ".Lf193c24_00194868:\n"
        "addl $1, 0x26ac(%esi)\n" /* line 1561 | frame */
        "addl $1, %edi\n" /* line 1546 | i */
        "movl -0x12f0(%ebp), %eax\n" /* cachedFrame */
        "cmpl %edi, 0x10(%eax)\n" /* i */
        "jle .Lf193c24_00193c6b\n"
        "movl %eax, %ecx\n"
        ".Lf193c24_00194883:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1550 | state */
        "cltd\n"
        "idivl 0x14(%ebx)\n" /* state */
        "movl 0x24(%ebx), %eax\n" /* state */
        "movl %eax, -0x1304(%ebp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "movl %edi, %eax\n" /* i */
        "addl 0x14(%ecx), %eax\n"
        "movl %eax, %ecx\n"
        "andl $0x80000fff, %ecx\n"
        "js .Lf193c24_0019490e\n"
        ".Lf193c24_001948b1:\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %ecx, %eax\n"
        "shll $5, %eax\n"
        "addl %ecx, %eax\n"
        "shll $3, %eax\n"
        "addl -0x1304(%ebp), %edx\n"
        "addl 0x4c(%ebx), %eax\n" /* state */
        "addl $4, %eax\n"
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1555 | state */
        "addl $1, %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* state */
        "cmpl $0x7ffffffd, %eax\n" /* line 1557 */
        "jle .Lf193c24_00194868\n"
        "movl $0x2b05cc, 4(%esp)\n" /* line 1559 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194868\n"
        ".Lf193c24_0019490e:\n"
        "subl $1, %ecx\n" /* line 1550 */
        "orl $0xfffff000, %ecx\n"
        "addl $1, %ecx\n"
        "jmp .Lf193c24_001948b1\n"
        /* } scope */
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        ".Lf193c24_0019491c:\n"
        "movl %ecx, %eax\n" /* line 386 */
        "addl $0x20c48, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b05f0, (%esp)\n" /* "%s: Delta request from out of date packet.
" */
        "calll Com_DPrintf\n"
        "jmp .Lf193c24_00193d9b\n"
        /* } scope */
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194938:\n"
        "movl $0, -0x12f0(%ebp)\n" /* line 1141 | cachedFrame */
        "jmp .Lf193c24_001942e3\n"
        /* } scope */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194947:\n"
        "leal -0x2c(%ebp), %ebx\n" /* line 639 | org, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll CM_PointLeafnum\n"
        "movl %eax, (%esp)\n" /* line 641 */
        "calll CM_LeafCluster\n"
        "testl %eax, %eax\n" /* line 642 */
        "js .Lf193c24_001949a9\n"
        "movl %eax, (%esp)\n" /* line 645 */
        "calll CM_ClusterPVS\n"
        "movl %eax, -0x12d0(%ebp)\n" /* bitvector */
        "calll G_GetFogOpaqueDistSqrd\n" /* line 647 */
        "fstps -0x12cc(%ebp)\n" /* fogOpaqueDistSqrd */
        "movss -0x12cc(%ebp), %xmm0\n" /* line 648 | fogOpaqueDistSqrd */
        "movaps %xmm0, %xmm1\n"
        "cmpneqss 0x2ed684, %xmm0\n" /* 3.4028234663852886e+38f */
        "andps %xmm1, %xmm0\n"
        "movss %xmm0, -0x12cc(%ebp)\n" /* fogOpaqueDistSqrd */
        "movl 0x195ee80, %eax\n" /* line 651 */
        "movl 0x5f424(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf193c24_00194c86\n"
        /* } scope */
        ".Lf193c24_001949a9:\n"
        "movl 0x195f284, %edx\n" /* line 1488 */
        "movl 0xc(%edx), %ecx\n"
        "movl %ecx, -0x12f4(%ebp)\n" /* client */
        "movl 0x195f290, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf193c24_00193c6b\n"
        "movl $0, -0x1260(%ebp)\n"
        "movl %edx, %edi\n" /* i */
        "jmp .Lf193c24_00194a01\n"
        ".Lf193c24_001949d9:\n"
        "movl 0x195f290, %ecx\n"
        ".Lf193c24_001949df:\n"
        "addl $1, -0x1260(%ebp)\n"
        "addl $0x78f0c, -0x12f4(%ebp)\n" /* client */
        "movl (%ecx), %eax\n"
        "movl -0x1260(%ebp), %ebx\n" /* state */
        "cmpl 8(%eax), %ebx\n" /* state */
        "jge .Lf193c24_00193c6b\n"
        ".Lf193c24_00194a01:\n"
        "movl -0x12f4(%ebp), %ebx\n" /* line 1490 | client, state */
        "cmpl $1, (%ebx)\n" /* state */
        "jle .Lf193c24_001949df\n"
        "movl 0x1c(%edi), %eax\n" /* line 1492 | i */
        "cltd\n"
        "idivl 0x14(%edi)\n" /* i */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x24(%edi), %edx\n" /* i */
        "leal (%edx, %eax, 4), %ebx\n" /* state */
        "movl -0x1260(%ebp), %eax\n" /* line 1493 */
        "movl %eax, (%esp)\n"
        "calll G_GetClientState\n"
        "movl $0x5c, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll memcpy\n"
        "movl -0x1260(%ebp), %edx\n" /* line 1496 */
        "cmpl (%ebx), %edx\n" /* state */
        "jne .Lf193c24_001949d9\n"
        "movl 0x1c(%edi), %eax\n" /* line 1506 | i */
        "addl $1, %eax\n"
        "movl %eax, 0x1c(%edi)\n" /* i */
        "cmpl $0x7ffffffd, %eax\n" /* line 1508 */
        "jg .Lf193c24_00194c6d\n"
        ".Lf193c24_00194a61:\n"
        "addl $1, 0x26ac(%esi)\n" /* line 1512 | frame */
        "movl 0x195f290, %ecx\n"
        "jmp .Lf193c24_001949df\n"
        ".Lf193c24_00194a73:\n"
        "movl -0x1264(%ebp), %eax\n" /* line 1520 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00194847\n"
        "movl $0, -0x125c(%ebp)\n"
        "movl 0x195f284, %edi\n" /* i */
        "jmp .Lf193c24_00194ab3\n"
        ".Lf193c24_00194a93:\n"
        "addl $1, 0x26a8(%esi)\n" /* line 1542 | frame */
        "addl $1, -0x125c(%ebp)\n" /* line 1520 */
        "movl -0x1264(%ebp), %ecx\n"
        "cmpl %ecx, -0x125c(%ebp)\n"
        "je .Lf193c24_00194847\n"
        ".Lf193c24_00194ab3:\n"
        "movl 0x18(%edi), %eax\n" /* line 1523 | i */
        "cltd\n"
        "idivl 0x10(%edi)\n" /* i */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ebx\n" /* state */
        "shll $8, %ebx\n" /* state */
        "subl %eax, %ebx\n" /* state */
        "addl 0x20(%edi), %ebx\n" /* i, state */
        "movl -0x12f0(%ebp), %ecx\n" /* line 1524 | cachedFrame */
        "movl 0xc(%ecx), %eax\n"
        "movl -0x125c(%ebp), %edx\n"
        "addl -0x1250(%ebp, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "andl $0x80003fff, %edx\n"
        "js .Lf193c24_00194b7e\n"
        ".Lf193c24_00194aed:\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl 0x48(%edi), %eax\n" /* i */
        "movl $0xf0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll memcpy\n"
        "movl 0x10(%ebx), %eax\n" /* line 1527 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b21\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1528 | deltaTime */
        "movl %eax, 0x10(%ebx)\n" /* state */
        ".Lf193c24_00194b21:\n"
        "movl 0x34(%ebx), %eax\n" /* line 1529 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b31\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1530 | deltaTime */
        "movl %eax, 0x34(%ebx)\n" /* state */
        ".Lf193c24_00194b31:\n"
        "movl 0x54(%ebx), %eax\n" /* line 1531 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b41\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1532 | deltaTime */
        "movl %eax, 0x54(%ebx)\n" /* state */
        ".Lf193c24_00194b41:\n"
        "movl 0x58(%ebx), %eax\n" /* line 1533 | state */
        "testl %eax, %eax\n"
        "je .Lf193c24_00194b51\n"
        "addl -0x12ec(%ebp), %eax\n" /* line 1534 | deltaTime */
        "movl %eax, 0x58(%ebx)\n" /* state */
        ".Lf193c24_00194b51:\n"
        "movl 0x18(%edi), %eax\n" /* line 1536 | i */
        "addl $1, %eax\n"
        "movl %eax, 0x18(%edi)\n" /* i */
        "cmpl $0x7ffffffd, %eax\n" /* line 1538 */
        "jle .Lf193c24_00194a93\n"
        "movl $0x2b05a8, 4(%esp)\n" /* line 1540 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194a93\n"
        ".Lf193c24_00194b7e:\n"
        "subl $1, %edx\n" /* line 1524 */
        "orl $0xffffc000, %edx\n"
        "addl $1, %edx\n"
        "jmp .Lf193c24_00194aed\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        /* { scope 5: e */
        ".Lf193c24_00194b8f:\n"
        "leal 0x108(%edx), %ecx\n" /* line 805 */
        "movl %ecx, -0x12b8(%ebp)\n"
        "addl $0xfc, %edx\n"
        "movl %edx, -0x12b4(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* lastLeaf */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x80, 0xc(%esp)\n"
        "leal -0x250(%ebp), %eax\n" /* leafs */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CM_BoxLeafnums\n"
        "movl %eax, %ebx\n" /* num_leafs */
        "testl %eax, %eax\n" /* line 806 */
        "je .Lf193c24_001944f7\n"
        "testl %ebx, %ebx\n" /* line 809 | num_leafs */
        "jg .Lf193c24_00194fb0\n"
        ".Lf193c24_00194bde:\n"
        "movss -0x12ac(%ebp), %xmm0\n" /* line 821 | fogOpaqueDistSqrd */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf193c24_00194f7e\n"
        "jne .Lf193c24_00194f7e\n"
        /* { scope 6 */
        ".Lf193c24_00194bf9:\n"
        "cmpl $0x400, -0x1264(%ebp)\n" /* line 608 */
        "je .Lf193c24_001944f7\n"
        "movl -0x12a8(%ebp), %eax\n" /* line 613 | e */
        "movl -0x1264(%ebp), %ebx\n" /* i */
        "movl %eax, -0x1250(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 614 | i */
        "movl %ebx, -0x1264(%ebp)\n" /* i */
        "jmp .Lf193c24_001944f7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf193c24_00194c2a:\n"
        "movl $0, -0x12ec(%ebp)\n" /* line 1446 | deltaTime */
        "jmp .Lf193c24_00194328\n"
        ".Lf193c24_00194c39:\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "jmp .Lf193c24_001946ac\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194c41:\n"
        "movl -0x12e4(%ebp), %edx\n" /* line 1138 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl -0x12e0(%ebp)\n"
        "movl %eax, -0x12e8(%ebp)\n" /* archiveTime */
        "xorl %ebx, %ebx\n" /* archivedFrame */
        "jmp .Lf193c24_001942c3\n"
        /* } scope */
        ".Lf193c24_00194c6d:\n"
        "movl $0x2b05cc, 4(%esp)\n" /* line 1510 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194a61\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194c86:\n"
        "movl $0, -0x12c8(%ebp)\n" /* line 651 | entnum */
        "movl $0, -0x1270(%ebp)\n"
        "jmp .Lf193c24_00194cf2\n"
        ".Lf193c24_00194c9c:\n"
        "jl .Lf193c24_00194cac\n" /* line 675 */
        "movl 0x195f284, %eax\n"
        "cmpl 4(%eax), %edx\n"
        "js .Lf193c24_0019500d\n"
        ".Lf193c24_00194cac:\n"
        "cmpl $0x400, -0x1270(%ebp)\n" /* line 590 */
        "je .Lf193c24_00194cd4\n"
        "movl -0x12c8(%ebp), %eax\n" /* line 595 | entnum */
        "movl -0x1270(%ebp), %ebx\n" /* i */
        "movl %eax, -0x1250(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 596 | i */
        "movl %ebx, -0x1270(%ebp)\n" /* i */
        ".Lf193c24_00194cd4:\n"
        "addl $1, -0x12c8(%ebp)\n" /* line 651 | entnum */
        "movl 0x195ee80, %eax\n"
        "movl -0x12c8(%ebp), %ebx\n" /* entnum, i */
        "cmpl %ebx, 0x5f424(%eax)\n" /* i */
        "jle .Lf193c24_00194e55\n"
        ".Lf193c24_00194cf2:\n"
        "movl -0x12c8(%ebp), %eax\n" /* line 653 | entnum */
        "movl %eax, (%esp)\n"
        "calll SV_GentityNum\n"
        "movl %eax, -0x12d4(%ebp)\n" /* ent */
        "cmpb $0, 0xf0(%eax)\n" /* line 656 */
        "je .Lf193c24_00194cd4\n"
        "movl -0x12c4(%ebp), %edx\n" /* line 661 | clientNum */
        "cmpl %edx, -0x12c8(%ebp)\n" /* entnum */
        "je .Lf193c24_00194cd4\n"
        "movl 0x100(%eax), %edx\n" /* line 664 */
        "cmpl $0, %edx\n"
        "jne .Lf193c24_00194c9c\n"
        "testb $1, 0xf2(%eax)\n" /* line 667 */
        "jne .Lf193c24_00194cd4\n"
        "movl -0x12c4(%ebp), %eax\n" /* line 670 | clientNum */
        "sarl $5, %eax\n"
        "movl -0x12c4(%ebp), %ecx\n" /* clientNum */
        "andl $0x1f, %ecx\n"
        "movl -0x12d4(%ebp), %ebx\n" /* ent, i */
        "movl 0xf4(%ebx, %eax, 4), %eax\n" /* i */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_00194cd4\n"
        ".Lf193c24_00194d5e:\n"
        "movl -0x12d4(%ebp), %ecx\n" /* line 684 | ent */
        "movzbl 0xf2(%ecx), %eax\n"
        "testb $0x18, %al\n"
        "jne .Lf193c24_00194cac\n"
        "movl -0x12d4(%ebp), %edx\n" /* line 690 | ent */
        "movl %edx, (%esp)\n"
        "calll SV_SvEntityForGentity\n"
        "movl %eax, %edi\n" /* svEnt */
        "movl 0x118(%eax), %ecx\n" /* line 693 */
        "movl %ecx, -0x12dc(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lf193c24_00194cd4\n"
        "movl -0x12dc(%ebp), %eax\n" /* line 699 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_00194e09\n"
        "movl 0x11c(%edi), %edx\n" /* line 701 | svEnt */
        "movl %edx, %eax\n" /* line 702 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%eax, %ecx), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_00194e09\n"
        "movl %edi, %ebx\n" /* line 703 | svEnt, i */
        "movl $0, -0x12d8(%ebp)\n" /* i */
        ".Lf193c24_00194dcd:\n"
        "addl $1, -0x12d8(%ebp)\n" /* line 699 | i */
        "movl -0x12d8(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x12dc(%ebp)\n"
        "je .Lf193c24_00194ef1\n"
        "movl 0x120(%ebx), %edx\n" /* line 701 | i */
        "addl $4, %ebx\n" /* i */
        "movl %edx, %eax\n" /* line 702 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%eax, %ecx), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf193c24_00194dcd\n"
        ".Lf193c24_00194e09:\n"
        "movss -0x12cc(%ebp), %xmm0\n" /* line 722 | fogOpaqueDistSqrd */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf193c24_00194f42\n"
        "jne .Lf193c24_00194f42\n"
        /* { scope 5: e */
        ".Lf193c24_00194e24:\n"
        "cmpl $0x400, -0x1270(%ebp)\n" /* line 590 */
        "je .Lf193c24_00194cd4\n"
        "movl -0x12c8(%ebp), %ecx\n" /* line 595 | entnum */
        "movl -0x1270(%ebp), %edx\n"
        "movl %ecx, -0x1250(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 596 */
        "movl %edx, -0x1270(%ebp)\n"
        "jmp .Lf193c24_00194cd4\n"
        /* } scope */
        /* } scope */
        ".Lf193c24_00194e55:\n"
        "movl -0x1270(%ebp), %eax\n" /* line 1473 */
        "testl %eax, %eax\n"
        "jle .Lf193c24_001949a9\n"
        "xorl %edi, %edi\n" /* i */
        "movl 0x195f284, %ebx\n" /* state */
        "jmp .Lf193c24_00194e83\n"
        ".Lf193c24_00194e6d:\n"
        "addl $1, 0x26a8(%esi)\n" /* line 1484 | frame */
        "addl $1, %edi\n" /* line 1473 | i */
        "cmpl -0x1270(%ebp), %edi\n" /* i */
        "je .Lf193c24_001949a9\n"
        ".Lf193c24_00194e83:\n"
        "movl -0x1250(%ebp, %edi, 4), %eax\n" /* line 1475 */
        "movl %eax, (%esp)\n"
        "calll SV_GentityNum\n"
        "movl %eax, -0x130c(%ebp)\n" /* ent */
        "movl 0x18(%ebx), %ecx\n" /* line 1477 | state */
        "movl %ecx, %eax\n"
        "cltd\n"
        "idivl 0x10(%ebx)\n" /* state */
        "movl %edx, %ecx\n"
        "shll $4, %edx\n"
        "shll $8, %ecx\n"
        "subl %edx, %ecx\n"
        "addl 0x20(%ebx), %ecx\n" /* state */
        "movl $0xf0, 8(%esp)\n"
        "movl -0x130c(%ebp), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x18(%ebx), %eax\n" /* line 1478 | state */
        "addl $1, %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* state */
        "cmpl $0x7ffffffd, %eax\n" /* line 1480 */
        "jle .Lf193c24_00194e6d\n"
        "movl $0x2b05a8, 4(%esp)\n" /* line 1482 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf193c24_00194e6d\n"
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_00194ef1:\n"
        "movl 0x15c(%edi), %ebx\n" /* line 710 | svEnt, i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf193c24_00194cd4\n"
        "cmpl %edx, %ebx\n" /* line 713 | i */
        "jl .Lf193c24_00194f35\n"
        "movl %edx, %eax\n" /* line 715 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%ecx, %eax), %eax\n"
        ".Lf193c24_00194f12:\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf193c24_00194f35\n"
        "addl $1, %edx\n" /* line 713 */
        "cmpl %ebx, %edx\n" /* i */
        "jg .Lf193c24_00194f35\n"
        "movl %edx, %eax\n" /* line 715 */
        "sarl $3, %eax\n"
        "movl -0x12d0(%ebp), %ecx\n" /* bitvector */
        "movzbl (%eax, %ecx), %eax\n"
        "jmp .Lf193c24_00194f12\n"
        ".Lf193c24_00194f35:\n"
        "cmpl %ebx, %edx\n" /* line 718 | i */
        "jne .Lf193c24_00194e09\n"
        "jmp .Lf193c24_00194cd4\n"
        ".Lf193c24_00194f42:\n"
        "movss %xmm0, 0xc(%esp)\n" /* line 722 */
        "leal -0x2c(%ebp), %eax\n" /* org */
        "movl %eax, 8(%esp)\n"
        "movl -0x12d4(%ebp), %eax\n" /* ent */
        "addl $0x12c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x12d4(%ebp), %eax\n" /* ent */
        "addl $0x120, %eax\n"
        "movl %eax, (%esp)\n"
        "calll BoxDistSqrdExceeds\n"
        "testl %eax, %eax\n"
        "jne .Lf193c24_00194cd4\n"
        "jmp .Lf193c24_00194e24\n"
        /* } scope */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        /* { scope 5: e */
        ".Lf193c24_00194f7e:\n"
        "movss %xmm0, 0xc(%esp)\n" /* line 821 */
        "leal -0x2c(%ebp), %eax\n" /* org */
        "movl %eax, 8(%esp)\n"
        "movl -0x12b8(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x12b4(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll BoxDistSqrdExceeds\n"
        "testl %eax, %eax\n"
        "jne .Lf193c24_001944f7\n"
        "jmp .Lf193c24_00194bf9\n"
        ".Lf193c24_00194fb0:\n"
        "xorl %edi, %edi\n" /* line 806 | i */
        "jmp .Lf193c24_00194fbf\n"
        ".Lf193c24_00194fb4:\n"
        "addl $1, %edi\n" /* line 809 | i */
        "cmpl %ebx, %edi\n" /* num_leafs, i */
        "je .Lf193c24_001944f7\n"
        ".Lf193c24_00194fbf:\n"
        "movl -0x250(%ebp, %edi, 4), %eax\n" /* line 811 */
        "movl %eax, (%esp)\n"
        "calll CM_LeafCluster\n"
        "movl %eax, %ecx\n"
        "cmpl $-1, %eax\n" /* line 812 */
        "je .Lf193c24_00194fb4\n"
        "sarl $3, %eax\n"
        "movl -0x12b0(%ebp), %edx\n" /* clientpvs */
        "movzbl (%edx, %eax), %eax\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf193c24_00194fb4\n"
        "cmpl %edi, %ebx\n" /* line 818 | i, num_leafs */
        "je .Lf193c24_001944f7\n"
        "jmp .Lf193c24_00194bde\n"
        "movl %eax, %ebx\n" /* num_leafs */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "leal -0x1c(%ebp), %ecx\n" /* line 1762 | msg_buf_large_local */
        "movl %ecx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll __Unwind_Resume\n"
        /* { scope 2: to_first_entity, to_num_entities, from_first_entity, from_num_entities, ... */
        /* { scope 3: oldindex, newindex, oldclient, newclient, ... */
        /* { scope 4: clientpvs, leafs, lastLeaf, fogOpaqueDistSqrd, ... */
        ".Lf193c24_0019500d:\n"
        "movl -0x12d4(%ebp), %edx\n" /* line 680 | ent */
        "movl $0, 0x100(%edx)\n"
        "jmp .Lf193c24_00194d5e\n"
    );
}

/* line 2077 */
__attribute__((naked))
void SV_SendClientMessages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2077 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl 0x195ee80, %eax\n" /* line 2085 */
        "movl $0, 0x5f48c(%eax)\n"
        "movl $0, 0x5f4e4(%eax)\n" /* line 2086 */
        "movl 0x195f284, %eax\n" /* line 2089 */
        "movl 0xc(%eax), %ebx\n" /* c */
        "movl 0x195f290, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf195022_0019520b\n"
        "movl $0, -0x2c(%ebp)\n" /* i */
        "movl $0, -0x28(%ebp)\n" /* numclients */
        ".Lf195022_0019506d:\n"
        "movl (%ebx), %edi\n" /* line 2091 | c */
        "testl %edi, %edi\n"
        "je .Lf195022_00195140\n"
        "movl 0x195f284, %eax\n" /* line 2096 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "leal 0x20d18(%ebx), %eax\n" /* line 2077 */
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2096 */
        "cmpl 0x20d18(%ebx), %ecx\n" /* c */
        "jl .Lf195022_00195140\n"
        "addl $1, -0x28(%ebp)\n" /* line 2101 | numclients */
        "movl 0x725dc(%ebx), %esi\n" /* line 2105 | c, rate */
        "testl %esi, %esi\n" /* rate */
        "je .Lf195022_00195319\n"
        "movl 0x725e4(%ebx), %edi\n" /* line 2107 | c, messageSize */
        "subl 0x725e0(%ebx), %edi\n" /* c, messageSize */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl $0x5dc, %edi\n" /* line 1587 */
        "jle .Lf195022_00195217\n"
        "movl $0x5dc, %edi\n"
        "movl $0x16e360, -0x24(%ebp)\n"
        ".Lf195022_001950d0:\n"
        "leal 0x6e5a8(%ebx), %eax\n" /* line 2077 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x6e5a8(%ebx), %esi\n" /* line 1591 | rate */
        "movl 0x195f268, %ecx\n" /* line 1592 */
        "movl (%ecx), %edx\n"
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf195022_00195101\n"
        "cmpl $0x3e7, %eax\n" /* line 1594 */
        "jle .Lf195022_00195378\n"
        ".Lf195022_001950f9:\n"
        "movl 8(%edx), %eax\n" /* line 1598 */
        "cmpl %eax, %esi\n" /* rate */
        "cmovgl %eax, %esi\n" /* rate */
        ".Lf195022_00195101:\n"
        "movl -0x24(%ebp), %edx\n" /* line 1603 */
        "addl $0xbb80, %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl %esi\n" /* rate */
        "movl %eax, %esi\n" /* rate */
        "movl 0x195f2bc, %eax\n" /* line 1605 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf195022_0019534c\n"
        /* } scope */
        /* } scope */
        ".Lf195022_00195122:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2107 */
        "addl %esi, %eax\n" /* rate */
        "movl -0x20(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "leal 0x6e5b4(%ebx), %eax\n" /* line 2108 | c */
        "movl %eax, (%esp)\n"
        "calll SV_Netchan_TransmitNextFragment\n"
        "movl 0x195f290, %edx\n"
        ".Lf195022_00195140:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 2089 | i */
        "addl $0x78f0c, %ebx\n" /* c */
        "movl (%edx), %eax\n"
        "movl -0x2c(%ebp), %ecx\n" /* i */
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf195022_0019506d\n"
        ".Lf195022_00195158:\n"
        "movl 0x195f288, %eax\n" /* line 2128 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf195022_00195203\n"
        "movl -0x28(%ebp), %ebx\n" /* numclients, c */
        "testl %ebx, %ebx\n" /* c */
        "jle .Lf195022_00195203\n"
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movl 0x195ee80, %ebx\n" /* c */
        "movl %ebx, %edx\n" /* c */
        "leal 0x4c(%ebx), %ecx\n" /* c */
        /* { scope 2 */
        ".Lf195022_00195186:\n"
        "movl 0x5f43c(%edx), %eax\n" /* line 2134 */
        "movl %eax, 0x5f438(%edx)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 2135 */
        "addss %xmm0, %xmm1\n"
        "movl 0x5f498(%edx), %eax\n" /* line 2137 */
        "movl %eax, 0x5f494(%edx)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 2138 */
        "addss %xmm0, %xmm2\n"
        "addl $4, %edx\n"
        "cmpl %ecx, %edx\n" /* line 2132 */
        "jne .Lf195022_00195186\n"
        "movl %ebx, %eax\n" /* line 2141 | c */
        "movl 0x5f48c(%ebx), %ecx\n" /* c */
        "movl %ecx, 0x5f484(%ebx)\n" /* c */
        "cvtsi2ssl %ecx, %xmm3\n" /* line 2142 */
        "addss %xmm1, %xmm3\n"
        "movl 0x5f4e4(%ebx), %edx\n" /* line 2144 | c */
        "movl %edx, 0x5f4e0(%ebx)\n" /* c */
        "cvtsi2ssl %edx, %xmm4\n" /* line 2145 */
        "addss %xmm2, %xmm4\n"
        "cmpl 0x5f490(%ebx), %ecx\n" /* line 2147 | c */
        "jge .Lf195022_00195247\n"
        "cmpl 0x5f4e8(%eax), %edx\n" /* line 2150 */
        "jge .Lf195022_0019522b\n"
        ".Lf195022_001951ef:\n"
        "movl 0x5f488(%ebx), %eax\n" /* line 2153 | c */
        "addl $1, %eax\n"
        "movl %eax, 0x5f488(%ebx)\n" /* c */
        "cmpl $0x13, %eax\n" /* line 2155 */
        "jg .Lf195022_00195257\n"
        /* } scope */
        /* } scope */
        ".Lf195022_00195203:\n"
        "addl $0x6c, %esp\n" /* line 2173 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195022_0019520b:\n"
        "movl $0, -0x28(%ebp)\n" /* line 2089 | numclients */
        "jmp .Lf195022_00195158\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf195022_00195217:\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 1587 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "jmp .Lf195022_001950d0\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf195022_0019522b:\n"
        "movl %edx, 0x5f4e8(%eax)\n" /* line 2151 */
        "movl 0x5f488(%ebx), %eax\n" /* line 2153 | c */
        "addl $1, %eax\n"
        "movl %eax, 0x5f488(%ebx)\n" /* c */
        "cmpl $0x13, %eax\n" /* line 2155 */
        "jle .Lf195022_00195203\n"
        "jmp .Lf195022_00195257\n"
        ".Lf195022_00195247:\n"
        "movl %ecx, 0x5f490(%ebx)\n" /* line 2148 | c */
        "cmpl 0x5f4e8(%eax), %edx\n" /* line 2150 */
        "jl .Lf195022_001951ef\n"
        "jmp .Lf195022_0019522b\n"
        /* { scope 3 */
        ".Lf195022_00195257:\n"
        "movl $0, 0x5f488(%ebx)\n" /* line 2159 | c */
        "movss 0x2ed694, %xmm0\n" /* line 2161 | 20.0f */
        "divss %xmm0, %xmm3\n"
        "divss %xmm0, %xmm4\n" /* line 2162 */
        "movaps %xmm3, %xmm0\n" /* line 2164 */
        "divss %xmm4, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "mulss 0x2ed798, %xmm1\n" /* 100.0f */
        "movaps %xmm1, %xmm0\n" /* line 2165 */
        "addss 0x5f4ec(%ebx), %xmm0\n" /* c */
        "movss %xmm0, 0x5f4ec(%ebx)\n" /* c */
        "movl 0x5f4f0(%ebx), %eax\n" /* line 2166 | c */
        "addl $1, %eax\n"
        "movl %eax, 0x5f4f0(%ebx)\n" /* c */
        "cvtsi2ssl %eax, %xmm2\n" /* line 2168 */
        "divss %xmm2, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0x2c(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0x24(%esp)\n"
        "movl 0x5f4e8(%ebx), %eax\n" /* c */
        "movl %eax, 0x20(%esp)\n"
        "cvtss2sd %xmm4, %xmm4\n"
        "movsd %xmm4, 0x18(%esp)\n"
        "movl 0x5f490(%ebx), %eax\n" /* c */
        "movl %eax, 0x14(%esp)\n"
        "cvtss2sd %xmm3, %xmm0\n"
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtsi2ssl -0x28(%ebp), %xmm0\n" /* numclients */
        "divss %xmm0, %xmm3\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 4(%esp)\n"
        "movl $0x2b06d0, (%esp)\n" /* "bpspc(%2.0f) bps(%2.0f) pk(%i) ubps(%2.0f) upk(%i) cr(%2.2f)" */
        "calll Com_DPrintf\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2173 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf195022_00195319:\n"
        "movl %ebx, (%esp)\n" /* line 2119 | c */
        "calll SV_SendClientSnapshot\n"
        "movl %ebx, (%esp)\n" /* line 2123 | c */
        "calll SV_SendClientVoiceData\n"
        "movl 0x195f290, %edx\n"
        "addl $1, -0x2c(%ebp)\n" /* line 2089 | i */
        "addl $0x78f0c, %ebx\n" /* c */
        "movl (%edx), %eax\n"
        "movl -0x2c(%ebp), %ecx\n" /* i */
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf195022_0019506d\n"
        "jmp .Lf195022_00195158\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf195022_0019534c:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1606 */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal 0x20c48(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* rate */
        "movl $0x2b0548, (%esp)\n" /* "It would take %ims to send %i bytes to client %s (rate %i)
" */
        "calll Com_Printf\n"
        "jmp .Lf195022_00195122\n"
        ".Lf195022_00195378:\n"
        "movl $0x3e8, 4(%esp)\n" /* line 1596 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl 0x195f268, %eax\n"
        "movl (%eax), %edx\n"
        "jmp .Lf195022_001950f9\n"
    );
}

