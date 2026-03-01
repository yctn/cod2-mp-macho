/* ASM dump from: MacWinCursor.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacWinCursor.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacSwap.h"
 */

static EventLoopTimerRef sTimerRef; /* 0x334c14 */
static HCURSOR sCurrentWinCursor; /* 0x3080a4 */
static bool sVisibleCursor; /* 0x3080a0 */
static TCursorList sCursorList; /* 0x334c00 */
static WinCursor *sCurrentCursor; /* 0x334c0c */
static HCURSOR sSavedWinCursor; /* 0x334c10 */

bool WinIcon_Load(const WinIcon * _this, const UInt8 *inIcon);
HCURSOR SetWinCursor(HCURSOR hCursor);
void SwitchToWinCursor(void);
void SwitchToMacCursor(void);
void CursorTimerProc(void);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D_LoadCursorFromFileA(void); /* global destructors keyed to LoadCursorFromFileA */
static void GLOBAL__I_LoadCursorFromFileA(void); /* global constructors keyed to LoadCursorFromFileA */
void WinIcon_WinIcon(const WinIcon * _this);
bool WinCursor_ReadCursor(const WinCursor * _this, const UInt8 *inCursor);
bool WinCursor_Load(const WinCursor * _this, const char *inFileName);
HCURSOR LoadCursorFromFileA(LPCSTR lpFileName);
void ZN7WinIconD2Ev(void); /* WinIcon_~WinIcon */
void ZN7WinIconD1Ev(void); /* WinIcon_~WinIcon */
void WinCursor_WinCursor(const WinCursor * _this, const WinCursor *inCursor);
void ZN9WinCursorD2Ev(void); /* WinCursor_~WinCursor */
void ZN9WinCursorD1Ev(void); /* WinCursor_~WinCursor */
void ZNSt6vectorI9WinCursorSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void); /* std_vector<WinCursor, std_allocator<WinCursor> >__M_insert_aux */

/* line 295 */
__attribute__((naked))
bool WinIcon_Load(const WinIcon * _this, const UInt8 *inIcon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 295 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x148c, %esp\n"
        "movl $0, -0x146c(%ebp)\n"
        "movl 0xc(%ebp), %ebx\n" /* inIcon */
        /* { scope 1: y */
        "cmpw $0, (%ebx)\n" /* line 302 | inIcon */
        "jne .Lfc460_0000c48c\n"
        "movzwl 2(%ebx), %esi\n" /* line 310 | inIcon, signature */
        "leal -1(%esi), %eax\n" /* line 312 | signature */
        "cmpw $1, %ax\n"
        "jbe .Lfc460_0000c499\n"
        ".Lfc460_0000c48c:\n"
        "xorl %eax, %eax\n" /* line 519 */
        /* } scope */
        ".Lfc460_0000c48e:\n"
        "addl $0x148c, %esp\n" /* line 523 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: y */
        ".Lfc460_0000c499:\n"
        "cmpw $1, 4(%ebx)\n" /* line 322 | inIcon */
        "jne .Lfc460_0000c48c\n"
        "movzbl 7(%ebx), %eax\n" /* line 331 | inIcon, height */
        "movzbl 8(%ebx), %edx\n" /* line 332 | inIcon, colors */
        "cmpb $0x20, 6(%ebx)\n" /* line 334 | inIcon */
        "jne .Lfc460_0000c48c\n"
        "cmpb $0x20, %al\n"
        "jne .Lfc460_0000c48c\n"
        "testb %dl, %dl\n" /* line 339 */
        "jne .Lfc460_0000c48c\n"
        "movw $0, -0x24(%ebp)\n" /* line 348 | bounds */
        "movw $0, -0x22(%ebp)\n"
        "movw $0x20, -0x1e(%ebp)\n" /* line 349 */
        "movw $0x20, -0x20(%ebp)\n" /* line 350 */
        "movl $0, 0x14(%esp)\n" /* line 353 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* bounds, error */
        "movl %eax, 8(%esp)\n" /* error */
        "movl $0x20, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* theOffscreen, error */
        "movl %eax, (%esp)\n" /* error */
        "calll NewGWorld\n"
        "testw %ax, %ax\n" /* line 354 */
        "jne .Lfc460_0000c48c\n"
        "movl -0x1c(%ebp), %eax\n" /* line 359 | theOffscreen */
        "movl %eax, (%esp)\n"
        "calll GetGWorldPixMap\n"
        "movl %eax, %edi\n" /* thePixMap */
        "movl %eax, (%esp)\n" /* line 360 */
        "calll LockPixels\n"
        "cmpw $2, %si\n" /* line 365 | signature */
        "je .Lfc460_0000c6f8\n"
        "leal 0xe(%ebx), %edx\n" /* line 375 | inIcon */
        "movw $0, -0x1468(%ebp)\n" /* hotX */
        "movw $0, -0x1458(%ebp)\n" /* hotY */
        ".Lfc460_0000c539:\n"
        "movl %ebx, %eax\n" /* line 392 | inIcon */
        "addl 4(%edx), %eax\n"
        "leal 0x28(%eax), %esi\n" /* line 397 | signature */
        "cmpl $0x28, (%eax)\n" /* line 399 */
        "jne .Lfc460_0000c6e6\n"
        "movzwl 0xe(%eax), %ecx\n" /* line 409 */
        "movl $1, %ebx\n" /* numColors */
        "shll %cl, %ebx\n" /* numColors */
        "cmpl $0x100, %ebx\n" /* line 419 | numColors */
        "jg .Lfc460_0000c580\n"
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 421 | numColors */
        "jle .Lfc460_0000c580\n"
        /* } scope */
        "xorl %edx, %edx\n" /* line 419 */
        ".Lfc460_0000c563:\n"
        "movl (%esi), %eax\n" /* line 423 | signature */
        /* { scope 2 */
        "addl $4, %esi\n" /* line 424 | signature */
        "andl $0xffffff, %eax\n" /* line 426 */
        "subl $0x1000000, %eax\n"
        "movl %eax, -0x424(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 421 | i */
        "cmpl %edx, %ebx\n" /* i, numColors */
        "jne .Lfc460_0000c563\n"
        /* } scope */
        ".Lfc460_0000c580:\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 433 */
        "movl $0, 4(%esp)\n"
        "leal -0x1424(%ebp), %eax\n" /* theBitmap */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "cmpl $2, %ebx\n" /* line 437 | row */
        "je .Lfc460_0000c742\n"
        "cmpl $0x10, %ebx\n" /* line 451 | row */
        "je .Lfc460_0000c795\n"
        "cmpl $0x100, %ebx\n" /* line 464 | row */
        "jne .Lfc460_0000c6e6\n"
        "movl %esi, %ebx\n" /* signature, row */
        "movl $0x1f, -0x1434(%ebp)\n"
        ".Lfc460_0000c5c8:\n"
        "movl %ebx, %esi\n" /* row, signature */
        "movl -0x1434(%ebp), %eax\n"
        "shll $7, %eax\n"
        "leal -0x1424(%ebp), %edx\n" /* theBitmap */
        "addl %eax, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lfc460_0000c5dd:\n"
        "movzbl (%esi), %eax\n" /* line 470 | signature */
        "addl $1, %esi\n" /* signature */
        "movl -0x424(%ebp, %eax, 4), %eax\n" /* line 471 */
        "movl %eax, (%edx)\n"
        "addl $1, %ecx\n" /* line 468 */
        "addl $4, %edx\n"
        "cmpl $0x20, %ecx\n"
        "jne .Lfc460_0000c5dd\n"
        "leal 0x20(%ebx), %esi\n" /* row, signature */
        "subl $1, -0x1434(%ebp)\n" /* line 466 */
        "movl %esi, %ebx\n" /* signature, row */
        "cmpl $-1, -0x1434(%ebp)\n"
        "jne .Lfc460_0000c5c8\n"
        ".Lfc460_0000c60c:\n"
        "movl $0x1f, %ebx\n" /* line 479 | row */
        ".Lfc460_0000c611:\n"
        "movl (%esi), %edx\n" /* line 486 | signature */
        "addl $4, %esi\n" /* line 487 | signature */
        "movl %ebx, %eax\n" /* row */
        "shll $7, %eax\n"
        "leal -0x1424(%ebp), %ecx\n" /* theBitmap */
        "leal (%ecx, %eax), %eax\n"
        "movl $0x20, %ecx\n"
        ".Lfc460_0000c629:\n"
        "testb $1, %dl\n" /* line 490 */
        "je .Lfc460_0000c635\n"
        "movl $0, 0x7c(%eax)\n" /* line 492 */
        ".Lfc460_0000c635:\n"
        "shrl $1, %edx\n" /* line 494 */
        "subl $4, %eax\n"
        "subl $1, %ecx\n" /* line 488 */
        "jne .Lfc460_0000c629\n"
        "subl $1, %ebx\n" /* line 484 | row */
        "cmpl $-1, %ebx\n" /* row */
        "jne .Lfc460_0000c611\n"
        "movl %edi, (%esp)\n" /* line 500 | thePixMap */
        "calll GetPixRowBytes\n"
        "movl %eax, -0x1440(%ebp)\n" /* rowBytes */
        "movl $0, -0x143c(%ebp)\n" /* y */
        /* { scope 2 */
        ".Lfc460_0000c65f:\n"
        "movl -0x143c(%ebp), %esi\n" /* line 501 | y, signature */
        "imull -0x1440(%ebp), %esi\n" /* rowBytes, signature */
        "movl -0x143c(%ebp), %eax\n" /* y */
        "shll $7, %eax\n"
        "leal -0x1424(%ebp), %ebx\n" /* theBitmap, row */
        "addl %eax, %ebx\n" /* row */
        "xorl %ecx, %ecx\n"
        /* { scope 3 */
        ".Lfc460_0000c67f:\n"
        "movl (%edi), %eax\n" /* line 506 | thePixMap */
        "movl (%eax), %eax\n"
        "leal (%eax, %ecx, 4), %edx\n"
        "movl (%ebx), %eax\n" /* row */
        "movl %eax, (%edx, %esi)\n"
        "addl $1, %ecx\n" /* line 503 | x */
        "addl $4, %ebx\n" /* row */
        "cmpl $0x20, %ecx\n" /* x */
        "jne .Lfc460_0000c67f\n"
        /* } scope */
        "addl $1, -0x143c(%ebp)\n" /* line 501 | y */
        "cmpl $0x20, -0x143c(%ebp)\n" /* y */
        "jne .Lfc460_0000c65f\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1509 | this */
        "movl (%eax), %edx\n"
        "movl -0x1468(%ebp), %eax\n" /* line 514 | hotX */
        "shll $0x10, %eax\n"
        "movzwl -0x1458(%ebp), %ecx\n" /* hotY */
        "movl %ecx, -0x146c(%ebp)\n"
        "orl %eax, %ecx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* thePixMap */
        "calll QDRegisterNamedPixMapCursor\n"
        "testl %eax, %eax\n" /* line 515 */
        "jne .Lfc460_0000c6e6\n"
        "movb $1, %al\n"
        "jmp .Lfc460_0000c48e\n"
        ".Lfc460_0000c6e6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 517 | theOffscreen */
        "movl %eax, (%esp)\n"
        "calll DisposeGWorld\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc460_0000c48e\n"
        ".Lfc460_0000c6f8:\n"
        "movzwl 0xa(%ebx), %eax\n" /* line 367 | inIcon */
        "movw %ax, -0x1468(%ebp)\n" /* hotX */
        "movzwl 0xc(%ebx), %ecx\n" /* line 369 | inIcon */
        "movw %cx, -0x1458(%ebp)\n" /* hotY */
        "leal 0xe(%ebx), %edx\n" /* line 370 | inIcon */
        "cmpw $0x20, %ax\n" /* line 378 */
        "jbe .Lfc460_0000c720\n"
        "movw $0, -0x1468(%ebp)\n" /* hotX */
        ".Lfc460_0000c720:\n"
        "cmpw $0x21, -0x1458(%ebp)\n" /* line 382 | hotY */
        "movl $0, %eax\n"
        "movl -0x1458(%ebp), %ecx\n" /* hotY */
        "cmovael %eax, %ecx\n"
        "movw %cx, -0x1458(%ebp)\n" /* hotY */
        "jmp .Lfc460_0000c539\n"
        ".Lfc460_0000c742:\n"
        "movl $0x1f, -0x142c(%ebp)\n" /* line 437 */
        ".Lfc460_0000c74c:\n"
        "movl (%esi), %ecx\n" /* line 441 | signature */
        "addl $4, %esi\n" /* line 442 | signature */
        "movl -0x142c(%ebp), %eax\n"
        "shll $7, %eax\n"
        "leal -0x1424(%ebp), %edx\n" /* theBitmap */
        "addl %eax, %edx\n"
        "movl $0x20, %ebx\n" /* row */
        ".Lfc460_0000c767:\n"
        "movl %ecx, %eax\n" /* line 446 */
        "andl $1, %eax\n"
        "movl -0x424(%ebp, %eax, 4), %eax\n"
        "movl %eax, 0x7c(%edx)\n"
        "shrl $1, %ecx\n" /* line 447 */
        "subl $4, %edx\n"
        "subl $1, %ebx\n" /* line 444 | row */
        "jne .Lfc460_0000c767\n"
        "subl $1, -0x142c(%ebp)\n" /* line 439 */
        "cmpl $-1, -0x142c(%ebp)\n"
        "jne .Lfc460_0000c74c\n"
        "jmp .Lfc460_0000c60c\n"
        ".Lfc460_0000c795:\n"
        "movl %esi, -0x1438(%ebp)\n" /* line 451 | signature */
        "movl $0x1f, -0x1430(%ebp)\n"
        ".Lfc460_0000c7a5:\n"
        "movl -0x1430(%ebp), %eax\n"
        "shll $7, %eax\n"
        "leal -0x1424(%ebp), %ecx\n" /* theBitmap */
        "addl %eax, %ecx\n"
        "xorl %ebx, %ebx\n" /* row */
        ".Lfc460_0000c7b8:\n"
        "movzbl (%esi), %edx\n" /* line 457 | signature */
        "addl $1, %esi\n" /* signature */
        "movl %edx, %eax\n" /* line 459 */
        "shrl $4, %eax\n"
        "movl -0x424(%ebp, %eax, 4), %eax\n"
        "movl %eax, (%ecx)\n"
        "andl $0xf, %edx\n" /* line 460 */
        "movl -0x424(%ebp, %edx, 4), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "addl $2, %ebx\n" /* line 455 | row */
        "addl $8, %ecx\n"
        "cmpl $0x20, %ebx\n" /* row */
        "jne .Lfc460_0000c7b8\n"
        "movl -0x1438(%ebp), %esi\n" /* signature */
        "addl $0x10, %esi\n" /* signature */
        "subl $1, -0x1430(%ebp)\n" /* line 453 */
        "movl %esi, -0x1438(%ebp)\n" /* signature */
        "cmpl $-1, -0x1430(%ebp)\n"
        "je .Lfc460_0000c60c\n"
        "movl -0x1438(%ebp), %esi\n" /* signature */
        "jmp .Lfc460_0000c7a5\n"
    );
}

