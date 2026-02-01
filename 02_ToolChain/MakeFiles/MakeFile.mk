###############################################
# Project configuration
###############################################
TARGET = ProjectBuildFile

# Injected by BuildSystem Makefile
BUILD_ROOT ?= $(error BUILD_ROOT not set)

# Project root is the parent of Build_System
PROJECT_ROOT := $(abspath $(BUILD_ROOT)/..)

SOFTWARE_ROOT := $(PROJECT_ROOT)/06_Software

###############################################
# Verbosity control (quiet by default, errors kept)
###############################################
VERBOSE ?= 0
ifeq ($(VERBOSE),0)
Q := @
else
Q :=
endif

###############################################
# Software directories (CURRENT PROJECT SCOPE)
###############################################

# -------- Application --------
APP_DIR        = $(SOFTWARE_ROOT)/01_Application
APP_SRC_DIR    = $(APP_DIR)/Source

# -------- Libraries (Common / Std_Types) --------
LIB_DIR            = $(SOFTWARE_ROOT)/03_Libraries
COMMON_DIR         = $(LIB_DIR)/Common
STD_TYPES_DIR      = $(COMMON_DIR)/STD_TYPES
STD_TYPES_INC_DIR  = $(STD_TYPES_DIR)/Include
STD_TYPES_CFG_DIR  = $(STD_TYPES_DIR)/Cfg

# -------- MCAL (GPIO only) --------
MCAL_DIR       = $(SOFTWARE_ROOT)/07_MCAL
GPIO_DIR       = $(MCAL_DIR)/GPIO
GPIO_SRC_DIR   = $(GPIO_DIR)/Source
GPIO_HDR_DIR   = $(GPIO_DIR)/Header
GPIO_INC_DIR   = $(GPIO_DIR)/Header/Include
GPIO_CFG_DIR   = $(GPIO_DIR)/Cfg

# -------- Platform (Startup + Linker) --------
PLATFORM_DIR      = $(SOFTWARE_ROOT)/08_Platform
STARTUP_DIR       = $(PLATFORM_DIR)/StartUp_Code

LINKER_DIR        = $(PLATFORM_DIR)/Linker
#LINKER_CFG_DIR    = $(LINKER_DIR)/Cfg

###############################################
# Source directories (auto-scan)
###############################################
SRC_DIRS = \
	$(APP_SRC_DIR) \
	$(GPIO_SRC_DIR) \
	$(STARTUP_DIR)

###############################################
# Include directories (PUBLIC + module Cfg)
###############################################
INC_DIRS = \
	$(APP_INC_DIR) \
	$(STD_TYPES_INC_DIR) \
	$(STD_TYPES_CFG_DIR) \
	$(GPIO_HDR_DIR) \
	$(GPIO_INC_DIR) \
	$(GPIO_CFG_DIR)

###############################################
# Build output directories
###############################################
TEMP_DIR     = Temp
OBJ_DIR      = $(TEMP_DIR)/Obj
PRE_DIR      = $(TEMP_DIR)/Pre
ELF_DIR      = $(TEMP_DIR)/Elf
MAP_DIR      = $(TEMP_DIR)/Map
BIN_DIR      = $(TEMP_DIR)/Bin
DUMP_DIR     = $(TEMP_DIR)/Dump
SYM_DIR      = $(TEMP_DIR)/Sym
SIZE_DIR     = $(TEMP_DIR)/Size

###############################################
# Create output folders
###############################################
$(shell mkdir -p $(OBJ_DIR) $(PRE_DIR) $(ELF_DIR) $(MAP_DIR) \
                 $(BIN_DIR) $(DUMP_DIR) $(SYM_DIR) $(SIZE_DIR))

###############################################
# Allow make to find source files
###############################################
VPATH = $(SRC_DIRS)

###############################################
# Auto-detect all C and ASM sources
###############################################
C_SOURCES = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_SOURCES = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.s))

