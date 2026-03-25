"""MacOS→Linux platform API stub generator.

Generates stub implementations for macOS-specific frameworks that the
COD2 binary links against. On Linux, these are replaced with either:
- Direct pass-through (OpenGL → GL/gl.h)
- No-op stubs (AGL, Carbon, AudioUnit, IOKit, QuickTime)

Each framework gets a .c and .h file pair in the stubs/ directory.
"""

import os
from .macho_loader import MachOLoader
from .imports import _classify_symbol


# AGL (Apple GL context management) stub definitions
AGL_STUBS = {
    'header_includes': ['<GL/gl.h>', '<GL/glx.h>'],
    'typedefs': [
        'typedef void *AGLContext;',
        'typedef void *AGLPixelFormat;',
        'typedef void *AGLDrawable;',
        'typedef int AGLError;',
        'typedef unsigned int GLenum;',
        'typedef int GLint;',
    ],
    'functions': [
        ('AGLPixelFormat', 'aglChoosePixelFormat', 'void *gdevs, int ndev, const int *attribs',
         'return (AGLPixelFormat)0; /* TODO: implement with GLX */'),
        ('AGLContext', 'aglCreateContext', 'AGLPixelFormat pix, AGLContext share',
         'return (AGLContext)0; /* TODO: implement with GLX */'),
        ('int', 'aglDestroyContext', 'AGLContext ctx',
         'return 1;'),
        ('int', 'aglSetCurrentContext', 'AGLContext ctx',
         'return 1;'),
        ('int', 'aglSetDrawable', 'AGLContext ctx, AGLDrawable draw',
         'return 1;'),
        ('int', 'aglSetFullScreen', 'AGLContext ctx, int width, int height, int freq, int device',
         'return 1;'),
        ('void', 'aglDestroyPixelFormat', 'AGLPixelFormat pix',
         ''),
        ('int', 'aglUpdateContext', 'AGLContext ctx',
         'return 1;'),
        ('void', 'aglSwapBuffers', 'AGLContext ctx',
         '/* TODO: glXSwapBuffers */'),
        ('AGLError', 'aglGetError', 'void',
         'return 0; /* AGL_NO_ERROR */'),
        ('const char *', 'aglErrorString', 'AGLError code',
         'return "no error";'),
        ('int', 'aglSetInteger', 'AGLContext ctx, GLenum pname, const GLint *params',
         'return 1;'),
        ('int', 'aglGetInteger', 'AGLContext ctx, GLenum pname, GLint *params',
         'if (params) *params = 0; return 1;'),
    ],
}

