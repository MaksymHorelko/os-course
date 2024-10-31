CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/thread_function.c
OBJ = build/main.o build/thread_function.o
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
