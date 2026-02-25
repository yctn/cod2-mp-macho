/* ASM dump from: MacGameEngine.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacGameEngine.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacExceptions.h"
 *   #include "Mac/Tools/MacTools.h"
 */

static bool sSystemCursorVisible; /* 0x334e84 */
static const char *kBuildTag; /* 0x3083a0 */
static const char *kProductTag; /* 0x3083a4 */
static EventTargetRef sEventTargetRef; /* 0x334e80 */

void CMacGameEngine_CMacGameEngine(const CMacGameEngine * _this);
void ZN14CMacGameEngineD2Ev(void); /* CMacGameEngine_~CMacGameEngine */
void ZN14CMacGameEngineD1Ev(void); /* CMacGameEngine_~CMacGameEngine */
void ZN14CMacGameEngineD0Ev(void); /* CMacGameEngine_~CMacGameEngine */
void CMacGameEngine_Run(const CMacGameEngine * _this, int argc, char * *argv);
int main(int argc, char * *argv);
Boolean CMacGameEngine_ProcessAllEvents(void);
void CMacGameEngine_Quit(void);
void CMacGameEngine_DrawSplashScreen(const char *inFileName);
Boolean CMacGameEngine_Initialize(const CMacGameEngine * _this);
void CMacGameEngine_MacMain(const CMacGameEngine * _this);
void CMacGameEngine_SetIsRunning(const CMacGameEngine * _this, int inIsRunning);
void CMacGameEngine_DoMouseDown(const CMacGameEngine * _this, int inButton, Point inPoint, UInt32 inModifiers, UInt32 inClickCount);
void CMacGameEngine_DoMouseUp(const CMacGameEngine * _this, int inButton, Point inPoint);
void CMacGameEngine_DoMouseMoved(const CMacGameEngine * _this, Point inDelta, Point inPoint, UInt32 inModifiers);
void CMacGameEngine_DoMouseWheel(const CMacGameEngine * _this, SInt32 inDelta, Point inPoint, UInt32 inModifiers);
void CMacGameEngine_DoKeyDown(const CMacGameEngine * _this, int inCharCode, UInt32 inKeyCode);
void CMacGameEngine_DoKeyUp(const CMacGameEngine * _this, int inCharCode, UInt32 inKeyCode);
void CMacGameEngine_DoTextInput(const CMacGameEngine * _this, int inUniChar);
Boolean CMacGameEngine_IsQuitAvailable(const CMacGameEngine * _this);
void CMacGameEngine_DoQuit(const CMacGameEngine * _this);
OSStatus CMacGameEngine_HandleEventProc(EventRef inEvent, void *inUserData);
OSErr CMacGameEngine_HandleAppleEvent(const AppleEvent *inEvent, AppleEvent *outReply, SInt32 inRefCon);
void CMacGameEngine_InstallEventHandlers(const CMacGameEngine * _this);
void CMacGameEngine_OneShotTimer(const CMacGameEngine * _this);
void CMacGameEngine_OneShotTimerProc(void *inUserData);
Boolean CMacGameEngine_HandleEvent(const CMacGameEngine * _this, EventRef inEvent);

/* line 95 */
__attribute__((naked))
void CMacGameEngine_CMacGameEngine(const CMacGameEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x32fd68, (%eax)\n" /* line 104 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movb $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movb $0, 0x1c(%eax)\n"
        "movb $0, 0x1d(%eax)\n"
        "movb $0, 0x1e(%eax)\n"
        "calll GetMainEventQueue\n" /* line 106 */
        "leave\n" /* line 107 */
        "retl\n"
    );
}

/* line 111 */
__attribute__((naked))
void ZN14CMacGameEngineD2Ev(void) /* CMacGameEngine_~CMacGameEngine */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 111 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32fd68, (%ebx)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* line 113 | this */
        "testl %eax, %eax\n"
        "je .Lf26420_0002643f\n"
        "movl %eax, (%esp)\n" /* line 115 */
        "calll RemoveEventHandler\n"
        ".Lf26420_0002643f:\n"
        "movl 0x10(%ebx), %eax\n" /* line 118 | this */
        "testl %eax, %eax\n"
        "je .Lf26420_0002644e\n"
        "movl %eax, (%esp)\n" /* line 120 */
        "calll RemoveEventHandler\n"
        ".Lf26420_0002644e:\n"
        "addl $0x14, %esp\n" /* line 122 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 111 */
__attribute__((naked))
void ZN14CMacGameEngineD1Ev(void) /* CMacGameEngine_~CMacGameEngine */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 111 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32fd68, (%ebx)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* line 113 | this */
        "testl %eax, %eax\n"
        "je .Lf26454_00026473\n"
        "movl %eax, (%esp)\n" /* line 115 */
        "calll RemoveEventHandler\n"
        ".Lf26454_00026473:\n"
        "movl 0x10(%ebx), %eax\n" /* line 118 | this */
        "testl %eax, %eax\n"
        "je .Lf26454_00026482\n"
        "movl %eax, (%esp)\n" /* line 120 */
        "calll RemoveEventHandler\n"
        ".Lf26454_00026482:\n"
        "addl $0x14, %esp\n" /* line 122 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 111 */
__attribute__((naked))
void ZN14CMacGameEngineD0Ev(void) /* CMacGameEngine_~CMacGameEngine */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 111 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32fd68, (%ebx)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* line 113 | this */
        "testl %eax, %eax\n"
        "je .Lf26488_000264a7\n"
        "movl %eax, (%esp)\n" /* line 115 */
        "calll RemoveEventHandler\n"
        ".Lf26488_000264a7:\n"
        "movl 0x10(%ebx), %eax\n" /* line 118 | this */
        "testl %eax, %eax\n"
        "je .Lf26488_000264b6\n"
        "movl %eax, (%esp)\n" /* line 120 */
        "calll RemoveEventHandler\n"
        ".Lf26488_000264b6:\n"
        "movl %ebx, 8(%ebp)\n" /* line 122 | this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 127 */
__attribute__((naked))
void CMacGameEngine_Run(const CMacGameEngine * _this, int argc, char * *argv)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 127 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 129 | argc */
        "movl %eax, 4(%ebx)\n" /* this */
        "movl 0x10(%ebp), %eax\n" /* line 130 | argv */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl (%ebx), %eax\n" /* line 132 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *8(%eax)\n"
        "testb %al, %al\n"
        "je .Lf264c4_0002650f\n"
        /* { scope 1 */
        "calll MacDisplay_Initialize\n" /* line 135 */
        "testl %eax, %eax\n" /* line 136 */
        "je .Lf264c4_000264f5\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 150 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf264c4_000264f5:\n"
        "calll MacPreferences_Synchronize\n" /* line 142 */
        "calll GetMainEventQueue\n" /* line 144 */
        "movl %eax, (%esp)\n"
        "calll FlushEventQueue\n"
        "movl (%ebx), %eax\n" /* line 146 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0xc(%eax)\n"
        /* } scope */
        ".Lf264c4_0002650f:\n"
        "addl $0x14, %esp\n" /* line 150 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp MacPreferences_Synchronize\n" /* line 149 */
    );
}

