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
# - Author      : Mohamed Eid
# - File Name   : MakeFilePolicy_Cfg.mk
# - File Type   : Build Policy Configuration Script
# - Module      : MakeFile
# - Layer       : Toolchain
# Description:
#     This file defines the centralized build governance model.
#     It controls:
#         • Warning discipline and strictness levels
#         • Optimization and debug configuration
#         • Link-Time Optimization (LTO)
#         • Dead code elimination and section splitting
#         • Stack usage reporting
#         • Coverage and sanitizer instrumentation (host only)
#         • Metadata injection (build timestamp / build ID)
#         • Verbosity and color output
#         • Parallel build behavior
#         • Error handling policy
# Responsibilities:
#     - Define policy-driven compiler flags
#     - Define policy-driven assembler flags
#     - Define policy-driven linker flags
#     - Provide profile-based overrides (dev, release, ci, size, etc.)
# Important:
#     This file does NOT:
#         • Define directory structure
#         • Define build rules
#         • Compile source files
#         • Link firmware directly
#     It strictly governs how the toolchain behaves.
#     All configuration variables use '?=' to allow command-line override.
#
# -----------------------------------------------------------------------------------------------------------
# Version History
# -----------------------------------------------------------------------------------------------------------
# Version | Date       | Author       | Description
# --------|------------|--------------|-------------------------------------------------------------
# 1.00.00 | 2026-02-17 | Mohamed Eid  | Initial policy governance architecture
##################################################################################################################################################################################

# -----------------------------------------------------------------------------------------------------------
# BUILD COMMAND
# -----------------------------------------------------------------------------------------------------------
#
# make
#   → Default development profile (debug enabled, no -Werror)
#
# make BUILD_PROFILE=release
#   → Optimized build (-O2), debug disabled, warnings as errors
#
# make BUILD_PROFILE=ci
#   → Strict CI build, optimized, warnings treated as errors
#
# make BUILD_PROFILE=size
#   → Size optimized (-Os + LTO)
#
# make BUILD_PROFILE=coverage
#   → Coverage instrumentation enabled (host only)
#
# make BUILD_PROFILE=sanitize
#   → Address/Undefined sanitizers enabled (host only)
#
# make WARNINGS_AS_ERROR=1
#   → Convert warnings into errors (-Werror)
#
# make STRICT_MODE=1
#   → Enable maximum compiler discipline
#
# make ENABLE_LTO=1
#   → Enable link-time optimization
#
# make VERBOSE=1
#   → Print full compiler commands
#
# make ENABLE_PARALLEL=1 PARALLEL_JOBS=8
#   → Build in parallel with 8 jobs
# -----------------------------------------------------------------------------------------------------------
# HOW TO USE (Command Line Examples + What They Actually Do)
# -----------------------------------------------------------------------------------------------------------
#
# Default development build:
#     make
#   → Uses BUILD_PROFILE=dev
#   → Debug enabled (-g)
#   → No -Werror
#   → Optimization level O0
#   → Normal warnings enabled
#
# Release build:
#     make BUILD_PROFILE=release
#   → Optimization level O2
#   → Debug disabled
#   → Warnings treated as errors (-Werror)
#   → Link-Time Optimization enabled (if configured)
#
# Strict CI build:
#     make BUILD_PROFILE=ci
#   → Optimized build
#   → Debug disabled
#   → All warnings treated as errors
#   → Strict compiler checks enabled
#   → Intended for automated pipelines
#
# Enable warnings as errors:
#     make WARNINGS_AS_ERROR=1
#   → Adds -Werror
#   → Any compiler warning becomes a build failure
#
# Maximum strict mode:
#     make STRICT_MODE=1
#   → Enables pedantic checks
#   → Adds advanced strict flags
#   → Forces -Werror
#
# Enable Link-Time Optimization:
#     make ENABLE_LTO=1
#   → Adds -flto
#   → Allows cross-file optimization during linking
#   → Can reduce size and improve performance
#
# Size-optimized build:
#     make BUILD_PROFILE=size
#   → Uses -Os
#   → Enables LTO
#   → Focused on reducing flash usage
#
# Coverage build (host only):
#     make BUILD_PROFILE=coverage
#   → Adds --coverage
#   → Generates coverage data (.gcda / .gcno)
#   → Used with gcov/lcov
#
# Sanitizer build (host only):
#     make BUILD_PROFILE=sanitize
#   → Adds -fsanitize=address,undefined
#   → Detects memory errors and undefined behavior
#
# Verbose build:
#     make VERBOSE=1
#   → Prints full compiler commands
#   → Useful for debugging flags
#
# Deep toolchain verbose:
#     make VERBOSE=2
#   → Shows include resolution (-H)
#   → Shows toolchain internal behavior
#
# Disable colored output:
#     make ENABLE_COLOR=0
#   → Removes ANSI color escape sequences
#   → Useful in some CI logs
#
# Parallel build:
#     make ENABLE_PARALLEL=1 PARALLEL_JOBS=8
#   → Enables -j8
#   → Compiles files in parallel
#   → Speeds up large builds
#
# Continue on error (NOT recommended):
#     make CONTINUE_ON_ERROR=1
#   → Build continues even if a compilation step fails
#   → Dangerous, only for diagnostics
#
# -----------------------------------------------------------------------------------------------------------
##################################################################################################################################################################################

