#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "integral.h"

double shared_result = 0.0;
pthread_mutex_t mutex;

double function(double x)
{
    return 4.0 - x * x;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <number_of_threads> <a> <b>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    double a = atof(argv[2]);
    double b = atof(argv[3]);

    if (num_threads <= 0 || a >= b)
    {
        printf("Invalid input parameters.\n");
        return 1;
    }

    pthread_t threads[num_threads];
    ThreadArgs args[num_threads];

    double step = (b - a) / num_threads;
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < num_threads; i++)
    {
        args[i].id = i;
        args[i].a = a + i * step;
        args[i].b = args[i].a + step;
        args[i].precision = 1e-6;
        args[i].func = function;
        args[i].mutex = &mutex;
        args[i].result = &shared_result;

        pthread_create(&threads[i], NULL, calculate_partial_integral, &args[i]);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Final result of integration: %.5f\n", shared_result);
    return 0;
}
