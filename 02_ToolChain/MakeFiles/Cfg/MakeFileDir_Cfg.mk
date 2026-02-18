##################################################################################################################################################################################
# License     : MIT License
# Copyright (c) 2025 Mohamed Eid
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
# - File Name          : MakefileDir_Cfg.mk
# - File Type          : Directory Configuration Script
# - Module             : Build System
# - Layer              : Toolchain
# - Description        : Centralized directory configuration for the entire software architecture.
# - Responsibilities   : - Define software layer roots (APP, HAL, MCAL, etc.)
#                        - Define module-level source and include directories
#                        - Define platform and startup paths
#                        - Define build output directories
#                        - Define quality report directories
# - Design Rule        : - Private headers are never exposed to upper layers.
#                        - Public APIs are exposed only via Include folders.
# - This file contains : - NO compilation logic
#                        - NO compiler flags
#                        - NO toolchain selection
#                        - It is strictly responsible for structural definition only.
# - Architecture Model : Module/
#                          ├── Source/
#                          ├── Header/
#                          │     ├── Include/   (Public headers)
#                          │     └── *.h        (Private headers)
#                          └── Cfg/
#                                ├── Source/
#                                └── Header/
#                                      ├── Include/  (Private headers)
#                                      └── *.h       (Private headers)
# -----------------------------------------------------------------------------------------------------------
# Version History
# -----------------------------------------------------------------------------------------------------------
# Version | Date       | Author       | Description
# --------|------------|--------------|-------------------------------------------------------------
# 1.00.00 | 2026-02-16 | Mohamed Eid  | Initial centralized directory architecture definition
##################################################################################################################################################################################


###########################################################
# Root Validation
###########################################################

BUILD_ROOT  ?= $(error BUILD_ROOT not set by entry Makefile)
PROJECT_ROOT ?= $(error PROJECT_ROOT not set by entry Makefile)

###########################################################
# Global Roots
###########################################################

SOFTWARE_ROOT := $(PROJECT_ROOT)/06_Software
TEST_ROOT     := $(PROJECT_ROOT)/08_Tests
UNITTEST_ROOT := $(TEST_ROOT)/01_Unit_Test

###########################################################
# Layer Roots Directories
###########################################################
APP_ROOT        := $(SOFTWARE_ROOT)/APP
INTERFACE_ROOT  := $(SOFTWARE_ROOT)/INTERFACE
LIB_ROOT        := $(SOFTWARE_ROOT)/LIB
SERVICE_ROOT    := $(SOFTWARE_ROOT)/SERVICE
RTOS_ROOT       := $(SOFTWARE_ROOT)/RTOS
STACK_ROOT      := $(SOFTWARE_ROOT)/STACK
HAL_ROOT        := $(SOFTWARE_ROOT)/HAL
MCAL_ROOT       := $(SOFTWARE_ROOT)/MCAL
PLATFORM_ROOT   := $(SOFTWARE_ROOT)/PLATFORM

###################################################################################
# Application layer Componenets Directories
###################################################################################
# ------------ APP Module --------------
APP_SRC_DIR     := $(APP_ROOT)/Source

#========================================================
# ------------ APP Source Directories --------------
APP_SRC_DIRS = \
	$(APP_SRC_DIR)

# ------------ APP Include Directories --------------
APP_INC_DIRS =

###################################################################################
# Interfaces Layer Components Directories
###################################################################################
# ------------ MCAL_API Module --------------
MCAL_API_ROOT     := $(INTERFACE_ROOT)/MCAL_API
MCAL_API_INC_DIR  := $(MCAL_API_ROOT)/Include

# ------------ HAL_API Module --------------
HAL_API_ROOT     := $(INTERFACE_ROOT)/HAL_API
HAL_API_INC_DIR  := $(HAL_API_ROOT)/Include


#========================================================
# ------------ INTERFACE Source Directories --------------
INTERFACE_SRC_DIRS =

# ------------ INTERFACE Include Directories --------------
INTERFACE_INC_DIRS = \
	$(MCAL_API_INC_DIR)

