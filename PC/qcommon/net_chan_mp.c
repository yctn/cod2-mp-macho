/* ASM dump from: net_chan_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/net_chan_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern int g_qport; /* 0x0 */
extern const dvar_t *net_profile; /* 0x0 */
extern const dvar_t *net_showprofile; /* 0x0 */
extern const dvar_t *net_lanauthorize; /* 0x0 */
extern const dvar_t *showpackets; /* 0x0 */
extern const dvar_t *showdrop; /* 0x0 */
extern const dvar_t *packetDebug; /* 0x0 */
static char s[64]; /* s */
extern char * netsrcString[2]; /* netsrcString */
static int net_iProfilingOn; /* net_iProfilingOn */
static loopback_t loopbacks[2]; /* loopbacks */

extern void Com_Printf(const char *fmt, ...);
extern void SV_Netchan_PrintProfileStats(int bDumpRecvStats);
extern void CL_Netchan_PrintProfileStats(int bDumpRecvStats);
extern qboolean Sys_GetPacket(netadr_t *net_from, msg_t *net_message);

void NetProf_PrepProfiling(netProfileInfo_t * *pProf);
void NetProf_AddPacket(netProfileStream_t *pProfStream, int iSize, qboolean bFragment);
void NetProf_UpdateStatistics(netProfileStream_t *pStream);
void Net_DumpProfile_f(void);
void Net_DisplayProfile(void);
void Netchan_Init(int port);
void Netchan_Setup(netsrc_t sock, netchan_t *chan, struct netadr_t adr, int qport);
int NET_CompareAdrSigned(netadr_t *a, netadr_t *b);
qboolean NET_IsLocalAddress(netadr_t adr);
qboolean NET_GetPacket(netadr_t *net_from, msg_t *net_message);
const char * NET_AdrToString(netadr_t a);
qboolean NET_StringToAdr(const char *s, netadr_t *a);
Bool NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to);
void NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, byte *format, int len);
Bool NET_OutOfBandData(netsrc_t sock, netadr_t adr, byte *format, int len);
Bool NET_OutOfBandPrint(netsrc_t sock, netadr_t adr, const char *data);
qboolean NET_CompareAdr(netadr_t a, netadr_t b);
qboolean NET_CompareBaseAdr(netadr_t a, netadr_t b);
qboolean NET_GetLoopPacket(netsrc_t sock, netadr_t *net_from, msg_t *net_message);
Bool Netchan_TransmitNextFragment(netchan_t *chan);
Bool Netchan_Transmit(netchan_t *chan, int length, const byte *data);
qboolean Netchan_Process(netchan_t *chan, msg_t *msg);

/* line 156 */
__attribute__((naked))
void NetProf_PrepProfiling(netProfileInfo_t * *pProf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 156 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pProf */
        "movl net_profile, %eax\n" /* line 158 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf157828_00157857\n"
        "movl net_iProfilingOn, %eax\n" /* line 160 */
        "testl %eax, %eax\n"
        "je .Lf157828_0015787a\n"
        "movl (%ebx), %edx\n" /* line 177 | pProf */
        "testl %edx, %edx\n"
        "je .Lf157828_001578f5\n"
        ".Lf157828_00157851:\n"
        "addl $0x14, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf157828_00157857:\n"
        "movl net_iProfilingOn, %eax\n" /* line 185 */
        "testl %eax, %eax\n"
        "jne .Lf157828_001578b5\n"
        "movl (%ebx), %eax\n" /* line 191 | pProf */
        "testl %eax, %eax\n"
        "je .Lf157828_00157851\n"
        ".Lf157828_00157866:\n"
        "movl %eax, (%esp)\n" /* line 193 */
        "calll free\n"
        "movl $0, (%ebx)\n" /* line 194 | pProf */
        "addl $0x14, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf157828_0015787a:\n"
        "movl imp_com_sv_running, %eax\n" /* line 162 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf157828_001578d6\n"
        ".Lf157828_00157887:\n"
        "movl $1, net_iProfilingOn\n" /* line 163 */
        ".Lf157828_00157891:\n"
        "movl net_iProfilingOn, %eax\n" /* line 173 */
        "movl g_qport(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab038, (%esp)\n" /* "Net Profiling turned on: %s
" */
        "calll Com_Printf\n"
        "movl (%ebx), %edx\n" /* line 177 | pProf */
        "testl %edx, %edx\n"
        "jne .Lf157828_00157851\n"
        "jmp .Lf157828_001578f5\n"
        ".Lf157828_001578b5:\n"
        "movl $0, net_iProfilingOn\n" /* line 187 */
        "movl $str_002ab058, (%esp)\n" /* line 188 */
        "calll Com_Printf\n"
        "movl (%ebx), %eax\n" /* line 191 | pProf */
        "testl %eax, %eax\n"
        "jne .Lf157828_00157866\n"
        "jmp .Lf157828_00157851\n"
        ".Lf157828_001578d6:\n"
        "movl imp_legacyHacks, %eax\n" /* line 162 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf157828_001578e9\n"
        "cmpl $2, %edx\n"
        "je .Lf157828_00157887\n"
        ".Lf157828_001578e9:\n"
        "movl $2, net_iProfilingOn\n" /* line 165 */
        "jmp .Lf157828_00157891\n"
        ".Lf157828_001578f5:\n"
        "movl $0x5e0, (%esp)\n" /* line 179 */
        "calll malloc\n"
        "movl %eax, (%ebx)\n" /* pProf */
        "movl $0x5e0, 8(%esp)\n" /* line 180 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "jmp .Lf157828_00157851\n"
    );
}

/* line 205 */
__attribute__((naked))
void NetProf_AddPacket(netProfileStream_t *pProfStream, int iSize, qboolean bFragment)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 205 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* pProfStream */
        /* { scope 1 */
        "movl 0x2d0(%esi), %ecx\n" /* line 211 | pProfStream */
        "addl $1, %ecx\n"
        "movl $0x88888889, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "leal (%edx, %ecx), %ebx\n" /* pPacket */
        "sarl $5, %ebx\n" /* pPacket */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* pPacket */
        "leal (, %ebx, 4), %edx\n"
        "movl %ebx, %eax\n" /* pPacket */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl %ecx, %ebx\n" /* pPacket */
        "subl %eax, %ebx\n" /* pPacket */
        "movl %ebx, 0x2d0(%esi)\n" /* pPacket, pProfStream */
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 213 | pPacket */
        "leal (%esi, %ebx, 4), %ebx\n" /* pProfStream, pPacket */
        "calll Sys_Milliseconds\n" /* line 216 */
        "movl %eax, (%ebx)\n" /* pPacket */
        "movl 0xc(%ebp), %eax\n" /* line 217 | iSize */
        "movl %eax, 4(%ebx)\n" /* pPacket */
        "movl 0x10(%ebp), %eax\n" /* line 218 | bFragment */
        "movl %eax, 8(%ebx)\n" /* pPacket */
        /* } scope */
        "popl %ebx\n" /* line 219 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 269 */
__attribute__((naked))
void NetProf_UpdateStatistics(netProfileStream_t *pStream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 269 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll Sys_Milliseconds\n" /* line 291 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* pStream */
        "movl $0, -0x30(%ebp)\n" /* iNumPackets */
        "movl $0, -0x2c(%ebp)\n" /* iNumFragments */
        "movl $0xffffffff, -0x28(%ebp)\n" /* iOldestPacket */
        "movl $0, -0x24(%ebp)\n" /* iTotalBytes */
        "movl $0x270f, -0x20(%ebp)\n"
        "xorl %edi, %edi\n" /* iLargestSize */
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf15797c_001579c4\n"
        ".Lf15797c_001579b9:\n"
        "addl $1, %esi\n" /* line 295 | i */
        "addl $0xc, %ebx\n"
        "cmpl $0x3c, %esi\n" /* i */
        "je .Lf15797c_00157a14\n"
        ".Lf15797c_001579c4:\n"
        "movl (%ebx), %eax\n" /* line 297 */
        "testl %eax, %eax\n"
        "je .Lf15797c_001579b9\n"
        "calll Sys_Milliseconds\n" /* line 301 */
        "movl (%ebx), %ecx\n"
        "leal 0x3e8(%ecx), %edx\n"
        "cmpl %edx, %eax\n"
        "jg .Lf15797c_001579b9\n"
        "addl $1, -0x30(%ebp)\n" /* line 304 | iNumPackets */
        "cmpl $1, 8(%ebx)\n" /* line 307 */
        "sbbl $-1, -0x2c(%ebp)\n" /* iNumFragments */
        "cmpl -0x1c(%ebp), %ecx\n" /* line 309 */
        "jge .Lf15797c_001579f2\n"
        "movl %esi, -0x28(%ebp)\n" /* i, iOldestPacket */
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lf15797c_001579f2:\n"
        "movl 4(%ebx), %eax\n" /* line 315 */
        "addl %eax, -0x24(%ebp)\n" /* iTotalBytes */
        "cmpl -0x20(%ebp), %eax\n" /* line 317 */
        "movl -0x20(%ebp), %edx\n"
        "cmovll %eax, %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "cmpl %edi, %eax\n" /* line 320 | iLargestSize */
        "cmovgl %eax, %edi\n" /* iLargestSize */
        "addl $1, %esi\n" /* line 295 | i */
        "addl $0xc, %ebx\n"
        "cmpl $0x3c, %esi\n" /* i */
        "jne .Lf15797c_001579c4\n"
        ".Lf15797c_00157a14:\n"
        "movl -0x30(%ebp), %eax\n" /* line 325 | iNumPackets */
        "testl %eax, %eax\n"
        "jne .Lf15797c_00157a6c\n"
        "movl 8(%ebp), %ecx\n" /* line 327 | pStream */
        "movl $0, 0x2d4(%ecx)\n"
        "movl $0, 0x2d8(%ecx)\n" /* line 328 */
        "movl $0, 0x2dc(%ecx)\n" /* line 329 */
        "movl $0, 0x2e0(%ecx)\n" /* line 330 */
        "movl $0, 0x2e4(%ecx)\n" /* line 331 */
        "movl $0, 0x2e8(%ecx)\n" /* line 332 */
        "movl $0, 0x2ec(%ecx)\n" /* line 333 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15797c_00157a6c:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 338 | iNumFragments */
        "testl %eax, %eax\n"
        "je .Lf15797c_00157acd\n"
        "movl -0x2c(%ebp), %edx\n" /* line 339 | iNumFragments */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "cltd\n"
        "idivl -0x30(%ebp)\n" /* iNumPackets */
        "movl 8(%ebp), %ecx\n" /* pStream */
        "movl %eax, 0x2e4(%ecx)\n"
        "movl 8(%ebp), %edx\n" /* line 344 | pStream */
        "movl %edi, 0x2e8(%edx)\n" /* iLargestSize */
        "movl -0x20(%ebp), %ecx\n" /* line 345 */
        "movl %ecx, 0x2ec(%edx)\n"
        "movl 0x2d8(%edx), %ebx\n" /* line 348 */
        "addl $0x64, %ebx\n"
        "calll Sys_Milliseconds\n"
        "cmpl %eax, %ebx\n"
        "jl .Lf15797c_00157afe\n"
        ".Lf15797c_00157ab0:\n"
        "movl -0x30(%ebp), %eax\n" /* line 376 | iNumPackets */
        "movl 8(%ebp), %ecx\n" /* pStream */
        "movl %eax, 0x2dc(%ecx)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 377 | iNumFragments */
        "movl %edx, 0x2e0(%ecx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15797c_00157acd:\n"
        "movl 8(%ebp), %eax\n" /* line 341 | pStream */
        "movl $0, 0x2e4(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 344 | pStream */
        "movl %edi, 0x2e8(%edx)\n" /* iLargestSize */
        "movl -0x20(%ebp), %ecx\n" /* line 345 */
        "movl %ecx, 0x2ec(%edx)\n"
        "movl 0x2d8(%edx), %ebx\n" /* line 348 */
        "addl $0x64, %ebx\n"
        "calll Sys_Milliseconds\n"
        "cmpl %eax, %ebx\n"
        "jge .Lf15797c_00157ab0\n"
        ".Lf15797c_00157afe:\n"
        "calll Sys_Milliseconds\n" /* line 351 */
        "movl %eax, %edx\n"
        "subl -0x1c(%ebp), %edx\n"
        "cmpl $-1, -0x28(%ebp)\n" /* line 354 | iOldestPacket */
        "je .Lf15797c_00157b2c\n"
        "movl -0x28(%ebp), %ecx\n" /* line 356 | iOldestPacket */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl 8(%ebp), %ecx\n" /* pStream */
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 4(%eax), %ecx\n"
        "subl %ecx, -0x24(%ebp)\n" /* iTotalBytes */
        "subl $1, -0x30(%ebp)\n" /* line 357 | iNumPackets */
        "cmpl $1, 8(%eax)\n" /* line 360 */
        "adcl $-1, -0x2c(%ebp)\n" /* iNumFragments */
        ".Lf15797c_00157b2c:\n"
        "testl %edx, %edx\n" /* line 363 */
        "jle .Lf15797c_00157b37\n"
        "movl -0x30(%ebp), %eax\n" /* iNumPackets */
        "testl %eax, %eax\n"
        "jne .Lf15797c_00157b49\n"
        ".Lf15797c_00157b37:\n"
        "movl 8(%ebp), %eax\n" /* line 364 | pStream */
        "movl $0, 0x2d4(%eax)\n"
        "jmp .Lf15797c_00157ab0\n"
        ".Lf15797c_00157b49:\n"
        "movl -0x24(%ebp), %eax\n" /* line 367 | iTotalBytes */
        "testl %eax, %eax\n"
        "jne .Lf15797c_00157b70\n"
        "movl 8(%ebp), %edx\n" /* line 368 | pStream */
        "movl $0, 0x2d4(%edx)\n"
        ".Lf15797c_00157b5d:\n"
        "calll Sys_Milliseconds\n" /* line 372 */
        "movl 8(%ebp), %edx\n" /* pStream */
        "movl %eax, 0x2d8(%edx)\n"
        "jmp .Lf15797c_00157ab0\n"
        ".Lf15797c_00157b70:\n"
        "cvtsi2ssl -0x24(%ebp), %xmm0\n" /* line 370 | iTotalBytes */
        "cvtsi2ssl %edx, %xmm1\n"
        "mulss lit4_002ed658, %xmm1\n" /* 0.0010000000474974513f */
        "divss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl 8(%ebp), %ecx\n" /* pStream */
        "movl %eax, 0x2d4(%ecx)\n"
        "jmp .Lf15797c_00157b5d\n"
    );
}

