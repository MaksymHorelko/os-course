#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "worker.h"

pthread_key_t thread_data_key;

void cleanup_thread_data(void *data)
{
    free(data);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    pthread_t threads[num_threads];

    pthread_key_create(&thread_data_key, cleanup_thread_data);

    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_create(&threads[i], NULL, worker_function, (void *)(long)i) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return 1;
        }
    }

    pthread_key_delete(thread_data_key);

    printf("All threads completed.\n");
    return 0;
}
