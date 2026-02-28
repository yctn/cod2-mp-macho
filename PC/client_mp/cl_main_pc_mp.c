/* ASM dump from: cl_main_pc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_main_pc_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern serverStatus_t cl_serverStatusList[16]; /* 0x0 */
static Bool s_playerMute[64]; /* s_playerMute */
extern int NET_CompareAdrSigned(const int *a, const int *b);
extern void qsort(void *base, unsigned int nmemb, unsigned int size, int (*compar)(const void *, const void *));

static int rconGlob; /* rconGlob */

static int CL_CompareAdrSigned(const int *a, const int *b);
int CL_SetServerInfo(serverInfo_t *server, const char *info, int ping);
int CL_SetServerInfoByAddress(netadr_t from, const char *info, int ping);
int CL_ServerInfoPacket(netadr_t from, msg_t *msg, int time);
qboolean CL_CDKeyValidate(const char *key, const char *checksum);
int CL_SortGlobalServers(void);
int CL_RconInit(void);
int CL_Rcon_f(void);
int CL_ServerStatusResponse(netadr_t from, msg_t *msg);
int CL_ResetPlayerMuting(int clientIndex);
int CL_MutePlayer(int clientIndex);
Bool CL_IsPlayerMuted(int clientIndex);
int CL_ClearMutedList(void);
int CL_GlobalServers_f(void);
int CL_ServersResponsePacket(netadr_t from, msg_t *msg);
int CL_Ping_f(void);
int CL_Connect_f(void);
int CL_ServerStatus(char *serverAddress, char *serverStatusString, int maxLen);
int CL_ServerStatus_f(void);

/* line 89 */
static int CL_CompareAdrSigned(const int *a, const int *b)
{
    return NET_CompareAdrSigned(a, b);
}

/* line 156 */
__attribute__((naked))
int CL_SetServerInfo(serverInfo_t *server, const char *info, int ping)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 156 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* server */
        "movl 0xc(%ebp), %esi\n" /* info */
        "testl %ebx, %ebx\n" /* line 158 | server */
        "je .Lf15f6ea_0015f927\n"
        "testl %esi, %esi\n" /* line 160 | info */
        "je .Lf15f6ea_0015f920\n"
        "movl $str_002a8a54, 4(%esp)\n" /* line 162 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0xd(%ebx)\n" /* server */
        "movl $str_002aa89c, 4(%esp)\n" /* line 163 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%ebx), %eax\n" /* server */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002a7124, 4(%esp)\n" /* line 164 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x40(%ebx), %eax\n" /* server */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002a70dc, 4(%esp)\n" /* line 165 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0xe(%ebx)\n" /* server */
        "movl $str_002aa890, 4(%esp)\n" /* line 166 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl $0x18, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x60(%ebx), %eax\n" /* server */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002aa884, 4(%esp)\n" /* line 167 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl $0x10, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x78(%ebx), %eax\n" /* server */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab8c0, 4(%esp)\n" /* line 168 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0xc(%ebx)\n" /* server */
        "movl $str_002ab8c8, 4(%esp)\n" /* line 169 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movw %ax, 0x1a(%ebx)\n" /* server */
        "movl $str_002ab8d0, 4(%esp)\n" /* line 170 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movw %ax, 0x1c(%ebx)\n" /* server */
        "movl $str_002a718c, 4(%esp)\n" /* line 171 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x10(%ebx)\n" /* server */
        "movl $str_002ab4e0, 4(%esp)\n" /* line 172 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x15(%ebx)\n" /* server */
        "movl $str_002a9af0, 4(%esp)\n" /* line 173 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x11(%ebx)\n" /* server */
        "movl $str_002aa870, 4(%esp)\n" /* line 174 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x12(%ebx)\n" /* server */
        "movl $str_002aa87c, 4(%esp)\n" /* line 175 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x13(%ebx)\n" /* server */
        "movl $str_002aa880, 4(%esp)\n" /* line 176 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x14(%ebx)\n" /* server */
        "movl $str_002aa878, 4(%esp)\n" /* line 177 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x16(%ebx)\n" /* server */
        "movl $str_002a9cf4, 4(%esp)\n" /* line 178 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x17(%ebx)\n" /* server */
        "movl $str_0021ec00, 4(%esp)\n" /* line 180 */
        "movl %esi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movb %al, 0x18(%ebx)\n" /* server */
        ".Lf15f6ea_0015f920:\n"
        "movl 0x10(%ebp), %eax\n" /* line 183 | ping */
        "movw %ax, 0x1e(%ebx)\n" /* server */
        ".Lf15f6ea_0015f927:\n"
        "addl $0x10, %esp\n" /* line 185 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 94 */
__attribute__((naked))
int CL_SetServerInfoByAddress(netadr_t from, const char *info, int ping)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "calll Com_PumpMessageLoop\n" /* line 101 */
        "movl $0, -0x4c(%ebp)\n"
        "movl imp_cls, %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "addl $0x13c, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "jmp .Lf15f92e_0015f974\n"
        ".Lf15f92e_0015f955:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 103 */
        "addl $0x88, -0x68(%ebp)\n"
        "addl $0x88, -0x54(%ebp)\n"
        "cmpl $0x80, -0x4c(%ebp)\n"
        "je .Lf15f92e_0015f9fc\n"
        ".Lf15f92e_0015f974:\n"
        "movl -0x54(%ebp), %edx\n" /* line 105 */
        "movl 0x13c(%edx), %edi\n" /* i */
        "movl %edi, -0x48(%ebp)\n" /* i */
        "movl 0x140(%edx), %esi\n" /* high */
        "movl %esi, -0x44(%ebp)\n" /* high */
        "movl 0x144(%edx), %ebx\n"
        "movl %ebx, -0x40(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* from */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x10(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %edi, 0xc(%esp)\n" /* i */
        "movl %esi, 0x10(%esp)\n" /* high */
        "movl %ebx, 0x14(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf15f92e_0015f955\n"
        "movl 0x18(%ebp), %eax\n" /* line 107 | ping */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* info */
        "movl %edx, 4(%esp)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_SetServerInfo\n"
        "addl $1, -0x4c(%ebp)\n" /* line 103 */
        "addl $0x88, -0x68(%ebp)\n"
        "addl $0x88, -0x54(%ebp)\n"
        "cmpl $0x80, -0x4c(%ebp)\n"
        "jne .Lf15f92e_0015f974\n"
        ".Lf15f92e_0015f9fc:\n"
        "movl imp_cls, %ecx\n" /* line 112 */
        "movl 0x4540(%ecx), %esi\n" /* high */
        "testl %esi, %esi\n" /* line 113 | high */
        "jg .Lf15f92e_0015fac4\n"
        ".Lf15f92e_0015fa10:\n"
        "movl $0, -0x50(%ebp)\n"
        "leal str_0029c494+436(%ecx), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf15f92e_0015fa45\n"
        ".Lf15f92e_0015fa27:\n"
        "addl $1, -0x50(%ebp)\n" /* line 145 */
        "addl $0x88, -0x64(%ebp)\n"
        "addl $0x88, -0x58(%ebp)\n"
        "cmpl $0x80, -0x50(%ebp)\n"
        "je .Lf15f92e_0015fabc\n"
        ".Lf15f92e_0015fa42:\n"
        "movl -0x58(%ebp), %edx\n"
        ".Lf15f92e_0015fa45:\n"
        "movl (%edx), %edi\n" /* line 147 | i */
        "movl %edi, -0x30(%ebp)\n" /* i */
        "movl 4(%edx), %esi\n" /* high */
        "movl %esi, -0x2c(%ebp)\n" /* high */
        "movl 8(%edx), %ebx\n"
        "movl %ebx, -0x28(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* from */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x10(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edi, 0xc(%esp)\n" /* i */
        "movl %esi, 0x10(%esp)\n" /* high */
        "movl %ebx, 0x14(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf15f92e_0015fa27\n"
        "movl 0x18(%ebp), %eax\n" /* line 149 | ping */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* info */
        "movl %edx, 4(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_SetServerInfo\n"
        "addl $1, -0x50(%ebp)\n" /* line 145 */
        "addl $0x88, -0x64(%ebp)\n"
        "addl $0x88, -0x58(%ebp)\n"
        "cmpl $0x80, -0x50(%ebp)\n"
        "jne .Lf15f92e_0015fa42\n"
        /* } scope */
        ".Lf15f92e_0015fabc:\n"
        "addl $0x7c, %esp\n" /* line 153 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15f92e_0015fac4:\n"
        "movl $0, -0x5c(%ebp)\n" /* line 113 | low */
        "jmp .Lf15f92e_0015fae0\n"
        ".Lf15f92e_0015facd:\n"
        "jle .Lf15f92e_0015fb27\n" /* line 124 */
        "addl $1, %ebx\n" /* line 126 */
        "movl %ebx, -0x5c(%ebp)\n" /* low */
        "cmpl %esi, -0x5c(%ebp)\n" /* line 113 | high, low */
        "jge .Lf15f92e_0015fb1c\n"
        ".Lf15f92e_0015fada:\n"
        "movl imp_cls, %ecx\n"
        ".Lf15f92e_0015fae0:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 115 | low */
        "addl %esi, %edx\n" /* high */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %ebx\n"
        "sarl $1, %ebx\n"
        "movl %ebx, %edi\n" /* i */
        "movl %ebx, %eax\n" /* line 116 */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %ebx, 8), %eax\n"
        "leal 4(%eax, %ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 8(%ebp), %edx\n" /* from */
        "movl %edx, (%esp)\n"
        "calll NET_CompareAdrSigned\n"
        "cmpl $0, %eax\n" /* line 118 */
        "jge .Lf15f92e_0015facd\n"
        "movl %ebx, %esi\n" /* line 136 | high */
        "cmpl %esi, -0x5c(%ebp)\n" /* line 113 | high, low */
        "jl .Lf15f92e_0015fada\n"
        ".Lf15f92e_0015fb1c:\n"
        "movl imp_cls, %ecx\n"
        "jmp .Lf15f92e_0015fa10\n"
        ".Lf15f92e_0015fb27:\n"
        "subl $1, %edi\n" /* line 130 | i */
        "js .Lf15f92e_0015fb54\n"
        "movl %edi, %eax\n" /* i */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %edi, 8), %eax\n"
        "addl imp_cls, %eax\n"
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 8(%ebp), %eax\n" /* from */
        "movl %eax, (%esp)\n"
        "calll NET_CompareAdrSigned\n"
        "testl %eax, %eax\n"
        "je .Lf15f92e_0015fb27\n"
        ".Lf15f92e_0015fb54:\n"
        "leal 1(%edi), %esi\n" /* line 134 | i, high */
        "movl imp_cls, %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl %esi, %eax\n" /* high */
        "shll $7, %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0x4544(%eax, %edx), %edi\n" /* i */
        "movl %edi, %ebx\n" /* i */
        ".Lf15f92e_0015fb71:\n"
        "movl 0x18(%ebp), %eax\n" /* line 138 | ping */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* info */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_SetServerInfo\n"
        "addl $1, %esi\n" /* line 139 | high */
        "addl $0x88, %ebx\n"
        "addl $0x88, %edi\n" /* i */
        "movl -0x60(%ebp), %eax\n" /* line 136 */
        "cmpl 0x4540(%eax), %esi\n" /* high */
        "jge .Lf15f92e_0015fb1c\n"
        "movl %edi, 4(%esp)\n" /* i */
        "leal 8(%ebp), %edx\n" /* from */
        "movl %edx, (%esp)\n"
        "calll NET_CompareAdrSigned\n"
        "testl %eax, %eax\n"
        "je .Lf15f92e_0015fb71\n"
        "jmp .Lf15f92e_0015fb1c\n"
    );
}

