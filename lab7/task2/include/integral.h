#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <pthread.h>

typedef struct
{
    int id;                 // Ідентифікатор потоку
    double a;               // Ліва межа інтегрування
    double b;               // Права межа інтегрування
    double precision;       // Точність обчислень
    double (*func)(double); // Функція для інтегрування
    pthread_mutex_t *mutex; // Вказівник на м’ютекс
    double *result;         // Вказівник на спільну змінну результату
} ThreadArgs;

double integrate(double (*func)(double), double a, double b, double precision);
void *calculate_partial_integral(void *args);

#endif
