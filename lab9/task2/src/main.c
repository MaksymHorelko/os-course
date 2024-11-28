#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alarm_handler.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <time_in_seconds> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int time_in_seconds = atoi(argv[1]);
    if (time_in_seconds <= 0)
    {
        fprintf(stderr, "Error: Time should be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    const char *message = argv[2];

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        run_alarm(time_in_seconds, message);
    }
    else
    {
        printf("Alarm set for %d seconds. Parent process exiting...\n", time_in_seconds);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
