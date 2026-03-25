#!/usr/bin/env python3
"""CLI driver for the COD2 Mach-O i386 decompiler."""

import argparse
import sys
import os
import time


def main():
    parser = argparse.ArgumentParser(
        description='COD2 Mach-O i386 Decompiler',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog='''
Examples:
  python3 -m decomp.decomp binary.x86                     # Full decompilation
  python3 -m decomp.decomp binary.x86 --function 0x278c   # Single function
  python3 -m decomp.decomp binary.x86 --function _start   # By name
  python3 -m decomp.decomp binary.x86 --file cm_trace     # One source file
  python3 -m decomp.decomp binary.x86 --list-functions    # List all functions
  python3 -m decomp.decomp binary.x86 --list-types        # List all types
  python3 -m decomp.decomp binary.x86 --dump-stabs        # Raw STABS dump
  python3 -m decomp.decomp binary.x86 --stats             # Binary statistics
''')
    parser.add_argument('binary', help='Path to Mach-O i386 binary')
    parser.add_argument('-o', '--output', default='output',
                        help='Output directory (default: output)')
    parser.add_argument('--function', metavar='ADDR_OR_NAME',
                        help='Decompile a single function (hex address or name)')
    parser.add_argument('--file', metavar='PATTERN',
                        help='Decompile functions from matching source file')
    parser.add_argument('--list-functions', action='store_true',
                        help='List all functions')
    parser.add_argument('--list-types', action='store_true',
                        help='List all type definitions')
    parser.add_argument('--list-files', action='store_true',
                        help='List all compilation units')
    parser.add_argument('--dump-stabs', action='store_true',
                        help='Dump raw STABS debug info')
    parser.add_argument('--stats', action='store_true',
                        help='Print binary statistics')
    parser.add_argument('--goto', action='store_true',
                        help='Use goto-based output (no structuring)')
    parser.add_argument('--asm', action='store_true',
                        help='Emit naked functions with inline AT&T asm (compilable)')
    parser.add_argument('--imports', action='store_true',
                        help='Generate import stubs only')
    parser.add_argument('--headers', action='store_true',
                        help='Generate type headers only')
    parser.add_argument('--dump-headers', action='store_true',
                        help='Reconstruct per-header files from N_BINCL data')
    parser.add_argument('--compare-q3', action='store_true',
                        help='Compare STABS struct definitions against Q3A source')
    parser.add_argument('--check-match', metavar='FILE_OR_FUNC',
                        help='Check compiled C function against original binary bytes')

    args = parser.parse_args()

    if not os.path.exists(args.binary):
        print(f'Error: binary not found: {args.binary}', file=sys.stderr)
        sys.exit(1)

    # Load binary
    print(f'Loading {args.binary}...', file=sys.stderr)
    t0 = time.time()

    from .macho_loader import MachOLoader
    loader = MachOLoader(args.binary)
    print(f'  Mach-O loaded: {len(loader.segments)} segments, '
          f'{len(loader.symbols)} symbols', file=sys.stderr)

    # Parse STABS
    from .stabs_parser import StabsParser
    stabs = StabsParser(loader)
    t1 = time.time()
    print(f'  STABS parsed: {len(stabs.all_functions)} functions, '
          f'{len(stabs.compilation_units)} CUs, '
          f'{len(stabs.all_types)} types ({t1-t0:.1f}s)', file=sys.stderr)

    # Handle info-only commands
    if args.stats:
        _print_stats(loader, stabs)
        return

    if args.list_functions:
        _list_functions(stabs)
        return

    if args.list_types:
        _list_types(stabs)
        return

    if args.list_files:
        _list_files(stabs)
        return

    if args.dump_stabs:
        _dump_stabs(loader, stabs)
        return

    # Initialize disassembly engine
    from .disasm import Disassembler
    from .type_system import TypeResolver

    disasm = Disassembler(loader, stabs, att_syntax=args.asm)
    types = TypeResolver(stabs)

    if args.headers:
        os.makedirs(args.output, exist_ok=True)
        header = types.generate_common_types_header()
        path = os.path.join(args.output, 'common_types.h')
        with open(path, 'w') as f:
            f.write(header)
        print(f'Generated {path}', file=sys.stderr)
        return

    if args.imports:
        from .imports import ImportGenerator
        gen = ImportGenerator(loader)
        gen.generate_stubs(args.output)
        summary = gen.get_import_summary()
        print(f'Generated import stubs:', file=sys.stderr)
        for cat, count in sorted(summary.items()):
            print(f'  {cat}: {count} symbols', file=sys.stderr)
        return

    if args.dump_headers:
        from .type_system import TypeResolver
        from .header_reconstruct import HeaderReconstructor
        types = TypeResolver(stabs)
        hr = HeaderReconstructor(stabs, types)
        hr.print_report()
        headers = hr.generate_headers(args.output)
        print(f'\nGenerated {len(headers)} per-header files to {args.output}/',
              file=sys.stderr)
        return

    if args.compare_q3:
        from .type_system import TypeResolver
        from .q3_compare import Q3Comparator
        types = TypeResolver(stabs)
        q3 = Q3Comparator(stabs, types)
        q3.print_report()
        return

    if args.check_match:
        from .type_system import TypeResolver
        from .match_check import MatchChecker
        types = TypeResolver(stabs)
        mc = MatchChecker(loader, stabs, types)
        mc.check(args.check_match)
        return

    # --- ASM mode ---
    if args.asm:
        from .asm_emit import AsmEmitter
        emitter = AsmEmitter(loader, stabs, disasm, types)

        # Single function
        if args.function:
            func = _find_function(stabs, args.function)
            if func is None:
                print(f'Error: function not found: {args.function}', file=sys.stderr)
                sys.exit(1)
            code = emitter.emit_function(func)
            print(code)
            return

        # Single file
        if args.file:
            found = emitter.emit_file_by_name(args.file, args.output)
            if not found:
                print(f'Error: no source file matching: {args.file}', file=sys.stderr)
                sys.exit(1)
            print(f'Emitted to {args.output}/', file=sys.stderr)
            return

        # Full asm dump
        from .imports import ImportGenerator
        from .data_extract import DataExtractor
        from .platform_stubs import PlatformStubGenerator
        from .build_system import BuildSystemGenerator

        def progress(idx, total, filename):
            name = filename.split('/')[-1]
            print(f'\r  [{idx+1}/{total}] {name:40s}', end='', file=sys.stderr)

        print(f'Emitting asm to {args.output}/...', file=sys.stderr)
        t2 = time.time()
        emitter.emit_all(args.output, progress_callback=progress)
        t3 = time.time()
        print(f'\n  ASM emit complete ({t3-t2:.1f}s)', file=sys.stderr)

        # Generate imports
        gen = ImportGenerator(loader)
        gen.generate_stubs(args.output)
        print(f'  Import stubs generated', file=sys.stderr)

        # Extract data sections
        data_ext = DataExtractor(loader, stabs)
        data_ext.generate_all(args.output)
        print(f'  Data sections extracted', file=sys.stderr)

        # Generate platform stubs
        stub_gen = PlatformStubGenerator(loader)
        stub_gen.generate_stubs(args.output)
        print(f'  Platform stubs generated', file=sys.stderr)

        # Generate Makefile
        build_gen = BuildSystemGenerator()
        build_gen.generate(args.output)
        print(f'  Makefile generated', file=sys.stderr)

        total_funcs = len(stabs.all_functions)
        total_cus = len(stabs.compilation_units)
        print(f'\nDone: {total_funcs} functions from {total_cus} source files',
              file=sys.stderr)
        print(f'Build with: cd {args.output} && make -j$(nproc)', file=sys.stderr)
        return

    # --- Standard decompilation mode ---
    from .cfg import CFGBuilder
    cfg_builder = CFGBuilder(loader)

    # Single function decompilation
    if args.function:
        func = _find_function(stabs, args.function)
        if func is None:
            print(f'Error: function not found: {args.function}', file=sys.stderr)
            sys.exit(1)

        from .emit import SourceEmitter
        emitter = SourceEmitter(loader, stabs, disasm, types, cfg_builder,
                                structured=not args.goto)
        code = emitter.emit_function(func)
        print(code)
        return

    # Single file decompilation
    if args.file:
        from .emit import SourceEmitter
        emitter = SourceEmitter(loader, stabs, disasm, types, cfg_builder,
                                structured=not args.goto)
        found = emitter.emit_file_by_name(args.file, args.output)
        if not found:
            print(f'Error: no source file matching: {args.file}', file=sys.stderr)
            sys.exit(1)
        print(f'Emitted to {args.output}/', file=sys.stderr)
        return

    # Full decompilation
    from .emit import SourceEmitter
    from .imports import ImportGenerator
    from .data_extract import DataExtractor
    from .platform_stubs import PlatformStubGenerator
    from .build_system import BuildSystemGenerator

    emitter = SourceEmitter(loader, stabs, disasm, types, cfg_builder,
                            structured=not args.goto)

    def progress(idx, total, filename):
        name = filename.split('/')[-1]
        print(f'\r  [{idx+1}/{total}] {name:40s}', end='', file=sys.stderr)

    print(f'Decompiling to {args.output}/...', file=sys.stderr)
    t2 = time.time()
    emitter.emit_all(args.output, progress_callback=progress)
    t3 = time.time()
    print(f'\n  Decompilation complete ({t3-t2:.1f}s)', file=sys.stderr)

    # Generate imports
    gen = ImportGenerator(loader)
    gen.generate_stubs(args.output)
    print(f'  Import stubs generated', file=sys.stderr)

    # Extract data sections so the generated tree can compile as a project.
    data_ext = DataExtractor(loader, stabs)
    data_ext.generate_all(args.output)
    print(f'  Data sections extracted', file=sys.stderr)

    # Generate platform stubs for macOS-specific imports.
    stub_gen = PlatformStubGenerator(loader)
    stub_gen.generate_stubs(args.output)
    print(f'  Platform stubs generated', file=sys.stderr)

    # Generate a Makefile for the decompiled output.
    build_gen = BuildSystemGenerator()
    build_gen.generate(args.output)
    print(f'  Makefile generated', file=sys.stderr)

    total_funcs = len(stabs.all_functions)
    total_cus = len(stabs.compilation_units)
    print(f'\nDone: {total_funcs} functions from {total_cus} source files',
          file=sys.stderr)
    print(f'Build with: cd {args.output} && make -j$(nproc)', file=sys.stderr)


