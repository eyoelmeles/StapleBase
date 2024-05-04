CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

EXEC = staplebase

SRC_DIR = src
OBJ_DIR = obj
TESTS_DIR = tests

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TEST_SRCS = $(wildcard $(TESTS_DIR)/*.c)
TEST_EXECUTABLES = $(patsubst $(TESTS_DIR)/%.c, $(TESTS_DIR)/%, $(TEST_SRCS))

all: $(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

tests: $(TEST_EXECUTABLES)

$(TESTS_DIR)/%: $(TESTS_DIR)/%.c $(OBJS)  # Include $(OBJS) in the rule
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

run_tests: tests
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $$test..."; \
		./$$test; \
	done

clean:
	rm -f $(OBJS) $(EXEC) $(TEST_EXECUTABLES) integers.bin

