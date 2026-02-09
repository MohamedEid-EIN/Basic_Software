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
# Verbosity control (quiet by default)
###############################################
VERBOSE ?= 0
ifeq ($(VERBOSE),0)
Q := @
else
Q :=
endif

###############################################
# Pretty build messages
###############################################
ifeq ($(VERBOSE),0)

define PRINT_PP
	@echo " [PP ] Preprocessing $<"
endef

define PRINT_ASM_GEN
	@echo " [ASM] Generating    $< -> .s"
endef

define PRINT_CC
	@echo " [CC ] Compiling     $<"
endef

define PRINT_AS
	@echo " [AS ] Assembling    $<"
endef

define PRINT_LD
	@echo " [LD ] Linking       $(TARGET).elf"
endef

define PRINT_CLEAN
	@echo " [CLN] Removing build artifacts:"
endef

define PRINT_RM
	@echo "      - $1"
endef

else
define PRINT_PP
endef
define PRINT_ASM_GEN
endef
define PRINT_CC
endef
define PRINT_AS
endef
define PRINT_LD
endef
define PRINT_CLEAN
endef
define PRINT_RM
endef
endif

###############################################
# Software directories
###############################################

# -------- Application --------
APP_DIR        = $(SOFTWARE_ROOT)/01_Application
APP_SRC_DIR    = $(APP_DIR)/Source

# ------------ Libraries ----------------
LIB_DIR            = $(SOFTWARE_ROOT)/03_Libraries
UTILS_DIR          = $(LIB_DIR)/UTILS
UTILS_INC_DIR      = $(UTILS_DIR)/Include
STD_TYPES_DIR      = $(LIB_DIR)/STD_TYPES
STD_TYPES_INC_DIR  = $(STD_TYPES_DIR)/Include
STD_TYPES_CFG_DIR  = $(STD_TYPES_DIR)/Cfg

# ------------ HAL CHLCD ----------------
HAL_DIR             = $(SOFTWARE_ROOT)/07_HAL
CHLCD_DIR           = $(HAL_DIR)/CHLCD
CHLCD_SRC_DIR       = $(CHLCD_DIR)/Source
CHLCD_HDR_DIR       = $(CHLCD_DIR)/Header
CHLCD_INC_DIR       = $(CHLCD_DIR)/Header/Include
CHLCD_CFG_DIR       = $(CHLCD_DIR)/Cfg

# ----------- Interfaces -----------
INTERFACES_DIR = $(SOFTWARE_ROOT)/02_Interfaces

# -------- MCAL (GPIO only) --------
MCAL_DIR           = $(SOFTWARE_ROOT)/08_MCAL
GPIO_DIR           = $(MCAL_DIR)/GPIO
GPIO_HDR_DIR       = $(GPIO_DIR)/Header
GPIO_INC_DIR       = $(GPIO_DIR)/Header/Include
GPIO_SRC_DIR       = $(GPIO_DIR)/Source
GPIO_CFG_DIR       = $(GPIO_DIR)/Cfg/Header
GPIO_CFG_SRC_DIR   = $(GPIO_DIR)/Cfg/Source

# -------- Platform --------
PLATFORM_DIR    = $(SOFTWARE_ROOT)/09_Platform
CLOCK_DIR       = $(PLATFORM_DIR)/CLOCK
CLOCK_SRC_DIR   = $(CLOCK_DIR)/Source
CLOCK_HDR_DIR   = $(CLOCK_DIR)/Header
CLOCK_INC_DIR   = $(CLOCK_DIR)/Header/Include
CLOCK_CFG_DIR   = $(CLOCK_DIR)/Cfg
STARTUP_DIR     = $(PLATFORM_DIR)/StartUp_Code

LINKER_DIR      = $(PLATFORM_DIR)/Linker

###############################################
# Source directories
###############################################
SRC_DIRS = \
	$(APP_SRC_DIR) \
	$(GPIO_SRC_DIR) \
	$(GPIO_CFG_SRC_DIR) \
	$(CLOCK_SRC_DIR) \
    $(CHLCD_SRC_DIR) \
	$(STARTUP_DIR)

