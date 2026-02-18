# ===============================
# Unit Test Build (GPIO)
# ===============================

# Compilers
CC  = gcc
CXX = g++

# Target
TARGET = test_gpio

# ===============================
# Flags
# ===============================

BASE_CFLAGS   = -Wall -Wextra -g
BASE_CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Enable UNIT_TEST macro for fault injection hooks
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

INCLUDES  = -I../../../06_Software/03_Libraries/STD_TYPES/Cfg
INCLUDES += -I../../../06_Software/03_Libraries/STD_TYPES/Include
INCLUDES += -I../../../06_Software/03_Libraries/UTILS/Include
INCLUDES += -I../../../06_Software/08_MCAL/GPIO/Cfg/Header
INCLUDES += -I../../../06_Software/08_MCAL/GPIO/Header
INCLUDES += -I../../../06_Software/08_MCAL/GPIO/Header/Include
INCLUDES += -IMocks

# ===============================
# Source Files
# ===============================

C_SRCS = \
	../../../06_Software/08_MCAL/GPIO/Source/GPIO.c \
	../../../06_Software/08_MCAL/GPIO/Cfg/Source/GPIO_Cfg.c \
	Mocks/GPIO_Mock.c

CPP_SRCS = \
	Test/UnitTest_GPIO.cpp

# ===============================
# Default Build
# ===============================

all: build

build: clean
	$(COMPILER)  $(CFLAGS)   $(INCLUDES) -c $(C_SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(CPP_SRCS)
	$(CXX) *.o -o $(TARGET) $(LIBS)

run: build
	./$(TARGET)

# ===============================
# Coverage Build
# ===============================

coverage: clean
	$(COMPILER)  $(CFLAGS)   $(COVERAGE_FLAGS) $(INCLUDES) -c $(C_SRCS)
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
# Static Analysis
# ===============================

static:
	cppcheck --enable=all --inconclusive \
	         --force \
	         --xml --xml-version=2 \
	         ../../../06_Software 2> cppcheck-report.xml
	cppcheck-htmlreport \
	         --file=cppcheck-report.xml \
	         --report-dir=cppcheck-report \
	         --source-dir=../../../06_Software/08_MCAL/GPIO
	@echo "Static analysis report generated in cppcheck-report/index.html"

# ===============================
# Advanced Static Analysis (Clang)
# ===============================


analyze: clean
	mkdir -p clang-report
	scan-build \
	--keep-going \
	-o clang-report \
	--use-cc=$(COMPILER) \
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
	rm -rf coverage_report
	rm -f $(TARGET)
