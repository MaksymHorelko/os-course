#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "cancellable_thread.h"

void *cancellable_function(void *arg)
{
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    int iteration = 0;
    while (1)
    {
        printf("Child Thread. Iteration: %d\n", iteration++);
        sleep(1);
    }

    return NULL;
}
