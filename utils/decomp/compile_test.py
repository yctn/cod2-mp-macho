#!/usr/bin/env python3
"""Compilation test: decompile binary then check each .c file with gcc -fsyntax-only."""

import argparse
import os
import subprocess
import sys
import tempfile
import time


def run_decompile(binary: str, output_dir: str) -> bool:
    """Run full decompilation to output_dir. Returns True on success."""
    cmd = [sys.executable, '-m', 'decomp.decomp', binary, '-o', output_dir]
    print(f'Running: {" ".join(cmd)}', file=sys.stderr)
    result = subprocess.run(cmd, capture_output=True, text=True)
    sys.stderr.write(result.stderr)
    if result.returncode != 0:
        print(f'Decompilation failed (exit {result.returncode})', file=sys.stderr)
        return False
    return True


def find_c_files(output_dir: str) -> list[str]:
    """Find all .c files in output directory."""
    c_files = []
    for root, dirs, files in os.walk(output_dir):
        for f in sorted(files):
            if f.endswith('.c'):
                c_files.append(os.path.join(root, f))
    return c_files


def compile_check(c_file: str, output_dir: str) -> tuple[bool, str]:
    """Run gcc -fsyntax-only on a single file. Returns (success, error_output)."""
    include_flags = [f'-I{output_dir}']
    source_dir = os.path.dirname(c_file)
    if source_dir and os.path.abspath(source_dir) != os.path.abspath(output_dir):
        include_flags.append(f'-I{source_dir}')

    cmd = [
        'gcc', '-fsyntax-only', '-c', '-m32', '-w',
        *include_flags,
        c_file,
    ]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    if result.returncode == 0:
        return (True, '')
    return (False, result.stderr)


def categorize_errors(stderr: str) -> dict[str, int]:
    """Categorize GCC errors by type."""
    cats: dict[str, int] = {}
    for line in stderr.splitlines():
        if ': error:' in line:
            msg = line.split(': error:')[1].strip()
            # Simplify common patterns
            if 'undeclared' in msg:
                key = 'undeclared identifier'
            elif 'unknown type name' in msg:
                key = 'unknown type name'
            elif 'expected' in msg:
                key = 'syntax error (expected)'
            elif 'redefinition' in msg or 'redeclared' in msg:
                key = 'redefinition/redeclared'
            elif 'conflicting types' in msg:
                key = 'conflicting types'
            elif 'duplicate' in msg:
                key = 'duplicate value'
            else:
                key = msg[:60]
            cats[key] = cats.get(key, 0) + 1
    return cats


def main():
    parser = argparse.ArgumentParser(
        description='Decompile and test compilation of output files')
    parser.add_argument('binary', help='Path to Mach-O binary')
    parser.add_argument('-o', '--output', default=None,
                        help='Output directory (default: temp dir)')
    parser.add_argument('--skip-decompile', action='store_true',
                        help='Skip decompilation, test existing output dir')
    parser.add_argument('--file', metavar='PATTERN',
                        help='Only test files matching pattern')
    parser.add_argument('--show-errors', action='store_true',
                        help='Show full error output for failing files')
    parser.add_argument('--header-only', action='store_true',
                        help='Only test common_types.h')
    args = parser.parse_args()

    # Determine output dir
    if args.output:
        output_dir = args.output
    elif args.skip_decompile:
        print('Error: --skip-decompile requires -o/--output', file=sys.stderr)
        sys.exit(1)
    else:
        output_dir = tempfile.mkdtemp(prefix='decomp_test_')
        print(f'Using temp dir: {output_dir}', file=sys.stderr)

    # Decompile
    if not args.skip_decompile:
        t0 = time.time()
        if not run_decompile(args.binary, output_dir):
            sys.exit(1)
        t1 = time.time()
        print(f'Decompilation: {t1-t0:.1f}s', file=sys.stderr)

    # Test header only
    if args.header_only:
        header = os.path.join(output_dir, 'common_types.h')
        if not os.path.exists(header):
            print(f'Error: {header} not found', file=sys.stderr)
            sys.exit(1)
        # Create a dummy .c file to test the header
        test_c = os.path.join(output_dir, '_test_header.c')
        with open(test_c, 'w') as f:
            f.write(f'#include "common_types.h"\n')
        ok, err = compile_check(test_c, output_dir)
        os.unlink(test_c)
        if ok:
            print('common_types.h: OK')
        else:
            print('common_types.h: FAIL')
            print(err)
        sys.exit(0 if ok else 1)

    # Find and test .c files
    c_files = find_c_files(output_dir)
    if args.file:
        c_files = [f for f in c_files if args.file in f]

    if not c_files:
        print('No .c files found', file=sys.stderr)
        sys.exit(1)

    print(f'\nTesting {len(c_files)} files...', file=sys.stderr)

    passed = 0
    failed = 0
    all_errors: dict[str, int] = {}
    failed_files: list[tuple[str, str]] = []

    for i, cfile in enumerate(c_files):
        rel = os.path.relpath(cfile, output_dir)
        ok, err = compile_check(cfile, output_dir)
        if ok:
            passed += 1
        else:
            failed += 1
            failed_files.append((rel, err))
            cats = categorize_errors(err)
            for k, v in cats.items():
                all_errors[k] = all_errors.get(k, 0) + v

        if (i + 1) % 50 == 0 or i + 1 == len(c_files):
            print(f'\r  [{i+1}/{len(c_files)}] {passed} pass, {failed} fail',
                  end='', file=sys.stderr)

    print(file=sys.stderr)

    # Summary
    print(f'\n=== Compilation Results ===')
    print(f'Total files: {len(c_files)}')
    print(f'  Passed: {passed}')
    print(f'  Failed: {failed}')
    pct = passed * 100.0 / len(c_files) if c_files else 0
    print(f'  Pass rate: {pct:.1f}%')

    if all_errors:
        print(f'\nError categories:')
        for cat, count in sorted(all_errors.items(), key=lambda x: -x[1]):
            print(f'  {count:4d}  {cat}')

    if args.show_errors and failed_files:
        print(f'\n=== Failed files ===')
        for rel, err in failed_files[:20]:
            print(f'\n--- {rel} ---')
            # Show first 10 error lines
            lines = err.strip().splitlines()
            for line in lines[:10]:
                print(f'  {line}')
            if len(lines) > 10:
                print(f'  ... ({len(lines)-10} more lines)')

    sys.exit(0 if failed == 0 else 1)


if __name__ == '__main__':
    main()