/* line 60 */
__attribute__((naked))
int main(int argc, char * *argv)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $4, (%esp)\n" /* line 64 */
        "calll MacTools_SetCursorID\n"
        "calll GetMacGameEngine\n" /* line 69 */
        "movl 0xc(%ebp), %edx\n" /* line 72 | argv */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* argc */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CMacGameEngine_Run\n"
        /* } scope */
        ".Lf2651a_00026548:\n"
        "xorl %eax, %eax\n" /* line 89 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        "cmpl $2, %edx\n"
        "je .Lf2651a_00026564\n"
        "movl %eax, (%esp)\n" /* line 83 */
        "calll ___cxa_begin_catch\n"
        ".Lf2651a_0002655d:\n"
        "calll ___cxa_end_catch\n"
        "jmp .Lf2651a_00026548\n"
        ".Lf2651a_00026564:\n"
        "movl %eax, (%esp)\n" /* line 75 */
        "calll ___cxa_begin_catch\n"
        "cmpl $0x4e22, (%eax)\n" /* line 77 */
        "jne .Lf2651a_0002655d\n"
        "movl $1, 8(%esp)\n" /* line 79 */
        "movl $0, 4(%esp)\n"
        "movl $0x215d2c, (%esp)\n" /* "Not authorized" */
        "calll MacTools_MessageAlert\n"
        "jmp .Lf2651a_0002655d\n"
        "movl %eax, %ebx\n"
        "calll ___cxa_end_catch\n" /* line 75 */
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 155 */
__attribute__((naked))
Boolean CMacGameEngine_ProcessAllEvents(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 155 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        /* { scope 1 */
        "calll GetMacGameEngine\n" /* line 159 */
        "movl %eax, %esi\n" /* theGameEngine */
        "movb $0, 0x1e(%eax)\n" /* line 160 */
        "leal -0xc(%ebp), %ebx\n" /* carbonEvent */
        "jmp .Lf265a2_000265d9\n"
        ".Lf265a2_000265ba:\n"
        "movl sEventTargetRef, %eax\n" /* line 166 */
        "movl %eax, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* carbonEvent */
        "movl %eax, (%esp)\n"
        "calll SendEventToEventTarget\n"
        "movl -0xc(%ebp), %eax\n" /* line 167 | carbonEvent */
        "movl %eax, (%esp)\n"
        "calll ReleaseEvent\n"
        ".Lf265a2_000265d9:\n"
        "movl %ebx, 0x14(%esp)\n" /* line 164 */
        "movl $1, 0x10(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll ReceiveNextEvent\n"
        "testl %eax, %eax\n"
        "je .Lf265a2_000265ba\n"
        "movzbl 0x1c(%esi), %eax\n" /* theGameEngine */
        /* } scope */
        "addl $0x30, %esp\n" /* line 171 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 199 */
__attribute__((naked))
void CMacGameEngine_Quit(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 199 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll GetMacGameEngine\n" /* line 201 */
        "cmpb $0, 0x1d(%eax)\n"
        "jne .Lf2661a_0002662d\n"
        "leave\n" /* line 205 */
        "retl\n"
        ".Lf2661a_0002662d:\n"
        "calll GetMacGameEngine\n" /* line 203 */
        "movb $1, 0x1c(%eax)\n"
        "leave\n" /* line 205 */
        "retl\n"
    );
}

/* line 211 */
__attribute__((naked))
void CMacGameEngine_DrawSplashScreen(const char *inFileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        /* { scope 1 */
        "leal -0x94(%ebp), %ebx\n" /* line 214 | ref */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inFileName, error */
        "movl %eax, (%esp)\n" /* error */
        "calll MacFolders_GetDataFolderItemRef\n"
        "testl %eax, %eax\n" /* line 215 */
        "je .Lf26638_00026668\n"
        /* } scope */
        ".Lf26638_0002665d:\n"
        "addl $0xbc, %esp\n" /* line 251 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf26638_00026668:\n"
        "movl %ebx, 4(%esp)\n" /* line 217 */
        "movl $0, (%esp)\n"
        "calll CFURLCreateFromFSRef\n"
        "movl %eax, %esi\n" /* urlRef */
        "testl %eax, %eax\n" /* line 218 */
        "je .Lf26638_0002665d\n"
        /* { scope 3: imageRef */
        "movl %eax, (%esp)\n" /* line 220 */
        "calll CGDataProviderCreateWithURL\n"
        "movl %eax, %edi\n" /* providerRef */
        "testl %eax, %eax\n" /* line 221 */
        "je .Lf26638_000266f6\n"
        /* { scope 4: width, height, contextRef */
        "movl $0, 0xc(%esp)\n" /* line 223 */
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CGImageCreateWithPNGDataProvider\n"
        "movl %eax, -0xa4(%ebp)\n" /* imageRef */
        "testl %eax, %eax\n" /* line 224 */
        "je .Lf26638_000266ee\n"
        /* { scope 5 */
        "leal -0x20(%ebp), %eax\n" /* line 227 | height */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* width */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetCurrentDimensions\n"
        "calll MacDisplay_GetMainPort\n" /* line 230 */
        "leal -0x24(%ebp), %edx\n" /* contextRef */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll QDBeginCGContext\n"
        "testl %eax, %eax\n" /* line 231 */
        "je .Lf26638_00026709\n"
        ".Lf26638_000266e0:\n"
        "movl -0xa4(%ebp), %eax\n" /* line 242 | imageRef */
        "movl %eax, (%esp)\n"
        "calll CGImageRelease\n"
        /* } scope */
        ".Lf26638_000266ee:\n"
        "movl %edi, (%esp)\n" /* line 245 | providerRef */
        "calll CGDataProviderRelease\n"
        /* } scope */
        ".Lf26638_000266f6:\n"
        "movl %esi, (%esp)\n" /* line 248 | urlRef */
        "calll CFRelease\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0xbc, %esp\n" /* line 251 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3: imageRef */
        /* { scope 4: width, height, contextRef */
        /* { scope 5 */
        ".Lf26638_00026709:\n"
        "cvtsi2ssl -0x20(%ebp), %xmm0\n" /* line 233 | height */
        "movss %xmm0, -0xa0(%ebp)\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* width */
        "movss %xmm0, -0x9c(%ebp)\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 234 */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, -0x40(%ebp)\n"
        "movl %ebx, -0x44(%ebp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* contextRef */
        "movl %eax, (%esp)\n"
        "calll CGContextClearRect\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 236 */
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl %ebx, -0x30(%ebp)\n"
        "movl %ebx, -0x34(%ebp)\n"
        "movl -0xa4(%ebp), %eax\n" /* imageRef */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* contextRef */
        "movl %eax, (%esp)\n"
        "calll CGContextDrawImage\n"
        "movl -0x24(%ebp), %eax\n" /* line 237 | contextRef */
        "movl %eax, (%esp)\n"
        "calll CGContextFlush\n"
        "calll MacDisplay_GetMainPort\n" /* line 239 */
        "leal -0x24(%ebp), %edx\n" /* contextRef */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll QDEndCGContext\n"
        "jmp .Lf26638_000266e0\n"
    );
}

