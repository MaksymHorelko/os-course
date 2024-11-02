CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/random_thread.c src/string_thread.c
OBJ = build/main.o build/random_thread.o build/string_thread.o
BIN = bin/main

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(BIN)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build bin