/* line 192 */
__attribute__((naked))
int CL_ServerInfoPacket(netadr_t from, msg_t *msg, int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 192 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x49c, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x47a(%ebp)\n"
        "movzbl 0xf(%ebp), %edx\n"
        "movb %dl, -0x47b(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x47c(%ebp)\n"
        "movzbl 0xd(%ebp), %edx\n"
        "movb %dl, -0x47d(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x47e(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* from */
        "movl %edx, -0x484(%ebp)\n"
        /* { scope 1 */
        "movl 0x14(%ebp), %edi\n" /* line 201 | msg */
        "movl %edi, (%esp)\n"
        "calll MSG_ReadString\n"
        "movl %eax, -0x488(%ebp)\n" /* infoString */
        "movl $str_002a7118, 4(%esp)\n" /* line 204 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* prot */
        "movl $str_002aa7ec, (%esp)\n" /* line 205 */
        "calll Dvar_GetString\n"
        "cmpb $0, (%eax)\n" /* line 206 */
        "jne .Lf15fbbe_0016008d\n"
        "movl $0x73, %eax\n"
        ".Lf15fbbe_0015fc4a:\n"
        "cmpl %ebx, %eax\n" /* prot */
        "je .Lf15fbbe_0015fc6f\n"
        "movl -0x488(%ebp), %eax\n" /* line 208 | infoString */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab8d8, (%esp)\n" /* "Different protocol info packet: %s
" */
        "calll Com_DPrintf\n"
        /* } scope */
        ".Lf15fbbe_0015fc64:\n"
        "addl $0x49c, %esp\n" /* line 305 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15fbbe_0015fc6f:\n"
        "xorl %esi, %esi\n" /* line 209 | i */
        "movl imp_cl_pinglist, %ebx\n" /* prot */
        "addl $8, %ebx\n" /* prot */
        "jmp .Lf15fbbe_0015fc8e\n"
        ".Lf15fbbe_0015fc7c:\n"
        "addl $1, %esi\n" /* line 213 | i */
        "addl $0x414, %ebx\n" /* prot */
        "cmpl $0x10, %esi\n" /* i */
        "je .Lf15fbbe_0015fe56\n"
        ".Lf15fbbe_0015fc8e:\n"
        "cmpw $0, (%ebx)\n" /* line 215 | prot */
        "je .Lf15fbbe_0015fc7c\n"
        "movl 8(%ebx), %ecx\n" /* prot */
        "testl %ecx, %ecx\n"
        "jne .Lf15fbbe_0015fc7c\n"
        "movl -8(%ebx), %ecx\n" /* prot */
        "movl %ecx, -0x6c(%ebp)\n"
        "movl -4(%ebx), %edx\n" /* prot */
        "movl %edx, -0x68(%ebp)\n"
        "movl (%ebx), %edi\n" /* prot */
        "movl %edi, 0x14(%esp)\n"
        "movl %edi, -0x64(%ebp)\n"
        "movzwl -0x47a(%ebp), %eax\n"
        "movw %ax, -0x58(%ebp)\n"
        "movzbl -0x47b(%ebp), %eax\n"
        "movb %al, -0x59(%ebp)\n"
        "movzbl -0x47c(%ebp), %eax\n"
        "movb %al, -0x5a(%ebp)\n"
        "movzbl -0x47d(%ebp), %eax\n"
        "movb %al, -0x5b(%ebp)\n"
        "movzbl -0x47e(%ebp), %eax\n"
        "movb %al, -0x5c(%ebp)\n"
        "movl -0x484(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf15fbbe_0015fc7c\n"
        "movl imp_cl_pinglist, %edi\n" /* line 218 */
        "movl %esi, %ebx\n" /* i, prot */
        "shll $6, %ebx\n" /* prot */
        "addl %esi, %ebx\n" /* i, prot */
        "leal (%esi, %ebx, 4), %ebx\n" /* i, prot */
        "shll $2, %ebx\n" /* prot */
        "leal (%ebx, %edi), %esi\n" /* prot, i */
        "movl 0xc(%esi), %edx\n" /* i */
        "subl %edx, 0x18(%ebp)\n" /* time */
        "movl 0x18(%ebp), %eax\n" /* time */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* i */
        "movzwl -0x47a(%ebp), %eax\n" /* line 219 */
        "movw %ax, -0x4c(%ebp)\n"
        "movzbl -0x47b(%ebp), %edx\n"
        "movb %dl, -0x4d(%ebp)\n"
        "movzbl -0x47c(%ebp), %eax\n"
        "movb %al, -0x4e(%ebp)\n"
        "movzbl -0x47d(%ebp), %edx\n"
        "movb %dl, -0x4f(%ebp)\n"
        "movzbl -0x47e(%ebp), %eax\n"
        "movb %al, -0x50(%ebp)\n"
        "movl -0x484(%ebp), %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl %edx, (%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab8fc, (%esp)\n" /* "ping time %dms from %s
" */
        "calll Com_DPrintf\n"
        "leal 0x14(%ebx, %edi), %ebx\n" /* line 222 | prot */
        "movl $0x400, 8(%esp)\n"
        "movl -0x488(%ebp), %edi\n" /* infoString */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* prot */
        "calll I_strncpyz\n"
        "movl -0x484(%ebp), %eax\n" /* line 226 */
        "subl $3, %eax\n"
        "cmpl $1, %eax\n"
        "setbe %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n" /* line 247 */
        "movl $str_00215a64, (%esp)\n" /* "%d" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002ab8c0, 4(%esp)\n" /* "nettype" */
        "movl %ebx, (%esp)\n" /* prot */
        "calll Info_SetValueForKey\n"
        "movl 0x10(%esi), %eax\n" /* line 248 | i */
        "movzwl -0x47a(%ebp), %edx\n"
        "movw %dx, -0x40(%ebp)\n"
        "movzbl -0x47b(%ebp), %edx\n"
        "movb %dl, -0x41(%ebp)\n"
        "movzbl -0x47c(%ebp), %edx\n"
        "movb %dl, -0x42(%ebp)\n"
        "movzbl -0x47d(%ebp), %edx\n"
        "movb %dl, -0x43(%ebp)\n"
        "movzbl -0x47e(%ebp), %edx\n"
        "movb %dl, -0x44(%ebp)\n"
        "movl -0x484(%ebp), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_SetServerInfoByAddress\n"
        "jmp .Lf15fbbe_0015fc64\n"
        ".Lf15fbbe_0015fe56:\n"
        "movl imp_cls, %eax\n" /* line 255 */
        "movl str_002a0938+272(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf15fbbe_0015fc64\n"
        "xorl %esi, %esi\n" /* line 257 | i */
        "movl %eax, %ebx\n" /* prot */
        "jmp .Lf15fbbe_0015ff08\n"
        ".Lf15fbbe_0015fe72:\n"
        "movl 0x13c(%ebx), %ecx\n" /* line 269 | prot */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0x140(%ebx), %edx\n" /* prot */
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x144(%ebx), %edi\n" /* prot */
        "movl %edi, 0x14(%esp)\n"
        "movl %edi, -0x34(%ebp)\n"
        "movzwl -0x47a(%ebp), %eax\n"
        "movw %ax, -0x28(%ebp)\n"
        "movzbl -0x47b(%ebp), %eax\n"
        "movb %al, -0x29(%ebp)\n"
        "movzbl -0x47c(%ebp), %eax\n"
        "movb %al, -0x2a(%ebp)\n"
        "movzbl -0x47d(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl -0x47e(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movl -0x484(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf15fbbe_0015fc64\n"
        "addl $1, %esi\n" /* line 260 | i */
        "addl $0x88, %ebx\n" /* prot */
        "cmpl $0x80, %esi\n" /* i */
        "je .Lf15fbbe_0016009a\n"
        ".Lf15fbbe_0015ff08:\n"
        "cmpw $0, 0x144(%ebx)\n" /* line 263 | prot */
        "jne .Lf15fbbe_0015fe72\n"
        "movl imp_cls, %edx\n" /* line 282 */
        "leal 1(%esi), %eax\n" /* i */
        "movl %eax, 0x138(%edx)\n"
        "movl %esi, %eax\n" /* line 283 | i */
        "shll $7, %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "addl %edx, %eax\n"
        "leal 0x130(%eax), %ecx\n"
        "movzwl -0x47a(%ebp), %edx\n"
        "movw %dx, 0x14(%ecx)\n"
        "movzbl -0x47b(%ebp), %edx\n"
        "movb %dl, 0x143(%eax)\n"
        "movzbl -0x47c(%ebp), %edx\n"
        "movb %dl, 0x142(%eax)\n"
        "movzbl -0x47d(%ebp), %edx\n"
        "movb %dl, 0x141(%eax)\n"
        "movzbl -0x47e(%ebp), %edx\n"
        "movb %dl, 0x10(%ecx)\n"
        "movl -0x484(%ebp), %edx\n"
        "movl %edx, 0x13c(%eax)\n"
        "movb $0, 0x19(%ecx)\n" /* line 284 */
        "movb $0, 0x15c(%eax)\n" /* line 285 */
        "movb $0, 0x17c(%eax)\n" /* line 286 */
        "movb $0, 0x1a(%ecx)\n" /* line 287 */
        "leal 0x140(%eax), %edx\n" /* line 288 */
        "movw $0, 0x18(%edx)\n"
        "movw $0, 0x16(%edx)\n" /* line 289 */
        "movw $0xffff, 0x1a(%edx)\n" /* line 290 */
        "movb $0, 0x19c(%eax)\n" /* line 291 */
        "movb $0, 0x1b4(%eax)\n" /* line 292 */
        "movzbl -0x484(%ebp), %eax\n" /* line 293 */
        "movb %al, 0x18(%ecx)\n"
        "movb $0, 0xc(%edx)\n" /* line 294 */
        "movl 0x14(%ebp), %edx\n" /* line 296 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadString\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x46c(%ebp), %ebx\n" /* info, prot */
        "movl %ebx, (%esp)\n" /* prot */
        "calll I_strncpyz\n"
        "cmpb $0, -0x46c(%ebp)\n" /* line 297 | info */
        "je .Lf15fbbe_0015fc64\n"
        "movl $0xffffffff, %edx\n" /* line 299 */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %ebx, %edi\n" /* prot */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "cmpb $0xa, -0x46e(%ecx, %ebp)\n"
        "je .Lf15fbbe_00160022\n"
        "movl %edx, %ecx\n" /* line 301 */
        "movl %ebx, %edi\n" /* prot */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movw $0xa, -1(%ecx, %ebx)\n"
        ".Lf15fbbe_00160022:\n"
        "movzwl -0x47a(%ebp), %edi\n" /* line 303 */
        "movw %di, -0x1c(%ebp)\n"
        "movzbl -0x47b(%ebp), %eax\n"
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x47c(%ebp), %edx\n"
        "movb %dl, -0x1e(%ebp)\n"
        "movzbl -0x47d(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x47e(%ebp), %edx\n"
        "movb %dl, -0x20(%ebp)\n"
        "movl -0x484(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, (%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %ebx, 8(%esp)\n" /* prot */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab944, (%esp)\n" /* "%s: %s" */
        "calll Com_Printf\n"
        "jmp .Lf15fbbe_0015fc64\n"
        ".Lf15fbbe_0016008d:\n"
        "movl %eax, (%esp)\n" /* line 206 */
        "calll atoi\n"
        "jmp .Lf15fbbe_0015fc4a\n"
        ".Lf15fbbe_0016009a:\n"
        "movl $str_002ab914, (%esp)\n" /* line 277 */
        "calll Com_DPrintf\n"
        "jmp .Lf15fbbe_0015fc64\n"
    );
}