/* line 172 */
__attribute__((naked))
HCURSOR SetWinCursor(HCURSOR hCursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* hCursor */
        /* { scope 1: theCursor */
        "movl sCurrentWinCursor, %edi\n" /* line 180 */
        "cmpl %ecx, %edi\n"
        "je .Lfc810_0000c832\n"
        "movl sSavedWinCursor, %edx\n" /* line 186 */
        "testl %edx, %edx\n"
        "je .Lfc810_0000c83c\n"
        "movl %ecx, %edi\n"
        /* } scope */
        ".Lfc810_0000c832:\n"
        "movl %edi, %eax\n" /* line 243 */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: theCursor */
        ".Lfc810_0000c83c:\n"
        "movl %ecx, sCurrentWinCursor\n" /* line 192 */
        "testl %ecx, %ecx\n" /* line 196 */
        "je .Lfc810_0000c930\n"
        "movl sCursorList, %eax\n" /* line 334 */
        "movl %eax, %ebx\n" /* line 210 */
        "movl 0x334c04, %esi\n" /* line 603 */
        "cmpl %eax, %esi\n" /* line 210 */
        "je .Lfc810_0000c90d\n"
        "cmpl (%eax), %ecx\n" /* line 212 */
        "je .Lfc810_0000c87a\n"
        "leal 0x44(%eax), %edx\n"
        ".Lfc810_0000c866:\n"
        "addl $0x44, %ebx\n" /* line 623 */
        "cmpl %esi, %ebx\n" /* line 210 */
        "je .Lfc810_0000c90d\n"
        "movl (%edx), %eax\n" /* line 598 */
        "addl $0x44, %edx\n"
        "cmpl %eax, %ecx\n" /* line 212 */
        "jne .Lfc810_0000c866\n"
        ".Lfc810_0000c87a:\n"
        "movl $0, 0x38(%ebx)\n" /* line 866 */
        "calll TickCount\n" /* line 868 */
        "movl 0x38(%ebx), %ecx\n"
        "movl 0x34(%ebx), %edx\n"
        "addl (%edx, %ecx, 4), %eax\n"
        "movl %eax, 0x3c(%ebx)\n"
        "movb $1, 0x40(%ebx)\n" /* line 869 */
        "movl (%edx, %ecx, 4), %edx\n" /* line 530 */
        "movl 0x2c(%ebx), %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll QDSetNamedPixMapCursor\n"
        "movl %ebx, sCurrentCursor\n" /* line 873 */
        ".Lfc810_0000c8ad:\n"
        "cmpb $0, sVisibleCursor\n" /* line 227 */
        "je .Lfc810_0000c922\n"
        ".Lfc810_0000c8b6:\n"
        "movl sTimerRef, %eax\n" /* line 235 */
        "testl %eax, %eax\n"
        "jne .Lfc810_0000c832\n"
        "calll GetMainEventLoop\n" /* line 237 */
        "movl $sTimerRef, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $CursorTimerProc, 0x14(%esp)\n"
        "movl $0x11111111, 0xc(%esp)\n"
        "movl $0x3f911111, 0x10(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventLoopTimer\n"
        "jmp .Lfc810_0000c832\n"
        /* { scope 2 */
        ".Lfc810_0000c90d:\n"
        "leal -0x5c(%ebp), %eax\n" /* line 222 | theCursor */
        "movl %eax, (%esp)\n"
        "calll GetQDGlobalsArrow\n"
        "movl %eax, (%esp)\n"
        "calll SetCursor\n"
        "jmp .Lfc810_0000c8ad\n"
        /* } scope */
        ".Lfc810_0000c922:\n"
        "calll ShowCursor\n" /* line 229 */
        "movb $1, sVisibleCursor\n" /* line 230 */
        "jmp .Lfc810_0000c8b6\n"
        ".Lfc810_0000c930:\n"
        "cmpb $0, sVisibleCursor\n" /* line 198 */
        "je .Lfc810_0000c832\n"
        "calll HideCursor\n" /* line 200 */
        "movb $0, sVisibleCursor\n" /* line 201 */
        "jmp .Lfc810_0000c832\n"
    );
}