/* line 390 */
void Net_DumpProfile_f(void)
{
    if (net_iProfilingOn == 0)
    {
        Com_Printf("Network profiling is not on. Set net_profile to turn on network profiling\n");
        return;
    }
    if (net_iProfilingOn == 1)
    {
        CL_Netchan_PrintProfileStats(1);
        return;
    }
    SV_Netchan_PrintProfileStats(1);
}

/* line 419 */
void Net_DisplayProfile(void)
{
    if (net_iProfilingOn == 0)
        return;
    if (net_iProfilingOn == 1)
    {
        CL_Netchan_PrintProfileStats(0);
        return;
    }
    SV_Netchan_PrintProfileStats(0);
}

/* line 837 */
__attribute__((naked))
void Netchan_Init(int port)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 837 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 839 */
        "movl $0, 4(%esp)\n"
        "movl $str_002ab0c0, (%esp)\n" /* "showpackets" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, showpackets\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 840 */
        "movl $0, 4(%esp)\n"
        "movl $str_002ab0cc, (%esp)\n" /* "showdrop" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, showdrop\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 841 */
        "movl $0, 4(%esp)\n"
        "movl $str_002ab0d8, (%esp)\n" /* "packetDebug" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, packetDebug\n"
        "movzwl 8(%ebp), %eax\n" /* line 845 | port */
        "movl %eax, g_qport\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 848 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002ab0e4, (%esp)\n" /* "net_profile" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, net_profile\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 849 */
        "movl $3, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002ab0f0, (%esp)\n" /* "net_showprofile" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, net_showprofile\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 851 */
        "movl $0, 4(%esp)\n"
        "movl $str_002ab100, (%esp)\n" /* "net_lanauthorize" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, net_lanauthorize\n"
        "movl $Net_DumpProfile_f, 4(%esp)\n" /* line 865 */
        "movl $str_002ab114, (%esp)\n" /* "net_dumpprofile" */
        "calll Cmd_AddCommand\n"
        "leave\n" /* line 870 */
        "retl\n"
    );
}

/* line 879 */
__attribute__((naked))
void Netchan_Setup(netsrc_t sock, netchan_t *chan, struct netadr_t adr, int qport)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 879 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* sock */
        "movl %eax, -0x24(%ebp)\n" /* sock */
        "movl 0xc(%ebp), %ebx\n" /* chan */
        "movl 0x1c(%ebp), %eax\n" /* qport */
        "movl %eax, -0x28(%ebp)\n" /* qport */
        "movl 0x18(%ebp), %esi\n"
        "movzbl 0x17(%ebp), %edi\n"
        "movzbl 0x16(%ebp), %eax\n"
        "movb %al, -0x19(%ebp)\n"
        "movzbl 0x15(%ebp), %eax\n"
        "movb %al, -0x1a(%ebp)\n"
        "movzbl 0x14(%ebp), %eax\n"
        "movb %al, -0x1b(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* adr */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0x8038, 8(%esp)\n" /* line 881 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* chan */
        "calll memset\n"
        "movl -0x24(%ebp), %eax\n" /* line 883 | sock */
        "movl %eax, 4(%ebx)\n" /* chan */
        "movw %si, 0x18(%ebx)\n" /* line 884 | chan */
        "movl %edi, %eax\n"
        "movb %al, 0x17(%ebx)\n" /* chan */
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, 0x16(%ebx)\n" /* chan */
        "movzbl -0x1a(%ebp), %eax\n"
        "movb %al, 0x15(%ebx)\n" /* chan */
        "movzbl -0x1b(%ebp), %eax\n"
        "movb %al, 0x14(%ebx)\n" /* chan */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* chan */
        "movl -0x28(%ebp), %eax\n" /* line 886 | qport */
        "movl %eax, 0x1c(%ebx)\n" /* chan */
        "movl $0, 0xc(%ebx)\n" /* line 888 | chan */
        "movl $1, (%ebx)\n" /* line 889 | chan */
        "addl $0x8034, %ebx\n" /* line 891 | chan */
        "movl %ebx, 8(%ebp)\n" /* chan, sock */
        "addl $0x2c, %esp\n" /* line 892 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp NetProf_PrepProfiling\n" /* line 891 */
    );
}

