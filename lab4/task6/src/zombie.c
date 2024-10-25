#include "zombie.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_zombie()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    else if (pid == 0)
    {

        printf("Child process (Zombie) PID: %d\n", getpid());
        exit(0);
    }
    
    else
    {
        printf("Parent process, PID: %d. Checking for zombie process:\n", getpid());
        system("ps -o pid,ppid,state,cmd");

        sleep(3);

        wait(NULL);

        printf("\nAfter calling wait():\n");
        system("ps -o pid,ppid,state,cmd");
    }
}
