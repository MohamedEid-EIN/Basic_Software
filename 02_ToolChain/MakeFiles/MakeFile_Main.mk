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
# File Name   : Makefile_Main.mk
# File Type   : Main Build Entry Point
# Module      : MakeFile
# Layer       : ToolChain
# Description :
#   This is the primary Makefile entry.
#   It connects:
#       - Directory configuration
#       - Toolchain configuration
#       - Policy definitions
#       - Folder initialization
#       - Build orchestration
# Responsibilities :
#   - Include all configuration layers
#   - Define default target
#   - Define clean behavior
#   - Auto-detect sources
#   - Define compilation rules
#   - Define linking rules
# Important :
#   This file coordinates the build system.
#   It does not contain deep configuration logic.
# -----------------------------------------------------------------------------------------------------------
# Version History
# -----------------------------------------------------------------------------------------------------------
# Version | Date       | Author       | Description
# --------|------------|--------------|-------------------------------------------------------------
# 1.00.00 | 2026-02-17 | Mohamed Eid  | Initial toolchain configuration architecture
##################################################################################################################################################################################

###########################################################
# Include Configuration Files
###########################################################
# Absolute directory of the current Makefile (engine root)
ENGINE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Directory structure definitions
include $(ENGINE_DIR)/Cfg/MakeFileDir_Cfg.mk

# Toolchain configuration (compiler, flags, linker)
include $(ENGINE_DIR)/Cfg/MakeFile_Cfg.mk

# Policy layer (warning rules, quality rules, extensions)
include $(ENGINE_DIR)/Include/MakeFilePolicy.mk

# Folder initialization (build & quality directories)
include $(ENGINE_DIR)/Include/BuildFolders.mk
###########################################################
# Auto-detect Sources
###########################################################
# Automatically collect all C source files from registered source directories
C_SOURCES := $(foreach dir,$(ALL_SRC_DIR),$(wildcard $(dir)/*.c))

# Automatically collect all assembly source files
S_SOURCES := $(foreach dir,$(ALL_SRC_DIR),$(wildcard $(dir)/*.s))

###########################################################
# Object Files
###########################################################
# Generate object file list from C and assembly sources
OBJS = \
	$(addprefix $(OBJ_DIR)/,$(notdir $(C_SOURCES:.c=.o))) \
	$(addprefix $(OBJ_DIR)/,$(notdir $(S_SOURCES:.s=.o)))

###########################################################
# Dependency Files
###########################################################
# Generate dependency file list for automatic rebuild tracking
DEPS = $(addprefix $(DEP_DIR)/,$(notdir $(C_SOURCES:.c=.d)))
# Build logging and orchestration
include $(ENGINE_DIR)/Include/BuildLogging.mk

###########################################################
# Default Target
###########################################################
# Default user target
# Running `make` triggers the build lifecycle
.PHONY: all
all: build

###########################################################
# Clean Artifacts
###########################################################
# Removes all temporary build artifacts
.PHONY: clean
clean:
	$(OUTPUT)$(ECHO_PROCESS) "Starting clean process..."
	$(OUTPUT)rm -rvf $(TEMP_DIR)/*
	$(OUTPUT)$(ECHO_FINISHED) "Artifacts files Deleted..."

###########################################################
# Compile C Files
###########################################################
# Rule: compile .c → .o
# Logs compilation output into build log
$(OBJ_DIR)/%.o: %.c
	$(OUTPUT)$(ECHO_COMPILE) "$(notdir $<)"
	@echo "Compiling: $(notdir $<)" >> "$(BUILD_LOG)"
	@$(COMPILER) $(CFLAGS) -c $< -o $@ >> "$(BUILD_LOG)" 2>&1

###########################################################
# Compile Assembly Files
###########################################################
# Rule: assemble .s → .o
# Logs assembly output into build log
$(OBJ_DIR)/%.o: %.s
	$(OUTPUT)$(ECHO_ASSEMBLE) "$(notdir $<)"
	@echo "Assembling: $(notdir $<)" >> "$(BUILD_LOG)"
	@$(ASSMBLER) $(ASFLAGS) -c $< -o $@ >> "$(BUILD_LOG)" 2>&1

###########################################################
# Linking
###########################################################
# Rule: link all objects into final ELF executable
# Produces firmware binary before artifact extraction
$(ELF_DIR)/$(TARGET).elf: $(OBJS)
	$(OUTPUT)$(ECHO_LINK) "$(TARGET).elf"
	@echo "Linking: $(TARGET).elf" >> "$(BUILD_LOG)"
	@$(LINKER) $(OBJS) $(LDFLAGS) -o $@ >> "$(BUILD_LOG)" 2>&1

###########################################################
# Generate Preprocessing Files (.i)
###########################################################
# Rule: generate preprocessed source (.i) from .c
# Useful for debugging macro expansion and includes
$(PRE_DIR)/%.i: %.c | $(PRE_DIR)
	@mkdir -p $(dir $@)
	$(OUTPUT)printf "$(COLOR_BYELLOW)Preprocessing:$(COLOR_RESET) %s\n" "$(notdir $<)"
	@echo "Preprocessing: $(notdir $<)" >> "$(BUILD_LOG)"
	@$(COMPILER) -E $(CFLAGS) $< -o $@ 2>> "$(BUILD_LOG)"

###########################################################
# Generate Assembly Files (.s from .c)
###########################################################
# Rule: generate assembly listing from C source
# Useful for optimization and instruction analysis
$(ASM_DIR)/%.s: %.c | $(ASM_DIR)
	@mkdir -p $(dir $@)
	$(OUTPUT)printf "$(COLOR_BMAGENTA)Assembly:$(COLOR_RESET) %s\n" "$(notdir $<)"
	@echo "Generating assembly: $(notdir $<)" >> "$(BUILD_LOG)"
	@$(COMPILER) -S $(CFLAGS) $< -o $@ 2>> "$(BUILD_LOG)"

###########################################################
# Include Dependencies
###########################################################
# Automatically include generated dependency files
# Ensures proper incremental rebuild behavior
-include $(DEPS)
