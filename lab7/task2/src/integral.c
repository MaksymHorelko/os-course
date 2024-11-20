#include <stdio.h>
#include <pthread.h>
#include "integral.h"

double integrate(double (*func)(double), double a, double b, double precision)
{
    double result = 0.0;
    int n = 1;
    double step, current_sum;

    do
    {
        current_sum = 0.0;
        step = (b - a) / n;

        for (int i = 0; i < n; i++)
        {
            double x_mid = a + step * (i + 0.5);
            current_sum += func(x_mid);
        }
        current_sum *= step;

        if (fabs(current_sum - result) < precision)
        {
            break;
        }

        result = current_sum;
        n *= 2;
    } while (1);

    return result;
}

void *calculate_partial_integral(void *args)
{
    ThreadArgs *data = (ThreadArgs *)args;
    double local_result = integrate(data->func, data->a, data->b, data->precision);

    pthread_mutex_lock(data->mutex);
    *(data->result) += local_result;
    pthread_mutex_unlock(data->mutex);

    printf("Thread %d: calculated partial integral = %.5f\n", data->id, local_result);
    return NULL;
}