/* line 261 */
__attribute__((naked))
void SwitchToWinCursor(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 261 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl sSavedWinCursor, %eax\n" /* line 265 | saveWinCursor */
        "movl $0, sSavedWinCursor\n" /* line 266 */
        "movl %eax, (%esp)\n" /* line 267 */
        "calll SetWinCursor\n"
        /* } scope */
        "leave\n" /* line 269 */
        "retl\n"
    );
}

/* line 250 */
__attribute__((naked))
void SwitchToMacCursor(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 250 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sSavedWinCursor, %ecx\n" /* line 252 */
        "testl %ecx, %ecx\n"
        "je .Lfc96e_0000c980\n"
        "leave\n" /* line 256 */
        "retl\n"
        ".Lfc96e_0000c980:\n"
        "movl $0xffffffff, (%esp)\n" /* line 254 */
        "calll SetWinCursor\n"
        "movl %eax, sSavedWinCursor\n"
        "leave\n" /* line 256 */
        "retl\n"
    );
}

/* line 112 */
__attribute__((naked))
void CursorTimerProc(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 112 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl sCurrentCursor, %ebx\n" /* line 114 */
        "testl %ebx, %ebx\n"
        "je .Lfc994_0000c9ae\n"
        "movl sSavedWinCursor, %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc994_0000c9b4\n"
        ".Lfc994_0000c9ae:\n"
        "addl $0x14, %esp\n" /* line 118 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc994_0000c9b4:\n"
        "cmpl $1, 0xc(%ebx)\n" /* line 881 */
        "jbe .Lfc994_0000ca04\n"
        /* { scope 1 */
        ".Lfc994_0000c9ba:\n"
        "calll TickCount\n" /* line 883 */
        "movl %eax, %ecx\n" /* now */
        "cmpl 0x3c(%ebx), %eax\n" /* line 884 */
        "jb .Lfc994_0000c9ae\n"
        "movl 0x38(%ebx), %edx\n" /* line 886 */
        "addl $1, %edx\n"
        "movl %edx, 0x38(%ebx)\n"
        "cmpl 0x10(%ebx), %edx\n"
        "jb .Lfc994_0000c9dd\n"
        "xorl %edx, %edx\n" /* line 888 */
        "movl $0, 0x38(%ebx)\n"
        ".Lfc994_0000c9dd:\n"
        "movl 0x30(%ebx), %eax\n" /* line 891 */
        "addl (%eax, %edx, 4), %ecx\n"
        "movl %ecx, 0x3c(%ebx)\n"
        "movl 0x34(%ebx), %eax\n" /* line 530 */
        "movl (%eax, %edx, 4), %edx\n"
        "movl 0x2c(%ebx), %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll QDSetNamedPixMapCursor\n"
        "movb $0, 0x40(%ebx)\n" /* line 895 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 118 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc994_0000ca04:\n"
        "cmpb $0, 0x40(%ebx)\n" /* line 881 */
        "jne .Lfc994_0000c9ba\n"
        "jmp .Lfc994_0000c9ae\n"
    );
}

/* line 898 */
__attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 898 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 105 */
        "je .Lfca0c_0000ca25\n"
        ".Lfca0c_0000ca1d:\n"
        "addl $0x3c, %esp\n" /* line 898 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfca0c_0000ca25:\n"
        "cmpl $1, %eax\n" /* line 105 */
        "je .Lfca0c_0000ca72\n"
        "testl %eax, %eax\n"
        "jne .Lfca0c_0000ca1d\n"
        "movl 0x334c04, %edi\n" /* line 273 */
        "movl sCursorList, %eax\n"
        "movl %eax, %ebx\n"
        "cmpl %eax, %edi\n" /* line 173 */
        "je .Lfca0c_0000ca5e\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        ".Lfca0c_0000ca47:\n"
        "movl 4(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        "cmpl -0x2c(%ebp), %esi\n" /* line 224 */
        "jne .Lfca0c_0000ca98\n"
        ".Lfca0c_0000ca52:\n"
        "addl $0x44, %ebx\n" /* line 173 */
        "cmpl %ebx, %edi\n"
        "jne .Lfca0c_0000ca47\n"
        "movl sCursorList, %eax\n"
        ".Lfca0c_0000ca5e:\n"
        "testl %eax, %eax\n" /* line 122 */
        "je .Lfca0c_0000ca1d\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "addl $0x3c, %esp\n" /* line 898 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfca0c_0000ca72:\n"
        "movl $0, sCursorList\n" /* line 85 */
        "movl $0, 0x334c04\n"
        "movl $0, 0x334c08\n"
        "addl $0x3c, %esp\n" /* line 898 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfca0c_0000ca98:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfca0c_0000ca52\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfca0c_0000ca52\n"
        "movl %eax, %ebx\n"
        "movl sCursorList, %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lfca0c_0000cad3\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lfca0c_0000cad3:\n"
        "movl %ebx, (%esp)\n" /* line 109 */
        "calll __Unwind_Resume\n"
    );
}

/* line 900 */
__attribute__((naked))
void GLOBAL__D_LoadCursorFromFileA(void) /* global destructors keyed to LoadCursorFromFileA */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 900 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 899 */
__attribute__((naked))
void GLOBAL__I_LoadCursorFromFileA(void) /* global constructors keyed to LoadCursorFromFileA */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 899 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 275 */
__attribute__((naked))
void WinIcon_WinIcon(const WinIcon * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 275 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        /* { scope 1 */
        "leal 0xc(%esi), %eax\n" /* line 207 */
        /* } scope */
        /* { scope 1 */
        "movl %eax, (%ebx)\n" /* line 251 */
        /* } scope */
        /* { scope 1 */
        "movl __ZZN7WinIconC4EvE7sNextID, %edx\n" /* line 280 */
        "leal 1(%edx), %eax\n"
        "movl %eax, __ZZN7WinIconC4EvE7sNextID\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x215b90, 4(%esp)\n" /* "icon-%d" */
        "leal -0x99(%ebp), %eax\n" /* temp */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x99(%ebp), %edi\n" /* temp */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "leal -0x99(%ebp), %eax\n" /* temp */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 283 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %edi\n"
        "movl (%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 | this */
        /* { scope 1 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lfcb00_0000cb8b\n"
        /* } scope */
        ".Lfcb00_0000cb83:\n"
        "movl %edi, (%esp)\n" /* line 472 */
        "calll __Unwind_Resume\n"
        /* { scope 1 */
        ".Lfcb00_0000cb8b:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfcb00_0000cb83\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfcb00_0000cb83\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
    );
}

/* overload skip: WinIcon_WinIcon (0xcbbc) */