/* line 390 */
__attribute__((naked))
qboolean CL_CDKeyValidate(const char *key, const char *checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 390 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* key */
        "movl 0xc(%ebp), %esi\n" /* checksum */
        "xorl %edx, %edx\n"
        "movl $1, %ecx\n"
        /* { scope 1 */
        ".Lf1600ac_001600c1:\n"
        "movsbl -1(%ecx, %ebx), %eax\n" /* line 405 */
        "xorl %eax, %edx\n"
        "movl $8, %eax\n"
        "jmp .Lf1600ac_001600dc\n"
        ".Lf1600ac_001600cf:\n"
        "shrl $1, %edx\n" /* line 410 */
        "xorl $0xa001, %edx\n"
        "subl $1, %eax\n" /* line 407 */
        "je .Lf1600ac_001600e8\n"
        ".Lf1600ac_001600dc:\n"
        "testb $1, %dl\n" /* line 409 */
        "jne .Lf1600ac_001600cf\n"
        "shrl $1, %edx\n" /* line 412 */
        "subl $1, %eax\n" /* line 407 */
        "jne .Lf1600ac_001600dc\n"
        ".Lf1600ac_001600e8:\n"
        "addl $1, %ecx\n"
        "cmpl $0x11, %ecx\n" /* line 403 */
        "jne .Lf1600ac_001600c1\n"
        "movl %edx, 8(%esp)\n" /* line 416 */
        "movl $str_00228f18, 4(%esp)\n" /* "%04x" */
        "leal -0xd(%ebp), %ebx\n" /* chs, key */
        "movl %ebx, (%esp)\n" /* key */
        "calll sprintf\n"
        "testl %esi, %esi\n" /* line 418 | checksum */
        "je .Lf1600ac_0016012c\n"
        "movl $4, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* checksum */
        "movl %ebx, (%esp)\n" /* key */
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf1600ac_0016012c\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 425 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1600ac_0016012c:\n"
        "movl $1, %eax\n" /* line 418 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 425 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 432 */
int CL_SortGlobalServers(void)
{
    byte *base = *(byte **)imp_cls;
    int count = *(int *)(base + 0x4540);
    qsort(base + 0x4544, count, 0x88, (int (*)(const void *, const void *))CL_CompareAdrSigned);
    return 0;
}

/* line 677 */
int CL_RconInit(void)
{
    *(byte *)&rconGlob = 0;
    *(int *)((char *)&rconGlob + 24) = 1;
}

/* line 750 */
__attribute__((naked))
int CL_Rcon_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 750 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 759 */
        "subl $1, %eax\n"
        "jle .Lf160184_00160210\n"
        "movl $1, (%esp)\n" /* line 765 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* cmd */
        "movl $str_002ab970, 4(%esp)\n" /* line 766 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf160184_001601e1\n"
        "calll Cmd_Argc\n" /* line 689 */
        "cmpl $3, %eax\n"
        "je .Lf160184_001603e2\n"
        "movl $str_002ab978, (%esp)\n" /* line 691 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf160184_001601d6:\n"
        "addl $0x45c, %esp\n" /* line 827 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf160184_001601e1:\n"
        "movl $str_002ab9c8, 4(%esp)\n" /* line 771 */
        "movl %ebx, (%esp)\n" /* cmd */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf160184_00160235\n"
        "cmpb $0, rconGlob\n" /* line 709 */
        "je .Lf160184_00160227\n"
        "movb $0, rconGlob\n" /* line 715 */
        /* } scope */
        "addl $0x45c, %esp\n" /* line 827 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf160184_00160210:\n"
        "movl $str_002ab94c, (%esp)\n" /* line 761 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x45c, %esp\n" /* line 827 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf160184_00160227:\n"
        "movl $str_002ab9d0, (%esp)\n" /* line 711 */
        "calll Com_Printf\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_00160235:\n"
        "movl $str_002ab9e0, 4(%esp)\n" /* line 776 */
        "movl %ebx, (%esp)\n" /* cmd */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf160184_00160449\n"
        "cmpb $0, rconGlob\n" /* line 782 */
        "je .Lf160184_00160438\n"
        "movb $0xff, -0x424(%ebp)\n" /* line 788 | message */
        "movb $0xff, -0x423(%ebp)\n" /* line 789 */
        "movb $0xff, -0x422(%ebp)\n" /* line 790 */
        "movb $0xff, -0x421(%ebp)\n" /* line 791 */
        "movb $0, -0x420(%ebp)\n" /* line 792 */
        "movl $0, 0x10(%esp)\n" /* line 795 */
        "movl $0x400, 0xc(%esp)\n"
        "movl $4, 8(%esp)\n"
        "leal -0x424(%ebp), %esi\n" /* message */
        "movl %esi, 4(%esp)\n"
        "movl $str_002aba5c, (%esp)\n" /* "rcon " */
        "calll Com_AddToString\n"
        "movl $0, 0x10(%esp)\n" /* line 796 */
        "movl $0x400, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $rconGlob, (%esp)\n"
        "calll Com_AddToString\n"
        "movl %eax, %ebx\n" /* cmd */
        "movl $1, %edi\n" /* i */
        "jmp .Lf160184_0016032b\n"
        ".Lf160184_001602d8:\n"
        "movl $0, 0x10(%esp)\n" /* line 800 */
        "movl $0x400, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* cmd */
        "movl %esi, 4(%esp)\n"
        "movl $str_00217914, (%esp)\n" /* " " */
        "calll Com_AddToString\n"
        "movl %eax, %ebx\n" /* cmd */
        "movl %edi, (%esp)\n" /* line 801 | i */
        "calll Cmd_Argv\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0x400, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* cmd */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_AddToString\n"
        "movl %eax, %ebx\n" /* cmd */
        "addl $1, %edi\n" /* line 798 | i */
        ".Lf160184_0016032b:\n"
        "calll Cmd_Argc\n"
        "cmpl %eax, %edi\n" /* i */
        "jl .Lf160184_001602d8\n"
        "cmpl $0x400, %ebx\n" /* line 803 | cmd */
        "je .Lf160184_001604e3\n"
        "movb $0, -0x424(%ebp, %ebx)\n" /* line 808 */
        "movl imp_clc, %eax\n" /* line 810 */
        "movl (%eax), %eax\n"
        "cmpl $4, (%eax)\n"
        "jle .Lf160184_00160464\n"
        "movzwl 0x407e0(%eax), %edx\n" /* line 812 */
        "movw %dx, -0x42a(%ebp)\n"
        "movzbl 0x407df(%eax), %edi\n" /* i */
        "movzbl 0x407de(%eax), %ebx\n" /* cmd */
        "movzbl 0x407dd(%eax), %ecx\n"
        "movzbl 0x407dc(%eax), %edx\n"
        "movb %dl, -0x439(%ebp)\n"
        "movl 0x407d8(%eax), %eax\n"
        ".Lf160184_0016038e:\n"
        "movzwl -0x42a(%ebp), %edx\n" /* line 826 */
        "movw %dx, -0x1c(%ebp)\n"
        "movl %edi, %edx\n" /* i */
        "movb %dl, -0x1d(%ebp)\n"
        "movb %bl, -0x1e(%ebp)\n" /* cmd */
        "movb %cl, -0x1f(%ebp)\n"
        "movzbl -0x439(%ebp), %edx\n"
        "movb %dl, -0x20(%ebp)\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll CL_Netchan_SendOOBPacket\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_001603e2:\n"
        "movl $2, (%esp)\n" /* line 695 */
        "calll Cmd_Argv\n"
        "movl %eax, %edx\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n" /* i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "cmpl $0x17, %eax\n" /* line 697 */
        "jbe .Lf160184_0016041f\n"
        "movl $0x18, 4(%esp)\n" /* line 699 */
        "movl $str_002ab998, (%esp)\n" /* "rcon password must be %i characters or less
" */
        "calll Com_Printf\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_0016041f:\n"
        "movl %ecx, 8(%esp)\n" /* line 703 */
        "movl %edx, 4(%esp)\n"
        "movl $rconGlob, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_00160438:\n"
        "movl $str_002aba18, (%esp)\n" /* line 784 */
        "calll Com_Printf\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_00160449:\n"
        "calll Cmd_Argc\n" /* line 723 */
        "cmpl $3, %eax\n"
        "je .Lf160184_001604a7\n"
        "movl $str_002ab9e8, (%esp)\n" /* line 725 */
        "calll Com_Printf\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_00160464:\n"
        "movl rconGlob+24, %eax\n" /* line 814 */
        "cmpl $1, %eax\n"
        "je .Lf160184_0016050d\n"
        "movzwl rconGlob+32, %edx\n" /* line 816 */
        "movw %dx, -0x42a(%ebp)\n"
        "movzbl rconGlob+31, %edi\n" /* i */
        "movzbl rconGlob+30, %ebx\n" /* cmd */
        "movzbl rconGlob+29, %ecx\n"
        "movzbl rconGlob+28, %edx\n"
        "movb %dl, -0x439(%ebp)\n"
        "jmp .Lf160184_0016038e\n"
        ".Lf160184_001604a7:\n"
        "movl $2, (%esp)\n" /* line 729 */
        "calll Cmd_Argv\n"
        "movl $rconGlob+24, 4(%esp)\n" /* line 730 */
        "movl %eax, (%esp)\n"
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf160184_001604fc\n"
        "cmpw $0, rconGlob+32\n" /* line 737 */
        "jne .Lf160184_001601d6\n"
        "movw $0x2071, rconGlob+32\n" /* line 738 */
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_001604e3:\n"
        "movl $0x3ff, 4(%esp)\n" /* line 805 */
        "movl $str_002aba64, (%esp)\n" /* "rcon commands are limited to %i characters
" */
        "calll Com_Printf\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_001604fc:\n"
        "movl $str_002aba04, (%esp)\n" /* line 732 */
        "calll Com_Printf\n"
        "jmp .Lf160184_001601d6\n"
        ".Lf160184_0016050d:\n"
        "movl $str_002aba90, (%esp)\n" /* line 820 */
        "calll Com_Printf\n"
        "movl $str_002abacc, (%esp)\n" /* line 821 */
        "calll Com_Printf\n"
        "movl $str_002abaf0, (%esp)\n" /* line 822 */
        "calll Com_Printf\n"
        "jmp .Lf160184_001601d6\n"
    );
}