###############################################
# Include directories (UNCHANGED)
###############################################
INC_DIRS = \
	$(INTERFACES_DIR) \
	$(UTILS_INC_DIR) \
	$(STD_TYPES_INC_DIR) \
	$(STD_TYPES_CFG_DIR) \
	$(GPIO_HDR_DIR) \
	$(GPIO_INC_DIR) \
	$(GPIO_CFG_DIR) \
	$(CHLCD_HDR_DIR) \
	$(CHLCD_INC_DIR) \
	$(CHLCD_CFG_DIR) \
	$(CLOCK_HDR_DIR) \
	$(CLOCK_INC_DIR) \
	$(CLOCK_CFG_DIR)

###############################################
# Build output directories
###############################################
TEMP_DIR     = Temp
OBJ_DIR      = $(TEMP_DIR)/Obj
PRE_DIR      = $(TEMP_DIR)/Pre
DEP_DIR      = $(TEMP_DIR)/Dep
ELF_DIR      = $(TEMP_DIR)/Elf
MAP_DIR      = $(TEMP_DIR)/Map
BIN_DIR      = $(TEMP_DIR)/Bin
DUMP_DIR     = $(TEMP_DIR)/Dump
SYM_DIR      = $(TEMP_DIR)/Sym
SIZE_DIR     = $(TEMP_DIR)/Size

###############################################
# Create output folders
###############################################
$(shell mkdir -p $(OBJ_DIR) $(PRE_DIR) $(DEP_DIR) $(ELF_DIR) $(MAP_DIR) \
                 $(BIN_DIR) $(DUMP_DIR) $(SYM_DIR) $(SIZE_DIR))

###############################################
# Allow make to find source files
###############################################
VPATH = $(SRC_DIRS)

###############################################
# Auto-detect sources
###############################################
C_SOURCES = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_SOURCES = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.s))

###############################################
# Object files
###############################################
OBJS = \
	$(addprefix $(OBJ_DIR)/,$(notdir $(C_SOURCES:.c=.o))) \
	$(addprefix $(OBJ_DIR)/,$(notdir $(S_SOURCES:.s=.o)))

###############################################
# Dependency files
###############################################
DEPS = $(addprefix $(DEP_DIR)/,$(notdir $(C_SOURCES:.c=.d)))

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
# Flags
###############################################
CFLAGS  = $(CPU) -O0 -ffreestanding -nostdlib -nostartfiles -g -fno-builtin-memset
CFLAGS += -MMD -MP -MF $(DEP_DIR)/$*.d

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
all: $(ELF_DIR)/$(TARGET).elf diagnostics success

###############################################
# Compilation rules (ALL STAGES)
###############################################
$(OBJ_DIR)/%.o: %.c
	$(PRINT_PP)
	$(Q)$(CC) $(CFLAGS) -E $< -o $(PRE_DIR)/$(notdir $*).i

	$(PRINT_ASM_GEN)
	$(Q)$(CC) $(CFLAGS) -S $< -o $(PRE_DIR)/$(notdir $*).s

	$(PRINT_CC)
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	$(PRINT_AS)
	$(Q)$(AS) $(ASFLAGS) -c $< -o $@

###############################################
# Linking
###############################################
$(ELF_DIR)/$(TARGET).elf: $(OBJS)
	$(PRINT_LD)
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
# Diagnostics
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
# Inspection outputs
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
# Dependency include
###############################################
-include $(DEPS)

###############################################
# Build success summary
###############################################
.PHONY: success
success:
	@echo "--------------------------------------------"
	@echo " BUILD SUCCESSFUL"
	@echo " Generated artifacts:"
	@echo "  - $(ELF_DIR)/$(TARGET).elf"
	@echo "  - $(BIN_DIR)/$(TARGET).bin"
	@echo "  - $(BIN_DIR)/$(TARGET).hex"
	@echo "  - $(BIN_DIR)/$(TARGET).srec"
	@echo "  - $(MAP_DIR)/$(TARGET).map"
	@echo "--------------------------------------------"

###############################################
# Clean (EXPLICIT)
###############################################
clean:
	$(PRINT_CLEAN)
	$(call PRINT_RM,$(OBJ_DIR))
	$(call PRINT_RM,$(PRE_DIR))
	$(call PRINT_RM,$(DEP_DIR))
	$(call PRINT_RM,$(ELF_DIR))
	$(call PRINT_RM,$(MAP_DIR))
	$(call PRINT_RM,$(BIN_DIR))
	$(call PRINT_RM,$(DUMP_DIR))
	$(call PRINT_RM,$(SYM_DIR))
	$(call PRINT_RM,$(SIZE_DIR))
	$(Q)rm -rf $(TEMP_DIR)/*
