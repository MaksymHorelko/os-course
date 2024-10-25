#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "process_manager.h"

pid_t create_child_process()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child process started with PID: %d\n", getpid());
        while (1)
            ;
        exit(0);
    }
    return pid;
}

void terminate_child_processes(pid_t *child_pids, int num_children)
{
    for (int i = 0; i < num_children; i++)
    {
        if (child_pids[i] > 0)
        {
            kill(child_pids[i], SIGKILL);
            printf("Terminated child process with PID: %d\n", child_pids[i]);
        }
    }
}

void display_process_info(pid_t *child_pids, int num_children)
{
    printf("Displaying process info using 'ps' command:\n");
    system("ps -aux | grep '[p]rocess_manager'");
    for (int i = 0; i < num_children; i++)
    {
        printf("Child PID: %d\n", child_pids[i]);
    }
}
