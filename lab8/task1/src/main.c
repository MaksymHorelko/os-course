#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "buffer.h"

#define BUFFER_SIZE 5
#define RUNTIME_SECONDS 10

Buffer buffer;
sem_t empty_slots;
sem_t full_slots;
pthread_mutex_t buffer_lock;

void *producer_thread(void *args)
{
    while (1)
    {
        int item = rand() % 100;
        sem_wait(&empty_slots);
        pthread_mutex_lock(&buffer_lock);

        buffer_put(&buffer, item);
        printf("Producer produced: %d\n", item);

        pthread_mutex_unlock(&buffer_lock);
        sem_post(&full_slots);
        usleep(rand() % 500000);
    }
    return NULL;
}

void *consumer_thread(void *args)
{
    while (1)
    {
        sem_wait(&full_slots);
        pthread_mutex_lock(&buffer_lock);

        int item = buffer_get(&buffer);
        printf("Consumer consumed: %d\n", item);

        pthread_mutex_unlock(&buffer_lock);
        sem_post(&empty_slots);
        usleep(rand() % 500000);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int buffer_size = BUFFER_SIZE;

    if (argc > 1)
    {
        buffer_size = atoi(argv[1]);
        if (buffer_size <= 0)
        {
            printf("Invalid buffer size. Using default size: %d\n", BUFFER_SIZE);
            buffer_size = BUFFER_SIZE;
        }
    }

    srand(time(NULL));
    buffer_init(&buffer, buffer_size);

    sem_init(&empty_slots, 0, buffer_size);
    sem_init(&full_slots, 0, 0);
    pthread_mutex_init(&buffer_lock, NULL);

    pthread_t producer, consumer;

    pthread_create(&producer, NULL, producer_thread, NULL);
    pthread_create(&consumer, NULL, consumer_thread, NULL);

    sleep(RUNTIME_SECONDS);

    printf("Time is up. Cancelling threads...\n");
    pthread_cancel(producer);
    pthread_cancel(consumer);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);
    pthread_mutex_destroy(&buffer_lock);
    buffer_destroy(&buffer);

    printf("Program completed.\n");
    return 0;
}
