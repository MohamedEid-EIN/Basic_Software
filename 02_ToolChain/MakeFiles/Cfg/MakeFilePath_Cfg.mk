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
	$(GPIO_CFG_SRC_DIR) \
	$(GPIO_SRC_DIR) \
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
