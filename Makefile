# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Executable name
EXEC = relational_db

# Directories
SRC_DIR = src
OBJ_DIR = obj
TESTS_DIR = tests

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Test source files
TEST_SRCS = $(wildcard $(TESTS_DIR)/*.c)
TEST_EXECUTABLES = $(patsubst $(TESTS_DIR)/%.c, $(TESTS_DIR)/%, $(TEST_SRCS))

# Default target
all: $(EXEC)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Compile test files into test executables
tests: $(TEST_EXECUTABLES)

$(TESTS_DIR)/%: $(TESTS_DIR)/%.c $(OBJS)  # Include $(OBJS) in the rule
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

# Run tests
run_tests: tests
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $$test..."; \
		./$$test; \
	done

# Clean up object files, executables, and test executables
clean:
	rm -f $(OBJS) $(EXEC) $(TEST_EXECUTABLES)