/* line 1252 */
__attribute__((naked))
int NET_CompareAdrSigned(netadr_t *a, netadr_t *b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1252 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* a */
        "movl 0xc(%ebp), %edi\n" /* b */
        "movl (%ecx), %eax\n" /* line 1254 */
        "movl (%edi), %edx\n" /* b */
        "cmpl %edx, %eax\n"
        "je .Lf157db4_00157dd8\n"
        "subl %edx, %eax\n" /* line 1255 */
        "movl %eax, -0x2c(%ebp)\n"
        ".Lf157db4_00157dd0:\n"
        "addl $0x5c, %esp\n" /* line 1278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf157db4_00157dd8:\n"
        "cmpl $2, %eax\n" /* line 1257 */
        "je .Lf157db4_00157dee\n"
        "cmpl $4, %eax\n" /* line 1260 */
        "je .Lf157db4_00157e00\n"
        "movl $str_002ab150, (%esp)\n" /* line 1276 */
        "calll Com_Printf\n"
        ".Lf157db4_00157dee:\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "addl $0x5c, %esp\n" /* line 1278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf157db4_00157e00:\n"
        "movzwl 8(%ecx), %edx\n" /* line 1262 */
        "movzwl 8(%edi), %eax\n" /* b */
        "cmpw %ax, %dx\n"
        "je .Lf157db4_00157e22\n"
        "movzwl %dx, %edx\n" /* line 1263 */
        "movzwl %ax, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl %edx, %eax\n"
        "addl $0x5c, %esp\n" /* line 1278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf157db4_00157e22:\n"
        "addl $4, %ecx\n" /* line 1264 */
        "movl %ecx, -0x1c(%ebp)\n"
        "addl $4, %edi\n" /* b */
        "movl %edi, -0x2c(%ebp)\n" /* b */
        "movl $4, %ebx\n"
        "cld\n"
        "movl %ecx, %esi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* b */
        "movl $0, %eax\n"
        "je .Lf157db4_00157e4b\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n" /* b */
        "subl %ecx, %eax\n"
        ".Lf157db4_00157e4b:\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf157db4_00157dd0\n"
    );
}

/* line 1293 */
qboolean NET_IsLocalAddress(netadr_t adr)
{
    if (adr.type == 2 || adr.type == 0)
        return 1;
    return 0;
}

/* line 1308 */
qboolean NET_GetPacket(netadr_t *net_from, msg_t *net_message)
{
    return Sys_GetPacket(net_from, net_message);
}

/* line 126 */
__attribute__((naked))
const char * NET_AdrToString(netadr_t a)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 126 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movzbl 0xc(%ebp), %edi\n"
        "movzbl 0xd(%ebp), %esi\n"
        "movzbl 0xe(%ebp), %ebx\n"
        "movzbl 0xf(%ebp), %ecx\n"
        "movl 0x10(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* a */
        /* { scope 1 */
        "cmpl $2, %edx\n" /* line 130 */
        "je .Lf157e76_00157efe\n"
        "cmpl $4, %edx\n" /* line 134 */
        "je .Lf157e76_00157eac\n"
        /* } scope */
        "movl $s, %eax\n" /* line 146 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf157e76_00157eac:\n"
        "rolw $8, %ax\n" /* line 925 */
        "cwtl\n" /* line 136 */
        "movl %eax, 0x1c(%esp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movzbl %bl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a91dc, 8(%esp)\n" /* "%i.%i.%i.%i:%i" */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        /* } scope */
        "movl $s, %eax\n" /* line 146 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf157e76_00157efe:\n"
        "movl $str_002ab178, 8(%esp)\n" /* line 132 */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        /* } scope */
        "movl $s, %eax\n" /* line 146 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1617 */
__attribute__((naked))
qboolean NET_StringToAdr(const char *s, netadr_t *a)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1617 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* a */
        /* { scope 1 */
        "movl $str_002a8ab8, %edi\n" /* line 1623 */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* s, port */
        "repe cmpsb %es:(%edi), (%esi)\n" /* port */
        "movl $0, %edx\n"
        "je .Lf157f28_00157f58\n"
        "movzbl -1(%esi), %edx\n" /* port */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf157f28_00157f58:\n"
        "testl %edx, %edx\n"
        "jne .Lf157f28_00157f80\n"
        "movl $0, 4(%ebx)\n" /* line 1625 | a */
        "movl $0, 8(%ebx)\n" /* a */
        "movl $2, (%ebx)\n" /* line 1626 | a */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf157f28_00157f75:\n"
        "addl $0x41c, %esp\n" /* line 1664 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf157f28_00157f80:\n"
        "movl $0x400, 8(%esp)\n" /* line 1631 */
        "movl 8(%ebp), %eax\n" /* s */
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %edi\n" /* base */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x3a, 4(%esp)\n" /* line 1632 */
        "movl %edi, (%esp)\n"
        "calll strchr\n"
        "movl %eax, %esi\n" /* port */
        "testl %eax, %eax\n" /* line 1633 */
        "je .Lf157f28_00157fb9\n"
        "movb $0, (%eax)\n" /* line 1635 */
        "addl $1, %esi\n" /* line 1636 | port */
        ".Lf157f28_00157fb9:\n"
        "movl %ebx, 4(%esp)\n" /* line 1639 | a */
        "movl %edi, (%esp)\n"
        "calll Sys_StringToAdr\n"
        "testl %eax, %eax\n" /* line 1641 */
        "je .Lf157f28_00157ff3\n"
        "cmpl $-1, 4(%ebx)\n" /* line 1648 | a */
        "je .Lf157f28_00158004\n"
        "testl %esi, %esi\n" /* line 1654 | port */
        "je .Lf157f28_00158011\n"
        "movl %esi, (%esp)\n" /* line 1656 | port */
        "calll atoi\n"
        "rolw $8, %ax\n" /* line 46 */
        "movw %ax, 8(%ebx)\n" /* line 1656 | a */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1664 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf157f28_00157ff3:\n"
        "movl $1, (%ebx)\n" /* line 1643 | a */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 1664 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf157f28_00158004:\n"
        "movl $1, (%ebx)\n" /* line 1650 | a */
        "xorl %eax, %eax\n"
        "jmp .Lf157f28_00157f75\n"
        ".Lf157f28_00158011:\n"
        "movw $0x2071, 8(%ebx)\n" /* line 1660 | a */
        "movl $1, %eax\n"
        "jmp .Lf157f28_00157f75\n"
    );
}

/* line 1389 */
__attribute__((naked))
Bool NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1389 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x1c(%ebp), %eax\n"
        "movw %ax, -0x2a(%ebp)\n"
        "movzbl 0x1b(%ebp), %esi\n" /* port */
        "movzbl 0x1a(%ebp), %edi\n"
        "movzbl 0x19(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl 0x18(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movl 0x14(%ebp), %ebx\n" /* to, loop */
        "movl showpackets, %eax\n" /* line 1392 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf158022_00158062\n"
        "movl 0x10(%ebp), %eax\n" /* data */
        "cmpl $-1, (%eax)\n"
        "je .Lf158022_00158145\n"
        ".Lf158022_00158062:\n"
        "cmpl $2, %ebx\n" /* line 1395 | loop */
        "je .Lf158022_001580cc\n"
        "cmpl $1, %ebx\n" /* line 1400 | loop */
        "je .Lf158022_00158070\n"
        "testl %ebx, %ebx\n" /* line 1404 | loop */
        "jne .Lf158022_0015807a\n"
        ".Lf158022_00158070:\n"
        "xorl %eax, %eax\n" /* line 1409 */
        "addl $0x4c, %esp\n" /* line 1410 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf158022_0015807a:\n"
        "movzwl -0x2a(%ebp), %eax\n" /* line 1409 */
        "movw %ax, -0x1c(%ebp)\n"
        "movl %esi, %eax\n" /* port */
        "movb %al, -0x1d(%ebp)\n"
        "movl %edi, %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x2b(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x2c(%ebp), %eax\n"
        "movb %al, -0x20(%ebp)\n"
        "movl %ebx, -0x24(%ebp)\n" /* loop */
        "movl %ebx, 8(%esp)\n" /* loop */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* length */
        "movl %eax, (%esp)\n"
        "calll Sys_SendPacket\n"
        "movzbl %al, %eax\n"
        "addl $0x4c, %esp\n" /* line 1410 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf158022_001580cc:\n"
        "movl 8(%ebp), %eax\n" /* line 1368 | sock */
        "testl %eax, %eax\n"
        "jle .Lf158022_0015816e\n"
        "cmpl $1, %eax\n" /* line 1373 */
        "je .Lf158022_00158165\n"
        ".Lf158022_001580e0:\n"
        "xorl %esi, %esi\n" /* port */
        ".Lf158022_001580e2:\n"
        "leal (%eax, %eax, 4), %ebx\n" /* line 1376 | loop */
        "leal (%eax, %ebx, 2), %ebx\n" /* loop */
        "shll $8, %ebx\n" /* loop */
        "addl %eax, %ebx\n" /* loop */
        "leal loopbacks(, %ebx, 8), %ebx\n" /* loop */
        "movl 0x5804(%ebx), %eax\n" /* line 1378 | loop */
        "movl %eax, %edx\n"
        "andl $0xf, %edx\n"
        "addl $1, %eax\n" /* line 1379 */
        "movl %eax, 0x5804(%ebx)\n" /* loop */
        "leal (%edx, %edx, 4), %eax\n" /* line 1381 */
        "leal (%edx, %eax, 2), %eax\n"
        "shll $7, %eax\n"
        "addl %eax, %ebx\n" /* loop */
        "movl 0xc(%ebp), %eax\n" /* length */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* loop */
        "calll memcpy\n"
        "movl 0xc(%ebp), %eax\n" /* line 1382 | length */
        "movl %eax, 0x578(%ebx)\n" /* loop */
        "movl %esi, 0x57c(%ebx)\n" /* line 1383 | port, loop */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1410 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf158022_00158145:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1393 | length */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002ab184, (%esp)\n" /* "[client %i] send packet %4i
