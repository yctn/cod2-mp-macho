/* ASM dump from: MacWinCursor.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacWinCursor.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacSwap.h"
 */

static EventLoopTimerRef sTimerRef; /* 0x334c14 */
__attribute__((used)) static bool sVisibleCursor = 1; /* 0x3080a0 */
__attribute__((used)) static HCURSOR sCurrentWinCursor = (HCURSOR)-1; /* 0x3080a4 */
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
bool WinIcon_Load(const WinIcon * _this, const UInt8 *inIcon)
{ return 0; }

/* line 172 */
HCURSOR SetWinCursor(HCURSOR hCursor)
{ return 0; }

/* line 261 */
void SwitchToWinCursor(void)
{ }

/* line 250 */
void SwitchToMacCursor(void)
{ }

/* line 112 */
void CursorTimerProc(void)
{ }

/* line 898 */
void __static_initialization_and_destruction_0(void)
{ }

/* line 900 */
void GLOBAL__D_LoadCursorFromFileA(void) /* global destructors keyed to LoadCursorFromFileA */
{ }

/* line 899 */
void GLOBAL__I_LoadCursorFromFileA(void) /* global constructors keyed to LoadCursorFromFileA */
{ }

/* line 275 */
void WinIcon_WinIcon(const WinIcon * _this)
{ }

/* overload skip: WinIcon_WinIcon (0xcbbc) */

/* line 649 */
bool WinCursor_ReadCursor(const WinCursor * _this, const UInt8 *inCursor)
{ return 0; }

/* line 613 */
bool WinCursor_Load(const WinCursor * _this, const char *inFileName)
{ return 0; }

/* line 127 */
HCURSOR LoadCursorFromFileA(LPCSTR lpFileName)
{ return 0; }

/* line 287 */
void ZN7WinIconD2Ev(void) /* WinIcon_~WinIcon */
{ }

/* line 287 */
void ZN7WinIconD1Ev(void) /* WinIcon_~WinIcon */
{ }

/* line 555 */
void WinCursor_WinCursor(const WinCursor * _this, const WinCursor *inCursor)
{ }

/* overload skip: WinCursor_WinCursor (0xd4de) */

/* line 589 */
void ZN9WinCursorD2Ev(void) /* WinCursor_~WinCursor */
{ }

/* line 589 */
void ZN9WinCursorD1Ev(void) /* WinCursor_~WinCursor */
{ }

/* line 249 */
void ZNSt6vectorI9WinCursorSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<WinCursor, std_allocator<WinCursor> >__M_insert_aux */
{ }

