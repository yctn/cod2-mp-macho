#!/usr/bin/env python3
"""Replace raw Mac string addresses ($0xHHHHHH) with symbol refs ($str_00HHHHHH) in inline ASM."""

import re, glob, sys

# Build set of known string addresses from strings.c
known_addrs = set()
with open('strings.c') as f:
    for line in f:
        m = re.match(r'const char (str_([0-9a-f]+))\[\]', line)
        if m:
            known_addrs.add(m.group(2))

print(f'Known string addresses: {len(known_addrs)}')

# Pattern to match $0xHHHHHH in inline asm strings (inside quotes)
# Matches things like: $0x228f48
def replace_raw_addrs(content, filename):
    count = 0
    def replacer(m):
        nonlocal count
        prefix = m.group(1)  # everything before the hex
        hexval = m.group(2)  # the hex digits after 0x
        addr = hexval.lower().zfill(8)
        if addr in known_addrs:
            count += 1
            return prefix + 'str_' + addr
        return m.group(0)

    # Match $0xHHHHHH patterns - the $ and 0x are literal in the asm string
    # In C strings: "$0x228f48"
    new_content = re.sub(r'(\$)0x([0-9a-fA-F]{5,7})(?![0-9a-fA-F])', replacer, content)
    return new_content, count

total_files = 0
total_refs = 0

for f in sorted(glob.glob('**/*.c', recursive=True)):
    if f in ('strings.c', 'rodata.c', 'fix_string_addrs.py'):
        continue
    with open(f) as fh:
        content = fh.read()

    new_content, count = replace_raw_addrs(content, f)
    if count > 0:
        if '--dry-run' not in sys.argv:
            with open(f, 'w') as fh:
                fh.write(new_content)
        print(f'  {f}: {count} replacements')
        total_files += 1
        total_refs += count

print(f'Total: {total_refs} replacements in {total_files} files')
if '--dry-run' in sys.argv:
    print('(dry run - no files modified)')
