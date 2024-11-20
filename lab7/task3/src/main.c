#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "rw_array.h"

#define DEFAULT_ARRAY_SIZE 10
#define DEFAULT_WRITERS 2
#define DEFAULT_READERS 5
#define RUNTIME_SECONDS 10

int *array;
int array_size;
pthread_rwlock_t rwlock;

void *writer_thread(void *args)
{
    ThreadArgs *data = (ThreadArgs *)args;
    while (1)
    {
        usleep(rand() % 500000);

        int index = rand() % array_size;
        int value = rand() % 100;

        pthread_rwlock_wrlock(&rwlock);
        array[index] = value;
        printf("Writer %d wrote %d at index %d\n", data->id, value, index);
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}

void *reader_thread(void *args)
{
    ThreadArgs *data = (ThreadArgs *)args;
    while (1)
    {
        usleep(rand() % 500000);

        int index = rand() % array_size;

        pthread_rwlock_rdlock(&rwlock);
        int value = array[index];
        printf("Reader %d read %d from index %d\n", data->id, value, index);
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}

void *display_thread(void *args)
{
    while (1)
    {
        sleep(1);

        pthread_rwlock_rdlock(&rwlock);
        printf("Array state: ");
        for (int i = 0; i < array_size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int num_writers = DEFAULT_WRITERS;
    int num_readers = DEFAULT_READERS;
    array_size = DEFAULT_ARRAY_SIZE;

    if (argc > 1)
        array_size = atoi(argv[1]);
    if (argc > 2)
        num_writers = atoi(argv[2]);
    if (argc > 3)
        num_readers = atoi(argv[3]);

    if (array_size <= 0 || num_writers <= 0 || num_readers <= 0)
    {
        printf("Invalid input parameters.\n");
        return 1;
    }

    srand(time(NULL));
    array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++)
        array[i] = 0;

    pthread_rwlock_init(&rwlock, NULL);

    pthread_t *writers = malloc(num_writers * sizeof(pthread_t));
    pthread_t *readers = malloc(num_readers * sizeof(pthread_t));
    pthread_t display;

    ThreadArgs *writer_args = malloc(num_writers * sizeof(ThreadArgs));
    ThreadArgs *reader_args = malloc(num_readers * sizeof(ThreadArgs));

    for (int i = 0; i < num_writers; i++)
    {
        writer_args[i].id = i;
        pthread_create(&writers[i], NULL, writer_thread, &writer_args[i]);
    }

    for (int i = 0; i < num_readers; i++)
    {
        reader_args[i].id = i;
        pthread_create(&readers[i], NULL, reader_thread, &reader_args[i]);
    }

    pthread_create(&display, NULL, display_thread, NULL);

    sleep(RUNTIME_SECONDS);

    printf("Time is up. Terminating program.\n");
    free(array);
    free(writers);
    free(readers);
    free(writer_args);
    free(reader_args);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
