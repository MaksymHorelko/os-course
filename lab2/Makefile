CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = 
SRC = src/environ.c src/actions.c
OBJ = build/environ.o build/actions.o
BIN = bin/environ

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf bin/* build/*

.PHONY: all clean
