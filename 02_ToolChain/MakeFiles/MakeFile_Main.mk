##################################################################################################################################################################################
# License     : MIT License
# Copyright (c) 2026 Mohamed Eid
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction...
##################################################################################################################################################################################

###########################################################
# Include Configuration Files
###########################################################
ENGINE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

include $(ENGINE_DIR)/Cfg/MakeFileDir_Cfg.mk
include $(ENGINE_DIR)/Cfg/MakeFile_Cfg.mk
include $(ENGINE_DIR)/Include/MakeFilePolicy.mk
include $(ENGINE_DIR)/Include/BuildFolders.mk

###########################################################
# Auto-detect Sources
###########################################################
C_SOURCES := $(foreach dir,$(ALL_SRC_DIR),$(wildcard $(dir)/*.c))
S_SOURCES := $(foreach dir,$(ALL_SRC_DIR),$(wildcard $(dir)/*.s))

###########################################################
# Object Files
###########################################################
OBJS = \
	$(addprefix $(OBJ_DIR)/,$(notdir $(C_SOURCES:.c=.o))) \
	$(addprefix $(OBJ_DIR)/,$(notdir $(S_SOURCES:.s=.o)))

###########################################################
# Dependency Files
###########################################################
DEPS = $(addprefix $(DEP_DIR)/,$(notdir $(C_SOURCES:.c=.d)))

include $(ENGINE_DIR)/Include/BuildLogging.mk

###########################################################
# Default Target
###########################################################
.PHONY: all
all: build

###########################################################
# Clean Artifacts
###########################################################
.PHONY: clean
clean:
	$(OUTPUT)$(ECHO_PROCESS) "Starting clean process..."
	$(OUTPUT)rm -rvf $(TEMP_DIR)/*
	$(OUTPUT)$(ECHO_FINISHED) "Artifacts files Deleted..."

###########################################################
# Compile C Files
###########################################################
$(OBJ_DIR)/%.o: %.c
	$(OUTPUT)$(ECHO_COMPILE) "$(notdir $<)"
	@$(COMPILER) $(CFLAGS) -c $< -o $@

###########################################################
# Compile Assembly Files
###########################################################
$(OBJ_DIR)/%.o: %.s
	$(OUTPUT)$(ECHO_ASSEMBLE) "$(notdir $<)"
	@$(ASSMBLER) $(ASFLAGS) -c $< -o $@

###########################################################
# Linking
###########################################################
$(ELF_DIR)/$(TARGET).elf: $(OBJS)
	$(OUTPUT)$(ECHO_LINK) "$(TARGET).elf"
	@$(LINKER) $(OBJS) $(LDFLAGS) -o $@

###########################################################
# Generate Preprocessing Files (.i)
###########################################################
$(PRE_DIR)/%.i: %.c | $(PRE_DIR)
	@mkdir -p $(dir $@)
	$(OUTPUT)printf "$(COLOR_BYELLOW)Preprocessing:$(COLOR_RESET) %s\n" "$(notdir $<)"
	@$(COMPILER) -E $(CFLAGS) $< -o $@

###########################################################
# Generate Assembly Files (.s from .c)
###########################################################
$(ASM_DIR)/%.s: %.c | $(ASM_DIR)
	@mkdir -p $(dir $@)
	$(OUTPUT)printf "$(COLOR_BMAGENTA)Assembly:$(COLOR_RESET) %s\n" "$(notdir $<)"
	@$(COMPILER) -S $(CFLAGS) $< -o $@

###########################################################
# Include Dependencies
###########################################################
-include $(DEPS)
