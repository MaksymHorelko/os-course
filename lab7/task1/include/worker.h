#ifndef WORKER_H
#define WORKER_H

typedef struct {
    int id;
    int num_operations;
    int increment;
} ThreadArgs;

void *modify_variable(void *args);

#endif