# Carbon (event handling, window management) stub definitions
CARBON_STUBS = {
    'header_includes': [],
    'typedefs': [
        'typedef void *WindowRef;',
        'typedef void *EventRef;',
        'typedef void *EventHandlerRef;',
        'typedef void *EventHandlerUPP;',
        'typedef void *EventTargetRef;',
        'typedef void *MenuRef;',
        'typedef unsigned int EventClass;',
        'typedef unsigned int EventKind;',
        'typedef unsigned int OSStatus;',
        'typedef unsigned int OSType;',
        'typedef int OSErr;',
        'typedef unsigned int UInt32;',
        'typedef unsigned short UInt16;',
        'typedef unsigned char UInt8;',
        'typedef int SInt32;',
        'typedef short SInt16;',
        'typedef signed char SInt8;',
        'typedef int Boolean;',
        'typedef unsigned int FourCharCode;',
        'typedef struct { short v; short h; } Point;',
        'typedef struct { short top; short left; short bottom; short right; } Rect;',
        'typedef void *GDHandle;',
        'typedef void *CGrafPtr;',
        'typedef void *DialogRef;',
        'typedef void *ControlRef;',
        'typedef void *CFStringRef;',
        'typedef void *CFURLRef;',
        'typedef void *CFBundleRef;',
        'typedef void *CFDictionaryRef;',
        'typedef const void *CFAllocatorRef;',
        'typedef unsigned int CFStringEncoding;',
        'typedef unsigned int CFTypeID;',
        'typedef void *CFTypeRef;',
    ],
    'functions': [
        ('void', 'RunApplicationEventLoop', 'void', '/* TODO */'),
        ('void', 'QuitApplicationEventLoop', 'void', ''),
        ('OSStatus', 'InstallEventHandler', 'EventTargetRef target, EventHandlerUPP handler, unsigned int numTypes, const void *list, void *userData, EventHandlerRef *outRef',
         'if (outRef) *outRef = 0; return 0;'),
        ('OSStatus', 'RemoveEventHandler', 'EventHandlerRef ref', 'return 0;'),
        ('EventTargetRef', 'GetApplicationEventTarget', 'void', 'return (EventTargetRef)0;'),
        ('EventTargetRef', 'GetWindowEventTarget', 'WindowRef window', 'return (EventTargetRef)0;'),
        ('OSStatus', 'GetEventParameter', 'EventRef event, OSType name, OSType type, void *outType, unsigned int bufSize, unsigned int *outSize, void *outData',
         'return -1;'),
        ('EventClass', 'GetEventClass', 'EventRef event', 'return 0;'),
        ('EventKind', 'GetEventKind', 'EventRef event', 'return 0;'),
        ('void', 'GetMouse', 'Point *p', 'if (p) { p->h = 0; p->v = 0; }'),
        ('Boolean', 'Button', 'void', 'return 0;'),
        ('unsigned int', 'TickCount', 'void', 'return 0;'),
        ('void', 'GetKeys', 'void *keys', ''),
        ('GDHandle', 'GetMainDevice', 'void', 'return (GDHandle)0;'),
        ('GDHandle', 'GetDeviceList', 'void', 'return (GDHandle)0;'),
        ('GDHandle', 'GetNextDevice', 'GDHandle dev', 'return (GDHandle)0;'),
        ('CGrafPtr', 'GetWindowPort', 'WindowRef window', 'return (CGrafPtr)0;'),
        ('void', 'HideWindow', 'WindowRef window', ''),
        ('void', 'ShowWindow', 'WindowRef window', ''),
        ('void', 'DisposeWindow', 'WindowRef window', ''),
        ('void', 'SetWindowBounds', 'WindowRef window, int regionCode, const Rect *bounds', ''),
        ('OSStatus', 'SetWindowGroupLevel', 'void *group, int level', 'return 0;'),
        ('void', 'ShowCursor', 'void', ''),
        ('void', 'HideCursor', 'void', ''),
        ('void', 'ObscureCursor', 'void', ''),
        ('CFStringRef', 'CFStringCreateWithCString', 'CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding',
         'return (CFStringRef)cStr;'),
        ('int', 'CFStringGetCString', 'CFStringRef str, char *buffer, int bufferSize, CFStringEncoding encoding',
         'return 0;'),
        ('CFBundleRef', 'CFBundleGetMainBundle', 'void', 'return (CFBundleRef)0;'),
        ('CFURLRef', 'CFBundleCopyBundleURL', 'CFBundleRef bundle', 'return (CFURLRef)0;'),
        ('int', 'CFURLGetFileSystemRepresentation', 'CFURLRef url, int resolveAgainstBase, unsigned char *buffer, int maxBufLen',
         'return 0;'),
        ('void', 'CFRelease', 'CFTypeRef cf', ''),
    ],
}

# Audio (CoreAudio, AudioUnit, AudioToolbox) stub definitions
AUDIO_STUBS = {
    'header_includes': [],
    'typedefs': [
        'typedef void *AudioUnit;',
        'typedef void *AUGraph;',
        'typedef void *AUNode;',
        'typedef unsigned int AudioUnitPropertyID;',
        'typedef unsigned int AudioUnitScope;',
        'typedef unsigned int AudioUnitElement;',
        'typedef int OSStatus;',
        'typedef unsigned int UInt32;',
        'typedef struct { double mSampleRate; unsigned int mFormatID; unsigned int mFormatFlags; unsigned int mBytesPerPacket; unsigned int mFramesPerPacket; unsigned int mBytesPerFrame; unsigned int mChannelsPerFrame; unsigned int mBitsPerChannel; unsigned int mReserved; } AudioStreamBasicDescription;',
        'typedef struct { unsigned int componentType; unsigned int componentSubType; unsigned int componentManufacturer; unsigned int componentFlags; unsigned int componentFlagsMask; } ComponentDescription;',
        'typedef void *AudioDeviceID;',
    ],
    'functions': [
        ('OSStatus', 'NewAUGraph', 'AUGraph *outGraph', 'if (outGraph) *outGraph = 0; return 0;'),
        ('OSStatus', 'DisposeAUGraph', 'AUGraph graph', 'return 0;'),
        ('OSStatus', 'AUGraphInitialize', 'AUGraph graph', 'return 0;'),
        ('OSStatus', 'AUGraphStart', 'AUGraph graph', 'return 0;'),
        ('OSStatus', 'AUGraphStop', 'AUGraph graph', 'return 0;'),
        ('OSStatus', 'AUGraphAddNode', 'AUGraph graph, const ComponentDescription *desc, AUNode *outNode',
         'if (outNode) *outNode = 0; return 0;'),
        ('OSStatus', 'AUGraphConnectNodeInput', 'AUGraph graph, AUNode srcNode, unsigned int srcOutput, AUNode destNode, unsigned int destInput',
         'return 0;'),
        ('OSStatus', 'AUGraphNodeInfo', 'AUGraph graph, AUNode node, ComponentDescription *outDesc, AudioUnit *outUnit',
         'if (outUnit) *outUnit = 0; return 0;'),
        ('OSStatus', 'AUGraphOpen', 'AUGraph graph', 'return 0;'),
        ('OSStatus', 'AudioUnitSetProperty', 'AudioUnit unit, AudioUnitPropertyID id, AudioUnitScope scope, AudioUnitElement elem, const void *data, UInt32 size',
         'return 0;'),
        ('OSStatus', 'AudioUnitGetProperty', 'AudioUnit unit, AudioUnitPropertyID id, AudioUnitScope scope, AudioUnitElement elem, void *data, UInt32 *size',
         'return 0;'),
        ('OSStatus', 'AudioUnitSetParameter', 'AudioUnit unit, unsigned int paramID, unsigned int scope, unsigned int elem, float value, unsigned int offset',
         'return 0;'),
        ('OSStatus', 'AudioUnitRender', 'AudioUnit unit, unsigned int *ioActionFlags, const void *inTimeStamp, unsigned int inOutputBusNumber, unsigned int inNumberFrames, void *ioData',
         'return 0;'),
        ('OSStatus', 'AudioOutputUnitStart', 'AudioUnit unit', 'return 0;'),
        ('OSStatus', 'AudioOutputUnitStop', 'AudioUnit unit', 'return 0;'),
        ('OSStatus', 'AudioDeviceGetProperty', 'AudioDeviceID dev, unsigned int channel, int isInput, unsigned int propID, unsigned int *size, void *data',
         'return 0;'),
        ('OSStatus', 'AudioDeviceSetProperty', 'AudioDeviceID dev, const void *when, unsigned int channel, int isInput, unsigned int propID, unsigned int size, const void *data',
         'return 0;'),
        ('OSStatus', 'AudioHardwareGetProperty', 'unsigned int propID, unsigned int *size, void *data',
         'return 0;'),
    ],
}

