# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
OUTPUT_NAME := haxagonal_helper

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Target executable
TARGET := $(BIN_DIR)/app

# Source files and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)
	make final

# Build target
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Final output
final: $(TARGET)
	@echo "Building final output using object files..."
	$(CXX) $(CXXFLAGS) -o ${OUTPUT_NAME} $(OBJS)
	

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	rm -rf ${OUTPUT_NAME}

# Phony targets
.PHONY: all clean