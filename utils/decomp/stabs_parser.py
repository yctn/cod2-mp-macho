"""STABS debug info parser for Mach-O binaries."""

import os
from dataclasses import dataclass, field
from typing import Optional
from .macho_loader import (
    MachOLoader, NList,
    N_GSYM, N_FUN, N_STSYM, N_LCSYM, N_BNSYM, N_OPT,
    N_RSYM, N_SLINE, N_ENSYM, N_SOL, N_LSYM, N_BINCL,
    N_PSYM, N_EINCL, N_LBRAC, N_RBRAC, N_EXCL, N_BCOMM, N_ECOMM, N_STAB
)

# Source path prefixes to strip for normalization
SOURCE_PREFIX = '/Users/kevin/Development/i5works/COD2/Project/'
ALT_PREFIX = '/SourceCache/'


def _normalize_header_path(path: str) -> str:
    """Strip source prefix and resolve .. components."""
    for prefix in (SOURCE_PREFIX, ALT_PREFIX):
        if path.startswith(prefix):
            path = path[len(prefix):]
            break
    return os.path.normpath(path)


# Type definitions
@dataclass
class StabsType:
    """Base class for all STABS type nodes."""
    pass

@dataclass
class TypeRef(StabsType):
    file_num: int
    type_id: int

@dataclass
class RangeType(StabsType):
    base: tuple  # (file_num, type_id)
    low: str
    high: str

@dataclass
class PointerType(StabsType):
    target: StabsType

@dataclass
class ReferenceType(StabsType):
    target: StabsType

@dataclass
class ConstType(StabsType):
    target: StabsType

@dataclass
class VolatileType(StabsType):
    target: StabsType

@dataclass
class ArrayType(StabsType):
    index_type: StabsType
    low: int
    high: int
    elem_type: StabsType

@dataclass
class StructField:
    name: str
    type: StabsType
    bit_offset: int
    bit_size: int

@dataclass
class StructType(StabsType):
    size: int
    fields: list[StructField]
    is_union: bool = False

@dataclass
class EnumValue:
    name: str
    value: int

@dataclass
class EnumType(StabsType):
    values: list[EnumValue]

@dataclass
class FuncType(StabsType):
    return_type: StabsType

@dataclass
class CrossRefType(StabsType):
    kind: str  # 's' for struct, 'u' for union, 'e' for enum
    name: str

@dataclass
class SizedType(StabsType):
    bits: int
    inner: StabsType

@dataclass
class MethodType(StabsType):
    """C++ method - stored but generally skipped in C output."""
    info: str


# Function-level data structures
@dataclass
class Parameter:
    name: str
    type_ref: StabsType
    stack_offset: int
    line: int

@dataclass
class LocalVar:
    name: str
    type_ref: StabsType
    ebp_offset: int  # negative offset from EBP
    line: int
    scope_depth: int = 0  # nesting depth from N_LBRAC/N_RBRAC

@dataclass
class RegisterVar:
    name: str
    type_ref: StabsType
    register: int  # DWARF register number
    line: int
    is_param: bool = False  # True if 'P' descriptor (register parameter)

@dataclass
class SourceLine:
    addr: int
    line: int

@dataclass
class ScopeBracket:
    addr: int    # absolute address of scope boundary
    depth: int   # scope depth after this bracket
    is_open: bool  # True = LBRAC (open), False = RBRAC (close)

@dataclass
class Function:
    name: str
    addr: int
    size: int
    source_file: str
    start_line: int
    params: list[Parameter] = field(default_factory=list)
    locals: list[LocalVar] = field(default_factory=list)
    reg_vars: list[RegisterVar] = field(default_factory=list)
    line_map: list[SourceLine] = field(default_factory=list)
    scope_brackets: list[ScopeBracket] = field(default_factory=list)
    cu: Optional['CompilationUnit'] = field(default=None, repr=False)
    return_type: Optional[StabsType] = None
    is_static: bool = False  # True if STABS descriptor is 'f' (local/static function)

