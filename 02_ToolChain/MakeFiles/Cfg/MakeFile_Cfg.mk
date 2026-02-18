##################################################################################################################################################################################
# License     : MIT License
# Copyright (c) 2026 Mohamed Eid
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# -----------------------------------------------------------------------------------------------------------
# - Author             : Mohamed Eid
# - File Name          : MakeFile_Cfg.mk
# - File Type          : Build Configuration Script
# - Module             : MakeFile
# - Layer              : Toolchain
# - Description        :
#     This file defines the COMPLETE toolchain configuration for the project.
#     It centralizes:
#         • Target name
#         • Toolchain selection
#         • CPU architecture definition
#         • Compiler flags
#         • Assembler flags
#         • Linker flags
#         • Policy-based flag injection
# - Responsibilities   :
#         • Define how the firmware is built
#         • Define how objects are compiled
#         • Define how binaries are generated
#         • Define how memory is linked
# - This file contains :
#         • NO build rules
#         • NO recipes
#         • NO compilation commands
#         • NO directory structure definitions
#         • ONLY configuration variables and flag definitions
#         • Rules are defined elsewhere.
#         • This file only defines behavior.
# -----------------------------------------------------------------------------------------------------------
# Version History
# -----------------------------------------------------------------------------------------------------------
# Version | Date       | Author       | Description
# --------|------------|--------------|-------------------------------------------------------------
# 1.00.00 | 2026-02-17 | Mohamed Eid  | Initial toolchain configuration architecture
##################################################################################################################################################################################

#####################################################################
# Final firmware name (without extension).
# Produces:
#   $(TARGET).elf
#   $(TARGET).bin
#   $(TARGET).map
#   etc.
#####################################################################
TARGET       = ProjectBuildFile

#####################################################################
# Defines the target ARM core architecture.
# This instructs the compiler to generate Cortex-M4 instructions.
#####################################################################
CPU          = -mcpu=cortex-m4

#####################################################################
# Forces generation of Thumb instruction set (required for Cortex-M).
#####################################################################
MODE         = -mthumb

#####################################################################
# C compiler used for .c files.
#####################################################################
COMPILER     = arm-none-eabi-gcc

#####################################################################
# Assembler frontend (GCC used to preprocess .s files).
#####################################################################
ASSMBLER     = arm-none-eabi-gcc

#####################################################################
# Low-level linker used to combine object files.
#####################################################################
LINKER       = arm-none-eabi-ld

#####################################################################
# Converts ELF to binary / hex / srec.
#####################################################################
BIN_TOOL     = arm-none-eabi-objcopy

#####################################################################
# Generates disassembly and inspection output.
#####################################################################
DUMP_TOOL    = arm-none-eabi-objdump

#####################################################################
# Lists symbol table from ELF.
#####################################################################
SYMBOL_TOOL  = arm-none-eabi-nm

#####################################################################
# Prints memory usage (FLASH / RAM).
#####################################################################
SIZE_TOOL    = arm-none-eabi-size

#####################################################################
# Optimization level.
#####################################################################
OPTIMIZATION = -O0

#####################################################################
# COMPILER FLAGS
######################################################################
# The following flags apply ONLY to the C compiler stage.
# They control:
#   - Optimization
#   - Debug information
#   - Code generation
#   - Warning behavior
#   - Section placement
#   - Safety features
#   - Architecture selection
#
# ---------------- LANGUAGE STANDARD ----------------
# -std=c89            → ANSI C
# -std=c99            → C99 standard
# -std=c11            → C11 standard
# -std=gnu99          → GNU C99 extensions
# -std=gnu11          → GNU C11 extensions
#
# ---------------- OPTIMIZATION LEVELS ----------------
# -O0     → No optimization (best for debugging)
# -O1     → Basic optimization
# -O2     → Balanced optimization (recommended release)
# -O3     → Aggressive optimization
# -Os     → Optimize for size
# -Ofast  → Maximum performance, breaks strict compliance
#
# Fine control:
# -finline-functions      → Enable aggressive inlining
# -fno-inline             → Disable inlining
# -funroll-loops          → Unroll loops
# -fno-unroll-loops       → Disable loop unrolling
# -frename-registers      → Improve register allocation
#
# ---------------- DEBUG INFORMATION ----------------
# -g      → Generate debug symbols
# -g0     → Disable debug symbols
# -g1     → Minimal debug info
# -g2     → Default debug info
# -g3     → Maximum debug info
# -ggdb   → GDB specific debug format
#
# ---------------- FREESTANDING / BARE-METAL ----------------
# -ffreestanding      → No hosted assumptions (bare-metal)
# -fno-builtin        → Disable builtin libc optimizations
# -nostdlib           → Do not link standard C library
# -nostartfiles       → Do not link default startup files
#
# ---------------- SECTION CONTROL (for linker GC) ----------------
# -ffunction-sections → Each function in its own section
# -fdata-sections     → Each variable in its own section
#
# ---------------- WARNING CONTROL ----------------
# -Wall               → Enable common warnings
# -Wextra             → Enable extra warnings
# -Wshadow            → Warn about variable shadowing
# -Wundef             → Warn if undefined macro used in #if
# -Wconversion        → Warn on implicit type conversions
# -Wdouble-promotion  → Warn on float → double promotions
# -Wformat=2          → Strict format string checks
# -Wstrict-prototypes → Warn if function has no prototype
# -Wmissing-prototypes→ Warn if global function lacks prototype
# -Wcast-align        → Warn on alignment changes
# -Wpointer-arith     → Warn on pointer arithmetic issues
# -Wswitch-enum       → Warn if enum values not handled
# -Wpedantic          → Strict ISO compliance warnings
# -Werror             → Treat warnings as errors
#
# Disable specific warnings:
# -Wno-unused-variable
# -Wno-shadow
# -Wno-conversion
#
# ---------------- DEPENDENCY GENERATION ----------------
# -MMD → Generate dependency file (.d)
# -MP  → Add phony targets
# -MF  → Specify dependency output file
#
# ---------------- SAFETY FEATURES ----------------
# -fstack-usage            → Generate stack usage report
# -fstack-protector        → Basic stack overflow protection
# -fstack-protector-strong → Stronger stack protection
# -fstack-check            → Runtime stack checking
# -fno-strict-aliasing     → Disable strict alias optimizations
#
# ---------------- PERFORMANCE / SIZE ----------------
# -fomit-frame-pointer → Remove frame pointer
# -flto                → Link-Time Optimization
# -fvisibility=hidden  → Hide symbols by default
#
# ---------------- COVERAGE / PROFILING ----------------
# -fprofile-arcs   → Enable profiling instrumentation
# -ftest-coverage  → Generate coverage data
# --coverage       → Shorthand for coverage
#
# ---------------- ARCHITECTURE ----------------
# -mcpu=cortex-m0/m3/m4/m7 → Target specific ARM core
# -mthumb                  → Use Thumb instruction set
# -mfpu=fpv4-sp-d16        → Select FPU
# -mfloat-abi=hard         → Hardware floating point
# -mfloat-abi=softfp       → Software/hybrid floating point
#
#####################################################################
# Inject architecture selection.
CFLAGS  = $(CPU)

