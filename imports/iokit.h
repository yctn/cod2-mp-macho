#ifndef IMPORTS_IOKIT_H
#define IMPORTS_IOKIT_H

/* Import stubs for IOKit */

int IOBSDNameMatching(); /* _IOBSDNameMatching */
int IOIteratorNext(); /* _IOIteratorNext */
int IOMasterPort(); /* _IOMasterPort */
int IOObjectConformsTo(); /* _IOObjectConformsTo */
int IOObjectGetClass(); /* _IOObjectGetClass */
int IOObjectRelease(); /* _IOObjectRelease */
int IOObjectRetain(); /* _IOObjectRetain */
int IORegistryEntryCreateCFProperty(); /* _IORegistryEntryCreateCFProperty */
int IORegistryEntryCreateIterator(); /* _IORegistryEntryCreateIterator */
int IORegistryEntryGetParentEntry(); /* _IORegistryEntryGetParentEntry */
int IOServiceGetMatchingServices(); /* _IOServiceGetMatchingServices */

#endif /* IMPORTS_IOKIT_H */
