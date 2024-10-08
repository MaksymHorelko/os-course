#include "math_series.h"

double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

double taylor_sin(double x, double epsilon) {
    double term = x;
    double sum = term;
    int n = 1;

    while (term > epsilon || term < -epsilon) {
        term = -term * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}

double taylor_cos(double x, double epsilon) {
    double term = 1.0;
    double sum = term;
    int n = 1;

    while (term > epsilon || term < -epsilon) {
        term = -term * x * x / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }

    return sum;
}
