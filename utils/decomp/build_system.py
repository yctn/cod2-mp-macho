"""Makefile generator for the decompiled COD2 Linux project."""

import os


class BuildSystemGenerator:
    """Generate a Makefile for the decompiled project."""

    def __init__(self):
        self.cc = 'gcc'
        self.cflags = '-m32 -fno-pie -no-pie -w -O0 -g -I.'
        self.ldflags = '-m32 -no-pie'
        self.libs = '-lGL -lm -lpthread -ldl -lstdc++'
        self.target = 'cod2_linux'

    def generate(self, output_dir: str):
        """Generate the Makefile in the output directory."""
        makefile_path = os.path.join(output_dir, 'Makefile')

        content = f'''# Auto-generated Makefile for COD2 Linux decompilation
# Build with: make -j$(nproc)

CC = {self.cc}
CFLAGS = {self.cflags}
LDFLAGS = {self.ldflags}
LIBS = {self.libs}
TARGET = {self.target}

# Find all source files recursively
C_SRCS = $(shell find . -name '*.c' | sort)
S_SRCS = $(shell find . -name '*.S' | sort)
SRCS = $(C_SRCS) $(S_SRCS)
C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.S=.o)
OBJS = $(C_OBJS) $(S_OBJS)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
\t$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

# Compile .c to .o. Add the source directory as an include root so
# vendor-style includes like <speex/speex.h> resolve locally.
%.o: %.c
\t$(CC) $(CFLAGS) -I$(dir $<) -c -o $@ $<

# Assemble .S to .o
%.o: %.S
\t$(CC) -m32 -c -o $@ $<

# Clean build artifacts
clean:
\trm -f $(TARGET) $(OBJS)

# Count build errors (useful for progress tracking)
check:
\t@echo "Attempting build..."
\t@$(MAKE) all 2>&1 | grep -c "error:" || echo "0 errors"

# List all source files
list:
\t@echo "$(SRCS)" | tr ' ' '\\n'

# Count source files
count:
\t@echo "Source files: $$(echo $(SRCS) | wc -w)"
\t@echo "Object files: $$(find . -name '*.o' | wc -l)"

.PHONY: all clean check list count
'''

        with open(makefile_path, 'w') as f:
            f.write(content)