/* line 1095 */
__attribute__((naked))
int CL_ServerStatusResponse(netadr_t from, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1095 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x43e(%ebp)\n"
        "movzbl 0xf(%ebp), %ebx\n"
        "movb %bl, -0x43f(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x440(%ebp)\n"
        "movzbl 0xd(%ebp), %ebx\n"
        "movb %bl, -0x441(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x442(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* from */
        "movl %ebx, -0x448(%ebp)\n"
        "movl $0, -0x45c(%ebp)\n"
        "movl $cl_serverStatusList, %edi\n"
        "movl $cl_serverStatusList, %esi\n"
        /* { scope 1 */
        ".Lf160536_00160591:\n"
        "movl 0x2000(%edi), %ecx\n" /* line 1106 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl 0x2004(%edi), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x2008(%edi), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movzwl -0x43e(%ebp), %ebx\n"
        "movw %bx, -0x24(%ebp)\n"
        "movzbl -0x43f(%ebp), %ebx\n"
        "movb %bl, -0x25(%ebp)\n"
        "movzbl -0x440(%ebp), %ebx\n"
        "movb %bl, -0x26(%ebp)\n"
        "movzbl -0x441(%ebp), %ebx\n"
        "movb %bl, -0x27(%ebp)\n"
        "movzbl -0x442(%ebp), %ebx\n"
        "movb %bl, -0x28(%ebp)\n"
        "movl -0x448(%ebp), %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf160536_00160639\n"
        "addl $1, -0x45c(%ebp)\n" /* line 1104 */
        "addl $0x2020, %esi\n"
        "addl $0x2020, %edi\n"
        "cmpl $0x10, -0x45c(%ebp)\n"
        "jne .Lf160536_00160591\n"
        /* } scope */
        ".Lf160536_0016062e:\n"
        "addl $0x47c, %esp\n" /* line 1196 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf160536_00160639:\n"
        "testl %esi, %esi\n" /* line 1113 */
        "je .Lf160536_0016062e\n"
        "movl 0x14(%ebp), %eax\n" /* line 1118 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadStringLine\n"
        "movl %eax, %edi\n"
        "movl %eax, 0xc(%esp)\n" /* line 1121 */
        "movl $str_00216058, 8(%esp)\n" /* "%s" */
        "movl $0x2000, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x2018(%esi), %eax\n" /* line 1123 */
        "testl %eax, %eax\n"
        "jne .Lf160536_0016077c\n"
        ".Lf160536_00160674:\n"
        "cld\n" /* line 1158 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl $str_00222630, 8(%esp)\n" /* line 1159 */
        "movl $0x2000, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x2018(%esi), %eax\n" /* line 1161 */
        "testl %eax, %eax\n"
        "jne .Lf160536_0016091f\n"
        ".Lf160536_001606b1:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1166 | msg */
        "movl %ebx, (%esp)\n"
        "calll MSG_ReadStringLine\n"
        "movl %eax, %ebx\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf160536_0016082b\n"
        ".Lf160536_001606c7:\n"
        "cld\n" /* line 1186 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl $str_00222630, 8(%esp)\n" /* line 1187 */
        "movl $0x2000, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "calll Sys_Milliseconds\n" /* line 1189 */
        "movl %eax, 0x200c(%esi)\n"
        "movzwl -0x43e(%ebp), %ebx\n" /* line 1190 */
        "movw %bx, 0x2008(%esi)\n"
        "movzbl -0x43f(%ebp), %eax\n"
        "movb %al, 0x2007(%esi)\n"
        "movzbl -0x440(%ebp), %ebx\n"
        "movb %bl, 0x2006(%esi)\n"
        "movzbl -0x441(%ebp), %eax\n"
        "movb %al, 0x2005(%esi)\n"
        "movzbl -0x442(%ebp), %ebx\n"
        "movb %bl, 0x2004(%esi)\n"
        "movl -0x448(%ebp), %eax\n"
        "movl %eax, 0x2000(%esi)\n"
        "movl $0, 0x2014(%esi)\n" /* line 1191 */
        "movl 0x2018(%esi), %edi\n" /* line 1192 */
        "testl %edi, %edi\n"
        "je .Lf160536_0016062e\n"
        "movl $1, 0x201c(%esi)\n" /* line 1194 */
        /* } scope */
        "addl $0x47c, %esp\n" /* line 1196 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf160536_0016077c:\n"
        "movl $str_002abb28, (%esp)\n" /* line 1125 */
        "calll Com_Printf\n"
        "movzbl (%edi), %eax\n"
        ".Lf160536_0016078b:\n"
        "testb %al, %al\n" /* line 1127 */
        "je .Lf160536_00160674\n"
        "movl $0, -0x43c(%ebp)\n"
        "leal -0x438(%ebp), %ebx\n" /* info */
        "cmpb $0x5c, %al\n" /* line 1131 */
        "je .Lf160536_00160809\n"
        ".Lf160536_001607a7:\n"
        "xorl %edx, %edx\n" /* line 1132 */
        "jmp .Lf160536_001607ae\n"
        ".Lf160536_001607ab:\n"
        "movzbl (%edi), %eax\n"
        ".Lf160536_001607ae:\n"
        "testb %al, %al\n" /* line 1134 */
        "je .Lf160536_001607c8\n"
        "movb %al, (%edx, %ebx)\n" /* line 1136 */
        "addl $1, %edx\n"
        "cmpl $0x3ff, %edx\n" /* line 1137 */
        "je .Lf160536_001607c8\n"
        "addl $1, %edi\n" /* line 1139 */
        "cmpb $0x5c, (%edi)\n" /* line 1140 */
        "jne .Lf160536_001607ab\n"
        ".Lf160536_001607c8:\n"
        "movb $0, -0x438(%ebp, %edx)\n" /* line 1145 */
        "movl -0x43c(%ebp), %eax\n" /* line 1146 */
        "testl %eax, %eax\n"
        "je .Lf160536_00160819\n"
        "movl %ebx, 4(%esp)\n" /* line 1148 */
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf160536_001607ea:\n"
        "addl $1, -0x43c(%ebp)\n" /* line 1129 */
        "cmpl $2, -0x43c(%ebp)\n"
        "je .Lf160536_00160811\n"
        "movzbl (%edi), %eax\n"
        "testb %al, %al\n"
        "je .Lf160536_00160674\n"
        "cmpb $0x5c, %al\n" /* line 1131 */
        "jne .Lf160536_001607a7\n"
        ".Lf160536_00160809:\n"
        "addl $1, %edi\n" /* line 1132 */
        "movzbl (%edi), %eax\n"
        "jmp .Lf160536_001607a7\n"
        ".Lf160536_00160811:\n"
        "movzbl (%edi), %eax\n"
        "jmp .Lf160536_0016078b\n"
        ".Lf160536_00160819:\n"
        "movl %ebx, 4(%esp)\n" /* line 1152 */
        "movl $str_002abb3c, (%esp)\n" /* "%-24s" */
        "calll Com_Printf\n"
        "jmp .Lf160536_001607ea\n"
        ".Lf160536_0016082b:\n"
        "movl $0, -0x44c(%ebp)\n" /* line 1166 | i */
        "jmp .Lf160536_00160854\n"
        ".Lf160536_00160837:\n"
        "movl 0x14(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadStringLine\n"
        "movl %eax, %ebx\n"
        "addl $1, -0x44c(%ebp)\n" /* i */
        "cmpb $0, (%eax)\n"
        "je .Lf160536_001606c7\n"
        ".Lf160536_00160854:\n"
        "cld\n" /* line 1169 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1170 */
        "movl $str_002a6fb8, 8(%esp)\n" /* "\%s" */
        "movl $0x2000, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x2018(%esi), %eax\n" /* line 1172 */
        "testl %eax, %eax\n"
        "je .Lf160536_00160837\n"
        "movl $0, -0x20(%ebp)\n" /* line 1174 | ping */
        "movl $0, -0x1c(%ebp)\n" /* score */
        "leal -0x20(%ebp), %eax\n" /* line 1175 | ping */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* score */
        "movl %eax, 8(%esp)\n"
        "movl $str_002abb6c, 4(%esp)\n" /* "%d %d" */
        "movl %ebx, (%esp)\n"
        "calll sscanf\n"
        "movl $0x20, 4(%esp)\n" /* line 1176 */
        "movl %ebx, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 1177 */
        "je .Lf160536_00160918\n"
        "addl $1, %eax\n" /* line 1178 */
        "movl $0x20, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 1179 */
        "je .Lf160536_00160918\n"
        "addl $1, %eax\n" /* line 1180 */
        ".Lf160536_001608eb:\n"
        "movl %eax, 0x10(%esp)\n" /* line 1183 */
        "movl -0x20(%ebp), %eax\n" /* ping */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* score */
        "movl %eax, 8(%esp)\n"
        "movl -0x44c(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002abb7c, (%esp)\n" /* "%-2d   %-3d    %-3d   %s
" */
        "calll Com_Printf\n"
        "jmp .Lf160536_00160837\n"
        ".Lf160536_00160918:\n"
        "movl $str_002abb74, %eax\n" /* line 1180 */
        "jmp .Lf160536_001608eb\n"
        ".Lf160536_0016091f:\n"
        "movl $str_002abb44, (%esp)\n" /* line 1163 */
        "calll Com_Printf\n"
        "movl $str_002abb50, (%esp)\n" /* line 1164 */
        "calll Com_Printf\n"
        "jmp .Lf160536_001606b1\n"
    );
}

/* line 1328 */
int CL_ResetPlayerMuting(int clientIndex)
{
    s_playerMute[clientIndex] = 0;
}

/* line 1335 */
__attribute__((naked))
int CL_MutePlayer(int clientIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1335 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* clientIndex */
        "cmpb $0, s_playerMute(%edx)\n" /* line 1338 */
        "sete %al\n"
        "movb %al, s_playerMute(%edx)\n"
        "testb %al, %al\n" /* line 1339 */
        "je .Lf16094c_0016098b\n"
        "movl %edx, 4(%esp)\n" /* line 1340 */
        "movl $str_002abb98, (%esp)\n" /* "muteplayer %i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "leave\n" /* line 1343 */
        "retl\n"
        ".Lf16094c_0016098b:\n"
        "movl %edx, 4(%esp)\n" /* line 1342 */
        "movl $str_002abba8, (%esp)\n" /* "unmuteplayer %i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "leave\n" /* line 1343 */
        "retl\n"
    );
}

/* line 1346 */
Bool CL_IsPlayerMuted(int clientIndex)
{
    return s_playerMute[clientIndex];
}

/* line 1353 */
int CL_ClearMutedList(void)
{
    memset(s_playerMute, 0, 0x40);
}