@dataclass
class TypeDef:
    name: str
    file_num: int
    type_id: int
    type_def: StabsType
    is_tag: bool  # T = struct/union/enum tag, t = typedef

@dataclass
class GlobalVar:
    name: str
    type_ref: StabsType
    addr: int  # 0 for N_GSYM (resolved via symbol table)
    kind: str  # 'global', 'static', 'bss'
    source_file: str
    line: int

@dataclass
class CompilationUnit:
    directory: str
    source_file: str
    functions: list[Function] = field(default_factory=list)
    types: list[TypeDef] = field(default_factory=list)
    globals: list[GlobalVar] = field(default_factory=list)
    type_map: dict = field(default_factory=dict)  # (file,id) -> StabsType
    include_files: list[str] = field(default_factory=list)  # ordered unique headers from N_SOL
    header_types: dict = field(default_factory=dict)  # normalized_header_path -> list[TypeDef]


class StabsTypeParser:
    """Recursive descent parser for STABS type description strings."""

    def __init__(self, s: str, pos: int = 0):
        self.s = s
        self.pos = pos

    def peek(self) -> str:
        if self.pos >= len(self.s):
            return ''
        return self.s[self.pos]

    def advance(self) -> str:
        c = self.s[self.pos]
        self.pos += 1
        return c

    def expect(self, c: str):
        if self.pos >= len(self.s) or self.s[self.pos] != c:
            return False
        self.pos += 1
        return True

    def parse_number(self) -> str:
        start = self.pos
        if self.pos < len(self.s) and self.s[self.pos] in '-+':
            self.pos += 1
        while self.pos < len(self.s) and self.s[self.pos].isdigit():
            self.pos += 1
        return self.s[start:self.pos]

    def parse_int(self) -> int:
        s = self.parse_number()
        if not s or s in ('+', '-'):
            return 0
        return int(s)

    def parse_type_ref(self) -> tuple:
        """Parse (file_num,type_id) or just type_id."""
        if self.peek() == '(':
            self.advance()  # (
            file_num = self.parse_int()
            self.expect(',')
            type_id = self.parse_int()
            self.expect(')')
            return (file_num, type_id)
        else:
            tid = self.parse_int()
            return (0, tid)

    def parse_type(self) -> StabsType:
        """Parse a STABS type expression."""
        if self.pos >= len(self.s):
            return TypeRef(0, 0)

        c = self.peek()

        # Type reference: (file,id) or just number
        if c == '(' or c.isdigit() or c == '-':
            ref = self.parse_type_ref()
            # Check if this is a definition: (file,id)=...
            if self.peek() == '=':
                self.advance()  # =
                return self._parse_type_definition(ref)
            return TypeRef(ref[0], ref[1])

        # Pointer
        if c == '*':
            self.advance()
            target = self.parse_type()
            return PointerType(target)

        # Reference
        if c == '&':
            self.advance()
            target = self.parse_type()
            return ReferenceType(target)

        # Const
        if c == 'k':
            self.advance()
            target = self.parse_type()
            return ConstType(target)

        # Volatile
        if c == 'B':
            self.advance()
            target = self.parse_type()
            return VolatileType(target)

        # Function type
        if c == 'f':
            self.advance()
            ret = self.parse_type()
            return FuncType(ret)

        # Range type
        if c == 'r':
            return self._parse_range()

        # Struct
        if c == 's':
            return self._parse_struct(False)

        # Union
        if c == 'u':
            return self._parse_struct(True)

        # Enum
        if c == 'e':
            return self._parse_enum()

        # Array
        if c == 'a':
            return self._parse_array()

        # Cross-reference
        if c == 'x':
            return self._parse_cross_ref()

        # Size annotation: @s<bits>;
        if c == '@':
            return self._parse_sized()

        # Method type (C++ - skip)
        if c == '#':
            return self._parse_method()

        # Unknown - consume and return void ref
        self.advance()
        return TypeRef(0, 0)

    def _parse_type_definition(self, ref: tuple) -> StabsType:
        """Parse after seeing (file,id)="""
        t = self.parse_type()
        # Wrap to preserve the definition identity
        return t

    def _parse_range(self) -> RangeType:
        self.advance()  # 'r'
        base = self.parse_type_ref()
        self.expect(';')
        low = self.parse_number()
        self.expect(';')
        high = self.parse_number()
        self.expect(';')
        return RangeType(base, low, high)

    def _parse_struct(self, is_union: bool) -> StructType:
        self.advance()  # 's' or 'u'
        num_s = self.parse_number()
        if not num_s:
            return StructType(0, [], is_union)
        size = int(num_s)
        fields = []
        while self.pos < len(self.s) and self.peek() != ';':
            # Skip C++ base class specs (start with !)
            if self.peek() == '!':
                self._skip_base_classes()
                continue
            # Save position before reading field name
            save_pos = self.pos
            fname = self._read_until(':')
            if fname is None:
                break
            # Check if this is a C++ method definition (::)
            if self.peek() == ':':
                # It's a method section - skip everything until ;;
                self._skip_cpp_methods()
                continue
            # Regular field: type,bitoff,bitsize;
            try:
                ftype = self.parse_type()
                if not self.expect(','):
                    # Malformed - skip to next ;
                    self._skip_to_semicolon()
                    continue
                bo_s = self.parse_number()
                if not bo_s:
                    self._skip_to_semicolon()
                    continue
                bit_offset = int(bo_s)
                if not self.expect(','):
                    self._skip_to_semicolon()
                    continue
                bs_s = self.parse_number()
                if not bs_s:
                    self._skip_to_semicolon()
                    continue
                bit_size = int(bs_s)
                self.expect(';')
                fields.append(StructField(fname, ftype, bit_offset, bit_size))
            except (ValueError, IndexError):
                self._skip_to_semicolon()
                continue
        self.expect(';')
        return StructType(size, fields, is_union)

    def _skip_to_semicolon(self):
        """Skip ahead to the next semicolon."""
        depth = 0
        while self.pos < len(self.s):
            c = self.s[self.pos]
            if c == '(':
                depth += 1
            elif c == ')':
                depth -= 1
            elif c == ';' and depth <= 0:
                self.pos += 1
                return
            self.pos += 1

    def _skip_base_classes(self):
        """Skip C++ base class specifications."""
        self.advance()  # '!'
        nbase_s = self.parse_number()
        if not nbase_s:
            return
        nbase = int(nbase_s)
        self.expect(',')
        for _ in range(nbase):
            # Format: virtual_flag access_flag offset , type ;
            while self.pos < len(self.s) and self.peek() != ';':
                self.advance()
            self.expect(';')

    def _skip_cpp_methods(self):
        """Skip C++ method definitions in struct body.
        Methods appear as name::type;vis;flags; and end with ;; at end of struct fields."""
        # We already consumed name: and see another :
        # Skip everything until we find ;; which ends the method block,
        # or until we reach end of struct
        depth = 0
        prev_semi = False
        while self.pos < len(self.s):
            c = self.s[self.pos]
            if c == '(':
                depth += 1
                self.pos += 1
                prev_semi = False
            elif c == ')':
                depth -= 1
                self.pos += 1
                prev_semi = False
            elif c == ';' and depth <= 0:
                self.pos += 1
                if prev_semi:
                    # ;; = end of struct or end of method section
                    # Put back one ; since the struct parser expects to see it
                    self.pos -= 1
                    return
                prev_semi = True
            else:
                prev_semi = False
                self.pos += 1

    def _parse_enum(self) -> EnumType:
        self.advance()  # 'e'
        values = []
        while self.pos < len(self.s) and self.peek() != ';':
            name = self._read_until(':')
            if name is None:
                break
            val = self.parse_int()
            self.expect(',')
            values.append(EnumValue(name, val))
        self.expect(';')
        return EnumType(values)

    def _parse_array(self) -> ArrayType:
        self.advance()  # 'a'
        if self.peek() == 'r':
            idx_type = self.parse_type()
            # For 'ar' shorthand: ar(idx);lo;hi;(elem)
            if isinstance(idx_type, RangeType):
                lo = int(idx_type.low)
                hi = int(idx_type.high)
                elem = self.parse_type()
                return ArrayType(idx_type, lo, hi, elem)
        else:
            idx_type = self.parse_type()
        self.expect(';')
        lo = self.parse_int()
        self.expect(';')
        hi = self.parse_int()
        self.expect(';')
        elem = self.parse_type()
        return ArrayType(idx_type, lo, hi, elem)

    def _parse_cross_ref(self) -> CrossRefType:
        self.advance()  # 'x'
        kind = self.advance()  # 's', 'u', or 'e'
        name = self._read_until(':')
        return CrossRefType(kind, name or '')

    def _parse_sized(self) -> StabsType:
        self.advance()  # '@'
        if self.peek() == 's':
            self.advance()  # 's'
            bits = self.parse_int()
            self.expect(';')
            inner = self.parse_type()
            return SizedType(bits, inner)
        # Other @ annotations - skip to ;
        while self.pos < len(self.s) and self.peek() != ';':
            self.advance()
        self.expect(';')
        return self.parse_type()

    def _parse_method(self) -> MethodType:
        start = self.pos
        self.advance()  # '#'
        # Skip method type info - consume to matching ;
        depth = 0
        while self.pos < len(self.s):
            c = self.s[self.pos]
            if c == '(':
                depth += 1
            elif c == ')':
                depth -= 1
            elif c == ';' and depth == 0:
                self.pos += 1
                break
            self.pos += 1
        return MethodType(self.s[start:self.pos])

    def _read_until(self, delim: str) -> Optional[str]:
        start = self.pos
        while self.pos < len(self.s):
            if self.s[self.pos] == delim:
                result = self.s[start:self.pos]
                self.pos += 1  # skip delimiter
                return result
            self.pos += 1
        return None


