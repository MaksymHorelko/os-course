#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "worker.h"

extern pthread_key_t thread_data_key;

void *worker_function(void *arg)
{
    int thread_id = (int)(long)arg;

    thread_data_t *data = malloc(sizeof(thread_data_t));
    if (data == NULL)
    {
        perror("Failed to allocate memory for thread data");
        pthread_exit(NULL);
    }

    data->thread_id = thread_id;
    snprintf(data->message, sizeof(data->message), "Thread %d message", thread_id);

    pthread_setspecific(thread_data_key, data);

    int num_lines = rand() % 5 + 1;
    for (int i = 0; i < num_lines; i++)
    {
        int random_number = rand() % 100 + 1;

        thread_data_t *thread_data = pthread_getspecific(thread_data_key);
        printf("%s: Random number %d\n", thread_data->message, random_number);

        sleep(1);
    }

    pthread_exit(NULL);
}
