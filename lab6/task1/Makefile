CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/display_thread.c src/worker_threads.c
OBJ = build/main.o build/display_thread.o build/worker_threads.o
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
