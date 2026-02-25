#ifndef MAC_TOOLS_MACGLOBALS_H_H
#define MAC_TOOLS_MACGLOBALS_H_H

/* Reconstructed from: Mac/Tools/MacGlobals.h */
/* Types attributed via N_BINCL cross-reference */

struct AlertStdCFStringAlertParamRec;

struct AlertStdCFStringAlertParamRec {
    UInt32 version;
    Boolean movable;
    Boolean helpButton;
    CFStringRef defaultText;
    CFStringRef cancelText;
    CFStringRef otherText;
    SInt16 defaultButton;
    SInt16 cancelButton;
    UInt16 position;
    OptionBits flags;
};

#endif /* MAC_TOOLS_MACGLOBALS_H_H */