/* line 649 */
__attribute__((naked))
bool WinCursor_ReadCursor(const WinCursor * _this, const UInt8 *inCursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 649 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* inCursor */
        /* { scope 1 */
        "cmpl $0x52494646, (%eax)\n" /* line 656 */
        "je .Lfcc78_0000cc96\n"
        ".Lfcc78_0000cc8c:\n"
        "xorl %eax, %eax\n" /* line 858 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcc78_0000cc96:\n"
        "leal 8(%eax), %esi\n" /* line 664 | p */
        "addl 4(%eax), %eax\n" /* line 668 */
        "movl %eax, -0x34(%ebp)\n" /* endP */
        "cmpl %eax, %esi\n" /* line 669 | p */
        "jae .Lfcc78_0000cd9b\n"
        "movl (%esi), %eax\n" /* line 671 | p */
        "leal 4(%esi), %edx\n" /* line 672 | p */
        "movl %edx, -0x30(%ebp)\n"
        "cmpl $0x4c495354, %eax\n" /* line 674 */
        "je .Lfcc78_0000cde2\n"
        ".Lfcc78_0000ccba:\n"
        "jbe .Lfcc78_0000cdb1\n"
        "cmpl $0x6672616d, %eax\n"
        "je .Lfcc78_0000ce67\n"
        "ja .Lfcc78_0000ce0b\n"
        "cmpl $0x616e6968, %eax\n"
        "jne .Lfcc78_0000cc8c\n"
        "leal 8(%esi), %ecx\n" /* line 723 | p */
        "cmpl $0x24, 4(%esi)\n" /* line 725 | p */
        "jne .Lfcc78_0000cc8c\n"
        "movl 8(%esi), %edx\n" /* line 731 | p */
        "movl 8(%ebp), %edi\n" /* this */
        "movl %edx, 8(%edi)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "movl 8(%ecx), %ebx\n"
        "movl %ebx, 0x10(%edi)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 0x18(%edi)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, 0x1c(%edi)\n"
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, 0x20(%edi)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, 0x24(%edi)\n"
        "movl 0x20(%ecx), %eax\n"
        "movl %eax, 0x28(%edi)\n"
        "addl $0x2c, %esi\n" /* line 732 | p */
        "movl %esi, -0x30(%ebp)\n" /* p */
        "cmpl $0x24, %edx\n" /* line 742 */
        "jne .Lfcc78_0000cc8c\n"
        "testb $1, %al\n" /* line 747 */
        "je .Lfcc78_0000cc8c\n"
        "leal (, %ebx, 4), %eax\n" /* line 754 */
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, 0x30(%edi)\n"
        "movl 0x10(%edi), %eax\n" /* line 755 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, 0x34(%edi)\n"
        /* { scope 2 */
        "movl 0x10(%edi), %ebx\n" /* line 757 | i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lfcc78_0000cdc5\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lfcc78_0000cd76\n"
        ".Lfcc78_0000cd5f:\n"
        "movl 8(%ebp), %edi\n" /* line 767 | this */
        "addl 0x34(%edi), %ecx\n"
        "movl $0, (%ecx)\n"
        ".Lfcc78_0000cd6b:\n"
        "addl $1, %ebx\n" /* line 757 | i */
        "movl 8(%ebp), %eax\n" /* this */
        "cmpl 0x10(%eax), %ebx\n" /* i */
        "jae .Lfcc78_0000cdc5\n"
        ".Lfcc78_0000cd76:\n"
        "leal (, %ebx, 4), %ecx\n" /* line 759 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x30(%edx), %eax\n"
        "addl %ecx, %eax\n"
        "movl %edx, %esi\n" /* p */
        "movl 0x24(%edx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 0x10(%esi), %eax\n" /* line 761 | p */
        "cmpl %eax, 0xc(%esi)\n" /* p */
        "jne .Lfcc78_0000cd5f\n"
        "addl 0x34(%esi), %ecx\n" /* line 763 | p */
        "movl %ebx, (%ecx)\n" /* i */
        "jmp .Lfcc78_0000cd6b\n"
        /* } scope */
        ".Lfcc78_0000cd9b:\n"
        "movl 8(%ebp), %eax\n" /* line 858 | this */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcc78_0000cdb1:\n"
        "cmpl $0x49415254, %eax\n" /* line 674 */
        "je .Lfcc78_0000cdf7\n"
        "ja .Lfcc78_0000cdec\n"
        "cmpl $0x41434f4e, %eax\n"
        "jne .Lfcc78_0000cc8c\n"
        ".Lfcc78_0000cdc5:\n"
        "movl -0x30(%ebp), %edi\n"
        ".Lfcc78_0000cdc8:\n"
        "cmpl %edi, -0x34(%ebp)\n" /* line 669 | endP */
        "jbe .Lfcc78_0000cd9b\n"
        "movl %edi, %esi\n" /* p */
        "movl (%esi), %eax\n" /* line 671 | p */
        "leal 4(%esi), %edx\n" /* line 672 | p */
        "movl %edx, -0x30(%ebp)\n"
        "cmpl $0x4c495354, %eax\n" /* line 674 */
        "jne .Lfcc78_0000ccba\n"
        ".Lfcc78_0000cde2:\n"
        "addl $8, %esi\n" /* line 685 | p */
        "movl %esi, -0x30(%ebp)\n" /* p */
        "movl %esi, %edi\n" /* p */
        "jmp .Lfcc78_0000cdc8\n"
        ".Lfcc78_0000cdec:\n"
        "cmpl $0x494e414d, %eax\n" /* line 674 */
        "jne .Lfcc78_0000cf56\n"
        ".Lfcc78_0000cdf7:\n"
        "movl 4(%esi), %eax\n" /* line 715 | p */
        "addl $1, %eax\n"
        "andl $0xfffffffe, %eax\n"
        "leal 8(%esi, %eax), %eax\n" /* p */
        "movl %eax, -0x30(%ebp)\n"
        "movl %eax, %edi\n"
        "jmp .Lfcc78_0000cdc8\n"
        ".Lfcc78_0000ce0b:\n"
        "cmpl $0x72617465, %eax\n" /* line 674 */
        "je .Lfcc78_0000cf66\n"
        "cmpl $0x73657120, %eax\n"
        "jne .Lfcc78_0000cc8c\n"
        "addl $8, %esi\n" /* line 837 | p */
        "movl %esi, -0x30(%ebp)\n" /* p */
        /* { scope 2 */
        "movl 8(%ebp), %edi\n" /* line 840 | this */
        "movl 0x10(%edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfcc78_0000cfa4\n"
        "xorl %ecx, %ecx\n" /* i */
        "movl 8(%ebp), %edx\n" /* this */
        "movl -0x30(%ebp), %ebx\n" /* i */
        "jmp .Lfcc78_0000ce41\n"
        ".Lfcc78_0000ce3f:\n"
        "movl %esi, %edx\n" /* p */
        ".Lfcc78_0000ce41:\n"
        "leal (, %ecx, 4), %eax\n" /* line 842 */
        "addl 0x34(%edx), %eax\n"
        "movl (%ebx), %edx\n" /* line 46 */
        "movl %edx, (%eax)\n" /* line 842 */
        "addl $4, %ebx\n" /* line 843 | i */
        "movl %ebx, -0x30(%ebp)\n" /* i */
        "addl $1, %ecx\n" /* line 840 | i */
        "movl 8(%ebp), %esi\n" /* this, p */
        "cmpl 0x10(%esi), %ecx\n" /* p, i */
        "jb .Lfcc78_0000ce3f\n"
        "movl %ebx, %edi\n" /* i */
        "jmp .Lfcc78_0000cdc8\n"
        /* } scope */
        ".Lfcc78_0000ce67:\n"
        "movl 8(%ebp), %edx\n" /* line 775 | this */
        "movl 8(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfcc78_0000cc8c\n"
        "movl 0xc(%edx), %ecx\n" /* line 781 */
        "movl %ecx, -0x40(%ebp)\n"
        "leal 4(, %ecx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, -0x44(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x40(%ebp), %ebx\n" /* this */
        "movl -0x44(%ebp), %edi\n"
        "movl %ebx, (%edi)\n" /* this */
        "subl $1, %ebx\n" /* this */
        "movl %ebx, -0x38(%ebp)\n" /* this */
        "movl %eax, %edi\n"
        "cmpl $-1, %ebx\n" /* this */
        "je .Lfcc78_0000cec9\n"
        "movl %ebx, %ecx\n" /* this */
        "movl -0x40(%ebp), %ebx\n" /* line 858 | i */
        "subl $2, %ebx\n" /* i */
        "movl %ecx, -0x2c(%ebp)\n"
        ".Lfcc78_0000ceb3:\n"
        "movl %edi, (%esp)\n" /* line 781 */
        "calll WinIcon_WinIcon\n"
        "addl $4, %edi\n"
        "movl %ebx, -0x2c(%ebp)\n" /* this */
        "subl $1, %ebx\n" /* this */
        "cmpl $-2, %ebx\n" /* this */
        "jne .Lfcc78_0000ceb3\n"
        ".Lfcc78_0000cec9:\n"
        "movl -0x3c(%ebp), %edi\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %edi, 0x2c(%ebx)\n" /* this */
        /* { scope 2 */
        "movl 0xc(%ebx), %eax\n" /* line 783 | i */
        "testl %eax, %eax\n"
        "je .Lfcc78_0000cdc5\n"
        "movl -0x30(%ebp), %ebx\n" /* line 788 | i */
        "cmpl $0x69636f6e, (%ebx)\n" /* i */
        "jne .Lfcc78_0000cc8c\n"
        "cmpl $0x2fe, 8(%esi)\n" /* line 797 | p */
        "jne .Lfcc78_0000cc8c\n"
        "leal 0x30a(%esi), %eax\n" /* p */
        "xorl %ebx, %ebx\n" /* i */
        ".Lfcc78_0000cf01:\n"
        "movl %eax, -0x30(%ebp)\n" /* line 649 | inCursor */
        "movl 8(%ebp), %esi\n" /* line 804 | this, p */
        "movl 0x2c(%esi), %edx\n" /* p */
        "subl $0x2fe, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%edx, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll WinIcon_Load\n"
        "testb %al, %al\n"
        "je .Lfcc78_0000cc8c\n"
        "addl $1, %ebx\n" /* line 783 | i */
        "cmpl 0xc(%esi), %ebx\n" /* p, i */
        "jae .Lfcc78_0000cdc5\n"
        "movl -0x30(%ebp), %ecx\n" /* line 788 */
        "cmpl $0x69636f6e, (%ecx)\n"
        "jne .Lfcc78_0000cc8c\n"
        "movl %ecx, %eax\n" /* line 46 */
        "addl $0x306, %eax\n"
        "cmpl $0x2fe, 4(%ecx)\n" /* line 797 */
        "je .Lfcc78_0000cf01\n"
        "jmp .Lfcc78_0000cc8c\n"
        /* } scope */
        ".Lfcc78_0000cf56:\n"
        "cmpl $0x494e464f, %eax\n" /* line 674 */
        "jne .Lfcc78_0000cc8c\n"
        "jmp .Lfcc78_0000cdc5\n"
        ".Lfcc78_0000cf66:\n"
        "addl $8, %esi\n" /* line 820 | p */
        "movl %esi, -0x30(%ebp)\n" /* p */
        /* { scope 2 */
        "movl 8(%ebp), %edi\n" /* line 823 | this */
        "movl 0x10(%edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfcc78_0000cfa4\n"
        "xorl %ecx, %ecx\n" /* i */
        ".Lfcc78_0000cf78:\n"
        "leal (, %ecx, 4), %eax\n" /* line 825 */
        "movl 8(%ebp), %edx\n" /* this */
        "addl 0x30(%edx), %eax\n"
        "movl -0x30(%ebp), %ebx\n" /* line 46 */
        "movl (%ebx), %edx\n"
        "movl %edx, (%eax)\n" /* line 825 */
        "addl $4, %ebx\n" /* line 826 | i */
        "movl %ebx, -0x30(%ebp)\n" /* i */
        "addl $1, %ecx\n" /* line 823 | i */
        "movl 8(%ebp), %esi\n" /* this, p */
        "cmpl 0x10(%esi), %ecx\n" /* p, i */
        "jb .Lfcc78_0000cf78\n"
        "movl %ebx, %edi\n" /* i */
        "jmp .Lfcc78_0000cdc8\n"
        ".Lfcc78_0000cfa4:\n"
        "movl %esi, %edi\n" /* p */
        "jmp .Lfcc78_0000cdc8\n"
        "movl %eax, -0x48(%ebp)\n"
        /* } scope */
        "movl -0x3c(%ebp), %edx\n" /* line 781 */
        "testl %edx, %edx\n"
        "je .Lfcc78_0000cfe0\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl %eax, -0x40(%ebp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl -0x3c(%ebp), %ecx\n"
        "leal -4(%ecx, %edx, 4), %ebx\n" /* this */
        "cmpl %ecx, %ebx\n" /* this */
        "je .Lfcc78_0000cfe0\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n"
        ".Lfcc78_0000cfcf:\n"
        "subl $4, %ebx\n" /* this */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 3 */
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lfcc78_0000cff6\n"
        /* } scope */
        /* } scope */
        ".Lfcc78_0000cfdb:\n"
        "cmpl %ebx, -0x3c(%ebp)\n" /* line 781 | this */
        "jne .Lfcc78_0000cfcf\n"
        ".Lfcc78_0000cfe0:\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        "movl -0x48(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll __Unwind_Resume\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfcc78_0000cff6:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfcc78_0000cfdb\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfcc78_0000cfdb\n"
        "movl %eax, -0x48(%ebp)\n"
        "jmp .Lfcc78_0000cfe0\n"
    );
}

