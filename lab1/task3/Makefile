CC = gcc
CFLAGS = -Wall -g

SRC_DIR = src
OBJ = main.o
EXEC = task3

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -lm

main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c

clean:
	rm -f *.o $(EXEC)

.PHONY: all clean