/* line 258 */
__attribute__((naked))
Boolean CMacGameEngine_Initialize(const CMacGameEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 258 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4d0, %esp\n"
        /* { scope 1: rlp */
        "leal -0x18(%ebp), %eax\n" /* line 268 | macEvent */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll EventAvail\n"
        "movl kProductTag, %eax\n" /* line 272 */
        "movl %eax, 4(%esp)\n"
        "movl kBuildTag, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf267e2_00026826\n"
        ".Lf267e2_0002681a:\n"
        "xorl %eax, %eax\n" /* line 379 */
        /* } scope */
        ".Lf267e2_0002681c:\n"
        "addl $0x4d0, %esp\n" /* line 380 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: rlp */
        ".Lf267e2_00026826:\n"
        "calll MacFeatures_GetSystemVersion\n" /* line 279 */
        "cmpw $0x1038, %ax\n"
        "jg .Lf267e2_00026852\n"
        "calll MacResources_GetNeedsNewerOSError\n" /* line 281 */
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_MessageAlert\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x4d0, %esp\n" /* line 380 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: rlp */
        /* { scope 2 */
        ".Lf267e2_00026852:\n"
        "leal -0x4ac(%ebp), %esi\n" /* line 290 | rlp */
        "movl %esi, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll getrlimit\n"
        "testl %eax, %eax\n" /* line 291 */
        "jne .Lf267e2_000268c4\n"
        "movl -0x4ac(%ebp), %eax\n" /* line 293 | rlp */
        "movl -0x4a8(%ebp), %edx\n"
        "movl %eax, %ecx\n"
        "movl %edx, %ebx\n"
        "shldl $1, %ecx, %ebx\n"
        "addl %ecx, %ecx\n"
        "addl %eax, %ecx\n"
        "adcl %edx, %ebx\n"
        "movl %ecx, -0x4ac(%ebp)\n" /* rlp */
        "movl %ebx, -0x4a8(%ebp)\n"
        "movl -0x4a4(%ebp), %eax\n" /* line 294 */
        "movl -0x4a0(%ebp), %edx\n"
        "cmpl %edx, %ebx\n"
        "jl .Lf267e2_000268b4\n"
        "jle .Lf267e2_000269f5\n"
        ".Lf267e2_000268a8:\n"
        "movl %eax, -0x4ac(%ebp)\n" /* line 296 | rlp */
        "movl %edx, -0x4a8(%ebp)\n"
        ".Lf267e2_000268b4:\n"
        "movl %esi, 4(%esp)\n" /* line 298 */
        "movl $3, (%esp)\n"
        "calll setrlimit\n"
        /* } scope */
        ".Lf267e2_000268c4:\n"
        "calll EnterMovies\n" /* line 319 */
        "testw %ax, %ax\n" /* line 320 */
        "jne .Lf267e2_0002694d\n"
        "calll MacFolders_GetApplicationVRefNum\n" /* line 330 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "leal -0xaa(%ebp), %edx\n" /* volInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl $0x2000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "cwtl\n"
        "movl %eax, (%esp)\n"
        "calll FSGetVolumeInfo\n"
        "testw %ax, %ax\n" /* line 331 */
        "jne .Lf267e2_00026928\n"
        "movzwl -0x36(%ebp), %eax\n" /* line 333 */
        "testb %al, %al\n"
        "js .Lf267e2_00026a02\n"
        "testw %ax, %ax\n"
        "js .Lf267e2_00026a02\n"
        ".Lf267e2_00026928:\n"
        "calll MacFolders_GetDataFolderID\n" /* line 343 */
        "testl %eax, %eax\n"
        "jne .Lf267e2_00026997\n"
        "calll MacResources_GetMissingDataFolderError\n" /* line 345 */
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_MessageAlert\n"
        "xorl %eax, %eax\n"
        "jmp .Lf267e2_0002681c\n"
        ".Lf267e2_0002694d:\n"
        "calll MacResources_GetNoQuickTimeError\n" /* line 322 */
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_MessageAlert\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x4d0, %esp\n" /* line 380 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: rlp */
        /* { scope 2 */
        ".Lf267e2_0002696e:\n"
        "calll MacResources_GetInsertDiscError\n" /* line 360 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_QuestionAlert\n"
        "testb %al, %al\n"
        "je .Lf267e2_0002681a\n"
        "movl $4, (%esp)\n" /* line 365 */
        "calll MacTools_SetCursorID\n"
        ".Lf267e2_00026997:\n"
        "calll MacResources_GetDiscName\n" /* line 355 */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_FindDiscVolume\n"
        "testw %ax, %ax\n"
        "je .Lf267e2_0002696e\n"
        /* } scope */
        "movl $0x14, -0x2c(%ebp)\n" /* line 374 | compInfo */
        "leal -0x2c(%ebp), %eax\n" /* line 375 | compInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x10, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0x4e4f4e45, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll GetCompressionInfo\n"
        "movl $4, (%esp)\n" /* line 376 */
        "calll MacTools_SetCursorID\n"
        "movl $1, %eax\n"
        "jmp .Lf267e2_0002681c\n"
        /* { scope 2 */
        ".Lf267e2_000269f5:\n"
        "cmpl %eax, %ecx\n" /* line 294 */
        "jbe .Lf267e2_000268b4\n"
        "jmp .Lf267e2_000268a8\n"
        /* } scope */
        ".Lf267e2_00026a02:\n"
        "calll MacResources_GetCantRunFromDiscError\n" /* line 336 */
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_MessageAlert\n"
        "xorl %eax, %eax\n"
        "jmp .Lf267e2_0002681c\n"
    );
}

/* line 385 */
__attribute__((naked))
void CMacGameEngine_MacMain(const CMacGameEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 385 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1 */
        "calll GetMainEventLoop\n" /* line 398 */
        "leal -0xc(%ebp), %edx\n" /* timerRef */
        "movl %edx, 0x1c(%esp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, 0x18(%esp)\n"
        "movl $CMacGameEngine_OneShotTimerProc, 0x14(%esp)\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, 0xc(%esp)\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventLoopTimer\n"
        "calll RunApplicationEventLoop\n" /* line 402 */
        "calll MacDisplay_ReleaseDisplay\n" /* line 405 */
        /* } scope */
        "leave\n" /* line 428 */
        "retl\n"
    );
}

/* line 434 */
__attribute__((naked))
void CMacGameEngine_SetIsRunning(const CMacGameEngine * _this, int inIsRunning)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 434 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 436 | inIsRunning */
        "movl 8(%ebp), %eax\n" /* this */
        "movb %dl, 0x1d(%eax)\n"
        "popl %ebp\n" /* line 437 */
        "retl\n"
    );
}

