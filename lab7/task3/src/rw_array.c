#include <stdio.h>
#include <pthread.h>
#include "rw_array.h"

void initialize_array(int *array, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }
}

void print_array(int *array, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}
