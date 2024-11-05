#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pi_calculator.h"

void *calculate_pi(void *arg)
{
    double *pi = malloc(sizeof(double));
    if (pi == NULL)
    {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }

    *pi = 0.0;
    int n = 100000;

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    for (int i = 0; i < n; i++)
    {
        pthread_testcancel();
        if (i % 2 == 0)
        {
            *pi += 1.0 / (2 * i + 1);
        }
        else
        {
            *pi -= 1.0 / (2 * i + 1);
        }

        if (i % 10000 == 0)
        {
            printf("Current pi estimate: %.15f\n", *pi * 4);
        }
    }

    *pi *= 4;
    return pi;
}