CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g

# Source files
SRCS = MatrixGraph_ranish.cpp \
       ranish_TestGraph.cpp

# Header files
HDRS = MatrixGraph_ranish.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = TestGraph

# Rule to build the executable
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files
%.o: %.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Phony target to clean up object files and executables
.PHONY: clean
clean:
    rm -f $(OBJS) $(TARGET)
