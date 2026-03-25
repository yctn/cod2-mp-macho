"""Import stub generator for external framework symbols."""

import os
from .macho_loader import MachOLoader


# Known API signatures for common frameworks
KNOWN_SIGNATURES = {
    # libc / libSystem
    '_malloc': 'void *malloc(unsigned long size)',
    '_free': 'void free(void *ptr)',
    '_calloc': 'void *calloc(unsigned long count, unsigned long size)',
    '_realloc': 'void *realloc(void *ptr, unsigned long size)',
    '_memcpy': 'void *memcpy(void *dst, const void *src, unsigned long n)',
    '_memmove': 'void *memmove(void *dst, const void *src, unsigned long n)',
    '_memset': 'void *memset(void *s, int c, unsigned long n)',
    '_memcmp': 'int memcmp(const void *s1, const void *s2, unsigned long n)',
    '_strlen': 'unsigned long strlen(const char *s)',
    '_strcpy': 'char *strcpy(char *dst, const char *src)',
    '_strncpy': 'char *strncpy(char *dst, const char *src, unsigned long n)',
    '_strcmp': 'int strcmp(const char *s1, const char *s2)',
    '_strncmp': 'int strncmp(const char *s1, const char *s2, unsigned long n)',
    '_strcat': 'char *strcat(char *s1, const char *s2)',
    '_strncat': 'char *strncat(char *s1, const char *s2, unsigned long n)',
    '_strchr': 'char *strchr(const char *s, int c)',
    '_strrchr': 'char *strrchr(const char *s, int c)',
    '_strstr': 'char *strstr(const char *haystack, const char *needle)',
    '_sprintf': 'int sprintf(char *str, const char *format, ...)',
    '_snprintf': 'int snprintf(char *str, unsigned long size, const char *format, ...)',
    '_printf': 'int printf(const char *format, ...)',
    '_fprintf': 'int fprintf(void *stream, const char *format, ...)',
    '_sscanf': 'int sscanf(const char *str, const char *format, ...)',
    '_fopen': 'void *fopen(const char *path, const char *mode)',
    '_fclose': 'int fclose(void *stream)',
    '_fread': 'unsigned long fread(void *ptr, unsigned long size, unsigned long nmemb, void *stream)',
    '_fwrite': 'unsigned long fwrite(const void *ptr, unsigned long size, unsigned long nmemb, void *stream)',
    '_fseek': 'int fseek(void *stream, long offset, int whence)',
    '_ftell': 'long ftell(void *stream)',
    '_fgets': 'char *fgets(char *s, int size, void *stream)',
    '_fputs': 'int fputs(const char *s, void *stream)',
    '_fflush': 'int fflush(void *stream)',
    '_open': 'int open(const char *path, int flags, ...)',
    '_close': 'int close(int fd)',
    '_read': 'long read(int fd, void *buf, unsigned long nbyte)',
    '_write': 'long write(int fd, const void *buf, unsigned long nbyte)',
    '_lseek': 'long lseek(int fd, long offset, int whence)',
    '_stat': 'int stat(const char *path, void *buf)',
    '_mkdir': 'int mkdir(const char *path, int mode)',
    '_unlink': 'int unlink(const char *path)',
    '_rename': 'int rename(const char *old, const char *new_name)',
    '_exit': 'void exit(int status)',
    '_abort': 'void abort(void)',
    '_atoi': 'int atoi(const char *str)',
    '_atof': 'double atof(const char *str)',
    '_strtol': 'long strtol(const char *str, char **endptr, int base)',
    '_strtod': 'double strtod(const char *str, char **endptr)',
    '_abs': 'int abs(int n)',
    '_rand': 'int rand(void)',
    '_srand': 'void srand(unsigned int seed)',
    '_time': 'long time(long *tloc)',
    '_clock': 'long clock(void)',
    '_getenv': 'char *getenv(const char *name)',
    '_system': 'int system(const char *command)',
    '_qsort': 'void qsort(void *base, unsigned long nmemb, unsigned long size, int (*compar)(const void *, const void *))',
    '_bsearch': 'void *bsearch(const void *key, const void *base, unsigned long nmemb, unsigned long size, int (*compar)(const void *, const void *))',
    '_sin': 'double sin(double x)',
    '_cos': 'double cos(double x)',
    '_tan': 'double tan(double x)',
    '_sqrt': 'double sqrt(double x)',
    '_pow': 'double pow(double x, double y)',
    '_log': 'double log(double x)',
    '_exp': 'double exp(double x)',
    '_floor': 'double floor(double x)',
    '_ceil': 'double ceil(double x)',
    '_fabs': 'double fabs(double x)',
    '_sinf': 'float sinf(float x)',
    '_cosf': 'float cosf(float x)',
    '_tanf': 'float tanf(float x)',
    '_sqrtf': 'float sqrtf(float x)',
    '_atan2': 'double atan2(double y, double x)',
    '_atan2f': 'float atan2f(float y, float x)',
    '_acos': 'double acos(double x)',
    '_acosf': 'float acosf(float x)',
    # OpenGL
    '_glBegin': 'void glBegin(unsigned int mode)',
    '_glEnd': 'void glEnd(void)',
    '_glVertex2f': 'void glVertex2f(float x, float y)',
    '_glVertex3f': 'void glVertex3f(float x, float y, float z)',
    '_glColor4f': 'void glColor4f(float r, float g, float b, float a)',
    '_glTexCoord2f': 'void glTexCoord2f(float s, float t)',
    '_glEnable': 'void glEnable(unsigned int cap)',
    '_glDisable': 'void glDisable(unsigned int cap)',
    '_glClear': 'void glClear(unsigned int mask)',
    '_glViewport': 'void glViewport(int x, int y, int width, int height)',
    '_glMatrixMode': 'void glMatrixMode(unsigned int mode)',
    '_glLoadIdentity': 'void glLoadIdentity(void)',
    '_glBindTexture': 'void glBindTexture(unsigned int target, unsigned int texture)',
    '_glGenTextures': 'void glGenTextures(int n, unsigned int *textures)',
    '_glDeleteTextures': 'void glDeleteTextures(int n, const unsigned int *textures)',
    '_glTexImage2D': 'void glTexImage2D(unsigned int target, int level, int internalformat, int width, int height, int border, unsigned int format, unsigned int type, const void *pixels)',
    '_glTexParameteri': 'void glTexParameteri(unsigned int target, unsigned int pname, int param)',
    '_glBlendFunc': 'void glBlendFunc(unsigned int sfactor, unsigned int dfactor)',
    '_glDepthMask': 'void glDepthMask(unsigned char flag)',
    '_glScissor': 'void glScissor(int x, int y, int width, int height)',
    '_glGetIntegerv': 'void glGetIntegerv(unsigned int pname, int *params)',
    '_glGetError': 'unsigned int glGetError(void)',
    '_glOrtho': 'void glOrtho(double left, double right, double bottom, double top, double nearVal, double farVal)',
    '_glPushMatrix': 'void glPushMatrix(void)',
    '_glPopMatrix': 'void glPopMatrix(void)',
    '_glTranslatef': 'void glTranslatef(float x, float y, float z)',
    '_glRotatef': 'void glRotatef(float angle, float x, float y, float z)',
    '_glScalef': 'void glScalef(float x, float y, float z)',
}