/* line 622 */
__attribute__((naked))
int CL_GlobalServers_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 622 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 631 */
        "cmpl $2, %eax\n"
        "jle .Lf1609e2_00160b68\n"
        "movl imp_cls, %ebx\n" /* line 637 | buffptr */
        "movl 0x4540(%ebx), %eax\n" /* buffptr */
        "testl %eax, %eax\n"
        "jle .Lf1609e2_00160a3b\n"
        "xorl %edi, %edi\n" /* i */
        ".Lf1609e2_00160a0e:\n"
        "movl %edi, %eax\n" /* line 639 | i */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %edi, 8), %edx\n"
        "leal 4(%edx, %ebx), %edx\n"
        "movl $0xffffffff, %eax\n" /* line 642 */
        "movzbl 0x19(%edx), %ecx\n"
        "addb $1, %cl\n"
        "cmovnel %ecx, %eax\n"
        "movb %al, 0x19(%edx)\n"
        "addl $1, %edi\n" /* line 637 | i */
        "cmpl 0x4540(%ebx), %edi\n" /* buffptr, i */
        "jl .Lf1609e2_00160a0e\n"
        ".Lf1609e2_00160a3b:\n"
        "movl $str_002abbf4, (%esp)\n" /* line 645 */
        "calll Com_Printf\n"
        "leal -0x30(%ebp), %eax\n" /* line 649 | to */
        "movl %eax, 4(%esp)\n"
        "movl $str_002a9298, (%esp)\n" /* "cod2master.activision.com" */
        "calll NET_StringToAdr\n"
        "movl imp_cls, %eax\n" /* line 650 */
        "movl $1, 0x453c(%eax)\n"
        "movl $1, str_002a0938+272(%eax)\n" /* line 651 */
        "movl $4, -0x30(%ebp)\n" /* line 653 | to */
        "movw $0xe650, -0x28(%ebp)\n" /* line 654 */
        "movl $2, (%esp)\n" /* line 656 */
        "calll Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002abc1c, 4(%esp)\n" /* "getservers %s" */
        "leal -0x430(%ebp), %eax\n" /* command */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "cld\n" /* line 659 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x430(%ebp), %edi\n" /* command, i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "leal -0x431(%ecx, %ebp), %ebx\n" /* buffptr */
        "calll Cmd_Argc\n" /* line 660 */
        "movl %eax, %esi\n" /* count */
        "cmpl $3, %eax\n" /* line 661 */
        "jg .Lf1609e2_00160b28\n"
        "movl $str_00216d6c, (%esp)\n" /* line 665 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "jne .Lf1609e2_00160b1a\n"
        ".Lf1609e2_00160adb:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 670 | to */
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x430(%ebp), %ebx\n" /* command, buffptr */
        "movl %ebx, 0x10(%esp)\n" /* buffptr */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        "addl $0x44c, %esp\n" /* line 671 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1609e2_00160b1a:\n"
        "movl $0x6d656420, (%ebx)\n" /* line 667 | buffptr */
        "movw $0x6f, 4(%ebx)\n" /* buffptr */
        "jmp .Lf1609e2_00160adb\n"
        ".Lf1609e2_00160b28:\n"
        "movl $3, %edi\n" /* line 661 | i */
        ".Lf1609e2_00160b2d:\n"
        "movl %edi, (%esp)\n" /* line 662 | i */
        "calll Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002abc2c, 4(%esp)\n" /* " %s" */
        "movl %ebx, (%esp)\n" /* buffptr */
        "calll sprintf\n"
        "addl %eax, %ebx\n" /* buffptr */
        "addl $1, %edi\n" /* line 661 | i */
        "cmpl %edi, %esi\n" /* i, count */
        "jne .Lf1609e2_00160b2d\n"
        "movl $str_00216d6c, (%esp)\n" /* line 665 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "je .Lf1609e2_00160adb\n"
        "jmp .Lf1609e2_00160b1a\n"
        ".Lf1609e2_00160b68:\n"
        "movl $str_002abbb8, (%esp)\n" /* line 633 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x44c, %esp\n" /* line 671 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 518 */
__attribute__((naked))
int CL_ServersResponsePacket(netadr_t from, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 518 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x67c, %esp\n"
        "movl 0x14(%ebp), %ebx\n" /* msg */
        /* { scope 1: adr */
        "calll Com_PumpMessageLoop\n" /* line 529 */
        "movl $str_002abc30, (%esp)\n" /* line 531 */
        "calll Com_Printf\n"
        "movl imp_cls, %eax\n" /* line 533 */
        "movl $0, 0x453c(%eax)\n"
        "movl 4(%ebx), %esi\n" /* line 537 | msg, buffptr */
        "movl %esi, %edi\n" /* line 538 | buffptr, buffend */
        "addl 0xc(%ebx), %edi\n" /* msg, buffend */
        "movl $0, -0x63c(%ebp)\n" /* numservers */
        "leal -0x621(%ebp), %eax\n"
        "movl %eax, -0x62c(%ebp)\n"
        "leal 1(%esi), %ebx\n" /* line 539 | buffptr, msg */
        "cmpl %ebx, %edi\n" /* msg, buffend */
        "ja .Lf160b80_00160bde\n"
        "jmp .Lf160b80_00160cdc\n"
        ".Lf160b80_00160bd9:\n"
        "movl %ebx, %esi\n" /* msg, buffptr */
        "addl $1, %ebx\n" /* msg */
        ".Lf160b80_00160bde:\n"
        "cmpb $0x5c, (%esi)\n" /* line 544 | buffptr */
        "je .Lf160b80_00160be7\n"
        "cmpl %ebx, %edi\n" /* line 542 | msg, buffend */
        "ja .Lf160b80_00160bd9\n"
        ".Lf160b80_00160be7:\n"
        "leal -6(%edi), %eax\n" /* line 549 | buffend */
        "cmpl %eax, %ebx\n" /* msg */
        "jae .Lf160b80_00160cdc\n"
        "movzbl 1(%esi), %edx\n" /* line 555 | buffptr */
        "movb %dl, -0x645(%ebp)\n"
        "movl -0x62c(%ebp), %ecx\n"
        "movb %dl, -3(%ecx)\n"
        "movzbl 1(%ebx), %eax\n" /* line 556 | msg */
        "movb %al, -0x646(%ebp)\n"
        "movb %al, -2(%ecx)\n"
        "movzbl 2(%ebx), %edx\n" /* line 557 | msg */
        "movb %dl, -0x647(%ebp)\n"
        "movb %dl, -1(%ecx)\n"
        "movzbl 3(%ebx), %ecx\n" /* line 558 | msg */
        "movl -0x62c(%ebp), %eax\n"
        "movb %cl, (%eax)\n"
        "movzbw 4(%ebx), %ax\n" /* line 561 | msg */
        "shll $8, %eax\n"
        "movl -0x62c(%ebp), %edx\n"
        "movw %ax, 1(%edx)\n"
        "addl $7, %esi\n" /* line 562 | buffptr */
        "movzbw 5(%ebx), %dx\n" /* msg */
        "addl %edx, %eax\n"
        /* { scope 2: low */
        "rolw $8, %ax\n" /* line 46 */
        /* } scope */
        "movzwl %ax, %eax\n" /* line 925 | data */
        "movw %ax, -0x65a(%ebp)\n" /* data */
        "movl -0x62c(%ebp), %edx\n" /* line 563 */
        "movw %ax, 1(%edx)\n"
        "cmpb $0x5c, (%esi)\n" /* line 566 | buffptr */
        "jne .Lf160b80_00160cdc\n"
        "movzwl -0x65a(%ebp), %eax\n" /* line 571 */
        "movl %eax, 0x18(%esp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl -0x647(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x646(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x645(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x63c(%ebp), %ecx\n" /* numservers */
        "movl %ecx, 4(%esp)\n"
        "movl $str_002abc4c, (%esp)\n" /* "server: %d ip: %d.%d.%d.%d:%d
" */
        "calll Com_DPrintf\n"
        "addl $1, -0x63c(%ebp)\n" /* line 573 | numservers */
        "cmpl $0x100, -0x63c(%ebp)\n" /* line 574 | numservers */
        "je .Lf160b80_00160cdc\n"
        "cmpb $0x45, 7(%ebx)\n" /* line 580 | msg */
        "je .Lf160b80_00160ee7\n"
        ".Lf160b80_00160cca:\n"
        "addl $6, -0x62c(%ebp)\n" /* line 582 */
        "leal 1(%esi), %ebx\n" /* line 539 | buffptr, msg */
        "cmpl %ebx, %edi\n" /* msg, buffend */
        "ja .Lf160b80_00160bde\n"
        ".Lf160b80_00160cdc:\n"
        "movl imp_cls, %eax\n" /* line 586 */
        "movl %eax, -0x64c(%ebp)\n"
        "movl 0x4540(%eax), %edx\n"
        "movl %edx, -0x640(%ebp)\n" /* count */
        "movl -0x63c(%ebp), %eax\n" /* line 589 | numservers */
        "testl %eax, %eax\n"
        "jle .Lf160b80_00160f00\n"
        "cmpl $0x4e1f, -0x640(%ebp)\n" /* count */
        "jg .Lf160b80_00160f00\n"
        "movl $0, -0x644(%ebp)\n" /* i */
        "jmp .Lf160b80_00160de5\n"
        ".Lf160b80_00160d20:\n"
        "movl -0x640(%ebp), %eax\n" /* line 603 | count */
        "shll $7, %eax\n"
        "movl -0x640(%ebp), %ecx\n" /* count */
        "leal 0x4540(%eax, %ecx, 8), %edx\n"
        "addl -0x64c(%ebp), %edx\n"
        "leal 4(%edx), %eax\n"
        "addl $1, %ecx\n" /* line 604 */
        "movl %ecx, -0x640(%ebp)\n" /* count */
        "movzwl -0x632(%ebp), %ecx\n" /* line 445 */
        "movw %cx, 8(%eax)\n"
        "movzbl -0x630(%ebp), %ecx\n"
        "movb %cl, 7(%eax)\n"
        "movzbl -0x62f(%ebp), %ecx\n"
        "movb %cl, 6(%eax)\n"
        "movzbl -0x62e(%ebp), %ecx\n"
        "movb %cl, 5(%eax)\n"
        "movzbl -0x62d(%ebp), %ecx\n"
        "movb %cl, 4(%eax)\n"
        "movl $4, 4(%edx)\n"
        "movb $0, 0xd(%eax)\n" /* line 447 */
        "movb $0, 0x20(%eax)\n" /* line 448 */
        "movb $0, 0x40(%eax)\n" /* line 449 */
        "movb $0, 0xe(%eax)\n" /* line 450 */
        "movw $0, 0x1c(%eax)\n" /* line 451 */
        "movw $0, 0x1a(%eax)\n" /* line 452 */
        "movw $0xffff, 0x1e(%eax)\n" /* line 453 */
        "movb $0, 0x60(%eax)\n" /* line 454 */
        "movb $0, 0x78(%eax)\n" /* line 455 */
        "movb $0, 0xc(%eax)\n" /* line 456 */
        "movb $0, 0x10(%eax)\n" /* line 457 */
        "movb $1, 0xf(%eax)\n" /* line 458 */
        "movb $0, 0x19(%eax)\n" /* line 459 */
        ".Lf160b80_00160dbc:\n"
        "addl $1, -0x644(%ebp)\n" /* line 589 | i */
        "movl -0x644(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x63c(%ebp)\n" /* numservers */
        "je .Lf160b80_00160f00\n"
        "cmpl $0x4e1f, -0x640(%ebp)\n" /* count */
        "jg .Lf160b80_00160f00\n"
        ".Lf160b80_00160de5:\n"
        "movl -0x644(%ebp), %ecx\n" /* line 591 | i */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal -0x624(%ebp, %eax, 2), %eax\n"
        "movzbl (%eax), %edx\n" /* line 594 */
        "movb %dl, -0x62d(%ebp)\n"
        "movzbl 1(%eax), %ecx\n" /* line 595 */
        "movb %cl, -0x62e(%ebp)\n"
        "movzbl 2(%eax), %edx\n" /* line 596 */
        "movb %dl, -0x62f(%ebp)\n"
        "movzbl 3(%eax), %ecx\n" /* line 597 */
        "movb %cl, -0x630(%ebp)\n"
        "movzwl 4(%eax), %eax\n" /* line 598 */
        "movw %ax, -0x632(%ebp)\n"
        "movw %ax, -0x1c(%ebp)\n"
        "movb %cl, -0x1d(%ebp)\n"
        "movb %dl, -0x1e(%ebp)\n"
        "movzbl -0x62e(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x62d(%ebp), %edx\n"
        "movb %dl, -0x20(%ebp)\n"
        "movl $4, -0x24(%ebp)\n" /* adr */
        /* { scope 2: low */
        /* { scope 3 */
        "movl -0x64c(%ebp), %ecx\n" /* line 475 */
        "movl 0x4540(%ecx), %esi\n" /* high */
        "testl %esi, %esi\n" /* line 476 | high */
        "jle .Lf160b80_00160d20\n"
        "movl $0, -0x638(%ebp)\n" /* low */
        "jmp .Lf160b80_00160e8e\n"
        ".Lf160b80_00160e6c:\n"
        "jle .Lf160b80_00160f60\n" /* line 487 */
        "addl $1, %ebx\n" /* line 489 */
        "movl %ebx, -0x638(%ebp)\n" /* low */
        "cmpl -0x638(%ebp), %esi\n" /* line 476 | low, high */
        "jle .Lf160b80_00160ed6\n"
        ".Lf160b80_00160e83:\n"
        "movl imp_cls, %eax\n"
        "movl %eax, -0x64c(%ebp)\n"
        ".Lf160b80_00160e8e:\n"
        "movl -0x638(%ebp), %edx\n" /* line 478 | low */
        "addl %esi, %edx\n" /* high */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %ebx\n"
        "sarl $1, %ebx\n"
        "movl %ebx, %edi\n" /* i */
        "movl %ebx, %eax\n" /* line 479 */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %ebx, 8), %eax\n"
        "movl -0x64c(%ebp), %edx\n"
        "leal 4(%eax, %edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* adr */
        "movl %ecx, (%esp)\n"
        "calll NET_CompareAdrSigned\n"
        "cmpl $0, %eax\n" /* line 481 */
        "jge .Lf160b80_00160e6c\n"
        "movl %ebx, %esi\n" /* line 499 | high */
        "cmpl -0x638(%ebp), %esi\n" /* line 476 | low, high */
        "jg .Lf160b80_00160e83\n"
        ".Lf160b80_00160ed6:\n"
        "movl imp_cls, %edx\n"
        "movl %edx, -0x64c(%ebp)\n"
        "jmp .Lf160b80_00160d20\n"
        /* } scope */
        /* } scope */
        ".Lf160b80_00160ee7:\n"
        "cmpb $0x4f, 8(%ebx)\n" /* line 580 | msg */
        "jne .Lf160b80_00160cca\n"
        "cmpb $0x54, 9(%ebx)\n" /* msg */
        "jne .Lf160b80_00160cca\n"
        "jmp .Lf160b80_00160cdc\n"
        ".Lf160b80_00160f00:\n"
        "movl -0x640(%ebp), %eax\n" /* line 609 | count */
        "movl -0x64c(%ebp), %edx\n"
        "movl %eax, 0x4540(%edx)\n"
        "movl $CL_CompareAdrSigned, 0xc(%esp)\n" /* line 434 */
        "movl $0x88, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %eax\n"
        "addl $0x4544, %eax\n"
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl -0x640(%ebp), %ecx\n" /* line 612 | count */
        "movl %ecx, 8(%esp)\n"
        "movl -0x63c(%ebp), %eax\n" /* numservers */
        "movl %eax, 4(%esp)\n"
        "movl $str_002abc6c, (%esp)\n" /* "%d servers parsed (total %d)
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x67c, %esp\n" /* line 613 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: adr */
        /* { scope 2: low */
        /* { scope 3 */
        ".Lf160b80_00160f60:\n"
        "subl $1, %edi\n" /* line 493 | i */
        "js .Lf160b80_00160f8d\n"
        "movl %edi, %eax\n" /* i */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %edi, 8), %eax\n"
        "addl imp_cls, %eax\n"
        "addl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* adr */
        "movl %eax, (%esp)\n"
        "calll NET_CompareAdrSigned\n"
        "testl %eax, %eax\n"
        "je .Lf160b80_00160f60\n"
        ".Lf160b80_00160f8d:\n"
        "addl $1, %edi\n" /* line 497 | i */
        "movl imp_cls, %edx\n"
        "movl %edx, -0x64c(%ebp)\n"
        "movl %edi, %eax\n" /* i */
        "shll $7, %eax\n"
        "leal (%eax, %edi, 8), %eax\n"
        "addl %edx, %eax\n"
        "leal 0x4544(%eax), %ecx\n"
        "movl %ecx, -0x650(%ebp)\n"
        "leal 0x4540(%eax), %esi\n" /* high */
        ".Lf160b80_00160fb8:\n"
        "movzbl -0x1e(%ebp), %edx\n" /* line 501 */
        "movzbl -0x1f(%ebp), %ecx\n"
        "movzbl -0x20(%ebp), %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 445 */
        "movw %ax, 0xc(%esi)\n"
        "movzbl -0x1d(%ebp), %eax\n"
        "movb %al, 0xb(%esi)\n"
        "movb %dl, 0xa(%esi)\n"
        "movb %cl, 9(%esi)\n"
        "movb %bl, 8(%esi)\n"
        "movl -0x24(%ebp), %eax\n" /* adr */
        "movl %eax, 4(%esi)\n"
        "movb $0, 0x11(%esi)\n" /* line 447 */
        "movb $0, 0x24(%esi)\n" /* line 448 */
        "movb $0, 0x44(%esi)\n" /* line 449 */
        "movb $0, 0x12(%esi)\n" /* line 450 */
        "movw $0, 0x20(%esi)\n" /* line 451 */
        "movw $0, 0x1e(%esi)\n" /* line 452 */
        "movw $0xffff, 0x22(%esi)\n" /* line 453 */
        "movb $0, 0x64(%esi)\n" /* line 454 */
        "movb $0, 0x7c(%esi)\n" /* line 455 */
        "movb $0, 0x10(%esi)\n" /* line 456 */
        "movb $0, 0x14(%esi)\n" /* line 457 */
        "movb $1, 0x13(%esi)\n" /* line 458 */
        "movb $0, 0x1d(%esi)\n" /* line 459 */
        "addl $1, %edi\n" /* line 502 | i */
        "addl $0x88, %esi\n" /* high */
        "addl $0x88, -0x650(%ebp)\n"
        "movl -0x64c(%ebp), %eax\n" /* line 499 */
        "cmpl 0x4540(%eax), %edi\n" /* i */
        "jge .Lf160b80_00160dbc\n"
        "movl -0x650(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* adr */
        "movl %ecx, (%esp)\n"
        "calll NET_CompareAdrSigned\n"
        "testl %eax, %eax\n"
        "je .Lf160b80_00160fb8\n"
        "movl imp_cls, %edx\n"
        "movl %edx, -0x64c(%ebp)\n"
        "jmp .Lf160b80_00160dbc\n"
    );
}