# IOKit (HID, input devices) stub definitions
IOKIT_STUBS = {
    'header_includes': [],
    'typedefs': [
        'typedef void *io_object_t;',
        'typedef void *io_iterator_t;',
        'typedef void *io_service_t;',
        'typedef void *IOHIDDeviceInterface;',
        'typedef void *IOHIDElementCookie;',
        'typedef unsigned int IOReturn;',
        'typedef unsigned int mach_port_t;',
        'typedef void *CFMutableDictionaryRef;',
    ],
    'functions': [
        ('CFMutableDictionaryRef', 'IOServiceMatching', 'const char *name',
         'return (CFMutableDictionaryRef)0;'),
        ('int', 'IOServiceGetMatchingServices', 'mach_port_t masterPort, CFMutableDictionaryRef matching, io_iterator_t *existing',
         'if (existing) *existing = 0; return 0;'),
        ('io_object_t', 'IOIteratorNext', 'io_iterator_t iterator',
         'return (io_object_t)0;'),
        ('int', 'IOObjectRelease', 'io_object_t object', 'return 0;'),
        ('int', 'IORegistryEntryCreateCFProperties', 'io_object_t entry, void *properties, void *allocator, unsigned int options',
         'return 0;'),
        ('int', 'IOCreatePlugInInterfaceForService', 'io_service_t service, void *pluginType, void *interfaceType, void **theInterface, int *theScore',
         'return -1;'),
        ('int', 'IOHIDDeviceOpen', 'void *device, unsigned int options', 'return 0;'),
        ('int', 'IOHIDDeviceClose', 'void *device, unsigned int options', 'return 0;'),
        ('mach_port_t', 'IOMasterPort', 'unsigned int bootstrapPort, mach_port_t *masterPort',
         'if (masterPort) *masterPort = 0; return 0;'),
    ],
}

# QuickTime stub definitions
QUICKTIME_STUBS = {
    'header_includes': [],
    'typedefs': [
        'typedef int OSErr;',
    ],
    'functions': [
        ('OSErr', 'EnterMovies', 'void', 'return 0;'),
        ('void', 'ExitMovies', 'void', ''),
    ],
}

