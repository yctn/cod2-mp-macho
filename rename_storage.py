#!/usr/bin/env python3
"""
Rename foo_storage → foo, update #define macros to reference the new name.
The C preprocessor handles self-referential #define foo ((Type *)foo) correctly
(the inner 'foo' is not recursively expanded — it resolves to the variable).
Direct-alias defines (#define foo foo_storage) are removed entirely.
"""

import re
import os
import sys

# Match:  UInt32 foo_storage[N]  /  int foo_storage[N]  /  TYPE foo_storage  etc.
DECL_RE = re.compile(
    r'\b(\w[\w\s\*]*?)\s+(\w+)_storage(\s*(?:\[\w+\])*\s*(?:=|\{|;))',
)

# Match a #define line: #define foo ...
DEFINE_RE = re.compile(r'^(\s*#define\s+)(\w+)(\s+.*)$')


def find_storage_vars(content):
    """Return set of base names (without _storage) found in this file."""
    names = set()
    for m in re.finditer(r'\b(\w+)_storage\b', content):
        names.add(m.group(1))
    return names


def process_file(path, dry_run=False):
    with open(path, encoding='utf-8', errors='replace') as f:
        original = f.read()

    names = find_storage_vars(original)
    if not names:
        return False

    content = original

    for name in sorted(names, key=len, reverse=True):  # longest first avoids partial matches
        storage_name = name + '_storage'
        if storage_name not in content:
            continue

        # Replace all occurrences of foo_storage with foo
        new_content = re.sub(r'\b' + re.escape(storage_name) + r'\b', name, content)

        # Now fix the #define line:
        # After the rename, if there was "#define foo ((Type *)foo_storage)"
        # it became "#define foo ((Type *)foo)" — self-referential, keep it.
        # If there was "#define foo foo_storage" it became "#define foo foo" — remove it.
        def fix_define(m):
            define_keyword = m.group(1)  # "#define "
            macro_name = m.group(2)
            rest = m.group(3)           # " foo" or " ((Type *)foo)" etc.

            if macro_name != name:
                return m.group(0)  # not our macro

            rest_stripped = rest.strip()

            # Direct alias: #define foo foo  → remove line
            if rest_stripped == name:
                return ''  # will remove the line

            # Keep everything else (self-referential cast, array index, etc.)
            return m.group(0)

        lines = new_content.split('\n')
        result_lines = []
        for line in lines:
            m = DEFINE_RE.match(line)
            if m:
                fixed = fix_define(m)
                if fixed != '':
                    result_lines.append(line)
                # else: drop the line (was a direct alias)
            else:
                result_lines.append(line)

        new_content = '\n'.join(result_lines)
        content = new_content

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
                if process_file(path, dry_run=dry_run):
                    changed += 1
                    print(f'  updated: {path}')

    print(f'\nDone: {changed}/{total} files {"(dry run)" if dry_run else "updated"}.')


if __name__ == '__main__':
    main()
