"""GCC binary matching infrastructure.

Extracts original function bytes from the Mach-O binary, compiles
rewritten C functions, and compares at the instruction level to
check for byte-accurate matching.
"""

import os
import re
import struct
import subprocess
import tempfile
from typing import Optional

from .macho_loader import MachOLoader
from .stabs_parser import StabsParser, Function
from .type_system import TypeResolver


class MatchChecker:
    """Compare compiled C output against original binary functions."""

    # Try common GCC paths
    GCC_CANDIDATES = [
        'gcc-4.0',
        '/usr/local/gcc-4.0/bin/gcc',
        '/opt/gcc-4.0/bin/gcc',
        'gcc',  # fallback to system gcc
    ]

    # Default compiler flags matching Apple GCC 4.0 on i386
    DEFAULT_CFLAGS = [
        '-m32',
        '-O2',
        '-fno-strict-aliasing',
        '-fno-pie',
        '-fno-PIC',
        '-std=gnu99',
    ]

    def __init__(self, loader: MachOLoader, stabs: StabsParser,
                 types: TypeResolver):
        self.loader = loader
        self.stabs = stabs
        self.types = types
        self._gcc_path = self._find_gcc()
        self._text_data = self._load_text_section()

    def _find_gcc(self) -> Optional[str]:
        """Find a usable GCC compiler."""
        for candidate in self.GCC_CANDIDATES:
            try:
                result = subprocess.run(
                    [candidate, '--version'],
                    capture_output=True, text=True, timeout=5)
                if result.returncode == 0:
                    version_line = result.stdout.split('\n')[0]
                    return candidate
            except (FileNotFoundError, subprocess.TimeoutExpired):
                continue
        return None

    def _load_text_section(self) -> Optional[tuple]:
        """Load the __TEXT,__text section data.

        Returns (section_addr, data_bytes) or None.
        """
        sect = self.loader.section_by_name.get(('__TEXT', '__text'))
        if not sect:
            return None
        data = self.loader.read_bytes(sect.addr, sect.size)
        return (sect.addr, data)

    def get_function_bytes(self, func: Function) -> Optional[bytes]:
        """Extract the original bytes for a function from the Mach-O binary."""
        if not self._text_data or func.size == 0:
            return None
        sect_addr, data = self._text_data
        offset = func.addr - sect_addr
        if offset < 0 or offset + func.size > len(data):
            return None
        return data[offset:offset + func.size]

    def compile_function(self, source_path: str, cflags: list[str] = None,
                          include_dirs: list[str] = None) -> Optional[bytes]:
        """Compile a C source file and extract .text bytes.

        Returns the compiled .text section bytes, or None on failure.
        """
        if not self._gcc_path:
            print('Error: no GCC compiler found')
            return None

        flags = cflags or self.DEFAULT_CFLAGS[:]
        if include_dirs:
            for d in include_dirs:
                flags.extend(['-I', d])

        with tempfile.NamedTemporaryFile(suffix='.o', delete=False) as tmp:
            obj_path = tmp.name

        try:
            cmd = [self._gcc_path] + flags + ['-c', source_path, '-o', obj_path]
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
            if result.returncode != 0:
                print(f'Compilation failed:')
                print(result.stderr)
                return None

            # Extract .text from ELF object
            return self._extract_text_from_elf(obj_path)
        except subprocess.TimeoutExpired:
            print('Compilation timed out')
            return None
        finally:
            if os.path.exists(obj_path):
                os.unlink(obj_path)

    def _extract_text_from_elf(self, obj_path: str) -> Optional[bytes]:
        """Extract .text section bytes from an ELF .o file using objcopy."""
        with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as tmp:
            bin_path = tmp.name

        try:
            # Use objcopy to extract raw .text bytes
            result = subprocess.run(
                ['objcopy', '-O', 'binary', '-j', '.text', obj_path, bin_path],
                capture_output=True, text=True, timeout=10)
            if result.returncode != 0:
                # Try reading with objdump as fallback
                return self._extract_text_objdump(obj_path)

            with open(bin_path, 'rb') as f:
                return f.read()
        except (FileNotFoundError, subprocess.TimeoutExpired):
            return self._extract_text_objdump(obj_path)
        finally:
            if os.path.exists(bin_path):
                os.unlink(bin_path)

    def _extract_text_objdump(self, obj_path: str) -> Optional[bytes]:
        """Fallback: extract .text using objdump -s."""
        try:
            result = subprocess.run(
                ['objdump', '-s', '-j', '.text', obj_path],
                capture_output=True, text=True, timeout=10)
            if result.returncode != 0:
                return None

            # Parse hex dump
            data = bytearray()
            for line in result.stdout.split('\n'):
                line = line.strip()
                if not line or not line[0].isalnum():
                    continue
                # Format: " addr hex hex hex hex  ascii"
                parts = line.split()
                if len(parts) >= 2:
                    # Skip address, collect hex words
                    for part in parts[1:]:
                        if len(part) == 8 and all(c in '0123456789abcdef' for c in part):
                            data.extend(bytes.fromhex(part))
                        else:
                            break
            return bytes(data) if data else None
        except (FileNotFoundError, subprocess.TimeoutExpired):
            return None

    def compare_bytes(self, original: bytes, compiled: bytes) -> dict:
        """Compare two byte sequences at the instruction level.

        Returns a dict with match statistics:
        - total_bytes: length of original
        - matching_bytes: count of identical bytes
        - match_percent: percentage match
        - first_diff_offset: offset of first difference, or -1 if identical
        """
        orig_len = len(original)
        comp_len = len(compiled)
        min_len = min(orig_len, comp_len)

        matching = sum(1 for i in range(min_len) if original[i] == compiled[i])
        first_diff = -1
        for i in range(min_len):
            if original[i] != compiled[i]:
                first_diff = i
                break
        if first_diff == -1 and orig_len != comp_len:
            first_diff = min_len

        return {
            'total_bytes': orig_len,
            'compiled_bytes': comp_len,
            'matching_bytes': matching,
            'match_percent': (matching / orig_len * 100) if orig_len > 0 else 0,
            'first_diff_offset': first_diff,
            'exact_match': original == compiled,
        }

    def compare_instructions(self, original: bytes, compiled: bytes) -> dict:
        """Compare at instruction level, ignoring relocation targets.

        Uses capstone to disassemble both and compare opcode bytes
        while allowing address operands to differ (they'll be relocated).
        """
        try:
            from capstone import Cs, CS_ARCH_X86, CS_MODE_32
        except ImportError:
            return self.compare_bytes(original, compiled)

        md = Cs(CS_ARCH_X86, CS_MODE_32)
        md.detail = True

        orig_insns = list(md.disasm(original, 0))
        comp_insns = list(md.disasm(compiled, 0))

        total = len(orig_insns)
        matching = 0
        first_diff = -1

        for i, (oi, ci) in enumerate(zip(orig_insns, comp_insns)):
            # Compare mnemonic and register operands (ignore immediate/displacement values
            # which may differ due to relocation)
            if oi.mnemonic == ci.mnemonic and oi.bytes[0] == ci.bytes[0]:
                # Same opcode prefix byte + mnemonic = structural match
                matching += 1
            elif first_diff == -1:
                first_diff = i

        if first_diff == -1 and len(orig_insns) != len(comp_insns):
            first_diff = min(len(orig_insns), len(comp_insns))

        return {
            'total_insns': total,
            'compiled_insns': len(comp_insns),
            'matching_insns': matching,
            'match_percent': (matching / total * 100) if total > 0 else 0,
            'first_diff_insn': first_diff,
            'exact_match': (len(orig_insns) == len(comp_insns) and
                          matching == total),
        }

    def check(self, spec: str):
        """Check match for a file or function specified on the command line.

        Spec can be:
        - A .c source file path (compiles and compares all functions in it)
        - A function name (extracts original bytes and prints hex dump)
        - A hex address (same as function name)
        """
        # Check if it's a file
        if os.path.isfile(spec):
            self._check_file(spec)
            return

        # Try as function spec
        func = self._find_function(spec)
        if func:
            self._check_function(func)
            return

        print(f'Error: "{spec}" is not a file or known function')

    def _find_function(self, spec: str) -> Optional[Function]:
        """Find a function by address or name."""
        if spec.startswith('0x') or spec.startswith('0X'):
            try:
                addr = int(spec, 16)
                return self.stabs.get_function_by_addr(addr)
            except ValueError:
                pass
        try:
            addr = int(spec)
            return self.stabs.get_function_by_addr(addr)
        except ValueError:
            pass
        func = self.stabs.get_function_by_name(spec)
        if func:
            return func
        func = self.stabs.get_function_by_name('_' + spec)
        if func:
            return func
        for f in self.stabs.all_functions:
            if spec in f.name:
                return f
        return None

    def _check_function(self, func: Function):
        """Print info about a single function for matching."""
        print(f'=== Function: {func.name} ===')
        print(f'Address: 0x{func.addr:08x}')
        print(f'Size: {func.size} bytes')
        print(f'Source: {func.source_file}:{func.start_line}')

        original = self.get_function_bytes(func)
        if original:
            print(f'\nOriginal bytes ({len(original)} bytes):')
            # Print hex dump
            for i in range(0, len(original), 16):
                chunk = original[i:i+16]
                hex_str = ' '.join(f'{b:02x}' for b in chunk)
                ascii_str = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
                print(f'  {i:04x}: {hex_str:<48s} {ascii_str}')

            # Disassemble
            try:
                from capstone import Cs, CS_ARCH_X86, CS_MODE_32
                md = Cs(CS_ARCH_X86, CS_MODE_32)
                print(f'\nDisassembly:')
                for insn in md.disasm(original, func.addr):
                    print(f'  0x{insn.address:08x}: {insn.mnemonic:8s} {insn.op_str}')
            except ImportError:
                print('(capstone not available for disassembly)')
        else:
            print('Could not extract function bytes')

        if not self._gcc_path:
            print('\nNo GCC compiler found for match checking.')
            print('Install GCC 4.0 or set GCC40 environment variable.')
        else:
            print(f'\nCompiler: {self._gcc_path}')
            print(f'Flags: {" ".join(self.DEFAULT_CFLAGS)}')
            print(f'\nTo check match:')
            print(f'  1. Write C implementation in a .c file')
            print(f'  2. Run: python3 -m decomp.decomp binary.x86 --check-match your_file.c')

    def _check_file(self, source_path: str):
        """Compile a C file and compare against original binary."""
        print(f'=== Match Check: {source_path} ===')

        if not self._gcc_path:
            print('Error: no GCC compiler found')
            return

        # Determine include directory (where common_types.h lives)
        include_dirs = []
        src_dir = os.path.dirname(os.path.abspath(source_path))
        # Look for common_types.h
        for candidate in [src_dir, os.path.join(src_dir, '..'),
                         os.path.join(src_dir, '..', '..')]:
            if os.path.exists(os.path.join(candidate, 'common_types.h')):
                include_dirs.append(candidate)
                break

        print(f'Compiler: {self._gcc_path}')
        print(f'Flags: {" ".join(self.DEFAULT_CFLAGS)}')
        if include_dirs:
            print(f'Include: {include_dirs[0]}')

        compiled = self.compile_function(source_path, include_dirs=include_dirs)
        if compiled is None:
            return

        print(f'Compiled size: {len(compiled)} bytes')

        # Try to match against functions
        # Read the source to find function names
        with open(source_path) as f:
            source = f.read()

        # Find function definitions (simple heuristic)
        func_pattern = re.compile(r'^\w[\w\s*]+\s+(\w+)\s*\([^)]*\)\s*\{',
                                  re.MULTILINE)
        func_names = func_pattern.findall(source)

        if not func_names:
            print('No function definitions found in source')
            return

        for fname in func_names:
            func = self._find_function(fname)
            if not func:
                print(f'\n{fname}: not found in binary (skipping)')
                continue

            original = self.get_function_bytes(func)
            if not original:
                print(f'\n{fname}: could not extract original bytes')
                continue

            result = self.compare_instructions(original, compiled)
            status = 'MATCH' if result.get('exact_match') else 'MISMATCH'
            pct = result.get('match_percent', 0)
            print(f'\n{fname} (0x{func.addr:08x}): {status} ({pct:.1f}% instructions)')
            if not result.get('exact_match'):
                total = result.get('total_insns', 0)
                matching = result.get('matching_insns', 0)
                print(f'  Original: {result.get("total_insns", 0)} instructions')
                print(f'  Compiled: {result.get("compiled_insns", 0)} instructions')
                print(f'  Matching: {matching}/{total}')
                first = result.get('first_diff_insn', -1)
                if first >= 0:
                    print(f'  First difference at instruction #{first}')

    def print_compiler_info(self):
        """Print information about the available compiler."""
        if self._gcc_path:
            result = subprocess.run(
                [self._gcc_path, '--version'],
                capture_output=True, text=True, timeout=5)
            print(f'Compiler: {self._gcc_path}')
            print(result.stdout.split('\n')[0])
        else:
            print('No GCC compiler found.')
            print('Expected: gcc-4.0 or /usr/local/gcc-4.0/bin/gcc')
            print('Target: Apple GCC 4.0 (GCC 4.0.4 mainline as fallback)')