###########################################################
# Build Profile
###########################################################
# dev | release | ci | strict | coverage | sanitize | size
BUILD_PROFILE ?= dev


###########################################################
# Verbosity Control
###########################################################
# 0 → Quiet (default)
# 1 → Show compiler commands
# 2 → Deep toolchain verbose (-v -H)
VERBOSE ?= 0

ifeq ($(VERBOSE),0)
OUTPUT := @
else
OUTPUT :=
endif

TOOLCHAIN_VERBOSE_FLAGS :=
ifeq ($(VERBOSE),1)
TOOLCHAIN_VERBOSE_FLAGS += -v
endif
ifeq ($(VERBOSE),2)
TOOLCHAIN_VERBOSE_FLAGS += -v -H
endif


###########################################################
# Warning & Strictness Configuration
###########################################################
ENABLE_WARNINGS      ?= 1
ENABLE_EXTRA_WARN    ?= 1
ENABLE_PEDANTIC      ?= 0
WARNINGS_AS_ERROR    ?= 0
STRICT_MODE          ?= 0

WARNING_FLAGS :=

# Basic warnings (-Wall -Wextra)
ifeq ($(ENABLE_WARNINGS),1)
WARNING_FLAGS += -Wall -Wextra
endif

# Extended warnings for subtle bugs
ifeq ($(ENABLE_EXTRA_WARN),1)
WARNING_FLAGS += -Wshadow -Wundef -Wconversion -Wdouble-promotion
endif

# Enforce ISO C compliance warnings
ifeq ($(ENABLE_PEDANTIC),1)
WARNING_FLAGS += -Wpedantic
endif

# Treat warnings as errors
ifeq ($(WARNINGS_AS_ERROR),1)
WARNING_FLAGS += -Werror
endif

# Maximum strict compiler discipline
ifeq ($(STRICT_MODE),1)
WARNING_FLAGS += -Werror -Wpedantic -Wcast-align -Wformat=2 -Wstrict-prototypes
endif


###########################################################
# Optimization & Debug Configuration
###########################################################
ENABLE_DEBUG   ?= 1
OPT_LEVEL      ?= 0
ENABLE_LTO     ?= 0
ENABLE_SIZE_OPT ?= 0

DEBUG_FLAGS :=
ifeq ($(ENABLE_DEBUG),1)
DEBUG_FLAGS += -g
endif

OPT_FLAGS := -O$(OPT_LEVEL)

ifeq ($(ENABLE_SIZE_OPT),1)
OPT_FLAGS := -Os
endif

LTO_FLAGS :=
ifeq ($(ENABLE_LTO),1)
LTO_FLAGS += -flto
endif


###########################################################
# Section Splitting (Dead Code Removal Support)
###########################################################
ENABLE_SECTION_SPLIT ?= 1

SECTION_FLAGS :=
ifeq ($(ENABLE_SECTION_SPLIT),1)
SECTION_FLAGS += -ffunction-sections -fdata-sections
endif


###########################################################
# Linker Garbage Collection
###########################################################
ENABLE_GC_SECTIONS ?= 1

GC_FLAGS :=
ifeq ($(ENABLE_GC_SECTIONS),1)
GC_FLAGS += --gc-sections
endif


###########################################################
# Stack Usage Reporting
###########################################################
ENABLE_STACK_USAGE ?= 0

STACK_FLAGS :=
ifeq ($(ENABLE_STACK_USAGE),1)
STACK_FLAGS += -fstack-usage
endif


###########################################################
# Coverage (Host Builds Only)
###########################################################
ENABLE_COVERAGE ?= 0

COVERAGE_FLAGS :=
ifeq ($(ENABLE_COVERAGE),1)
COVERAGE_FLAGS += --coverage
endif


###########################################################
# Sanitizer (Host Builds Only)
###########################################################
ENABLE_SANITIZER ?= 0

