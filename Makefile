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
COMPARE_DIR ?= .compare
COMPARE_BINARY ?= toolchain/utils/binary.x86
COMPARE_CC ?= toolchain/toolchains/bin/gcc-4.0.4
COMPARE_NAKED_CC ?= $(NAKED_CC)
COMPARE_LD ?= ld
COMPARE_SYMBOL_MAP = $(COMPARE_DIR)/orig_symbol_map.json
COMPARE_SCRIPT = $(COMPARE_DIR)/cod2_compare.ld
COMPARE_TARGET = $(COMPARE_DIR)/cod2_compare.o
COMPARE_GENERATED_DIR = $(COMPARE_DIR)/generated
COMPARE_REPORT_DIR = $(COMPARE_DIR)/reports
COMPARE_DATA_SRC = $(COMPARE_GENERATED_DIR)/data_compare.S
COMPARE_DATA_REPORT = $(COMPARE_REPORT_DIR)/data_symbol_ownership.tsv
COMPARE_OVERLAP_REPORT = $(COMPARE_REPORT_DIR)/compare_overlap_report.tsv
COMPARE_SIZE_REPORT = $(COMPARE_REPORT_DIR)/compare_size_report.tsv
COMPARE_SPLIT_GEN_DIR = $(COMPARE_GENERATED_DIR)/split_naked
PROJECT_SOURCE_EXCLUDES = -not -path './toolchain/*' -not -path './utils/*' -not -path './toolchains/*' -not -path './.compare*/*'
DATA_INPUT = $(firstword $(wildcard data.c data.c.bak))
COMPARE_FILTERED_C_SRCS = ./bss.c ./rodata.c ./stubs/audio_stubs.c ./stubs/cpp_compat.c ./stubs/link_stubs.c ./stubs/macos_compat.c
# Optional compare-only split path for naked-heavy TUs.
# Example:
#   make COMPARE_SPLIT_NAKED_SRCS=./PC/ui/ui_shared_obj.c compare
#   make COMPARE_DIR=.compare-exp/ui_shared \
#       COMPARE_SPLIT_NAKED_SRCS=./PC/ui/ui_shared_obj.c \
#       compare compare-size-report
COMPARE_SPLIT_NAKED_SRCS ?=

# Find all .c and .S files recursively
C_SRCS = $(shell find . -name '*.c' $(PROJECT_SOURCE_EXCLUDES) | sort)
S_SRCS = $(shell find . -name '*.S' $(PROJECT_SOURCE_EXCLUDES) | sort)
NAKED_C_SRCS = $(shell rg -l '__attribute__\(\(naked\)\)' . -g'*.c' -g'!toolchain/**' -g'!utils/**' -g'!toolchains/**' -g'!.compare*/**' 2>/dev/null || true)
C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.S=.o)
NAKED_OBJS = $(NAKED_C_SRCS:.c=.o)
OBJS = $(C_OBJS) $(S_OBJS)
COMPARE_DIRECT_C_SRCS = $(filter-out $(COMPARE_FILTERED_C_SRCS) $(COMPARE_SPLIT_NAKED_SRCS),$(C_SRCS))
COMPARE_DIRECT_C_OBJS = $(addprefix $(COMPARE_DIR)/obj/,$(COMPARE_DIRECT_C_SRCS:.c=.o))
COMPARE_FILTERED_C_OBJS = $(addprefix $(COMPARE_DIR)/obj/,$(COMPARE_FILTERED_C_SRCS:.c=.o))
COMPARE_RAW_FILTERED_C_OBJS = $(addprefix $(COMPARE_DIR)/raw/,$(COMPARE_FILTERED_C_SRCS:.c=.o))
COMPARE_SPLIT_FINAL_OBJS = $(addprefix $(COMPARE_DIR)/obj/,$(COMPARE_SPLIT_NAKED_SRCS:.c=.o))
COMPARE_SPLIT_NONAKED_SRCS = $(addprefix $(COMPARE_SPLIT_GEN_DIR)/,$(COMPARE_SPLIT_NAKED_SRCS:.c=.nonaked.c))
COMPARE_SPLIT_NAKED_GEN_SRCS = $(addprefix $(COMPARE_SPLIT_GEN_DIR)/,$(COMPARE_SPLIT_NAKED_SRCS:.c=.naked.c))
COMPARE_SPLIT_STAMPS = $(addprefix $(COMPARE_SPLIT_GEN_DIR)/,$(COMPARE_SPLIT_NAKED_SRCS:.c=.split.stamp))
COMPARE_SPLIT_NONAKED_OBJS = $(addprefix $(COMPARE_DIR)/split/nonaked/,$(COMPARE_SPLIT_NAKED_SRCS:.c=.o))
COMPARE_SPLIT_NAKED_HOST_OBJS = $(addprefix $(COMPARE_DIR)/split/naked/,$(COMPARE_SPLIT_NAKED_SRCS:.c=.o))
COMPARE_BASE_S_SRCS = $(filter-out ./data.S,$(S_SRCS))
COMPARE_S_SRCS = $(COMPARE_BASE_S_SRCS) $(COMPARE_DATA_SRC)
COMPARE_BASE_S_OBJS = $(addprefix $(COMPARE_DIR)/obj/,$(COMPARE_BASE_S_SRCS:.S=.o))
COMPARE_S_OBJS = $(addprefix $(COMPARE_DIR)/obj/,$(COMPARE_S_SRCS:.S=.o))
COMPARE_NAKED_COMPARE_SRCS = $(filter-out $(COMPARE_SPLIT_NAKED_SRCS),$(NAKED_C_SRCS))
COMPARE_NAKED_OBJS = $(addprefix $(COMPARE_DIR)/obj/,$(COMPARE_NAKED_COMPARE_SRCS:.c=.o))
COMPARE_NAKED_FUNC_SECTION_OPTOUT_SRCS = \
	./PC/bgame/bg_misc.c \
	./PC/bgame/bg_pmove.c \
	./PC/bgame/bg_weapons.c \
	./PC/botlib/l_precomp.c \
	./PC/botlib/l_script.c \
	./PC/cgame_mp/cg_ents_mp.c \
	./PC/cgame_mp/cg_newDraw_mp.c \
	./PC/cgame_mp/cg_servercmds_mp.c \
	./PC/cgame_mp/cg_view_mp.c \
	./PC/cgame_mp/cg_weapons.c \
	./PC/client_mp/cl_keys_mp.c \
	./PC/game_mp/g_active_mp.c \
	./PC/gfx_d3d/rb_tess.c \
	./PC/script/scr_variable.c \
	./PC/script/scr_vm.c \
	./PC/script/scr_yacc.c \
	./PC/server_mp/sv_main_mp.c
