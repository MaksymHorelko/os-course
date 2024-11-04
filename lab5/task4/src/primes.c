#include "primes.h"
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PRIMES 50
int primes_global[MAX_PRIMES];

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void *calculate_primes_global(void *arg)
{
    int n = *(int *)arg;
    int count = 0, num = 2;
    while (count < n)
    {
        if (is_prime(num))
        {
            primes_global[count++] = num;
        }
        num++;
    }
    return NULL;
}

void *calculate_primes_return(void *arg)
{
    int n = *(int *)arg;
    int *result = malloc(n * sizeof(int));
    int count = 0, num = 2;
    while (count < n)
    {
        if (is_prime(num))
        {
            result[count++] = num;
        }
        num++;
    }
    return result;
}

void calculate_primes_arg(int n, int *result)
{
    int count = 0, num = 2;
    while (count < n)
    {
        if (is_prime(num))
        {
            result[count++] = num;
        }
        num++;
    }
}
