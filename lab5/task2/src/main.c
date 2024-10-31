#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "thread_function.h"

int main()
{
    const char *thread_names[4] = {"Thread1", "Thread2", "Thread3", "Thread4"};
    const char *messages[4] = {"Hello", "World", "Multithreading", "Example"};
    int repetitions[4] = {3, 5, 2, 4};

    pthread_t threads[4];
    ThreadArgs args[4];

    for (int i = 0; i < 4; i++)
    {
        args[i].name = thread_names[i];
        args[i].str = messages[i];
        args[i].num = repetitions[i];

        if (pthread_create(&threads[i], NULL, thread_function, &args[i]) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return 1;
        }
    }

    printf("All threads completed.\n");
    return 0;
}
