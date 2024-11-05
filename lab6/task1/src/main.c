#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "worker_threads.h"
#include "display_thread.h"

#define ARRAY_SIZE 100

int global_array[ARRAY_SIZE];
int num_threads;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    num_threads = atoi(argv[1]);
    if (num_threads <= 0 || num_threads > ARRAY_SIZE)
    {
        fprintf(stderr, "Number of threads should be between 1 and %d.\n", ARRAY_SIZE);
        return 1;
    }

    pthread_t threads[num_threads];
    pthread_t display_thread;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        global_array[i] = -1;
    }

    pthread_create(&display_thread, NULL, display_function, &num_threads);
    pthread_detach(display_thread);

    for (int i = 0; i < num_threads; i++)
    {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, worker_function, arg);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All calculation threads have finished.\n");

    return 0;
}