COMPARE_NAKED_FUNC_SECTION_OPTOUT_OBJS = $(addprefix $(COMPARE_DIR)/obj/,$(COMPARE_NAKED_FUNC_SECTION_OPTOUT_SRCS:.c=.o))
COMPARE_C_OBJS = $(COMPARE_DIRECT_C_OBJS) $(COMPARE_FILTERED_C_OBJS) $(COMPARE_SPLIT_FINAL_OBJS)
COMPARE_PROVIDER_OBJS = $(COMPARE_C_OBJS) $(COMPARE_BASE_S_OBJS)
COMPARE_OBJS = $(COMPARE_C_OBJS) $(COMPARE_S_OBJS)
COMPARE_FILTER_BASE_OBJS = $(COMPARE_DIRECT_C_OBJS) $(COMPARE_BASE_S_OBJS)
COMPARE_BSS_PROVIDER_OBJS = $(COMPARE_FILTER_BASE_OBJS)
COMPARE_RODATA_PROVIDER_OBJS = $(COMPARE_FILTER_BASE_OBJS)
COMPARE_MACOS_COMPAT_PROVIDER_OBJS = $(COMPARE_FILTER_BASE_OBJS) $(COMPARE_DIR)/obj/./bss.o $(COMPARE_DIR)/obj/./rodata.o
COMPARE_AUDIO_STUBS_PROVIDER_OBJS = $(COMPARE_MACOS_COMPAT_PROVIDER_OBJS) $(COMPARE_DIR)/obj/./stubs/macos_compat.o
COMPARE_CPP_COMPAT_PROVIDER_OBJS = $(COMPARE_AUDIO_STUBS_PROVIDER_OBJS) $(COMPARE_DIR)/obj/./stubs/audio_stubs.o
COMPARE_LINK_STUBS_PROVIDER_OBJS = $(COMPARE_CPP_COMPAT_PROVIDER_OBJS) $(COMPARE_DIR)/obj/./stubs/cpp_compat.o
COMPARE_CFLAGS = -std=$(CSTD) -m32 -fno-pie -fno-PIC -w -O2 -msse -fno-omit-frame-pointer -fno-strict-aliasing -ffunction-sections -fdata-sections -fno-common -DSDL_DISABLE_IMMINTRIN_H -IPC/speex -I. $(SDL2_CFLAGS)
COMPARE_NAKED_CFLAGS = -std=$(CSTD) -m32 -fno-pie -fno-PIC -w -O2 -msse -fno-omit-frame-pointer -fno-strict-aliasing -ffunction-sections -fdata-sections -fno-common -DSDL_DISABLE_IMMINTRIN_H -IPC/speex -I. $(SDL2_CFLAGS) -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration -Wno-error=implicit-int -Wno-error=int-conversion -Wno-error=return-mismatch
COMPARE_NAKED_CFLAGS_NO_FUNC_SECTIONS = -std=$(CSTD) -m32 -fno-pie -fno-PIC -w -O2 -msse -fno-omit-frame-pointer -fno-strict-aliasing -fdata-sections -fno-common -DSDL_DISABLE_IMMINTRIN_H -IPC/speex -I. $(SDL2_CFLAGS) -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration -Wno-error=implicit-int -Wno-error=int-conversion -Wno-error=return-mismatch
$(COMPARE_NAKED_FUNC_SECTION_OPTOUT_OBJS): COMPARE_NAKED_FILE_CFLAGS = $(COMPARE_NAKED_CFLAGS_NO_FUNC_SECTIONS)

