#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "process_manager.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number_of_children>\n", argv[0]);
        return 1;
    }

    int num_children = atoi(argv[1]);
    if (num_children <= 0)
    {
        fprintf(stderr, "Please provide a positive integer for the number of children.\n");
        return 1;
    }

    pid_t *child_pids = malloc(num_children * sizeof(pid_t));

    for (int i = 0; i < num_children; i++)
    {
        child_pids[i] = create_child_process();
    }

    display_process_info(child_pids, num_children);

    printf("Enter 'terminate' to kill all child processes or 'exit' to leave them running: ");
    char command[10];
    fgets(command, sizeof(command), stdin);

    if (strncmp(command, "terminate", 9) == 0)
    {
        terminate_child_processes(child_pids, num_children);
    }

    free(child_pids);
    printf("Program completed.\n");
    return 0;
}