/* line 1036 */
__attribute__((naked))
void CMacGameEngine_DoMouseDown(const CMacGameEngine * _this, int inButton, Point inPoint, UInt32 inModifiers, UInt32 inClickCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1036 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1080 */
        "retl\n"
    );
}

/* line 1087 */
__attribute__((naked))
void CMacGameEngine_DoMouseUp(const CMacGameEngine * _this, int inButton, Point inPoint)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1087 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1111 */
        "retl\n"
    );
}

/* line 1119 */
__attribute__((naked))
void CMacGameEngine_DoMouseMoved(const CMacGameEngine * _this, Point inDelta, Point inPoint, UInt32 inModifiers)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1119 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1130 */
        "retl\n"
    );
}

/* line 1138 */
__attribute__((naked))
void CMacGameEngine_DoMouseWheel(const CMacGameEngine * _this, SInt32 inDelta, Point inPoint, UInt32 inModifiers)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1138 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1152 */
        "retl\n"
    );
}

/* line 1161 */
__attribute__((naked))
void CMacGameEngine_DoKeyDown(const CMacGameEngine * _this, int inCharCode, UInt32 inKeyCode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1161 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1166 */
        "retl\n"
    );
}

/* line 1173 */
__attribute__((naked))
void CMacGameEngine_DoKeyUp(const CMacGameEngine * _this, int inCharCode, UInt32 inKeyCode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1173 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1178 */
        "retl\n"
    );
}

/* line 1186 */
__attribute__((naked))
void CMacGameEngine_DoTextInput(const CMacGameEngine * _this, int inUniChar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1186 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1197 */
        "retl\n"
    );
}

/* line 1204 */
__attribute__((naked))
Boolean CMacGameEngine_IsQuitAvailable(const CMacGameEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1204 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n" /* line 1211 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1216 */
__attribute__((naked))
void CMacGameEngine_DoQuit(const CMacGameEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1216 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl (%ebx), %eax\n" /* line 1218 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        "testb %al, %al\n"
        "je .Lf26aa8_00026ac2\n"
        "movb $1, 0x1c(%ebx)\n" /* line 1220 | this */
        ".Lf26aa8_00026ac2:\n"
        "addl $0x14, %esp\n" /* line 1235 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1320 */
__attribute__((naked))
OSStatus CMacGameEngine_HandleEventProc(EventRef inEvent, void *inUserData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1320 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* inUserData */
        /* { scope 1 */
        "movl (%eax), %ecx\n" /* line 1330 */
        "movl 0xc(%ebp), %edx\n" /* inEvent */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ecx)\n"
        "cmpb $1, %al\n"
        "sbbl %eax, %eax\n"
        "andl $0xffffd96e, %eax\n"
        /* } scope */
        "leave\n" /* line 1345 */
        "retl\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 1339 */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        "movl $0xffffd96e, %eax\n"
        /* } scope */
        "leave\n" /* line 1345 */
        "retl\n"
    );
}

/* line 1353 */
__attribute__((naked))
OSErr CMacGameEngine_HandleAppleEvent(const AppleEvent *inEvent, AppleEvent *outReply, SInt32 inRefCon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1353 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* inRefCon */
        "testl %ebx, %ebx\n" /* line 1356 | inRefCon */
        "jne .Lf26b00_00026b19\n"
        "movl $0xfffff954, %eax\n"
        ".Lf26b00_00026b13:\n"
        "addl $0x14, %esp\n" /* line 1372 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf26b00_00026b19:\n"
        "movl (%ebx), %eax\n" /* line 1358 | inRefCon */
        "movl %ebx, (%esp)\n" /* inRefCon */
        "calll *0x34(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf26b00_00026b2c\n"
        "movl $0xffffff80, %eax\n"
        "jmp .Lf26b00_00026b13\n"
        ".Lf26b00_00026b2c:\n"
        "movl (%ebx), %eax\n" /* line 1360 | inRefCon */
        "movl %ebx, (%esp)\n" /* inRefCon */
        "calll *0x38(%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf26b00_00026b13\n"
    );
}

/* line 442 */
__attribute__((naked))
void CMacGameEngine_InstallEventHandlers(const CMacGameEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 442 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: theMenu, theIndex */
        "calll GetEventDispatcherTarget\n" /* line 444 */
        "movl %eax, sEventTargetRef\n"
        "calll MacDisplay_IsWindowMode\n" /* line 449 */
        "testb %al, %al\n"
        "je .Lf26b3a_00026cca\n"
        /* { scope 2: theEvents, itemIndex */
        /* { scope 3 */
        "leal -0x88(%ebp), %edi\n" /* line 473 | theEvents */
        "movl $0x68, 8(%esp)\n"
        "movl $__ZZN14CMacGameEngine20InstallEventHandlersEvE5C.133, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "calll GetApplicationEventTarget\n" /* line 475 */
        "leal 0xc(%esi), %edx\n" /* this */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* this */
        "movl %edi, 0xc(%esp)\n"
        "movl $0xd, 8(%esp)\n"
        "movl $CMacGameEngine_HandleEventProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventHandler\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf26b3a_00026dc5\n"
        /* } scope */
        /* { scope 3 */
        "movl $0x6d6f7573, -0x88(%ebp)\n" /* line 497 | theEvents */
        "movl $1, -0x84(%ebp)\n"
        "movl $0x6d6f7573, -0x80(%ebp)\n"
        "movl $2, -0x7c(%ebp)\n"
        "movl $0x6b657962, -0x78(%ebp)\n"
        "movl $1, -0x74(%ebp)\n"
        "movl $0x6b657962, -0x70(%ebp)\n"
        "movl $2, -0x6c(%ebp)\n"
        "movl $0x6b657962, -0x68(%ebp)\n"
        "movl $3, -0x64(%ebp)\n"
        "movl $0x6b657962, -0x60(%ebp)\n"
        "movl $4, -0x5c(%ebp)\n"
        "movl $0x74657874, -0x58(%ebp)\n"
        "movl $2, -0x54(%ebp)\n"
        "movl $0x77696e64, -0x50(%ebp)\n"
        "movl $0x48, -0x4c(%ebp)\n"
        "calll MacDisplay_GetMainWindow\n" /* line 499 */
        "movl %eax, (%esp)\n"
        "calll GetWindowEventTarget\n"
        "leal 0x10(%esi), %edx\n" /* this */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* this */
        "movl %edi, 0xc(%esp)\n"
        "movl $8, 8(%esp)\n"
        "movl $CMacGameEngine_HandleEventProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventHandler\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf26b3a_00026dc5\n"
        /* } scope */
        "movl $0x80, (%esp)\n" /* line 505 */
        "calll GetMenuHandle\n"
        "movl %eax, %ebx\n" /* theMenu */
        "testl %eax, %eax\n" /* line 506 */
        "je .Lf26b3a_00026d92\n"
        /* { scope 3 */
        "leal -0x1a(%ebp), %eax\n" /* line 509 | itemIndex, error2 */
        "movl %eax, 0x10(%esp)\n" /* error2 */
        "movl $0x546f676c, 0xc(%esp)\n"
        "movl $0x1020, 8(%esp)\n"
        "movl $0x32e7d4, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theMenu */
        "calll AppendMenuItemTextWithCFString\n"
        "testl %eax, %eax\n" /* line 510 */
        "jne .Lf26b3a_00026d92\n"
        "movl $0x54, 8(%esp)\n" /* line 512 */
        "movzwl -0x1a(%ebp), %eax\n" /* itemIndex */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theMenu */
        "calll SetItemCmd\n"
        "jmp .Lf26b3a_00026d92\n"
        /* } scope */
        /* } scope */
        /* { scope 2: theEvents, itemIndex */
        /* { scope 3 */
        ".Lf26b3a_00026cca:\n"
        "leal -0x88(%ebp), %edi\n" /* line 539 | theEvents */
        "movl $0x68, 8(%esp)\n"
        "movl $__ZZN14CMacGameEngine20InstallEventHandlersEvE5C.135, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "calll GetApplicationEventTarget\n" /* line 541 */
        "leal 0xc(%esi), %edx\n" /* this */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* this */
        "movl %edi, 0xc(%esp)\n"
        "movl $0xd, 8(%esp)\n"
        "movl $CMacGameEngine_HandleEventProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventHandler\n"
        "movl %eax, %ebx\n" /* theMenu */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf26b3a_00026dc5\n"
        /* } scope */
        "leal -0x1a(%ebp), %eax\n" /* line 549 | itemIndex */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* theMenu */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x68696465, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll GetIndMenuItemWithCommandID\n"
        "testl %eax, %eax\n" /* line 550 */
        "jne .Lf26b3a_00026d92\n"
        /* { scope 3 */
        "movl $0x636d6473, -0x88(%ebp)\n" /* line 554 | theEvents */
        "movl $1, -0x84(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 556 | theMenu */
        "movl %eax, (%esp)\n"
        "calll GetMenuEventTarget\n"
        "leal 0x10(%esi), %edx\n" /* this */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* this */
        "movl %edi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $CMacGameEngine_HandleEventProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventHandler\n"
        /* } scope */
        /* } scope */
        ".Lf26b3a_00026d92:\n"
        "movl $0, 0x10(%esp)\n" /* line 563 */
        "movl %esi, 0xc(%esp)\n" /* this */
        "movl $CMacGameEngine_HandleAppleEvent, 8(%esp)\n"
        "movl $0x71756974, 4(%esp)\n"
        "movl $0x61657674, (%esp)\n"
        "calll AEInstallEventHandler\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 564 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: theMenu, theIndex */
        /* { scope 2: theEvents, itemIndex */
        /* { scope 3 */
        ".Lf26b3a_00026dc5:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
    );
}