/* line 898 */
__attribute__((naked))
int CL_Ping_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 898 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 904 */
        "cmpl $2, %eax\n"
        "je .Lf16106e_00161095\n"
        "movl $str_002abc8c, (%esp)\n" /* line 906 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf16106e_0016108d:\n"
        "addl $0x6c, %esp\n" /* line 928 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16106e_00161095:\n"
        "leal -0x3c(%ebp), %ebx\n" /* line 910 | to */
        "movl $0, -0x3c(%ebp)\n" /* to */
        "movl $0, -0x38(%ebp)\n"
        "movl $0, -0x34(%ebp)\n"
        "movl $1, (%esp)\n" /* line 912 */
        "calll Cmd_Argv\n"
        "movl %ebx, 4(%esp)\n" /* line 914 */
        "movl %eax, (%esp)\n"
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf16106e_0016108d\n"
        "calll Sys_Milliseconds\n" /* line 846 */
        "movl %eax, %edi\n"
        "movl imp_cl_pinglist, %ebx\n"
        "movl %ebx, -0x4c(%ebp)\n"
        "leal 8(%ebx), %edx\n"
        "leal 0x4140(%ebx), %esi\n"
        "jmp .Lf16106e_00161106\n"
        ".Lf16106e_001610e4:\n"
        "movl %edi, %eax\n" /* line 856 */
        "subl 4(%edx), %eax\n"
        "cmpl $0x1f3, %eax\n"
        "jg .Lf16106e_0016111a\n"
        ".Lf16106e_001610f0:\n"
        "addl $0x414, %ebx\n" /* line 849 */
        "addl $0x414, %edx\n"
        "movl %esi, %ecx\n"
        "cmpl %ebx, %esi\n"
        "je .Lf16106e_001611ab\n"
        ".Lf16106e_00161106:\n"
        "cmpw $0, (%edx)\n" /* line 852 */
        "je .Lf16106e_0016111a\n"
        "movl 8(%edx), %eax\n" /* line 854 */
        "testl %eax, %eax\n"
        "je .Lf16106e_001610e4\n"
        "cmpl $0x1f3, %eax\n" /* line 862 */
        "jle .Lf16106e_001610f0\n"
        ".Lf16106e_0016111a:\n"
        "movw $0, 8(%ebx)\n" /* line 870 */
        ".Lf16106e_00161120:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 921 | to */
        "movl %eax, (%ebx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "calll Sys_Milliseconds\n" /* line 922 */
        "movl %eax, 0xc(%ebx)\n"
        "movl $0, 0x10(%ebx)\n" /* line 923 */
        "movl (%ebx), %ecx\n" /* line 925 */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 4(%ebx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_SetServerInfoByAddress\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 927 | to */
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $str_002a9420, 0x10(%esp)\n" /* "getinfo xxx" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 928 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16106e_001611ab:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 849 */
        "movl %ebx, %edx\n"
        "movl $0x80000000, %esi\n"
        ".Lf16106e_001611b5:\n"
        "movl %edi, %eax\n" /* line 881 */
        "subl 0xc(%edx), %eax\n"
        "cmpl %esi, %eax\n" /* line 882 */
        "jle .Lf16106e_001611c2\n"
        "movl %edx, %ebx\n"
        "movl %eax, %esi\n"
        ".Lf16106e_001611c2:\n"
        "addl $0x414, %edx\n" /* line 878 */
        "cmpl %edx, %ecx\n"
        "jne .Lf16106e_001611b5\n"
        "jmp .Lf16106e_00161120\n"
    );
}