SANITIZER_FLAGS :=
ifeq ($(ENABLE_SANITIZER),1)
SANITIZER_FLAGS += -fsanitize=address -fsanitize=undefined
endif


###########################################################
# Build Metadata Injection
###########################################################
ENABLE_BUILD_TIMESTAMP ?= 1
ENABLE_BUILD_ID        ?= 0

BUILD_META_FLAGS :=

ifeq ($(ENABLE_BUILD_TIMESTAMP),1)
BUILD_META_FLAGS += -DBUILD_TIMESTAMP=\"$(shell date +%Y-%m-%d_%H:%M:%S)\"
endif

ifeq ($(ENABLE_BUILD_ID),1)
BUILD_META_FLAGS += -DBUILD_ID=\"$(shell git rev-parse --short HEAD 2>/dev/null)\"
endif


###########################################################
# Parallel Build Configuration
###########################################################
ENABLE_PARALLEL ?= 0
PARALLEL_JOBS   ?= 4

ifeq ($(ENABLE_PARALLEL),1)
MAKEFLAGS += -j$(PARALLEL_JOBS)
endif


###########################################################
# Error Handling
###########################################################
CONTINUE_ON_ERROR ?= 0

ifeq ($(CONTINUE_ON_ERROR),1)
ERROR_PREFIX := -
else
ERROR_PREFIX :=
endif

###########################################################
# Color Output Configuration
###########################################################
ENABLE_COLOR ?= 1
DIAG_FLAGS :=
DIAG_FLAGS += -fdiagnostics-color=always
DIAG_FLAGS += -fdiagnostics-show-option
DIAG_FLAGS += -fmessage-length=0
DIAG_FLAGS += -fmacro-prefix-map=$(abspath $(PROJECT_ROOT))=.
DIAG_FLAGS += -fdebug-prefix-map=$(abspath $(PROJECT_ROOT))=.

ifeq ($(ENABLE_COLOR),1)

