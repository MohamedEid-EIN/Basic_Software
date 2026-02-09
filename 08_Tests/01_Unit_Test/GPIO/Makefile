# Host compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# GoogleTest libraries
LIBS = -lgtest -lgtest_main -pthread

# Target executable
TARGET = gpio_test

# Include paths (GPIO headers)
INCLUDES  = -I../../../06_Software/03_Libraries/STD_TYPES/Cfg
INCLUDES  += -I../../../06_Software/03_Libraries/STD_TYPES/Include
INCLUDES  += -I../../../06_Software/03_Libraries/UTILS/Include

INCLUDES += -I../../../06_Software/07_MCAL/GPIO/Cfg
INCLUDES += -I../../../06_Software/07_MCAL/GPIO/Header
INCLUDES += -I../../../06_Software/07_MCAL/GPIO/Header/Include


# Sources (C++ test + C GPIO implementation)
SRCS = \
	UnitTest_GPIO.cpp \
	../../../06_Software/07_MCAL/GPIO/Source/GPIO.c

all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET) $(LIBS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
