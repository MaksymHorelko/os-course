#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "worker.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <delay_seconds>\n", argv[0]);
        return 1;
    }

    int delay = atoi(argv[1]);
    pthread_t worker_thread;

    if (pthread_create(&worker_thread, NULL, worker_function, NULL) != 0)
    {
        perror("Failed to create thread");
        return 1;
    }

    sleep(delay);

    if (pthread_cancel(worker_thread) != 0)
    {
        perror("Failed to cancel thread");
        return 1;
    }

    void *status;
    if (pthread_join(worker_thread, &status) != 0)
    {
        perror("Failed to join thread");
        return 1;
    }

    if (status == PTHREAD_CANCELED)
    {
        fprintf(stderr, "Thread was canceled\n");
    }
    else
    {
        fprintf(stderr, "Thread completed normally\n");
    }

    return 0;
}