/* line 613 */
__attribute__((naked))
bool WinCursor_Load(const WinCursor * _this, const char *inFileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 613 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl $0x215b98, 4(%esp)\n" /* line 617 */
        "movl 0xc(%ebp), %eax\n" /* inFileName */
        "movl %eax, (%esp)\n"
        "calll fopen\n"
        "movl %eax, %esi\n" /* fp */
        "testl %eax, %eax\n" /* line 618 */
        "je .Lfd024_0000d0bc\n"
        /* { scope 2 */
        "movl $2, 8(%esp)\n" /* line 620 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n" /* result */
        "calll fseek\n"
        "testl %eax, %eax\n" /* line 621 */
        "je .Lfd024_0000d077\n"
        "xorl %ebx, %ebx\n" /* okay */
        ".Lfd024_0000d064:\n"
        "movl %esi, (%esp)\n" /* line 637 | fp */
        "calll fclose\n"
        "movzbl %bl, %eax\n" /* okay */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 641 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfd024_0000d077:\n"
        "movl %esi, (%esp)\n" /* line 623 | fp */
        "calll ftell\n"
        "movl %eax, %ebx\n" /* okay */
        "movl %esi, (%esp)\n" /* line 624 | fp */
        "calll rewind\n"
        "movl %ebx, (%esp)\n" /* line 626 | okay */
        "calll malloc\n"
        "movl %eax, %edi\n" /* p */
        "movl %esi, 0xc(%esp)\n" /* line 628 | fp */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* okay */
        "movl %eax, (%esp)\n"
        "calll fread\n"
        "subl $1, %eax\n" /* line 629 */
        "je .Lfd024_0000d0c6\n"
        "xorl %ebx, %ebx\n" /* okay */
        ".Lfd024_0000d0b2:\n"
        "movl %edi, (%esp)\n" /* line 634 | p */
        "calll free\n"
        "jmp .Lfd024_0000d064\n"
        /* } scope */
        /* } scope */
        ".Lfd024_0000d0bc:\n"
        "xorl %eax, %eax\n" /* line 618 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 641 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfd024_0000d0c6:\n"
        "movl %edi, 4(%esp)\n" /* line 631 | p */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll WinCursor_ReadCursor\n"
        "movl %eax, %ebx\n" /* okay */
        "jmp .Lfd024_0000d0b2\n"
    );
}

/* line 127 */
__attribute__((naked))
HCURSOR LoadCursorFromFileA(LPCSTR lpFileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 127 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 131 | lpFileName */
        "movl %eax, 4(%esp)\n"
        "leal -0x460(%ebp), %ebx\n" /* path */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl $0, 4(%esp)\n" /* line 132 */
        "movl %ebx, (%esp)\n"
        "calll MacFiles_CleanPath\n"
        "movl %ebx, (%esp)\n" /* line 133 */
        "calll strlwr\n"
        "movl $0x215b9c, 4(%esp)\n" /* line 137 */
        "movl %ebx, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lfd0da_0000d2a2\n"
        "movl sCursorList, %edi\n" /* line 334 */
        "cmpl 0x334c04, %edi\n" /* line 145 */
        "je .Lfd0da_0000d15b\n"
        ".Lfd0da_0000d139:\n"
        "leal 4(%edi), %eax\n" /* line 606 */
        "movl %ebx, 4(%esp)\n" /* line 2140 */
        "movl %eax, (%esp)\n"
        "calll __ZNKSs7compareEPKc\n"
        "testl %eax, %eax\n" /* line 147 */
        "je .Lfd0da_0000d293\n"
        "addl $0x44, %edi\n" /* line 623 */
        "cmpl 0x334c04, %edi\n" /* line 145 */
        "jne .Lfd0da_0000d139\n"
        ".Lfd0da_0000d15b:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 178 */
        "movl %eax, -0x470(%ebp)\n"
        "addl $0xc, %eax\n" /* line 207 */
        "movl %eax, -0x46c(%ebp)\n"
        "movl %eax, -0x5c(%ebp)\n" /* line 251 */
        "movl __ZZN9WinCursorC4EvE11sNextHandle, %eax\n" /* line 540 */
        "movl %eax, -0x60(%ebp)\n" /* theCursor */
        "addl $1, %eax\n"
        "movl %eax, __ZZN9WinCursorC4EvE11sNextHandle\n"
        "leal -0x60(%ebp), %esi\n" /* line 542 | theCursor, this */
        "leal -0x58(%ebp), %edi\n"
        "cld\n"
        "movl $9, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $0, -0x34(%ebp)\n" /* line 544 */
        "movl $0, -0x30(%ebp)\n" /* line 545 */
        "movl $0, -0x2c(%ebp)\n" /* line 546 */
        "movl $0, -0x28(%ebp)\n" /* line 547 */
        "movl $0, -0x24(%ebp)\n" /* line 548 */
        "movb $0, -0x20(%ebp)\n" /* line 549 */
        "movl %ebx, 4(%esp)\n" /* line 156 */
        "movl %esi, (%esp)\n"
        "calll WinCursor_Load\n"
        "testb %al, %al\n"
        "je .Lfd0da_0000d28f\n"
        "movl 0x334c04, %edi\n" /* line 604 */
        "cmpl 0x334c08, %edi\n"
        "je .Lfd0da_0000d2b1\n"
        "testl %edi, %edi\n" /* line 104 */
        "je .Lfd0da_0000d268\n"
        "leal 4(%edi), %eax\n" /* line 555 | this */
        /* { scope 2 */
        "movl -0x46c(%ebp), %edx\n" /* line 251 */
        "movl %edx, 4(%edi)\n"
        /* } scope */
        "movl -0x60(%ebp), %edx\n" /* line 557 | theCursor */
        "movl %edx, (%edi)\n"
        "leal -0x5c(%ebp), %edx\n" /* line 480 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        "movl -0x58(%ebp), %eax\n" /* line 559 */
        "movl %eax, 8(%edi)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x18(%edi)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x1c(%edi)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x20(%edi)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x24(%edi)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x28(%edi)\n"
        "movl -0x34(%ebp), %eax\n" /* line 560 */
        "movl %eax, 0x2c(%edi)\n"
        "movl -0x30(%ebp), %eax\n" /* line 561 */
        "movl %eax, 0x30(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 562 */
        "movl %eax, 0x34(%edi)\n"
        "movl -0x28(%ebp), %eax\n" /* line 563 */
        "movl %eax, 0x38(%edi)\n"
        "movl -0x24(%ebp), %eax\n" /* line 564 */
        "movl %eax, 0x3c(%edi)\n"
        "movzbl -0x20(%ebp), %eax\n" /* line 565 */
        "movb %al, 0x40(%edi)\n"
        "movl 0x334c04, %edi\n"
        ".Lfd0da_0000d268:\n"
        "addl $0x44, %edi\n" /* line 607 */
        "movl %edi, 0x334c04\n"
        ".Lfd0da_0000d271:\n"
        "movl -0x60(%ebp), %ebx\n" /* line 598 | theCursor */
        ".Lfd0da_0000d274:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %edi, -0x470(%ebp)\n" /* line 224 */
        "jne .Lfd0da_0000d2c7\n"
        /* } scope */
        ".Lfd0da_0000d282:\n"
        "movl %ebx, %eax\n" /* line 165 */
        "addl $0x47c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd0da_0000d28f:\n"
        "xorl %ebx, %ebx\n" /* line 591 */
        "jmp .Lfd0da_0000d274\n"
        ".Lfd0da_0000d293:\n"
        "movl (%edi), %ebx\n" /* line 598 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 165 */
        "addl $0x47c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd0da_0000d2a2:\n"
        "xorl %ebx, %ebx\n" /* line 249 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 165 */
        "addl $0x47c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd0da_0000d2b1:\n"
        "movl %esi, 8(%esp)\n" /* line 610 | this */
        "movl %edi, 4(%esp)\n"
        "movl $sCursorList, (%esp)\n"
        "calll ZNSt6vectorI9WinCursorSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_\n"
        "jmp .Lfd0da_0000d271\n"
        ".Lfd0da_0000d2c7:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd0da_0000d282\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd0da_0000d282\n"
        "movl %eax, %ebx\n"
        ".Lfd0da_0000d2f1:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x470(%ebp)\n" /* line 224 */
        "jne .Lfd0da_0000d343\n"
        ".Lfd0da_0000d2ff:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 2 */
        "cmpl %esi, -0x470(%ebp)\n" /* line 224 */
        "je .Lfd0da_0000d2f1\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd0da_0000d2f1\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd0da_0000d2f1\n"
        "movl %eax, %ebx\n"
        "jmp .Lfd0da_0000d2ff\n"
        /* } scope */
        ".Lfd0da_0000d343:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd0da_0000d2ff\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd0da_0000d2ff\n"
    );
}