# Default target
all: $(TARGET)

compare: $(COMPARE_TARGET)

compare-report: $(COMPARE_DATA_REPORT)

compare-overlap-report: $(COMPARE_OVERLAP_REPORT)

compare-size-report: $(COMPARE_SIZE_REPORT)

compare-split-experiment:
ifndef SPLIT_SRC
	$(error SPLIT_SRC is required, e.g. make SPLIT_SRC=./PC/client_mp/cl_main_mp.c compare-split-experiment)
endif
	python3 -m utils.decomp.run_compare_experiment $(SPLIT_SRC) --binary $(COMPARE_BINARY)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -Wl,--allow-multiple-definition -Wl,--wrap,FX_TryRegisterEffect -Wl,--wrap,FX_CreateDefaultEffect -Wl,--wrap,FX_RegisterEffect -Wl,--wrap,R_Error -Wl,--defsym,__mh_execute_header=0x1000 -Wl,--defsym,level_ptr=level -Wl,--defsym,g_entities_ptr=g_entities -Wl,--defsym,scr_const_ptr=scr_const -Wl,--defsym,playerCorpseInfo_ptr=g_scr_data -Wl,--defsym,g_renderer_ptr=re -Wl,--defsym,scrAnimPub_ptr=scrAnimPub -Wl,--defsym,scrCompPub_ptr=scrCompilePub -Wl,--defsym,scrParserPub_ptr=scrParserPub -Wl,--defsym,r_frontEndData_ptr=rg -Wl,--defsym,r_sys_ptr=ri -Wl,--defsym,r_limits_ptr=vidConfig -Wl,--defsym,sv_ptr=sv -Wl,--defsym,svs_ptr=svs -Wl,--defsym,cg_globUI=legacyHacks -Wl,--defsym,g_time=imp_level_bgs -Wl,--defsym,g_time_ptr=imp_bgs $(LIBS)

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

$(COMPARE_NAKED_OBJS): $(COMPARE_DIR)/obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPARE_NAKED_CC) $(or $(COMPARE_NAKED_FILE_CFLAGS),$(COMPARE_NAKED_CFLAGS)) -c -o $@ $<

$(COMPARE_DIR)/obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPARE_CC) $(COMPARE_CFLAGS) -c -o $@ $<

$(COMPARE_DIR)/raw/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPARE_CC) $(COMPARE_CFLAGS) -c -o $@ $<

$(COMPARE_DIR)/obj/%.o: %.S
	@mkdir -p $(dir $@)
	$(COMPARE_CC) -m32 -fno-pie -fno-PIC -c -o $@ $<

$(COMPARE_SPLIT_GEN_DIR)/%.split.stamp: %.c toolchain/utils/decomp/split_naked_source.py
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.split_naked_source $< $(COMPARE_SPLIT_GEN_DIR)/$*.nonaked.c $(COMPARE_SPLIT_GEN_DIR)/$*.naked.c
	@touch $@

$(COMPARE_DIR)/split/nonaked/%.o: $(COMPARE_SPLIT_GEN_DIR)/%.split.stamp
	@mkdir -p $(dir $@)
	$(COMPARE_CC) $(COMPARE_CFLAGS) -c -o $@ $(COMPARE_SPLIT_GEN_DIR)/$*.nonaked.c

$(COMPARE_DIR)/split/naked/%.o: $(COMPARE_SPLIT_GEN_DIR)/%.split.stamp
	@mkdir -p $(dir $@)
	$(COMPARE_NAKED_CC) $(or $(COMPARE_NAKED_FILE_CFLAGS),$(COMPARE_NAKED_CFLAGS)) -c -o $@ $(COMPARE_SPLIT_GEN_DIR)/$*.naked.c

