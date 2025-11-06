# --- Variables ---
#
# Compiler and flags.
CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lncursesw

# Dirs.
BUILD_DIR = build
SRC_DIR = src
HEADERS_DIR = include
DATA_SRC_DIR = data

# --- Targets ---

# 1. The executable we want to build.
TARGET = $(BUILD_DIR)/godsays

# 2. We want to copy data from the root to build dir.
DATA_TARGET_DIR = $(BUILD_DIR)/$(DATA_SRC_DIR)
# A list of all the files inside data.
DATA_FILES = $(wildcard $(DATA_SRC_DIR)/*)

# --- Rules ---

all: $(TARGET) $(DATA_TARGET_DIR)

$(TARGET): $(SRC_DIR)/main.c
	@echo "Compiling..."
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(DATA_TARGET_DIR): $(DATA_FILES)
	@echo "Copying data files..."
	@mkdir -p $(DATA_TARGET_DIR)
	@cp -r $(DATA_SRC_DIR)/* $(DATA_TARGET_DIR)/

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)

.PHONY: all clean
