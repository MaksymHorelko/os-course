CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/process_info.c
OBJ = build/main.o build/process_info.o
BIN = bin/process_info

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(BIN)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build bin
