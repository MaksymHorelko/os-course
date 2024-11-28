#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "signal_handler.h"
#include <sys/wait.h>

#define SIGNAL_COUNT 5

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0)
    {
        child_process_logic();
    }
    else
    {
        for (int i = 0; i < SIGNAL_COUNT; i++)
        {
            union sigval value;
            value.sival_int = i + 1;

            if (sigqueue(pid, SIGRTMIN, value) != 0)
            {
                perror("Failed to send signal");
            }
            else
            {
                printf("Parent process: Sent signal %d with value %d\n", SIGRTMIN, value.sival_int);
            }

            sleep(1);
        }

        if (kill(pid, SIGTERM) != 0)
        {
            perror("Failed to send SIGTERM");
        }

        wait(NULL);
        printf("Parent process: Child has terminated. Exiting.\n");
    }

    return 0;
}
