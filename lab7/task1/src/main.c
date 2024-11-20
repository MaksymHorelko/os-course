#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "worker.h"

#define DEFAULT_NUM_PAIRS 2
#define DEFAULT_NUM_OPERATIONS 100000

long shared_variable = 0;

int main(int argc, char *argv[])
{
    int num_pairs = DEFAULT_NUM_PAIRS;
    int num_operations = DEFAULT_NUM_OPERATIONS;

    if (argc > 1)
    {
        num_pairs = atoi(argv[1]);
    }
    if (argc > 2)
    {
        num_operations = atoi(argv[2]);
    }

    pthread_t *threads = malloc(num_pairs * 2 * sizeof(pthread_t));
    ThreadArgs *args = malloc(num_pairs * 2 * sizeof(ThreadArgs));

    printf("Starting program with %d pairs of threads, each performing %d operations.\n", num_pairs, num_operations);
    printf("Initial value of shared variable: %ld\n", shared_variable);

    for (int i = 0; i < num_pairs; i++)
    {
        args[2 * i].id = i * 2;
        args[2 * i].num_operations = num_operations;
        args[2 * i].increment = 1;

        args[2 * i + 1].id = i * 2 + 1;
        args[2 * i + 1].num_operations = num_operations;
        args[2 * i + 1].increment = -1;

        pthread_create(&threads[2 * i], NULL, modify_variable, &args[2 * i]);
        pthread_create(&threads[2 * i + 1], NULL, modify_variable, &args[2 * i + 1]);
    }

    for (int i = 0; i < num_pairs * 2; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Final value of shared variable: %ld\n", shared_variable);

    free(threads);
    free(args);
    return 0;
}