/* line 1242 */
__attribute__((naked))
void CMacGameEngine_OneShotTimer(const CMacGameEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1242 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "calll MacResources_GetDiscName\n" /* line 1246 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_FindDiscVolume\n"
        "testw %ax, %ax\n"
        "jne .Lf26dee_00026e20\n"
        /* } scope */
        "addl $0x410, %esp\n" /* line 1285 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf26dee_00026e20:\n"
        "movl $0x400, 4(%esp)\n" /* line 1255 */
        "leal -0x408(%ebp), %ebx\n" /* path */
        "movl %ebx, (%esp)\n"
        "calll MacFolders_GetDataFolderPath\n"
        "movl %ebx, (%esp)\n" /* line 1256 */
        "calll chdir\n"
        "movl $0x1e0, 4(%esp)\n" /* line 1272 */
        "movl $0x280, (%esp)\n"
        "calll MacDisplay_SetupDisplay\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf26dee_00026e7e\n"
        "movl %esi, (%esp)\n" /* line 1276 | this */
        "calll CMacGameEngine_InstallEventHandlers\n"
        "movl $1, (%esp)\n" /* line 1280 */
        "calll MacTools_HideCursor\n"
        "movl (%esi), %eax\n" /* line 1284 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x10(%eax)\n"
        /* } scope */
        "addl $0x410, %esp\n" /* line 1285 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf26dee_00026e7e:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
    );
}

/* line 1292 */
__attribute__((naked))
void CMacGameEngine_OneShotTimerProc(void *inUserData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1292 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 1300 | inUserData */
        "movl %eax, (%esp)\n"
        "calll CMacGameEngine_OneShotTimer\n"
        ".Lf26ea6_00026eb7:\n"
        "leave\n" /* line 1312 */
        "jmp QuitApplicationEventLoop\n" /* line 1311 */
        "movl %eax, (%esp)\n" /* line 1306 */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        "jmp .Lf26ea6_00026eb7\n"
    );
}