def _find_function(stabs, spec: str):
    """Find a function by address or name."""
    # Try as hex address
    if spec.startswith('0x') or spec.startswith('0X'):
        try:
            addr = int(spec, 16)
            return stabs.get_function_by_addr(addr)
        except ValueError:
            pass
    # Try as decimal address
    try:
        addr = int(spec)
        return stabs.get_function_by_addr(addr)
    except ValueError:
        pass
    # Try as name (exact match)
    func = stabs.get_function_by_name(spec)
    if func:
        return func
    # Try with underscore prefix
    func = stabs.get_function_by_name('_' + spec)
    if func:
        return func
    # Try partial match
    for f in stabs.all_functions:
        if spec in f.name:
            return f
    return None


def _print_stats(loader, stabs):
    """Print binary statistics."""
    print(f'=== Binary Statistics ===')
    print(f'Segments: {len(loader.segments)}')
    for seg in loader.segments:
        print(f'  {seg.segname:16s} 0x{seg.vmaddr:08x} - 0x{seg.end_addr:08x} '
              f'({seg.vmsize:,} bytes, {len(seg.sections)} sections)')
        for sect in seg.sections:
            print(f'    {sect.sectname:20s} 0x{sect.addr:08x} size={sect.size:,}')

    print(f'\nSymbols: {len(loader.symbols):,}')
    print(f'  Local: {loader.nlocalsym:,}')
    print(f'  External: {loader.nextdefsym:,}')
    print(f'  Undefined (imports): {loader.nundefsym:,}')
    print(f'  Indirect: {len(loader.indirect_syms):,}')

    print(f'\nDylibs: {len(loader.dylibs)}')
    for d in loader.dylibs:
        print(f'  {d.name}')

    print(f'\nEntry point: 0x{loader.entry_point:x}')

    print(f'\nSTABS Debug Info:')
    print(f'  Compilation units: {len(stabs.compilation_units)}')
    print(f'  Functions: {len(stabs.all_functions)}')
    print(f'  Type definitions: {len(stabs.all_types)}')
    print(f'  Global variables: {len(stabs.all_globals)}')

    total_lines = sum(len(f.line_map) for f in stabs.all_functions)
    total_params = sum(len(f.params) for f in stabs.all_functions)
    total_locals = sum(len(f.locals) for f in stabs.all_functions)
    print(f'  Line mappings: {total_lines:,}')
    print(f'  Parameters: {total_params:,}')
    print(f'  Local variables: {total_locals:,}')


