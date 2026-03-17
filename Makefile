# Auto-generated Makefile for COD2 Linux decompilation
# Build with: make -j$(nproc)

CC ?= gcc
NAKED_CC ?= gcc
CSTD ?= gnu99
LIBSTDCPP ?= /usr/lib32/libstdc++.so.6
SDL2_CFLAGS = $(shell pkg-config --cflags sdl2 2>/dev/null || echo -I/usr/include/SDL2)
SDL2_LIBS = $(shell pkg-config --libs sdl2 2>/dev/null || echo -lSDL2)
CFLAGS = -std=$(CSTD) -m32 -fno-pie -no-pie -w -O0 -g -msse -fno-omit-frame-pointer -DSDL_DISABLE_IMMINTRIN_H -IPC/speex -I. $(SDL2_CFLAGS) -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration -Wno-error=implicit-int -Wno-error=int-conversion -Wno-error=return-mismatch
LDFLAGS = -m32 -no-pie -L/usr/lib32 -L/usr/lib/i386-linux-gnu
LIBS = -lGL -lm -lpthread -ldl $(LIBSTDCPP) $(SDL2_LIBS)
TARGET = cod2_linux

# Find all .c and .S files recursively
C_SRCS = $(shell find . -name '*.c' | sort)
S_SRCS = $(shell find . -name '*.S' | sort)
NAKED_C_SRCS = $(shell rg -l '__attribute__\(\(naked\)\)' . -g'*.c' 2>/dev/null || true)
C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.S=.o)
NAKED_OBJS = $(NAKED_C_SRCS:.c=.o)
OBJS = $(C_OBJS) $(S_OBJS)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -Wl,--allow-multiple-definition -Wl,--defsym,__mh_execute_header=0x1000 -Wl,--defsym,level_ptr=level -Wl,--defsym,g_entities_ptr=g_entities -Wl,--defsym,scr_const_ptr=scr_const -Wl,--defsym,playerCorpseInfo_ptr=g_scr_data -Wl,--defsym,g_renderer_ptr=re -Wl,--defsym,scrAnimPub_ptr=scrAnimPub -Wl,--defsym,scrCompPub_ptr=scrCompilePub -Wl,--defsym,scrParserPub_ptr=scrParserPub -Wl,--defsym,r_frontEndData_ptr=rg -Wl,--defsym,r_sys_ptr=ri -Wl,--defsym,r_limits_ptr=vidConfig -Wl,--defsym,sv_ptr=sv -Wl,--defsym,svs_ptr=svs -Wl,--defsym,cg_globUI=legacyHacks -Wl,--defsym,g_time=imp_level_bgs -Wl,--defsym,g_time_ptr=imp_bgs $(LIBS)

# Old GCC 4.0 mishandles x86 __attribute__((naked)) functions and emits a
# normal prologue, so build those translation units with the host GCC instead.
$(NAKED_OBJS): %.o: %.c
	$(NAKED_CC) $(CFLAGS) -c -o $@ $<

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Assemble .S to .o
%.o: %.S
	$(CC) -m32 -c -o $@ $<

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
