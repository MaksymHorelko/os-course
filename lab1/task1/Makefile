CC = gcc
CFLAGS = -Wall -g

SRC_DIR = src
OBJ = main.o math_series.o curve_length.o
EXEC = task1

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -lm

main.o: $(SRC_DIR)/main.c $(SRC_DIR)/curve_length.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c

math_series.o: $(SRC_DIR)/math_series.c $(SRC_DIR)/math_series.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/math_series.c

curve_length.o: $(SRC_DIR)/curve_length.c $(SRC_DIR)/curve_length.h $(SRC_DIR)/math_series.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/curve_length.c

clean:
	rm -f *.o $(EXEC)

.PHONY: all clean