###################################################################################
# Liberaries Layer Components Directories
###################################################################################
# ------------ STD_TYPES Module --------------
STD_TYPES_ROOT := $(LIB_ROOT)/STD_TYPES
STD_TYPES_INC_DIR := $(STD_TYPES_ROOT)/Include
STD_TYPES_CFG_DIR := $(STD_TYPES_ROOT)/Cfg

# ------------ STD_TYPES Module --------------
UTILS_ROOT := $(LIB_ROOT)/UTILS
UTILS_INC_DIR := $(UTILS_ROOT)/Include


#========================================================
# ------------ LIB Source Directories --------------
LIB_SRC_DIRS =

# ------------ LIB Include Directories --------------
LIB_INC_DIRS = \
	$(UTILS_INC_DIR) \
	$(STD_TYPES_INC_DIR) \
	$(STD_TYPES_CFG_DIR)
###################################################################################
# Services Layer Components Directories
###################################################################################

#========================================================
# ------------ SERVICE Source Directories --------------
SERVICE_SRC_DIRS =

# ------------ SERVICE Include Directories --------------
SERVICE_INC_DIRS =

###################################################################################
# Real Time Operating System Layer Components Directories
###################################################################################

#========================================================
# ------------ RTOS Source Directories --------------
RTOS_SRC_DIRS =

# ------------ RTOS Include Directories --------------
RTOS_INC_DIRS =

###################################################################################
# Stacks Layer Components Directories
###################################################################################

#========================================================
# ------------ STACK Source Directories --------------
STACK_SRC_DIRS =

# ------------ STACK Include Directories --------------
STACK_INC_DIRS =

###################################################################################
# Hardware Abstraction Layer Components Directories
###################################################################################

# ------------ CHLCD Module --------------
CHLCD_ROOT        := $(HAL_ROOT)/CHLCD
CHLCD_SRC_DIR     := $(CHLCD_ROOT)/Source
CHLCD_HDR_DIR     := $(CHLCD_ROOT)/Header
CHLCD_INC_DIR     := $(CHLCD_HDR_DIR)/Include
CHLCD_CFG_SRC_DIR := $(CHLCD_ROOT)/Cfg/Source
CHLCD_CFG_HDR_DIR := $(CHLCD_ROOT)/Cfg/Header

# ------------ LED Module --------------
LED_ROOT           := $(HAL_ROOT)/LED
LED_SRC_DIR        := $(LED_ROOT)/Source
LED_HDR_DIR        := $(LED_ROOT)/Header
LED_INC_DIR        := $(LED_HDR_DIR)/Include
LED_CFG_SRC_DIR    := $(LED_ROOT)/Cfg/Source
LED_CFG_HDR_DIR    := $(LED_ROOT)/Cfg/Header

# ------------ MOSENS Module --------------
MOSENS_ROOT        := $(HAL_ROOT)/MOSENS
MOSENS_SRC_DIR     := $(MOSENS_ROOT)/Source
MOSENS_HDR_DIR     := $(MOSENS_ROOT)/Header
MOSENS_INC_DIR     := $(MOSENS_HDR_DIR)/Include
MOSENS_CFG_SRC_DIR := $(MOSENS_ROOT)/Cfg/Source
MOSENS_CFG_HDR_DIR := $(MOSENS_ROOT)/Cfg/Header

#========================================================
# ------------ HAL Source Directories --------------
HAL_SRC_DIRS =

# ------------ HAL Include Directories --------------
HAL_INC_DIRS =

###################################################################################
# MicroController Abstraction Layer Components Directories
###################################################################################

# ------------ GPIO Module --------------
GPIO_ROOT        := $(MCAL_ROOT)/GPIO
GPIO_SRC_DIR     := $(GPIO_ROOT)/Source
GPIO_HDR_DIR     := $(GPIO_ROOT)/Header
GPIO_INC_DIR     := $(GPIO_HDR_DIR)/Include
GPIO_CFG_SRC_DIR := $(GPIO_ROOT)/Cfg/Source
GPIO_CFG_HDR_DIR := $(GPIO_ROOT)/Cfg/Header

