#ifndef PRIMES_H
#define PRIMES_H

#include <pthread.h>

#define MAX_PRIMES 50
extern int primes_global[MAX_PRIMES];

void *calculate_primes_global(void *arg);
void *calculate_primes_return(void *arg);
void calculate_primes_arg(int n, int *result);

#endif