###############################################
# Convert sources to object names
###############################################
OBJS = \
	$(addprefix $(OBJ_DIR)/, $(notdir $(C_SOURCES:.c=.o))) \
	$(addprefix $(OBJ_DIR)/, $(notdir $(S_SOURCES:.s=.o)))

###############################################
# Tools
###############################################
CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
NM      = arm-none-eabi-nm
SIZE    = arm-none-eabi-size

CPU = -mcpu=cortex-m4 -mthumb

###############################################
# FLAGS
###############################################
CFLAGS  = $(CPU) -O0 -ffreestanding -nostdlib -nostartfiles -g -fno-builtin-memset
ifeq ($(VERBOSE),1)
CFLAGS += -H -v
endif
ASFLAGS = $(CPU) -x assembler-with-cpp -g

###############################################
# Include paths
###############################################
CFLAGS += $(foreach inc,$(INC_DIRS),-I$(inc))

###############################################
# Linker
###############################################
LINKER_SCRIPT = $(LINKER_DIR)/Linker.ld
LDFLAGS = -T $(LINKER_SCRIPT) \
          -L$(LINKER_DIR) \
          -Map=$(MAP_DIR)/$(TARGET).map

###############################################
# Default rule
###############################################
all: $(ELF_DIR)/$(TARGET).elf diagnostics

###############################################
# Generic compilation rules
###############################################
$(OBJ_DIR)/%.o: %.c
	$(Q)$(CC) $(CFLAGS) -c $< -o $@
	$(Q)$(CC) $(CFLAGS) -E $< -o $(PRE_DIR)/$(notdir $*).i
	$(Q)$(CC) $(CFLAGS) -S $< -o $(PRE_DIR)/$(notdir $*).s

$(OBJ_DIR)/%.o: %.s
	$(Q)$(AS) $(ASFLAGS) -c $< -o $@

###############################################
# Linking
###############################################
$(ELF_DIR)/$(TARGET).elf: $(OBJS)
	$(Q)$(LD) $(LDFLAGS) $(OBJS) -o $@

###############################################
# Firmware formats
###############################################
$(BIN_DIR)/%.bin: $(ELF_DIR)/%.elf
	$(Q)$(OBJCOPY) -O binary $< $@

$(BIN_DIR)/%.hex: $(ELF_DIR)/%.elf
	$(Q)$(OBJCOPY) -O ihex $< $@

$(BIN_DIR)/%.srec: $(ELF_DIR)/%.elf
	$(Q)$(OBJCOPY) -O srec $< $@

###############################################
# Debug / inspection outputs
###############################################
$(DUMP_DIR)/%.lst: $(ELF_DIR)/%.elf
	$(Q)$(OBJDUMP) -d -S -x $< > $@

$(SYM_DIR)/%.sym: $(ELF_DIR)/%.elf
	$(Q)$(NM) -n $< > $@

$(SIZE_DIR)/%.size: $(ELF_DIR)/%.elf
	$(Q)$(SIZE) -A $< > $@

$(DUMP_DIR)/%.dump: $(ELF_DIR)/%.elf
	$(Q)$(OBJDUMP) -x $< > $@

$(ELF_DIR)/%.dbg: $(ELF_DIR)/%.elf
	$(Q)$(OBJCOPY) --only-keep-debug $< $@

$(ELF_DIR)/%.stripped.elf: $(ELF_DIR)/%.elf
	$(Q)$(OBJCOPY) --strip-debug $< $@

###############################################
# Diagnostics group
###############################################
diagnostics: \
	$(DUMP_DIR)/$(TARGET).lst \
	$(SYM_DIR)/$(TARGET).sym \
	$(SIZE_DIR)/$(TARGET).size \
	$(DUMP_DIR)/$(TARGET).dump \
	$(ELF_DIR)/$(TARGET).dbg \
	$(ELF_DIR)/$(TARGET).stripped.elf \
	$(BIN_DIR)/$(TARGET).bin \
	$(BIN_DIR)/$(TARGET).hex \
	$(BIN_DIR)/$(TARGET).srec

###############################################
# Cleaning
###############################################
clean:
	rm -rf $(TEMP_DIR)/*