/* line 287 */
__attribute__((naked))
void ZN7WinIconD2Ev(void) /* WinIcon_~WinIcon */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 287 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 269 | this */
        "movl (%eax), %eax\n"
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "jne .Lfd36c_0000d389\n"
        /* } scope */
        ".Lfd36c_0000d383:\n"
        "addl $0x24, %esp\n" /* line 289 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd36c_0000d389:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd36c_0000d383\n"
        "leal -9(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd36c_0000d383\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
    );
}

/* line 287 */
__attribute__((naked))
void ZN7WinIconD1Ev(void) /* WinIcon_~WinIcon */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 287 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 269 | this */
        "movl (%eax), %eax\n"
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "jne .Lfd3ba_0000d3d7\n"
        /* } scope */
        ".Lfd3ba_0000d3d1:\n"
        "addl $0x24, %esp\n" /* line 289 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd3ba_0000d3d7:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd3ba_0000d3d1\n"
        "leal -9(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd3ba_0000d3d1\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
    );
}

/* line 555 */
__attribute__((naked))
void WinCursor_WinCursor(const WinCursor * _this, const WinCursor *inCursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 555 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* inCursor */
        "leal 4(%esi), %edx\n" /* this */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        /* { scope 2 */
        "leal 0xc(%edi), %eax\n" /* line 207 */
        /* } scope */
        /* { scope 2 */
        "movl %eax, 4(%esi)\n" /* line 251 */
        /* } scope */
        /* } scope */
        "movl (%ebx), %eax\n" /* line 557 | inCursor */
        "movl %eax, (%esi)\n" /* this */
        "leal 4(%ebx), %eax\n" /* line 558 | inCursor, __str */
        /* { scope 1 */
        "movl %eax, 4(%esp)\n" /* line 480 */
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl 8(%ebx), %eax\n" /* line 559 | inCursor */
        "movl %eax, 8(%esi)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0xc(%esi)\n" /* this */
        "movl 0x10(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0x10(%esi)\n" /* this */
        "movl 0x14(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0x14(%esi)\n" /* this */
        "movl 0x18(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0x18(%esi)\n" /* this */
        "movl 0x1c(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0x1c(%esi)\n" /* this */
        "movl 0x20(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0x20(%esi)\n" /* this */
        "movl 0x24(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0x24(%esi)\n" /* this */
        "movl 0x28(%ebx), %eax\n" /* inCursor */
        "movl %eax, 0x28(%esi)\n" /* this */
        "movl 0x2c(%ebx), %eax\n" /* line 560 | inCursor */
        "movl %eax, 0x2c(%esi)\n" /* this */
        "movl 0x30(%ebx), %eax\n" /* line 561 | inCursor */
        "movl %eax, 0x30(%esi)\n" /* this */
        "movl 0x34(%ebx), %eax\n" /* line 562 | inCursor */
        "movl %eax, 0x34(%esi)\n" /* this */
        "movl 0x38(%ebx), %eax\n" /* line 563 | inCursor */
        "movl %eax, 0x38(%esi)\n" /* this */
        "movl 0x3c(%ebx), %eax\n" /* line 564 | inCursor */
        "movl %eax, 0x3c(%esi)\n" /* this */
        "movzbl 0x40(%ebx), %eax\n" /* line 565 | inCursor */
        "movb %al, 0x40(%esi)\n" /* this */
        "addl $0x3c, %esp\n" /* line 566 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 4(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lfd408_0000d4b4\n"
        /* } scope */
        ".Lfd408_0000d4a9:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 472 */
        ".Lfd408_0000d4ac:\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        /* { scope 1 */
        ".Lfd408_0000d4b4:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd408_0000d4a9\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd408_0000d4a9\n"
        "jmp .Lfd408_0000d4ac\n"
    );
}

/* overload skip: WinCursor_WinCursor (0xd4de) */

