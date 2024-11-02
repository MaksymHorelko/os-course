#ifndef RANDOM_THREAD_H
#define RANDOM_THREAD_H

typedef struct
{
    int max_randoms;
    int random_range;
    int target_number;
} RandomThreadArgs;

void *random_thread_func(void *arg);

#endif
