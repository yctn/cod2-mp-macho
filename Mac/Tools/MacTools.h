#ifndef MAC_TOOLS_MACTOOLS_H_H
#define MAC_TOOLS_MACTOOLS_H_H

/* Reconstructed from: Mac/Tools/MacTools.h */
/* Types attributed via N_BINCL cross-reference */

struct HICommand;

struct HICommand {
    UInt32 attributes;
    UInt32 commandID;
    struct { MenuRef menuRef; MenuItemIndex menuItemIndex; } menu;
};

#endif /* MAC_TOOLS_MACTOOLS_H_H */
