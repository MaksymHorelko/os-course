#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "worker.h"

void cleanup_handler(void *arg)
{
    fprintf(stderr, "Thread cleanup: %s\n", (char *)arg);
}

void *worker_function(void *arg)
{
    int iteration = 0;

    pthread_cleanup_push(cleanup_handler, "Thread is exiting");

    while (1)
    {
        printf("Iteration %d\n", iteration++);
        sleep(1);

        pthread_cleanup_pop(1);

        return NULL;
    }
}