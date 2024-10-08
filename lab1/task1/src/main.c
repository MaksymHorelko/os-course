#include <stdio.h>
#include "curve_length.h"

int main() {
    double a, b, epsilon;
    int n;

    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter number of segments n: ");
    scanf("%d", &n);

    printf("Enter precision epsilon (0 < epsilon < 0.1): ");
    scanf("%lf", &epsilon);

    if (epsilon <= 0 || epsilon >= 0.1) {
        printf("Invalid epsilon. Must be between 0 and 0.1.\n");
        return 1;
    }

    double length = curve_length(a, b, n, epsilon);
    printf("The approximate length of the curve is: %.6f\n", length);

    return 0;
}
