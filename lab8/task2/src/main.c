#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "shared_data.h"

#define RUNTIME_SECONDS 10

SharedData shared_data;

void *producer_thread(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&shared_data.lock);

        while (shared_data.has_data)
        {
            pthread_cond_wait(&shared_data.producer_cond, &shared_data.lock);
        }

        shared_data.data = rand() % 100;
        shared_data.has_data = 1;

        printf("Producer generated: %d\n", shared_data.data);
        pthread_cond_signal(&shared_data.consumer_cond);

        pthread_mutex_unlock(&shared_data.lock);
        usleep(rand() % 500000 + 500000);
    }
    return NULL;
}

void *consumer_thread(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&shared_data.lock);

        while (!shared_data.has_data)
        {
            pthread_cond_wait(&shared_data.consumer_cond, &shared_data.lock);
        }

        printf("Consumer consumed: %d\n", shared_data.data);
        shared_data.data = 0;
        shared_data.has_data = 0;

        pthread_cond_signal(&shared_data.producer_cond);

        pthread_mutex_unlock(&shared_data.lock);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    shared_data_init(&shared_data);

    pthread_t producer, consumer;

    pthread_create(&producer, NULL, producer_thread, NULL);
    pthread_create(&consumer, NULL, consumer_thread, NULL);

    sleep(RUNTIME_SECONDS);

    printf("Time is up. Cancelling threads...\n");
    pthread_cancel(producer);
    pthread_cancel(consumer);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    shared_data_destroy(&shared_data);

    printf("Program completed.\n");
    return 0;
}