def _list_functions(stabs):
    """List all functions."""
    from .demangle import demangle_display
    for f in sorted(stabs.all_functions, key=lambda x: x.addr):
        src = f.source_file.split('/')[-1] if f.source_file else '?'
        display = demangle_display(f.name)
        print(f'0x{f.addr:08x} {f.size:6d} {display:60s} {src}:{f.start_line}')


def _list_types(stabs):
    """List all type definitions."""
    from .type_system import TypeResolver
    types = TypeResolver(stabs)
    for name in sorted(types._all_structs.keys()):
        st = types._all_structs[name]
        kind = 'union' if st.is_union else 'struct'
        nfields = len(st.fields)
        print(f'{kind:6s} {name:40s} size={st.size:5d} fields={nfields}')
    for name in sorted(types._all_enums.keys()):
        et = types._all_enums[name]
        print(f'enum   {name:40s} values={len(et.values)}')
    for name in sorted(types._all_typedefs.keys()):
        key, tdef, cu = types._all_typedefs[name]
        ctype = types.type_to_c(tdef, cu=cu)
        print(f'typedef {ctype} {name};')


def _list_files(stabs):
    """List all compilation units."""
    for cu in stabs.compilation_units:
        nfunc = len(cu.functions)
        ntype = len(cu.types)
        nglobal = len(cu.globals)
        name = cu.source_file.split('/')[-1] if cu.source_file else '?'
        print(f'{name:40s} funcs={nfunc:4d} types={ntype:4d} globals={nglobal:3d}  {cu.source_file}')