# CoreFoundation extras (beyond what's in Carbon)
COREFOUNDATION_STUBS = {
    'header_includes': [],
    'typedefs': [
        'typedef void *CFTypeRef;',
        'typedef void *CFAllocatorRef;',
        'typedef void *CFStringRef;',
        'typedef void *CFArrayRef;',
        'typedef void *CFMutableArrayRef;',
        'typedef void *CFDictionaryRef;',
        'typedef void *CFMutableDictionaryRef;',
        'typedef void *CFNumberRef;',
        'typedef void *CFDataRef;',
        'typedef void *CFBooleanRef;',
        'typedef unsigned int CFIndex;',
        'typedef unsigned int CFTypeID;',
        'typedef double CFTimeInterval;',
    ],
    'functions': [
        ('CFIndex', 'CFArrayGetCount', 'CFArrayRef array', 'return 0;'),
        ('const void *', 'CFArrayGetValueAtIndex', 'CFArrayRef array, CFIndex idx', 'return 0;'),
        ('CFNumberRef', 'CFNumberCreate', 'CFAllocatorRef alloc, int theType, const void *valuePtr', 'return (CFNumberRef)0;'),
        ('int', 'CFNumberGetValue', 'CFNumberRef number, int theType, void *valuePtr', 'return 0;'),
        ('const void *', 'CFDictionaryGetValue', 'CFDictionaryRef dict, const void *key', 'return 0;'),
        ('void', 'CFRetain', 'CFTypeRef cf', ''),
    ],
}

# Map framework name to stub definition
FRAMEWORK_STUBS = {
    'agl': AGL_STUBS,
    'carbon': CARBON_STUBS,
    'audio': AUDIO_STUBS,
    'iokit': IOKIT_STUBS,
    'quicktime': QUICKTIME_STUBS,
    'corefoundation': COREFOUNDATION_STUBS,
}


class PlatformStubGenerator:
    """Generate platform stub files for macOS→Linux porting."""

    def __init__(self, loader: MachOLoader):
        self.loader = loader
        # Determine which frameworks are actually used
        self._used_frameworks: set[str] = set()
        self._scan_imports()

    def _scan_imports(self):
        """Scan import symbols to determine which frameworks are needed."""
        for name, idx in self.loader.get_import_symbols():
            cat = _classify_symbol(name)
            cat_lower = cat.lower()
            if cat_lower in FRAMEWORK_STUBS:
                self._used_frameworks.add(cat_lower)
            elif cat == 'AGL':
                self._used_frameworks.add('agl')
            elif cat == 'Carbon':
                self._used_frameworks.add('carbon')
            elif cat in ('AudioToolbox', 'CoreAudio', 'AudioUnit'):
                self._used_frameworks.add('audio')
            elif cat == 'IOKit':
                self._used_frameworks.add('iokit')
            elif cat == 'QuickTime':
                self._used_frameworks.add('quicktime')
            elif cat == 'CoreFoundation':
                self._used_frameworks.add('corefoundation')

    def generate_stubs(self, output_dir: str):
        """Generate all needed stub files."""
        stubs_dir = os.path.join(output_dir, 'stubs')
        os.makedirs(stubs_dir, exist_ok=True)

        for framework in sorted(self._used_frameworks):
            if framework not in FRAMEWORK_STUBS:
                continue
            stubs = FRAMEWORK_STUBS[framework]
            self._generate_header(stubs_dir, framework, stubs)
            self._generate_source(stubs_dir, framework, stubs)

    def _generate_header(self, stubs_dir: str, name: str, stubs: dict):
        """Generate a stub header file."""
        guard = f'STUBS_{name.upper()}_H'
        lines = [
            f'#ifndef {guard}',
            f'#define {guard}',
            '',
            f'/* Platform stubs for {name} (macOS → Linux) */',
            '',
        ]

        for inc in stubs.get('header_includes', []):
            lines.append(f'#include {inc}')
        if stubs.get('header_includes'):
            lines.append('')

        for td in stubs.get('typedefs', []):
            lines.append(td)
        if stubs.get('typedefs'):
            lines.append('')

        for ret, fname, params, _ in stubs.get('functions', []):
            lines.append(f'{ret} {fname}({params});')

        lines.extend(['', f'#endif /* {guard} */', ''])

        path = os.path.join(stubs_dir, f'{name}_stubs.h')
        with open(path, 'w') as f:
            f.write('\n'.join(lines))

    def _generate_source(self, stubs_dir: str, name: str, stubs: dict):
        """Generate a stub source file."""
        lines = [
            f'/* Platform stubs for {name} (macOS → Linux) */',
            f'#include "{name}_stubs.h"',
            '',
        ]

        for ret, fname, params, body in stubs.get('functions', []):
            lines.append(f'{ret} {fname}({params})')
            lines.append('{')
            if body:
                lines.append(f'    {body}')
            lines.append('}')
            lines.append('')

        path = os.path.join(stubs_dir, f'{name}_stubs.c')
        with open(path, 'w') as f:
            f.write('\n'.join(lines))

    def get_stub_includes(self) -> list[str]:
        """Return list of stub header includes for imports.h."""
        includes = []
        for framework in sorted(self._used_frameworks):
            if framework in FRAMEWORK_STUBS:
                includes.append(f'#include "stubs/{framework}_stubs.h"')
        return includes
