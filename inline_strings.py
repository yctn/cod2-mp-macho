#!/usr/bin/env python3
"""
Inline str_XXXXXXXX string references into C source files.

1. Parses strings.c to build a {str_name: "value"} map.
2. For each C file:
   a. Removes 'extern const char str_XXXXXXXX[];' declarations.
   b. Replaces (UInt32)str_XXX / (uintptr_t)str_XXX in UInt32[] initializers
      with the bare string literal, and changes the array type to const char *.
   c. Replaces all remaining str_XXX uses with the string literal.
   d. Removes redundant #define macros that just cast const char *[] to
      (const char * const *) or similar (no-op after type fix).
"""

import re
import os
import sys

STR_RE = re.compile(r'\bstr_([0-9a-f]{8})\b')
EXTERN_DECL_RE = re.compile(
    r'^\s*extern\s+const\s+char\s+str_[0-9a-f]{8}\s*\[\s*\]\s*;[^\n]*$',
    re.MULTILINE,
)

# Matches: TYPE varname[N] = { ... };  (possibly multi-line, up to first ;)
# We'll detect arrays that contain (UInt32)str_XXX after initial replacement.
UINT32_CAST_RE = re.compile(r'\(UInt32\)\s*str_[0-9a-f]{8}')
UINTPTR_CAST_RE = re.compile(r'\(uintptr_t\)"')  # after first-pass replacement


def parse_strings_c(path):
    """Return dict: str_name -> raw C string value (the quoted literal).
    Handles adjacent string literal concatenation: "a" "b" -> "a" "b"
    """
    mapping = {}
    # Match one or more adjacent quoted literals (C string concatenation)
    quoted = r'"(?:[^"\\]|\\.)*"'
    pattern = re.compile(
        r'const\s+char\s+(str_[0-9a-f]{8})\s*\[\s*\]\s*=\s*((?:' + quoted + r'\s*)+)\s*;'
    )
    with open(path, encoding='utf-8', errors='replace') as f:
        content = f.read()
    for m in pattern.finditer(content):
        # Join adjacent string literals into one value (keep as-is for C)
        val = m.group(2).strip()
        mapping[m.group(1)] = val
    # Add the empty string that's not defined in strings.c
    # str_002157b8 is at address 0x002157b8 — a null byte just before str_002157bc
    mapping.setdefault('str_002157b8', '""')
    return mapping


def escape_for_regex(s):
    return re.escape(s)


def replace_str_refs(content, mapping):
    """Replace all str_XXX identifiers with their quoted string value."""
    def replacer(m):
        name = m.group(0)
        return mapping.get(name, name)
    return STR_RE.sub(replacer, content)


def fix_uint32_string_arrays(content):
    """
    Convert:
        UInt32 foo[N] = { (UInt32)"val1", (UInt32)"val2", ... };
    or:
        __attribute__(...) UInt32 foo[N] = { (UInt32)"val", 0, ... };
    to:
        const char * foo[] = { "val1", "val2", NULL, ... };

    Also removes (uintptr_t) / (UInt32) casts around string literals in
    array initializers.
    """
    # Remove casts of the form (UInt32)"..." or (uintptr_t)"..."
    content = re.sub(r'\((UInt32|uintptr_t)\)(")', r'\2', content)

    # Find UInt32 array declarations whose initializers now contain string literals.
    # Pattern: optional __attribute__(...) UInt32 name[N] = { ... };
    # We replace UInt32 with const char * and remove the [N] dimension.
    def fix_decl(m):
        prefix = m.group('prefix')   # everything before the type
        attrs = m.group('attrs')     # optional __attribute__((...))
        name = m.group('name')
        init = m.group('init')       # the { ... } initializer body

        # Only convert if the initializer contains string literals
        if not re.search(r'"', init):
            return m.group(0)

        # Replace trailing integer zeros (padding) with NULL
        init_fixed = re.sub(r'\b0\b', 'NULL', init)
        # Remove any remaining (UInt32) or (uintptr_t) casts that slipped through
        init_fixed = re.sub(r'\((UInt32|uintptr_t)\)', '', init_fixed)

        if attrs:
            return f'{prefix}{attrs}\nconst char * {name}[] = {{{init_fixed}}};'
        return f'{prefix}const char * {name}[] = {{{init_fixed}}};'

    # Match: [attrs] UInt32 name[...] = { body };
    array_re = re.compile(
        r'(?P<prefix>^[ \t]*)(?P<attrs>(?:__attribute__\s*\((?:[^()]*|\([^()]*\))*\)\s*)*)UInt32\s+(?P<name>\w+)\s*\[[^\]]*\]\s*=\s*\{(?P<init>[^}]*)\}\s*;',
        re.MULTILINE,
    )
    content = array_re.sub(fix_decl, content)
    return content