# Inject Thumb mode.
CFLAGS += $(MODE)

# Inject optimization profile.
CFLAGS += $(OPTIMIZATION)

# Indicates bare-metal environment (no hosted assumptions).
CFLAGS += -ffreestanding

# Do not link standard C library.
CFLAGS += -nostdlib

# Do not link default CRT startup files.
CFLAGS += -nostartfiles

# Generate debug symbols.
CFLAGS += -g

# Prevent GCC from replacing memset with builtin variant.
CFLAGS += -fno-builtin-memset

# Enable dependency generation for incremental builds.
CFLAGS += -MMD -MP

# Output dependency file to dependency directory.
CFLAGS += -MF $(DEP_DIR)/$*.d

# Allows injection of additional flags from external policy layer.
CFLAGS += $(POLICY_CFLAGS)

# Automatically include all registered include directories.
CFLAGS += $(foreach inc,$(ALL_INC_DIRS),-I$(inc))

#####################################################################
# ASSEMBLER FLAGS
#####################################################################
#
# These flags apply ONLY to the assembler stage.
#
# -x assembler-with-cpp → Enable C preprocessor inside .s files
# -g                    → Generate debug symbols for assembly
# -mcpu=...             → Target CPU architecture
# -mthumb               → Thumb instruction set
#
# Diagnostics:
# -Wa,-adhln            → Generate mixed source/assembly listing
# -Wa,--fatal-warnings  → Treat assembler warnings as errors
#
#####################################################################
# Target architecture for assembler.
ASFLAGS  = $(CPU)

# Thumb mode for assembly.
ASFLAGS += $(MODE)

# Enable C preprocessor inside .s files.
ASFLAGS += -x assembler-with-cpp

# Generate debug symbols for assembly.
ASFLAGS += -g

# Policy-driven assembler extensions.
ASFLAGS += $(POLICY_ASFLAGS)



#####################################################################
# LINKER FLAGS
#####################################################################
# These flags apply ONLY during linking stage.
# They control:
#   - Memory layout
#   - Section placement
#   - Dead code elimination
#   - Map file generation
#   - Symbol stripping
#
# ---------------- LINKER SCRIPT ----------------
# -T linker.ld → Use custom linker script
#
# ---------------- LIBRARY SEARCH PATH ----------------
# -L path → Add library search path
#
# ---------------- MAP FILE ----------------
# -Map=output.map → Generate memory map file
#
# ---------------- GARBAGE COLLECTION ----------------
# --gc-sections        → Remove unused sections
# --print-gc-sections  → Show removed sections
# --no-gc-sections     → Disable garbage collection
#
# ---------------- MEMORY DIAGNOSTICS ----------------
# --print-memory-usage → Show FLASH/RAM usage
# --cref               → Generate cross reference table
#
# ---------------- STRIPPING ----------------
# -s               → Strip symbols
# --strip-debug    → Remove debug info
# --strip-all      → Remove all symbols
#
# ---------------- ENTRY POINT ----------------
# --entry=Reset_Handler → Define firmware entry symbol
#
# ---------------- FORCE SYMBOL ----------------
# --undefined=symbol → Force inclusion of symbol
#
# ---------------- ADVANCED LINKER OPTIONS ----------------
# --wrap=symbol         → Replace symbol with wrapper
# --relax               → Optimize instruction relaxation
# --sort-common         → Sort common symbols
# --section-start=...   → Force section address
# --defsym=symbol=value → Define symbol at link time
#
#####################################################################
# Path to linker script defining memory layout.
LINKER_SCRIPT := $(LINKER_DIR)/Linker.ld

# Tell linker which memory script to use.
LDFLAGS  = -T $(LINKER_SCRIPT)

# Add linker directory to library search path.
LDFLAGS += -L$(LINKER_DIR)

# Generate memory map file for analysis.
LDFLAGS += -Map=$(MAP_DIR)/$(TARGET).map

# Policy-driven linker extensions (GC, memory usage, etc.)
LDFLAGS += $(POLICY_LDFLAGS)