# Map dylib path patterns to header/framework names
DYLIB_TO_FRAMEWORK = {
    'IOKit': 'IOKit',
    'OpenGL': 'OpenGL',
    'QuickTime': 'QuickTime',
    'AGL': 'AGL',
    'AudioUnit': 'AudioUnit',
    'AudioToolbox': 'AudioToolbox',
    'CoreAudio': 'CoreAudio',
    'Carbon': 'Carbon',
    'libstdc++': 'libstdcxx',
    'libgcc_s': 'libgcc',
    'libSystem': 'libc',
}


def _classify_symbol(name: str) -> str:
    """Classify a symbol into a framework category."""
    if name.startswith('_gl') or name.startswith('_GL'):
        return 'OpenGL'
    if name.startswith('_AE') or name.startswith('_CreateObjSpecifier'):
        return 'Carbon'
    if name.startswith('_CF') or name.startswith('_kCF'):
        return 'CoreFoundation'
    if name.startswith('_Audio') or name.startswith('_kAudio'):
        return 'AudioToolbox'
    if name.startswith('_agl') or name.startswith('_AGL'):
        return 'AGL'
    if name.startswith('_HID') or name.startswith('_IOHID') or name.startswith('_IO'):
        return 'IOKit'
    if name.startswith('___cxa_') or name.startswith('___gxx_'):
        return 'libstdcxx'
    if name.startswith('_NSApp') or name.startswith('_NS'):
        return 'Carbon'
    if name.startswith('_QT') or name.startswith('_Enter') or name.startswith('_Exit'):
        return 'QuickTime'
    # Most remaining are libc
    return 'libc'