/* line 313 */
__attribute__((naked))
int CL_Connect_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 313 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: chs */
        "calll Cmd_Argc\n" /* line 317 */
        "cmpl $2, %eax\n"
        "je .Lf1611d2_001611f9\n"
        "movl $str_002abca4, (%esp)\n" /* line 319 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf1611d2_001611f1:\n"
        "addl $0x4c, %esp\n" /* line 382 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: chs */
        ".Lf1611d2_001611f9:\n"
        "movl $0, (%esp)\n" /* line 323 */
        "calll SND_StopSounds\n"
        "movl imp_clc, %eax\n" /* line 326 */
        "movl (%eax), %eax\n"
        "movb $0, 0x28(%eax)\n"
        "movl $1, (%esp)\n" /* line 328 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* server */
        "movl imp_com_sv_running, %eax\n" /* line 330 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1611d2_0016140a\n"
        ".Lf1611d2_0016122f:\n"
        "movl imp_legacyHacks, %edx\n"
        ".Lf1611d2_00161235:\n"
        "movl (%edx), %eax\n" /* line 336 */
        "movb $0, 0x5c(%eax)\n"
        "movl (%edx), %eax\n" /* line 337 */
        "movb $0, 0x9c(%eax)\n"
        "movl $0, (%esp)\n" /* line 339 */
        "calll SV_Frame\n"
        "calll CL_Disconnect\n" /* line 341 */
        "calll Con_Close\n" /* line 342 */
        "movl $0x100, 8(%esp)\n" /* line 344 */
        "movl %ebx, 4(%esp)\n" /* server */
        "movl imp_cls, %esi\n"
        "addl $8, %esi\n"
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl imp_clc, %eax\n" /* line 346 */
        "movl (%eax), %ebx\n" /* server */
        "leal 0x14(%ebx), %eax\n" /* server */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf1611d2_001613f3\n"
        "cmpw $0, 0x1c(%ebx)\n" /* line 352 | server */
        "je .Lf1611d2_001613e8\n"
        ".Lf1611d2_001612a0:\n"
        "movzwl 0x1c(%ebx), %eax\n" /* line 356 | server */
        "rolw $8, %ax\n" /* line 925 */
        "cwtl\n" /* line 356 */
        "movl %eax, 0x18(%esp)\n"
        "movzbl 0x1b(%ebx), %eax\n" /* server */
        "movl %eax, 0x14(%esp)\n"
        "movzbl 0x1a(%ebx), %eax\n" /* server */
        "movl %eax, 0x10(%esp)\n"
        "movzbl 0x19(%ebx), %eax\n" /* server */
        "movl %eax, 0xc(%esp)\n"
        "movzbl 0x18(%ebx), %eax\n" /* server */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a92e0, (%esp)\n" /* "%s resolved to %i.%i.%i.%i:%i
" */
        "calll Com_Printf\n"
        "movl 0x14(%ebx), %ecx\n" /* line 359 | server */
        "movl %ecx, -0x38(%ebp)\n"
        "movl 0x18(%ebx), %edx\n" /* server */
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n" /* server */
        "movl %eax, -0x30(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_IsLocalAddress\n"
        "testl %eax, %eax\n"
        "jne .Lf1611d2_00161372\n"
        "xorl %edx, %edx\n"
        "movl imp_cl_cdkey, %ecx\n"
        "leal 0x10(%ecx), %ebx\n" /* server */
        /* { scope 2 */
        ".Lf1611d2_0016130e:\n"
        "movsbl (%ecx), %eax\n" /* line 405 */
        "xorl %eax, %edx\n"
        "movl $8, %eax\n"
        "jmp .Lf1611d2_00161327\n"
        ".Lf1611d2_0016131a:\n"
        "shrl $1, %edx\n" /* line 410 */
        "xorl $0xa001, %edx\n"
        "subl $1, %eax\n" /* line 407 */
        "je .Lf1611d2_00161333\n"
        ".Lf1611d2_00161327:\n"
        "testb $1, %dl\n" /* line 409 */
        "jne .Lf1611d2_0016131a\n"
        "shrl $1, %edx\n" /* line 412 */
        "subl $1, %eax\n" /* line 407 */
        "jne .Lf1611d2_00161327\n"
        ".Lf1611d2_00161333:\n"
        "addl $1, %ecx\n"
        "cmpl %ebx, %ecx\n" /* line 403 | server */
        "jne .Lf1611d2_0016130e\n"
        "movl %edx, 8(%esp)\n" /* line 416 */
        "movl $str_00228f18, 4(%esp)\n" /* "%04x" */
        "leal -0x1d(%ebp), %ebx\n" /* chs, server */
        "movl %ebx, (%esp)\n" /* server */
        "calll sprintf\n"
        "movl $4, 8(%esp)\n" /* line 418 */
        "movl imp_cl_cdkeychecksum, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* server */
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1611d2_0016145b\n"
        /* } scope */
        ".Lf1611d2_00161372:\n"
        "movl imp_clc, %esi\n" /* line 366 */
        "movl (%esi), %ebx\n" /* server */
        "movl 0x14(%ebx), %ecx\n" /* server */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl 0x18(%ebx), %edx\n" /* server */
        "movl %edx, -0x28(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n" /* server */
        "movl %eax, -0x24(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_IsLocalAddress\n"
        "testl %eax, %eax\n"
        "je .Lf1611d2_00161446\n"
        "movl $4, (%ebx)\n" /* line 367 | server */
        "movl (%esi), %edx\n"
        ".Lf1611d2_001613ac:\n"
        "movl imp_cl, %eax\n" /* line 371 */
        "movl (%eax), %eax\n"
        "movl $0, 4(%eax)\n"
        "movb $0, 8(%eax)\n" /* line 372 */
        "movl $0xfffe7961, 0x20(%edx)\n" /* line 373 */
        "movl $0, 0x24(%edx)\n" /* line 374 */
        "movl imp_g_qport, %eax\n" /* line 377 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%edx)\n"
        "calll UI_CloseAll\n" /* line 380 */
        "calll SCR_UpdateScreen\n" /* line 381 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 382 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: chs */
        ".Lf1611d2_001613e8:\n"
        "movw $0x2071, 0x1c(%ebx)\n" /* line 354 | server */
        "jmp .Lf1611d2_001612a0\n"
        ".Lf1611d2_001613f3:\n"
        "movl $str_002abcc0, (%esp)\n" /* line 348 */
        "calll Com_Printf\n"
        "movl $0, (%ebx)\n" /* line 349 | server */
        "jmp .Lf1611d2_001611f1\n"
        ".Lf1611d2_0016140a:\n"
        "movl $str_002a8ab8, %edi\n" /* line 330 */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* server */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1611d2_0016142a\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1611d2_0016142a:\n"
        "testl %edx, %edx\n"
        "jne .Lf1611d2_0016122f\n"
        "movl imp_legacyHacks, %edx\n" /* line 333 */
        "movl (%edx), %eax\n"
        "movb $1, 0xdd(%eax)\n"
        "jmp .Lf1611d2_00161235\n"
        ".Lf1611d2_00161446:\n"
        "movl imp_clc, %edx\n" /* line 369 */
        "movl (%edx), %eax\n"
        "movl $3, (%eax)\n"
        "movl %eax, %edx\n"
        "jmp .Lf1611d2_001613ac\n"
        ".Lf1611d2_0016145b:\n"
        "movl $str_002a9280, 4(%esp)\n" /* line 361 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1611d2_001611f1\n"
    );
}

/* line 980 */
__attribute__((naked))
int CL_ServerStatus(char *serverAddress, char *serverStatusString, int maxLen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 980 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %edx\n" /* serverAddress */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 987 */
        "je .Lf161474_001616ef\n"
        "leal -0x6c(%ebp), %eax\n" /* line 997 | to */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf161474_001616e2\n"
        "movl -0x64(%ebp), %eax\n" /* line 1001 */
        "movw %ax, -0x7a(%ebp)\n"
        "movzbl -0x65(%ebp), %edx\n"
        "movb %dl, -0x7b(%ebp)\n"
        "movzbl -0x66(%ebp), %eax\n"
        "movb %al, -0x7c(%ebp)\n"
        "movzbl -0x67(%ebp), %edx\n"
        "movb %dl, -0x7d(%ebp)\n"
        "movzbl -0x68(%ebp), %eax\n"
        "movb %al, -0x7e(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n" /* to */
        "movl %edx, -0x8c(%ebp)\n"
        "xorl %esi, %esi\n" /* i */
        "movl $cl_serverStatusList, %ebx\n" /* oldestTime */
        /* { scope 2 */
        ".Lf161474_001614d5:\n"
        "movl 0x2000(%ebx), %ecx\n" /* line 944 | oldestTime */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0x2004(%ebx), %edx\n" /* oldestTime */
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x2008(%ebx), %edi\n" /* oldestTime */
        "movl %edi, -0x28(%ebp)\n"
        "movzwl -0x7a(%ebp), %eax\n"
        "movw %ax, -0x40(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x41(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x42(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x43(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x44(%ebp)\n"
        "movl -0x8c(%ebp), %edi\n"
        "movl %edi, -0x48(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x2008(%ebx), %eax\n" /* oldestTime */
        "movl %eax, 0x14(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf161474_001615bb\n"
        "addl $1, %esi\n" /* line 942 | i */
        "addl $0x2020, %ebx\n" /* oldestTime */
        "cmpl $0x10, %esi\n" /* i */
        "jne .Lf161474_001614d5\n"
        "xorl %edx, %edx\n"
        "movl $cl_serverStatusList, %eax\n"
        ".Lf161474_00161562:\n"
        "movl 0x201c(%eax), %esi\n" /* line 951 | i */
        "testl %esi, %esi\n" /* i */
        "jne .Lf161474_0016178b\n"
        "addl $1, %edx\n" /* line 949 */
        "addl $0x2020, %eax\n"
        "cmpl $0x10, %edx\n"
        "jne .Lf161474_00161562\n"
        ".Lf161474_0016157d:\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf161474_00161593\n"
        ".Lf161474_00161581:\n"
        "movl 0x2010(%edx), %eax\n" /* line 960 */
        "addl $0x2020, %edx\n"
        "cmpl %eax, %ebx\n" /* oldestTime */
        "jle .Lf161474_001615b3\n"
        "movl %ecx, %esi\n" /* i */
        ".Lf161474_00161593:\n"
        "movl %esi, %edx\n" /* line 963 | i */
        "shll $5, %edx\n"
        "movl %esi, %eax\n" /* i */
        "shll $0xd, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl cl_serverStatusList+8208(%eax), %ebx\n" /* oldestTime */
        "cmpl $-1, %esi\n" /* i */
        "je .Lf161474_0016157d\n"
        /* } scope */
        "leal cl_serverStatusList+8224(%eax), %edx\n" /* line 1042 */
        "movl %esi, %ecx\n" /* i */
        /* { scope 2 */
        ".Lf161474_001615b3:\n"
        "addl $1, %ecx\n" /* line 958 */
        "cmpl $0xf, %ecx\n"
        "jle .Lf161474_00161581\n"
        ".Lf161474_001615bb:\n"
        "movl %esi, %eax\n" /* line 946 | i */
        "shll $5, %eax\n"
        "shll $0xd, %esi\n" /* i */
        "leal cl_serverStatusList(%eax, %esi), %esi\n" /* i */
        "movl %esi, -0x84(%ebp)\n" /* i, serverStatus */
        /* } scope */
        ".Lf161474_001615d0:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1003 | serverStatusString, oldestTime */
        "testl %ebx, %ebx\n" /* oldestTime */
        "je .Lf161474_001616d2\n"
        "movl -0x84(%ebp), %edx\n" /* line 1010 | serverStatus */
        "movl 0x2000(%edx), %edi\n"
        "movl %edi, -0x60(%ebp)\n"
        "movl 0x2004(%edx), %esi\n" /* i */
        "movl %esi, -0x5c(%ebp)\n" /* i */
        "movl 0x2008(%edx), %ebx\n" /* oldestTime */
        "movl %ebx, -0x58(%ebp)\n" /* oldestTime */
        "movl -0x6c(%ebp), %ecx\n" /* to */
        "movl %ecx, -0x54(%ebp)\n"
        "movl -0x68(%ebp), %edx\n"
        "movl %edx, -0x50(%ebp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* i */
        "movl %ebx, 0x14(%esp)\n" /* oldestTime */
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf161474_00161717\n"
        "movl -0x84(%ebp), %eax\n" /* line 1033 | serverStatus */
        "movl 0x201c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf161474_001616e2\n"
        "movl %eax, %edx\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1035 | to */
        "movl %eax, 0x2000(%edx)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x2004(%edx)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x2008(%edx)\n"
        "movl $0, 0x2018(%edx)\n" /* line 1036 */
        "movl $1, 0x2014(%edx)\n" /* line 1037 */
        "movl $0, 0x201c(%edx)\n" /* line 1038 */
        "calll Sys_Milliseconds\n" /* line 1039 */
        "movl -0x84(%ebp), %edi\n" /* serverStatus */
        "movl %eax, 0x2010(%edi)\n"
        "movl $0, 0x200c(%edi)\n" /* line 1040 */
        "movl -0x6c(%ebp), %ecx\n" /* line 1041 | to */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl -0x68(%ebp), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        ".Lf161474_001616ae:\n"
        "movl $str_002ab528, 0x10(%esp)\n" /* "getstatus" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "xorl %eax, %eax\n"
        "jmp .Lf161474_001616e4\n"
        ".Lf161474_001616d2:\n"
        "movl -0x84(%ebp), %eax\n" /* line 1005 | serverStatus */
        "movl $1, 0x201c(%eax)\n"
        ".Lf161474_001616e2:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf161474_001616e4:\n"
        "addl $0xac, %esp\n" /* line 1045 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf161474_001616ef:\n"
        "movl $cl_serverStatusList, %eax\n" /* line 987 */
        "movl $cl_serverStatusList+131584, %edx\n"
        ".Lf161474_001616f9:\n"
        "movw $0, 0x2008(%eax)\n" /* line 991 */
        "movl $1, 0x201c(%eax)\n" /* line 992 */
        "addl $0x2020, %eax\n"
        "cmpl %eax, %edx\n" /* line 989 */
        "jne .Lf161474_001616f9\n"
        "jmp .Lf161474_001616e2\n"
        ".Lf161474_00161717:\n"
        "movl -0x84(%ebp), %edi\n" /* line 1013 | serverStatus */
        "movl 0x2014(%edi), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf161474_001617a5\n"
        "movl 0x2010(%edi), %ebx\n" /* line 1021 | oldestTime */
        "calll Sys_Milliseconds\n"
        "movl imp_cl_serverStatusResendTime, %edx\n"
        "movl (%edx), %edx\n"
        "subl 8(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* oldestTime */
        "jge .Lf161474_001616e2\n"
        "movl $0, 0x2018(%edi)\n" /* line 1023 */
        "movl $1, 0x2014(%edi)\n" /* line 1024 */
        "movl $0, 0x201c(%edi)\n" /* line 1025 */
        "movl $0, 0x200c(%edi)\n" /* line 1026 */
        "calll Sys_Milliseconds\n" /* line 1027 */
        "movl %eax, 0x2010(%edi)\n"
        "movl -0x6c(%ebp), %ecx\n" /* line 1028 | to */
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x68(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "jmp .Lf161474_001616ae\n"
        /* { scope 2 */
        ".Lf161474_0016178b:\n"
        "movl %edx, %eax\n" /* line 953 */
        "shll $5, %eax\n"
        "shll $0xd, %edx\n"
        "leal cl_serverStatusList(%eax, %edx), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* serverStatus */
        "jmp .Lf161474_001615d0\n"
        /* } scope */
        ".Lf161474_001617a5:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1015 | maxLen */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* serverStatusString */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $1, 0x201c(%edi)\n" /* line 1016 */
        "movl $0, 0x2010(%edi)\n" /* line 1017 */
        "movl $1, %eax\n"
        "jmp .Lf161474_001616e4\n"
    );
}