# ------------ SPI Module --------------
SPI_ROOT        := $(MCAL_ROOT)/SPI
SPI_SRC_DIR     := $(SPI_ROOT)/Source
SPI_HDR_DIR     := $(SPI_ROOT)/Header
SPI_INC_DIR     := $(SPI_HDR_DIR)/Include
SPI_CFG_SRC_DIR := $(SPI_ROOT)/Cfg/Source
SPI_CFG_HDR_DIR := $(SPI_ROOT)/Cfg/Header

# ------------ UART Module --------------
UART_ROOT        := $(MCAL_ROOT)/UART
UART_SRC_DIR     := $(UART_ROOT)/Source
UART_HDR_DIR     := $(UART_ROOT)/Header
UART_INC_DIR     := $(UART_HDR_DIR)/Include
UART_CFG_SRC_DIR := $(UART_ROOT)/Cfg/Source
UART_CFG_HDR_DIR := $(UART_ROOT)/Cfg/Header

# ------------ IIC Module --------------
IIC_ROOT        := $(MCAL_ROOT)/IIC
IIC_SRC_DIR     := $(IIC_ROOT)/Source
IIC_HDR_DIR     := $(IIC_ROOT)/Header
IIC_INC_DIR     := $(IIC_HDR_DIR)/Include
IIC_CFG_SRC_DIR := $(IIC_ROOT)/Cfg/Source
IIC_CFG_HDR_DIR := $(IIC_ROOT)/Cfg/Header

# ------------ ADC Module --------------
ADC_ROOT        := $(MCAL_ROOT)/ADC
ADC_SRC_DIR     := $(ADC_ROOT)/Source
ADC_HDR_DIR     := $(ADC_ROOT)/Header
ADC_INC_DIR     := $(ADC_HDR_DIR)/Include
ADC_CFG_SRC_DIR := $(ADC_ROOT)/Cfg/Source
ADC_CFG_HDR_DIR := $(ADC_ROOT)/Cfg/Header

# ------------ DAC Module --------------
DAC_ROOT        := $(MCAL_ROOT)/DAC
DAC_SRC_DIR     := $(DAC_ROOT)/Source
DAC_HDR_DIR     := $(DAC_ROOT)/Header
DAC_INC_DIR     := $(DAC_HDR_DIR)/Include
DAC_CFG_SRC_DIR := $(DAC_ROOT)/Cfg/Source
DAC_CFG_HDR_DIR := $(DAC_ROOT)/Cfg/Header

# ------------ PWM Module --------------
PWM_ROOT        := $(MCAL_ROOT)/PWM
PWM_SRC_DIR     := $(PWM_ROOT)/Source
PWM_HDR_DIR     := $(PWM_ROOT)/Header
PWM_INC_DIR     := $(PWM_HDR_DIR)/Include
PWM_CFG_SRC_DIR := $(PWM_ROOT)/Cfg/Source
PWM_CFG_HDR_DIR := $(PWM_ROOT)/Cfg/Header

# ------------ ICU Module --------------
ICU_ROOT        := $(MCAL_ROOT)/ICU
ICU_SRC_DIR     := $(ICU_ROOT)/Source
ICU_HDR_DIR     := $(ICU_ROOT)/Header
ICU_INC_DIR     := $(ICU_HDR_DIR)/Include
ICU_CFG_SRC_DIR := $(ICU_ROOT)/Cfg/Source
ICU_CFG_HDR_DIR := $(ICU_ROOT)/Cfg/Header

# ------------ CAN Module --------------
CAN_ROOT        := $(MCAL_ROOT)/CAN
CAN_SRC_DIR     := $(CAN_ROOT)/Source
CAN_HDR_DIR     := $(CAN_ROOT)/Header
CAN_INC_DIR     := $(CAN_HDR_DIR)/Include
CAN_CFG_SRC_DIR := $(CAN_ROOT)/Cfg/Source
CAN_CFG_HDR_DIR := $(CAN_ROOT)/Cfg/Header

#========================================================
# ------------ MCAL Source directories --------------
MCAL_SRC_DIRS = \
	$(GPIO_CFG_SRC_DIR) \
	$(GPIO_SRC_DIR)