class ImportGenerator:
    """Generate stub headers for imported symbols."""

    def __init__(self, loader: MachOLoader):
        self.loader = loader

    def generate_stubs(self, output_dir: str):
        """Generate import stub headers."""
        imports_dir = os.path.join(output_dir, 'imports')
        os.makedirs(imports_dir, exist_ok=True)

        # Categorize all imports
        categories: dict[str, list[tuple[str, int]]] = {}
        for name, idx in self.loader.get_import_symbols():
            cat = _classify_symbol(name)
            categories.setdefault(cat, []).append((name, idx))

        # Also include jump table symbols
        jt = self.loader.section_by_name.get(('__IMPORT', '__jump_table'))
        if jt:
            stride = jt.reserved2
            if stride > 0:
                for i in range(jt.size // stride):
                    addr = jt.addr + i * stride
                    name = self.loader.resolve_jump_table(addr)
                    if name:
                        cat = _classify_symbol(name)
                        if not any(n == name for n, _ in categories.get(cat, [])):
                            categories.setdefault(cat, []).append((name, -1))

        # Generate per-category headers
        all_imports_lines = [
            '#ifndef IMPORTS_H',
            '#define IMPORTS_H',
            '',
        ]

        for cat in sorted(categories.keys()):
            syms = sorted(categories[cat], key=lambda x: x[0])
            header = self._generate_category_header(cat, syms)
            header_file = f'{cat.lower()}.h'
            path = os.path.join(imports_dir, header_file)
            with open(path, 'w') as f:
                f.write(header)
            all_imports_lines.append(f'#include "imports/{header_file}"')

        all_imports_lines.extend(['', '#endif /* IMPORTS_H */', ''])
        all_path = os.path.join(output_dir, 'imports.h')
        with open(all_path, 'w') as f:
            f.write('\n'.join(all_imports_lines))

    # Standard C/POSIX functions already declared by system headers.
    # Redeclaring these in import stubs causes "conflicting types" errors.
    _SYSTEM_DECLARED = {
        # <stdio.h>
        'fopen', 'fclose', 'fread', 'fwrite', 'fseek', 'ftell', 'fflush',
        'fgets', 'fputs', 'feof', 'ferror', 'clearerr', 'rewind', 'fgetc',
        'fputc', 'ungetc', 'fgetpos', 'fsetpos', 'tmpfile', 'tmpnam',
        'fprintf', 'printf', 'sprintf', 'snprintf', 'vfprintf', 'vprintf',
        'vsprintf', 'vsnprintf', 'sscanf', 'fscanf', 'scanf', 'perror',
        'rename', 'remove', 'setvbuf', 'setbuf', 'puts', 'getchar', 'putchar',
        # <stdlib.h>
        'malloc', 'free', 'calloc', 'realloc', 'exit', 'abort', 'atexit',
        'atoi', 'atol', 'atof', 'strtol', 'strtoul', 'strtod', 'strtof',
        'abs', 'labs', 'div', 'ldiv', 'rand', 'srand', 'qsort', 'bsearch',
        'getenv', 'system', 'mktemp',
        # <string.h>
        'memcpy', 'memmove', 'memset', 'memcmp', 'memchr',
        'strlen', 'strcpy', 'strncpy', 'strcmp', 'strncmp',
        'strcat', 'strncat', 'strchr', 'strrchr', 'strstr', 'strtok',
        'strdup', 'strerror', 'strpbrk', 'strspn', 'strcspn', 'strsep',
        'strcasecmp', 'strncasecmp', 'bcopy', 'bzero', 'bcmp',
        # <math.h>
        'sin', 'cos', 'tan', 'asin', 'acos', 'atan', 'atan2',
        'sinf', 'cosf', 'tanf', 'asinf', 'acosf', 'atanf', 'atan2f',
        'sqrt', 'sqrtf', 'pow', 'powf', 'log', 'logf', 'log10', 'log10f',
        'exp', 'expf', 'ceil', 'ceilf', 'floor', 'floorf',
        'fabs', 'fabsf', 'fmod', 'fmodf', 'ldexp', 'frexp', 'modf',
        # <time.h>
        'time', 'clock', 'difftime', 'mktime', 'asctime', 'ctime',
        'gmtime', 'localtime', 'strftime',
        # <unistd.h> / <fcntl.h>
        'open', 'close', 'read', 'write', 'lseek', 'unlink', 'rmdir',
        'getcwd', 'chdir', 'access', 'isatty', 'dup', 'dup2', 'pipe',
        'fork', 'execv', 'execve', 'getpid', 'getuid', 'sleep', 'usleep',
        'stat', 'fstat', 'lstat', 'mkdir', 'chmod', 'ftruncate',
        # <signal.h>
        'signal', 'raise', 'sigaction',
        # <errno.h>
        'error',
        # <setjmp.h>
        'setjmp', 'longjmp',
        # <pthread.h>
        'pthread_create', 'pthread_join', 'pthread_exit', 'pthread_detach',
        'pthread_mutex_init', 'pthread_mutex_lock', 'pthread_mutex_unlock',
        'pthread_mutex_destroy', 'pthread_cond_init', 'pthread_cond_wait',
        'pthread_cond_signal', 'pthread_cond_broadcast', 'pthread_cond_destroy',
        'pthread_self', 'pthread_equal', 'pthread_attr_init',
        # <dlfcn.h>
        'dlopen', 'dlclose', 'dlsym', 'dlerror',
        # <sys/socket.h> / <netdb.h> / <netinet/in.h>
        'socket', 'bind', 'listen', 'accept', 'connect', 'send', 'recv',
        'sendto', 'recvfrom', 'setsockopt', 'getsockopt', 'shutdown',
        'select', 'poll', 'gethostbyname', 'getaddrinfo', 'freeaddrinfo',
        'getnameinfo', 'inet_ntoa', 'inet_addr', 'htons', 'htonl',
        'ntohs', 'ntohl',
        # <sys/mman.h>
        'mmap', 'munmap', 'mprotect',
        # <sys/ioctl.h>
        'ioctl', 'fcntl',
    }

    def _generate_category_header(self, category: str, symbols: list) -> str:
        """Generate a header file for a category of imports."""
        guard = f'IMPORTS_{category.upper()}_H'
        lines = [
            f'#ifndef {guard}',
            f'#define {guard}',
            '',
            f'/* Import stubs for {category} */',
            '',
        ]

        for name, idx in symbols:
            clean = name.lstrip('_')
            # Skip functions already declared by system headers
            if clean in self._SYSTEM_DECLARED:
                lines.append(f'/* {clean}() — provided by system headers */')
                continue
            sig = KNOWN_SIGNATURES.get(name)
            if sig:
                lines.append(f'{sig};')
            else:
                # Generate generic declaration
                lines.append(f'int {clean}(); /* {name} */')

        lines.extend(['', f'#endif /* {guard} */', ''])
        return '\n'.join(lines)

    def get_import_summary(self) -> dict[str, int]:
        """Return count of imports per category."""
        categories: dict[str, int] = {}
        for name, idx in self.loader.get_import_symbols():
            cat = _classify_symbol(name)
            categories[cat] = categories.get(cat, 0) + 1
        return categories
