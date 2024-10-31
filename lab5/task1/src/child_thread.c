#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "child_thread.h"

void *child_thread_function(void *arg)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("Child Thread. Iteration: %d\n", i);
        sleep(rand() % 3);
    }
    return NULL;
}
