SRC_DIR := cpp
BUILD_DIR := builds

SRC := $(SRC_DIR)/main.cpp
TARGET := $(BUILD_DIR)/main

CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
