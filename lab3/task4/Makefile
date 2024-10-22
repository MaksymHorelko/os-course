CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = 
SRC = src/main.c
OBJ = build/main.o
BIN = bin/main

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