/* line 1053 */
__attribute__((naked))
int CL_ServerStatus_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1053 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl $0xc, 8(%esp)\n" /* line 1059 */
        "movl $0, 4(%esp)\n"
        "leal -0x48(%ebp), %ebx\n" /* to */
        "movl %ebx, (%esp)\n"
        "calll Com_Memset\n"
        "calll Cmd_Argc\n" /* line 1061 */
        "cmpl $2, %eax\n"
        "je .Lf1617da_001619a7\n"
        "movl imp_clc, %eax\n" /* line 1063 */
        "movl (%eax), %eax\n"
        "cmpl $8, (%eax)\n"
        "je .Lf1617da_00161838\n"
        ".Lf1617da_00161818:\n"
        "movl $str_002a8b24, (%esp)\n" /* line 1065 */
        "calll Com_Printf\n"
        "movl $str_002abcd4, (%esp)\n" /* line 1066 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf1617da_00161830:\n"
        "addl $0x7c, %esp\n" /* line 1087 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1617da_00161838:\n"
        "movl 0x407a0(%eax), %eax\n" /* line 1063 */
        "testl %eax, %eax\n"
        "jne .Lf1617da_00161818\n"
        "movl imp_cls, %eax\n"
        "addl $8, %eax\n"
        ".Lf1617da_0016184a:\n"
        "movl %ebx, 4(%esp)\n" /* line 1076 */
        "movl %eax, (%esp)\n"
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf1617da_00161830\n"
        "movl -0x48(%ebp), %ecx\n" /* line 1081 | to */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl $str_002ab528, 0x10(%esp)\n" /* "getstatus" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl -0x40(%ebp), %eax\n" /* line 1083 */
        "movw %ax, -0x4a(%ebp)\n"
        "movzbl -0x41(%ebp), %eax\n"
        "movb %al, -0x4b(%ebp)\n"
        "movzbl -0x42(%ebp), %eax\n"
        "movb %al, -0x4c(%ebp)\n"
        "movzbl -0x43(%ebp), %eax\n"
        "movb %al, -0x4d(%ebp)\n"
        "movzbl -0x44(%ebp), %eax\n"
        "movb %al, -0x4e(%ebp)\n"
        "movl -0x48(%ebp), %edi\n" /* to */
        "movl %edi, -0x5c(%ebp)\n"
        "xorl %esi, %esi\n" /* oldestTime */
        "movl $cl_serverStatusList, %ebx\n"
        /* { scope 2 */
        ".Lf1617da_001618bc:\n"
        "movl 0x2000(%ebx), %ecx\n" /* line 944 */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0x2004(%ebx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x2008(%ebx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movzwl -0x4a(%ebp), %edi\n"
        "movw %di, -0x1c(%ebp)\n"
        "movzbl -0x4b(%ebp), %eax\n"
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x4c(%ebp), %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x4d(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x4e(%ebp), %eax\n"
        "movb %al, -0x20(%ebp)\n"
        "movl -0x5c(%ebp), %edi\n"
        "movl %edi, -0x24(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x2008(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf1617da_001619b8\n"
        "addl $1, %esi\n" /* line 942 | oldestTime */
        "addl $0x2020, %ebx\n"
        "cmpl $0x10, %esi\n" /* oldestTime */
        "jne .Lf1617da_001618bc\n"
        "xorl %edx, %edx\n"
        "movl $cl_serverStatusList, %eax\n"
        ".Lf1617da_0016194a:\n"
        "movl 0x201c(%eax), %edi\n" /* line 951 */
        "testl %edi, %edi\n"
        "jne .Lf1617da_00161a0f\n"
        "addl $1, %edx\n" /* line 949 */
        "addl $0x2020, %eax\n"
        "cmpl $0x10, %edx\n"
        "jne .Lf1617da_0016194a\n"
        "xorl %ebx, %ebx\n"
        ".Lf1617da_00161967:\n"
        "movl %ebx, %edx\n" /* line 963 */
        "shll $5, %edx\n"
        "movl %ebx, %eax\n"
        "shll $0xd, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl cl_serverStatusList+8208(%eax), %esi\n" /* oldestTime */
        "cmpl $-1, %ebx\n"
        "je .Lf1617da_00161a20\n"
        /* } scope */
        "leal cl_serverStatusList+8224(%eax), %edx\n" /* line 1086 */
        "movl %ebx, %ecx\n"
        /* { scope 2 */
        ".Lf1617da_0016198b:\n"
        "addl $1, %ecx\n" /* line 958 */
        "cmpl $0xf, %ecx\n"
        "jg .Lf1617da_001619fe\n"
        "movl 0x2010(%edx), %eax\n" /* line 960 */
        "addl $0x2020, %edx\n"
        "cmpl %eax, %esi\n" /* oldestTime */
        "jle .Lf1617da_0016198b\n"
        "movl %ecx, %ebx\n" /* line 949 */
        "jmp .Lf1617da_00161967\n"
        /* } scope */
        ".Lf1617da_001619a7:\n"
        "movl $1, (%esp)\n" /* line 1073 */
        "calll Cmd_Argv\n"
        "jmp .Lf1617da_0016184a\n"
        /* { scope 2 */
        ".Lf1617da_001619b8:\n"
        "movl %esi, %eax\n" /* line 946 | oldestTime */
        "shll $5, %eax\n"
        "shll $0xd, %esi\n" /* oldestTime */
        "leal cl_serverStatusList(%eax, %esi), %edx\n"
        /* } scope */
        ".Lf1617da_001619c7:\n"
        "movl -0x48(%ebp), %eax\n" /* line 1084 | to */
        "movl %eax, 0x2000(%edx)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x2004(%edx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x2008(%edx)\n"
        "movl $1, 0x2018(%edx)\n" /* line 1085 */
        "movl $1, 0x2014(%edx)\n" /* line 1086 */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1087 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1617da_001619fe:\n"
        "movl %ebx, %eax\n" /* line 968 */
        "shll $5, %eax\n"
        "shll $0xd, %ebx\n"
        "leal cl_serverStatusList(%eax, %ebx), %edx\n"
        "jmp .Lf1617da_001619c7\n"
        ".Lf1617da_00161a0f:\n"
        "movl %edx, %eax\n" /* line 953 */
        "shll $5, %eax\n"
        "shll $0xd, %edx\n"
        "leal cl_serverStatusList(%eax, %edx), %edx\n"
        "jmp .Lf1617da_001619c7\n"
        ".Lf1617da_00161a20:\n"
        "xorl %ecx, %ecx\n" /* line 949 */
        "movl %ecx, %ebx\n"
        "jmp .Lf1617da_00161967\n"
    );
}

