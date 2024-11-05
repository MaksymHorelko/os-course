#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "display_thread.h"

extern int global_array[];

void *display_function(void *arg)
{
    int num_threads = *(int *)arg;

    while (1)
    {
        int filled = 1;
        printf("Current state of global array: ");
        for (int i = 0; i < num_threads; i++)
        {
            if (global_array[i] == -1)
            {
                filled = 0;
            }
            printf("%d ", global_array[i]);
        }
        printf("\n");

        if (filled)
        {
            printf("Display thread terminating as global array is fully populated.\n");
            pthread_exit(NULL);
        }
        sleep(1);
    }
    return NULL;
}
