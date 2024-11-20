#ifndef RW_ARRAY_H
#define RW_ARRAY_H

typedef struct
{
    int id;
} ThreadArgs;

void initialize_array(int *array, int size, int value);
void print_array(int *array, int size);

#endif
