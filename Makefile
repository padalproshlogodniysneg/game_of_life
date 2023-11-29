CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC_DIR = src
BUILD_DIR = build

EXECUTABLE = $(BUILD_DIR)/game_of_life
INIT_FILES = $(wildcard *.txt)

all: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD_DIR)/main.o $(BUILD_DIR)/game_of_life.o
	$(CC) -o $@ $^

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/game_of_life.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/game_of_life.o: $(SRC_DIR)/game_of_life.c $(SRC_DIR)/game_of_life.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)

rebuild: clean all