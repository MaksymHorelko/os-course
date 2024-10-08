#ifndef POINT_H
#define POINT_H

typedef struct
{
    double x, y; // Координати точки
    double mass; // Маса точки
} Point;

// Функції для роботи з точками
double distance(Point p1, Point p2);
Point find_closest_point(Point points[], int n, int index);
int find_min_mass_point(Point points[], int n);

#endif
