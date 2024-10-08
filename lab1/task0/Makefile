CC = gcc
CFLAGS = -Wall -g

SRC_DIR = src
OBJ = main.o point.o process.o
EXEC = task0

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -lm

main.o: $(SRC_DIR)/main.c $(SRC_DIR)/point.h $(SRC_DIR)/process.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c

point.o: $(SRC_DIR)/point.c $(SRC_DIR)/point.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/point.c

process.o: $(SRC_DIR)/process.c $(SRC_DIR)/point.h $(SRC_DIR)/process.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/process.c

clean:
	rm -f *.o $(EXEC)

.PHONY: all clean