/* line 570 */
__attribute__((naked))
Boolean CMacGameEngine_HandleEvent(const CMacGameEngine * _this, EventRef inEvent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 570 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* inEvent */
        /* { scope 1: theCharCode, theKeyCode, theCommand, theClickCount, ... */
        "movl 8(%ebp), %eax\n" /* line 574 | this */
        "cmpb $0, 0x1d(%eax)\n"
        "jne .Lf26ecc_00026f80\n"
        ".Lf26ecc_00026ee5:\n"
        "movl $1, %esi\n"
        "movl %edi, (%esp)\n" /* line 576 | inEvent */
        "calll GetEventKind\n"
        "movl %eax, %ebx\n" /* eventKind */
        "movl %edi, (%esp)\n" /* line 578 | inEvent */
        "calll GetEventClass\n"
        "cmpl $0x6d656e75, %eax\n"
        "je .Lf26ecc_00026fac\n"
        ".Lf26ecc_00026f07:\n"
        "jbe .Lf26ecc_00026f38\n"
        "cmpl $0x74657874, %eax\n"
        "je .Lf26ecc_00027134\n"
        "cmpl $0x77696e64, %eax\n"
        "je .Lf26ecc_00026fcc\n"
        "cmpl $0x6d6f7573, %eax\n"
        "jne .Lf26ecc_00026f76\n"
        "movl %esi, %edx\n" /* line 582 */
        "testb %dl, %dl\n"
        "jne .Lf26ecc_00026f76\n"
        "cmpl $0xa, %ebx\n" /* line 587 | eventKind */
        "ja .Lf26ecc_00026f76\n"
        "jmpl *0x2ef9a8(, %ebx, 4)\n"
        ".Lf26ecc_00026f38:\n"
        "cmpl $0x636d6473, %eax\n" /* line 578 */
        "je .Lf26ecc_000270a9\n"
        "cmpl $0x6b657962, %eax\n"
        "je .Lf26ecc_00026ff5\n"
        "cmpl $0x6170706c, %eax\n"
        "jne .Lf26ecc_00026f76\n"
        "movl 8(%ebp), %eax\n" /* line 825 | this */
        "cmpb $0, 0x1d(%eax)\n"
        "je .Lf26ecc_00026f76\n"
        "cmpl $2, %ebx\n" /* line 830 | eventKind */
        "je .Lf26ecc_000271be\n"
        "ja .Lf26ecc_000271c8\n"
        "subl $1, %ebx\n" /* eventKind */
        "je .Lf26ecc_000271e2\n"
        ".Lf26ecc_00026f76:\n"
        "xorl %eax, %eax\n" /* line 874 */
        /* } scope */
        ".Lf26ecc_00026f78:\n"
        "addl $0x4c, %esp\n" /* line 1025 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: theCharCode, theKeyCode, theCommand, theClickCount, ... */
        ".Lf26ecc_00026f80:\n"
        "calll MacGlobals_IsSystemLocked\n" /* line 574 */
        "testb %al, %al\n"
        "jne .Lf26ecc_00026ee5\n"
        "xorl %esi, %esi\n"
        "movl %edi, (%esp)\n" /* line 576 | inEvent */
        "calll GetEventKind\n"
        "movl %eax, %ebx\n" /* eventKind */
        "movl %edi, (%esp)\n" /* line 578 | inEvent */
        "calll GetEventClass\n"
        "cmpl $0x6d656e75, %eax\n"
        "jne .Lf26ecc_00026f07\n"
        ".Lf26ecc_00026fac:\n"
        "movl 8(%ebp), %edx\n" /* line 865 | this */
        "cmpb $0, 0x1d(%edx)\n"
        "je .Lf26ecc_00026f76\n"
        "cmpl $1, %ebx\n" /* line 870 | eventKind */
        "je .Lf26ecc_000271be\n"
        "cmpl $2, %ebx\n" /* eventKind */
        "jne .Lf26ecc_00026f76\n"
        "calll MacGlobals_UnlockSystem\n" /* line 880 */
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        ".Lf26ecc_00026fcc:\n"
        "movl 8(%ebp), %ecx\n" /* line 889 | this */
        "cmpb $0, 0x1d(%ecx)\n"
        "je .Lf26ecc_00026f76\n"
        "cmpl $0x1b, %ebx\n" /* line 894 | eventKind */
        "je .Lf26ecc_0002762d\n"
        "cmpl $0x48, %ebx\n" /* eventKind */
        "jne .Lf26ecc_00026f76\n"
        "movl 8(%ebp), %edx\n" /* line 908 | this */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *0x38(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        ".Lf26ecc_00026ff5:\n"
        "movl %esi, %eax\n" /* line 716 */
        "testb %al, %al\n"
        "jne .Lf26ecc_00026f76\n"
        "cmpl $3, %ebx\n" /* line 721 | eventKind */
        "je .Lf26ecc_00027673\n"
        "cmpl $4, %ebx\n" /* eventKind */
        "je .Lf26ecc_00027705\n"
        "subl $1, %ebx\n" /* eventKind */
        "jne .Lf26ecc_00026f76\n"
        /* { scope 2 */
        "leal -0x20(%ebp), %eax\n" /* line 37 | theCharCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x54455854, 8(%esp)\n"
        "movl $0x6b636872, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "leal -0x24(%ebp), %eax\n" /* theKeyCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x6b636f64, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl 8(%ebp), %ecx\n" /* line 746 | this */
        "movl (%ecx), %edx\n"
        "movl -0x24(%ebp), %eax\n" /* theKeyCode */
        "movl %eax, 8(%esp)\n"
        "movzbl -0x20(%ebp), %eax\n" /* theCharCode */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *0x28(%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        ".Lf26ecc_000270a9:\n"
        "cmpl $1, %ebx\n" /* line 918 | eventKind */
        "je .Lf26ecc_000275a2\n"
        "cmpl $2, %ebx\n" /* eventKind */
        "jne .Lf26ecc_00026f76\n"
        /* { scope 2 */
        "leal -0x36(%ebp), %eax\n" /* line 973 | theCommand, error2 */
        "movl %eax, 0x18(%esp)\n" /* error2 */
        "movl $0, 0x14(%esp)\n"
        "movl $0xe, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x68636d64, 8(%esp)\n"
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* inEvent */
        "calll GetEventParameter\n"
        "testl %eax, %eax\n" /* line 974 */
        "jne .Lf26ecc_00026f76\n"
        "testb $1, -0x36(%ebp)\n" /* theCommand */
        "je .Lf26ecc_00026f76\n"
        "cmpl $0x71756974, -0x32(%ebp)\n" /* line 976 */
        "jne .Lf26ecc_00026f76\n"
        "movl 8(%ebp), %edx\n" /* line 980 | this */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *0x34(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf26ecc_0002712a\n"
        "testb $1, -0x36(%ebp)\n" /* line 982 | theCommand */
        "jne .Lf26ecc_00027585\n"
        ".Lf26ecc_0002712a:\n"
        "movl $1, %eax\n" /* line 984 */
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        ".Lf26ecc_00027134:\n"
        "movl %esi, %edx\n" /* line 799 */
        "testb %dl, %dl\n"
        "jne .Lf26ecc_00026f76\n"
        "cmpl $2, %ebx\n" /* line 804 | eventKind */
        "jne .Lf26ecc_00026f76\n"
        /* { scope 2 */
        "leal -0x20(%ebp), %eax\n" /* line 37 | theCharCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x75747874, 8(%esp)\n"
        "movl $0x74737478, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl $0xd, %eax\n" /* line 813 */
        "cmpw $3, -0x20(%ebp)\n" /* theCharCode */
        "cmovnew -0x20(%ebp), %ax\n" /* theCharCode */
        "movw %ax, -0x20(%ebp)\n" /* theCharCode */
        "movl 8(%ebp), %ecx\n" /* line 816 | this */
        "movl (%ecx), %edx\n"
        "movzwl %ax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *0x30(%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        ".Lf26ecc_000271aa:\n"
        "movl $0, 4(%esp)\n" /* line 846 */
        "movl $0, (%esp)\n"
        "calll MacTools_ShowCursor\n"
        ".Lf26ecc_000271be:\n"
        "calll MacGlobals_LockSystem\n" /* line 874 */
        "jmp .Lf26ecc_00026f76\n"
        ".Lf26ecc_000271c8:\n"
        "cmpl $0x6b, %ebx\n" /* line 830 | eventKind */
        "je .Lf26ecc_000271aa\n"
        "cmpl $0x6c, %ebx\n" /* eventKind */
        "jne .Lf26ecc_00026f76\n"
        "movl $1, (%esp)\n" /* line 854 */
        "calll MacTools_HideCursor\n"
        ".Lf26ecc_000271e2:\n"
        "calll MacGlobals_UnlockSystem\n" /* line 855 */
        "jmp .Lf26ecc_00026f76\n"
        /* { scope 2 */
        "leal -0x20(%ebp), %eax\n" /* line 37 | theCharCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d62746e, 8(%esp)\n"
        "movl $0x6d62746e, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "leal -0x36(%ebp), %ebx\n" /* theCommand */
        "movl %ebx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x51447074, 8(%esp)\n"
        "movl $0x6d6c6f63, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl %ebx, (%esp)\n" /* line 596 | eventKind */
        "calll MacDisplay_GlobalToLocal\n"
        "leal -0x24(%ebp), %eax\n" /* line 37 | theKeyCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x6b6d6f64, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "leal -0x28(%ebp), %eax\n" /* theClickCount */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x63636e74, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "cmpw $1, -0x20(%ebp)\n" /* line 604 | theCharCode */
        "je .Lf26ecc_0002790c\n"
        ".Lf26ecc_000272db:\n"
        "calll MacDisplay_InWindowMode\n" /* line 617 */
        "testb %al, %al\n"
        "je .Lf26ecc_000272f7\n"
        "movl -0x36(%ebp), %eax\n" /* theCommand */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_PointInWindow\n"
        "testb %al, %al\n"
        "je .Lf26ecc_00026f76\n"
        ".Lf26ecc_000272f7:\n"
        "movl 8(%ebp), %edx\n" /* line 622 | this */
        "movl (%edx), %eax\n"
        "movl 0x18(%eax), %edx\n"
        "movl -0x28(%ebp), %eax\n" /* theClickCount */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* theKeyCode */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x36(%ebp), %eax\n" /* theCommand */
        "movl %eax, 8(%esp)\n"
        "movzwl -0x20(%ebp), %eax\n" /* theCharCode */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll *%edx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        "leal -0x20(%ebp), %eax\n" /* line 37 | theCharCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d62746e, 8(%esp)\n"
        "movl $0x6d62746e, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "leal -0x36(%ebp), %ebx\n" /* theCommand */
        "movl %ebx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x51447074, 8(%esp)\n"
        "movl $0x6d6c6f63, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl %ebx, (%esp)\n" /* line 633 | eventKind */
        "calll MacDisplay_GlobalToLocal\n"
        "cmpw $1, -0x20(%ebp)\n" /* line 635 | theCharCode */
        "je .Lf26ecc_00027928\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 8(%ebp), %ecx\n" /* this */
        ".Lf26ecc_000273b2:\n"
        "movl (%edx), %eax\n" /* line 643 */
        "movl 0x1c(%eax), %edx\n"
        "movl -0x36(%ebp), %eax\n" /* theCommand */
        "movl %eax, 8(%esp)\n"
        "movzwl -0x20(%ebp), %eax\n" /* theCharCode */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *%edx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        "leal -0x1c(%ebp), %eax\n" /* line 37 | theDelta */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x51447074, 8(%esp)\n"
        "movl $0x6d647461, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "leal -0x36(%ebp), %ebx\n" /* theCommand */
        "movl %ebx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x51447074, 8(%esp)\n"
        "movl $0x6d6c6f63, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl %ebx, (%esp)\n" /* line 655 | eventKind */
        "calll MacDisplay_GlobalToLocal\n"
        "leal -0x20(%ebp), %eax\n" /* line 37 | theCharCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x6b6d6f64, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl 8(%ebp), %edx\n" /* line 678 | this */
        "movl (%edx), %eax\n"
        "movl 0x20(%eax), %edx\n"
        "movl -0x20(%ebp), %eax\n" /* theCharCode */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x36(%ebp), %eax\n" /* theCommand */
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* theDelta */
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_00027498:\n"
        "movl %eax, 4(%esp)\n" /* line 706 */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll *%edx\n"
        "jmp .Lf26ecc_00026f76\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 684 | this */
        "cmpb $0, 0x1e(%eax)\n"
        "jne .Lf26ecc_00026f76\n"
        /* { scope 2 */
        "movb $1, 0x1e(%eax)\n" /* line 690 */
        "leal -0x20(%ebp), %eax\n" /* line 37 | theCharCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6c6f6e67, 8(%esp)\n"
        "movl $0x6d77646c, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "leal -0x36(%ebp), %ebx\n" /* theCommand */
        "movl %ebx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x51447074, 8(%esp)\n"
        "movl $0x6d6c6f63, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl %ebx, (%esp)\n" /* line 697 | eventKind */
        "calll MacDisplay_GlobalToLocal\n"
        "leal -0x24(%ebp), %eax\n" /* line 37 | theKeyCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x6b6d6f64, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl 8(%ebp), %edx\n" /* line 706 | this */
        "movl (%edx), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "movl -0x24(%ebp), %eax\n" /* theKeyCode */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x36(%ebp), %eax\n" /* theCommand */
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* theCharCode */
        "jmp .Lf26ecc_00027498\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_00027585:\n"
        "movzwl -0x2a(%ebp), %eax\n" /* line 984 */
        "movl %eax, 4(%esp)\n"
        "movl -0x2e(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DisableMenuItem\n"
        "movl $1, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_000275a2:\n"
        "leal -0x36(%ebp), %eax\n" /* line 923 | theCommand, error2 */
        "movl %eax, 0x18(%esp)\n" /* error2 */
        "movl $0, 0x14(%esp)\n"
        "movl $0xe, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x68636d64, 8(%esp)\n"
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* inEvent */
        "calll GetEventParameter\n"
        "testl %eax, %eax\n" /* line 924 */
        "jne .Lf26ecc_00026f76\n"
        "movl -0x32(%ebp), %eax\n" /* line 926 */
        "cmpl $0x68696465, %eax\n"
        "je .Lf26ecc_000277dd\n"
        "cmpl $0x71756974, %eax\n"
        "je .Lf26ecc_000277ea\n"
        "cmpl $0x546f676c, %eax\n"
        "jne .Lf26ecc_00026f76\n"
        "calll MacTools_IsCursorVisible\n" /* line 949 */
        "testb %al, %al\n"
        "je .Lf26ecc_000278e9\n"
        "movl $1, (%esp)\n" /* line 951 */
        "calll MacTools_HideCursor\n"
        "calll MacGlobals_UnlockSystem\n" /* line 952 */
        "movl $1, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_0002762d:\n"
        "leal -0x36(%ebp), %ebx\n" /* line 899 | theCommand, eventKind */
        "movl %ebx, (%esp)\n" /* eventKind */
        "calll GetGlobalMouse\n"
        "movl %ebx, (%esp)\n" /* line 900 | eventKind */
        "calll MacDisplay_GlobalToLocal\n"
        "movl -0x36(%ebp), %eax\n" /* line 1408 | theCommand */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_PointInWindow\n"
        "testb %al, %al\n"
        "je .Lf26ecc_000277bd\n"
        "cmpb $0, sSystemCursorVisible\n" /* line 1410 */
        "je .Lf26ecc_00026f76\n"
        "calll SwitchToWinCursor\n" /* line 1412 */
        "movb $0, sSystemCursorVisible\n" /* line 1413 */
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_00027673:\n"
        "leal -0x20(%ebp), %eax\n" /* line 37 | theCharCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x54455854, 8(%esp)\n"
        "movl $0x6b636872, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "leal -0x24(%ebp), %eax\n" /* theKeyCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x6b636f64, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        "movl 8(%ebp), %eax\n" /* line 774 | this */
        "movl (%eax), %edx\n"
        "movl -0x24(%ebp), %eax\n" /* theKeyCode */
        "movl %eax, 8(%esp)\n"
        "movzbl -0x20(%ebp), %eax\n" /* theCharCode */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll *0x2c(%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_00027705:\n"
        "leal -0x24(%ebp), %eax\n" /* line 37 | theKeyCode */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x6b6d6f64, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetEventParameter\n"
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 1382 | this */
        "movl 0x18(%eax), %edx\n" /* wasDown */
        "movl %edx, %eax\n" /* wasDown */
        "shrl $9, %eax\n"
        "movl %eax, %ecx\n" /* wasDown */
        "andb $1, %cl\n" /* wasDown */
        "movl -0x24(%ebp), %ebx\n" /* line 1383 | theKeyCode, eventKind */
        "movl %ebx, %eax\n" /* eventKind, nowDown */
        "shrl $9, %eax\n" /* nowDown */
        "andb $1, %al\n" /* nowDown */
        "cmpb %al, %cl\n" /* line 1385 */
        "je .Lf26ecc_0002776a\n"
        "testb %cl, %cl\n" /* line 1387 */
        "jne .Lf26ecc_000277ff\n"
        "testb %al, %al\n" /* line 1391 */
        "jne .Lf26ecc_000278c0\n"
        /* } scope */
        /* { scope 3 */
        ".Lf26ecc_0002776a:\n"
        "movl %edx, %eax\n" /* line 1382 | wasDown */
        "shrl $0xc, %eax\n"
        "movl %eax, %ecx\n" /* wasDown */
        "andb $1, %cl\n" /* wasDown */
        "movl %ebx, %eax\n" /* line 1383 | eventKind, nowDown */
        "shrl $0xc, %eax\n" /* nowDown */
        "andb $1, %al\n" /* nowDown */
        "cmpb %al, %cl\n" /* line 1385 */
        "je .Lf26ecc_0002778f\n"
        "testb %cl, %cl\n" /* line 1387 */
        "jne .Lf26ecc_00027828\n"
        "testb %al, %al\n" /* line 1391 */
        "jne .Lf26ecc_00027874\n"
        /* } scope */
        /* { scope 3 */
        ".Lf26ecc_0002778f:\n"
        "shrl $0xb, %edx\n" /* line 1382 | wasDown */
        "andb $1, %dl\n" /* wasDown */
        "movl %ebx, %eax\n" /* line 1383 | eventKind, nowDown */
        "shrl $0xb, %eax\n" /* nowDown */
        "andb $1, %al\n" /* nowDown */
        "cmpb %al, %dl\n" /* line 1385 */
        "je .Lf26ecc_000277b0\n"
        "testb %dl, %dl\n" /* line 1387 */
        "jne .Lf26ecc_00027851\n"
        "testb %al, %al\n" /* line 1391 */
        "jne .Lf26ecc_0002789d\n"
        /* } scope */
        ".Lf26ecc_000277b0:\n"
        "movl 8(%ebp), %eax\n" /* line 790 | this */
        "movl %ebx, 0x18(%eax)\n" /* eventKind */
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_000277bd:\n"
        "cmpb $0, sSystemCursorVisible\n" /* line 1418 */
        "jne .Lf26ecc_00026f76\n"
        "calll SwitchToMacCursor\n" /* line 1420 */
        "movb $1, sSystemCursorVisible\n" /* line 1421 */
        "xorl %eax, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_000277dd:\n"
        "calll MacDisplay_IsFullscreen\n" /* line 938 */
        "movzbl %al, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        ".Lf26ecc_000277ea:\n"
        "movl 8(%ebp), %ecx\n" /* line 930 | this */
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *0x38(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf26ecc_000277ff:\n"
        "movl 8(%ebp), %edx\n" /* line 1389 | this */
        "movl (%edx), %eax\n"
        "movl $0x38, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%eax)\n"
        "movl -0x24(%ebp), %ebx\n" /* theKeyCode, eventKind */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x18(%ecx), %edx\n"
        "jmp .Lf26ecc_0002776a\n"
        /* } scope */
        /* { scope 3 */
        ".Lf26ecc_00027828:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl (%edx), %eax\n"
        "movl $0x3b, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%eax)\n"
        "movl -0x24(%ebp), %ebx\n" /* theKeyCode, eventKind */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x18(%ecx), %edx\n"
        "jmp .Lf26ecc_0002778f\n"
        /* } scope */
        /* { scope 3 */
        ".Lf26ecc_00027851:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl (%edx), %eax\n"
        "movl $0x3a, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%eax)\n"
        "movl -0x24(%ebp), %ebx\n" /* theKeyCode, eventKind */
        "jmp .Lf26ecc_000277b0\n"
        /* } scope */
        /* { scope 3 */
        ".Lf26ecc_00027874:\n"
        "movl 8(%ebp), %edx\n" /* line 1393 | this */
        "movl (%edx), %eax\n"
        "movl $0x3b, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x28(%eax)\n"
        "movl -0x24(%ebp), %ebx\n" /* theKeyCode, eventKind */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x18(%ecx), %edx\n"
        "jmp .Lf26ecc_0002778f\n"
        /* } scope */
        /* { scope 3 */
        ".Lf26ecc_0002789d:\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl (%ecx), %eax\n"
        "movl $0x3a, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *0x28(%eax)\n"
        "movl -0x24(%ebp), %ebx\n" /* theKeyCode, eventKind */
        "jmp .Lf26ecc_000277b0\n"
        /* } scope */
        /* { scope 3 */
        ".Lf26ecc_000278c0:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl (%edx), %eax\n"
        "movl $0x38, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x28(%eax)\n"
        "movl -0x24(%ebp), %ebx\n" /* theKeyCode, eventKind */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x18(%ecx), %edx\n"
        "jmp .Lf26ecc_0002776a\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_000278e9:\n"
        "movl $0, 4(%esp)\n" /* line 956 */
        "movl $0, (%esp)\n"
        "calll MacTools_ShowCursor\n"
        "calll MacGlobals_LockSystem\n" /* line 957 */
        "movl $1, %eax\n"
        "jmp .Lf26ecc_00026f78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_0002790c:\n"
        "testb $1, -0x23(%ebp)\n" /* line 609 */
        "je .Lf26ecc_000272db\n"
        "movw $2, -0x20(%ebp)\n" /* line 611 | theCharCode */
        "movl 8(%ebp), %ecx\n" /* line 612 | this */
        "movb $1, 0x14(%ecx)\n"
        "jmp .Lf26ecc_000272db\n"
        /* } scope */
        /* { scope 2 */
        ".Lf26ecc_00027928:\n"
        "movl 8(%ebp), %eax\n" /* line 635 | this */
        "cmpb $0, 0x14(%eax)\n"
        "je .Lf26ecc_00027946\n"
        "movw $2, -0x20(%ebp)\n" /* line 637 | theCharCode */
        "movb $0, 0x14(%eax)\n" /* line 638 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 8(%ebp), %ecx\n" /* this */
        "jmp .Lf26ecc_000273b2\n"
        ".Lf26ecc_00027946:\n"
        "movl %eax, %edx\n"
        "movl %eax, %ecx\n"
        "jmp .Lf26ecc_000273b2\n"
    );
}

