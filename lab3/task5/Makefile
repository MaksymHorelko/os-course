CC = gcc
CFLAGS = -Wall -Iinclude
BIN_DIR = bin

all: main child

main: $(BIN_DIR)/main

child: $(BIN_DIR)/child

$(BIN_DIR)/main: src/main.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) src/main.o -o $(BIN_DIR)/main

$(BIN_DIR)/child: src/child.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) src/child.o -o $(BIN_DIR)/child

src/main.o: src/main.c include/main.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/child.o: src/child.c include/child.h
	$(CC) $(CFLAGS) -c src/child.c -o src/child.o

clean:
	rm -f src/*.o $(BIN_DIR)/main $(BIN_DIR)/child
