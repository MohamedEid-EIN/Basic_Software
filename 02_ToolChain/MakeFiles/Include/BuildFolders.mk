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
# - Author      : Mohamed Eid
# - File Name   : MakeFile_Folders.mk
# - File Type   : Directory Initialization Script
# - Module      : MakeFile
# - Layer       : ToolChain
# Description:
#     This file is responsible for creating and maintaining
#     the complete directory structure required by the build system.
#     It guarantees that:
#         • All temporary build artifacts have valid destinations
#         • All quality-related folders exist before analysis
#         • No manual folder creation is required
# Responsibilities:
#     - Create build artifact directories (not committed to Git)
#     - Create quality/report directories (committed to Git)
# Important:
#     This file does NOT:
#         • Compile sources
#         • Define flags
#         • Link binaries
#     It strictly ensures filesystem readiness.
# -----------------------------------------------------------------------------------------------------------
# Version History
# -----------------------------------------------------------------------------------------------------------
# Version | Date       | Author       | Description
# --------|------------|--------------|-------------------------------------------------------------
# 1.00.00 | 2026-02-17 | Mohamed Eid  | Initial toolchain configuration architecture
##################################################################################################################################################################################

###########################################################
# Create build output folders (Temp - not committed)
###########################################################
$(shell mkdir -p $(OBJ_DIR) \
                 $(PRE_DIR) \
                 $(DEP_DIR) \
                 $(ELF_DIR) \
                 $(MAP_DIR) \
                 $(BIN_DIR) \
                 $(DUMP_DIR) \
                 $(SYM_DIR) \
                 $(SIZE_DIR) \
                 $(LOG_DIR)\
                 $(ASM_DIR) \
                 $(DBG_DIR) \
                 $(HEX_DIR) \
                 $(SREC_DIR) \
                 $(LIST_DIR))

###########################################################
# Create Quality folders (Committed in Git)
###########################################################
$(shell mkdir -p $(REPORTS_DIR) \
                 $(UT_ROOT) \
                 $(UT_ALL_DIR) \
                 $(UT_MODULES_DIR) \
                 $(UT_GPIO_DIR) \
                 $(SANALYSIS_ROOT) \
                 $(SANALYSIS_ALL_DIR) \
                 $(SANALYSIS_MODULES_DIR) \
                 $(SANALYSIS_GPIO_DIR) \
                 $(COVERAGE_ROOT) \
                 $(COVERAGE_ALL_DIR) \
                 $(COVERAGE_MODULES_DIR) \
                 $(COVERAGE_GPIO_DIR))
