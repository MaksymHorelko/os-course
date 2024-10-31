#include <stdio.h>
#include <unistd.h>
#include "thread_function.h"

void *thread_function(void *arg)
{
    ThreadArgs *args = (ThreadArgs *)arg;

    for (int i = 1; i <= args->num; i++)
    {
        printf("%s. %s %d\n", args->name, args->str, i);
        sleep(1);
    }
    return NULL;
}
