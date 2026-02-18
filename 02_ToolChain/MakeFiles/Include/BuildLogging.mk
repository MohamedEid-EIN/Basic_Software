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
# File Name   : MakeFile_Build.mk
# File Type   : Build Logging & Orchestration Script
# Module      : MakeFile
# Layer       : ToolChain
# Description :
#   This file controls the build lifecycle.
#   It manages:
#       - Logging initialization
#       - Artifact generation
#       - Preprocessing and assembly extraction
#       - Diagnostic reporting
#       - Build success notification
# Important :
#   - No compiler flags are defined here.
#   - No directory structure is defined here.
#   - This file orchestrates execution only.
# -----------------------------------------------------------------------------------------------------------
# Version History
# -----------------------------------------------------------------------------------------------------------
# Version | Date       | Author       | Description
# --------|------------|--------------|-------------------------------------------------------------
# 1.00.00 | 2026-02-17 | Mohamed Eid  | Initial toolchain configuration architecture
##################################################################################################################################################################################

###########################################################
# Log File Configuration
###########################################################
# Central build log file used during the entire build process
BUILD_LOG := $(LOG_DIR)/$(TARGET).log

###########################################################
# Generate list of preprocessing and assembly files
###########################################################
# Extract only object files from OBJS
C_OBJS := $(filter %.o,$(OBJS))

# Remove startup assembly object (if present)
C_OBJS := $(filter-out %Startup.o,$(C_OBJS))

# Generate corresponding preprocessing (.i) files
PRE_FILES := $(patsubst $(OBJ_DIR)/%.o,$(PRE_DIR)/%.i,$(C_OBJS))

# Generate corresponding assembly (.s) files
ASM_FILES := $(patsubst $(OBJ_DIR)/%.o,$(ASM_DIR)/%.s,$(C_OBJS))

###########################################################
# Artifacts
###########################################################
# All artifacts generated from the final ELF file
ARTIFACTS = \
	$(ELF_DIR)/$(TARGET).elf \
	$(MAP_DIR)/$(TARGET).map \
	$(BIN_DIR)/$(TARGET).bin \
	$(HEX_DIR)/$(TARGET).hex \
	$(SREC_DIR)/$(TARGET).srec \
	$(DUMP_DIR)/$(TARGET).dump \
	$(SYM_DIR)/$(TARGET).sym \
	$(SIZE_DIR)/$(TARGET).size \
	$(DBG_DIR)/$(TARGET).dbg \
	$(LIST_DIR)/$(TARGET).lst

###########################################################
# Build Entry
###########################################################
# Primary build target
.PHONY: build
build: build_start $(ELF_DIR)/$(TARGET).elf diagnostic success

###########################################################
# Build Start
###########################################################
# Initializes log and prints formatted banner
.PHONY: build_start
build_start:
	@mkdir -p $(LOG_DIR)
	@printf "$(COLOR_BCYAN)================ BUILD START ================\n$(COLOR_RESET)"
	@printf "$(COLOR_CYAN)Target  : $(TARGET)\n$(COLOR_RESET)"
	@printf "$(COLOR_CYAN)Date    : %s\n$(COLOR_RESET)" "$$(date)"
	@printf "$(COLOR_BCYAN)=============================================\n$(COLOR_RESET)"
	@echo "================ BUILD START ================" > "$(BUILD_LOG)"
	@echo "Target  : $(TARGET)" >> "$(BUILD_LOG)"
	@echo "Date    : $$(date)" >> "$(BUILD_LOG)"
	@echo "=============================================" >> "$(BUILD_LOG)"
	$(OUTPUT)$(ECHO_PROCESS) "Starting build process..."
	@echo "Process: Starting build process..." >> "$(BUILD_LOG)"

###########################################################
# Preprocessing & Assembly Targets
###########################################################
# Explicit generation of preprocessing files
.PHONY: preprocess
preprocess: $(PRE_FILES)

# Explicit generation of assembly files
.PHONY: assembly
assembly: $(ASM_FILES)

###########################################################
# Diagnostic (Artifact Generation & Reporting)
###########################################################
.PHONY: diagnostic
diagnostic: $(ARTIFACTS) preprocess assembly
	$(OUTPUT)$(ECHO_INFORMATION) "Artifacts generated:"
	@echo "Information: Artifacts generated:" >> "$(BUILD_LOG)"
	@for file in $(notdir $(ARTIFACTS)); do \
		printf "   - %s\n" "$$file"; \
		printf "   - %s\n" "$$file" >> "$(BUILD_LOG)"; \
	done
	@echo "" >> "$(BUILD_LOG)"
	@echo "Preprocessing files:" >> "$(BUILD_LOG)"
	@for file in $(notdir $(PRE_FILES)); do \
		printf "   - %s\n" "$$file"; \
		printf "   - %s\n" "$$file" >> "$(BUILD_LOG)"; \
	done
	@echo "" >> "$(BUILD_LOG)"
	@echo "Assembly files:" >> "$(BUILD_LOG)"
	@for file in $(notdir $(ASM_FILES)); do \
		printf "   - %s\n" "$$file"; \
		printf "   - %s\n" "$$file" >> "$(BUILD_LOG)"; \
	done

###########################################################
# Artifact Rules
###########################################################
# Generate full disassembly listing
$(LIST_DIR)/%.lst: $(ELF_DIR)/%.elf
	@$(DUMP_TOOL) -d -S -x $< > $@ 2>> "$(BUILD_LOG)"

# Generate sorted symbol table
$(SYM_DIR)/%.sym: $(ELF_DIR)/%.elf
	@$(SYMBOL_TOOL) -n $< > $@ 2>> "$(BUILD_LOG)"

# Generate memory size report
$(SIZE_DIR)/%.size: $(ELF_DIR)/%.elf
	@$(SIZE_TOOL) -A $< > $@ 2>> "$(BUILD_LOG)"

# Generate raw ELF dump
$(DUMP_DIR)/%.dump: $(ELF_DIR)/%.elf
	@$(DUMP_TOOL) -x $< > $@ 2>> "$(BUILD_LOG)"

# Extract debug-only symbols
$(DBG_DIR)/%.dbg: $(ELF_DIR)/%.elf
	@$(BIN_TOOL) --only-keep-debug $< $@ 2>> "$(BUILD_LOG)"

# Generate raw binary image
$(BIN_DIR)/%.bin: $(ELF_DIR)/%.elf
	@$(BIN_TOOL) -O binary $< $@ 2>> "$(BUILD_LOG)"

# Generate Intel HEX image
$(HEX_DIR)/%.hex: $(ELF_DIR)/%.elf
	@$(BIN_TOOL) -O ihex $< $@ 2>> "$(BUILD_LOG)"

# Generate Motorola S-Record image
$(SREC_DIR)/%.srec: $(ELF_DIR)/%.elf
	@$(BIN_TOOL) -O srec $< $@ 2>> "$(BUILD_LOG)"

###########################################################
# Success message
###########################################################
.PHONY: success
success:
	$(OUTPUT)$(ECHO_SUCCESS)
	@echo "" >> "$(BUILD_LOG)"
	@echo "================ BUILD SUCCESS ==============" >> "$(BUILD_LOG)"
