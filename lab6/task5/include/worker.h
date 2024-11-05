#ifndef WORKER_H
#define WORKER_H

typedef struct
{
    int thread_id;
    char message[50];
} thread_data_t;

void *worker_function(void *arg);

#endif
