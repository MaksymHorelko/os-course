#include <math.h>
#include "math_series.h"
#include "curve_length.h"

double f(double x, double epsilon) {
    double sin_x2 = taylor_sin(x * x, epsilon);
    double cos_x3 = taylor_cos(x * x * x, epsilon);
    return sin_x2 / (1 + cos_x3);
}

double curve_length(double a, double b, int n, double epsilon) {
    double h = (b - a) / n;
    double length = 0.0;

    double x_prev = a;
    double y_prev = f(x_prev, epsilon);

    for (int i = 1; i <= n; i++) {
        double x_curr = a + i * h;
        double y_curr = f(x_curr, epsilon);

        double dx = x_curr - x_prev;
        double dy = y_curr - y_prev;

        length += sqrt(dx * dx + dy * dy);

        x_prev = x_curr;
        y_prev = y_curr;
    }

    return length;
}