/* line 589 */
__attribute__((naked))
void ZN9WinCursorD2Ev(void) /* WinCursor_~WinCursor */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 589 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 269 | this */
        "movl 4(%eax), %eax\n"
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "jne .Lfd5b4_0000d5d2\n"
        /* } scope */
        ".Lfd5b4_0000d5cc:\n"
        "addl $0x24, %esp\n" /* line 591 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd5b4_0000d5d2:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd5b4_0000d5cc\n"
        "leal -9(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd5b4_0000d5cc\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
    );
}

/* line 589 */
__attribute__((naked))
void ZN9WinCursorD1Ev(void) /* WinCursor_~WinCursor */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 589 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 269 | this */
        "movl 4(%eax), %eax\n"
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 224 */
        "jne .Lfd602_0000d620\n"
        /* } scope */
        ".Lfd602_0000d61a:\n"
        "addl $0x24, %esp\n" /* line 591 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd602_0000d620:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lfd602_0000d61a\n"
        "leal -9(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lfd602_0000d61a\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorI9WinCursorSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<WinCursor, std_allocator<WinCursor> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0x78(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 251 | this */
        "movl 4(%edx), %edi\n"
        "cmpl 8(%edx), %edi\n"
        "je .Lf2bc4b0_002bc741\n"
        /* { scope 1 */
        "leal -0x44(%edi), %ebx\n" /* line 253 | inCursor */
        "testl %edi, %edi\n" /* line 104 */
        "je .Lf2bc4b0_002bca4f\n"
        /* { scope 2: this, __dat */
        "leal 4(%edi), %esi\n" /* line 555 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 178 */
        "movl %eax, -0x80(%ebp)\n" /* this */
        /* { scope 3 */
        "addl $0xc, %eax\n" /* line 207 */
        "movl %eax, -0x7c(%ebp)\n" /* __dat */
        /* } scope */
        /* { scope 3 */
        "movl %eax, 4(%edi)\n" /* line 251 */
        /* } scope */
        "movl -0x44(%edi), %eax\n" /* line 557 */
        "movl %eax, (%edi)\n"
        "leal -0x40(%edi), %eax\n" /* line 558 | __str */
        /* { scope 3 */
        "movl %eax, 4(%esp)\n" /* line 480 */
        "movl %esi, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl 8(%ebx), %eax\n" /* line 559 | this */
        "movl %eax, 8(%edi)\n"
        "movl 0xc(%ebx), %eax\n" /* this */
        "movl %eax, 0xc(%edi)\n"
        "movl 0x10(%ebx), %eax\n" /* this */
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%ebx), %eax\n" /* this */
        "movl %eax, 0x14(%edi)\n"
        "movl 0x18(%ebx), %eax\n" /* this */
        "movl %eax, 0x18(%edi)\n"
        "movl 0x1c(%ebx), %eax\n" /* this */
        "movl %eax, 0x1c(%edi)\n"
        "movl 0x20(%ebx), %eax\n" /* this */
        "movl %eax, 0x20(%edi)\n"
        "movl 0x24(%ebx), %eax\n" /* this */
        "movl %eax, 0x24(%edi)\n"
        "movl 0x28(%ebx), %eax\n" /* this */
        "movl %eax, 0x28(%edi)\n"
        "movl 0x2c(%ebx), %eax\n" /* line 560 | this */
        "movl %eax, 0x2c(%edi)\n"
        "movl 0x30(%ebx), %eax\n" /* line 561 | this */
        "movl %eax, 0x30(%edi)\n"
        "movl 0x34(%ebx), %eax\n" /* line 562 | this */
        "movl %eax, 0x34(%edi)\n"
        "movl 0x38(%ebx), %eax\n" /* line 563 | this */
        "movl %eax, 0x38(%edi)\n"
        "movl 0x3c(%ebx), %eax\n" /* line 564 | this */
        "movl %eax, 0x3c(%edi)\n"
        "movzbl 0x40(%ebx), %eax\n" /* line 565 | this */
        "movb %al, 0x40(%edi)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %edi\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lf2bc4b0_002bc567:\n"
        "addl $0x44, %edi\n" /* line 255 */
        "movl %edi, 4(%eax)\n"
        "movl -0x7c(%ebp), %edx\n" /* line 251 | __dat */
        "movl %edx, -0x5c(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* line 557 | __x */
        "movl (%edx), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* __x_copy */
        "movl %edx, %eax\n" /* line 558 | __str */
        "addl $4, %eax\n" /* __str */
        /* { scope 2: this, __dat */
        "movl %eax, 4(%esp)\n" /* line 480 */
        "leal -0x5c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl 0x10(%ebp), %edx\n" /* line 559 | __x */
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x18(%edx), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x1c(%edx), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x24(%edx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x2c(%edx), %eax\n" /* line 560 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x30(%edx), %eax\n" /* line 561 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x34(%edx), %eax\n" /* line 562 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x38(%edx), %eax\n" /* line 563 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x3c(%edx), %eax\n" /* line 564 */
        "movl %eax, -0x24(%ebp)\n"
        "movzbl 0x40(%edx), %eax\n" /* line 565 */
        "movb %al, -0x20(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 257 | this */
        "movl 4(%edx), %eax\n"
        "leal -0x88(%eax), %esi\n"
        "leal -0x44(%eax), %ebx\n" /* inCursor */
        /* { scope 2: this, __dat */
        "movl %esi, %edx\n" /* line 411 */
        "subl 0xc(%ebp), %edx\n" /* __position */
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "negl %eax\n"
        "movl %eax, -0x8c(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf2bc4b0_002bc6b1\n"
        /* } scope */
        "xorl %edi, %edi\n" /* line 472 */
        ".Lf2bc4b0_002bc62b:\n"
        "subl $0x44, %esi\n" /* line 412 */
        "subl $0x44, %ebx\n" /* inCursor */
        "movl (%esi), %eax\n" /* line 574 */
        "movl %eax, (%ebx)\n" /* this */
        "leal 4(%esi), %eax\n" /* line 575 | this */
        "leal 4(%ebx), %edx\n" /* this */
        /* { scope 2: this, __dat */
        "movl %eax, 4(%esp)\n" /* line 480 */
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl 8(%esi), %eax\n" /* line 576 */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* this */
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* this */
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* this */
        "movl 0x18(%esi), %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* this */
        "movl 0x1c(%esi), %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* this */
        "movl 0x20(%esi), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* this */
        "movl 0x24(%esi), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* this */
        "movl 0x28(%esi), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* this */
        "movl 0x2c(%esi), %eax\n" /* line 577 */
        "movl %eax, 0x2c(%ebx)\n" /* this */
        "movl 0x30(%esi), %eax\n" /* line 578 */
        "movl %eax, 0x30(%ebx)\n" /* this */
        "movl 0x34(%esi), %eax\n" /* line 579 */
        "movl %eax, 0x34(%ebx)\n" /* this */
        "movl 0x38(%esi), %eax\n" /* line 580 */
        "movl %eax, 0x38(%ebx)\n" /* this */
        "movl 0x3c(%esi), %eax\n" /* line 581 */
        "movl %eax, 0x3c(%ebx)\n" /* this */
        "movzbl 0x40(%esi), %eax\n" /* line 582 */
        "movb %al, 0x40(%ebx)\n" /* this */
        "addl $1, %edi\n"
        "cmpl %edi, -0x8c(%ebp)\n" /* line 411 */
        "jne .Lf2bc4b0_002bc62b\n"
        ".Lf2bc4b0_002bc6b1:\n"
        "movl -0x60(%ebp), %eax\n" /* line 574 | __x_copy */
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %eax, (%edx)\n"
        "movl %edx, %eax\n" /* line 575 | this */
        "addl $4, %eax\n" /* this */
        /* { scope 2: this, __dat */
        "leal -0x5c(%ebp), %edx\n" /* line 480 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl -0x58(%ebp), %eax\n" /* line 576 */
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %eax, 8(%edx)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x28(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 577 */
        "movl %eax, 0x2c(%edx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 578 */
        "movl %eax, 0x30(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 579 */
        "movl %eax, 0x34(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 580 */
        "movl %eax, 0x38(%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 581 */
        "movl %eax, 0x3c(%edx)\n"
        "movzbl -0x20(%ebp), %eax\n" /* line 582 */
        "movb %al, 0x40(%edx)\n"
        "leal -0x5c(%ebp), %eax\n" /* line 591 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bc4b0_002bc741:\n"
        "movl %edx, %eax\n"
        /* { scope 1 */
        "movl %edi, %edx\n" /* line 759 */
        "subl (%eax), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "negl %eax\n"
        "cmpl $0x3c3c3c3, %eax\n" /* line 265 */
        "je .Lf2bc4b0_002bca88\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bc4b0_002bca66\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bc4b0_002bc779:\n"
        "movl %edx, %eax\n" /* line 88 */
        "shll $6, %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x90(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x84(%ebp)\n"
        "movl %eax, -0x74(%ebp)\n" /* line 276 */
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl (%edx), %esi\n"
        /* { scope 2: this, __dat */
        "movl %eax, -0x70(%ebp)\n" /* line 82 */
        "cmpl %esi, 0xc(%ebp)\n" /* line 85 | __position */
        "je .Lf2bc4b0_002bc840\n"
        "movl %eax, %ebx\n"
        ".Lf2bc4b0_002bc7ab:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bc4b0_002bc82c\n"
        "leal 4(%ebx), %edx\n" /* line 555 | this */
        /* { scope 3 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        /* { scope 4 */
        "leal 0xc(%edi), %eax\n" /* line 207 */
        /* } scope */
        /* { scope 4 */
        "movl %eax, 4(%ebx)\n" /* line 251 | inCursor */
        /* } scope */
        /* } scope */
        "movl (%esi), %eax\n" /* line 557 */
        "movl %eax, (%ebx)\n" /* this */
        "leal 4(%esi), %eax\n" /* line 558 | __str */
        /* { scope 3 */
        "movl %eax, 4(%esp)\n" /* line 480 */
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl 8(%esi), %eax\n" /* line 559 */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* this */
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* this */
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* this */
        "movl 0x18(%esi), %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* this */
        "movl 0x1c(%esi), %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* this */
        "movl 0x20(%esi), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* this */
        "movl 0x24(%esi), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* this */
        "movl 0x28(%esi), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* this */
        "movl 0x2c(%esi), %eax\n" /* line 560 */
        "movl %eax, 0x2c(%ebx)\n" /* this */
        "movl 0x30(%esi), %eax\n" /* line 561 */
        "movl %eax, 0x30(%ebx)\n" /* this */
        "movl 0x34(%esi), %eax\n" /* line 562 */
        "movl %eax, 0x34(%ebx)\n" /* this */
        "movl 0x38(%esi), %eax\n" /* line 563 */
        "movl %eax, 0x38(%ebx)\n" /* this */
        "movl 0x3c(%esi), %eax\n" /* line 564 */
        "movl %eax, 0x3c(%ebx)\n" /* this */
        "movzbl 0x40(%esi), %eax\n" /* line 565 */
        "movb %al, 0x40(%ebx)\n" /* this */
        ".Lf2bc4b0_002bc82c:\n"
        "addl $0x44, %esi\n" /* line 623 */
        "addl $0x44, %ebx\n" /* this */
        "movl %ebx, -0x70(%ebp)\n" /* this */
        "cmpl 0xc(%ebp), %esi\n" /* line 85 | __position */
        "jne .Lf2bc4b0_002bc7ab\n"
        "movl %ebx, %eax\n"
        /* } scope */
        ".Lf2bc4b0_002bc840:\n"
        "movl %eax, -0x74(%ebp)\n" /* line 279 */
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf2bc4b0_002bc931\n"
        "movl %eax, %edx\n"
        "movl %eax, %ebx\n" /* line 555 | this */
        "addl $4, %ebx\n" /* this */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 207 */
        "addl $0xc, %eax\n"
        /* { scope 2: this, __dat */
        "movl %eax, 4(%edx)\n" /* line 251 */
        /* } scope */
        "movl 0x10(%ebp), %edx\n" /* line 557 | __x */
        "movl (%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 558 | __x, __str */
        "addl $4, %eax\n" /* __str */
        /* { scope 2: this, __dat */
        "movl %eax, 4(%esp)\n" /* line 480 */
        "movl %ebx, (%esp)\n" /* this */
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl 0x10(%ebp), %edx\n" /* line 559 | __x */
        "movl 8(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0xc(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0x10(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0x14(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x14(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0x18(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x18(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0x1c(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0x20(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x20(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0x24(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x24(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl 0x28(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x28(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 560 | __x */
        "movl 0x2c(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x2c(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 561 | __x */
        "movl 0x30(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x30(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 562 | __x */
        "movl 0x34(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x34(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 563 | __x */
        "movl 0x38(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x38(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 564 | __x */
        "movl 0x3c(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, 0x3c(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 565 | __x */
        "movzbl 0x40(%edx), %eax\n"
        "movl -0x74(%ebp), %edx\n"
        "movb %al, 0x40(%edx)\n"
        "movl -0x70(%ebp), %eax\n"
        ".Lf2bc4b0_002bc931:\n"
        "addl $0x44, %eax\n" /* line 623 */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl 4(%edx), %edi\n"
        "movl -0x78(%ebp), %esi\n" /* line 286 */
        /* { scope 2: this, __dat */
        "movl %eax, -0x6c(%ebp)\n" /* line 82 */
        "cmpl %esi, %edi\n" /* line 85 */
        "je .Lf2bc4b0_002bc9f6\n"
        "movl %eax, %ebx\n"
        ".Lf2bc4b0_002bc94d:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bc4b0_002bc9dd\n"
        "leal 4(%ebx), %eax\n" /* line 555 | this */
        "movl %eax, -0x94(%ebp)\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 207 */
        "addl $0xc, %eax\n"
        /* { scope 3 */
        "movl %eax, 4(%ebx)\n" /* line 251 | inCursor */
        /* } scope */
        "movl (%esi), %eax\n" /* line 557 */
        "movl %eax, (%ebx)\n" /* this */
        "leal 4(%esi), %eax\n" /* line 558 | __str */
        /* { scope 3 */
        "movl %eax, 4(%esp)\n" /* line 480 */
        "movl -0x94(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl 8(%esi), %eax\n" /* line 559 */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* this */
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* this */
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* this */
        "movl 0x18(%esi), %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* this */
        "movl 0x1c(%esi), %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* this */
        "movl 0x20(%esi), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* this */
        "movl 0x24(%esi), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* this */
        "movl 0x28(%esi), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* this */
        "movl 0x2c(%esi), %eax\n" /* line 560 */
        "movl %eax, 0x2c(%ebx)\n" /* this */
        "movl 0x30(%esi), %eax\n" /* line 561 */
        "movl %eax, 0x30(%ebx)\n" /* this */
        "movl 0x34(%esi), %eax\n" /* line 562 */
        "movl %eax, 0x34(%ebx)\n" /* this */
        "movl 0x38(%esi), %eax\n" /* line 563 */
        "movl %eax, 0x38(%ebx)\n" /* this */
        "movl 0x3c(%esi), %eax\n" /* line 564 */
        "movl %eax, 0x3c(%ebx)\n" /* this */
        "movzbl 0x40(%esi), %eax\n" /* line 565 */
        "movb %al, 0x40(%ebx)\n" /* this */
        ".Lf2bc4b0_002bc9dd:\n"
        "addl $0x44, %esi\n" /* line 623 */
        "addl $0x44, %ebx\n" /* this */
        "movl %ebx, -0x6c(%ebp)\n" /* this */
        "cmpl %edi, %esi\n" /* line 85 */
        "jne .Lf2bc4b0_002bc94d\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 4(%eax), %edi\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf2bc4b0_002bc9f6:\n"
        "movl (%edx), %eax\n" /* line 603 */
        "movl %eax, %ebx\n" /* line 334 | inCursor */
        "cmpl %eax, %edi\n" /* line 173 */
        "je .Lf2bc4b0_002bca15\n"
        ".Lf2bc4b0_002bc9fe:\n"
        "leal 4(%ebx), %eax\n" /* line 591 | this */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "addl $0x44, %ebx\n" /* line 623 | this */
        "cmpl %edi, %ebx\n" /* line 173 | inCursor */
        "jne .Lf2bc4b0_002bc9fe\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl (%edx), %eax\n"
        ".Lf2bc4b0_002bca15:\n"
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bc4b0_002bca21\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bc4b0_002bca21:\n"
        "movl -0x84(%ebp), %edx\n" /* line 302 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, (%eax)\n"
        "movl -0x6c(%ebp), %edx\n" /* line 303 */
        "movl %edx, 4(%eax)\n"
        "movl -0x84(%ebp), %eax\n" /* line 304 */
        "addl -0x90(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: this, __dat */
        ".Lf2bc4b0_002bca4f:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 566 */
        "movl %edx, -0x80(%ebp)\n" /* this */
        "addl $0xc, %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* __dat */
        "movl 8(%ebp), %eax\n" /* this */
        "jmp .Lf2bc4b0_002bc567\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lf2bc4b0_002bca66:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bc4b0_002bca7e\n"
        "cmpl $0x3c3c3c3, %edx\n" /* line 85 */
        "jbe .Lf2bc4b0_002bc779\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bc4b0_002bca7e:\n"
        "movl $0x3c3c3c3, %edx\n" /* line 272 */
        "jmp .Lf2bc4b0_002bc779\n"
        ".Lf2bc4b0_002bca88:\n"
        "movl $0x215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
        "movl %eax, -0x88(%ebp)\n"
        /* } scope */
        /* { scope 1 */
        "leal -0x5c(%ebp), %edx\n" /* line 591 */
        "movl %edx, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        ".Lf2bc4b0_002bcaa5:\n"
        "movl -0x88(%ebp), %eax\n"
        ".Lf2bc4b0_002bcaab:\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x88(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n" /* inCursor */
        /* { scope 2: this, __dat */
        "cmpl %ebx, -0x80(%ebp)\n" /* line 224 | inCursor, this */
        "je .Lf2bc4b0_002bcaa5\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bc4b0_002bcaa5\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* inCursor */
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bc4b0_002bcaa5\n"
        "movl %eax, -0x88(%ebp)\n"
        /* } scope */
        /* { scope 2: this, __dat */
        "movl %esi, (%esp)\n" /* line 566 */
        "calll __ZNSsD1Ev\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        "jmp .Lf2bc4b0_002bcaab\n"
        "jmp .Lf2bc4b0_002bcaab\n"
        "movl %eax, -0x88(%ebp)\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "movl -0x88(%ebp), %edx\n" /* line 89 */
        "movl %edx, (%esp)\n"
        "calll ___cxa_begin_catch\n"
        "movl -0x74(%ebp), %ebx\n" /* line 91 */
        /* { scope 2: this, __dat */
        "cmpl %ebx, -0x6c(%ebp)\n" /* line 121 | inCursor */
        "je .Lf2bc4b0_002bcb49\n"
        ".Lf2bc4b0_002bcb36:\n"
        "leal 4(%ebx), %eax\n" /* line 591 | this */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "addl $0x44, %ebx\n" /* line 623 | this */
        "cmpl -0x6c(%ebp), %ebx\n" /* line 121 | inCursor */
        "jne .Lf2bc4b0_002bcb36\n"
        /* } scope */
        ".Lf2bc4b0_002bcb49:\n"
        "calll ___cxa_rethrow\n" /* line 92 */
        "movl %eax, -0x88(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 566 | this */
        "calll __ZNSsD1Ev\n"
        ".Lf2bc4b0_002bcb5c:\n"
        "movl -0x88(%ebp), %edx\n" /* line 292 */
        "movl %edx, (%esp)\n"
        "calll ___cxa_begin_catch\n"
        "movl -0x84(%ebp), %ebx\n" /* line 294 | inCursor */
        "cmpl %ebx, -0x74(%ebp)\n" /* line 173 | inCursor */
        "je .Lf2bc4b0_002bcb88\n"
        ".Lf2bc4b0_002bcb75:\n"
        "leal 4(%ebx), %eax\n" /* line 591 | this */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "addl $0x44, %ebx\n" /* line 623 | this */
        "cmpl %ebx, -0x74(%ebp)\n" /* line 173 | inCursor */
        "jne .Lf2bc4b0_002bcb75\n"
        ".Lf2bc4b0_002bcb88:\n"
        "movl -0x84(%ebp), %eax\n" /* line 122 */
        "testl %eax, %eax\n"
        "je .Lf2bc4b0_002bcba0\n"
        "movl -0x84(%ebp), %edx\n" /* line 94 */
        "movl %edx, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf2bc4b0_002bcba0:\n"
        "calll ___cxa_rethrow\n" /* line 296 */
        "movl %eax, -0x88(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* line 269 | inCursor */
        "leal -0xc(%eax), %ebx\n" /* line 277 | inCursor */
        /* { scope 2: this, __dat */
        "cmpl %edi, %ebx\n" /* line 224 | inCursor */
        "jne .Lf2bc4b0_002bcc0f\n"
        /* } scope */
        ".Lf2bc4b0_002bcbb5:\n"
        "movl -0x88(%ebp), %eax\n" /* line 89 */
        "movl %eax, (%esp)\n"
        "calll ___cxa_begin_catch\n"
        "movl -0x84(%ebp), %ebx\n" /* line 91 */
        /* { scope 2: this, __dat */
        "cmpl %ebx, -0x70(%ebp)\n" /* line 121 | inCursor */
        "je .Lf2bc4b0_002bcbe1\n"
        ".Lf2bc4b0_002bcbce:\n"
        "leal 4(%ebx), %eax\n" /* line 591 | this */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "addl $0x44, %ebx\n" /* line 623 | this */
        "cmpl %ebx, -0x70(%ebp)\n" /* line 121 | inCursor */
        "jne .Lf2bc4b0_002bcbce\n"
        /* } scope */
        ".Lf2bc4b0_002bcbe1:\n"
        "calll ___cxa_rethrow\n" /* line 92 */
        "movl %eax, -0x88(%ebp)\n"
        "calll ___cxa_end_catch\n" /* line 292 */
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x88(%ebp)\n"
        "calll ___cxa_end_catch\n" /* line 89 */
        "jmp .Lf2bc4b0_002bcb5c\n"
        /* { scope 2: this, __dat */
        ".Lf2bc4b0_002bcc0f:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bc4b0_002bcbb5\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* inCursor */
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bc4b0_002bcbb5\n"
        "movl %eax, -0x88(%ebp)\n"
        "jmp .Lf2bc4b0_002bcbb5\n"
    );
}

