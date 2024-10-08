#include <stdio.h>
#include "point.h"
#include "process.h"

int main()
{
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter coordinates (x ; y) for point %d: ", i + 1);
        scanf("%lf", &points[i].x);
        scanf("%lf", &points[i].y);

        printf("Enter mass for point %d: ", i + 1);
        scanf("%lf", &points[i].mass);
    }

    process_points(points, n);

    printf("The last remaining point is at (%.2f, %.2f) with mass %.2f\n", points[0].x, points[0].y, points[0].mass);
    return 0;
}
