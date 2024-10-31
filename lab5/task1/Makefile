CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/child_thread.c
OBJ = build/main.o build/child_thread.o
BIN = bin/child_thread

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(BIN)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build bin
