CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR  = src
TEST_DIR = tests
BIN_DIR  = bin

CORE_SRCS  = $(SRC_DIR)/tokeniser.cpp      # shared core code
MAIN_SRC   = ./main.cpp          # your program's main()
TEST_SRCS  = $(TEST_DIR)/test_tokeniser.cpp

APP_BIN   = $(BIN_DIR)/main               # main program
TEST_BIN  = $(BIN_DIR)/test_tokeniser 

.PHONY: all
all: $(APP_BIN)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(APP_BIN): $(CORE_SRCS) $(MAIN_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_BIN): $(CORE_SRCS) $(TEST_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@


.PHONY: run test clean

run: $(APP_BIN)
	./$(APP_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(BIN_DIR)/*