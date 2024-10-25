#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "monte_carlo.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <number of throws> <radius>\n", argv[0]);
        return 1;
    }

    int throws = atoi(argv[1]);
    double radius = atof(argv[2]);

    if (throws <= 0 || radius <= 0)
    {
        fprintf(stderr, "Throws and radius must be positive numbers.\n");
        return 1;
    }

    int pipefd[2]; 
    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    else if (pid == 0)
    {
        // Дочірній процес обчислює кількість влучень
        close(pipefd[0]);
        int hits = monte_carlo(throws, radius);
        write(pipefd[1], &hits, sizeof(hits)); // Передаємо кількість влучень через pipe
        close(pipefd[1]);                      // Закриваємо запис
        exit(0);
    }

    else
    {
        // Батьківський процес чекає завершення і отримує результат
        close(pipefd[1]); 
        int hits;
        read(pipefd[0], &hits, sizeof(hits)); // Читаємо кількість влучень
        close(pipefd[0]);                     // Закриваємо читання після отримання результату

        wait(NULL);
    
        double expected_area = 3.14159265358979323846 * radius * radius;
        double circle_area = (4 * radius * radius) * ((double)hits / throws);

        printf("After %d throws area is %.08f, error is %.08f\n", throws, circle_area, fabs(circle_area - expected_area));
    }

    return 0;
}
