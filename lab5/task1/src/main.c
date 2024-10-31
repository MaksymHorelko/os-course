#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "child_thread.h"

void *main_thread_function(void *arg)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("Main Thread. Iteration: %d\n", i);
        sleep(rand() % 3);
    }
    return NULL;
}

int main()
{
    pthread_t child_thread;

    srand(time(NULL));

    if (pthread_create(&child_thread, NULL, child_thread_function, NULL) != 0)
    {
        perror("Failed to create child thread");
        return 1;
    }

    main_thread_function(NULL);

    if (pthread_join(child_thread, NULL) != 0)
    {
        perror("Failed to join child thread");
        return 1;
    }

    printf("Both threads completed.\n");
    return 0;
}
