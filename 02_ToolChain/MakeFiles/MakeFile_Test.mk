# ===============================
# Unit Test Build (MODULE Aware)
# ===============================

ROOT       := $(PROJECT_ROOT)
BUILD_ROOT := $(BUILD_ROOT)
REPORT_DIR := $(BUILD_ROOT)/Temp/Test_Reports
MODULE     ?= GPIO
REPORT_DIR := $(BUILD_ROOT)/Temp/Test_Reports
XSL_FILE   := $(PROJECT_ROOT)/02_ToolChain/MakeFiles/gtest_report.xsl

# ===============================
# Compilers
# ===============================

CC  = gcc
CXX = g++

# ===============================
# Target
# ===============================

TARGET = test_$(MODULE)

# ===============================
# Flags
# ===============================

BASE_CFLAGS   = -Wall -Wextra -g
BASE_CXXFLAGS = -std=c++17 -Wall -Wextra -g

DEFINES = -DUNIT_TEST

CFLAGS   = $(BASE_CFLAGS)   $(DEFINES)
CXXFLAGS = $(BASE_CXXFLAGS) $(DEFINES)

# GoogleTest
LIBS = -lgtest -lgtest_main -pthread

# ===============================
# Coverage Flags
# ===============================

COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
COVERAGE_LIBS  = -lgcov

# ===============================
# Include Paths
# ===============================

INCLUDES  = -I$(ROOT)/06_Software/LIB/STD_TYPES/Cfg
INCLUDES += -I$(ROOT)/06_Software/LIB/STD_TYPES/Include
INCLUDES += -I$(ROOT)/06_Software/LIB/UTILS/Include
INCLUDES += -I$(ROOT)/06_Software/MCAL/$(MODULE)/Cfg/Header
INCLUDES += -I$(ROOT)/06_Software/MCAL/$(MODULE)/Header
INCLUDES += -I$(ROOT)/06_Software/MCAL/$(MODULE)/Header/Include
INCLUDES += -I$(TEST_ROOT)/Mocks
INCLUDES += -I$(TEST_ROOT)/Include

# ===============================
# Source Files
# ===============================

C_SRCS = \
	$(ROOT)/06_Software/MCAL/$(MODULE)/Source/$(MODULE).c \
	$(ROOT)/06_Software/MCAL/$(MODULE)/Cfg/Source/$(MODULE)_Cfg.c \
	$(TEST_ROOT)/Mocks/$(MODULE)_Mock.c

CPP_SRCS = \
	$(TEST_ROOT)/Test/UnitTest_$(MODULE).cpp

# ===============================
# Default Build
# ===============================

all: build

build: clean
	$(CC)  $(CFLAGS)   $(INCLUDES) -c $(C_SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(CPP_SRCS)
	$(CXX) *.o -o $(TARGET) $(LIBS)

run: build
	mkdir -p $(REPORT_DIR)
	./$(TARGET) --gtest_output=xml:$(REPORT_DIR)/$(TARGET).xml
	xsltproc $(XSL_FILE) \
	         $(REPORT_DIR)/$(TARGET).xml \
	         > $(REPORT_DIR)/$(TARGET).html
	@echo "------------------------------------------"
	@echo "Unit Test Reports Generated:"
	@echo "XML  : $(REPORT_DIR)/$(TARGET).xml"
	@echo "HTML : $(REPORT_DIR)/$(TARGET).html"
	@echo "------------------------------------------"
	@echo "------------------------------------------"
# ===============================
# Coverage Build
# ===============================

coverage: clean
	$(CC)  $(CFLAGS)   $(COVERAGE_FLAGS) $(INCLUDES) -c $(C_SRCS)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) $(INCLUDES) -c $(CPP_SRCS)
	$(CXX) *.o -o $(TARGET) $(LIBS) $(COVERAGE_LIBS)
	./$(TARGET)
	lcov --capture \
	     --ignore-errors mismatch \
	     --rc lcov_branch_coverage=1 \
	     --directory . \
	     --output-file coverage.info
	genhtml coverage.info \
	        --branch-coverage \
	        --output-directory coverage_report
	@echo "Coverage report generated in coverage_report/index.html"

# ===============================
# Static Analysis (Cppcheck)
# ===============================

static:
	cppcheck --enable=all --inconclusive \
	         --force \
	         --xml --xml-version=2 \
	         $(ROOT)/06_Software 2> cppcheck-report.xml
	cppcheck-htmlreport \
	         --file=cppcheck-report.xml \
	         --report-dir=cppcheck-report \
	         --source-dir=$(ROOT)/06_Software/08_MCAL/$(MODULE)
	@echo "Static analysis report generated in cppcheck-report/index.html"

# ===============================
# Advanced Static Analysis (Clang)
# ===============================

analyze: clean
	mkdir -p clang-report
	scan-build \
	--keep-going \
	-o clang-report \
	--use-cc=$(CC) \
	--use-c++=$(CXX) \
	make build || true
	@if [ -z "$$(ls -A clang-report)" ]; then \
		echo "<html><body><h2>No bugs found</h2></body></html>" > clang-report/index.html; \
	fi
	@echo "Clang report available in clang-report/"

# ===============================
# Clean
# ===============================

clean:
	rm -f *.o *.gcda *.gcno coverage.info
	rm -rf coverage_report clang-report cppcheck-report cppcheck-report.xml
	rm -f $(TARGET)