" */
        "calll Com_Printf\n"
        "jmp .Lf158022_00158062\n"
        /* { scope 1 */
        ".Lf158022_00158165:\n"
        "movzwl -0x2a(%ebp), %eax\n" /* line 1373 */
        "jmp .Lf158022_001580e0\n"
        ".Lf158022_0015816e:\n"
        "movl %eax, %esi\n" /* line 1368 | port */
        "movl $1, %eax\n"
        "jmp .Lf158022_001580e2\n"
    );
}

/* line 1569 */
__attribute__((naked))
void NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, byte *format, int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1569 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x804c, %esp\n"
        "movl 0x1c(%ebp), %ebx\n" /* len */
        "movl 0x14(%ebp), %edi\n"
        "movzbl 0x13(%ebp), %eax\n" /* format */
        "movb %al, -0x8029(%ebp)\n" /* format */
        "movzbl 0x12(%ebp), %eax\n" /* format */
        "movb %al, -0x802a(%ebp)\n" /* format */
        "movzbl 0x11(%ebp), %eax\n" /* format */
        "movb %al, -0x802b(%ebp)\n" /* format */
        "movzbl 0x10(%ebp), %eax\n" /* format */
        "movb %al, -0x802c(%ebp)\n" /* format */
        "movl 0xc(%ebp), %esi\n" /* adr */
        /* { scope 1 */
        "movb $0xff, -0x8024(%ebp)\n" /* line 1575 | string */
        "movb $0xff, -0x8023(%ebp)\n" /* line 1576 */
        "movb $0xff, -0x8022(%ebp)\n" /* line 1577 */
        "movb $0xff, -0x8021(%ebp)\n" /* line 1578 */
        "leal -0x8020(%ebp), %edx\n" /* line 1581 */
        "movl %ebx, 8(%esp)\n" /* len */
        "movl 0x18(%ebp), %eax\n" /* format */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl $4, %ebx\n" /* line 1584 | len */
        "movw %di, -0x1c(%ebp)\n" /* line 1596 */
        "movzbl -0x8029(%ebp), %eax\n"
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x802a(%ebp), %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x802b(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x802c(%ebp), %eax\n"
        "movb %al, -0x20(%ebp)\n"
        "movl %esi, -0x24(%ebp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x8024(%ebp), %eax\n" /* string */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* len */
        "movl 8(%ebp), %eax\n" /* sock */
        "movl %eax, (%esp)\n"
        "calll NET_SendPacket\n"
        "cmpl $1, 8(%ebp)\n" /* line 1601 | sock */
        "je .Lf15817a_00158262\n"
        "movl %ebx, (%esp)\n" /* line 1605 | len */
        "calll CL_Netchan_AddOOBProfilePacket\n"
        /* } scope */
        "addl $0x804c, %esp\n" /* line 1607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15817a_00158262:\n"
        "movl %ebx, (%esp)\n" /* line 1602 | len */
        "calll SV_Netchan_AddOOBProfilePacket\n"
        /* } scope */
        "addl $0x804c, %esp\n" /* line 1607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1520 */
__attribute__((naked))
Bool NET_OutOfBandData(netsrc_t sock, netadr_t adr, byte *format, int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1520 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x1c(%ebp), %esi\n" /* len */
        "movl 0x14(%ebp), %eax\n"
        "movw %ax, -0x2a(%ebp)\n"
        "movzbl 0x13(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl 0x12(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movzbl 0x11(%ebp), %eax\n"
        "movb %al, -0x2d(%ebp)\n"
        "movzbl 0x10(%ebp), %eax\n"
        "movb %al, -0x2e(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* adr */
        "movl %edi, -0x3c(%ebp)\n"
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 1525 */
        "leal -0x1c(%ebp), %eax\n" /* string_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edi\n" /* string_large_local */
        "movl %edi, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %ebx\n" /* string */
        "movb $0xff, (%eax)\n" /* line 1528 */
        "movb $0xff, 1(%eax)\n" /* line 1529 */
        "movb $0xff, 2(%eax)\n" /* line 1530 */
        "movb $0xff, 3(%eax)\n" /* line 1531 */
        "testl %esi, %esi\n" /* line 1533 | len */
        "jle .Lf158276_001582f6\n"
        "movl %eax, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf158276_001582e2:\n"
        "movl 0x18(%ebp), %edi\n" /* line 1535 | format */
        "movzbl (%edi, %ecx), %eax\n"
        "movb %al, 4(%edx)\n"
        "addl $1, %ecx\n" /* line 1533 */
        "addl $1, %edx\n"
        "cmpl %ecx, %esi\n" /* len */
        "jne .Lf158276_001582e2\n"
        ".Lf158276_001582f6:\n"
        "addl $4, %esi\n" /* line 1539 | len */
        "movzwl -0x2a(%ebp), %eax\n" /* line 1548 */
        "movw %ax, -0x20(%ebp)\n"
        "movzbl -0x2b(%ebp), %eax\n"
        "movb %al, -0x21(%ebp)\n"
        "movzbl -0x2c(%ebp), %eax\n"
        "movb %al, -0x22(%ebp)\n"
        "movzbl -0x2d(%ebp), %eax\n"
        "movb %al, -0x23(%ebp)\n"
        "movzbl -0x2e(%ebp), %eax\n"
        "movb %al, -0x24(%ebp)\n"
        "movl -0x3c(%ebp), %edi\n"
        "movl %edi, -0x28(%ebp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* string */
        "movl %esi, 4(%esp)\n" /* len */
        "movl 8(%ebp), %eax\n" /* sock */
        "movl %eax, (%esp)\n"
        "calll NET_SendPacket\n"
        "movzbl %al, %ebx\n" /* string */
        "cmpl $1, 8(%ebp)\n" /* line 1552 | sock */
        "je .Lf158276_00158373\n"
        "movl %esi, (%esp)\n" /* line 1556 | len */
        "calll CL_Netchan_AddOOBProfilePacket\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1559 | string_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* string */
        "setg %al\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1560 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf158276_00158373:\n"
        "movl %esi, (%esp)\n" /* line 1553 | len */
        "calll SV_Netchan_AddOOBProfilePacket\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1559 | string_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* string */
        "setg %al\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1560 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* string */
        /* { scope 1 */
        "leal -0x1c(%ebp), %edi\n" /* line 1559 | string_large_local */
        "movl %edi, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* string */
        "calll __Unwind_Resume\n"
    );
}

/* line 1465 */
__attribute__((naked))
Bool NET_OutOfBandPrint(netsrc_t sock, netadr_t adr, const char *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1465 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x18(%ebp), %esi\n" /* data */
        "movl 0x14(%ebp), %eax\n"
        "movw %ax, -0x2a(%ebp)\n"
        "movzbl 0x13(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl 0x12(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movzbl 0x11(%ebp), %eax\n"
        "movb %al, -0x2d(%ebp)\n"
        "movzbl 0x10(%ebp), %eax\n"
        "movb %al, -0x2e(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* adr */
        "movl %eax, -0x34(%ebp)\n"
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 1469 */
        "leal -0x1c(%ebp), %eax\n" /* string_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %eax\n" /* string_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %ebx\n" /* string */
        "movb $0xff, (%eax)\n" /* line 1472 */
        "movb $0xff, 1(%eax)\n" /* line 1473 */
        "movb $0xff, 2(%eax)\n" /* line 1474 */
        "movb $0xff, 3(%eax)\n" /* line 1475 */
        "movl showpackets, %eax\n" /* line 1477 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1583aa_00158429\n"
        "movl %esi, 4(%esp)\n" /* line 1479 | iLength */
        "movl $str_002ab1a4, (%esp)\n" /* "OOB Print: %s
" */
        "calll Com_DPrintf\n"
        ".Lf1583aa_00158429:\n"
        "cld\n" /* line 1482 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* iLength */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "cmpl $0x3ffc, %ecx\n"
        "jbe .Lf1583aa_00158469\n"
        "movl %eax, 4(%esp)\n" /* line 1484 */
        "movl $str_002ab1b4, (%esp)\n" /* "OOB Packet is %i bytes - too large to send
" */
        "calll Com_DPrintf\n"
        "xorl %ebx, %ebx\n" /* line 1509 | string */
        "leal -0x1c(%ebp), %eax\n" /* string_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1510 | string */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1583aa_00158469:\n"
        "leal 4(%ebx), %eax\n" /* line 1489 | string */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* iLength */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cld\n" /* line 1492 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* string */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* iLength */
        "movzwl -0x2a(%ebp), %eax\n" /* line 1498 */
        "movw %ax, -0x20(%ebp)\n"
        "movzbl -0x2b(%ebp), %eax\n"
        "movb %al, -0x21(%ebp)\n"
        "movzbl -0x2c(%ebp), %eax\n"
        "movb %al, -0x22(%ebp)\n"
        "movzbl -0x2d(%ebp), %eax\n"
        "movb %al, -0x23(%ebp)\n"
        "movzbl -0x2e(%ebp), %eax\n"
        "movb %al, -0x24(%ebp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* string */
        "movl %esi, 4(%esp)\n" /* iLength */
        "movl 8(%ebp), %eax\n" /* sock */
        "movl %eax, (%esp)\n"
        "calll NET_SendPacket\n"
        "movzbl %al, %ebx\n" /* string */
        "cmpl $1, 8(%ebp)\n" /* line 1502 | sock */
        "je .Lf1583aa_0015850a\n"
        "movl %esi, (%esp)\n" /* line 1506 | iLength */
        "calll CL_Netchan_AddOOBProfilePacket\n"
        ".Lf1583aa_001584ed:\n"
        "testl %ebx, %ebx\n" /* line 1509 | string */
        "setg %al\n"
        "movzbl %al, %ebx\n" /* string */
        "leal -0x1c(%ebp), %eax\n" /* string_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1510 | string */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1583aa_0015850a:\n"
        "movl %esi, (%esp)\n" /* line 1503 | iLength */
        "calll SV_Netchan_AddOOBProfilePacket\n"
        "jmp .Lf1583aa_001584ed\n"
        "movl %eax, %ebx\n" /* string */
        "leal -0x1c(%ebp), %eax\n" /* line 1509 | string_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* string */
        "calll __Unwind_Resume\n"
    );
}

