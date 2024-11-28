#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "sync.h"

pid_t child_pid;

void parent_process_logic();
void child_process_logic();

int main()
{
    child_pid = fork();

    if (child_pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0)
    {
        child_process_logic();
    }
    else
    {
        parent_process_logic();
    }

    return 0;
}

void parent_process_logic()
{
    printf("Parent process: Waiting for the child to print first.\n");

    kill(child_pid, SIGUSR1);

    pause();

    printf("Parent process: Printing message first.\n");

    pause();

    printf("Parent process: Printing message after child.\n");
}

void child_process_logic()
{
    pause();

    printf("Child process: Printing message second.\n");

    kill(getppid(), SIGUSR1);
}
