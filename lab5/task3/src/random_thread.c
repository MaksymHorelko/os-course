#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "random_thread.h"

void *random_thread_func(void *arg)
{
    RandomThreadArgs *args = (RandomThreadArgs *)arg;
    int number;

    srand(time(NULL));
    for (int i = 0; i < args->max_randoms; i++)
    {
        number = rand() % args->random_range;
        printf("Random Thread: generated number %d\n", number);
        sleep(1);

        if (number == args->target_number)
        {
            printf("Random Thread: target number %d reached. Terminating early.\n", args->target_number);
            return NULL;
        }
    }
    return NULL;
}
