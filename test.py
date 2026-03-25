
#!/usr/bin/env python3
import sys
import re
from pathlib import Path

ATTR = re.compile(r'__attribute__\s*\(\(\s*naked\s*\)\)')

def match_brace(text, start):
    depth = 0
    for i in range(start, len(text)):
        if text[i] == '{':
            depth += 1
        elif text[i] == '}':
            depth -= 1
            if depth == 0:
                return i
    return -1

def scan_file(path):
    data = path.read_text(errors="ignore")

    for m in ATTR.finditer(data):
        attr_pos = m.start()

        open_brace = data.find("{", m.end())
        if open_brace == -1:
            continue

        close_brace = match_brace(data, open_brace)
        if close_brace == -1:
            continue

        # walk backward to approximate start of declaration
        start = max(
            data.rfind("\n\n", 0, attr_pos),
            data.rfind(";", 0, attr_pos),
            data.rfind("}", 0, attr_pos),
        )
        start = 0 if start == -1 else start + 1

        sys.stdout.write(data[start:close_brace+1])
        sys.stdout.write("\n\n")

def walk(path):
    if path.is_file():
        scan_file(path)
        return
    for p in path.rglob("*"):
        if p.suffix in (".c",".h",".cc",".cpp",".cxx",".hpp",".hh",".hxx"):
            scan_file(p)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: script path...", file=sys.stderr)
        sys.exit(1)

    for arg in sys.argv[1:]:
        walk(Path(arg))
