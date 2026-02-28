# Auto-generated Makefile for COD2 Linux decompilation
# Build with: make -j$(nproc)

CC = gcc
SDL2_CFLAGS = $(shell pkg-config --cflags sdl2 2>/dev/null || echo -I/usr/include/SDL2)
SDL2_LIBS = $(shell pkg-config --libs sdl2 2>/dev/null || echo -lSDL2)
CFLAGS = -m32 -fno-pie -no-pie -w -O0 -g -I. $(SDL2_CFLAGS)
LDFLAGS = -m32 -no-pie
LIBS = -lGL -lm -lpthread -ldl -lstdc++ $(SDL2_LIBS)
TARGET = cod2_linux

# Find all .c files recursively
SRCS = $(shell find . -name '*.c' | sort)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean build artifacts
clean:
	rm -f $(TARGET) $(OBJS)

# Count build errors (useful for progress tracking)
check:
	@echo "Attempting build..."
	@$(MAKE) all 2>&1 | grep -c "error:" || echo "0 errors"

# List all source files
list:
	@echo "$(SRCS)" | tr ' ' '\n'

# Count source files
count:
	@echo "Source files: $$(echo $(SRCS) | wc -w)"
	@echo "Object files: $$(find . -name '*.o' | wc -l)"

.PHONY: all clean check list count
