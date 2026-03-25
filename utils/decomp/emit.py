"""C source file emitter: assembles decompiled functions into source files."""

import gc
import os
from typing import Optional
from .stabs_parser import StabsParser, CompilationUnit, Function, GlobalVar
from .type_system import TypeResolver
from .disasm import Disassembler, DisassembledFunction
from .cfg import CFGBuilder
from .decompile_goto import GotoDecompiler
from .structure import StructuredDecompiler
from .macho_loader import MachOLoader
from .demangle import demangle_display, get_demangler


# Base path to strip from source file paths
SOURCE_PREFIX = '/Users/kevin/Development/i5works/COD2/Project/'
ALT_PREFIX = '/SourceCache/'


class SourceEmitter:
    """Generates C source files from decompiled functions."""

    def __init__(self, loader: MachOLoader, stabs: StabsParser,
                 disasm: Disassembler, types: TypeResolver,
                 cfg_builder: CFGBuilder, structured: bool = True):
        self.loader = loader
        self.stabs = stabs
        self.disasm = disasm
        self.types = types
        self.cfg_builder = cfg_builder
        self.structured = structured
        self.goto_decompiler = GotoDecompiler(stabs, types, loader)
        self.struct_decompiler = StructuredDecompiler(stabs, types, self.goto_decompiler)

    def emit_all(self, output_dir: str, progress_callback=None):
        """Emit all source files."""
        os.makedirs(output_dir, exist_ok=True)

        # Generate common types header
        types_header = self.types.generate_common_types_header()
        types_path = os.path.join(output_dir, 'common_types.h')
        with open(types_path, 'w') as f:
            f.write(types_header)

        total = len(self.stabs.compilation_units)
        for idx, cu in enumerate(self.stabs.compilation_units):
            if not cu.functions:
                continue
            if progress_callback:
                progress_callback(idx, total, cu.source_file)
            self.emit_compilation_unit(cu, output_dir)
            # Periodic GC to keep memory in check during full decompile
            if idx % 20 == 0:
                get_demangler()._cache.clear()
                gc.collect()

    def emit_compilation_unit(self, cu: CompilationUnit, output_dir: str):
        """Emit a single compilation unit as a .c file."""
        rel_path = self._make_relative_path(cu.source_file)
        if not rel_path:
            return

        # Map .cp extension to .c
        if rel_path.endswith('.cp'):
            rel_path = rel_path[:-3] + '.c'
        elif rel_path.endswith('.cpp'):
            rel_path = rel_path[:-4] + '.c'
        elif not rel_path.endswith('.c') and not rel_path.endswith('.s'):
            rel_path = rel_path + '.c'

        output_path = os.path.join(output_dir, rel_path)
        os.makedirs(os.path.dirname(output_path), exist_ok=True)

        lines = self._generate_file_content(cu)

        with open(output_path, 'w') as f:
            f.write('\n'.join(lines))
            f.write('\n')

    def emit_function(self, func: Function) -> str:
        """Decompile and return C code for a single function."""
        dfunc = self.disasm.disassemble_function(func)
        if not dfunc.instructions:
            return f'/* {func.name}: no instructions */\n'

        blocks = self.cfg_builder.build_cfg(dfunc)

        if self.structured and blocks:
            try:
                return self.struct_decompiler.decompile(dfunc, blocks)
            except Exception:
                pass  # Fall through to goto mode
        return self.goto_decompiler.decompile(dfunc, blocks)

    def _generate_file_content(self, cu: CompilationUnit) -> list[str]:
        """Generate the content of a .c file."""
        lines = []

        # File header comment
        orig_name = cu.source_file.split('/')[-1]
        lines.append(f'/* Decompiled from: {orig_name} */')
        lines.append(f'/* Original path: {cu.source_file} */')
        lines.append('')
        lines.append('#include "common_types.h"')
        lines.append('')

        # Extern declarations for global (non-static) variables defined in this CU
        for gv in cu.globals:
            if gv.kind == 'global' and gv.name:
                vname = demangle_display(gv.name) if gv.name.startswith('_') else gv.name
                gtype = self.types.type_to_c(gv.type_ref, vname, cu=cu)
                lines.append(f'{gtype}; /* 0x{gv.addr:x} */')

        # Forward declarations for static variables
        for gv in cu.globals:
            if gv.kind in ('static', 'bss'):
                vname = demangle_display(gv.name) if gv.name.startswith('_') else gv.name
                gtype = self.types.type_to_c(gv.type_ref, vname, cu=cu)
                lines.append(f'static {gtype}; /* 0x{gv.addr:x} */')
        if cu.globals:
            lines.append('')

        # Forward declarations for functions in this CU
        sorted_funcs = sorted(cu.functions, key=lambda f: f.addr)
        for func in sorted_funcs:
            if func.size == 0:
                continue
            decl = self._make_func_prototype(func)
            lines.append(f'{decl};')
        if sorted_funcs:
            lines.append('')

        # Function definitions
        for func in sorted_funcs:
            if func.size == 0:
                lines.append(f'/* {func.name}: size=0, skipped */')
                lines.append('')
                continue

            try:
                code = self.emit_function(func)
                # Add source line annotation
                if func.start_line:
                    lines.append(f'/* line {func.start_line} */')
                lines.append(code)
                lines.append('')
            except Exception as e:
                lines.append(f'/* Error decompiling {func.name}: {e} */')
                lines.append('')

        return lines

    def _make_func_prototype(self, func: Function) -> str:
        """Generate a function prototype from STABS info."""
        if func.return_type:
            ret_type = self.types.type_to_c(func.return_type, '', cu=func.cu).strip()
        else:
            ret_type = 'int'
        params = []
        for p in func.params:
            ptype = self.types.type_to_c(p.type_ref, p.name, cu=func.cu)
            params.append(ptype)
        params_str = ', '.join(params) if params else 'void'
        fname = demangle_display(func.name)
        return f'{ret_type} {fname}({params_str})'

    def _make_relative_path(self, source_file: str) -> Optional[str]:
        """Convert absolute source path to relative output path."""
        if not source_file:
            return None

        if source_file.startswith(SOURCE_PREFIX):
            return source_file[len(SOURCE_PREFIX):]
        if source_file.startswith(ALT_PREFIX):
            return source_file[len(ALT_PREFIX):]

        # Just use the filename
        name = source_file.split('/')[-1]
        if name:
            return name
        return None

    def emit_file_by_name(self, filename: str, output_dir: str) -> bool:
        """Emit a specific source file by name pattern."""
        for cu in self.stabs.compilation_units:
            if filename in cu.source_file:
                self.emit_compilation_unit(cu, output_dir)
                return True
        return False
