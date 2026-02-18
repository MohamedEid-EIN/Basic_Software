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
# - Author      : Mohamed Eid
# - File Name   : Makefile
# - File Type   : Entry Build Script
# - Module      : Build_System
# - Layer       : Root
# - Description : Top-level entry point for the complete software build system.
#                 Responsible for:
#                   - Setting BUILD_ROOT and PROJECT_ROOT
#                   - Selecting build configuration (Debug/Release/Test)
#                   - Including directory configuration
#                   - Including toolchain configuration
#                   - Including module build logic
# -Design Reule : This file does NOT define module-specific paths.
#                  - All directory definitions are centralized in:
#                  - MakefileDir_Cfg.mk
#
# - Build Model : Layered architecture (APP → HAL → MCAL → PLATFORM)
# - Toolchain   : GCC / ARM-GCC (Configurable)
# -----------------------------------------------------------------------------------------------------------
# Version History
# -----------------------------------------------------------------------------------------------------------
# Version | Date       | Author       | Description
# --------|------------|--------------|-------------------------------------------------------------
# 1.00.00 | 2026-02-16 | Mohamed Eid  | Initial entry build system definition
##################################################################################################################################################################################


###########################################################
# Resolve absolute path of this Makefile
# (Independent of where make is invoked from)
###########################################################
BUILD_SYSTEM_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

###########################################################
# Project root directory
# Parent of 01_Build_System
###########################################################
ROOT := $(abspath $(BUILD_SYSTEM_DIR)/..)

###########################################################
# Location of internal build engines
###########################################################
TOOLCHAIN_DIR := $(ROOT)/02_ToolChain/MakeFiles

###########################################################
# Internal Makefiles (actual build logic lives there)
###########################################################
MAKEFILE_TARGET    := $(TOOLCHAIN_DIR)/MakeFile_Main.mk
MAKEFILE_TEST      := $(TOOLCHAIN_DIR)/MakeFile_Test.mk
MAKEFILE_SANALYSIS := $(TOOLCHAIN_DIR)/MakeFile_Analysis.mk

###############################################
# Default parameters
# MODULE: Used for module-specific builds
# FILE  : Used for file-specific operations
###############################################
MODULE ?= ALL          # if nothing is defined excute ALL
MODE ?= NORMAL         # if nothing is defined excute NORMAL behavior
FILE   ?=

###############################################
# Common command used to forward firmware build
# This prevents repetition in every target
###############################################
BUILD_TARGET = @$(MAKE) --no-print-directory -f $(MAKEFILE_TARGET) \
               BUILD_ROOT=$(BUILD_SYSTEM_DIR) \
               PROJECT_ROOT=$(ROOT) \
               MODULE=$(MODULE) \
               FILE=$(FILE)

###############################################
# Forwarding command for unit testing
###############################################
BUILD_TEST = $(MAKE) -f $(MAKEFILE_TEST) \
             BUILD_ROOT=$(BUILD_SYSTEM_DIR) \
             PROJECT_ROOT=$(ROOT) \
             MODULE=$(MODULE)

###############################################
# Forwarding command for static analysis
###############################################
BUILD_SANALYSIS = $(MAKE) -f $(MAKEFILE_SANALYSIS) \
                 BUILD_ROOT=$(BUILD_SYSTEM_DIR) \
                 PROJECT_ROOT=$(ROOT) \
                 MODULE=$(MODULE)

###############################################
# Declare non-file targets
# These are command-style targets, not files
###############################################
.PHONY: build clean rebuild \
        preprocess compile assemble link \
        test coverage analysis

###############################################
# Command to build all firmware files
# Default target executed when running: make build
###############################################
build:
	$(BUILD_TARGET) all

###############################################
# Command to delete all build artifacts
# and temporary generated folders
###############################################
clean:
	$(BUILD_TARGET) clean

###############################################
# Command to rebuild everything from scratch
# Executes clean first, then full build
###############################################
rebuild:
	$(BUILD_TARGET) rebuild

###############################################
# Command to run preprocessor stage only
# Example: make preprocess MODULE=GPIO
###############################################
preprocess:
	$(BUILD_TARGET) preprocess

###############################################
# Command to compile to assembly only
###############################################
compile:
	$(BUILD_TARGET) compile

###############################################
# Command to assemble to object files only
###############################################
assemble:
	$(BUILD_TARGET) assemble

###############################################
# Command to link object files only
###############################################
link:
	$(BUILD_TARGET) link

###############################################
# Command to execute unit tests
###############################################
test:
	$(BUILD_TEST) run

###############################################
# Command to run coverage instrumentation
###############################################
coverage:
	$(BUILD_TEST) MODE=coverage

###############################################
# Command to execute static analysis tools
###############################################
analysis:
	$(BUILD_SANALYSIS)