/* line 1281 */
__attribute__((naked))
qboolean NET_CompareAdr(netadr_t a, netadr_t b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1281 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 1254 | a */
        "movl 0x14(%ebp), %edx\n" /* b */
        "cmpl %edx, %eax\n"
        "je .Lf15852c_00158555\n"
        "subl %edx, %eax\n" /* line 1255 */
        "movl %eax, -0x2c(%ebp)\n"
        ".Lf15852c_00158544:\n"
        "xorl %eax, %eax\n" /* line 1276 */
        "cmpl $0, -0x2c(%ebp)\n"
        "sete %al\n"
        "addl $0x5c, %esp\n" /* line 1284 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf15852c_00158555:\n"
        "cmpl $2, %eax\n" /* line 1257 */
        "je .Lf15852c_0015856b\n"
        "cmpl $4, %eax\n" /* line 1260 */
        "je .Lf15852c_00158583\n"
        "movl $str_002ab150, (%esp)\n" /* line 1276 */
        "calll Com_Printf\n"
        ".Lf15852c_0015856b:\n"
        "movl $0, -0x2c(%ebp)\n"
        "xorl %eax, %eax\n"
        "cmpl $0, -0x2c(%ebp)\n"
        "sete %al\n"
        "addl $0x5c, %esp\n" /* line 1284 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf15852c_00158583:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1262 */
        "movl 0x1c(%ebp), %eax\n"
        "cmpw %ax, %dx\n"
        "je .Lf15852c_001585aa\n"
        "movzwl %dx, %edx\n" /* line 1263 */
        "movzwl %ax, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "xorl %eax, %eax\n" /* line 1276 */
        "cmpl $0, -0x2c(%ebp)\n"
        "sete %al\n"
        "addl $0x5c, %esp\n" /* line 1284 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf15852c_001585aa:\n"
        "movl $4, %ebx\n" /* line 1264 */
        "cld\n"
        "leal 0xc(%ebp), %esi\n"
        "leal 0x18(%ebp), %edi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf15852c_001585cb\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf15852c_001585cb:\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf15852c_00158544\n"
    );
}

/* line 1246 */
__attribute__((naked))
qboolean NET_CompareBaseAdr(netadr_t a, netadr_t b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %edx\n" /* line 1217 | a */
        "movl 0x14(%ebp), %eax\n" /* b */
        "cmpl %eax, %edx\n"
        "je .Lf1585d4_001585fd\n"
        ".Lf1585d4_001585e7:\n"
        "subl %eax, %edx\n" /* line 1224 */
        "movl %edx, -0x2c(%ebp)\n"
        ".Lf1585d4_001585ec:\n"
        "xorl %eax, %eax\n" /* line 1234 */
        "cmpl $0, -0x2c(%ebp)\n"
        "sete %al\n"
        "addl $0x5c, %esp\n" /* line 1249 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1585d4_001585fd:\n"
        "cmpl $2, %edx\n" /* line 1220 */
        "je .Lf1585d4_0015862a\n"
        "testl %edx, %edx\n" /* line 1223 */
        "je .Lf1585d4_00158620\n"
        "cmpl $4, %edx\n" /* line 1226 */
        "je .Lf1585d4_0015863a\n"
        "movl $str_002ab124, (%esp)\n" /* line 1234 */
        "calll Com_Printf\n"
        "movl $0, -0x2c(%ebp)\n"
        "jmp .Lf1585d4_001585ec\n"
        ".Lf1585d4_00158620:\n"
        "movzwl 0x10(%ebp), %edx\n" /* line 1224 */
        "movzwl 0x1c(%ebp), %eax\n"
        "jmp .Lf1585d4_001585e7\n"
        ".Lf1585d4_0015862a:\n"
        "movzwl 0x10(%ebp), %eax\n" /* line 1221 */
        "movl %eax, -0x2c(%ebp)\n"
        "movzwl 0x1c(%ebp), %eax\n"
        "subl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1585d4_001585ec\n"
        ".Lf1585d4_0015863a:\n"
        "movl $4, %ebx\n" /* line 1227 */
        "cld\n"
        "leal 0xc(%ebp), %esi\n"
        "leal 0x18(%ebp), %edi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1585d4_0015865b\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1585d4_0015865b:\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1585d4_001585ec\n"
    );
}

/* line 1349 */
__attribute__((naked))
qboolean NET_GetLoopPacket(netsrc_t sock, netadr_t *net_from, msg_t *net_message)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1349 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* sock */
        "movl 0xc(%ebp), %edi\n" /* net_from */
        /* { scope 1 */
        "leal (%eax, %eax, 4), %edx\n" /* line 1329 */
        "leal (%eax, %edx, 2), %edx\n"
        "shll $8, %edx\n"
        "addl %eax, %edx\n"
        "leal loopbacks(, %edx, 8), %esi\n" /* loop */
        "movl 0x5804(%esi), %edx\n" /* line 1331 | loop */
        "movl 0x5800(%esi), %ecx\n" /* loop */
        "movl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "cmpl $0x10, %eax\n"
        "jle .Lf158660_0015869f\n"
        "leal -0x10(%edx), %ecx\n" /* line 1332 */
        "movl %ecx, 0x5800(%esi)\n" /* loop */
        ".Lf158660_0015869f:\n"
        "cmpl 0x5804(%esi), %ecx\n" /* line 1334 | loop */
        "jl .Lf158660_001586b1\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1357 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf158660_001586b1:\n"
        "movl %ecx, %edx\n" /* line 1337 */
        "andl $0xf, %edx\n"
        "leal 1(%ecx), %eax\n" /* line 1338 */
        "movl %eax, 0x5800(%esi)\n" /* loop */
        "movl 0x10(%ebp), %eax\n" /* line 1340 | net_message */
        "movl 4(%eax), %ecx\n"
        "leal (%edx, %edx, 4), %ebx\n"
        "leal (%edx, %ebx, 2), %ebx\n"
        "shll $7, %ebx\n"
        "addl %esi, %ebx\n" /* loop */
        "movl 0x578(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x578(%ebx), %eax\n" /* line 1341 */
        "movl 0x10(%ebp), %edx\n" /* net_message */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 4(%edi)\n" /* line 1342 */
        "movl $0, 8(%edi)\n"
        "movl $2, (%edi)\n" /* line 1343 */
        "movl 0x57c(%ebx), %eax\n" /* line 1344 */
        "movw %ax, 8(%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1357 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 902 */
