CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = 
STATIC_LIB = lib/libarraylist.a
SHARED_LIB = lib/libarraylist.so
SRC = src/arraylist.c
OBJ = build/arraylist.o
BIN_STATIC = bin/static_app
BIN_SHARED = bin/shared_app

all: static_app shared_app

$(STATIC_LIB): $(OBJ)
	@mkdir -p lib
	ar rcs $(STATIC_LIB) $(OBJ)

$(SHARED_LIB): $(OBJ)
	@mkdir -p lib
	$(CC) -shared -o $(SHARED_LIB) $(OBJ)

static_app: $(STATIC_LIB) src/main.c
	@mkdir -p bin
	$(CC) $(CFLAGS) src/main.c -Llib -larraylist -o $(BIN_STATIC)

shared_app: $(SHARED_LIB) src/main.c
	@mkdir -p bin
	$(CC) $(CFLAGS) src/main.c -Llib -larraylist -Wl,-rpath=./lib -o $(BIN_SHARED)

build/arraylist.o: $(SRC)
	@mkdir -p build
	$(CC) $(CFLAGS) -fPIC -c $(SRC) -o $(OBJ)

clean:
	rm -rf bin/* build/* lib/*
