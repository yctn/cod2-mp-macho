/* Platform stubs for carbon (macOS → Linux) */
#include "carbon_stubs.h"

void RunApplicationEventLoop(void)
{
    /* TODO */
}

void QuitApplicationEventLoop(void)
{
}

OSStatus InstallEventHandler(EventTargetRef target, EventHandlerUPP handler, unsigned int numTypes, const void *list, void *userData, EventHandlerRef *outRef)
{
    if (outRef) *outRef = 0; return 0;
}

OSStatus RemoveEventHandler(EventHandlerRef ref)
{
    return 0;
}

EventTargetRef GetApplicationEventTarget(void)
{
    return (EventTargetRef)0;
}

EventTargetRef GetWindowEventTarget(WindowRef window)
{
    return (EventTargetRef)0;
}

OSStatus GetEventParameter(EventRef event, OSType name, OSType type, void *outType, unsigned int bufSize, unsigned int *outSize, void *outData)
{
    return -1;
}

EventClass GetEventClass(EventRef event)
{
    return 0;
}

EventKind GetEventKind(EventRef event)
{
    return 0;
}

void GetMouse(Point *p)
{
    if (p) { p->h = 0; p->v = 0; }
}

Boolean Button(void)
{
    return 0;
}

unsigned int TickCount(void)
{
    return 0;
}

void GetKeys(void *keys)
{
}

GDHandle GetMainDevice(void)
{
    return (GDHandle)0;
}

GDHandle GetDeviceList(void)
{
    return (GDHandle)0;
}

GDHandle GetNextDevice(GDHandle dev)
{
    return (GDHandle)0;
}

CGrafPtr GetWindowPort(WindowRef window)
{
    return (CGrafPtr)0;
}

void HideWindow(WindowRef window)
{
}

void ShowWindow(WindowRef window)
{
}

void DisposeWindow(WindowRef window)
{
}

void SetWindowBounds(WindowRef window, int regionCode, const Rect *bounds)
{
}

OSStatus SetWindowGroupLevel(void *group, int level)
{
    return 0;
}

void ShowCursor(void)
{
}

void HideCursor(void)
{
}

void ObscureCursor(void)
{
}

CFStringRef CFStringCreateWithCString(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding)
{
    return (CFStringRef)cStr;
}

int CFStringGetCString(CFStringRef str, char *buffer, int bufferSize, CFStringEncoding encoding)
{
    return 0;
}

CFBundleRef CFBundleGetMainBundle(void)
{
    return (CFBundleRef)0;
}

CFURLRef CFBundleCopyBundleURL(CFBundleRef bundle)
{
    return (CFURLRef)0;
}

int CFURLGetFileSystemRepresentation(CFURLRef url, int resolveAgainstBase, unsigned char *buffer, int maxBufLen)
{
    return 0;
}

void CFRelease(CFTypeRef cf)
{
}