# =========================================================
# ANSI BASE STYLES
# =========================================================
COLOR_RESET   := \033[0m
COLOR_BOLD    := \033[1m
COLOR_DIM     := \033[2m

# =========================================================
# STANDARD COLORS
# =========================================================
COLOR_RED     := \033[0;31m
COLOR_GREEN   := \033[0;32m
COLOR_YELLOW  := \033[0;33m
COLOR_BLUE    := \033[0;34m
COLOR_MAGENTA := \033[0;35m
COLOR_CYAN    := \033[0;36m
COLOR_GRAY    := \033[0;90m

# =========================================================
# BRIGHT / EMPHASIZED COLORS
# =========================================================
COLOR_BRED     := \033[1;31m
COLOR_BGREEN   := \033[1;32m
COLOR_BYELLOW  := \033[1;33m
COLOR_BBLUE    := \033[1;34m
COLOR_BMAGENTA := \033[1;35m
COLOR_BCYAN    := \033[1;36m
COLOR_BWHITE   := \033[1;37m

# =========================================================
# STAGE OUTPUT (Semantic Mapping) - FIXED: Only one %s per line
# =========================================================
ECHO_CC    = printf "$(COLOR_GREEN)[CC]$(COLOR_RESET) %s\n"
ECHO_AS    = printf "$(COLOR_BLUE)[AS]$(COLOR_RESET) %s\n"
ECHO_LD    = printf "$(COLOR_CYAN)[LD]$(COLOR_RESET) %s\n"
ECHO_BIN   = printf "$(COLOR_BYELLOW)[BIN]$(COLOR_RESET) %s\n"
ECHO_CFG   = printf "$(COLOR_MAGENTA)[CFG]$(COLOR_RESET) %s\n"
ECHO_INFO  = printf "$(COLOR_GRAY)[INFO]$(COLOR_RESET) %s\n"

ECHO_COMPILE     = printf "$(COLOR_GREEN)Compiling:$(COLOR_RESET) %s\n"
ECHO_ASSEMBLE    = printf "$(COLOR_BLUE)Assembling:$(COLOR_RESET) %s\n"
ECHO_LINK        = printf "$(COLOR_CYAN)Linking:$(COLOR_RESET) %s\n"
ECHO_GENERATE    = printf "$(COLOR_BYELLOW)Generating:$(COLOR_RESET) %s\n"
ECHO_BUILD_START = printf "$(COLOR_MAGENTA)Building: $(TARGET)...$(COLOR_RESET)\n"
ECHO_INFORMATION = printf "$(COLOR_BYELLOW)Information:$(COLOR_RESET) %s\n"
ECHO_PROCESS     = printf "$(COLOR_MAGENTA)Process:$(COLOR_RESET) %s\n"
ECHO_FINISHED    = printf "$(COLOR_GREEN)Success:$(COLOR_RESET) %s\n"

# =========================================================
# STATUS OUTPUT
# =========================================================
ECHO_OK    = printf "$(COLOR_BGREEN)%s$(COLOR_RESET)\n"
ECHO_WARN  = printf "$(COLOR_BYELLOW)%s$(COLOR_RESET)\n"
ECHO_ERR   = printf "$(COLOR_BRED)%s$(COLOR_RESET)\n"

# =========================================================
# BANNERS
# =========================================================
ECHO_SUCCESS     = printf "$(COLOR_BGREEN)\n=============================================\n BUILD SUCCESSFUL\n=============================================\n$(COLOR_RESET)"
ECHO_FAILURE     = printf "$(COLOR_BRED)\n=============================================\n BUILD FAILED\n=============================================\n$(COLOR_RESET)"
ECHO_CLEAN       = printf "$(COLOR_CYAN)\n Delete Artifacts files.....\n$(COLOR_RESET)"
ECHO_CLEAN_LOG   = printf "$(COLOR_CYAN)\n Delete Log file.....\n$(COLOR_RESET)"

else

# =========================================================
# NO COLOR MODE (CI / Plain Logs)
# =========================================================
COLOR_RESET :=

ECHO_CC    = printf "[CC] %s\n"
ECHO_AS    = printf "[AS] %s\n"
ECHO_LD    = printf "[LD] %s\n"
ECHO_BIN   = printf "[BIN] %s\n"
ECHO_CFG   = printf "[CFG] %s\n"
ECHO_INFO  = printf "[INFO] %s\n"

ECHO_COMPILE     = printf "Compiling: %s\n"
ECHO_ASSEMBLE    = printf "Assembling: %s\n"
ECHO_LINK        = printf "Linking: %s\n"
ECHO_GENERATE    = printf "Generating: %s\n"
ECHO_BUILD_START = printf "Building: $(TARGET)...\n"
ECHO_INFORMATION = printf "Information: %s\n"
ECHO_PROCESS     = printf "Process: %s\n"
ECHO_FINISHED    = printf "Success: %s\n"

ECHO_OK    = printf "%s\n"
ECHO_WARN  = printf "%s\n"
ECHO_ERR   = printf "%s\n"

ECHO_SUCCESS = printf "\n=============================================\n BUILD SUCCESSFUL\n=============================================\n"
ECHO_FAILURE = printf "\n=============================================\n BUILD FAILED\n=============================================\n"

endif


###########################################################
# Profile Overrides
###########################################################
ifeq ($(BUILD_PROFILE),release)
OPT_LEVEL         := 2
ENABLE_DEBUG      := 0
WARNINGS_AS_ERROR := 1
ENABLE_LTO        := 1
endif

ifeq ($(BUILD_PROFILE),ci)
OPT_LEVEL         := 2
ENABLE_DEBUG      := 0
WARNINGS_AS_ERROR := 1
STRICT_MODE       := 1
ENABLE_PEDANTIC   := 1
ENABLE_LTO        := 1
endif

ifeq ($(BUILD_PROFILE),coverage)
ENABLE_COVERAGE := 1
ENABLE_DEBUG    := 1
OPT_LEVEL       := 0
endif

ifeq ($(BUILD_PROFILE),sanitize)
ENABLE_SANITIZER := 1
ENABLE_DEBUG     := 1
OPT_LEVEL        := 0
endif

ifeq ($(BUILD_PROFILE),size)
ENABLE_SIZE_OPT := 1
ENABLE_LTO      := 1
endif


###########################################################
# Final Aggregated Policy Flags
###########################################################
POLICY_CFLAGS  := $(WARNING_FLAGS) $(DEBUG_FLAGS) $(OPT_FLAGS) \
                  $(LTO_FLAGS) $(SECTION_FLAGS) $(DIAG_FLAGS)\
                  $(STACK_FLAGS) $(COVERAGE_FLAGS) \
                  $(SANITIZER_FLAGS) $(BUILD_META_FLAGS) \
                  $(TOOLCHAIN_VERBOSE_FLAGS)

POLICY_ASFLAGS := $(DEBUG_FLAGS) $(LTO_FLAGS) $(TOOLCHAIN_VERBOSE_FLAGS)

POLICY_LDFLAGS := $(LTO_FLAGS) $(GC_FLAGS) \
                  $(COVERAGE_FLAGS) $(SANITIZER_FLAGS) \
                  $(TOOLCHAIN_VERBOSE_FLAGS)
