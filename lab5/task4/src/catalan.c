#include "catalan.h"
#include <stdlib.h>

#define MAX_CATALAN 50
int catalan_global[MAX_CATALAN];

unsigned long long factorial(int n)
{
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

unsigned long long catalan_number(int n)
{
    return factorial(2 * n) / (factorial(n + 1) * factorial(n));
}

void *calculate_catalan_global(void *arg)
{
    int n = *(int *)arg;
    for (int i = 0; i < n; i++)
    {
        catalan_global[i] = catalan_number(i);
    }
    return NULL;
}

void *calculate_catalan_return(void *arg)
{
    int n = *(int *)arg;
    int *result = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        result[i] = catalan_number(i);
    }
    return result;
}

void calculate_catalan_arg(int n, int *result)
{
    for (int i = 0; i < n; i++)
    {
        result[i] = catalan_number(i);
    }
}
