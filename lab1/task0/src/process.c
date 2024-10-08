#include "point.h"
#include "process.h"

void process_points(Point points[], int n)
{
    while (n > 1)
    {
        int min_index = find_min_mass_point(points, n);
        Point closest_point = find_closest_point(points, n, min_index);

        for (int i = 0; i < n; i++)
        {
            if (points[i].x == closest_point.x && points[i].y == closest_point.y)
            {
                points[i].mass += points[min_index].mass;
                break;
            }
        }

        for (int i = min_index; i < n - 1; i++)
        {
            points[i] = points[i + 1];
        }

        n--;
    }
}