def _dump_stabs(loader, stabs):
    """Dump raw STABS entries."""
    from .macho_loader import N_STAB
    TYPE_NAMES = {
        0x20: 'N_GSYM', 0x24: 'N_FUN', 0x26: 'N_STSYM', 0x28: 'N_LCSYM',
        0x2e: 'N_BNSYM', 0x3c: 'N_OPT', 0x40: 'N_RSYM', 0x44: 'N_SLINE',
        0x4e: 'N_ENSYM', 0x60: 'N_SO', 0x64: 'N_SOL', 0x80: 'N_LSYM',
        0x84: 'N_BINCL', 0xa0: 'N_PSYM', 0xa4: 'N_EINCL', 0xc0: 'N_LBRAC',
        0xe0: 'N_RBRAC', 0xc4: 'N_EXCL', 0x3e: 'N_ECOMM', 0x1e: 'N_BCOMM',
    }
    for i, sym in enumerate(loader.symbols):
        if sym.is_stab:
            name = loader.get_string(sym.n_strx)
            tname = TYPE_NAMES.get(sym.n_type, f'0x{sym.n_type:02x}')
            if len(name) > 120:
                name = name[:120] + '...'
            print(f'[{i:6d}] {tname:10s} sect={sym.n_sect} '
                  f'desc={sym.n_desc:5d} val=0x{sym.n_value:08x} '
                  f'"{name}"')


if __name__ == '__main__':
    main()