$(COMPARE_SPLIT_FINAL_OBJS): $(COMPARE_DIR)/obj/%.o: $(COMPARE_DIR)/split/nonaked/%.o $(COMPARE_DIR)/split/naked/%.o
	@mkdir -p $(dir $@)
	$(COMPARE_LD) -m elf_i386 -r -o $@ $^

$(COMPARE_DIR)/obj/./bss.o: $(COMPARE_DIR)/raw/./bss.o toolchain/utils/decomp/filter_compare_obj.py $(COMPARE_BSS_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.filter_compare_obj $< $@ --providers $(COMPARE_BSS_PROVIDER_OBJS)

$(COMPARE_DIR)/obj/./rodata.o: $(COMPARE_DIR)/raw/./rodata.o toolchain/utils/decomp/filter_compare_obj.py $(COMPARE_RODATA_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.filter_compare_obj $< $@ --providers $(COMPARE_RODATA_PROVIDER_OBJS)

$(COMPARE_DIR)/obj/./stubs/macos_compat.o: $(COMPARE_DIR)/raw/./stubs/macos_compat.o toolchain/utils/decomp/filter_compare_obj.py $(COMPARE_MACOS_COMPAT_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.filter_compare_obj $< $@ --providers $(COMPARE_MACOS_COMPAT_PROVIDER_OBJS)

$(COMPARE_DIR)/obj/./stubs/audio_stubs.o: $(COMPARE_DIR)/raw/./stubs/audio_stubs.o toolchain/utils/decomp/filter_compare_obj.py $(COMPARE_AUDIO_STUBS_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.filter_compare_obj $< $@ --providers $(COMPARE_AUDIO_STUBS_PROVIDER_OBJS)

$(COMPARE_DIR)/obj/./stubs/cpp_compat.o: $(COMPARE_DIR)/raw/./stubs/cpp_compat.o toolchain/utils/decomp/filter_compare_obj.py $(COMPARE_CPP_COMPAT_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.filter_compare_obj $< $@ --providers $(COMPARE_CPP_COMPAT_PROVIDER_OBJS)

$(COMPARE_DIR)/obj/./stubs/link_stubs.o: $(COMPARE_DIR)/raw/./stubs/link_stubs.o toolchain/utils/decomp/filter_compare_obj.py $(COMPARE_LINK_STUBS_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.filter_compare_obj $< $@ --providers $(COMPARE_LINK_STUBS_PROVIDER_OBJS)

$(COMPARE_DATA_SRC): toolchain/utils/fix_data_pointers.py $(DATA_INPUT) strings.c $(COMPARE_BINARY) $(COMPARE_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 toolchain/utils/fix_data_pointers.py --binary $(COMPARE_BINARY) --input $(DATA_INPUT) --output $@ --split-sections --no-rename --skip-defined-in $(COMPARE_PROVIDER_OBJS)

$(COMPARE_DATA_REPORT): toolchain/utils/decomp/data_symbol_ownership.py $(COMPARE_SYMBOL_MAP) $(COMPARE_DATA_SRC) $(COMPARE_PROVIDER_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.data_symbol_ownership $(COMPARE_SYMBOL_MAP) $(COMPARE_DATA_SRC) $@ $(COMPARE_PROVIDER_OBJS)

$(COMPARE_OVERLAP_REPORT): toolchain/utils/decomp/compare_overlap_report.py $(COMPARE_SYMBOL_MAP) $(COMPARE_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.compare_overlap_report $(COMPARE_SYMBOL_MAP) $@ $(COMPARE_OBJS)

$(COMPARE_SIZE_REPORT): toolchain/utils/decomp/compare_size_report.py $(COMPARE_SYMBOL_MAP) $(COMPARE_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.compare_size_report $(COMPARE_SYMBOL_MAP) $@ $(COMPARE_OBJS)

$(COMPARE_SYMBOL_MAP): toolchain/utils/decomp/orig_symbol_map.py $(COMPARE_BINARY)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.orig_symbol_map $(COMPARE_BINARY) $@

$(COMPARE_SCRIPT): toolchain/utils/decomp/compare_linker.py $(COMPARE_SYMBOL_MAP) $(COMPARE_OBJS)
	@mkdir -p $(dir $@)
	python3 -m utils.decomp.compare_linker $(COMPARE_SYMBOL_MAP) $@ $(COMPARE_OBJS)

$(COMPARE_TARGET): $(COMPARE_SCRIPT) $(COMPARE_OBJS)
	$(COMPARE_LD) -m elf_i386 -r -T $(COMPARE_SCRIPT) -o $@ $(COMPARE_OBJS)

# Clean build artifacts
clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(COMPARE_DIR)

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

.PHONY: all clean check list count compare compare-report compare-overlap-report compare-size-report compare-split-experiment
