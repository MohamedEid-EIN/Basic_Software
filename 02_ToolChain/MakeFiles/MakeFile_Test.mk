# ===============================
# Simple Unit Test Build
# ===============================

ROOT       := $(PROJECT_ROOT)
MODULE     ?= GPIO
TARGET     := test_$(MODULE)
TEST_ROOT  := $(ROOT)/08_Tests/01_Unit_Test

# ===============================
# Compilers
# ===============================

CC  = gcc
CXX = g++

# ===============================
# Flags
# ===============================

CFLAGS   = -Wall -Wextra -g -DUNIT_TEST
CXXFLAGS = -std=c++17 -Wall -Wextra -g -DUNIT_TEST

LIBS = -lgtest -lgtest_main -pthread

# ===============================
# Include Paths
# ===============================

INCLUDES  = -I$(ROOT)/06_Software/LIB/STD_TYPES/Cfg
INCLUDES += -I$(ROOT)/06_Software/LIB/STD_TYPES/Include
INCLUDES += -I$(ROOT)/06_Software/LIB/UTILS/Include
INCLUDES += -I$(ROOT)/06_Software/MCAL/$(MODULE)/Cfg/Header
INCLUDES += -I$(ROOT)/06_Software/MCAL/$(MODULE)/Header
INCLUDES += -I$(ROOT)/06_Software/MCAL/$(MODULE)/Header/Include
INCLUDES += -I$(TEST_ROOT)/$(MODULE)/Mocks
INCLUDES += -I$(TEST_ROOT)/$(MODULE)/Include

# ===============================
# Source Files
# ===============================

C_SRCS = \
	$(ROOT)/06_Software/MCAL/$(MODULE)/Source/$(MODULE).c \
	$(ROOT)/06_Software/MCAL/$(MODULE)/Cfg/Source/$(MODULE)_Cfg.c \
	$(TEST_ROOT)/$(MODULE)/Mocks/$(MODULE)_Mock.c

CPP_SRCS = \
	$(TEST_ROOT)/$(MODULE)/Test/UnitTest_$(MODULE).cpp

# ===============================
# Build
# ===============================

all: build

build:
	$(CC)  $(CFLAGS)   $(INCLUDES) -c $(C_SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(CPP_SRCS)
	$(CXX) *.o -o $(TARGET) $(LIBS)

run: build
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