def _parse_stabs_name_and_type(s: str):
    """Parse 'name:descriptor(type)' STABS string.
    Returns (name, descriptor, type_string, remaining)."""
    colon = s.find(':')
    if colon < 0:
        return s, '', '', ''
    name = s[:colon]
    rest = s[colon+1:]
    return name, rest


class StabsParser:
    def __init__(self, loader: MachOLoader):
        self.loader = loader
        self.compilation_units: list[CompilationUnit] = []
        self.all_functions: list[Function] = []
        self.all_types: dict[tuple, StabsType] = {}  # (file_num, type_id) -> type
        self.type_names: dict[tuple, str] = {}  # (file_num, type_id) -> name
        self.all_globals: list[GlobalVar] = []
        self._parse()

    def _parse(self):
        symbols = self.loader.symbols
        n = len(symbols)
        i = 0
        current_cu = None
        current_func = None
        current_file = ''
        pending_bnsym_addr = None
        pending_slines = []  # Buffer SLINEs between BNSYM and FUN
        current_header = None  # Track current header for N_SOL include mapping
        scope_depth = 0  # N_LBRAC/N_RBRAC nesting depth

        while i < n:
            sym = symbols[i]
            if not sym.is_stab:
                i += 1
                continue

            stype = sym.n_type
            name_str = self.loader.get_string(sym.n_strx)

            if stype == N_LBRAC:
                scope_depth += 1
                if current_func:
                    bracket_addr = sym.n_value
                    # n_value is relative to function start for LBRAC/RBRAC
                    if bracket_addr < current_func.addr:
                        bracket_addr += current_func.addr
                    current_func.scope_brackets.append(
                        ScopeBracket(bracket_addr, scope_depth, True))
                i += 1
                continue

            if stype == N_RBRAC:
                scope_depth = max(0, scope_depth - 1)
                if current_func:
                    bracket_addr = sym.n_value
                    if bracket_addr < current_func.addr:
                        bracket_addr += current_func.addr
                    current_func.scope_brackets.append(
                        ScopeBracket(bracket_addr, scope_depth, False))
                i += 1
                continue

            if stype == N_SOL:
                # Source file line / compilation unit marker
                if name_str and ('/' in name_str or name_str.endswith('.s')):
                    if name_str.endswith('/'):
                        # Directory prefix - next SOL should be full path
                        directory = name_str
                        i += 1
                        if i < n:
                            next_sym = symbols[i]
                            next_str = self.loader.get_string(next_sym.n_strx)
                            if next_sym.n_type == N_SOL and next_str and not next_str.endswith('/'):
                                # New compilation unit
                                current_cu = CompilationUnit(directory, next_str)
                                self.compilation_units.append(current_cu)
                                current_file = next_str
                                current_header = None
                        continue
                    elif sym.n_desc in (0, 4) and not any(
                        name_str.endswith(ext) for ext in ('.h', '.hpp')
                    ):
                        # Start of new CU with just the file path
                        if current_cu is None or name_str != current_file:
                            # Check if previous SOL was a directory
                            current_cu = CompilationUnit('', name_str)
                            self.compilation_units.append(current_cu)
                            current_file = name_str
                        current_header = None  # Back to .c file
                    elif any(name_str.endswith(ext) for ext in ('.h', '.hpp')):
                        # N_SOL pointing to a header file — track include
                        if current_cu is not None:
                            norm_path = _normalize_header_path(name_str)
                            if norm_path not in current_cu.include_files:
                                current_cu.include_files.append(norm_path)
                            current_header = norm_path
                i += 1
                continue

            if stype == N_BINCL:
                # Begin include file — track header includes for CU
                if current_cu is not None and name_str:
                    if any(name_str.endswith(ext) for ext in ('.h', '.hpp')):
                        norm_path = _normalize_header_path(name_str)
                        if norm_path not in current_cu.include_files:
                            current_cu.include_files.append(norm_path)
                        current_header = norm_path
                    else:
                        # Back to .c/.cpp source — reset header tracking
                        current_header = None
                i += 1
                continue

            if stype == N_OPT:
                i += 1
                continue

            if stype == N_BNSYM:
                pending_bnsym_addr = sym.n_value
                current_func = None
                pending_slines = []
                i += 1
                continue

            if stype == N_ENSYM:
                if current_func is not None:
                    current_func = None
                pending_bnsym_addr = None
                i += 1
                continue

            if stype == N_FUN:
                if not name_str:
                    # End marker: value is size
                    if current_func is not None:
                        current_func.size = sym.n_value
                    scope_depth = 0
                    i += 1
                    continue
                # Function definition
                fname, rest = _parse_stabs_name_and_type(name_str)
                # Parse return type from descriptor (F=global func, f=local func)
                ret_type_ref = None
                func_is_static = False
                if rest and rest[0] in ('F', 'f'):
                    func_is_static = (rest[0] == 'f')
                    try:
                        type_str = rest[1:]
                        parser = StabsTypeParser(type_str)
                        ret_type_ref = parser.parse_type()
                    except Exception:
                        ret_type_ref = None
                addr = sym.n_value
                scope_depth = 0  # Reset scope for new function
                func = Function(
                    name=fname,
                    addr=addr,
                    size=0,
                    source_file=current_file,
                    start_line=sym.n_desc,
                    cu=current_cu,
                    return_type=ret_type_ref,
                    is_static=func_is_static,
                )
                # Attach buffered SLINEs
                func.line_map = pending_slines[:]
                pending_slines = []
                current_func = func
                if current_cu:
                    current_cu.functions.append(func)
                self.all_functions.append(func)
                i += 1
                continue

            if stype == N_SLINE:
                sl = SourceLine(addr=sym.n_value, line=sym.n_desc)
                if current_func is not None:
                    current_func.line_map.append(sl)
                else:
                    # Buffer - will be attached when FUN is seen
                    pending_slines.append(sl)
                i += 1
                continue

            if stype == N_PSYM:
                if current_func is not None:
                    pname, rest = _parse_stabs_name_and_type(name_str)
                    ptype = self._parse_type_from_descriptor(rest)
                    current_func.params.append(
                        Parameter(pname, ptype, sym.n_value, sym.n_desc)
                    )
                i += 1
                continue

            if stype == N_RSYM:
                if current_func is not None:
                    rname, rest = _parse_stabs_name_and_type(name_str)
                    is_reg_param = rest.startswith('P')
                    rtype = self._parse_type_from_descriptor(rest)
                    current_func.reg_vars.append(
                        RegisterVar(rname, rtype, sym.n_value, sym.n_desc,
                                    is_param=is_reg_param)
                    )
                i += 1
                continue

            if stype == N_LSYM:
                name_str = self._handle_continuation(symbols, i, name_str)
                if name_str and ':' in name_str:
                    lname, rest = _parse_stabs_name_and_type(name_str)
                    if rest.startswith('t') or rest.startswith('T'):
                        # Type definition
                        is_tag = rest.startswith('T')
                        type_str = rest.lstrip('Tt')
                        ttype = self._parse_type_string(type_str)
                        # Extract type ref
                        ref = self._extract_type_ref(type_str)
                        if ref:
                            # Don't overwrite a concrete type (struct/enum)
                            # with a self-referencing TypeRef alias
                            _is_self_ref = (isinstance(ttype, TypeRef) and
                                            (ttype.file_num, ttype.type_id) == ref)
                            existing = self.all_types.get(ref)
                            if not (_is_self_ref and isinstance(existing,
                                    (StructType, EnumType, PointerType, ArrayType))):
                                self.all_types[ref] = ttype
                            if lname:
                                self.type_names[ref] = lname
                            if current_cu:
                                cu_existing = current_cu.type_map.get(ref)
                                if not (_is_self_ref and isinstance(cu_existing,
                                        (StructType, EnumType, PointerType, ArrayType))):
                                    current_cu.type_map[ref] = ttype
                                td = TypeDef(lname, ref[0], ref[1], ttype, is_tag)
                                current_cu.types.append(td)
                                # Associate type with current header if inside an #include
                                if current_header is not None:
                                    current_cu.header_types.setdefault(
                                        current_header, []).append(td)
                    elif rest.startswith('(') or (rest and rest[0].isdigit()):
                        # Local variable
                        if current_func is not None and sym.n_value != 0:
                            ltype = self._parse_type_from_descriptor(rest)
                            current_func.locals.append(
                                LocalVar(lname, ltype, sym.n_value, sym.n_desc,
                                         scope_depth=scope_depth)
                            )
                        elif current_func is not None and sym.n_value == 0 and sym.n_desc != 0:
                            # Could be a local with 0 offset (unlikely) or misclassified
                            ltype = self._parse_type_from_descriptor(rest)
                            current_func.locals.append(
                                LocalVar(lname, ltype, sym.n_value, sym.n_desc,
                                         scope_depth=scope_depth)
                            )
                i += 1
                continue

            if stype == N_GSYM:
                if name_str and ':' in name_str:
                    gname, rest = _parse_stabs_name_and_type(name_str)
                    gtype = self._parse_type_from_descriptor(rest.lstrip('G'))
                    gvar = GlobalVar(gname, gtype, 0, 'global', current_file, sym.n_desc)
                    self.all_globals.append(gvar)
                    if current_cu:
                        current_cu.globals.append(gvar)
                i += 1
                continue

            if stype == N_STSYM:
                if name_str and ':' in name_str:
                    sname, rest = _parse_stabs_name_and_type(name_str)
                    stype_ref = self._parse_type_from_descriptor(rest.lstrip('S').lstrip('V'))
                    svar = GlobalVar(sname, stype_ref, sym.n_value, 'static',
                                     current_file, sym.n_desc)
                    self.all_globals.append(svar)
                    if current_cu:
                        current_cu.globals.append(svar)
                i += 1
                continue

            if stype == N_LCSYM:
                if name_str and ':' in name_str:
                    bname, rest = _parse_stabs_name_and_type(name_str)
                    btype = self._parse_type_from_descriptor(rest.lstrip('S').lstrip('V'))
                    bvar = GlobalVar(bname, btype, sym.n_value, 'bss',
                                     current_file, sym.n_desc)
                    self.all_globals.append(bvar)
                    if current_cu:
                        current_cu.globals.append(bvar)
                i += 1
                continue

            # Skip other stab types
            i += 1

    def _handle_continuation(self, symbols, i, name_str):
        """Handle STABS continuation strings (truncated at ~80 chars, continued by next entry)."""
        if not name_str.endswith('\\'):
            return name_str
        parts = [name_str[:-1]]
        j = i + 1
        while j < len(symbols):
            sym = symbols[j]
            if not sym.is_stab:
                break
            s = self.loader.get_string(sym.n_strx)
            if sym.n_type == N_LSYM and s and sym.n_value == 0:
                if s.endswith('\\'):
                    parts.append(s[:-1])
                    j += 1
                    continue
                else:
                    parts.append(s)
                    break
            break
        return ''.join(parts)

    def _parse_type_from_descriptor(self, rest: str) -> StabsType:
        """Parse type from descriptor string after ':' and any descriptor prefix."""
        # Strip descriptor prefix (p, r, G, S, V, etc.)
        s = rest
        while s and s[0].isalpha() and s[0] not in '(' and s[0] not in 'rseufkBa':
            s = s[1:]
        if not s:
            return TypeRef(0, 0)
        parser = StabsTypeParser(s)
        return parser.parse_type()

    def _parse_type_string(self, s: str) -> StabsType:
        """Parse a full type definition string."""
        parser = StabsTypeParser(s)
        return parser.parse_type()

    def _extract_type_ref(self, s: str) -> Optional[tuple]:
        """Extract (file_num, type_id) from start of type string."""
        if not s:
            return None
        if s[0] == '(':
            try:
                comma = s.index(',', 1)
                close = s.index(')', comma)
                file_num = int(s[1:comma])
                type_id = int(s[comma+1:close])
                return (file_num, type_id)
            except (ValueError, IndexError):
                return None
        # Plain number
        try:
            i = 0
            if s[i] in '-+':
                i += 1
            while i < len(s) and s[i].isdigit():
                i += 1
            if i > 0:
                return (0, int(s[:i]))
        except ValueError:
            pass
        return None

    def get_function_by_addr(self, addr: int) -> Optional[Function]:
        for f in self.all_functions:
            if f.addr == addr:
                return f
        return None

    def get_function_by_name(self, name: str) -> Optional[Function]:
        for f in self.all_functions:
            if f.name == name:
                return f
        return None

    def get_functions_for_file(self, filename: str) -> list[Function]:
        return [f for f in self.all_functions
                if filename in f.source_file]

    def resolve_type(self, t: StabsType, visited: Optional[set] = None) -> StabsType:
        """Follow TypeRef chains to find the actual type definition."""
        if visited is None:
            visited = set()
        if isinstance(t, TypeRef):
            key = (t.file_num, t.type_id)
            if key in visited:
                return t
            visited.add(key)
            resolved = self.all_types.get(key)
            if resolved and not isinstance(resolved, TypeRef):
                return resolved
            if resolved:
                return self.resolve_type(resolved, visited)
        return t

    def get_type_name(self, t: StabsType) -> Optional[str]:
        """Get the human-readable name for a type."""
        if isinstance(t, TypeRef):
            key = (t.file_num, t.type_id)
            return self.type_names.get(key)
        return None