__attribute__((naked))
Bool Netchan_TransmitNextFragment(netchan_t *chan)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 902 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5dc, %esp\n"
        "movl 8(%ebp), %edi\n" /* chan */
        /* { scope 1: iSize */
        "leal 0x8034(%edi), %eax\n" /* line 909 | chan */
        "movl %eax, (%esp)\n"
        "calll NetProf_PrepProfiling\n"
        "movl $0x578, 8(%esp)\n" /* line 912 */
        "leal -0x5b4(%ebp), %eax\n" /* send_buf */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* send, pPacket */
        "movl %ebx, (%esp)\n" /* pPacket */
        "calll MSG_Init\n"
        "movl (%edi), %eax\n" /* line 914 | chan */
        "orl $0x80000000, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pPacket */
        "calll MSG_WriteLong\n"
        "movl 4(%edi), %eax\n" /* line 918 | chan */
        "testl %eax, %eax\n"
        "jle .Lf15871e_0015898f\n"
        ".Lf15871e_00158776:\n"
        "movl 0x402c(%edi), %edx\n" /* line 926 | chan */
        "movl 0x4030(%edi), %ecx\n" /* chan */
        "leal 0x514(%edx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jg .Lf15871e_0015886d\n"
        "movl $0x514, -0x5c4(%ebp)\n" /* fragmentLength */
        ".Lf15871e_0015879a:\n"
        "movl %edx, 4(%esp)\n" /* line 931 */
        "movl %ebx, (%esp)\n" /* pPacket */
        "calll MSG_WriteShort\n"
        "movl -0x5c4(%ebp), %eax\n" /* line 932 | fragmentLength */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pPacket */
        "calll MSG_WriteShort\n"
        "movl -0x5c4(%ebp), %eax\n" /* line 933 | fragmentLength */
        "movl %eax, 8(%esp)\n"
        "movl 0x402c(%edi), %eax\n" /* chan */
        "leal 0x4034(%edi, %eax), %eax\n" /* chan */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pPacket */
        "calll MSG_WriteData\n"
        "movl 0x10(%edi), %ecx\n" /* line 943 | chan */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x14(%edi), %edx\n" /* chan */
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x18(%edi), %eax\n" /* chan */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* chan */
        "movl %eax, (%esp)\n"
        "calll NET_SendPacket\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x5c0(%ebp)\n" /* res */
        "movl -0x30(%ebp), %eax\n" /* line 946 */
        "movl %eax, -0x5bc(%ebp)\n" /* iSize */
        "movl net_iProfilingOn, %eax\n" /* line 229 */
        "testl %eax, %eax\n"
        "jne .Lf15871e_001588f5\n"
        ".Lf15871e_00158831:\n"
        "movl showpackets, %eax\n" /* line 948 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf15871e_001588aa\n"
        ".Lf15871e_0015883c:\n"
        "movl -0x5c4(%ebp), %eax\n" /* line 953 | fragmentLength */
        "addl 0x402c(%edi), %eax\n" /* chan */
        "movl %eax, 0x402c(%edi)\n" /* chan */
        "cmpl 0x4030(%edi), %eax\n" /* line 959 | chan */
        "je .Lf15871e_0015887a\n"
        ".Lf15871e_00158856:\n"
        "xorl %eax, %eax\n" /* line 962 */
        "cmpl $0, -0x5c0(%ebp)\n" /* res */
        "setg %al\n"
        /* } scope */
        "addl $0x5dc, %esp\n" /* line 966 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf15871e_0015886d:\n"
        "subl %edx, %ecx\n" /* line 928 */
        "movl %ecx, -0x5c4(%ebp)\n" /* fragmentLength */
        "jmp .Lf15871e_0015879a\n"
        ".Lf15871e_0015887a:\n"
        "cmpl $0x514, -0x5c4(%ebp)\n" /* line 959 | fragmentLength */
        "je .Lf15871e_00158856\n"
        "addl $1, (%edi)\n" /* line 961 | chan */
        "movl $0, 0x4028(%edi)\n" /* line 962 | chan */
        "xorl %eax, %eax\n"
        "cmpl $0, -0x5c0(%ebp)\n" /* res */
        "setg %al\n"
        /* } scope */
        "addl $0x5dc, %esp\n" /* line 966 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf15871e_001588aa:\n"
        "movl -0x5c4(%ebp), %eax\n" /* line 950 | fragmentLength */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x402c(%edi), %eax\n" /* chan */
        "movl %eax, 0x14(%esp)\n"
        "movl (%edi), %eax\n" /* chan */
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 4(%edi), %eax\n" /* chan */
        "movl netsrcString(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002ab210, (%esp)\n" /* "[client %i] %s send %4i : s=%i fragment=%i,%i
" */
        "calll Com_Printf\n"
        "jmp .Lf15871e_0015883c\n"
        ".Lf15871e_001588f5:\n"
        "movl 0x8034(%edi), %esi\n" /* line 235 | pProfStream */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x2d0(%esi), %ecx\n" /* line 211 */
        "addl $1, %ecx\n"
        "movl $0x88888889, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "leal (%edx, %ecx), %ebx\n" /* pPacket */
        "sarl $5, %ebx\n" /* pPacket */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* pPacket */
        "leal (, %ebx, 4), %edx\n"
        "movl %ebx, %eax\n" /* pPacket */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl %ecx, %ebx\n" /* pPacket */
        "subl %eax, %ebx\n" /* pPacket */
        "movl %ebx, 0x2d0(%esi)\n" /* pPacket */
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 213 | pPacket */
        "leal (%esi, %ebx, 4), %ebx\n" /* pPacket */
        "calll Sys_Milliseconds\n" /* line 216 */
        "movl %eax, (%ebx)\n" /* pPacket */
        "movl -0x5bc(%ebp), %eax\n" /* line 217 | iSize */
        "movl %eax, 4(%ebx)\n" /* pPacket */
        "movl $1, 8(%ebx)\n" /* line 218 | pPacket */
        /* } scope */
        /* } scope */
        "movl net_showprofile, %eax\n" /* line 237 */
        "testb $2, 8(%eax)\n"
        "je .Lf15871e_00158831\n"
        "movl -0x5bc(%ebp), %eax\n" /* line 238 | iSize */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002ab1e0, 8(%esp)\n" /* " fragment" */
        "movl 4(%edi), %eax\n"
        "movl netsrcString(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab1ec, (%esp)\n" /* "%s send%s: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf15871e_00158831\n"
        ".Lf15871e_0015898f:\n"
        "movl 0x1c(%edi), %eax\n" /* line 920 | chan */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pPacket */
        "calll MSG_WriteShort\n"
        "jmp .Lf15871e_00158776\n"
    );
}

/* line 977 */
__attribute__((naked))
Bool Netchan_Transmit(netchan_t *chan, int length, const byte *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 977 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5dc, %esp\n"
        "movl 8(%ebp), %edi\n" /* chan */
        "movl 0xc(%ebp), %ebx\n" /* length */
        /* { scope 1: iSize */
        "cmpl $0x4000, %ebx\n" /* line 983 | length */
        "jg .Lf1589a4_00158b05\n"
        ".Lf1589a4_001589c2:\n"
        "movl $0, 0x402c(%edi)\n" /* line 987 | chan */
        "cmpl $0x513, %ebx\n" /* line 990 | length */
        "jle .Lf1589a4_00158a15\n"
        "movl $1, 0x4028(%edi)\n" /* line 992 | chan */
        "movl %ebx, 0x4030(%edi)\n" /* line 993 | length, chan */
        "movl %ebx, 8(%esp)\n" /* line 994 | length */
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "leal 0x4034(%edi), %eax\n" /* chan */
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl %edi, (%esp)\n" /* line 997 | chan */
        "calll Netchan_TransmitNextFragment\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5dc, %esp\n" /* line 1043 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf1589a4_00158a15:\n"
        "leal 0x8034(%edi), %eax\n" /* line 1002 | chan */
        "movl %eax, (%esp)\n"
        "calll NetProf_PrepProfiling\n"
        "movl $0x578, 8(%esp)\n" /* line 1005 */
        "leal -0x5b4(%ebp), %eax\n" /* send_buf */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %esi\n" /* send, pProfStream */
        "movl %esi, (%esp)\n" /* pProfStream */
        "calll MSG_Init\n"
        "movl (%edi), %eax\n" /* line 1007 | chan */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pProfStream */
        "calll MSG_WriteLong\n"
        "addl $1, (%edi)\n" /* line 1008 | chan */
        "movl 4(%edi), %eax\n" /* line 1012 | chan */
        "testl %eax, %eax\n"
        "jle .Lf1589a4_00158c4d\n"
        ".Lf1589a4_00158a5c:\n"
        "movl packetDebug, %eax\n" /* line 1018 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1589a4_00158b69\n"
        "movl %ebx, 8(%esp)\n" /* line 1021 | length */
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pProfStream */
        "calll MSG_WriteData\n"
        "movl packetDebug, %eax\n" /* line 1023 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1589a4_00158b9b\n"
        ".Lf1589a4_00158a8d:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1034 | chan */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x14(%edi), %edx\n" /* chan */
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x18(%edi), %eax\n" /* chan */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* chan */
        "movl %eax, (%esp)\n"
        "calll NET_SendPacket\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x5c0(%ebp)\n" /* res */
        "movl -0x30(%ebp), %eax\n" /* line 1037 */
        "movl %eax, -0x5bc(%ebp)\n" /* iSize */
        "movl net_iProfilingOn, %eax\n" /* line 229 */
        "testl %eax, %eax\n"
        "jne .Lf1589a4_00158bb3\n"
        ".Lf1589a4_00158ae3:\n"
        "movl showpackets, %eax\n" /* line 1039 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1589a4_00158b22\n"
        "xorl %eax, %eax\n" /* line 1042 */
        "cmpl $0, -0x5c0(%ebp)\n" /* res */
        "setg %al\n"
        /* } scope */
        ".Lf1589a4_00158afa:\n"
        "addl $0x5dc, %esp\n" /* line 1043 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf1589a4_00158b05:\n"
        "movl %ebx, 8(%esp)\n" /* line 985 | length */
        "movl $str_002ab240, 4(%esp)\n" /* "Netchan_Transmit: length = %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1589a4_001589c2\n"
        ".Lf1589a4_00158b22:\n"
        "movl 0xc(%edi), %eax\n" /* line 1040 | chan */
        "movl %eax, 0x14(%esp)\n"
        "movl (%edi), %eax\n" /* chan */
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 4(%edi), %eax\n" /* chan */
        "movl netsrcString(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002ab29c, (%esp)\n" /* "[client %i] %s send %4i : s=%i ack=%i
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n" /* line 1042 */
        "cmpl $0, -0x5c0(%ebp)\n" /* res */
        "setg %al\n"
        "jmp .Lf1589a4_00158afa\n"
        ".Lf1589a4_00158b69:\n"
        "movl %ebx, 4(%esp)\n" /* line 1019 | length */
        "movl $str_002ab260, (%esp)\n" /* "Adding %i byte payload to packet
" */
        "calll Com_Printf\n"
        "movl %ebx, 8(%esp)\n" /* line 1021 | length */
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pProfStream */
        "calll MSG_WriteData\n"
        "movl packetDebug, %eax\n" /* line 1023 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1589a4_00158a8d\n"
        ".Lf1589a4_00158b9b:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1024 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab284, (%esp)\n" /* "Sending %i byte packet
" */
        "calll Com_Printf\n"
        "jmp .Lf1589a4_00158a8d\n"
        ".Lf1589a4_00158bb3:\n"
        "movl 0x8034(%edi), %esi\n" /* line 235 | pProfStream */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x2d0(%esi), %ecx\n" /* line 211 */
        "addl $1, %ecx\n"
        "movl $0x88888889, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "leal (%edx, %ecx), %ebx\n" /* pPacket */
        "sarl $5, %ebx\n" /* pPacket */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* pPacket */
        "leal (, %ebx, 4), %edx\n"
        "movl %ebx, %eax\n" /* pPacket */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl %ecx, %ebx\n" /* pPacket */
        "subl %eax, %ebx\n" /* pPacket */
        "movl %ebx, 0x2d0(%esi)\n" /* pPacket */
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 213 | pPacket */
        "leal (%esi, %ebx, 4), %ebx\n" /* pPacket */
        "calll Sys_Milliseconds\n" /* line 216 */
        "movl %eax, (%ebx)\n" /* pPacket */
        "movl -0x5bc(%ebp), %eax\n" /* line 217 | iSize */
        "movl %eax, 4(%ebx)\n" /* pPacket */
        "movl $0, 8(%ebx)\n" /* line 218 | pPacket */
        /* } scope */
        /* } scope */
        "movl net_showprofile, %eax\n" /* line 237 */
        "testb $2, 8(%eax)\n"
        "je .Lf1589a4_00158ae3\n"
        "movl -0x5bc(%ebp), %eax\n" /* line 238 | iSize */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl 4(%edi), %eax\n"
        "movl netsrcString(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab1ec, (%esp)\n" /* "%s send%s: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1589a4_00158ae3\n"
        ".Lf1589a4_00158c4d:\n"
        "movl 0x1c(%edi), %eax\n" /* line 1014 | chan */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pProfStream */
        "calll MSG_WriteShort\n"
        "jmp .Lf1589a4_00158a5c\n"
    );
}

