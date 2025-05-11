SRC_DIR := cpp
LIB_DIR := $(SRC_DIR)/lib
BUILD_DIR := builds

# Archivos fuente principales
SRC := $(SRC_DIR)/main.cpp
# Archivo de la biblioteca merge_sort
MRG_SRC := $(LIB_DIR)/merge_sort/merge_sort.cpp
CNT_SRC := $(LIB_DIR)/counting/counting.cpp

ALL_SRC := $(SRC) $(MRG_SRC) $(CNT_SRC)

TARGET := $(BUILD_DIR)/main

CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -I$(LIB_DIR)

all: $(TARGET)

$(TARGET): $(ALL_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
