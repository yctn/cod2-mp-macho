/* ASM dump from: MacBuilder.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacBuilder.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacTools.h"
 */

/* Carbon types not in common_types.h */
typedef struct { short top; short left; short bottom; short right; } Rect;

static ControlKeyFilterUPP sControlKeyFilterUPP; /* 0x334708 */
static ControlEditTextValidationUPP sControlValidationUPP; /* 0x334704 */
static MacBuilderProcPtr sBuilderProcPtr; /* 0x334700 */

void StPortState_StPortState(StPortState *_this, WindowRef inWindow);
void ZN11StPortStateD1Ev(StPortState *_this);
ControlPartCode UserPaneHitTestProc(ControlRef theControl, struct Point theWherePt);
WindowRef MacBuilder_BuildWindow(CFStringRef inName, CFStringRef inNibName, int inStandardHandler, MacBuilderProcPtr inBuilderProc);
UInt32 MacBuilder_RunModalWindow(WindowRef inWindow);
void MacBuilder_ReleaseWindow(WindowRef inWindow);
ControlRef MacBuilder_GetControlRef(WindowRef inWindow, SInt32 inID);
static inflate_blocks_statef ValidationProc(ControlRef inControlRef);
static OSStatus HandleStandardEvents(EventRef inEvent, inflate_blocks_statef *inUserData);
static ControlKeyFilterResult KeyFilterProc(ControlRef inControlRef, SInt16 *ioCharCode, EventModifiers *ioModifiers);
inflate_blocks_statef MacBuilder_SetTextObjectFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize);
void MacBuilder_GetControlText(WindowRef inWindow, SInt32 inID, int inBufferSize, char *outText);
void MacBuilder_SetControlText(WindowRef inWindow, SInt32 inID, const char *inText);
void MacBuilder_SetControlVisible(WindowRef inWindow, SInt32 inID, int inVisible);
void MacBuilder_SetControlEnabled(WindowRef inWindow, SInt32 inID, int inEnabled);
void MacBuilder_SetControlFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize);
void MacBuilder_SetControlFocus(WindowRef inWindow, SInt32 inID);
void MacBuilder_SetupUserPaneControl(WindowRef inWindow, SInt32 inID, ControlUserPaneDrawProcPtr inDrawProc, ControlUserPaneTrackingProcPtr inTrackingProc);
inflate_blocks_statef MacBuilder_SetEditTextHook(WindowRef inWindow, SInt32 inID, MacBuilderEditHookPtr inHookProc, int inCharLimit);
TXNObject MacBuilder_GetTextObject(WindowRef inWindow, SInt32 inID);

/* StPortState constructor */
void StPortState_StPortState(StPortState *_this, WindowRef inWindow)
{
    GetPort(_this);
    SetPortWindowPort(inWindow);
}

/* StPortState::~StPortState */
void ZN11StPortStateD1Ev(StPortState *_this)
{
    SetPort(*(void **)_this);
}

/* line 143 */
ControlPartCode UserPaneHitTestProc(ControlRef theControl, struct Point theWherePt)
{
    Rect bounds;
    GetControlBounds(theControl, &bounds);
    return PtInRect(theWherePt, &bounds) != 0;
}

/* line 167 */
WindowRef MacBuilder_BuildWindow(CFStringRef inName, CFStringRef inNibName, int inStandardHandler, MacBuilderProcPtr inBuilderProc)
{
    return 0;
}

/* line 221 */
UInt32 MacBuilder_RunModalWindow(WindowRef inWindow)
{
    InitCursor();
    ShowWindow(inWindow);
    RunAppModalLoopForWindow(inWindow);
    HideWindow(inWindow);
    return GetWRefCon(inWindow);
}

/* line 235 */
void MacBuilder_ReleaseWindow(WindowRef inWindow)
{
    DisposeWindow(inWindow);
    sBuilderProcPtr = 0;
}

/* line 249 */
ControlRef MacBuilder_GetControlRef(WindowRef inWindow, SInt32 inID)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        return NULL;
    return theControl;
}

/* line 655 */
static inflate_blocks_statef ValidationProc(ControlRef inControlRef)
{
}

