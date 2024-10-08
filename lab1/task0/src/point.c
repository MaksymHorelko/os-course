#include <math.h>
#include "point.h"
#include <stdio.h>

// Функція для знаходження відстані між двома точками
double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Функція для знаходження найближчої точки до заданої
Point find_closest_point(Point points[], int n, int index)
{
    double min_dist = __DBL_MAX__;
    Point closest_point;
    for (int i = 0; i < n; i++)
    {
        if (i != index)
        {
            double dist = distance(points[index], points[i]);
            if (dist < min_dist)
            {
                min_dist = dist;
                closest_point = points[i];
            }
        }
    }
    return closest_point;
}

// Функція для знаходження індексу точки з найменшою масою
int find_min_mass_point(Point points[], int n)
{
    int min_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].mass < points[min_index].mass)
        {
            min_index = i;
        }
    }
    // printf("index of min mass: %d", min_index);

    return min_index;
}