# ------------ MCAL Include directories --------------
MCAL_INC_DIRS = \
	$(GPIO_HDR_DIR) \
	$(GPIO_INC_DIR) \
	$(GPIO_CFG_HDR_DIR)

###################################################################################
# PLATFORM Layer Components Directories
###################################################################################
# ------------ STARTUP Module --------------
STARTUP_DIR := $(PLATFORM_ROOT)/StartUp_Code

# ------------ Linker Module --------------
LINKER_DIR  := $(PLATFORM_ROOT)/Linker

#========================================================
# ------------ PLATFORM Source directories --------------
PLATFORM_SRC_DIRS = \
	$(STARTUP_DIR)

# ------------ PLATFORM Include directories --------------
PLATFORM_INC_DIRS =

###################################################################################
# Aggregate Source Directories
###################################################################################
ALL_SRC_DIR := \
             $(APP_SRC_DIRS) \
             $(INTERFACE_SRC_DIRS) \
             $(LIB_SRC_DIRS) \
             $(SERVICE_SRC_DIRS) \
             $(RTOS_SRC_DIRS) \
             $(STACK_SRC_DIRS) \
             $(HAL_SRC_DIRS) \
             $(MCAL_SRC_DIRS) \
             $(PLATFORM_SRC_DIRS)

VPATH := $(ALL_SRC_DIR)

###################################################################################
# Aggregate Include Directories
###################################################################################
ALL_INC_DIRS := \
             $(APP_INC_DIRS) \
             $(INTERFACE_INC_DIRS) \
             $(LIB_INC_DIRS) \
             $(SERVICE_INC_DIRS) \
             $(RTOS_INC_DIRS) \
             $(STACK_INC_DIRS) \
             $(HAL_INC_DIRS) \
             $(MCAL_INC_DIRS) \
             $(PLATFORM_INC_DIRS)

###################################################################################
# Build Directories
###################################################################################
TEMP_DIR     = Temp

# ------------ Build output directories --------------
OBJ_DIR  = $(TEMP_DIR)/Obj
PRE_DIR  = $(TEMP_DIR)/Pre
ASM_DIR  = $(TEMP_DIR)/Asm
DEP_DIR  = $(TEMP_DIR)/Dep
ELF_DIR  = $(TEMP_DIR)/Elf
MAP_DIR  = $(TEMP_DIR)/Map
BIN_DIR  = $(TEMP_DIR)/Bin
DUMP_DIR = $(TEMP_DIR)/Dump
SYM_DIR  = $(TEMP_DIR)/Sym
SIZE_DIR = $(TEMP_DIR)/Size
LOG_DIR  = $(TEMP_DIR)/Log
DBG_DIR  = $(TEMP_DIR)/Dbg
HEX_DIR  = $(TEMP_DIR)/Hex
SREC_DIR = $(TEMP_DIR)/Serc
LIST_DIR = $(TEMP_DIR)/Lst

###################################################################################
# Quality /Build / Verification Directories
###################################################################################
QUALITY_DIR = Quality
REPORTS_DIR := $(QUALITY_DIR)/Reports

# ------------ Unit Test Directories --------------
UT_ROOT            := $(REPORTS_DIR)/UnitTest
UT_ALL_DIR         := $(UT_ROOT)/All
UT_MODULES_DIR     := $(UT_ROOT)/Modules

UT_GPIO_DIR        := $(UT_MODULES_DIR)/GPIO

# ------------ Static Analysis Directories --------------
SANALYSIS_ROOT        := $(REPORTS_DIR)/Static_Analysis
SANALYSIS_ALL_DIR     := $(SANALYSIS_ROOT)/All
SANALYSIS_MODULES_DIR := $(SANALYSIS_ROOT)/Modules

SANALYSIS_GPIO_DIR    := $(SANALYSIS_MODULES_DIR)/GPIO

# ------------ Coverage Directories --------------
COVERAGE_ROOT        := $(REPORTS_DIR)/Coverage
COVERAGE_ALL_DIR     := $(COVERAGE_ROOT)/All
COVERAGE_MODULES_DIR := $(COVERAGE_ROOT)/Modules

COVERAGE_GPIO_DIR    := $(COVERAGE_MODULES_DIR)/GPIO
