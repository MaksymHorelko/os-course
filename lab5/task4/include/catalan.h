#ifndef CATALAN_H
#define CATALAN_H

#include <pthread.h>

#define MAX_CATALAN 50
extern int catalan_global[MAX_CATALAN];

void *calculate_catalan_global(void *arg);
void *calculate_catalan_return(void *arg);
void calculate_catalan_arg(int n, int *result);

#endif
