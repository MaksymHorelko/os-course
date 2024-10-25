#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include "process_counter.h"

void count_for_duration(int duration) {
    time_t start_time = time(NULL);
    unsigned long long counter = 0;

    while (time(NULL) - start_time < duration) {
        counter++;
    }

    printf("Process %d: Counter reached %llu\n", getpid(), counter);
}
