###############################################
# Build System entry Makefile
# Public entry point (CI + developers)
###############################################

# Absolute path of THIS Makefile (not where make is run from)
BUILD_SYSTEM_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# Project root = parent of 01_Build_System
PROJECT_ROOT := $(abspath $(BUILD_SYSTEM_DIR)/..)

# Path to internal core Makefile
MAKEFILE_CORE := $(PROJECT_ROOT)/02_ToolChain/MakeFiles/MakeFile.mk

.PHONY: all clean rebuild

all:
	$(MAKE) -f $(MAKEFILE_CORE) BUILD_ROOT=$(BUILD_SYSTEM_DIR)

clean:
	$(MAKE) -f $(MAKEFILE_CORE) BUILD_ROOT=$(BUILD_SYSTEM_DIR) clean

rebuild:
	$(MAKE) -f $(MAKEFILE_CORE) BUILD_ROOT=$(BUILD_SYSTEM_DIR) clean all