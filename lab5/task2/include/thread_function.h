#ifndef THREAD_FUNCTION_H
#define THREAD_FUNCTION_H

typedef struct
{
    const char *name;
    const char *str;
    int num;
} ThreadArgs;

void *thread_function(void *arg);

#endif