/* line 1058 */
__attribute__((naked))
qboolean Netchan_Process(netchan_t *chan, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1058 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* chan */
        /* { scope 1: iSize */
        "leal 0x8034(%edi), %eax\n" /* line 1067 | chan */
        "movl %eax, (%esp)\n"
        "calll NetProf_PrepProfiling\n"
        "movl 0xc(%ebp), %eax\n" /* line 1073 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_BeginReading\n"
        "movl 0xc(%ebp), %edx\n" /* line 1074 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, -0x34(%ebp)\n" /* sequence */
        "testl %eax, %eax\n" /* line 1077 */
        "js .Lf158c62_00158fd5\n"
        "movl $0, -0x28(%ebp)\n" /* fragmented */
        "cmpl $1, 4(%edi)\n" /* line 1089 | chan */
        "je .Lf158c62_00158fed\n"
        ".Lf158c62_00158cae:\n"
        "movl -0x28(%ebp), %esi\n" /* line 1096 | fragmented, pProfStream */
        "testl %esi, %esi\n" /* pProfStream */
        "jne .Lf158c62_00158fb4\n"
        "movl $0, -0x30(%ebp)\n" /* fragmentStart */
        "movl $0, -0x2c(%ebp)\n" /* fragmentLength */
        ".Lf158c62_00158cc7:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1107 | msg */
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* iSize */
        "movl net_iProfilingOn, %ebx\n" /* line 249 | pPacket */
        "testl %ebx, %ebx\n" /* pPacket */
        "jne .Lf158c62_00158f10\n"
        ".Lf158c62_00158cde:\n"
        "movl showpackets, %eax\n" /* line 1109 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf158c62_00158d27\n"
        "movl -0x28(%ebp), %ecx\n" /* line 1111 | fragmented */
        "testl %ecx, %ecx\n"
        "jne .Lf158c62_00158eca\n"
        "movl -0x34(%ebp), %ecx\n" /* line 1114 | sequence */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 4(%edi), %eax\n" /* chan */
        "movl netsrcString(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002ab2f4, (%esp)\n" /* "[client %i] %s recv %4i : s=%i
" */
        "calll Com_Printf\n"
        ".Lf158c62_00158d27:\n"
        "movl 0xc(%edi), %ebx\n" /* line 1120 | chan, pPacket */
        "cmpl %ebx, -0x34(%ebp)\n" /* pPacket, sequence */
        "jg .Lf158c62_00158d9e\n"
        "movl showdrop, %eax\n" /* line 1122 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf158c62_00158eb1\n"
        ".Lf158c62_00158d3e:\n"
        "movzwl 0x18(%edi), %edx\n" /* line 1123 | chan */
        "movzbl 0x17(%edi), %ecx\n" /* chan */
        "movzbl 0x16(%edi), %esi\n" /* chan, pProfStream */
        "movzbl 0x15(%edi), %eax\n" /* chan */
        "movb %al, -0x1f(%ebp)\n"
        "movzbl 0x14(%edi), %eax\n" /* chan */
        "movb %al, -0x20(%ebp)\n"
        "movl 0x10(%edi), %eax\n" /* chan */
        "cmpl $2, %eax\n" /* line 130 */
        "je .Lf158c62_0015912c\n"
        "cmpl $4, %eax\n" /* line 134 */
        "je .Lf158c62_0015914d\n"
        ".Lf158c62_00158d6d:\n"
        "movl %ebx, 0x10(%esp)\n" /* line 1123 | pPacket */
        "movl -0x34(%ebp), %ecx\n" /* sequence */
        "movl %ecx, 0xc(%esp)\n"
        "movl $s, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002ab314, (%esp)\n" /* "[client %i] %s:Out of order packet %i at %i
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf158c62_00158d96:\n"
        "addl $0x4c, %esp\n" /* line 1203 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf158c62_00158d9e:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1130 | sequence */
        "subl %ebx, %eax\n" /* pPacket */
        "leal -1(%eax), %ebx\n" /* pPacket */
        "movl %ebx, 8(%edi)\n" /* pPacket, chan */
        "testl %ebx, %ebx\n" /* line 1131 | pPacket */
        "jle .Lf158c62_00158e12\n"
        "movl showdrop, %eax\n" /* line 1133 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf158c62_00158ffd\n"
        ".Lf158c62_00158dbc:\n"
        "movzwl 0x18(%edi), %eax\n" /* line 1134 | chan */
        "movzbl 0x17(%edi), %ecx\n" /* chan */
        "movzbl 0x16(%edi), %esi\n" /* chan, pProfStream */
        "movzbl 0x15(%edi), %edx\n" /* chan */
        "movb %dl, -0x1d(%ebp)\n"
        "movzbl 0x14(%edi), %edx\n" /* chan */
        "movb %dl, -0x1e(%ebp)\n"
        "movl 0x10(%edi), %edx\n" /* chan */
        "cmpl $2, %edx\n" /* line 130 */
        "je .Lf158c62_001591ce\n"
        "cmpl $4, %edx\n" /* line 134 */
        "je .Lf158c62_001591ef\n"
        ".Lf158c62_00158deb:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1134 | sequence */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* pPacket */
        "movl $s, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002ab344, (%esp)\n" /* "[client %i] %s: Dropped %i packets at %i
" */
        "calll Com_Printf\n"
        ".Lf158c62_00158e12:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1141 | fragmented */
        "testl %edx, %edx\n"
        "jne .Lf158c62_00158e2c\n"
        ".Lf158c62_00158e19:\n"
        "movl -0x34(%ebp), %edx\n" /* line 1200 | sequence */
        "movl %edx, 0xc(%edi)\n" /* chan */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1203 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf158c62_00158e2c:\n"
        "movl -0x34(%ebp), %edx\n" /* line 1144 | sequence */
        "cmpl 0x20(%edi), %edx\n" /* chan */
        "je .Lf158c62_00158e3e\n"
        "movl %edx, 0x20(%edi)\n" /* line 1146 | chan */
        "movl $0, 0x24(%edi)\n" /* line 1147 | chan */
        ".Lf158c62_00158e3e:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 1151 | fragmentStart */
        "cmpl 0x24(%edi), %ecx\n" /* chan */
        "je .Lf158c62_00159011\n"
        "movl showdrop, %eax\n" /* line 1153 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf158c62_00158e60\n"
        "movl showpackets, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf158c62_00158ec0\n"
        ".Lf158c62_00158e60:\n"
        "movzwl 0x18(%edi), %edx\n" /* line 1154 | chan */
        "movzbl 0x17(%edi), %ecx\n" /* chan */
        "movzbl 0x16(%edi), %ebx\n" /* chan, pPacket */
        "movzbl 0x15(%edi), %esi\n" /* chan, pProfStream */
        "movzbl 0x14(%edi), %eax\n" /* chan */
        "movb %al, -0x1c(%ebp)\n"
        "movl 0x10(%edi), %eax\n" /* chan */
        "cmpl $2, %eax\n" /* line 130 */
        "je .Lf158c62_00159239\n"
        "cmpl $4, %eax\n" /* line 134 */
        "je .Lf158c62_0015925a\n"
        ".Lf158c62_00158e8c:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 1154 | sequence */
        "movl %ecx, 8(%esp)\n"
        "movl $s, 4(%esp)\n"
        "movl $str_002ab370, (%esp)\n" /* "%s:Dropped a message fragment
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1203 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf158c62_00158eb1:\n"
        "movl showpackets, %eax\n" /* line 1122 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf158c62_00158d3e\n"
        ".Lf158c62_00158ec0:\n"
        "xorl %eax, %eax\n" /* line 1202 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1203 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iSize */
        ".Lf158c62_00158eca:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1112 | fragmentLength */
        "movl %edx, 0x18(%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* fragmentStart */
        "movl %ecx, 0x14(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* sequence */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 4(%edi), %eax\n" /* chan */
        "movl netsrcString(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002ab2c4, (%esp)\n" /* "[client %i] %s recv %4i : s=%i fragment=%i,%i
" */
        "calll Com_Printf\n"
        "jmp .Lf158c62_00158d27\n"
        ".Lf158c62_00158f10:\n"
        "movl 0x8034(%edi), %esi\n" /* line 255 | pProfStream */
        "addl $0x2f0, %esi\n" /* pProfStream */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x2d0(%esi), %ecx\n" /* line 211 */
        "addl $1, %ecx\n"
        "movl $0x88888889, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "leal (%edx, %ecx), %ebx\n" /* pPacket */
        "sarl $5, %ebx\n" /* pPacket */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* pPacket */
        "leal (, %ebx, 4), %edx\n"
        "movl %ebx, %eax\n" /* pPacket */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl %ecx, %ebx\n" /* pPacket */
        "subl %eax, %ebx\n" /* pPacket */
        "movl %ebx, 0x2d0(%esi)\n" /* pPacket */
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 213 | pPacket */
        "leal (%esi, %ebx, 4), %ebx\n" /* pPacket */
        "calll Sys_Milliseconds\n" /* line 216 */
        "movl %eax, (%ebx)\n" /* pPacket */
        "movl -0x24(%ebp), %edx\n" /* line 217 | iSize */
        "movl %edx, 4(%ebx)\n" /* pPacket */
        "movl -0x28(%ebp), %ecx\n" /* line 218 | fragmented */
        "movl %ecx, 8(%ebx)\n" /* pPacket */
        /* } scope */
        /* } scope */
        "movl net_showprofile, %eax\n" /* line 257 */
        "testb $2, 8(%eax)\n"
        "je .Lf158c62_00158cde\n"
        "movl $str_002ab1e0, %edx\n" /* line 258 */
        "testl %ecx, %ecx\n"
        "movl $str_002157b8, %eax\n"
        "cmovel %eax, %edx\n"
        "movl -0x24(%ebp), %eax\n" /* iSize */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl 4(%edi), %eax\n"
        "movl netsrcString(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab1fc, (%esp)\n" /* "%s recieve%s: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf158c62_00158cde\n"
        ".Lf158c62_00158fb4:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1098 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadShort\n"
        "movl %eax, -0x30(%ebp)\n" /* fragmentStart */
        "movl 0xc(%ebp), %edx\n" /* line 1099 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadShort\n"
        "movl %eax, -0x2c(%ebp)\n" /* fragmentLength */
        "jmp .Lf158c62_00158cc7\n"
        ".Lf158c62_00158fd5:\n"
        "andl $0x7fffffff, -0x34(%ebp)\n" /* line 1079 | sequence */
        "movl $1, -0x28(%ebp)\n" /* fragmented */
        "cmpl $1, 4(%edi)\n" /* line 1089 | chan */
        "jne .Lf158c62_00158cae\n"
        ".Lf158c62_00158fed:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1091 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadShort\n"
        "jmp .Lf158c62_00158cae\n"
        ".Lf158c62_00158ffd:\n"
        "movl showpackets, %eax\n" /* line 1133 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf158c62_00158e12\n"
        "jmp .Lf158c62_00158dbc\n"
        ".Lf158c62_00159011:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1161 | fragmentLength */
        "testl %eax, %eax\n"
        "js .Lf158c62_001590d6\n"
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl 0x10(%eax), %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* fragmentLength */
        "addl %edx, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* msg */
        "cmpl 0xc(%ecx), %eax\n"
        "jg .Lf158c62_001590d6\n"
        "movl -0x30(%ebp), %eax\n" /* fragmentStart */
        "addl -0x2c(%ebp), %eax\n" /* fragmentLength */
        "cmpl $0x4000, %eax\n"
        "ja .Lf158c62_001590d6\n"
        "leal 0x28(%edi), %esi\n" /* line 1168 | chan, pProfStream */
        "movl -0x30(%ebp), %ecx\n" /* fragmentStart */
        "leal (%esi, %ecx), %eax\n" /* pProfStream */
        "movl 0xc(%ebp), %ecx\n" /* msg */
        "addl 4(%ecx), %edx\n"
        "movl -0x2c(%ebp), %ecx\n" /* fragmentLength */
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 1170 | fragmentLength, pPacket */
        "addl 0x24(%edi), %ebx\n" /* chan, pPacket */
        "movl %ebx, 0x24(%edi)\n" /* pPacket, chan */
        "cmpl $0x514, -0x2c(%ebp)\n" /* line 1173 | fragmentLength */
        "je .Lf158c62_00158ec0\n"
        "movl 0xc(%ebp), %eax\n" /* line 1178 | msg */
        "cmpl 8(%eax), %ebx\n" /* pPacket */
        "jle .Lf158c62_001592f0\n"
        "movzwl 0x18(%edi), %edx\n" /* line 1180 | chan */
        "movzbl 0x17(%edi), %ecx\n" /* chan */
        "movzbl 0x16(%edi), %esi\n" /* chan, pProfStream */
        "movzbl 0x15(%edi), %eax\n" /* chan */
        "movb %al, -0x19(%ebp)\n"
        "movzbl 0x14(%edi), %eax\n" /* chan */
        "movb %al, -0x1a(%ebp)\n"
        "movl 0x10(%edi), %eax\n" /* chan */
        "cmpl $2, %eax\n" /* line 130 */
        "je .Lf158c62_0015933e\n"
        "cmpl $4, %eax\n" /* line 134 */
        "je .Lf158c62_0015935f\n"
        ".Lf158c62_001590b7:\n"
        "movl %ebx, 8(%esp)\n" /* line 1180 | pPacket */
        "movl $s, 4(%esp)\n"
        "movl $str_002ab3ac, (%esp)\n" /* "%s:fragmentLength %i > msg->maxsize
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf158c62_00158d96\n"
        ".Lf158c62_001590d6:\n"
        "movl showdrop, %eax\n" /* line 1163 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf158c62_00159199\n"
        ".Lf158c62_001590e5:\n"
        "movzwl 0x18(%edi), %edx\n" /* line 1164 | chan */
        "movzbl 0x17(%edi), %ecx\n" /* chan */
        "movzbl 0x16(%edi), %ebx\n" /* chan, pPacket */
        "movzbl 0x15(%edi), %esi\n" /* chan, pProfStream */
        "movzbl 0x14(%edi), %eax\n" /* chan */
        "movb %al, -0x1b(%ebp)\n"
        "movl 0x10(%edi), %eax\n" /* chan */
        "cmpl $2, %eax\n" /* line 130 */
        "je .Lf158c62_001591ad\n"
        "cmpl $4, %eax\n" /* line 134 */
        "je .Lf158c62_001592a5\n"
        ".Lf158c62_00159111:\n"
        "movl $s, 4(%esp)\n" /* line 1164 */
        "movl $str_002ab390, (%esp)\n" /* "%s:illegal fragment length
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf158c62_00158d96\n"
        ".Lf158c62_0015912c:\n"
        "movl $str_002ab178, 8(%esp)\n" /* line 132 */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00158d6d\n"
        ".Lf158c62_0015914d:\n"
        "rolw $8, %dx\n" /* line 925 */
        "movswl %dx, %eax\n" /* line 136 */
        "movl %eax, 0x1c(%esp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %esi, %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl -0x1f(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a91dc, 8(%esp)\n" /* "%i.%i.%i.%i:%i" */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00158d6d\n"
        ".Lf158c62_00159199:\n"
        "movl showpackets, %eax\n" /* line 1163 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf158c62_001590e5\n"
        "jmp .Lf158c62_00158ec0\n"
        ".Lf158c62_001591ad:\n"
        "movl $str_002ab178, 8(%esp)\n" /* line 132 */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00159111\n"
        ".Lf158c62_001591ce:\n"
        "movl $str_002ab178, 8(%esp)\n" /* "loopback" */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00158deb\n"
        ".Lf158c62_001591ef:\n"
        "rolw $8, %ax\n" /* line 925 */
        "cwtl\n" /* line 136 */
        "movl %eax, 0x1c(%esp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %esi, %ecx\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl -0x1d(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x1e(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a91dc, 8(%esp)\n" /* "%i.%i.%i.%i:%i" */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00158deb\n"
        ".Lf158c62_00159239:\n"
        "movl $str_002ab178, 8(%esp)\n" /* line 132 */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00158e8c\n"
        ".Lf158c62_0015925a:\n"
        "rolw $8, %dx\n" /* line 925 */
        "movswl %dx, %eax\n" /* line 136 */
        "movl %eax, 0x1c(%esp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movzbl %bl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a91dc, 8(%esp)\n" /* "%i.%i.%i.%i:%i" */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00158e8c\n"
        ".Lf158c62_001592a5:\n"
        "rolw $8, %dx\n" /* line 925 */
        "movswl %dx, %eax\n" /* line 136 */
        "movl %eax, 0x1c(%esp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movzbl %bl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x1b(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a91dc, 8(%esp)\n" /* "%i.%i.%i.%i:%i" */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_00159111\n"
        ".Lf158c62_001592f0:\n"
        "movl %eax, %ecx\n"
        "movl 4(%eax), %eax\n" /* line 1187 */
        "movl -0x34(%ebp), %edx\n" /* sequence */
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 1189 */
        "addl $4, %edx\n"
        "movl 0x24(%edi), %eax\n" /* chan */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pProfStream */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x24(%edi), %eax\n" /* line 1190 | chan */
        "addl $4, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* msg */
        "movl %eax, 0xc(%ecx)\n"
        "movl $0, 0x24(%edi)\n" /* line 1191 | chan */
        "movl %ecx, (%esp)\n" /* line 1193 */
        "calll MSG_BeginReading\n"
        "movl 0xc(%ebp), %eax\n" /* line 1194 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "jmp .Lf158c62_00158e19\n"
        ".Lf158c62_0015933e:\n"
        "movl $str_002ab178, 8(%esp)\n" /* line 132 */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_001590b7\n"
        ".Lf158c62_0015935f:\n"
        "rolw $8, %dx\n" /* line 925 */
        "movswl %dx, %eax\n" /* line 136 */
        "movl %eax, 0x1c(%esp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %esi, %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a91dc, 8(%esp)\n" /* "%i.%i.%i.%i:%i" */
        "movl $0x40, 4(%esp)\n"
        "movl $s, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf158c62_001590b7\n"
    );
}

