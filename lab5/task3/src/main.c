#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "string_thread.h"
#include "random_thread.h"

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <string> <repetitions> <max_randoms> <random_range>\n", argv[0]);
        return 1;
    }

    const char *message = argv[1];
    int repetitions = atoi(argv[2]);

    int max_randoms = atoi(argv[3]);
    int random_range = atoi(argv[4]);
    int target_number = random_range / 2;

    pthread_t string_thread, random_thread;

    StringThreadArgs string_args = {message, repetitions};
    RandomThreadArgs random_args = {max_randoms, random_range, target_number};

    pthread_create(&string_thread, NULL, string_thread_func, &string_args);
    pthread_create(&random_thread, NULL, random_thread_func, &random_args);

    pthread_join(string_thread, NULL);
    pthread_join(random_thread, NULL);

    printf("All threads completed. Main thread exiting.\n");
    return 0;
}
