#include "mysystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int my_system(const char *command)
{
    if (command == NULL)
    {
        return -1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return -1;
    }
    else if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        perror("exec failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            return WEXITSTATUS(status);
        }
        else
        {
            return -1;
        }
    }
}
