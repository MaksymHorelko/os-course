#ifndef STRING_THREAD_H
#define STRING_THREAD_H

typedef struct
{
    const char *message;
    int repetitions;
} StringThreadArgs;

void *string_thread_func(void *arg);

#endif
