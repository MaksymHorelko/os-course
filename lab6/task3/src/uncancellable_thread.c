#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "uncancellable_thread.h"

void *uncancellable_function(void *arg)
{
    int delay_seconds = *(int *)arg;
    int iterations = delay_seconds * 2;

    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

    for (int i = 0; i < iterations; ++i)
    {
        printf("Child Thread. Iteration: %d\n", i + 1);
        sleep(1);
    }

    return NULL;
}
