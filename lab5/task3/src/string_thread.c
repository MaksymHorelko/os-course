#include <stdio.h>
#include <unistd.h>
#include "string_thread.h"

void *string_thread_func(void *arg)
{
    StringThreadArgs *args = (StringThreadArgs *)arg;
    for (int i = 0; i < args->repetitions; i++)
    {
        printf("String Thread: %s (iteration %d)\n", args->message, i + 1);
        sleep(1);
    }
    return NULL;
}
