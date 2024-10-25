CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/process_manager.c
OBJ = build/main.o build/process_manager.o
BIN = bin/process_manager

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(BIN)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build bin
