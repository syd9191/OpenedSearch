CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR  = src
TEST_DIR = tests
BIN_DIR  = bin

CORE_SRCS = \
    $(SRC_DIR)/tokeniser.cpp \
    $(SRC_DIR)/index.cpp 

MAIN_SRC   = ./main.cpp          # your program's main()

TOKENISER_TEST_SRCS  = $(TEST_DIR)/test_tokeniser.cpp
INDEX_TEST_SRCS = $(TEST_DIR)/test_index.cpp

APP_BIN   = $(BIN_DIR)/main               # main program
TOKENISER_TEST_BIN  = $(BIN_DIR)/test_tokeniser 
INDEX_TEST_BIN  = $(BIN_DIR)/test_index


.PHONY: all
all: $(APP_BIN)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(APP_BIN): $(CORE_SRCS) $(MAIN_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TOKENISER_TEST_BIN): $(CORE_SRCS) $(TOKENISER_TEST_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(INDEX_TEST_BIN): $(CORE_SRCS) $(INDEX_TEST_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: run test clean

run: $(APP_BIN)
	./$(APP_BIN)

test: $(TOKENISER_TEST_BIN) $(INDEX_TEST_BIN)
	./$(TOKENISER_TEST_BIN)
	./$(INDEX_TEST_BIN)

clean:
	rm -f $(BIN_DIR)/*