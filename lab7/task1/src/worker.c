#include <stdio.h>
#include "worker.h"

extern long shared_variable;

void *modify_variable(void *args)
{
    ThreadArgs *data = (ThreadArgs *)args;

    for (int i = 0; i < data->num_operations; i++)
    {
        long temp = shared_variable;
        temp += data->increment;
        shared_variable = temp;
    }

    printf("Thread %d completed.\n", data->id);
    return NULL;
}
