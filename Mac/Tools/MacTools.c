/* ASM dump from: MacTools.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacTools.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacGlobals.h"
 *   #include "Mac/Tools/MacMemory.h"
 */

__attribute__((used)) static UInt8 sSystemCursorVisible[32] = { 1 }; /* 0x308080 */
static Point sGlobalMouse; /* 0x334b80 */

void MacTools_SetCursorID(int inCursorID);
void MacTools_ShowCursor(int inWarpIt, const Point *inWarpPt);
void MacTools_HideCursor(int inWarpIt);
Boolean MacTools_IsCursorVisible(void);
SInt16 MacTools_FindDiscVolume(CFStringRef inVolumeName, char *outVolumePath);
void MacTools_CenterRect(MacRect *ioRect, const MacRect *inBounds);
void MacTools_Sleep(UInt32 inMillisecondsToSleep);
void MacTools_SendQuitAppleEvent(const ProcessSerialNumber *inPSN);
Boolean MacTools_FindApplicationPSN(OSType inCreatorCode, ProcessSerialNumber *outPSN);
SInt32 MacTools_GetDictionaryValue(CFDictionaryRef inDictionaryRef, CFStringRef inKeyRef);
Boolean MacTools_GetIORegistryValue(io_registry_entry_t inEntryRef, CFStringRef inKeyRef, char *outValue);
Boolean MacTools_PostPrivateEventToWindow(WindowRef inWindow, UInt32 inMessage, UInt32 inParam1, UInt32 inParam2);
Boolean MacTools_QuestionAlert(CFStringRef inMessage1, CFStringRef inMessage2);
void ZN12StShowCursorD1Ev(void); /* StShowCursor_~StShowCursor */
void MacTools_MessageAlert(CFStringRef inMessage1, CFStringRef inMessage2, int inStop);
void MacTools_MessageAlertFromKey(CFStringRef inKeyRef, int inStop);
Boolean SearchForApplication(OSType inCreator, FSRef *outAppRef);
void StShowCursor_StShowCursor(const StShowCursor * _this);
void ZNSt6vectorI5FSRefSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void); /* std_vector<FSRef, std_allocator<FSRef> >__M_insert_aux */

/* line 48 */
void MacTools_SetCursorID(int inCursorID)
{ }

/* line 62 */
void MacTools_ShowCursor(int inWarpIt, const Point *inWarpPt)
{ }

/* line 95 */
void MacTools_HideCursor(int inWarpIt)
{ }

/* line 143 */
Boolean MacTools_IsCursorVisible(void)
{ return 0; }

/* line 481 */
SInt16 MacTools_FindDiscVolume(CFStringRef inVolumeName, char *outVolumePath)
{ return 0; }

/* line 594 */
void MacTools_CenterRect(MacRect *ioRect, const MacRect *inBounds)
{ }

/* line 612 */
void MacTools_Sleep(UInt32 inMillisecondsToSleep)
{ }

/* line 660 */
void MacTools_SendQuitAppleEvent(const ProcessSerialNumber *inPSN)
{ }

/* line 716 */
Boolean MacTools_FindApplicationPSN(OSType inCreatorCode, ProcessSerialNumber *outPSN)
{ return 0; }

/* line 750 */
SInt32 MacTools_GetDictionaryValue(CFDictionaryRef inDictionaryRef, CFStringRef inKeyRef)
{ return 0; }

/* line 780 */
Boolean MacTools_GetIORegistryValue(io_registry_entry_t inEntryRef, CFStringRef inKeyRef, char *outValue)
{ return 0; }

/* overload skip: MacTools_GetIORegistryValue (0xaf82) */

/* line 935 */
Boolean MacTools_PostPrivateEventToWindow(WindowRef inWindow, UInt32 inMessage, UInt32 inParam1, UInt32 inParam2)
{ return 0; }

/* line 1105 */
Boolean MacTools_QuestionAlert(CFStringRef inMessage1, CFStringRef inMessage2)
{ return 0; }

/* overload skip: MacTools_QuestionAlert (0xb19e) */

/* line 1158 */
void ZN12StShowCursorD1Ev(void) /* StShowCursor_~StShowCursor */
{ }

/* line 1028 */
void MacTools_MessageAlert(CFStringRef inMessage1, CFStringRef inMessage2, int inStop)
{ }

/* overload skip: MacTools_MessageAlert (0xb2d0) */

/* overload skip: MacTools_MessageAlert (0xb2f4) */

/* line 962 */
void MacTools_MessageAlertFromKey(CFStringRef inKeyRef, int inStop)
{ }

/* line 156 */
Boolean SearchForApplication(OSType inCreator, FSRef *outAppRef)
{ return 0; }

/* line 1147 */
void StShowCursor_StShowCursor(const StShowCursor * _this)
{ }

/* line 249 */
void ZNSt6vectorI5FSRefSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<FSRef, std_allocator<FSRef> >__M_insert_aux */
{ }
