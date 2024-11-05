#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "worker_threads.h"

extern int global_array[];

void *worker_function(void *arg)
{
    int thread_num = *(int *)arg;
    free(arg);

    sleep(thread_num);

    int random_value = (rand() % 10) + 1;
    printf("Thread %d generated number %d\n", thread_num, random_value);

    global_array[thread_num] = random_value;

    sleep(random_value);

    printf("Thread %d finished.\n", thread_num);
    return NULL;
}