/* line 34 */
static OSStatus HandleStandardEvents(EventRef inEvent, inflate_blocks_statef *inUserData)
{
    return 0;
}

/* line 598 */
static ControlKeyFilterResult KeyFilterProc(ControlRef inControlRef, SInt16 *ioCharCode, EventModifiers *ioModifiers)
{
    return 0;
}

/* line 751 */
inflate_blocks_statef MacBuilder_SetTextObjectFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize)
{
}

/* line 305 */
void MacBuilder_GetControlText(WindowRef inWindow, SInt32 inID, int inBufferSize, char *outText)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    *outText = '\0';

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        theControl = NULL;

    if (!theControl)
        return;

    Size actualSize;
    error = GetControlData(theControl, 0, 0x74657874 /* 'text' */, (short)inBufferSize - 1, outText, &actualSize);
    if (error == 0)
        outText[actualSize] = '\0';
}

/* line 327 */
void MacBuilder_SetControlText(WindowRef inWindow, SInt32 inID, const char *inText)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        theControl = NULL;

    if (!theControl)
        return;

    SetControlData(theControl, 0, 0x74657874 /* 'text' */, strlen(inText), inText);
}

/* line 357 */
void MacBuilder_SetControlVisible(WindowRef inWindow, SInt32 inID, int inVisible)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        theControl = NULL;

    if (!theControl)
        return;

    if (inVisible)
        ShowControl(theControl);
    else
        HideControl(theControl);
}

/* line 379 */
void MacBuilder_SetControlEnabled(WindowRef inWindow, SInt32 inID, int inEnabled)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        theControl = NULL;

    if (!theControl)
        return;

    if (inEnabled)
        EnableControl(theControl);
    else
        DisableControl(theControl);
}

/* line 402 */
void MacBuilder_SetControlFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        theControl = NULL;

    if (!theControl)
        return;

    ControlFontStyleRec fontStyle;
    fontStyle.flags = 5;
    fontStyle.font = (short)inFontFamilyID;
    fontStyle.size = (short)inFontSize;
    SetControlFontStyle(theControl, &fontStyle);
}

/* line 421 */
void MacBuilder_SetControlFocus(WindowRef inWindow, SInt32 inID)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        theControl = NULL;

    if (!theControl)
        return;

    ControlKind kind;
    if (GetControlKind(theControl, &kind) != 0)
        return;

    if (kind.kind == 0x65747874 /* 'etxt' */ || kind.kind == 0x65757478 /* 'eutx' */)
    {
        SetKeyboardFocus(inWindow, theControl, 5);
    }
}

/* line 522 */
void MacBuilder_SetupUserPaneControl(WindowRef inWindow, SInt32 inID, ControlUserPaneDrawProcPtr inDrawProc, ControlUserPaneTrackingProcPtr inTrackingProc)
{
    ControlID controlID;
    ControlRef theControl = NULL;

    controlID.signature = 0x4974656d; /* 'Item' */
    controlID.id = inID;

    OSStatus error = GetControlByID(inWindow, &controlID, &theControl);
    if (error != 0)
        theControl = NULL;

    if (!theControl)
        return;

    ControlUserPaneDrawUPP drawUPP = NewControlUserPaneDrawUPP(inDrawProc);
    SetControlData(theControl, 0, 0x64726177 /* 'draw' */, 4, &drawUPP);

    if (!inTrackingProc)
        return;

    ControlUserPaneHitTestUPP testUPP = NewControlUserPaneHitTestUPP(UserPaneHitTestProc);
    SetControlData(theControl, 0, 0x68697474 /* 'hitt' */, 4, &testUPP);

    ControlUserPaneTrackingUPP trackingUPP = NewControlUserPaneTrackingUPP(inTrackingProc);
    SetControlData(theControl, 0, 0x7472616b /* 'trak' */, 4, &trackingUPP);
}

/* line 673 */
inflate_blocks_statef MacBuilder_SetEditTextHook(WindowRef inWindow, SInt32 inID, MacBuilderEditHookPtr inHookProc, int inCharLimit)
{
}

/* line 726 */
TXNObject MacBuilder_GetTextObject(WindowRef inWindow, SInt32 inID)
{
    return 0;
}

