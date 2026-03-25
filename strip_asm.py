#!/usr/bin/env python3
"""
Strip __EMSCRIPTEN__ conditional guards, keeping only the EMSCRIPTEN branches.

For #ifndef __EMSCRIPTEN__: skip the if-branch (asm), keep the else-branch (C).
For #ifdef __EMSCRIPTEN__:  keep the if-branch (C), skip the else-branch (asm).

This effectively "defines" __EMSCRIPTEN__ for preprocessing purposes,
selecting only the C/C++ code paths.
"""

import re
import os
import sys

IF_RE = re.compile(r'#\s*if(?:def|ndef)?\b')
IF0_RE = re.compile(r'#\s*if\s+0\b')
ENDIF_RE = re.compile(r'#\s*endif\b')
ELSE_RE = re.compile(r'#\s*else\b')
ELIF_RE = re.compile(r'#\s*elif\b')

IFNDEF_EMSCRIPTEN = '#ifndef __EMSCRIPTEN__'
IFDEF_EMSCRIPTEN  = '#ifdef __EMSCRIPTEN__'

def process_lines(lines):
    result = []
    i = 0
    n = len(lines)

    while i < n:
        line = lines[i]
        stripped = line.strip()

        is_ifndef = (stripped == IFNDEF_EMSCRIPTEN)
        is_ifdef  = (stripped == IFDEF_EMSCRIPTEN)
        is_if_zero = bool(IF0_RE.match(stripped))

        if not (is_ifndef or is_ifdef or is_if_zero):
            result.append(line)
            i += 1
            continue

        # For #if 0: discard the entire block (no else branch kept either)
        if is_if_zero:
            i += 1
            depth = 1
            while i < n:
                s = lines[i].strip()
                if IF_RE.match(s):
                    depth += 1
                elif ENDIF_RE.match(s):
                    depth -= 1
                    if depth == 0:
                        i += 1
                        break
                i += 1
            continue

        # keep_if_branch=True  → keep lines inside the #ifdef block, discard #else block
        # keep_if_branch=False → discard lines inside #ifndef block, keep #else block
        keep_if_branch = is_ifdef
        i += 1  # skip the #if(n)def line itself

        # --- Collect the if-branch ------------------------------------------
        if_lines = []
        depth = 1

        while i < n:
            s = lines[i].strip()
            if IF_RE.match(s):
                depth += 1
                if_lines.append(lines[i])
                i += 1
            elif (ELSE_RE.match(s) or ELIF_RE.match(s)) and depth == 1:
                i += 1  # skip the #else / #elif line
                break   # switch to else-branch collection
            elif ENDIF_RE.match(s) and depth == 1:
                i += 1  # skip the #endif
                depth = 0
                break   # no else-branch
            elif ENDIF_RE.match(s):
                depth -= 1
                if_lines.append(lines[i])
                i += 1
            else:
                if_lines.append(lines[i])
                i += 1

        if keep_if_branch:
            result.extend(if_lines)

        if depth == 0:
            # No else-branch was found; nothing more to do.
            continue

        # --- Collect the else-branch ----------------------------------------
        else_lines = []
        depth = 1

        while i < n:
            s = lines[i].strip()
            if IF_RE.match(s):
                depth += 1
                else_lines.append(lines[i])
                i += 1
            elif ENDIF_RE.match(s) and depth == 1:
                i += 1  # skip the closing #endif
                break
            elif ENDIF_RE.match(s):
                depth -= 1
                else_lines.append(lines[i])
                i += 1
            else:
                else_lines.append(lines[i])
                i += 1

        if not keep_if_branch:
            result.extend(else_lines)

    return result


def process_file(path):
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        original = f.read()

    lines = original.split('\n')
    result = process_lines(lines)
    new_content = '\n'.join(result)

    if new_content == original:
        return False

    with open(path, 'w', encoding='utf-8') as f:
        f.write(new_content)
    return True


def main():
    roots = sys.argv[1:] if len(sys.argv) > 1 else ['.']
    changed = 0
    total = 0

    for root in roots:
        for dirpath, dirnames, filenames in os.walk(root):
            # Skip reference/third-party directories
            dirnames[:] = [d for d in dirnames if d not in ('ref',)]
            for fname in filenames:
                if not fname.endswith(('.c', '.cpp', '.h', '.cc')):
                    continue
                path = os.path.join(dirpath, fname)
                total += 1
                if process_file(path):
                    changed += 1
                    print(f'  updated: {path}')

    print(f'\nDone: {changed}/{total} files updated.')


if __name__ == '__main__':
    main()
