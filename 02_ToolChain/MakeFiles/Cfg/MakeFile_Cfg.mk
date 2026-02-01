###############################################
# TBD
###############################################

# ------------------------------------------------
# Project root (current directory)
# ------------------------------------------------
PROJECT_ROOT  = . # Project root directore
BUILD_DIR     = $(PROJECT_ROOT)/01_Build_System
TOOLCHAIN_DIR = $(PROJECT_ROOT)/02_ToolChain
MAKEFILE_DIR  = $(PROJECT_ROOT)/02_ToolChain/MakeFiles
SOFTWARE_DIR  = $(PROJECT_ROOT)/06_Software
APP_DIR       = $(SOFTWARE_DIR)/01_Application
INT_DIR       = $(SOFTWARE_DIR)/02_Interfaces
SERVICES_DIR  = $(SOFTWARE_DIR)/04_Serivces
STACKS_DIR    = $(SOFTWARE_DIR)/06_Stacks

# ------------------------------------------------
# Libires modules source directories
# ------------------------------------------------
LIB_DIR       = $(SOFTWARE_DIR)/03_Libraries
COMON_DIR     = $(PLATFORM_DIR)/Common
COMON_CFG_DIR = $(PLATFORM_DIR)/Common


# ------------------------------------------------
# MCAL modules source directories
# ------------------------------------------------
MCAL_DIR     = $(SOFTWARE_DIR)/07_MCAL
GPIO_DIR     = $(MCAL_ROOT)/GPIO
GPIO_INC_DIR = $(GPIO_DIR)/Header/Include
GPIO_HDR_DIR = $(GPIO_DIR)/Header
GPIO_SRC_DIR = $(GPIO_DIR)/Source

# ------------------------------------------------
# PLATFORM modules source directories
# ------------------------------------------------
PLATFORM_DIR  = $(SOFTWARE_DIR)/08_Platform
STARTUP_DIR    = $(PLATFORM_DIR)/StartUp_Code
LINKER_DIR     = $(PLATFORM_DIR)/Liker
LINKER_CFG_DIR = $(PLATFORM_DIR)/Liker/Cfg

# ------------------------------------------------
# TBD
# ------------------------------------------------
SRC_DIRS = $(GPIO_SRC_DIR)
HDR_DIRS = $(GPIO_SRC_DIR)
INC_DIRS = $(GPIO_SRC_DIR)

