#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "catalan.h"
#include "primes.h"

#define NUM_CATALAN 10
#define NUM_PRIMES 10

int main()
{
    pthread_t catalan_thread, primes_thread;
    int catalan_count = NUM_CATALAN;
    int primes_count = NUM_PRIMES;

    // Використання глобальної змінної
    pthread_create(&catalan_thread, NULL, calculate_catalan_global, &catalan_count);
    pthread_create(&primes_thread, NULL, calculate_primes_global, &primes_count);

    pthread_join(catalan_thread, NULL);
    pthread_join(primes_thread, NULL);

    printf("Catalan numbers (global variable): ");
    for (int i = 0; i < catalan_count; i++)
    {
        printf("%d ", catalan_global[i]);
    }
    printf("\n");

    printf("Prime numbers (global variable): ");
    for (int i = 0; i < primes_count; i++)
    {
        printf("%d ", primes_global[i]);
    }
    printf("\n");

    // Використання повернення значень через результуючу змінну
    int *catalan_result;
    int *primes_result;
    pthread_create(&catalan_thread, NULL, calculate_catalan_return, &catalan_count);
    pthread_create(&primes_thread, NULL, calculate_primes_return, &primes_count);

    pthread_join(catalan_thread, (void **)&catalan_result);
    pthread_join(primes_thread, (void **)&primes_result);

    printf("Catalan numbers (return value): ");
    for (int i = 0; i < catalan_count; i++)
    {
        printf("%d ", catalan_result[i]);
    }
    printf("\n");

    printf("Prime numbers (return value): ");
    for (int i = 0; i < primes_count; i++)
    {
        printf("%d ", primes_result[i]);
    }
    printf("\n");

    free(catalan_result);
    free(primes_result);

    // Використання аргументу для передачі результату
    int catalan_array[NUM_CATALAN];
    int primes_array[NUM_PRIMES];

    calculate_catalan_arg(NUM_CATALAN, catalan_array);
    calculate_primes_arg(NUM_PRIMES, primes_array);

    printf("Catalan numbers (arg pass): ");
    for (int i = 0; i < NUM_CATALAN; i++)
    {
        printf("%d ", catalan_array[i]);
    }
    printf("\n");

    printf("Prime numbers (arg pass): ");
    for (int i = 0; i < NUM_PRIMES; i++)
    {
        printf("%d ", primes_array[i]);
    }
    printf("\n");

    return 0;
}