def remove_redundant_defines(content):
    """
    Remove #define macros like:
        #define foo ((const char * const *)foo)
        #define foo ((char **)foo)
        #define foo ((const char **)foo)
    where foo is now already const char *[], making the cast a no-op.
    Also remove direct-identity defines: #define foo foo
    """
    def check_define(m):
        macro = m.group(1)
        rest = m.group(2).strip()
        # Direct identity
        if rest == macro:
            return ''
        # Cast to char** variants of the same name
        cast_re = re.compile(
            r'^\(\((?:const\s+)?char\s*\*(?:\s*const\s*)?\*\)\s*' + re.escape(macro) + r'\)$'
        )
        if cast_re.match(rest):
            return ''
        return m.group(0)

    define_re = re.compile(r'^[ \t]*#define\s+(\w+)\s+(.+)$', re.MULTILINE)
    content = define_re.sub(lambda m: check_define(m), content)
    # Remove blank lines that result from deleted defines
    content = re.sub(r'\n{3,}', '\n\n', content)
    return content


def process_file(path, mapping, dry_run=False):
    with open(path, encoding='utf-8', errors='replace') as f:
        original = f.read()

    # Quick check: does this file reference any str_ symbols?
    if not STR_RE.search(original):
        return False

    content = original

    # 1. Remove extern declarations for str_ symbols
    content = EXTERN_DECL_RE.sub('', content)

    # 2. Replace (UInt32)str_XXX with (uintptr_t)"value" first
    #    so we can later detect and fix UInt32 arrays.
    def uint32_str_replacer(m):
        full = m.group(0)
        # Find the str_ name
        str_m = STR_RE.search(full)
        if str_m:
            val = mapping.get(str_m.group(0))
            if val:
                return f'(uintptr_t){val}'
        return full
    content = re.sub(r'\(UInt32\)\s*str_[0-9a-f]{8}', uint32_str_replacer, content)

    # 3. Fix UInt32 arrays that now have (uintptr_t)"..." entries
    content = fix_uint32_string_arrays(content)

    # 4. Replace all remaining str_XXX with their string value
    content = replace_str_refs(content, mapping)

    # 5. Remove redundant #define casts (now that arrays have proper types)
    content = remove_redundant_defines(content)

    # 6. Clean up empty lines left by removed extern decls
    content = re.sub(r'\n{3,}', '\n\n', content)

    if content == original:
        return False

    if not dry_run:
        with open(path, 'w', encoding='utf-8') as f:
            f.write(content)
    return True


def main():
    dry_run = '--dry-run' in sys.argv
    roots = [a for a in sys.argv[1:] if not a.startswith('--')]
    if not roots:
        roots = ['.']

    strings_c = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'strings.c')
    if not os.path.exists(strings_c):
        # Try CWD
        strings_c = 'strings.c'
    print(f'Parsing string map from: {strings_c}')
    mapping = parse_strings_c(strings_c)
    print(f'  {len(mapping)} strings loaded.')

    changed = 0
    total = 0
    for root in roots:
        for dirpath, dirnames, filenames in os.walk(root):
            dirnames[:] = [d for d in dirnames if d not in ('ref',)]
            for fname in filenames:
                if not fname.endswith(('.c', '.cpp', '.h', '.cc')):
                    continue
                path = os.path.join(dirpath, fname)
                total += 1
                if process_file(path, mapping, dry_run=dry_run):
                    changed += 1
                    print(f'  updated: {path}')

    print(f'\nDone: {changed}/{total} files {"(dry run)" if dry_run else "updated"}.')


if __name__ == '__main__':
    main()
