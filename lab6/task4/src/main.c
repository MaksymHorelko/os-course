#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "pi_calculator.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <delay_seconds>\n", argv[0]);
        return 1;
    }

    int delay = atoi(argv[1]);
    pthread_t pi_thread;
    void *result;

    if (pthread_create(&pi_thread, NULL, calculate_pi, NULL) != 0)
    {
        perror("Failed to create thread");
        return 1;
    }

    sleep(delay);

    if (pthread_cancel(pi_thread) != 0)
    {
        perror("Failed to cancel thread");
    }

    if (pthread_join(pi_thread, &result) != 0)
    {
        perror("Failed to join thread");
    }

    if (result == PTHREAD_CANCELED)
    {
        printf("Thread was canceled.\n");
    }
    else
    {
        printf("Thread completed the calculation. Final value of pi: %.15f\n", *((double *)result));
        free(result);
    }

    return 0;
}
