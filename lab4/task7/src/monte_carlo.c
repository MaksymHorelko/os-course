#include "monte_carlo.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int monte_carlo(int throws, double R)
{
    int hits = 0;
    double x, y;
    srand(time(NULL) ^ getpid());

    for (int i = 0; i < throws; i++)
    {
        x = ((double)rand() / RAND_MAX) * 2 * R - R;
        y = ((double)rand() / RAND_MAX) * 2 * R - R;

        if (x * x + y * y <= R * R)
        {
            hits++;
        }
    }

    return hits;
}
